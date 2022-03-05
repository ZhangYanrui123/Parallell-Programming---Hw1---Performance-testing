#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;


const int N = 4666;

double a[N],b[N][N],col_sum[N];

void init(){
    for(int i = 0;i <N;i++)
        a[i] = i;
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            b[i][j] = i + j;
}
int main()
{
    long long head,tail,freq;
    init();

    bool test1 = QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
    bool test2 = QueryPerformanceCounter((LARGE_INTEGER *)&head);
    for(int j = 0;j<N;j++){
            col_sum[j] = 0.0;
        for(int i = 0; i<N ; i++)
            col_sum[i] += b[i][j] * a[i];
    }
    bool test3 = QueryPerformanceCounter((LARGE_INTEGER *)&tail);
    for(int i = 0; i< N;i++)
        cout<<col_sum[i]<<" ";
    cout<<endl;
    cout<<"Freq:"<<freq<<",test1:"<<test1<<endl;
    cout<<"Head:"<<head<<",test2:"<<test2<<endl;
    cout<<"Tail:"<<tail<<",test3:"<<test3<<endl;
    cout<<"Col:"<<(tail - head)*1000/freq<<"ms"<<endl;


    return 0;
}
