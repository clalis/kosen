// dsp1-7.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"


using namespace std;

/*
 * 計算クラス
 */
class Calc
{
	double SRC_re[DAT_N];   //元データの実部
	double SRC_im[DAT_N];   //元データの虚部
	double DFT_re[N];   //DFTの実部
	double DFT_im[N];   //DFTの虚部
	double IDFT_re[N];  //IDFTの実部
	double IDFT_im[N];  //IDFTの虚部

public:
	void makeSourceData();  // 元データ作成
	void executeDFT();      // 離散フーリエ変換
	void executeIDFT();     // 逆離散フーリエ変換

private:
	double calcTerm(int n, double x);  //各項計算
};

static const string dftFilename = "DFT.csv";
static const string idftFilename = "IDFT.csv";
static const double pi = acos(-1.0); // お手軽π

/*
 * 元データ作成
 */
void Calc::makeSourceData()
{
	int i;

	for (i = 0; i < DAT_N; i++)
	{
		SRC_re[i] = 2 * sin(4 * (2 * pi / DAT_N) * i) + 3 * cos(2 * (2 * pi / DAT_N) * i);
		SRC_im[i] = 0.0;
	}
}

/*
 * 離散フーリエ変換
 */
void Calc::executeDFT()
{
	int k, n;  // LOOPインデックス

	// 出力ファイルOPEN
	ofstream pf(dftFilename, ios::out | ios::trunc);

	// ヘッダ出力 ( k, 角周波数, 元データ(実部), 元データ(虚部), DFT(実部), DFT(虚部) )
	pf << "k,f,x_re,x_im,X_re,X_im" << endl;

	// 計算・結果出力
	for (k = 0; k < N; k++)
	{
		DFT_re[k] = 0.0;
		DFT_im[k] = 0.0;
		for (n = 0; n < N; n++)
		{
			DFT_re[k] += SRC_re[n] * (cos((2 * pi / N) * k * n)) + SRC_im[n] * (sin((2 * pi / N) * k * n));
			DFT_im[k] += SRC_re[n] * (-sin((2 * pi / N) * k * n)) + SRC_im[n] * (cos((2 * pi / N) * k * n));
		}
		pf << k << "," << (2 * pi / N) * k << "," << SRC_re[k] << "," << SRC_im[k] << "," << DFT_re[k] << "," << DFT_im[k] << endl;
	}

	// 出力ファイルCLOSE
	pf.close();
}

/*
 * 逆離散フーリエ変換
 */
void Calc::executeIDFT()
{
	int k, n;  // LOOPインデックス

	// 出力ファイルOPEN
	ofstream pf(idftFilename, ios::out | ios::trunc);

	// ヘッダ出力 ( k, 角周波数, DFT(実部), DFT(虚部), IDFT(実部), IDFT(虚部) )
	pf << "k,\tf,\tX_re,\tX_im,\tx_re,\tx_im\n" << endl;

	// 計算・結果出力
	for (n = 0; n < N; n++)
	{
		IDFT_re[n] = 0.0;
		IDFT_im[n] = 0.0;
		for (k = 0; k < N; k++)
		{
			IDFT_re[n] += DFT_re[k] * (cos((2 * pi / N) * k * n)) - DFT_im[k] * (sin((2 * pi / N) * k * n));
			IDFT_im[n] += DFT_re[k] * (sin((2 * pi / N) * k * n)) + DFT_im[k] * (cos((2 * pi / N) * k * n));
		}
		IDFT_re[n] /= N;
		IDFT_im[n] /= N;
		pf << "," << n << "," << (2 * pi / N) * n << "," << DFT_re[n] << "," << DFT_im[n] << "," << IDFT_re[n] << "," << IDFT_im[n] << endl;
	}

	// 出力ファイルCLOSE
	pf.close();
}

class fft
{
private:
	complex<long double> w[512];
	long	br[512];
	long n;
	long double step;
	long double pi;
	void butterfly(complex<long double> a, complex<long double> b, complex<long double> out[], long k);
	complex<long double> multiplication(complex<long double> a, complex<long double> b);

public:
	fft(long num);
	void difFFT(complex<long double> x[]);
};

fft::fft(long num)
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

void fft::difFFT(complex<long double> x[])
{
	complex<long double> out[2];							// 一時記憶メモリ
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
				butterfly(x[num], x[num2], out, k*roop);
				x[num] = out[0];			// インプレイス
				x[num2] = out[1];			// インプレイス
			}
			bias += 2 * roop2;
		}
		roop2 /= 2;
		roop *= 2;
	}

	complex<long double> buffer;							// ベクトルの要素の入れ替え
	for (long i = 0; i < n; i++)
	{
		if (br[i] > i)
		{
			buffer = x[br[i]];
			x[br[i]] = x[i];
			x[i] = buffer;
		}
	}
}

void fft::butterfly(complex<long double> a, complex<long double> b, complex<long double> out[], long k)
{
	complex<long double> d;
	out[0] = complex<long double>(a.real() + b.real(), a.imag() + b.imag());

	d = complex<long double>(a.real() - b.real(), a.imag() - b.imag());

	out[1] = multiplication(d, w[k]);			// 複素数の積
}

complex<long double> fft::multiplication(complex<long double> a, complex<long double> b)
{
	complex<long double> c;									// 変数 c を 64 ビットの複素数型で宣言

	c = complex<long double>(a.real() * b.real() - a.imag() * b.imag(), a.real() * b.imag() + a.imag() * b.real());	// 複素数 a と b の乗算 

	return c;	// c を返す。
}

long main(long argc, char* argv[])
{
	long n;
	long double ts;
	complex<long double> sf[16384] = { 0.0 };		// 配列 sf[4] を 64 ビットの複素数型で宣言して，"0" に初期化
	char buf[512];

	cout << "DSP1-7 4J23 H.Shiina" << endl;
	cout << "After emitted \"data.txt\", u can get \"one_sec.wav\"." << endl;

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
		// 計算クラスインスタンス化
		Calc objCalc;

		// 元データ作成
		objCalc.makeSourceData();

		// 離散フーリエ変換
		// objCalc.executeDFT();

		// 逆離散フーリエ変換
		// objCalc.executeIDFT();
	}
	catch (...)
	{
		cout << "Caught exception." << endl;
		return EXIT_FAILURE;
	}

	long double pi = acos(-1.0);	// 円周率の算出
	printf(" Ts [second] = ");		// サンプリング周期の入力
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%lf", &ts);
	printf(" N = ");				// 分割数の入力
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d", &n);

	try
	{
		cout << "starting fft..." << endl;
		fft ft(n);

		long double f0 = 1.0 / ((long double)n * ts);													// 基本周波数の計算

		for (long i = 0; i < n; i++)	sf[i] = complex<long double>(1.0 + sin(2.0 * pi * 250.0 * (long double)i * ts));	// 離散時間信号

		ft.difFFT(sf);

		printf("\n");
		printf("f [Hz] FR(kf0) FI(kf0) |F(kf0)|\n");
		for (long i = 0; i < n; i++)
		{
			long double spt = sqrt(sf[i].real() * sf[i].real() + sf[i].imag() * sf[i].imag());
			printf("%6.1f%8.2f%8.2f%9.2f\n", f0 * (long double)i, sf[i].real(), sf[i].imag(), spt);	// 結果表示
		}
		cout << "finished fft..." << endl;
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
