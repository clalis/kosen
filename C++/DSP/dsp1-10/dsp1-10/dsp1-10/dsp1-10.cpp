// dsp1-10.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"


using namespace std;

struct RiffChunk // RIFFチャンクおよびWAVEフォームタイプ構造体
{
	char id[4];			// "RIFF"
	unsigned long size;	// ファイルサイズ-8
	char form[4];		// "WAVE"
};
struct FMTChunk // fmtチャンク構造体
{
	char id[4];					// "fmt " スペースも含まれるので注意
	unsigned long size;			// fmt領域のサイズ
	unsigned short format_id;	// フォーマットID (PCM:1)
	unsigned short channel;		// チャネル数 (モノラル:1 ステレオ:2)
	unsigned long fs;			// サンプリング周波数
	unsigned long byte_sec;		// １秒あたりのバイト数 (fs×byte_samp)
	unsigned short byte_samp;	// １要素のバイト数 (channel×(bit/8))
	unsigned short bit;			// 量子化ビット数 (8 or 16)
};
struct DataChunk // dataチャンク構造体
{
	char id[4];					// "data"
	unsigned long size;			// data領域のサイズ
};
static struct SetRiffChunk : private RiffChunk // RIFFチャンクおよびWAVEフォームタイプ構造体
{
	char id[4] = { 'R', 'I', 'F', 'F' };	// "RIFF"
	unsigned long size = 11025 * 2 + 36;	// ファイルサイズ-8
	char form[4] = { 'W', 'A', 'V', 'E' };	// "WAVE"
};
static struct SetFMTChunk : private FMTChunk // fmtチャンク構造体
{
	char id[4] = { 'f', 'm', 't', ' ' };	// "fmt " スペースも含まれるので注意
	unsigned long size = 16;				// fmt領域のサイズ
	unsigned short format_id = 1;			// フォーマットID (PCM:1)
	unsigned short channel = 2;				// チャネル数 (モノラル:1 ステレオ:2)
	unsigned long fs = 11025;				// サンプリング周波数
	unsigned long byte_sec = 11025 * 4;		// １秒あたりのバイト数 (fs×byte_samp)
	unsigned short byte_samp = 4;			// １要素のバイト数 (channel×(bit/8))
	unsigned short bit = 16;				// 量子化ビット数 (8 or 16)
};
static struct SetDataChunk : private DataChunk // dataチャンク構造体
{
	char id[4] = { 'd', 'a', 't', 'a' };	// "data"
	unsigned long size = 11025 * 4;			// data領域のサイズ
};

class RandomGen
{
public:
	RandomGen() : norm(0.0, 1.0)
	{
		mt.seed(rd());
	}

	double mersenneTwister(void) { return norm(mt); }

	void filteringWhite()
	{
		ifstream twin("C:\\Users\\s_cla\\Documents\\repos\\kosen\\C++\\DSP\\dsp1-10\\examples\\w_imp50.txt", ios::in);
		ofstream tdout("white_d.txt", ios::out | ios::trunc);
		ofstream tyout("white_y.txt", ios::out | ios::trunc);
		ofstream teout("white_e.txt", ios::out | ios::trunc);
		ofstream terrout("white_rrror.txt", ios::out | ios::trunc);
		vector<short> x(MAX_LEN);
		vector<double> w(MAX_LEN), h(MAX_LEN, 0.0);
		int sample = 11025, n = 50;
		double temp, d, y, e = 0.0, past, norm;

		if (twin.bad() || tdout.bad() || tyout.bad() || teout.bad() || terrout.bad())
		{
			cerr << "error" << endl;
			exit(EXIT_FAILURE);
		}

		while (twin >> temp)
		{
			cout << temp << endl;
			w.push_back(temp);
		}

		for (size_t i = 0; i < sample; i++)
		{
			d = 0.0;
			y = 0.0;
			norm = 0.0;
			past = e;

			for (size_t j = n - 1; j > 0; j--)	x[j] = x[j - 1];

			if (i < sample - (n - 1))	x[0] = mersenneTwister();
			else	x[0] = 0.0;

			for (size_t j = 0; j < n; j++)
			{
				d += x[j] * w[j];
				y += x[j] * h[j];
				norm += x[j] * x[j];
			}

			e = d - y;

			for (size_t j = 0; j < n; j++)	h[j] += (1.0 / (norm + 0.0000001)) * x[j] * e;

			tdout << d << endl;
			tyout << y << endl;
			teout << e << endl;

			if ((e*e) != 0.0)	tdout << 10 * log10(pow(e, 2.0)) << endl;
			else
			{
				tdout << 10 * log10(pow(past, 2.0)) << endl;
				e = past;
			}
		}
	}

	~RandomGen()
	{
	}

private:
	random_device rd;
	mt19937_64 mt;
	normal_distribution<> norm;
	static const int MAX_LEN = 11025;
};

RiffChunk riff;
FMTChunk fmt;
DataChunk dat;
SetRiffChunk sRiff;
SetFMTChunk sFmt;
SetDataChunk sDat;

int main()
{
	RandomGen rndGen;
	short lbuf = 0, rbuf = 0;
	char outfile[] = "C:\\Users\\TeamET\\Downloads\\kosen\\C\\DSP\\dsp1-10\\WAON_WAVE.wav"; //読み込むファイルの指定

	//ifstream bfin(outfile, ios::in | ios::binary);
	//ofstream tfout("data.txt", ios::out | ios::trunc);
	ofstream bfout("one_sec.wav", ios::out | ios::binary | ios::trunc);

	cout << "DSP1-6 4J23 H.Shiina" << endl;
	cout << "After opened \"w_imp50.txt\", u can get \"***.wav\"." << endl;

	rndGen.filteringWhite();

	//if (bfin.bad())
	//{
	//	cout << "Failed to opening \"" << outfile << "\"." << endl;
	//	exit(EXIT_FAILURE);
	//}

	//bfin.seekg(0, ios_base::beg);
	//bfin.read(static_cast<char *>(riff.id), sizeof(riff.id));
	//bfin.read(reinterpret_cast<char *>(&riff.size), sizeof(riff.size));    // https://msdn.microsoft.com/ja-jp/library/s3f49ktz.aspx
	//bfin.read(static_cast<char *>(riff.form), sizeof(riff.form));     // 曰く、unsigned longは4Byteらしい…
	//bfin.read(static_cast<char *>(fmt.id), sizeof(fmt.id));
	//bfin.read(reinterpret_cast<char *>(&fmt.size), sizeof(fmt.size));
	//bfin.read(reinterpret_cast<char *>(&fmt.format_id), sizeof(fmt.format_id));
	//bfin.read(reinterpret_cast<char *>(&fmt.channel), sizeof(fmt.channel));
	//bfin.read(reinterpret_cast<char *>(&fmt.fs), sizeof(fmt.fs));
	//bfin.read(reinterpret_cast<char *>(&fmt.byte_sec), sizeof(fmt.byte_sec));
	//bfin.read(reinterpret_cast<char *>(&fmt.byte_samp), sizeof(fmt.byte_samp));
	//bfin.read(reinterpret_cast<char *>(&fmt.bit), sizeof(fmt.bit));
	//bfin.read(static_cast<char *>(dat.id), sizeof(dat.size));
	//bfin.read(reinterpret_cast<char *>(&dat.size), sizeof(dat.size));

	//if (!tfout.bad())
	//{
	//	for (size_t i = 0; i < dat.size / 2; i += 2)
	//	{
	//		bfin.read(reinterpret_cast<char *>(&lbuf), sizeof(lbuf));
	//		tfout << lbuf << endl;
	//		bfin.read(reinterpret_cast<char *>(&rbuf), sizeof(rbuf));
	//		tfout << rbuf << endl;
	//	}
	//	tfout.close();
	//}
	//bfin.close();

	ifstream tfin("data.txt", ios::in);
	if (!tfin.bad())
	{
		//cout << tfin.rdbuf();

		if (!bfout.bad())
		{
			signed int i = 0;
			bfout.write(static_cast<const char *>(sRiff.id), sizeof(sRiff.id));
			bfout.write(reinterpret_cast<const char *>(&sRiff.size), sizeof(sRiff.size));
			bfout.write(static_cast<const char *>(sRiff.form), sizeof(sRiff.form));
			bfout.write(static_cast<const char *>(sFmt.id), sizeof(sFmt.id));
			bfout.write(reinterpret_cast<const char *>(&sFmt.size), sizeof(sFmt.size));
			bfout.write(reinterpret_cast<const char *>(&sFmt.format_id), sizeof(sFmt.format_id));
			bfout.write(reinterpret_cast<const char *>(&sFmt.channel), sizeof(sFmt.channel));
			bfout.write(reinterpret_cast<const char *>(&sFmt.fs), sizeof(sFmt.fs));
			bfout.write(reinterpret_cast<const char *>(&sFmt.byte_sec), sizeof(sFmt.byte_sec));
			bfout.write(reinterpret_cast<const char *>(&sFmt.byte_samp), sizeof(sFmt.byte_samp));
			bfout.write(reinterpret_cast<const char *>(&sFmt.bit), sizeof(sFmt.bit));
			bfout.write(static_cast<const char *>(sDat.id), sizeof(sDat.size));
			bfout.write(reinterpret_cast<const char *>(&sDat.size), sizeof(sDat.size));
			for (string line; getline(tfin, line);)
			{
				i = static_cast<short>(stoi(line.c_str()));
				bfout.write(reinterpret_cast<const char *>(&i), sizeof(static_cast<short>(i)));
			}

			tfin.close();
			bfout.close();
		}
		else
		{
			cout << "Failed to create \"one_sec.wav\" file." << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cout << "Failed to opening ""data.txt""." << endl;
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
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
