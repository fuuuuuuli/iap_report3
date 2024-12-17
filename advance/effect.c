#include <stdio.h>     // 標準入出力ヘッダのインクルード
#include "ppmlib2.h"   // 画面表示部をカットした ppmlib.h
#include "makefname.c" // 連番ファイル名の作成

// 関数のプロトタイプ宣言（makefname.c中の関数）
void make_filename(char head[], int keta, int num, char fname[]);

// main関数の始まり
int main(void)
{
    int i;           // i:入力ファイル番号
    char fname[256]; // ファイル名用配列（入出力兼用）
    int x, y, col,check;   // 制御変数

    printf("原画像のフレームの赤と青の要素を少しずらします。\n");
    for (i = 0; i <= 85;i++)
    {
        make_filename("org_ppm/org_frame_", 5, i, fname); // 5:数字の桁数
        printf("Opening file: %s\n", fname); // デバッグメッセージを追加
        // 画像をNo.0に読み込む
        load_color_image(0, fname);
        copy_color_image(0, 1);
        // 画像を反転させる
        for (y = 0; y < height[0]; y++)
        {
            for (x = 0; x < width[0]; x++)
            {
                if(y>5&&x<width[0]-10){
                    image[1][x][y][0] = image[0][x+10][y-5][0]*0.7+image[0][x][y][0]*0.3;
                }
                if(y>10&&x>5){
                    image[1][x][y][1] = image[0][x-5][y-10][2]*0.7+image[0][x][y][2]*0.3;
                }
            }
        }
        // 出力ファイル名（out00001.ppm～out00200.ppm）を作る
        make_filename("output/out", 5, i, fname);
        // 画像の保存
        save_color_image(1, fname);
    }
    printf("結果画像を out00001.ppm～out00200.ppm で出力しました\n");
    return 0; // プログラムの正常終了
}
