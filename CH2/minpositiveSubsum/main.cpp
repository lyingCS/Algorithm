#include <iostream>
#include<vector>

using namespace std;

template<typename T>
int minpositiveSubSum(vector<T> & vec)
{
    vector<T> sum(vec.size()+1);
    sum[0]=0;
    T Thismin,min=INT_MAX;
    for (int i = 1; i < vec.size()+1; ++i) {
        sum[i]=sum[i-1]+vec[i-1];
    }
    for (int j = 0; j < sum.size()-1; ++j) {
        for (int i = j+1; i <sum.size(); ++i) {
            Thismin=sum[i]-sum[j];
            if(Thismin<min&&Thismin>0)
                min=Thismin;
        }
    }
    return min;
}

int main() {
    vector<int> vec {89,2,3,-1,-2,3,78};
    cout << minpositiveSubSum(vec);
    return 0;
}
