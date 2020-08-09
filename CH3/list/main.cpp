#include <iostream>
#include "list.h"

using namespace std;

int main() {
    list<int> lee,lst;
    lee.push_back(1);
    lee.push_back(2);
    list<int>::iterator itr=lee.begin();
    lst.splice(lst.begin(),lee);
    list<int>::reverse_iterator itr2=lst.rbegin();
    while(itr2!=lst.rend())
        cout<<*itr2++<<endl;
    return 0;
}
