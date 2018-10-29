// H30 dsp1-6 4J23

// dsp1-6.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
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
	unsigned long byte_sec = 44100;			// １秒あたりのバイト数 (fs×byte_samp)
	unsigned short byte_samp = 4;			// １要素のバイト数 (channel×(bit/8))
	unsigned short bit = 16;				// 量子化ビット数 (8 or 16)
};
static struct SetDataChunk : private DataChunk // dataチャンク構造体
{
	char id[4] = { 'd', 'a', 't', 'a' };	// "data"
	unsigned long size = 11025 * 2;			// data領域のサイズ
};

RiffChunk riff;
FMTChunk fmt;
DataChunk dat;
SetRiffChunk sRiff;
SetFMTChunk sFmt;
SetDataChunk sDat;

int main()
{
	short lbuf = 0, rbuf = 0;
	char outfile[] = "C:\\Users\\TeamET\\Downloads\\kosen\\C\\DSP\\dsp1-6\\Yamaha-V50-E-Piano-1-C4.wav"; //読み込むファイルの指定

	ifstream bfin(outfile, ios::in | ios::binary);
	ofstream tfout("data.txt", ios::out | ios::trunc);
	ofstream bfout("one_sec.wav", ios::out | ios::binary | ios::trunc);

	if (bfin.bad())
	{
		cout << "Failed to opening \"" << outfile << "\"." << endl;
		exit(EXIT_FAILURE);
	}


	bfin.seekg(0, ios_base::beg);
	bfin.read(static_cast<char *>(riff.id), sizeof(riff.id));
	bfin.read(reinterpret_cast<char *>(&riff.size), sizeof(riff.size));    // https://msdn.microsoft.com/ja-jp/library/s3f49ktz.aspx
	bfin.read(static_cast<char *>(riff.form), sizeof(riff.form));     // 曰く、unsigned longは4Byteらしい…
	bfin.read(static_cast<char *>(fmt.id), sizeof(fmt.id));
	bfin.read(reinterpret_cast<char *>(&fmt.size), sizeof(fmt.size));
	bfin.read(reinterpret_cast<char *>(&fmt.format_id), sizeof(fmt.format_id));
	bfin.read(reinterpret_cast<char *>(&fmt.channel), sizeof(fmt.channel));
	bfin.read(reinterpret_cast<char *>(&fmt.fs), sizeof(fmt.fs));
	bfin.read(reinterpret_cast<char *>(&fmt.byte_sec), sizeof(fmt.byte_sec));
	bfin.read(reinterpret_cast<char *>(&fmt.byte_samp), sizeof(fmt.byte_samp));
	bfin.read(reinterpret_cast<char *>(&fmt.bit), sizeof(fmt.bit));
	bfin.read(static_cast<char *>(dat.id), sizeof(dat.size));
	bfin.read(reinterpret_cast<char *>(&dat.size), sizeof(dat.size));

	if (!tfout.bad())
	{
		for (size_t i = 0; i < dat.size / 2; i += 2)
		{
			bfin.read(reinterpret_cast<char *>(&lbuf), sizeof(lbuf));
			tfout << lbuf << endl;
			bfin.read(reinterpret_cast<char *>(&rbuf), sizeof(rbuf));
		}
		tfout.close();
	}
	bfin.close();

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


	exit(0);
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
