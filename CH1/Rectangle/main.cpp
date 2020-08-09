#include "Rectangle.h"

int main() {
    vector<Rectangle> rec={{1,2},{2,3},{3,1},{2,3},{1,4}};
    findMax(rec,CaseInsensitiveCompare{}).show();
    //cout<<CaseInsensitiveCompare{}(rec[0],rec[1]);
    return 0;
}
