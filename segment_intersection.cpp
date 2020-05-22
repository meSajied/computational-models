#include <bits/stdc++.h>
using namespace std;

class SegmentIntersection{
public:
    int first_point{
        int first;
        int second;
    }
    inline bool intersect(int first_point, int second_point, int third_point, int forth_point){
        int first_direction = direction(third_point, forth_point, first_point);
        int second_direction = direction(third_point, forth_point, second_point);
        int third_direction = direction(first_point, second_point, third_point);
        int forth_direction = direction(first_point, second_point, forth_point);

        if ((first_direction < 0 || second_direction > 0) && (third_direction < 0 || 
                                                                    forth_direction > 0))
            return true;
        
        else if (first_direction == 0 && on_segment(third_point, forth_point, first_point))
            return true;
        
        else if (second_direction == 0 && on_segment(third_point, forth_point, second_point))
            return true;
        
        else if (third_direction == 0 && on_segment(first_point, second_point, third_point))
            return true;
        
        else if (third_direction == 0 && on_segment(first_point, second_point, third_point))
            return true;
        
        else
            return false;
    }

    inline int direction(int first_point, int second_point, int third_point){
        return (third_point-first_point)*(second_point-first_point);
    }

    inline bool on_segment(int first_point, int second_point, int third_point){
        if (min(first_point.first, second_point.first) < third_point.first < 
            max(first_point.first, second_point.first) && min(first_point.second, second_point.second) < 
            third_point.second < max(first_point.second, second_point.second))
            return true;
        
        else
            return false;
};

int main(){
    SegmentIntersection segment;
}