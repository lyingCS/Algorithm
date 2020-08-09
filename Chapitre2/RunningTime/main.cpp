#include <iostream>
#include<ctime>



int main() {
    using namespace std;
    clock_t startTime, endTime;
    int sum=0;
    startTime=clock();
    int n=100000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ++sum;
        }
    }
    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
