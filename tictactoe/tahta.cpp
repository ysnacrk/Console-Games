#include "tahta.h"
#include <iostream>

using namespace std;

Board::Board(){

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i%2==1 && i>0){              
              if(j%2==1)
                __board[i][j]='.';     
              else{
                __board[i][j]='_'; 
              } 
                  
            }
            else{
                if(j%2==1 && j>0){    
                __board[i][j]='|';            
                }
                else{
                 __board[i][j]='*';               
                }                
            }
        }
    }
}

void Board::displayBoard(){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){

                cout<<__board[i][j];
            }
                cout<<endl;
        }
}

void Board::setMove_X(int x,int y){ 
        if(x==1||x==2)
            x*=2;

        if(y==1||y==2)
            y*=2;
    
        if(__board[x][y]=='*')
            __board[x][y]='X';
    
}
void Board::setMove_O(int x,int y){
        if(x==1||x==2)
            x*=2;

        if(y==1||y==2)
            y*=2;

        if(__board[x][y]=='*')
            __board[x][y]='O';
        
}

int Board::getCoordinate(int x,int y){
    return __board[x][y];
}