#include "TopSpin.hpp"
#include <iostream>

using namespace std;

//TopSpin constructor creats a TopSpin object with size numbers and a spin mechanism of spinSize
TopSpin::TopSpin(unsigned int boardSize, unsigned int spinSize){
    
    //Initilization of variables
    _bSize = boardSize;
    _sSize = spinSize;
    firstIndex = 1;
    
    //Check bounds
    if((boardSize >=1) && (spinSize <= boardSize))
        for (int i = 1; i<= boardSize; i++)
            board.addTail(i);
    
    //If out of bounds:
    //Default value of size should be 20, spinSize should default to 4
    else{
        cout<<"Invalid input! Program resorting to default settings: "<<endl;
        _bSize = 20;
        _sSize = 4;
        for (int i = 1; i<= 20; i++)
            board.addTail(i);
    }
    
}

//This function returns the board size of the CDLL object
int TopSpin::getBoardSize() const{
    return board.size();
}

//This function returns the spin size of the CDLL object
int TopSpin::getSpinSize() const{
    return _sSize;
}

//This function shifts the pieces 1 to the right
void TopSpin::shiftRight(){
    board.m_head = board.m_head->previous;
    board.m_tail = board.m_tail->previous;
}

//This function shifts the pieces 1 to the left
void TopSpin::shiftLeft(){
    board.m_head = board.m_head->next;
    board.m_tail = board.m_tail->next;
}

//This function reverses the pieces in the spin mechanism
void TopSpin::spin(){
    int m = getSpinSize();
    for (int i = 0; i <= (m/2); i++)
        board.swap((i+1),(m--));
}


//This function checks if the game has been solved
bool TopSpin::isSolved(){
    
    
    int minValue = board.retrieve(1);       //this is the lowest value in the board
    int minIndex = 1;                       //this variable keeps track of the index of the lowest val
    int n = 0;                              //this is a counter variable
    
    
    //Loop until the minimum value is found
    for (int i = 1; i < getBoardSize(); i++){
        if (board.retrieve(i) < minValue){
            //Store the minimum value index and value
            minValue = board.retrieve(i);
            minIndex = i;
        }
    }
    
    
    //Check both sides of the min value to see if the numbers are in a row
    
    for (int s = minIndex; s < getBoardSize(); s++)
        if (board.retrieve(s) < board.retrieve(s + 1))
            n++;
    for (int f = 1; f < minIndex; f++)
        if (board.retrieve(f) < board.retrieve(f + 1))
            n++;
    if (board.retrieve(getBoardSize()) < board.retrieve(1))
        n++;
    if (n == getBoardSize() - 1)
        return true;
    
    else
        return false;
}


TopSpin::~TopSpin(){
    //Check if the destructor is getting called - IT IS
    //cout<<"destructor"<<endl;
}
