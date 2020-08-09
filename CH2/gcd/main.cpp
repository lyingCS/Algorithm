#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(a==b)
        return a;
    else if(a<b)
    {
        swap(a,b);
    }

    if(a%2==0&&b%2==0)
    {
        return 2*gcd(a/2,b/2);
    }
    else if(a%2==1&&b%2==0)
    {
        return gcd(a,b/2);
    }
    else if(a%2==0&&b%2==1)
    {
        return gcd(a/2,b);
    }
    else return gcd((a+b)/2,(a-b)/2);
}

int main() {
    cout << gcd(15,13);
    return 0;
}
