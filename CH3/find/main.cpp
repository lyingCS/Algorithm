#include <iostream>
#include<vector>

using namespace std;

template<typename Iterator ,typename Object>
Iterator Find(Iterator start,Iterator end,const Object & x)
{
    Iterator iter=start;
    while(iter!=end)
    {
        if(*iter==x)
            return iter;
        iter++;
    }
    return end;
}

int main()
{
    vector<int> v1 {1,2,2,3,4,5,1,5,8};
    cout<<*(Find(v1.begin(),v1.end(),5)-1)<<endl;
    return 0;

}
