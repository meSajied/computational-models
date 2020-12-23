#include <iostream>
#include <cassert>
using namespace std;

int main(){
    int test_case;
    cin >> test_case;

    assert(test_case >= 1);
    assert(test_case <= 1000);

    while(test_case--){
        int x, y, N;
        cin >> x >> y >> N;

        assert(x >= 0);
        assert(x <= 1073741823);
        assert(y >= 0);
        assert(y <= 1073741823);
        assert(N >= 0);
        assert(N <= 1073741823);

    }
}