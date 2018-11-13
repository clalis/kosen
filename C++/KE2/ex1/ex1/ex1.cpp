// ex1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

#include "pch.h"


using namespace std;

vector<vector<int>> loadData(string fname);
vector<float> mean(vector<vector<int>> v);
void saveData(string fname, vector<float> v);

int main() {
	vector<vector<int>> d = loadData("../../kadai-1-data/c01.txt");

	//for (auto &item : d[0]) {
	//	cout << item << endl;
	//}

	//for (auto &item : mean(d)) {
	//	cout << item << endl;
	//}

	saveData("mean01.txt", mean(d));

	return 0;
}

vector<vector<int>> loadData(string fname)
{
	ifstream ifs(fname);
	vector<int> input((istream_iterator<int>(ifs)), istream_iterator<int>());
	vector<vector<int>> data(CHA_N, vector<int>(LET_N, 0));

	for (size_t i = 0; i < CHA_N; i++)
	{
		for (size_t j = 0; j < LET_N; j++)
		{
			data[i][j] = input[i * CHA_N + j];
		}
	}

	ifs.close();
	return data;
}

vector<float> mean(vector<vector<int>> v)
{
	vector<float> sumv(LET_N, 0);

	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			sumv[j] += v[i][j];
		}
	}
	for (size_t i = 0; i < LET_N; i++)
	{
		sumv[i] /= LET_N;
	}

	return sumv;
}

void saveData(string fname, vector<float> v)
{
	ofstream ofs(fname, ios::out | ios::trunc);


	if (!ofs.bad())
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			ofs << v[i] << endl;
		}
	}
	ofs.close();
}
