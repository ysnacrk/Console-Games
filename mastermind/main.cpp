#include <iostream>
#include<time.h>
#include <math.h>
#include <vector>

using namespace std;

int produceNumber(int range,int digit){

    int randNum = 0;
    int retNum = 0;
    srand(time(NULL));

    randNum = rand () % range +1;
    retNum = pow(10,(digit-1))*randNum;

    for(int i=0 ; i<(digit -1) ; i++){
        randNum = rand () % range;
        retNum += pow(10,i)*randNum;
    }
    return retNum;
}
void compare(int num1 , int num2,int len){

    int temp = 0;
    int temp2 = 0;

    int counter = 0;
    int counter2 = 0;

    int flag = 0;

    temp = num1;
    temp2 = num2;

    vector<int> vec;
    vector<int> vec2;
    vector<int>::iterator it;

    for(int i=0 ; i<len ; i++){

        if((temp%10) == (temp2%10)){

            vec.push_back(i);
            counter++;
            temp /=10;
            temp2 /=10;
            continue;
        }
        vec.push_back(0);
        temp /=10;
        temp2 /=10;
    }

    for(int i=0; i<len ; i++){
        temp = num1 % 10;
        temp2 = num2;

        for(int j=0 ; j<len ; j++){

            if(vec[j] == j)
                continue;

            if(temp != (temp2%10)){
                temp2 /= 10;
            }
            else{
                for(it = vec2.begin() ; it != vec2.end() ; it++){
                    if( *it == (temp2%10)){
                        flag++;
                        break;
                    }
                }
                if(flag == 0){
                    counter2++;
                    vec2.push_back(temp2%10);
                    temp2 /= 10;
                }
                temp2 /= 10;
            }
            flag = 0;
        }
        num1 /= 10;
    }
    for(int i=0;i<counter;i++)
        cout<<" * ";
    for(int i=0;i<counter2;i++)
        cout<<" o ";
}
int main()
{
    unsigned int digit; //take the digits of number exp "4" -> 1969
    unsigned int range; //take the limit ex 0-6 -> can not be "789"
    unsigned int num;   //take the user number

    cout<<"Digits :"<<endl;
    cin>>digit;
    cout<<"Range :"<<endl;
    cin>>range;

    unsigned int randomNum = produceNumber(range,digit);

    while(num != randomNum){
        cout<<">";
        cin>>num;
        compare (randomNum, num , digit);
    }
    cout<<"----- Congratulation You Find The Number -----";

    return 0;
}
