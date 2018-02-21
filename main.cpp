#include "TopSpin.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Variable declarations
    int userInput;
    int puzzleMoves;
    int randNum;
    int shiftNum;
    int userBoard;
    int userSpin;
    char shiftDirection;
    char playAgain;

    //Initialize random seed:
    srand ((unsigned int) (time(NULL)));
    randNum = rand() % 19 + 1;
    
    do{
        cout<<"WELCOME TO TOP SPIN"<<endl<<endl;

        //Asking for user input
        cout<<"Input board size: "<<endl;
        cin>>userBoard;
        cout<<"Input spin size: "<<endl;
        cin>>userSpin;
        
        //Create object based on user input
        TopSpin game(userBoard,userSpin);
        
        //Display the board for the user
        cout<<game;
        
        
        //Initilizing the puzzle
        cout<<"How many moves do you want to initilaize the puzzle with: "<<endl;
        cin>>puzzleMoves;
        
        for (int i=1; i<=puzzleMoves; i++){
            for (int j=1; j<=randNum; j++){
                game.shiftLeft();
                game.spin();
            }
        }
        
        //Display the initilized board for the user
        cout<<game;
        
        
        do{
            //Display menu
            cout<<"Please choose from the following options enter your choice by entering the corresponding number:"<<endl<<endl<<"1. Shift"<<endl<<"2. Spin"<<endl<<"3. Quit"<<endl;
            cin>>userInput;
            
            //Shift
            if (userInput == 1){
                
                //Get user input
                cout<<"Please enter the following: "<<endl;
                cout<<"Direction (enter L for left shift and R for right shift) = "<<endl;
                cin>>shiftDirection;
                cout<<"Number of shifts = "<<endl;
                cin>>shiftNum;
                
                //Left shift
                if (shiftDirection == 'L' || shiftDirection == 'l')
                    for (int i=1; i<=shiftNum; i++)
                        game.shiftLeft();
                
                //Right shift
                if (shiftDirection == 'R' || shiftDirection == 'r')
                    for (int i=1; i<=shiftNum; i++)
                        game.shiftRight();
                
                //Output
                cout<<game;
                
            }
            
            //Spin
            else if (userInput == 2){
                game.spin();
                cout<<game;
            }
            
            //Quit
            else if (userInput == 3){
                cout<<"Quiting the program..."<<endl<<endl;
                break;
                
            }
            
            
            //Invalid input - repeat until valid input
            else
                cout<<"Invalid choice!"<<endl;
            
            
            //Check if the game has been solved
            if (game.isSolved()){
                cout<<"CONGRATULATIONS!!!"<<endl<<endl;
                break;
            }
            
        } while(!(userInput==1 & userInput==2 & userInput==3 & game.isSolved()));
        
        //Ask if user wants to play again
        cout<<"Would you like to play again?"<<endl<<"Enter Y for yes and N for no:"<<endl;
        cin>>playAgain;
        
    }while(playAgain=='Y' || playAgain == 'y');
    
    
/*********************************** TESTING CDLL ***********************************/
    
    //int boardSize;
    //int spinSize;
    
    //Ask for user input
    //cout<<"Enter spin size: "<<endl;
    //cin>>spinSize;
    
    //cout<<"Enter board size: "<<endl;
    //cin>>boardSize;
    
    //Create new CDLL object
    //TopSpin ts(boardSize,spinSize);
    
    //Check addTail - WORKS
    //ts.board.addTail(5)<<endl;
    
    //Check addHead - WORKS
    //ts.board.addHead(9)<<endl;
    
    //Check add - WORKS
    //ts.board.add(3,6)<<endl;
    //cout<<"Added item: "<<ts.board.retrieve(3)<<endl;

    //Check removeTail - WORKS
    //ts.board.removeTail()<<endl;
    //cout<<"Tail: "<<ts.board.retrieve(ts.board.size())<<endl;

    //Check removeHead -  WORKS
    //ts.board.removeHead()<<endl;
    //cout<<"Head: "<<ts.board.retrieve(1)<<endl;

    //Check replace - WORKS
    //ts.board.replace(3,0)<<endl;
    
    //Check retrieveHead - WORKS
    //cout<<ts.board.retrieveHead()<<endl;
    
    //Check retrieveTail - WORKS
    //cout<<ts.board.retrieveTail()<<endl;
    
    //Check size - WORKS
    //cout<<ts.board.size()<<endl;
    
    //Check isEmpty - WORKS
    //cout<<ts.board.isEmpty()<<endl;
    
    //Check remove - WORKS
    //cout<<ts.board.remove(5)<<endl;
    
    //Check retrieve - WORKS
    //cout<<ts.board.retrieve(3)<<endl;
    
    //Check isSolved - WORKS
    //cout<<ts.isSolved()<<endl;;
    
    //Check swap - WORKS
    //ts.board.swap(5, 9);
    
    //Check spin in TopSpin - WORKS
    //ts.spin();
    
    //cout<<ts;

    
    
    return 0;
}
