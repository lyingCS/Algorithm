#include <iostream>
#include"Vector.h"
using namespace std;

int main() {
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    Vector<int>::iterator  iter=a.begin();
    cout<<*(a.insert(a.begin(),7));
    a.show();
    cout<<*(a.erase(a.begin()))<<endl;
    a.show();
    cout<<*(a.erase(a.begin(),iter+1))<<endl;
    a.show();
    return 0;
}
