#include<bits/stdc++.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<graphics.h>
using namespace std;

inline int drawCircle(int x, int y, int p, int q){
    
    glDrawPixels()
}

void circleBres(int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y); 
    while (y >= x) 
    { 
        x++;
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y); 
        delay(50); 
    } 
} 