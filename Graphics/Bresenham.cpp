#include<bits/stdc++.h>
using namespace std;

inline int bresenham(int x1, int y1, int x2, int y2){

    int slop, slopError, x, y;
    slop = 2*(y2 - y1);
    slopError = slop - (x2 - x1);
    for(x = x1, y = y1; x <= x2; x++){
        printf("(%d, %d)\n", x, y);

        if(slopError >= 0){
            y++;
            slopError -= 2*(x2 - x1);
        }
    }

}

int main(){
    int x1 = 3, y1 = 2, x2 = 15, y2 = 5;
    bresenham(x1, y1, x2, y2);
    return 0; 
} 