//
// Created by chang on 2020/7/1.
//

#ifndef DISJSET_DISJSETS_H
#define DISJSET_DISJSETS_H
#include<iostream>
#include<vector>

using namespace std;

class DisjSets{
public:
    explicit DisjSets(int numElements);

    int find(int x);
    void unionSets(int root1,int root2);
    void show();
    int num() const;

private:
    int size;
    vector<int> s;
};
#endif //DISJSET_DISJSETS_H
