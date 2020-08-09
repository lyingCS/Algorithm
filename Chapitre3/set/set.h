//
// Created by chang on 2020/6/20.
//

#ifndef SET_SET_H
#define SET_SET_H

template<typename Object>
class set{
private:
    struct Node{
        Object item;
        Node* father;
        Node* left;
        Node* right;

        Node(const Object& element,Node* a,Node* b,Node*c):item{element},father{a},left{b},right{c}{}
        Node(Object&& element,Node* a,Node* b,Node*c):item{std::move(element)},father{a},left{b},right{c}{}
    };
    Node* root;

public:
};

#endif //SET_SET_H
