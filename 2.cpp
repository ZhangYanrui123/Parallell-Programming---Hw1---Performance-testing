#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;


const int N = pow(2,20);                 //数据规模
const int repeat = 75466;               //重复次数
clock_t start,finish;
double a[N];
float sum = 0;

void init(){                         //数组初始2化
    for(int i = 0;i <N;i++){
        a[i]= (float)(rand() % 1000 + 1) ;
   }
}

void serial(){
    init();
    for(int i = 0;i <repeat;i++){
 //       init();
        for(int j = 0;j<N;j++)
            sum += a[j];
    }
}

void parallel8(){
    init ();
    for(int i = 0;i <repeat;i++){
  //      init();
        int sum1=0,sum2=0,sum3 = 0,sum4= 0,sum5 =0,sum6=0,sum7=0,sum8=0;
        for(int j = 0;j<N;j+=8){
            sum1 += a[j];
            sum2 += a[j+1];
            sum3 += a[j+2];
            sum4 += a[j+3];
            sum5 += a[j+4];
            sum6 += a[j+5];
            sum7 += a[j+6];
            sum8 += a[j+7];
        }
        int sum = sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8;
    }
}

void parallel4(){
    init ();
    for(int i = 0;i <repeat;i++){
  //      init();
        int sum1=0,sum2=0,sum3 = 0,sum4 = 0;
        for(int j = 0;j<N;j+=4){
            sum1 += a[j];
            sum2 += a[j+1];
            sum3 += a[j+2];
            sum4 += a[j+3];
        }
        int sum = sum1+sum2+sum3+sum4;
    }
}

void parallel2(){
    init ();
    for(int i = 0;i <repeat;i++){
   //     init();
        int sum1=0,sum2=0;
        for(int j = 0;j<N;j+=2){
            sum1 += a[j];
            sum2 += a[j+1];
        }
        int sum = sum1+sum2;
    }
}

void recursion(int n){
    if (n == 1)
        return;
    else{
        for (int i = 0; i < n / 2; i++)
           a[i] += a[n-1-i];
        n = n / 2;
        recursion(n);
    }
}
void recurse(){
    init();
    for(int i = 0;i<repeat;i++){
  //      init();
        recursion(N);
    }
}

void dicycle(){
    init();
    for(int i = 0;i < repeat;i++){
  //      init();
        for(int j = N;j>1;j/=2){
            for(int k = 0;k<j/2;k++){
               // a[k] = a[k*2];
               // a[k]+= a[k*2+1];
                a[k] = a[k*2] + a[k*2+1];
            }
        }
    }
}
void dicycle2(){
    init();
    for(int i = 0;i < repeat;i++){
 //       init();
        for(int j = N;j>1;j/=2){
            for(int k = 0;k<j/2;k++){
                a[k] = a[k*2];
                a[k]+= a[k*2+1];
            }
        }
    }
}
int main()
{

    //串行
    start = clock();
    serial();
    finish = clock();
    double x1 = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"serial:"<<x1<<"s"<<endl;
    //多链
    start = clock();
    parallel2();
    finish = clock();
    double x2 = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"parallel2:"<<x2<<"s"<<endl;
    cout<<"Acceleration Ratio1:"<<x1/x2<<endl;
    //多链
    start = clock();
    parallel4();
    finish = clock();
    double x3 = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"parallel4:"<<x3<<"s"<<endl;
    cout<<"Acceleration Ratio2:"<<x1/x3<<endl;
    //多链
    start = clock();
    parallel8();
    finish = clock();
    double x4 = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"parallel8:"<<x4<<"s"<<endl;
    cout<<"Acceleration Ratio3:"<<x1/x4<<endl;
/*    //递归
    start = clock();
    recurse();
    finish = clock();
    double x5 = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"recursion:"<<x5<<"s"<<endl;
    cout<<"Acceleration Ratio4:"<<x1/x5<<endl;
    //二重循环
    start = clock();
    dicycle();
    finish = clock();
    double x6 = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"dicycle:"<<x6<<"s"<<endl;
    cout<<"Acceleration Ratio5:"<<x1/x6<<endl;
    start = clock();
    dicycle2();
    finish = clock();
    double x7= (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"dicycle2:"<<x7<<"s"<<endl;
    cout<<"Acceleration Ratio6:"<<x1/x7<<endl;*/
    return 0;
}
