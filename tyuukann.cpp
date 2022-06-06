#define _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>
#include    "cglec.h"


//ダイヤモンドを作る関数
void Diamond(Image img,int x0, int y0, int zx)//x0,y0=中心座標　zx=ダイヤのx軸方向の半径
{
    int x1, y1, x2, y2, x3, y3, x4, y4, zy, color;

    zy = 2 * zx; //ダイヤのy軸方向の半径

    x1 = x0 - zx; y1 = y0 - zy; //左下座標
    x2 = x0 + zx; y2 = y0 - zy; //右下座標
    x3 = x0 - zx; y3 = y0 + zy; //左上座標
    x4 = x0 + zx; y4 = y0 + zy; //右上座標

    color = 200;//ダイヤの色
    for (int i = x1; i <= x2; i++) { //楕円の範囲を白で塗りつぶす。
        for (int j = y1; j <= y3; j++) {
            double dx = i - x0, dy = j - y0;
            if ((double)(dx * dx) / (double)(zx * zx) + (double)(dy * dy) / (double)(zy * zy) <= 1
                && i >= 0 && i < img.Nx && j>0 && j < img.Ny) {
                *(img.Data + i * img.Ny + j) = color;
            }   
        }
    }

    for (int x = x1; x < x0; x++) {//楕円の左下を黒く削る
        for (int y = y1; y < y0; y++) {
            double dx = x - x1, dy = y - y1, Dx = x - x0, Dy = y - y0;//dx,dy=削り取る楕円の半径、Dx,Dy=上で作った楕円の半径
            if ((double)(dx * dx) / (double)(zx * zx) + (double)(dy * dy) / (double)(zy * zy) <= 1
                && (double)(Dx * Dx) / (double)(zx * zx) + (double)(Dy * Dy) / (double)(zy * zy) <= 1
                && x >= 0 && x < img.Nx && y>0 && y < img.Ny) {
                *(img.Data + x * img.Ny + y) = 0;
            }
        }
    }

    for (int x = x2; x > x0; x--) {//楕円の右下を黒く削る
        for (int y = y2; y < y0; y++) {
            double dx = x2 - x, dy = y - y2, Dx = x - x0, Dy = y - y0;
            if ((double)(dx * dx) / (double)(zx * zx) + (double)(dy * dy) / (double)(zy * zy) <= 1
                && (double)(Dx * Dx) / (double)(zx * zx) + (double)(Dy * Dy) / (double)(zy * zy) <= 1
                && x >= 0 && x < img.Nx && y>0 && y < img.Ny) {
                *(img.Data + x * img.Ny + y) = 0;
            }
        }
    }

    for (int x = x3; x < x0; x++) {//楕円の左上を黒く削る
        for (int y = y3; y > y0; y--) {
            double dx = x - x1, dy = y3 - y, Dx = x - x0, Dy = y - y0;
            if ((double)(dx * dx) / (double)(zx * zx) + (double)(dy * dy) / (double)(zy * zy) <= 1
                && (double)(Dx * Dx) / (double)(zx * zx) + (double)(Dy * Dy) / (double)(zy * zy) <= 1
                && x >= 0 && x < img.Nx && y>0 && y < img.Ny) {
                *(img.Data + x * img.Ny + y) = 0;
            }
        }
    }

    for (int x = x4; x > x0; x--) {//楕円の左上を黒く削る
        for (int y = y4; y > y0; y--) {
            double dx = x4 - x, dy = y4 - y, Dx = x - x0, Dy = y - y0;
            if ((double)(dx * dx) / (double)(zx * zx) + (double)(dy * dy) / (double)(zy * zy) <= 1
                && (double)(Dx * Dx) / (double)(zx * zx) + (double)(Dy * Dy) / (double)(zy * zy) <= 1
                && x >= 0 && x < img.Nx && y>0 && y < img.Ny) {
                *(img.Data + x * img.Ny + y) = 0;
            }
        }
    }
}

int main(void)
{
    int Nx = 600, Ny = 400;

    unsigned char* data;
    data = (unsigned char*)malloc(sizeof(unsigned char) * Nx * Ny);
    if (data == NULL)               //メモリ割当に失敗か？
    {
        printf("メモリエラー!!");
        exit(0);                    //プログラムを終了する
    }

    Image I = { data, Nx, Ny };
    CglSetAll(I, 0);
    
    

    Diamond(I, Nx - 5, Ny - 5, 2);
    Diamond(I, Nx - 10, Ny - 12, 2);
    Diamond(I, Nx - 15, Ny - 13, 2);
    Diamond(I, Nx - 10, Ny - 5, 2);

    Diamond(I, Nx - 18, Ny - 22, 3);
    Diamond(I, Nx - 25, Ny - 29, 3);
    Diamond(I, Nx - 23, Ny - 17, 3);

    Diamond(I, Nx - 35, Ny - 38, 4);
    Diamond(I, Nx - 32, Ny - 25, 4);
    Diamond(I, Nx - 40, Ny - 32, 4);

    Diamond(I, Nx - 44, Ny - 53, 6);
    Diamond(I, Nx - 55, Ny - 40, 6);
    Diamond(I, Nx - 67, Ny - 63, 7);
    Diamond(I, Nx - 63, Ny - 70, 7);

    Diamond(I, Nx - 75, Ny - 52, 10);
    Diamond(I, Nx - 83, Ny - 82, 10);
    Diamond(I, Nx - 130, Ny - 120, 13);
    Diamond(I, Nx - 110, Ny - 77, 13);

    Diamond(I, Nx - 170, Ny - 150, 15);
    Diamond(I, Nx - 150, Ny - 90, 15);
    Diamond(I, Nx - 220, Ny - 165, 20);
    Diamond(I, Nx - 200, Ny - 110, 20);

    Diamond(I, Nx - 280, Ny - 150, 30);
    Diamond(I, Nx - 320, Ny - 230, 30);

    Diamond(I, Nx - 380, Ny - 180, 40);
    Diamond(I, Nx - 420, Ny - 300, 40);

    Diamond(I, Nx - 525, Ny - 250, 70);

    Diamond(I, Nx / 10 * 8+25, Ny / 10 * 8+25 , 4);

    Diamond(I, Nx / 10 * 8+20, Ny / 10*7+10, 4);
    Diamond(I, Nx / 10 * 8-15, Ny / 10 * 8+15, 4);

    Diamond(I, Nx / 10 * 7, Ny / 10*8, 7);

    Diamond(I, Nx / 10 * 6, Ny / 10*7-5, 8);
    Diamond(I, Nx / 10 * 6+15, Ny / 10 * 7+30, 5);
    Diamond(I, Nx / 10 * 6-20, Ny / 10 * 7+20, 7);
    Diamond(I, Nx / 10 * 6, Ny / 10 * 5, 5);
    Diamond(I, Nx / 10 * 6-20, Ny / 10 * 5+20, 7);

    Diamond(I, Nx / 10 * 5-20, Ny / 10*7, 8);
    Diamond(I, Nx / 10 * 5 - 20, Ny / 10 * 7, 10);
    Diamond(I, Nx / 10 * 5 - 40, Ny / 10 * 7+10, 5);
    Diamond(I, Nx / 10 * 5 - 50, Ny / 10 * 7-30, 7);

    Diamond(I, Nx / 10 * 4, Ny / 10*3, 10);

    Diamond(I, Nx / 10 * 3, Ny / 10*7, 10);
    Diamond(I, Nx / 10 * 3-20, Ny / 10 * 7-20, 6);

    Diamond(I, Nx / 10 * 2, Ny / 10*7, 4);
    Diamond(I, Nx / 10 * 2-10, Ny / 10*6, 12);
    Diamond(I, Nx / 10 * 2+20, Ny / 10 * 5, 15);
    Diamond(I, Nx / 10 * 2, Ny / 10 * 2, 8);
    Diamond(I, Nx / 10 * 2-20, Ny / 10-10, 10);
    Diamond(I, Nx / 10 * 2 + 25, Ny / 10+10, 12);

    Diamond(I, Nx / 20+15, Ny / 20+5, 10);
    Diamond(I, Nx / 20-12, Ny / 10, 10);
    Diamond(I, Nx / 20-10, Ny / 10*2, 5);
    Diamond(I, Nx / 20-5, Ny / 10*3, 3);
    Diamond(I, Nx / 20-5, Ny / 10*5, 5);
    Diamond(I, Nx / 20+10, Ny / 10*6, 10);
    Diamond(I, Nx / 20-12, Ny / 10 * 7-5, 7);
    Diamond(I, Nx / 10-5, Ny / 10 * 2, 4);

    CglSaveGrayBMP(I, "tyuukann.bmp");

    ColorImage c = CglInitColorImage(Nx, Ny);
   

    if (c.Nx == 0) //Nxが0だったらメモリ確保失敗
    {
        printf("メモリエラー");
        exit(0);
    }

    for (int y = 0; y < Ny; y++)
    {
        for (int x = 0; x < Nx; x++)
        {
            for (int z = 0; z < 256; z++) 
            {
                if (*(I.Data + x * I.Ny + y) != 0)
                    CglSetSafePixel(c, x, y, x/3, 0, z*3);
                else
                    CglSetSafePixel(c, x, y, 0, 0, 0);
            }
        }
    }
    for (int y = 0; y < Ny; y++)
    {
        for (int x = 0; x < Nx; x++)
        {
            for (int z = 0; z < 256; z++)
            {
                if (*(I.Data + x * I.Ny + y) == 0)
                    CglSetSafePixel(c, x, y, x/4+100 , y/4+150, z);
            }
        }
    }
    CglSaveColorImage(c, "tyuukann.bmp");
    free(I.Data);                     //メモリ解放
}
