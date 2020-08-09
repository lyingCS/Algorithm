#include <iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string infix,postfix;
    vector<int> v;
    cin>>infix;
    for(auto x:infix)
    {
        switch (x) {
            case '+':
                while(!v.empty()&&v.back()<5)
                {
                    if(v.back()==1)
                    {
                        postfix.push_back('+');
                        v.pop_back();
                    }
                    else if(v.back()==2)
                    {
                        postfix.push_back('-');
                        v.pop_back();
                    }
                    else if(v.back()==3)
                    {
                        postfix.push_back('*');
                        v.pop_back();
                    }
                    else if(v.back()==4)
                    {
                        postfix.push_back('/');
                        v.pop_back();
                    }
                }
                v.push_back(1);
                break;
            case '-':
                while(!v.empty()&&v.back()<5)
                {
                    if(v.back()==1)
                    {
                        postfix.push_back('+');
                        v.pop_back();
                    }
                    else if(v.back()==2)
                    {
                        postfix.push_back('-');
                        v.pop_back();
                    }
                    else if(v.back()==3)
                    {
                        postfix.push_back('*');
                        v.pop_back();
                    }
                    else if(v.back()==4)
                    {
                        postfix.push_back('/');
                        v.pop_back();
                    }
                }
                v.push_back(2);
                break;
            case '*':
                while(!v.empty()&&v.back()==3||v.back()==4)
                {
                    if(v.back()==3)
                    {
                        postfix.push_back('*');
                        v.pop_back();
                    }
                    else if(v.back()==4)
                    {
                        postfix.push_back('/');
                        v.pop_back();
                    }
                }
                v.push_back(3);
                break;

            case '/':
                while(!v.empty()&&v.back()==3||v.back()==4)
                {
                    if(v.back()==3)
                    {
                        postfix.push_back('*');
                        v.pop_back();
                    }
                    else if(v.back()==4)
                    {
                        postfix.push_back('/');
                        v.pop_back();
                    }
                }
                v.push_back(4);
                break;
            case '(':
                v.push_back(10);
                break;
            case ')':
                while(!v.empty()&&v.back()!=10)
                {
                    if(v.back()==1)
                    {
                        postfix.push_back('+');
                        v.pop_back();
                    }
                    else if(v.back()==2)
                    {
                        postfix.push_back('-');
                        v.pop_back();
                    }
                    else if(v.back()==3)
                    {
                        postfix.push_back('*');
                        v.pop_back();
                    }
                    else if(v.back()==4)
                    {
                        postfix.push_back('/');
                        v.pop_back();
                    }
                }
                v.pop_back();
                break;
            default:
                postfix.push_back(x);

        }
    }
    while(!v.empty())
    {
        if(v.back()==1)
        {
            postfix.push_back('+');
            v.pop_back();
        }
        else if(v.back()==2)
        {
            postfix.push_back('-');
            v.pop_back();
        }
        else if(v.back()==3)
        {
            postfix.push_back('*');
            v.pop_back();
        }
        else if(v.back()==4)
        {
            postfix.push_back('/');
            v.pop_back();
        }
    }
    cout<<postfix;
    return 0;
}
