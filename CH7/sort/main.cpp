#include <iostream>
#include<vector>
using namespace std;

template<typename Comparable>
void insertsort(vector<Comparable>& a){
    for(int p=1;p<a.size();++p){
        Comparable temp=move(a[p]);
        int j=p;
        while(j>0&&a[j-1]>temp){
            a[j]=move(a[j-1]);
            j--;
        }
        a[j]=move(temp);
    }
}

template<typename Comparable>
void insertsort(vector<Comparable>& a,int left,int right){
    for(int p=left;p<=right;++p){
        Comparable temp=move(a[p]);
        int j=p;
        while(j>0&&a[j-1]>temp){
            a[j]=move(a[j-1]);
            j--;
        }
        a[j]=move(temp);
    }
}

template<typename Comparable>
void shellsort(vector<Comparable>&a){
    for(int gap=a.size()/2;gap>0;gap/=2){
        for(int i=gap;i<a.size();i++){
            Comparable temp=move(a[i]);
            int j=i;
            for(;j>=gap&&temp<a[j-gap];j-=gap){
                a[j]=move(a[j-gap]);
            }
            a[j]=move(temp);
        }
    }
}

template<typename Comparable>
void heapsort(vector<Comparable>&a){
    for(int i=a.size()/2-1;i>=0;--i){
        perCDown(a,i,a.size());
    }
    for (int j = a.size()-1; j >0 ; --j) {
        swap(a[0],a[j]);
        perCDown(a,0,j);
    }
}

inline int leftChild(int i){
    return 2*i+1;
}

template<typename Comparable>
void perCDown(vector<Comparable> &a ,int i,int n){
    int child;
    Comparable tmp;
    for(tmp=move(a[i]);leftChild(i)<n;i=child){
        child=leftChild(i);
        if(child !=n-1&&a[child]<a[child+1])
            ++child;
        if(tmp<a[child])
            a[i]=move(a[child]);
        else
            break;
    }
    a[i]=move(tmp);
}

template<typename Comparable>
void mergesort(vector<Comparable> & a){
    vector<Comparable> tmparray(a.size());
    mergesort(a,tmparray,0,a.size()-1);
}

template<typename Comparable>
void mergesort(vector<Comparable> & a,vector<Comparable> & tmparray,int left,int right){
    if(left<right){
        int center=(left+right)/2;
        mergesort(a,tmparray,left,center);
        mergesort(a,tmparray,center+1,right);
        merge(a,tmparray,left,center+1,right);
    }
}

template<typename Comparable>
void merge(vector<Comparable>&a, vector<Comparable>&tmparray,int leftPos,int rightPos,int rightEnd){
    int leftEnd=rightPos-1;
    int tmpPos=leftPos;
    int numElements=rightEnd-leftPos+1;
    while(leftPos<=leftEnd&&rightPos<=rightEnd){
        if(a[leftPos]<=a[rightPos])
            tmparray[tmpPos++]=move(a[leftPos++]);
        else
            tmparray[tmpPos++]=move(a[rightPos++]);
    }
    while(leftPos<=leftEnd)
        tmparray[tmpPos++]=move(a[leftPos++]);
    while(rightPos<=rightEnd)
        tmparray[tmpPos++]=move(a[rightPos++]);
    for(int i=0;i<numElements;i++,--rightEnd)
        a[rightEnd]=move(tmparray[rightEnd]);
}

template<typename Comparable>
void quicksort(vector<Comparable>&a){
    quicksort(a,0,a.size()-1);
}

template<typename Comparable>
const Comparable & median3(vector<Comparable>&a,int left,int right){
    int center=(right+left)/2;
    if(a[center]<a[left])
        swap(a[left],a[center]);
    if(a[right]<a[left])
        swap(a[left],a[right]);
    if(a[right]<a[center])
        swap(a[center],a[right]);
    swap(a[center],a[right-1]);
    return a[right-1];
}

template<typename Comparable>
void quicksort(vector<Comparable>&a ,int left,int right){
    if(left+10<=right){
        const Comparable&pivot=median3(a,left,right);
        int i=left,j=right-1;
        for(;;){
            while(a[++i]<pivot){}
            while (pivot<a[--j]){}
            if(i<j)
                swap(a[i],a[j]);
            else
                break;
        }
        swap(a[i],a[right-1]);
        quicksort(a,left,i-1);
        quicksort(a,i+1,right);
    }
    else
        insertsort(a,left,right);
}



int main() {
    vector<int> res{15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    quicksort(res);
    for(const auto & x:res){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
