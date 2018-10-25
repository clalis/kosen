// H30 dsp1-6 4J23

// dsp1-6.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"


using namespace std;

struct RiffChunk // RIFFチャンクおよびWAVEフォームタイプ構造体
{
    char id[4];         // "RIFF"
    unsigned long size; // ファイルサイズ-8
    char form[4];       // "WAVE"
};
struct FMTChunk // fmtチャンク構造体
{
    char id[4];               // "fmt " スペースも含まれるので注意
    unsigned long size;       // fmt領域のサイズ
    unsigned short format_id; // フォーマットID (PCM:1)
    unsigned short channel;   // チャネル数 (モノラル:1 ステレオ:2)
    unsigned long fs;         // サンプリング周波数
    unsigned long byte_sec;   // １秒あたりのバイト数（fs×byte_samp)
    unsigned short byte_samp; // １要素のバイト数（channel×(bit/8)）
    unsigned short bit;       // 量子化ビット数（8 or 16）
};
struct DataChunk // dataチャンク構造体
{
    char id[4];               // "data"
    unsigned long size;       // data領域のサイズ
};

RiffChunk riff;
FMTChunk fmt;
DataChunk dat;

int main()
{
    char outfile[] = "C:\\Users\\TeamET\\Downloads\\kosen\\C\\DSP\\dsp1-6\\Yamaha-V50-E-Piano-1-C4.wav"; //読み込むファイルの指定

    ifstream fin(outfile, ios::in | ios::binary);
    if (!fin)
    {
        cout << "Failed to opening \"" << outfile << "\".\n";
        exit(EXIT_FAILURE);
    }

    fin.seekg(0, ios_base::beg);
    fin.read((char *)riff.id, sizeof(riff.id));
    fin.read((char *)&riff.size, sizeof(riff.size));    // https://msdn.microsoft.com/ja-jp/library/s3f49ktz.aspx
    fin.read((char *)riff.form, sizeof(riff.form));     // 曰く、unsigned longは4Byteらしい…
    fin.read((char *)fmt.id, sizeof(fmt.id));
    fin.read((char *)&fmt.size, sizeof(fmt.size));
    fin.read((char *)&fmt.format_id, sizeof(fmt.format_id));
    fin.read((char *)&fmt.channel, sizeof(fmt.channel));
    fin.read((char *)&fmt.fs, sizeof(fmt.fs));
    fin.read((char *)&fmt.byte_sec, sizeof(fmt.byte_sec));
    fin.read((char *)&fmt.byte_samp, sizeof(fmt.byte_samp));
    fin.read((char *)&fmt.bit, sizeof(fmt.bit));
    fin.read((char *)dat.id, sizeof(typeid(dat.id).name()));
    fin.read((char *)&dat.size, sizeof(dat.size));

    cout << dat.size << endl;

    fin.close();
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
