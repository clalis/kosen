// dsp2-4.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// R01	23_Shīna	DSP2-4-3

#include "DWT.h"


using namespace std;

int main()
{
	VectorXf raw_data(8), temp;
	raw_data << 10, 6, 2, 4, 8, 2, 6, 4;

	cout << "R01\t23_Shīna\tDSP2-4-3" << endl << endl;

	DWT* dwt = new DWT(raw_data);

	temp = dwt->enDWT(dwt->data);
	temp = dwt->enDWT(temp);
	dwt->enDWT(temp);

	cout << endl << "List of outer vectors" << endl;
	for (auto& vec : dwt->scalings)	cout << vec.transpose() << endl;
	for (auto& vec : dwt->wavelets)	cout << vec.transpose() << endl;

	cout << endl;
	dwt->deDWT(dwt->deDWT(dwt->deDWT(dwt->scalings.at(2), dwt->wavelets.at(2)), dwt->wavelets.at(1)), dwt->wavelets.at(0));

	dwt->~DWT();
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
