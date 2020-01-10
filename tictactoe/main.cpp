#include<iostream>
#include "tahta.h"

using namespace std;


bool isEnd(Board &__board){

        char temp='O';  

        int flag=0;  //if flag is three somebody wins

        //vertical board's coordinate controls
        for(int k=0;k<2;k++){ //first loop is x second loop o
           for(int i=0;i<=4;i=i+2){
                for(int j=0;j<=4;j=j+2){
                        if(__board.getCoordinate(j,i)==temp) 
                            flag++;
                }

                if(flag==3){
                    cout<<"------Congrutulations"<<temp<<" WON"<<"--------"<<endl;
                    return 1;
                }
                flag=0;
            }


                temp='X';

        }
        //horizontal board's coorditane controls
        for(int k=0;k<2;k++){
           for(int i=0;i<=4;i=i+2){
                for(int j=0;j<=4;j=j+2){
                        if(__board.getCoordinate(i,j)==temp)
                        flag++;
                }     
                      
                if(flag==3){
                    cout<<"------Congrutulations"<<temp<<""<<" WON"<<"--------"<<endl;
                    return 1;
                }

                flag=0;
            }
                temp='O';

        }
        //boards cross controls
        for(int i=0;i<2;i++){ 
            if(__board.getCoordinate(0,0) == temp){     //left to right
                if(__board.getCoordinate(2,2) == temp){
                    if(__board.getCoordinate(4,4) == temp){
                        cout<<"------Congrutulations"<<temp<<" WON"<<"--------"<<endl;
                        return 1;
                    }
                }
            }

            else if(__board.getCoordinate(0,4) == temp){ //right to left
                if(__board.getCoordinate(2,2) == temp){
                    if(__board.getCoordinate(4,0) == temp){
                        cout<<"------Congrutulations"<<temp<<" WON"<<"--------"<<endl;
                        return 1;
                    }
                }
            }
            
        temp='X';
        }

        flag=0;
        //full
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(__board.getCoordinate(i,j)=='*'){
                    flag++;
                }
            }
        }
        if(flag==0){
            cout<<"There is no probability"<<endl;
            return 1;
        }
        return 0;
  
}

void Play(Board &__board){

    int x=0,y=0;
    bool end=true;

    while(1){
        

        cout<<"----1s player's turn-----"<<endl;

        cout<<"Player1 move X coordinate: "<<endl;
        cin>>x;


        
        cout<<"Player1 move Y coordinate: "<<endl;
        cin>>y;
        
        __board.setMove_O(x,y);
        __board.displayBoard();
        
        end=isEnd(__board);

        if(end==1){
            break;
        }  

        cout<<"----2s player's turn-----"<<endl;

        cout<<"Player2 move X coordinate: "<<endl;
        cin>>x;
        
        cout<<"Player2 move Y coordinate: "<<endl;
        cin>>y;

        __board.setMove_X(x,y);
        __board.displayBoard();
    
        end=isEnd(__board);  

        if(end==1){
            break;
        }  
      
    }
}

int main(){
    Board __board;
    Play(__board);
}