#include <iostream>
#include<vector>
#include<string>

using namespace std;
vector<string> str{"this","two","fat","that"};
const char dir[4][4]={{'t','h','i','s'},{'w','a','t','s'},{'o','a','h','g'},{'f','g','d','t'}};
const int move1[8]={1,1,1,0,0,-1,-1,-1};
const int move2[8]={1,0,-1,1,-1,1,0,-1};

void judge(string& basicString, int &count) {
    //cout<<basicString<<count<<endl;
    if(find(str.begin(),str.end(),basicString)!=str.end())
        count++;
}

int main() {
    int count=0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 8; ++k) {
                string s="";
                int line=i;
                int row=j;
                do{
                    s.push_back(dir[line][row]);
                    judge(s,count);
                    line+=move1[k];
                    row+=move2[k];
                }while(0<=line&&line<=3&&0<=row&&row<=3);
            }
        }
    }
    cout << count;
    return 0;
}
/*#include<iostream>
#include<vector>
int main()
{
    using namespace std;
    int i=4;
    vector<int> vec;
    vec.push_back(i);
    cout<<i;
}*/