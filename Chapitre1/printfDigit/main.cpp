#include <iostream>

void printreal(double d);

void printint(int intnum);

void printdigit(double digitnum);

using namespace std;
void print(int n)
{
    cout<<n;
}

int main() {
    printreal(-1234.144);
    return 0;
}

void printreal(double d) {
    if(d<0)
    {
        cout<<'-';
        d=-d;
    }
    int intnum=(int)d;
    double digitnum=d-intnum;
    printint(intnum);
    cout<<".";
    printdigit(digitnum);


}

void printdigit(double digitnum) {
    print(digitnum*10);
    if (digitnum>0) printdigit(digitnum*10-(int)(digitnum*10));
}

void printint(int intnum) {
    if(intnum>=10) printint((int)intnum/10);
    print(intnum%10);
}
