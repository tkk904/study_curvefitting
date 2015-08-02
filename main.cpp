
#include <stdio.h>
#include <stdlib.h>
 
#define NMAX 100    /* 配列最大要素数 */
 
double lambda(int, int, double, double *);    /* λ(x)を求める関数 */
 
int main(void)
{
    int i;
    int n;    /* データの個数 */
 
    double x;    /* x */
    double f;    /* f(x) */
 
    double data_x[NMAX];    /* データのx */
    double data_f[NMAX];    /* データのf(x) */
 
    FILE *input;
    FILE *output;
 
    /* ファイルオープン処理 */
    input = fopen("input.dat", "r");
    output = fopen("output.dat", "w");
 
    /* 配列初期化 */
    for(i = 0 ; i < NMAX ; i++)
    {
        data_x[i] = 0.0;
        data_f[i] = 0.0;
    }
 
    i = 0;    /* 一度使ったiを0に初期化 */
    
    /* ファイルからデータを取得 */
    while(fscanf(input, "%lf%lf", &data_x[i], &data_f[i]) != EOF)
    {
        i++;    /* 次のデータを、次の配列要素に入れるためにインクルメント */
        n = i;    /* データの個数を代入 */
    }
 
    /* ラグランジュの補間公式に基づく処理 */
    for(x = data_x[0] ; x < data_x[n-1] ; x += 0.1)
    {
        f = 0.0;
        for(i = 0 ; i < n ; i++)
        {
            f += data_f[i] * lambda(i, n, x, data_x);
        }
 
        fprintf(output, "%f %f\n", x, f);    /* ファイルへ書き込み */
    }
 
    fclose(input);    /* ファイルを閉じる */
    fclose(output);    /* ファイルを閉じる */
 
    return 0;
}
 
/* λ(x)を求める関数 */
double lambda(int i, int n, double x, double data_x[])
{
    int j;
    double lam = 1.0;
 
    for(j = 0 ; j < n ; j++)
    {
        if(i != j)
        {
            lam *= (x - data_x[j])/(data_x[i] - data_x[j]);
        }
    }
 
    return lam;
}
 

