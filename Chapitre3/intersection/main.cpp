#include <iostream>
#include<vector>
using namespace std;

vector<int> intersection(const vector<int> &v1,const vector<int> &v2)
{
    auto iter1=v1.begin();
    auto iter2=v2.begin();
    vector<int> v3;
    while (iter1!=v1.end())
    {
        while(*iter2<*iter1&&iter2!=v2.end())
        {
            iter2++;
        }
        while (*iter2==*iter1&&iter2!=v2.end())
        {
            iter2++;
            v3.push_back(*iter1);
        }

        iter1++;
    }
    return v3;
}


int main() {
    vector<int> v1= {1,3,6,7,8,9};
    vector<int> v2= {3,5,7,8,10};
    vector<int> v3=move(intersection(v1,v2));
    for(int x:v3)
    {
        cout<<x<<" ";
    }
    cout<< endl;
    return 0;
}

