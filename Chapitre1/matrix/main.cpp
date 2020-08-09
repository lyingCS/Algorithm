#include <iostream>
#include "matrix.h"

int main() {
    vector<vector<int>> a={{1,2},{1,2},{2,3}};
    matrix<int> m=a;
    m.show();
    m.resize(2,1);
    m.show();

    return 0;
}
