#pragma once

#include <stdio.h>
#include "CircularDoublyLinkedList.h"
#include <iostream>


class TopSpinADT {
public:
    virtual void shiftLeft() = 0;
    virtual void shiftRight() = 0;
    virtual void spin() = 0;
    virtual bool isSolved() = 0;
};


class TopSpin: public TopSpinADT{
    
private:
    int _bSize;
    int _sSize;
    
public:
    int firstIndex;
    CircularDoublyLinkedList<int> board;

    //Function declarations
    TopSpin(unsigned int boardSize, unsigned int spinSize);
    int getBoardSize() const;
    int getSpinSize() const;
    void shiftLeft() override;
    void shiftRight() override;
    void spin() override;
    bool isSolved() override;

    //Destructor declaration
    ~TopSpin();
};


//Print operator
inline std::ostream& operator<< (std::ostream& os, const TopSpin& ts){
    
    cout<<endl;
    
    //Shifting numbers to the beginning
    if (ts.firstIndex>(ts.getBoardSize()-ts.getSpinSize()+1)){
        cout<<"[";
        for (int i = ts.firstIndex;i <= ts.getBoardSize();i++)
            cout<<ts.board.retrieve(i);
    }
    
    else{
        cout<<"[";
        for (int i=ts.firstIndex; i<(ts.firstIndex+ts.getSpinSize()); i++)
            cout<<" "<<ts.board.retrieve(i);
        cout<<" ]";
        for (int i= (ts.firstIndex + ts.getSpinSize()); i<= ts.getBoardSize(); i++)
            cout<<" "<<ts.board.retrieve(i);
    }
    
    for (int i=1; i < (ts.getSpinSize()-(ts.getBoardSize()-ts.firstIndex)); i++){
        cout<<" "<<ts.board.retrieve(i);
    }
    
    //The rest of the numbers that shifted to the end of the board
    if (ts.firstIndex > (ts.getBoardSize()-ts.getSpinSize()+1)){
        cout<<" ]";
        for (int i = (ts.getSpinSize()-(ts.getBoardSize()-ts.firstIndex)); i < ts.firstIndex; i++)
            cout<<" "<<ts.board.retrieve(i);
    }
    
    else
        for (int i=1; i<ts.firstIndex; i++)
            cout<<" "<<ts.board.retrieve(i);
    
    cout<<endl<<endl;
    
    return os;
}

