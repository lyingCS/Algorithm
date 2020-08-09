//
// Created by chang on 2020/6/7.
//

#ifndef RECTANGLE_RECTANGLE_H
#define RECTANGLE_RECTANGLE_H

#include<iostream>
#include<vector>

using namespace std;

class Rectangle{
private:
    int length;
    int width;
public:
    Rectangle(int a,int b):length(a),width(b){
    }
    int getLength() const{
        return length;
    }
    int getWidth() const{
        return width;
    }
    void show() const{
        cout<< "length:"<<length<<", width:"<<width<<endl;
    }

};

template<typename Object,typename Comparator>
const Object& findMax(const vector<Object> &rec,Comparator cmp){
    int maxIndex=0;
    for (int i = 0; i < rec.size(); ++i) {
        if(cmp(rec[maxIndex],rec[i]))
            maxIndex=i;
    }

    return rec[maxIndex];
}

class CaseInsensitiveCompare{
public:
            bool operator()(const Rectangle &a, const Rectangle &b){
                if(a.getLength()*a.getWidth()<b.getLength()*b.getWidth())
                    return true;
                else if(a.getLength()*a.getWidth()==b.getLength()*b.getWidth())
                    return a.getLength()+a.getWidth()<b.getLength()+b.getWidth();
                else
                    return false;
            }
        };

#endif //RECTANGLE_RECTANGLE_H
