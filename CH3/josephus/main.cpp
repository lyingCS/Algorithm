#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

void josephus(int m,vector<int> &v)
{
    int current=0;
    while(v.size()!=1)
    {
        current=(current+m)%v.size();
        v.erase(v.begin()+current);
    }
}

int main() {
    vector<int> v={1,2,3,4,5};
    josephus(1,v);
    for(int x:v)
        cout<<x;
    return 0;
}
