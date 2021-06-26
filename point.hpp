//
//  point.hpp
//  tic-tac-toe
//
//  Created by Егор Слипченко on 02.04.2021.
//

#ifndef point_hpp
#define point_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class point{
private:
    int x = 0;
    int y = 0;
public:
    void SetX(int x){
        this->x = x;
    }
    void SetY(int y){
        this->y = y;
    }
    
    int GetX(){
        return x;
    }
    
    int GetY(){
        return y;
    }
    
    bool operator==(point &th){
        bool result = (this->x == th.GetX()) && (this->y == th.GetY());
        return result;
    }
    
    point &operator=(const point &th){
        this->x = th.x;
        this->y = th.y;
        return *this;
    }
};

#endif /* point_hpp */
