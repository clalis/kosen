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
vector<vector<float>> covar(vector<vector<int>> v);
vector<float> mean(vector<vector<int>> v);
void saveData(string fname, vector<float> v);
void saveData(string fname, vector<vector<float>> v);

int main()
{
	vector<vector<int>> d = loadData("../../kadai-1-data/c01.txt");

	//for (auto &item : d.front()) {
	//	cout << item << endl;
	//}

	//for (auto &item : mean(d)) {
	//	cout << item << endl;
	//}

	for (size_t i = 1; i <= 1; i++)
	{
		string mean_fn, covar_fn;
		if (i < 10)
		{
			mean_fn = "../../kadai-1-data/mean/mean0" + to_string(i) + ".txt";
			covar_fn = "../../kadai-1-data/sigma/sigma0" + to_string(i) + ".txt";
		}
		else
		{
			mean_fn = "../../kadai-1-data/mean/mean" + to_string(i) + ".txt";
			covar_fn = "../../kadai-1-data/sigma/sigma" + to_string(i) + ".txt";
		}
		//saveData(mean_fn, mean(d));
		//saveData(covar_fn, covar(d));
	}

	return 0;
}

vector<vector<int>> loadData(string fname)
{
	ifstream ifs(fname);
	vector<int> input((istream_iterator<int>(ifs)), istream_iterator<int>());
	vector<vector<int>> data(LET_N, vector<int>(FEA_N, 0));

	for (size_t i = 0; i < LET_N; i++)
	{
		for (size_t j = 0; j < FEA_N; j++)
		{
			data[i][j] = input[i * FEA_N + j];
		}
	}

	ifs.close();
	return data;
}

vector<float> mean(vector<vector<int>> v)
{
	vector<float> avev(v.front().size(), 0);

	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v.front().size(); j++)
		{
			avev[j] += v[i][j];
		}
	}
	for (size_t i = 0; i < avev.size(); i++)	avev[i] /= v.size();

	return avev;
}

vector<vector<float>> covar(vector<vector<int>> v)
{
	vector<vector<float>> ans(FEA_N, vector<float>(FEA_N, 0.0f));
	vector<float> mi, mj;
	long sum = 0;

	for (size_t i = 0; i < ans.size(); i++)
	{
		for (size_t j = i; j < ans.size(); j++)
		{
			sum = 0;
			mi.clear();
			mj.clear();
			for (size_t k = 0; k < LET_N; k++)
			{
				sum += v[k][i] * v[k][j];

				mi.push_back(v[k][i]);
				mj.push_back(v[k][j]);
			}
			// NOT "inner_product(mi.begin(), mi.end(), mj.begin(), 0.0f);" but average...
			ans[i][j] = (sum / LET_N) - (accumulate(mi.begin(), mi.end(), 0.0) / mi.size() * accumulate(mj.begin(), mj.end(), 0.0) / mj.size());
			ans[j][i] = ans[i][j];
			//float fa = sum / LET_N;
			//float f = accumulate(mi.begin(), mi.end(), 0.0) / mi.size() * accumulate(mj.begin(), mj.end(), 0.0) / mj.size();
			//cout << fa << f;
		}
	}

	return ans;
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

void saveData(string fname, vector<vector<float>> v)
{
	ofstream ofs(fname, ios::out | ios::trunc);

	if (!ofs.bad())
	{
		for (auto vi : v) {
			for (auto vj : vi) {
				ofs << vj << "\t";
			}
			ofs << endl;
		}
	}
	ofs.close();
}
