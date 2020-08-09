#include <iostream>

const int n =3;

int a[n][n]={{1,2,3},{2,3,4},{3,4,5}};

bool matrix_search(int b[n][n],int x){

    int i=0;
    if(b[0][0]>x||b[n-1][n-1]<x)
        return false;
    for (i = 0;  i<n ; i++) {
        if (x==b[i][i])
            return true;
        else if(x<a[i][i])
            break;
    }
    for (int j = i; j < n; ++j) {
        if(x==a[i-1][j])
            return true;
    }
    for (int k = 0; k < i; ++k) {
        if(x==a[i][k])
            return true;
    }
    return false;
}

int main() {
    std::cout << matrix_search(a,5) << std::endl;
    return 0;
}
