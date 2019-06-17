// dsp2-2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// R01	23_Shīna	DSP2-2-3

#include "DSP.h"

using namespace Eigen;
using namespace std;

int main()
{
	const string file_name = "..\\dsp2-2_files\\samp.bmp";
	rgb_t colour;
	const static Vector4f oned(1, 2, 3, 4);
	static Matrix4f twod;
	twod <<
		1, 1, 1, 1,
		2, 1, 2, 1,
		3, 1, 3, 1,
		4, 1, 4, 1;

	Vector4f onedDCT = Vector4f::Zero(), onedIDCT = Vector4f::Zero();
	Matrix4f twodDCT = Matrix4f::Zero();
	DCT dct(static_cast<int>(oned.size()));

	cout << "R01\t23_Shīna\tDSP2-2-3\n\n";

	bitmap_image image(file_name);
	if (!image)
	{
		cout << "- Error - Failed to open " << file_name.c_str() << endl;
		exit(EXIT_FAILURE);
	}

	image.get_pixel(0, 119, colour);
	cout << "R\tG\tB" << endl
		<< static_cast<unsigned int>(colour.red) << "\t"
		<< static_cast<unsigned int>(colour.green) << "\t"
		<< static_cast<unsigned int>(colour.blue) << endl;
	image.get_pixel(79, 78, colour);	// 40, 79
	cout << static_cast<unsigned int>(colour.red) << "\t"
		<< static_cast<unsigned int>(colour.green) << "\t"
		<< static_cast<unsigned int>(colour.blue) << endl;
	image.get_pixel(119, 0, colour);
	cout << static_cast<unsigned int>(colour.red) << "\t"
		<< static_cast<unsigned int>(colour.green) << "\t"
		<< static_cast<unsigned int>(colour.blue) << endl;

	//onedDCT = dct.cnk() * oned;
	//onedIDCT = dct.cnk().transpose() * onedDCT;

	//cout << "DCT :\n" << onedDCT << endl;
	//cout << "IDCT :\n" << onedIDCT << endl;

	//twodDCT = dct.cnk() * twod * dct.cnk().transpose();

	//cout << "DCT :\n" << twodDCT << endl;
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
