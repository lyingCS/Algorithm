//
// Created by chang on 2020/7/8.
//
#include"SplayTree.h"

void SplayTree::splay(const int &x, BinaryNode *&t) {
    BinaryNode * leftTreeMax,*rightTreeMax;
    static BinaryNode header;
    header.left=header.right=nullNode;
    leftTreeMax=rightTreeMax=&header;

    nullNode->element=x;

    for(;;){
        if(x<t->element){
            if(x<t->left->element)
                rotateWithLeftChild(t);
            if(t->left==nullNode)
                break;
            rightTreeMax->left=t;
            rightTreeMax=t;
            t=t->left;
        }
        else if(x>t->element){
            if(x>t->right->element){
                rotateWithRightChild(t);
            }
            if(t->right==nullNode)
                break;
            leftTreeMax->right=t;
            leftTreeMax=t;
            t=t->right;
        } else
            break;

    }
    leftTreeMax->right=t->left;
    rightTreeMax->left=t->right;
    t->left=header.right;
    t->right=header.left;
}

void SplayTree::rotateWithLeftChild(BinaryNode *&k2) {
    BinaryNode * k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2=k1;
}

void SplayTree::rotateWithRightChild(BinaryNode *&k1) {
    BinaryNode * k2=k1->right;
    k1->right=k2->left;
    k2->right=k1;
    k1=k2;
}

void SplayTree::remove(const int &x) {
    if(!contains(x))
        return;
    BinaryNode *newTree;
    if(root->left==nullNode){
        newTree=root->right;
    }
    else{
        newTree=root->left;
        splay(x,newTree);
        newTree->right=root->right;
    }
    delete root;
    root=newTree;
}

void SplayTree::insert(const int &x) {
    static BinaryNode*newNode=nullptr;
    if(newNode== nullptr)
        newNode=new BinaryNode;
    newNode->element=x;
    if(root==nullNode){
        newNode->left=newNode->right=nullNode;
        root=newNode;
    }
    else{
        splay(x,root);
        if(x<root->element){
            newNode->left=root->left;
            newNode->right=root;
            root->left=nullNode;
            root=newNode;
        }
        else if(root->element<x){
            newNode->left=root;
            newNode->right=root->right;
            root->right=nullNode;
            root=newNode;
        }
        else
            return ;
    }
    newNode= nullptr;
}

bool SplayTree::contains(const int &x,BinaryNode *t) {
    if(t==nullNode){
        return false;
    }
    else if(x<t->element)
        return contains(x,t->left);
    else if(x>t->element)
        return contains(x,t->right);
    else{
        splay(x,root);
        return true;
    }
}

void SplayTree::makeEmpty(SplayTree::BinaryNode *t) {
    if(t!=nullNode)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t=nullNode;
}

void SplayTree::printfTree(ostream &out, SplayTree::BinaryNode *t) const {
    if(t!=nullNode)
    {
        printfTree(out,t->left);
        out<<t->element;
        printfTree(out,t->right);
    }
}

void SplayTree::printfTree(ostream &out) const {
    if(isempty())
        out<<"Empty Tree!"<<endl;
    else
        printfTree(out,root);
}
