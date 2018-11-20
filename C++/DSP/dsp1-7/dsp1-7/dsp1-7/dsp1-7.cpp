// dsp1-7.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"


using namespace std;

// 計算クラス
class DFT
{
	complex<double> SRC[DAT_N];   //元データの実部
	complex<double> DFT_dat[N];   //DFT
	complex<double> IDFT_dat[N];  //IDFT

public:
	void makeSourceData();  // 元データ作成
	void executeDFT();      // 離散フーリエ変換
	void executeIDFT();     // 逆離散フーリエ変換

private:
	double calcTerm(int n, double x);  //各項計算
};

class FFT
{
private:
	complex<long double> w[512];
	long br[512];
	long n;
	long double step;
	long double pi;
	void butterfly(complex<long double> a, complex<long double> b, complex<long double> out[], long k);
	complex<long double> multiplication(complex<long double> a, complex<long double> b);

public:
	FFT(long num);
	void difFFT(complex<long double> x[]);
};

static const string dftFilename = "DFT.csv";
static const string idftFilename = "IDFT.csv";
static const string fftFilename = "FFT.csv";
static const string ifftFilename = "IFFT.csv";
static const double pi = acos(-1.0); // お手軽π

// 元データ作成
void DFT::makeSourceData()
{
	int i;

	for (i = 0; i < DAT_N; i++)	SRC[i] = complex<double>(2 * sin(1024 * (2 * pi / DAT_N) * i) + 3 * cos(256 * (2 * pi / DAT_N) * i));
}

// 離散フーリエ変換
void DFT::executeDFT()
{
	// 出力ファイルOPEN
	ofstream pf(dftFilename, ios::out | ios::trunc);

	// ヘッダ出力 ( k, 角周波数, 元データ(実部), 元データ(虚部), DFT(実部), DFT(虚部) )
	pf << "k,f,x_re,x_im,X_re,X_im,|X(k)|" << endl;

	// 計算・結果出力
	for (size_t k = 0; k < N; k++)
	{
		DFT_dat[k] = complex<double>(0.0, 0.0);
		for (size_t n = 0; n < N; n++)	DFT_dat[k] += complex<double>(SRC[n].real() * (cos((2 * pi / N) * k * n)) + SRC[n].imag() * (sin((2 * pi / N) * k * n)), SRC[n].real() * (-sin((2 * pi / N) * k * n)) + SRC[n].imag() * (cos((2 * pi / N) * k * n)));

		long double spt = sqrt(DFT_dat[k].real() * DFT_dat[k].real() + DFT_dat[k].imag() * DFT_dat[k].imag());
		pf << k << "," << (2 * pi / N) * k << "," << SRC[k].real() << "," << SRC[k].imag() << "," << DFT_dat[k].real() << "," << DFT_dat[k].imag() << "," << spt << endl;
	}

	// 出力ファイルCLOSE
	pf.close();
}

// 逆離散フーリエ変換
void DFT::executeIDFT()
{
	// 出力ファイルOPEN
	ofstream pf(idftFilename, ios::out | ios::trunc);

	// ヘッダ出力 ( k, 角周波数, DFT(実部), DFT(虚部), IDFT(実部), IDFT(虚部) )
	pf << "k,\tf,\tX_re,\tX_im,\tx_re,\tx_im\n" << endl;

	// 計算・結果出力
	for (size_t n = 0; n < N; n++)
	{
		IDFT_dat[n] = complex<double>(0.0, 0.0);
		for (size_t k = 0; k < N; k++)	IDFT_dat[n] += complex<double>(DFT_dat[k].real() * (cos((2 * pi / N) * k * n)) - DFT_dat[k].imag() * (sin((2 * pi / N) * k * n)), DFT_dat[k].real() * (sin((2 * pi / N) * k * n)) + DFT_dat[k].imag() * (cos((2 * pi / N) * k * n)));
		IDFT_dat[n] /= complex<double>(N, N);

		pf << "," << n << "," << (2 * pi / N) * n << "," << DFT_dat[n].real() << "," << DFT_dat[n].imag() << "," << IDFT_dat[n].real() << "," << IDFT_dat[n].imag() << endl;
	}

	// 出力ファイルCLOSE
	pf.close();
}

FFT::FFT(long num)
{
	n = num;
	pi = acos(-1.0);
	long double omega = -2.0 * pi / (long double)n;	// 回転子の設定

	for (long i = 0; i < n; i++)w[i] = complex<long double>(cos(omega * (long double)i), sin(omega * (long double)i));	// 回転子の設定

	step = log((long double)n) / log(2.0);			// 総バタフライ区間数

	br[0] = 0;										// ビット反転
	long roop1 = 1;
	for (long i = 0; i < step; i++)
	{
		for (long j = 0; j < roop1; j++)	br[roop1 + j] = br[j] + n / (2 * roop1);
		roop1 *= 2;
	}
}

void FFT::difFFT(complex<long double> x[])
{
	complex<long double> out[2];			// 一時記憶メモリ
	long roop2 = n / 2;
	long roop = 1;

	for (long i = 0; i < step; i++)			// 第i番目のバタフライ区間
	{
		long bias = 0;
		for (long j = 0; j < roop; j++)
		{
			for (long k = 0; k < roop2; k++)
			{
				long num = bias + k;		// バタフライ演算対象信号の選択
				long num2 = num + roop2;	// バタフライ演算対象信号の選択
				butterfly(x[num], x[num2], out, k * roop);
				x[num] = out[0];			// インプレイス
				x[num2] = out[1];			// インプレイス
			}
			bias += 2 * roop2;
		}
		roop2 /= 2;
		roop *= 2;
	}

	complex<long double> buffer;							// ベクトルの要素の入れ替え
	for (long cnt = 0; cnt < n; cnt++)
	{
		if (br[cnt] > cnt)
		{
			buffer = x[br[cnt]];
			x[br[cnt]] = x[cnt];
			x[cnt] = buffer;
		}
	}
}

void FFT::butterfly(complex<long double> a, complex<long double> b, complex<long double> out[], long k)
{
	complex<long double> d;

	out[0] = complex<long double>(a.real() + b.real(), a.imag() + b.imag());
	d = complex<long double>(a.real() - b.real(), a.imag() - b.imag());
	out[1] = multiplication(d, w[k]);	// 複素数の積
}

complex<long double> FFT::multiplication(complex<long double> a, complex<long double> b)
{
	complex<long double> c;				// 変数 c を 64 ビットの複素数型で宣言

	c = complex<long double>(a.real() * b.real() - a.imag() * b.imag(), a.real() * b.imag() + a.imag() * b.real());	// 複素数 a と b の乗算 

	return c;	// c を返す。
}

int main(int argc, char* argv[])
{
	int n;
	long double ts;
	complex<long double> sf[DAT_N];		// 配列 sf[4] を 64 ビットの複素数型で宣言して，"0" に初期化
	char buf[512];

	cout << "DSP1-7 4J23 H.Shiina" << endl;
	cout << "Enter some ts and n." << endl;
	cout << "U can get result of." << endl;

	/*
		complex<float> c(1.0f, 2.0f);

		// ストリーム出力
		cout << "output : " << c << endl;

		// 各要素の取得
		cout << "real : " << c.real() << endl;
		cout << "imag : " << c.imag() << endl;

		// 演算
		complex<float> a(1.0f, 2.0f);
		complex<float> b(2.0f, 3.0f);
		cout << "a + b : " << a + b << endl;
		cout << "a - b : " << a - b << endl;
		cout << "a * b : " << a * b << endl;
		cout << "a / b : " << a / b << endl;

		// 各複素数の値を取得する
		cout << "abs : " << abs(c) << endl;   // 絶対値
		cout << "arg : " << arg(c) << endl;   // 偏角
		cout << "conj : " << conj(c) << endl; // 共役複素数
		cout << "polar : " << polar(c) << endl; // 極座標
	*/

	try
	{
		cout << "Starting DFT..." << endl;

		auto start = chrono::system_clock::now();

		// 計算クラスインスタンス化
		DFT objDFT;

		// 元データ作成
		objDFT.makeSourceData();

		// 離散フーリエ変換
		objDFT.executeDFT();

		auto msec = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count();
		cout << msec << endl;

		// 逆離散フーリエ変換
		objDFT.executeIDFT();
		cout << "Finished DFT..." << endl;
	}
	catch (...)
	{
		cout << "Caught exception." << endl;
		return EXIT_FAILURE;
	}

	cout << " Ts [second] = ";	// サンプリング周期の入力
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%lf", &ts);
	cout << "[N = 2^n] n = ";	// 分割数の入力
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d", &n);
	n = pow(2.0, n);

	try
	{
		cout << "Starting FFT..." << endl;

		// 出力ファイルOPEN
		ofstream pf(fftFilename, ios::out | ios::trunc);

		FFT ft(n);

		long double f0 = 2 * pi / ((long double)n);															// 基本周波数の計算

		for (size_t i = 0; i < DAT_N; i++)	sf[i] = complex<long double>(2 * sin(1024 * (2 * pi / DAT_N) * i) + 3 * cos(256 * (2 * pi / DAT_N) * i));	// 離散時間信号
		// 予備データ	1.0 + sin(2.0 * pi * 250.0 * (long double)i * ts)

		auto start = chrono::system_clock::now();

		ft.difFFT(sf);

		auto msec = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count();
		cout << msec << endl;

		pf << "f [Hz], FR(kf0), FI(kf0), |F(kf0)|" << endl;
		for (long i = 0; i < n; i++)
		{
			long double spt = sqrt(sf[i].real() * sf[i].real() + sf[i].imag() * sf[i].imag());
			pf << f0 * (long double)i << "," << sf[i].real() << "," << sf[i].imag() << "," << spt << endl;	// 結果表示
		}

		// 出力ファイルCLOSE
		pf.close();

		cout << "Finished FFT..." << endl;
	}
	catch (...)
	{
		cout << "Caught exception." << endl;
		return EXIT_FAILURE;
	}

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
