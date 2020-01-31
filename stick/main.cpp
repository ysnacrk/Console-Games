#include <iostream>
#include <curses.h>

#define WIDTH 9
using namespace std;

int  stickWidth = WIDTH;
int tower [20][WIDTH] = {-1};


void delay(int level){
    

        if(level < 2){
            level = 2;
        }
        level *= 8000000 ; 
        for(int i = 0 ; i < level ; i++){
        }
        refresh();
}

void setTower(){

    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < WIDTH ; j++){
            if(tower[i][j] != -1){
                move(i , tower[i][j]);
                hline('_' ,1);
            }
        }
    }
}

void initState(){

    hline('_' , 50);
    move(1, 0);
    vline('|' , 20);
    move(20, 0);
    hline('_' , 50);
    move(1, 49);
    vline('|' , 20);
    setTower();
}

void updateState(){
    clear();
    initState();
}

int main(){

    // initiazlize ncurses

    initscr(); 
    curs_set(0);
    nodelay(stdscr, TRUE);
    noecho();

    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < WIDTH; j++){
            tower[i][j] = -1;
        }
    }

    //game state
    //--update and run

    int tempCounter = 0;
    int test = 0;
    int i = 0;
    int Y = 18;
    int level = 4;
    char ch;

    for(int j = 0 ; j < WIDTH; j++){
        tower[19][j] = 20 + j;
    }

    while(true){

        ch = getch();

        if(ch == 'x'){

            tempCounter = stickWidth;
            stickWidth = 0;

            for(int j = 0 ; j < tempCounter ; j++){
                for(int k = 0 ; k  < WIDTH ; k++){
                    if((i + j) == tower[Y + 1][k]){
                        tower[Y][k] = i + j; 
                        stickWidth++;
                        break;
                    }
                }
            }
            
            i += stickWidth;
            Y--;
            if(Y % 2 == 0){
                level--;
            }    
        }

        updateState();
        move(Y  , i);
        hline('_' ,  stickWidth);
        delay(level);

        i++;

        if(i == 45){

            for(int j = 1; j < stickWidth ; j++){
                
                updateState();
                move(Y , i);
                hline('_' , 4-j);
                move(Y , 1);
                hline('_' , j);
                delay(level);
            }
            i=2;
        }

        //finish game
        if(stickWidth == 0 && Y > 5){
            move(12, 12);
            printw("******  GAME OVER  *****");
        }
        else if(Y == 5 &&  stickWidth > 0){
            break;
        }
    }
    
    move(12, 12);
    printw("******  WIN  *****");
    ch = getch();
}
