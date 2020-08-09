#include <iostream>
#include<string>
using namespace std;

void swap(std::string & str,int low,int i){
    if(low==i)
        return;
    char ch=str[low];
    str[low]=str[i];
    str[i]=ch;
}

void permute(string & str,int low,int high){
    if(low==high)
    {
        cout<<str<<endl;
        return;
    }
    else{
        for(int i=low;i<=str.length()-1;i++){
            swap(str,low,i);
            permute(str,low+1,high);
            swap(str,low,i);
        }
    }
}
void permute(string &str) {
    permute(str, 0, str.length()-1);
}

int main() {
    string str="abc";
    permute(str);

    return 0;
}

