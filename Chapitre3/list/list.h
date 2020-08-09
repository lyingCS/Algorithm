//
// Created by chang on 2020/6/16.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
template <typename Object>
class list
{
private:
    struct Node{
        Object data;
        Node *prev;
        Node *next;
        explicit Node(const Object & d=Object(),Node*p= nullptr,Node*n= nullptr):data(d),prev{p},next(n){};
        explicit Node(Object && d,Node*p= nullptr,Node*n = nullptr):data(std::move(d)),prev{p},next(n){};
    };
    int theSize;
    Node*head;
    Node*tail;
    void init();
public:
    class const_iterator
    {
    protected:
        Node*current;
        Object & retrieve()const{return current->data;}
        const_iterator(Node *p):current{p} {}
        friend class list<Object>;

    public:
        const_iterator():current(nullptr){}

        const Object&operator*()const {return retrieve();}

        const_iterator&operator++(){
            current=current->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator old=*this;
            ++(*this);
            return old;
        }

        const_iterator&operator--(){
            current=current->prev;
            return *this;
        }

        const_iterator operator--(int)
        {
            const_iterator old=*this;
            --(*this);
            return old;
        }

        const_iterator operator+(int k)const
        {
            const_iterator itr=current;
            for (int i = 0; i < k; ++i) {
                itr++;
            }
            return itr;
        }
        bool operator==(const const_iterator & rhs)const
        {return current==rhs.current;}
        bool operator!=(const const_iterator&rhs)const
        {return !(*this==rhs);}

    };
    class const_reverse_iterator
    {
    protected:
        Node*current;
        Object & retrieve()const{return current->data;}
        const_reverse_iterator(Node *p):current{p} {}
        friend class list<Object>;

    public:
        const_reverse_iterator():current(nullptr){}

        const Object&operator*()const {return retrieve();}

        const_reverse_iterator&operator++(){
            current=current->prev;
            return *this;
        }

        const_reverse_iterator operator++(int)
        {
            const_reverse_iterator old=*this;
            ++(*this);
            return old;
        }

        const_reverse_iterator&operator--(){
            current=current->next;
            return *this;
        }

        const_reverse_iterator operator--(int)
        {
            const_reverse_iterator old=*this;
            --(*this);
            return old;
        }

        const_reverse_iterator operator+(int k)const
        {
            const_reverse_iterator itr=current;
            for (int i = 0; i < k; ++i) {
                itr--;
            }
            return itr;
        }
        bool operator==(const const_reverse_iterator & rhs)const
        {return current==rhs.current;}
        bool operator!=(const const_reverse_iterator&rhs)const
        {return !(*this==rhs);}

    };
    class iterator: public const_iterator
    {
    protected:
        iterator(Node*p):const_iterator{p}{}
        friend class list<Object>;

    public:
        iterator(){}
        Object&operator*()
        {return const_iterator::retrieve();}
        const Object&operator*()const
        {return const_iterator::operator*();}
        iterator&operator++()
        {
            this->current=this->current->next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator old=*this;
            ++(*this);
            return old;
        }
        iterator&operator--()
        {
            this->current=this->current->prev;
            return *this;
        }
        iterator operator--(int)
        {
            iterator old=*this;
            --(*this);
            return old;
        }
        iterator operator+(int k)const
        {
            iterator itr=this->current;
            for (int i = 0; i < k; ++i) {
                itr++;
            }
            return itr;
        }
    };
    class reverse_iterator: public const_reverse_iterator
    {
    protected:
        reverse_iterator(Node*p):const_reverse_iterator{p}{}
        friend class list<Object>;

    public:
        reverse_iterator(){}
        Object&operator*()
        {return const_reverse_iterator::retrieve();}
        const Object&operator*()const
        {return const_reverse_iterator::operator*();}
        reverse_iterator&operator++()
        {
            this->current=this->current->prev;
            return *this;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator old=*this;
            ++(*this);
            return old;
        }
        reverse_iterator&operator--()
        {
            this->current=this->current->next;
            return *this;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator old=*this;
            --(*this);
            return old;
        }
        reverse_iterator operator+(int k)const
        {
            reverse_iterator itr=this->current;
            for (int i = 0; i < k; ++i) {
                itr--;
            }
            return itr;
        }
    };
    list();
    list(const list&rhs);
    ~list();
    list&operator=(const list &rhs);
    list(list&&rhs) noexcept ;
    list&operator=(list&&rhs);
    iterator begin()
    {return {head->next};}
    reverse_iterator rbegin()
    {return {tail->prev};}
    const_iterator begin()const
    {return {head->next};}
    const_reverse_iterator rbegin()const
    {return {tail->prev};}
    iterator end()
    {return {tail};}
    reverse_iterator rend()
    {return {head};}
    const_iterator end()const
    {return {tail};}
    const_reverse_iterator rend()const
    {return {head};}
    int size()const {return theSize;}
    bool empty()const {return size()==0;}
    void clear()
    {
        while(!empty())
            pop_front();
    }
    Object&front(){return *begin();}
    const Object&front()const {return *begin();}
    Object&back(){return *--end();}
    const Object&back()const {return *--end();}
    void push_front(const Object&x){insert(begin(),x);}
    void push_front(Object&&x){insert(begin(),std::move(x));}
    void push_back(const Object & x){insert(end(),x);}
    void push_back(Object&&x){insert(end(),std::move(x));}
    void pop_front(){erase(begin());}
    void pop_back(){erase(--end());}
    iterator insert(iterator itr,const Object&x);
    iterator insert(iterator itr,Object&&x);
    iterator erase(iterator itr);
    iterator erase(iterator from,iterator to);
    void splice(iterator position,list<Object>&lst);
};

template<typename Object>
list<Object>::list() {
    init();
}

template<typename Object>
void list<Object>::init() {
    theSize=0;
    head=new Node;
    tail=new Node;
    head->next=tail;
    tail->prev=head;
}

template<typename Object>
list<Object>::list(const list &rhs) {
    init();
    for(auto &x:rhs)
        push_back(x);
}

template<typename Object>
list<Object>::~list() {
    clear();
    delete head;
    delete tail;
}

template<typename Object>
list<Object> &list<Object>::operator=(const list &rhs) {
    list copy=rhs;
    std::swap(*this,copy);
    return *this;
}

template<typename Object>
list<Object>::list(list &&rhs) noexcept:theSize{rhs.theSize},head{rhs.head},tail{rhs.tail} {
    rhs.theSize=0;
    rhs.head= nullptr;
    rhs.tail= nullptr;
}

template<typename Object>
list<Object> &list<Object>::operator=(list &&rhs) {
    std::swap(theSize,rhs.theSize);
    std::swap(head,rhs.head);
    std::swap(tail,rhs.tail);

    return *this;
}

template<typename Object>
typename list<Object>::iterator list<Object>::insert(list<Object>::iterator itr, const Object &x) {
    Node*p=itr.current;
    theSize++;
    return {p->prev=p->prev->next=new Node{x,p->prev,p}};
}

template<typename Object>
typename list<Object>::iterator list<Object>::insert(list<Object>::iterator itr, Object &&x) {
    Node*p=itr.current;
    theSize++;
    return {p->prev=p->prev->next=new Node{std::move(x),p->prev,p}};
}

template<typename Object>
typename list<Object>::iterator list<Object>::erase(list::iterator itr) {
    Node*p=itr.current;
    iterator retVal{p->next};
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete p;
    theSize--;

    return retVal;
}

template<typename Object>
typename list<Object>::iterator list<Object>::erase(list::iterator from, list::iterator to) {
    for (iterator itr = from; itr!=to;) {
        itr=erase(itr);
    }

    return to;
}

template<typename Object>
void list<Object>::splice(list<Object>::iterator position, list<Object> &lst) {
    for(auto x:lst)
    {
        insert(position,x);
    }
}

#endif //LIST_LIST_H
