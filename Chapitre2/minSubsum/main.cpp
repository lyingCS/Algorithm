#include <iostream>
#include<vector>

using namespace std;

template<typename T>
int minSubSum(vector<T>&vec){
    int ThisSum=0,TotalSum=0;
    for(int x:vec){
        ThisSum+=x;
        if(TotalSum>ThisSum){
            TotalSum=ThisSum;
        }
        if(ThisSum>=0)
            ThisSum=0;
    }
    return TotalSum;
};

int main() {
    vector<int> vec{1,2,3,-1,-1,-1,2,3,-7,6,1};
    cout<<minSubSum(vec);
    return 0;
}
