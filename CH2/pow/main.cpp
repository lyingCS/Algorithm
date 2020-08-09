#include <iostream>
#include<cmath>
#include<vector>

using namespace std;

using namespace std;

int pow(int x,int n){
    int ans=1;
    int len=log2(n)+1;
    vector<int> a(len);
    a[0]=x;
    for (int i = 1; i < len; ++i) {
        a[i]=a[i-1]*a[i-1];
    }
    int j=0;
    while(n>0)
    {
        if(n%2)
            ans*=a[j];
        j++;
        n=n/2;
    }
    return ans;
}

int main() {
    std::cout << pow(2,4) << std::endl;
    return 0;
}
