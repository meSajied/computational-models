#include <vector>
using namespace std;

int getIndex(vector<int> v, int K){
    auto it = find(v.begin(), v.end(), K);
   if (it != v.end()) {
        int index = distance(v.begin(), it);
        return index;
    }
    else {
        return -1;
    }
}
