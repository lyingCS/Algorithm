#include <iostream>
#include<vector>

using namespace std;

void printLots(const vector<int> &v1,const vector<int> v2)
{
    for(int x:v2)
        cout<<v1[x-17]<<" ";
    cout<<endl;

    return ;
}

int main() {
    vector<int> v1 {1,2,3,4,5,6,7,8,9};
    vector<int> v2 {1,3,5};
    printLots(v1,v2);
    return 0;
}
