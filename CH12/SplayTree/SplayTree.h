//
// Created by chang on 2020/7/8.
//

#ifndef SPLAYTREE_SPLAYTREE_H
#define SPLAYTREE_SPLAYTREE_H
#include<iostream>
o
using namespace std;
class SplayTree{
public:
    SplayTree(){
        nullNode=new BinaryNode;
        nullNode->left=nullNode->right= nullNode;
        root=nullNode;
    }
    ~SplayTree(){
        makeEmpty();
        delete nullNode;
    }
    SplayTree(const SplayTree& rhs);
    SplayTree(SplayTree&&rhs);
    SplayTree&operator=(const SplayTree& rhs);
    SplayTree&operator=(SplayTree&&rhs);
    void makeEmpty(){makeEmpty(root);}
    void insert(const int &x);
    void remove(const int &x);
    bool contains(const int &x){return contains(x,root);}
    void printfTree(ostream &out=cout) const;
    bool isempty() const {return root == nullNode;}

private:
    struct BinaryNode{
        int element;
        BinaryNode* left;
        BinaryNode* right;
    };
    BinaryNode *root;
    BinaryNode *nullNode;

    void rotateWithLeftChild(BinaryNode *&k2);
    void rotateWithRightChild(BinaryNode *&k1);
    void splay(const int &x,BinaryNode *&t);
    bool contains(const int &x,BinaryNode* t);
    void makeEmpty(BinaryNode * t);
    void printfTree(ostream& out,BinaryNode *t)const;
};
#endif //SPLAYTREE_SPLAYTREE_H
