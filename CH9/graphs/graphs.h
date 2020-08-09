//
// Created by chang on 2020/7/4.
//

#ifndef GRAPHS_GRAPHS_H
#define GRAPHS_GRAPHS_H

#include <iostream>
#include<stack>
#include<queue>
#include <utility>
#include<vector>
#include<unordered_map>

using namespace std;
struct rood{
    char dest;
    int weight;
};

struct Vertex{
    vector<rood> adj;
    int ind;
    bool known;
    int dist;
    char path;
    explicit Vertex(){
        ind=0;
        known= false;
        dist=INT_MAX;
        path=' ';
    }
    Vertex(vector<rood> && x,int y):adj{x},ind{y}{
        known= false;
        dist=INT_MAX;
        path=' ';
    }
};

class Graph{
private:
    unordered_map<char,Vertex> v;
    int nums;
public:
    explicit Graph(unordered_map<char,Vertex> k):v{std::move(k)},nums{static_cast<int>(v.size())}{}
    void top_sort();
    void printPath(char ch);
    void dijkstra(char s);
};
#endif //GRAPHS_GRAPHS_H
