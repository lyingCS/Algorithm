#include <iostream>
#include<vector>

using namespace std;
int findadd(vector<int>& vec){
    int max=0;
    for(int x:vec)
    {
        if(x>max)
            max=x;
    }
    return 2*max;
}

int findmul(vector<int>& vec){
    int max=0;
    for(int x:vec)
    {
        if(x>max)
            max=x;
    }
    return max*max;
}

int findminus(vector<int>&vec)
{
    int max=0,min=INT_MAX;
    int maxi,mini;
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i]>max)
        {
            maxi=i;
            max=vec[i];
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i]<min)
        {
            mini=i;
            min=vec[i];
        }
    }
    if(maxi>=mini)
        return max-min;
    else{
        int _max=0,_min=INT_MAX;
        for (int i = 0; i <= maxi; ++i) {
            if(vec[i]<_min)
                _min=vec[i];
        }
        for (int i = mini; i < vec.size(); ++i) {
            if(vec[i]>_max)
                _max=vec[i];
        }
        return max-_min>_max-min?max-_min:_max-min;
    }
}

double finddev(vector<int>&vec)
{
    int max=0,min=INT_MAX;
    int maxi,mini;
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i]>max)
        {
            maxi=i;
            max=vec[i];
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i]<min)
        {
            mini=i;
            min=vec[i];
        }
    }
    if(maxi>=mini)
        return max/min;
    else{
        int _max=0,_min=INT_MAX;
        for (int i = 0; i <= maxi; ++i) {
            if(vec[i]<_min)
                _min=vec[i];
        }
        for (int i = mini; i < vec.size(); ++i) {
            if(vec[i]>_max)
                _max=vec[i];
        }
        return max/_min>_max/min?max/_min:_max/min;
    }
}
int main() {
    vector<int> a={3,2,4,3,7,1,5};
    std::cout << findadd(a)<<endl<<findminus(a)<<endl<<findmul(a)<<endl<<finddev(a)<< std::endl;
    return 0;
}
