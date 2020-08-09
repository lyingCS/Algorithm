//
// Created by chang on 2020/6/8.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include<vector>
#include<algorithm>

using namespace std;

void outint(int a){
    cout << a;
}

template<typename Object>
class matrix{
private:
    vector<vector<Object>> array;
public:
    matrix(){
        array.resize(0);
    }
    matrix(int rows,int cols):array(rows){
        for(auto & thisRow:array)
            thisRow.resize(cols);
    }
    matrix(vector<vector<Object>> v):array{v}{}
    matrix(vector<vector<Object>> && v):array{std::move(v)}{}
    const vector<Object>& operator[](int row) const {
    return array[rows];
    }
    vector<Object>&operator[](int row){
        return array[row]
    }
    int numrows() const{
        return array.size();
    }
    int numcols() const{
        return numrows()?array[0].size():0;
    }
    void resize(int a,int b){
        array.resize(a);
        for(auto & thisRow:array)
            thisRow.resize(b);
    }
    void show() const {
        for(auto Iter1=array.begin();Iter1!=array.end();Iter1++){
            for_each((*Iter1).begin(),(*Iter1).end(),outint);
            cout<<endl;
        }
    }
};


#endif //MATRIX_MATRIX_H
