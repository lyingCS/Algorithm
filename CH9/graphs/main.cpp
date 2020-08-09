#include"graphs.h"

int main() {
    unordered_map<char,Vertex> v;
/*    v['S']={{{'A',1},{'D',1},{'G',1}},0};
    v['A']={{{'B',1},{'E',1}},2};
    v['D']={{{'A',1},{'E',1}},2};
    v['G']={{{'E',1},{'D',1},{'H',1}},1};
    v['B']={{{'C',1}},1};
    v['E']={{{'C',1},{'F',1},{'I',1}},4};
    v['H']={{{'E',1},{'I',1}},1};
    v['C']={{{'T',1}},3};
    v['F']={{{'C',1},{'T',1}},2};
    v['I']={{{'F',1},{'T',1}},2};
    v['T']={{},3};*/
    v['A']=Vertex({{'B',2},{'D',1}},1);
    v['B']=Vertex({{'D',3},{'E',10}},1);
    v['C']=Vertex({{'A',4},{'F',5}},1);
    v['D']=Vertex({{'C',2},{'E',2},{'F',8},{'G',4}},2);
    v['E']=Vertex({{'G',6}},2);
    v['F']=Vertex({},3);
    v['G']=Vertex({{'F',1}},2);
    Graph graph(v);
    graph.dijkstra('A');
    graph.printPath('G');
    return 0;
}
