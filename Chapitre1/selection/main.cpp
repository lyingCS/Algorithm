#include <iostream>
#include<algorithm>
#include<list>

const int N=100;
const int k=N/2;

bool compare(int a, int b)
{
    return a>b;
}
void outint(int a)
{
    std::cout << a;
}

int main()
{
    using namespace std;
    int a[100];
    for (int i = 0; i < 100; ++i) {
        a[i]=i;
    }
    list<int> b;
    for (int j = 0; j < k; ++j) {
        b.push_back(a[j]);
    }
    b.sort(compare);
    list<int>::reverse_iterator Iter=b.rbegin();
    for (int l = k; l < 100; ++l) {
        if(a[l]<*Iter)
            continue;
        else{
            list<int>::iterator Iter_=b.begin();
            while(*Iter_>a[l])
                Iter++;
            b.insert(Iter_,a[l]);
            b.pop_back();
        }
    }
    cout<<*Iter;
    return 0;
}
