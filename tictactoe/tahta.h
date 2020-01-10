#include <iostream>

class Board{
    private:
        char __board [5][5];

    public:
        Board();
        void displayBoard();

        void setMove_X(int x,int y);
        void setMove_O(int x,int y); 

        int getCoordinate(int x,int y);
        
};