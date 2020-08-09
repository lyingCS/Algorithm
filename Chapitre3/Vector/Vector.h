//
// Created by chang on 2020/6/15.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include<algorithm>

template<typename Object>
class Vector
{
public:
    explicit Vector(int initSize =0):theSize{initSize},theCapacity{initSize+SPACE_CAPACITY}
    {
        objects=new Object[theCapacity];
    }
    Vector(const Vector & rhs):theSize{rhs.theSize},theCapacity{rhs.theCapacity},objects{nullptr}
    {
        objects=new Object[the Capacity];
        for (int k = 0; k < theSize; ++k) {
            objects[k]=rhs.objects[k];
        }
    }
    Vector & operator=(const Vector & rhs)
    {
        Vector copy=rhs;
        std::swap(*this,copy);
        return *this;
    }
    ~Vector()
    {
        delete []objects;
    }
    Vector (Vector && rhs) noexcept :theSize{rhs.theSize},theCapacity{rhs.theCapacity},objects{rhs.objects}
    {
        rhs.objects= nullptr;
        rhs.theSize=0;
        rhs.theCapacity=0;
    }
    Vector & operator=(Vector &&rhs){
        std::swap(theSize,rhs.theSize);
        std::swap(theCapacity,rhs.theCapacity);
        std::swap(objects,rhs.objects);

        return *this;
    }
    void resize(int newSize)
    {
        if(newSize>theCapacity)
            reserve(newSize*2);
        theSize=newSize;
    }
    void reserve(int newCapacity)
    {
        if(newCapacity<theSize)
            return;
         Object *newArray=new Object[newCapacity];
        for (int k = 0; k < theSize; ++k) {
            newArray[k]=std::move(objects[k]);
        }
        theCapacity=newCapacity;
        std::swap(objects,newArray);
        delete[] newArray;
    }
    Object & operator[] (int index)
    {
        if(index>=size()) {
            throw index;
            return nullptr;
        }

        return objects[index];
    }
    const Object & operator[](int index)const {
        return objects[index];
    }
    bool empty()const
    {return size()==0}

    int size() const {
        return theSize;
    }
    int capacity()const {
        return theCapacity;
    }
    void push_back(const Object && x) {
        if(theSize==theCapacity)
            reserve(2*theCapacity+1);
        objects[theSize++]=std::move(x);
    }
    void push_back(const Object & x) {
        if(theSize==theCapacity)
            reserve(2*theCapacity+1);
        objects[theSize++]=x;
    }
    void pop_back() {
        --theSize;
    }
    const Object& back()const {
        return objects[theSize-1];
    }
    typedef Object*iterator;
    typedef const Object*const_iterator;
    iterator begin() {
        return &objects[0];
    }
    const_iterator begin()const {
        return &objects[0];
    }
    iterator end() {
        return &objects[size()];
    }
    const_iterator end() const {
        return &objects[size()];
    }
    iterator insert(iterator pos,const Object& x)
    {
        if(theSize==theCapacity)
            reserve(2*theCapacity+1);
        theSize++;
        for (iterator iter=end()-1;iter!=pos;iter--)
        {
            *iter=*(iter-1);
        }
        *pos=x;
        return pos;
    }
    iterator erase(iterator pos)
    {
        if(pos>end())
        {
            throw pos;
            return nullptr;
        }
        theSize--;
        for (iterator i = pos; i < end(); ++i) {
            *i=*(i+1);
        }
        return pos;
    }
    iterator erase(iterator start,iterator end)
    {
        iterator iter=start;
        while(iter!=end)
        {
            erase(iter);
            end--;
        }
        return end;
    }
    void show()
    {
        for (int i = 0; i < theSize; ++i) {
            cout<<objects[i]<<" ";
        }
        cout<<endl;
    }
    static const int SPACE_CAPACITY=16;
private:
    int theSize;
    int theCapacity;
    Object *objects;
};
#endif //VECTOR_VECTOR_H
