#include <iostream>
#include<vector>

using namespace std;

template<typename T>
int binarysearch(vector<T> & vec,T x)
{
    int low=0,high=vec.size()-1,mid;
    while(low<high)
    {
        mid=(low+high)/2;
        if (vec[mid]<x)
        {
            low=mid+1;
        }
        else /*if(vec[mid]>x)*/
        {
            high=mid;
        }/*
        else return mid;*/
    }
    if(vec[low]==x)
        return low;
    return -1;
}

int main() {
    vector<int> vec={1,2,3,4,5,6,7,8,9,10};
    cout<< binarysearch(vec,1);
    return 0;
}
