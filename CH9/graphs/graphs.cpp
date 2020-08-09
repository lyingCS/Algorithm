//
// Created by chang on 2020/7/4.
//

#include "graphs.h"

void Graph::top_sort() {
    auto v_tmp=v;
    queue<char> q;
    int counter=0;

    for(const auto &x:v_tmp){
        if(x.second.ind==0)
            q.push(x.first);
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        Vertex ver_tmp=v_tmp[q.front()];
        q.pop();
        counter++;
        for(auto & x:ver_tmp.adj){
            if(--v_tmp[x.dest].ind==0){
                q.push(x.dest);
            }
        }
    }

    if(counter!=nums){
        cout<<"Cycle exists!";
    }
}

void Graph::printPath(char ch) {
    if(v[ch].path!=' '){
        printPath(v[ch].path);
        cout<<" to ";
    }
    cout<<ch;
}

void Graph::dijkstra(char s) {
    v[s].path=' ';
    v[s].dist=0;
    for (int i = 0; i < nums; ++i) {
        char c;
        int dist_max=INT_MAX;
        for(const auto & x:v){
            if(x.second.known==false&&x.second.dist<dist_max){
                c=x.first;
            }
        }
        v[c].known=true;
        for(auto & x:v[c].adj){
            if(!v[x.dest].known){
                int cvw=x.weight;
                if(v[c].dist+cvw<v[x.dest].dist){
                    v[x.dest].dist=v[c].dist+cvw;
                    v[x.dest].path=c;
                }
            }
        }
    }
}

