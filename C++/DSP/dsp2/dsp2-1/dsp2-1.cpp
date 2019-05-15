// dsp2-1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// R01	23_Shīna	DSP2-1-2

#include "DSP.h"

using namespace std;

/////////////////////////////////////////////////////
// ファイル読み込み
class FileManager
{
public:
	vector<double> readFile(string fn)
	{
		vector<double> data;
		ifstream ifs(fn);
		string str;
		vector<string> lines;
		if (ifs.fail())
		{
			cerr << "File loading has been failed." << endl;
			return data;
		}
		while (getline(ifs, str))	data.push_back(stod(str));

		return data;
	}

	void writeFile(string fn, vector<complex<double>> out)
	{
		ofstream writing_file;
		writing_file.open(fn, ios::out);

		cout << "writing " << fn << "..." << endl;

		for (auto each : out)	writing_file << each.real() << endl;

		cout << "output : " << fn << endl;
	}
};

class FFT
{
private:
	/////////////////////////////////////////////////////
	// bitリバーサル ビット演算
	vector<int> bit_r(int n)
	{
		vector<int> bit;
		int r = (int)log2(n);
		for (int i = 0; i < n; i++)
		{
			bit.push_back(0);
			for (int j = 0; j < r; j++)	bit[i] += ((i >> j) & 1) << (r - j - 1);
		}

		return bit;
	}
	/////////////////////////////////////////////////////
	// twid
	vector<complex<double>> twid(int n)
	{
		vector<complex<double>> wnk;
		int i;
		for (i = 0; i < n / 2; i++)
		{
			complex<double> comp(cos(-2 * M_PI * i / n), sin(-2 * M_PI * i / n));
			wnk.push_back(comp);
		}
		return wnk;
	}

	/////////////////////////////////////////////////////
	// FFT メイン
	vector<complex<double>> main(vector<complex<double>> in, int N)
	{
		int r_big = 1, r_sma = N / 2; //初期値を与えておく
		int i, j, k, out1, out2, nk;
		vector<complex<double>> wnk, out;
		vector<int> bits;
		int r = (int)log2(N);

		//回転子の生成とビットリバースの生成
		wnk = twid(N);
		bits = bit_r(N);

		//初期化
		for (i = 0; i < N; i++)	out.push_back(in[i]);

		//ビットリバース
		for (i = 0; i < N; i++)	out[bits[i]] = in[i];


		//メイン
		complex<double> dummy;
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < r_big; j++)
			{
				for (k = 0; k < r_sma; k++)
				{
					out1 = r_big * 2 * k + j;
					out2 = out1 + r_big;
					nk = j * r_sma;

					dummy = out[out2] * wnk[nk];
					out[out2] = out[out1] - dummy;
					out[out1] = out[out1] + dummy;
				}
			}
			r_big *= 2;
			r_sma /= 2;
		}
		return out;
	}

public:
	vector<complex<double>> fft(vector<complex<double>> in, int points)
	{
		int i, N = (int)in.size();
		vector<complex<double>> out;
		for (i = 0; i < points; i++)	out.push_back(0);
		for (i = 0; i < N; i++)	out[i] = in[i];
		return main(out, points);
	}

	vector<complex<double>> ifft(vector<complex<double>> in, int points, int division)
	{
		int i, N = (int)in.size();
		vector<complex<double>> out;
		for (i = 0; i < N; i++) in[i].imag(-in[i].imag());
		out = main(in, points);
		for (i = 0; i < points; i++)	out[i] /= points * division;

		return out;
	}

	vector<complex<double>> spectral(vector<complex<double>> in)
	{
		int i, N = (int)in.size();
		vector<complex<double>> out;
		for (i = 0; i < N; i++) out.push_back(0);
		for (i = 0; i < N; i++) out[i].real(in[i].real() * in[i].real() + in[i].imag() * in[i].imag());

		return out;
	}

	vector<complex<double>> innner(vector<complex<double>> in1, vector<complex<double>> in2)
	{
		int i, N = (int)in1.size();
		vector<complex<double>> out;
		for (i = 0; i < N; i++) out.push_back(0);
		for (i = 0; i < N; i++) in1[i].imag(-in1[i].imag());	// 複素共役をとる
		for (i = 0; i < N; i++) out[i] = in1[i] * in2[i];

		return out;
	}

	int estimatePower(int n)
	{
		int out = 1;
		int cnt = 1;
		while ((2 * n) > out)
		{
			out = static_cast<int>(pow(2, cnt));
			cnt++;
		}

		return out;
	}
};


int main(int argc, const char* argv[])
{
	vector<double> data;
	vector<complex<double>> xn1, xn2, yn1, yn2, out, sp;
	string input_fn1, input_fn2, output_fn;
	int input_num;
	auto start = chrono::system_clock::now(), end = chrono::system_clock::now();

	cout << "R01\t23_Shīna\tDSP2-1-2" << endl;
	cout << "Put files at same directory." << endl;
	cout << "(Auto-Corr : 0 | Cross-Corr : 1) : ";
	cin >> input_num;
	cout << "Enter first input filename. : ";
	cin >> input_fn1;
	if (input_num == 1)
	{
		cout << "Enter second input filename. : ";
		cin >> input_fn2;
	}
	cout << "Enter output filename. : ";
	cin >> output_fn;

	FileManager filemanager;
	data = filemanager.readFile(input_fn1);
	for (auto each : data)
	{
		complex<double> comp(each, 0);
		xn1.push_back(comp);
	}
	if (input_num == 1)
	{
		data = filemanager.readFile(input_fn2);
		for (auto each : data)
		{
			complex<double> comp(each, 0);
			xn2.push_back(comp);
		}
	}

	FFT fft;
	int size = (int)xn1.size();
	int fftpoint = fft.estimatePower(size);

	start = chrono::system_clock::now();

	yn1 = fft.fft(xn1, fftpoint);
	if (input_num == 0) sp = fft.spectral(yn1);
	else
	{
		yn2 = fft.fft(xn2, fftpoint);
		sp = fft.innner(yn1, yn2);
	}
	out = fft.ifft(sp, fftpoint, size);

	end = chrono::system_clock::now();
	cout << "Duration time : " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "[ms]" << std::endl;

	filemanager.writeFile(output_fn, out);

	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
