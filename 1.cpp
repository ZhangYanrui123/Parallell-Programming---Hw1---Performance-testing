#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


const int N = 10000;                   //数据规模
const int repeat = 10;               //重复次数
clock_t start,finish;
float a[N],b[N][N],col_sum[N];


void init(){                         //矩阵初始化
    for(int i = 0;i <N;i++)
        a[i]= (float)(rand() % 1000 + 1) ;


    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            b[i][j]= (float)(rand() % 1000 + 1) ;

}
int main()
{
    init();
    start = clock();
    for(int i = 0;i<repeat;i++){
 //       init();
        for(int j = 0;j<N;j++){
                col_sum[j] = 0.0;
            for(int i = 0; i<N ; i++)
                col_sum[j] += b[i][j] * a[i];
        }
    }
    finish = clock();
    cout<<"serial:"<<(double)(finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
    double x1 = (double)(finish - start);


    start = clock();
    for(int i = 0;i<repeat;i++){
 //       init();
        for(int i = 0;i<N;i++)
            col_sum[i] = 0.0;
        for(int i = 0; i<N ; i++)
            for(int j = 0;j<N;j++)
                col_sum[j] += b[i][j] * a[i];

    }
    finish = clock();
    cout<<"parallel:"<<(double)(finish - start)/CLOCKS_PER_SEC<<"s"<<endl;
    double x2 = (double)(finish - start);
    cout<<"Acceleration ratio:"<<x1/x2<<endl;
    return 0;
}
