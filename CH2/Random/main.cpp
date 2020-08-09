#include<ctime>
#include<random>
#include<sys/timeb.h>
#include <Windows.h>
#include<iostream>
#include<cstdio>

using namespace std;

const int n= 10;
int Rand(int _min, int _max)
{
    int temp;
    if (_min > _max)
    {
        temp = _max;
        _max = _min;
        _min = temp;
    }
    return rand() / (double)RAND_MAX *(_max - _min) + _min;
}

int main() {
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<> u(1,n);
    double run_time;
    LARGE_INTEGER time_start;
    LARGE_INTEGER time_over;
    double dqFreq;
    LARGE_INTEGER f;
    QueryPerformanceFrequency(&f);
    dqFreq=(double)f.QuadPart;
    int a[n];
    int temp;
    int i,j;
    bool used[n+1]={0};
    QueryPerformanceCounter(&time_start);
    /*for (i = 0; i < n; ++i) {       //algorithm 1
        temp=u(e);
        for (j = 0; j < i; ++j) {
            if(a[j]==temp)
                break;
        }
        if(j==i)
            a[i]=temp;
        else
            i--;
    }*/
    /*for (i = 0; i < n; ++i) {       //algorithm 2
        temp=u(e);
        if(!used[temp])
        {
            a[i]=temp;
            used[temp]=true;
        }
        else
            i--;
    }*/
    for (int k = 0; k < n; ++k) {
        a[k]=k+1;
    }
    for (int l = 1; l < n; ++l) {
        swap(a[l],a[Rand(0,l)]);
    }
    for(int k:a)
        cout<<k<<" ";
    QueryPerformanceCounter(&time_over);
    run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
    printf("\nrun_time:%fus\n",run_time);
    cin.get();
    return 0;
}