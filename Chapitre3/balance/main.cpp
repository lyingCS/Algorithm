#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    string str;
    cin>>str;
    vector<int> v;
    for (auto iter = str.begin(); iter !=str.end() ; ++iter) {
        if(*iter=='/'&&*(iter+1)=='*')
        {
            v.push_back(1);
            iter++;
        }
        else if(*iter=='{')
            v.push_back(2);
        else if(*iter=='[')
            v.push_back(3);
        else if(*iter=='(')
            v.push_back(4);
        else if(*iter=='*'&&*(iter+1)=='/')
        {
            if(v.back()==1)
                v.pop_back();
            else
            {
                cout<<"wrong"<<endl;
                return 0;
            }
            iter++;
        }
        else if(*iter=='}')
        {
            if(v.back()==2)
                v.pop_back();
            else
            {
                cout<<"wrong"<<endl;
                return 0;
            }
        }
        else if(*iter==']')
        {
            if(v.back()==3)
                v.pop_back();
            else
            {
                cout<<"wrong"<<endl;
                return 0;
            }
        }
        else if(*iter==')')
        {
            if(v.back()==4)
                v.pop_back();
            else
            {
                cout<<"wrong"<<endl;
                return 0;
            }
        }

    }
    if(v.empty())
        cout<<"right"<<endl;
    else
        cout<<"wrong"<<endl;
    return 0;
}
