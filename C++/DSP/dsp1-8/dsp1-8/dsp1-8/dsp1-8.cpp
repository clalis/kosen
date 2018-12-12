// dsp1-8.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"

using namespace std;

class FIR
{
public:
	FIR() :h(vector<double>(_sample, 0)), x(vector<double>(_N, 0)), i(0), y(0.0)
	{
		finame.push_back("data.txt");
		finame.push_back("dfilter.txt");
		finame.push_back("efilter.txt");
		finame.push_back("afilter.txt");
		foname.push_back("ddata.txt");
		foname.push_back("edata.txt");
		foname.push_back("adata.txt");

		fin.resize(finame.size());
		fout.resize(foname.size());

		i = 0;
		for (auto v : finame)
		{
			fin.at(i).open(v, ios::in);
			if (fin.at(i).bad())	exit(EXIT_FAILURE);
			i++;
		}

		i = 0;
		for (auto v : foname)
		{
			fout.at(i).open(v, ios::out | ios::trunc);
			if (fout.at(i).bad())	exit(EXIT_FAILURE);

			i++;
			filt(i);
		}
	}
	~FIR()
	{
		x.clear();
		h.clear();
	}
	void filt(int patt);
	static const int _N = 11025;
	static const int _sample = _N;

private:
	vector<ifstream> fin;
	vector<ofstream> fout;
	vector<string> finame, foname;
	vector<double> h, x;
	size_t i;
	double y;
};

void FIR::filt(int patt)
{
	fin.front().seekg(0, ios_base::beg);
	for (size_t i = 0; (i < h.size()) || fin.at(patt).eof(); i++)
	{
		fin.at(patt) >> h.at(i);
		if (fin.at(patt).bad() || fin.at(patt).eof())	break;
	}

	for (size_t i = 0; i < _sample + (_N - 1); i++)
	{
		for (size_t n = (_N - 1); n > 0; n--) x.at(n) = x.at(n - 1);
		if (!(fin.front().bad() || fin.front().eof()))	fin.front() >> x.front();
		else	x.front() = 0;

		y = inner_product(h.begin(), h.end(), x.begin(), 0.0);
		fout.at(patt - 1) << y << endl;
	}
}

int main(int argc, char** argv)
{
	cout << "H30\tDSP1-8\t4J23 Shiina" << endl << "Put a data file into the same directory." << endl << "U can get 3 effected files." << endl;

	FIR filter;
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
