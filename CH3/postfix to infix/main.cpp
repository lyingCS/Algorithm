#include <iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    string str;
    cin>>str;
    vector<string> infix;
    string tem;
    for(auto x:str)
    {
        switch (x) {
            case '+':
                tem='('+infix.back()+'+';
                infix.pop_back();
                tem+=infix.back()+')';
                infix.pop_back();
                infix.push_back(tem);
                break;
            case '-':
                tem='('+infix.back()+'-';
                infix.pop_back();
                tem+=infix.back()+')';
                infix.pop_back();
                infix.push_back(tem);
                break;
            case '*':
                tem='('+infix.back()+'*';
                infix.pop_back();
                tem+=infix.back()+')';
                infix.pop_back();
                infix.push_back(tem);
                break;
            case '/':
                tem='('+infix.back()+'/';
                infix.pop_back();
                tem+=infix.back()+')';
                infix.pop_back();
                infix.push_back(tem);
                break;
            default:
                tem=x;
                infix.push_back(tem);
                break;
        }
    }
    for(const auto& x:infix)
        cout<<x;
    cout<<endl;
    return 0;
}
