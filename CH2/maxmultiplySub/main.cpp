#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
T maxmultiplySub(vector<T> & vec)
{
    int len=vec.size();
    T maxmul=0;
    vector<T> mmax(len);
    vector<T> mmin(len);
    mmax[0]=vec[0];
    mmin[0]=vec[0];
    for (int i = 1 ; i < len; ++i) {
        mmax[i]=max(vec[i],max(vec[i]*mmax[i-1],vec[i]*mmin[i-1]));
        mmin[i]=min(vec[i],min(vec[i]*mmax[i-1],vec[i]*mmin[i-1]));
        cout<<mmax[i]<<" "<<mmin[i]<<endl;
        if(mmax[i]>maxmul)
            maxmul=mmax[i];
    }

    return maxmul;

}

int main() {
    vector<int> vec {1,2,3,-1,-2,1,1};
    cout<<maxmultiplySub(vec)<<endl;
    return 0;
}
