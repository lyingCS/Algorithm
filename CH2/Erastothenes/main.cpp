#include <iostream>
#include<vector>

using namespace std;

const int n=500;
vector<int> vec(n+1,0);

void Allprime(){
    int ceil=sqrt(n);
    for (int i = 2; i < ceil; ++i) {
        if(!vec[i])
        {
            int j=2;
            while(i*j<=n)
            {
                vec[i*j]=1;
                j++;
            }
        }
    }
    for (int k = 2; k < vec.size(); ++k) {
        if(vec[k]==0)
            cout<<k<<" ";
    }
};

int main() {
    Allprime();
    return 0;
}
