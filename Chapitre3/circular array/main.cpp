#include <iostream>
#include<vector>
#include<iterator>

using namespace std;

template<typename Object>
class cir_Array
{
private:
    vector<Object> array;
    int Size;
    int front=0;
    int back=0;
public:
    cir_Array(int n):Size{n}{array.resize(n);}
    cir_Array(vector<Object> v,int n):array{v},Size{n},back{static_cast<int>(v.size()-1)}{array.resize(n);}
    int CurrentSize(){return Size;}
    void show()
    {
        for (auto i = front; i != back ; ++i) {
            cout<<array[i]<<" ";
            if(i==Size-1)
                i=-1;
        }
        cout<<array[back]<<endl;
    }
    Object & enqueue(Object&& x)
    {
        if(back==Size-1)
            back=0;
        else back++;
        Size++;
        array[back]=x;
        return array[back];
    }
    Object & dequeue()
    {
        if(front==Size-1)
            front=0;
        else front++;
        Size--;
        return array[front];
    }
};

int main() {
    cir_Array<int> a({1,2},3);
    cout<<a.CurrentSize()<<endl;
    cout<<a.enqueue(1);
    cout<<a.dequeue();
    a.show();
    return 0;
}
