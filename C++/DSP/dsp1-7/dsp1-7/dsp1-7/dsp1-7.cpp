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

int main()
{
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
		objCalc.executeDFT();

		// 逆離散フーリエ変換
		objCalc.executeIDFT();
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
