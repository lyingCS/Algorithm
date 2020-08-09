#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    string str;
    cin>>str;
    vector<int> v;
    int x,y;
    for(auto x:str)
    {
        switch (x) {
            case '+':
                x=v.back();
                v.pop_back();
                y=v.back();
                v.pop_back();
                v.push_back(x+y);
                break;
            case '*':
                x=v.back();
                v.pop_back();
                y=v.back();
                v.pop_back();
                v.push_back(x*y);
                break;
            case '/':
                x=v.back();
                v.pop_back();
                y=v.back();
                v.pop_back();
                v.push_back(x/y);
                break;
            case '-':
                x=v.back();
                v.pop_back();
                y=v.back();
                v.pop_back();
                v.push_back(x-y);
                break;
            default:
                v.push_back(x-'0');
                break;

        }
    }
    cout<<v.back();
    return 0;
}
