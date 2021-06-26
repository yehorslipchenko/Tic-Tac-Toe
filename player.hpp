//
//  player.hpp
//  tic-tac-toe
//
//  Created by Егор Слипченко on 03.04.2021.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <iostream>
#include "point.hpp"


using namespace std;

class player{
private:
    static int count_player;
    int num_player = 0;
    
public:
    
    player(){
        count_player++;
        num_player = count_player;
    }
    
    point inf_pl(bool check){
        string intfnull = "\nPLAYER "+ to_string(num_player) + "(null):\n";
        string intfcross = "\nPLAYER "+ to_string(num_player) + "(cross):\n";
        if (check) {
            cout << intfcross;
        }else cout << intfnull;
        point my_step = MyStep();
        return my_step;
    }
    
    point MyStep(){
        point step;
        int x = 0;
        int y = 0;
        cout << "input x:";
        cin >> x;
        cout << "input y:";
        cin >> y;
        step.SetX(x);
        step.SetY(y);
        return step;
        
    }
    
};

#endif /* player_hpp */
