//
//  field.hpp
//  tic-tac-toe
//
//  Created by Егор Слипченко on 02.04.2021.
//

#ifndef field_hpp
#define field_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "point.hpp"
#include "player.hpp"
#define SIZE 3
#define LENGHTT 11
#define check_LINE 5
#define cnt_st 9

using namespace std;

class field{
public:
    string Field = "   |   |   \n-----------\n   |   |   \n-----------\n   |   |   \n";
    
private:
    
    
    int position [SIZE][SIZE]{{2,2,2},{2,2,2},{2,2,2}};
    static int count_steps;
    int check_steps = 0;
    vector<point> check_position;
    player pl_one;
    player pl_two;
    bool win = false;
    
    
    
    int GetStringPos(point &pos){
        int x = pos.GetX();
        int y = pos.GetY();
        int string_pos = 0;
        
        if (x==0 && y==0) {
            string_pos=1;
        }
        if (x==0 && y==1) {
            string_pos=5;
        }
        if (x==0 && y==2) {
            string_pos=9;
        }
        
        
        if (x==1 && y==0) {
            string_pos=25;
        }
        if (x==1 && y==1) {
            string_pos=29;
        }
        if (x==1 && y==2) {
            string_pos=33;
        }
        
        
        if (x==2 && y==0) {
            string_pos=49;
        }
        if (x==2 && y==1) {
            string_pos=53;
        }
        if (x==2 && y==2) {
            string_pos=57;
        }
        return string_pos;
    }
    
    
    void SetChoice(bool inDat,point &position){
        if (inDat) {
            this->position[position.GetX()][position.GetY()] = 1;
        }else this->position[position.GetX()][position.GetY()] = 0;
        
    }
    
    bool Check_Win(bool &winer){
        
//        for cross
        for (int i = 0; i<SIZE; i++) {
            if((position[i][0] == 1) && (position[i][1] == 1) && (position[i][2] == 1)){
                winer = true;
                return true;
            }
        }
        
        for (int i = 0; i<SIZE; i++) {
            if((position[0][i] == 1) && (position[1][i] == 1) && (position[2][i] == 1)){
                winer = true;
                return true;
            }
        }
        
        if((position[0][0] == 1) && (position[1][1] == 1) && (position[2][2] == 1)){
            winer = true;
            return true;
        }
        
        
        if((position[0][2] == 1) && (position[1][1] == 1) && (position[2][0] == 1)){
            winer = true;
            return true;
        }
        
//        for null
        for (int i = 0; i<SIZE; i++) {
            if((position[i][0] == 0) && (position[i][1] == 0) && (position[i][2] == 0)){
                winer = false;
                return true;
            }
        }
        
        for (int i = 0; i<SIZE; i++) {
            if((position[0][i] == 0) && (position[1][i] == 0) && (position[2][i] == 0)){
                winer = false;
                return true;
            }
        }
        
        if((position[0][0] == 0) && (position[1][1] == 0) && (position[2][2] == 0)){
            winer = false;
            return true;
        }
        
        if((position[0][2] == 0) && (position[1][1] == 0) && (position[2][0] == 0)){
            winer = false;
            return true;
        }
        
        return false;
    }
   
    

            
            
    bool build(bool inDat,point &pos){
        int check_x = pos.GetX();
        int check_y = pos.GetY();
        if(position[check_x][check_y] != 2) return false;
        
        SetChoice(inDat, pos);
        count_steps++;
        if (inDat) {
            Field[GetStringPos(pos)] = 'x';
        }else Field[GetStringPos(pos)] = 'o';
        
        bool winer;
        if (Check_Win(winer)) {
            EndGame(winer);
        }
        
        
        return true;
    }
    
    void EndGame(bool winner){
        if (winner) {
            
            for (int i = 0; i<Field.size(); i++) {
                if (Field[i] == 'x') {
                    Field[i] = 'X';
                }
            }
            
            cout << "\t\t\t\t\t\t\t\n\n\n\n X win my congratulations!\n\n";
            
        }else{
            
            for (int i = 0; i<Field.size(); i++) {
                if (Field[i] == 'o') {
                    Field[i] = 'O';
                }
            }
            
            cout << "\t\t\t\t\t\t\t\n\n\n\n O win my congratulations!\n\n";
            
        }
        
        win = true;
        
    }
    
    void Menu(){
        
        string start_menu = "\t\t\t\t\t\tWELCOME TO THE TIC-TAC-TOE\n\t\tMake crosses the first step!\n\t\tGOOD LUCK\n\n" + Field;
        cout << start_menu;
        
        
        check_steps++;
        bool check = check_steps%2;
        
        while (true) {
            if (check) {
                point pl_choice = pl_one.inf_pl(check);
                if (build(true, pl_choice)) {
                    break;
                }else continue;
                
            }else{
                point pl_choice = pl_two.inf_pl(check);
                if (build(false, pl_choice)) {
                    break;
                }else continue;
                
            }
        }
        if (!win) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            Menu();
        }
        
    
    }
    
    
public:
    
    field(){
        Menu();
    }
};




    
#endif /* field_hpp */
