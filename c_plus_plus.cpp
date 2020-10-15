#include <iostream>
using namespace std;

int main(){
    int *p, *q;
    int var = 20;

    p = &var;
    q = p;
    cout << p <<" " << q << endl;
}