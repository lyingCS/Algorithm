#include <iostream>


int recursive(int n);

using namespace std;
int main() {
    int n;
    std::cin>>n;
    int count=recursive(n);
    cout<<count;

    return 0;
}

int recursive(int n) {
    if(1==n)
        return 1;
    if(n%2){
        return 1+recursive((n-1)/2);
    } else return recursive(n/2);
    return 0;
}

