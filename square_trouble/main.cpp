#include <iostream>
#include <curses.h>

using namespace std;



int main(){

initscr(); // initiazlize ncurses


hline('_' , 50);
move(1, 0);
vline('|' , 20);
move(20, 0);
hline('_' , 50);
move(1, 49);
vline('|' , 20);


move(18, 22);
hline('_' , 5);


getch(); 

endwin(); // pencereyi sonlandırır





}



//to do


//alt tarafa bir adet çubuk bastır ve o sabit dursun key geldikçe hareket etsin