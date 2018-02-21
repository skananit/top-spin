#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
class CircularDoublyLinkedList{
    
public:
    //Doubly linked nodes = basic containers of a doubly linked list
    class Node{
    public:
        int value;
        Node * next;
        Node * previous;
        
        //Node constructors
        Node(){
            value = 0;
            next = nullptr;
            previous = nullptr;
        }
        Node(Node * n){
            next = n-> next;
            previous = n->previous;
            value = n->value;
        }
        Node(int val, Node *prev = nullptr, Node *nx = nullptr){
            next = nx;
            previous = prev;
            value = val;
            
        }
        const int& operator==(Node* m){
            if ((this->next) == (m->next) && (this->previous) == (m->previous) && (this->value) == (m->value))
                return 1;
            else
                return 0;
        }
    };
    
    //Constructor declarations
    CircularDoublyLinkedList();
    CircularDoublyLinkedList(int listSize);
    CircularDoublyLinkedList(const CircularDoublyLinkedList &other);
    
    //Function declarations
    unsigned int size() const;
    void add(unsigned int n, T item);
    void swap(int a, int b);
    void addTail(T item);
    void addHead(T item);
    bool isEmpty() const;
    T removeHead();
    T removeTail();
    T retrieveHead() const;
    T retrieveTail() const;
    T retrieve(unsigned int n) const;
    T replace(unsigned int n, T item);
    T remove(unsigned int n);
    
    
    //Destructor declaration
    ~CircularDoublyLinkedList();
  
    Node * m_head;
    Node * m_tail;
    Node * temp;
    Node *s, *ptr;
    unsigned int m_size;
};


//Default constructor
template <class T>
CircularDoublyLinkedList<T> ::CircularDoublyLinkedList(){
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

//Constructor with parameters
template <class T>
CircularDoublyLinkedList<T> ::CircularDoublyLinkedList(int listSize){
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    for (int i = 1;i <= listSize;i++)
        addTail(i);
    //Print the node values for checking
    //cout << "m_head.previous is: " << m_head->previous->value << endl;
    //cout << "m_tail.next is: " << m_tail->next->value << endl;
}


//Copy constructor
template <class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(const CircularDoublyLinkedList<T> &other) {
    
    //Case 1 - empty list
    if (other.m_size == 0){
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }
    
    //Case 2 - full list
    else{
        m_size = other.m_size;
        m_head = new Node(other.m_head->value, nullptr);
        if (other.m_tail == nullptr) {
            m_tail = m_head;
        }
        else{
            Node * copyFrom = other.m_head->next;
            Node *nextNode= m_head;
            
            //Copy the values
            while (copyFrom != nullptr){
                nextNode->next = new Node(copyFrom->value);
                copyFrom = copyFrom->next;
                nextNode = nextNode->next;
            }
            m_tail = nextNode;
        }
        
    }
}

//This function adds an item to end of list
template <class T>
void CircularDoublyLinkedList<T> ::addTail(T item){
    if (isEmpty()) addHead(item);
    else{
        temp = new Node;
        temp -> value = item;
        m_tail -> next = temp;
        temp -> previous = m_tail;
        m_tail = temp;
        m_head -> previous = m_tail;
        m_tail ->next= m_head;
        m_size++;
    }
}

//This function returns the number of items in the list
template <class T>
unsigned int CircularDoublyLinkedList<T> ::size() const{
    return m_size;
}


//This function returns true if the list is empty, and false otherwise
template <class T>
bool CircularDoublyLinkedList<T> ::isEmpty() const
{
    return (m_size == 0);
}

//This function adds item to front of list
template <class T>
void CircularDoublyLinkedList<T> ::addHead(T item)
{
    temp = new Node(item, m_head);
    if (m_head == m_tail && m_head == NULL)
    {
        m_head = m_tail = temp;
        m_head->next = m_tail->next = NULL;
        m_head->previous = m_tail->previous = NULL;
    }
    else
    {
        temp->next = m_head;
        m_head->previous = temp;
        m_head = temp;
        m_head->previous = m_tail;
        m_tail->next = m_head;
    }
    m_size++;
}

//This function removes front node, and return the data T found in it
template <class T>
T CircularDoublyLinkedList<T> ::removeHead(){
    assert((!isEmpty()&&"The list is empty"));
    Node * oldNode = m_head;
    T returnVal = m_head->value;
    m_head = m_head->next;
    if (m_head == nullptr) m_tail = nullptr;    //if the list is empty
    m_size--;
    delete oldNode;
    return returnVal;
}

//This function returns the data T in the front node
template <class T>
T CircularDoublyLinkedList<T> ::retrieveHead() const{
    assert((!isEmpty()&& "LinkedList is Empty (in retrieveHead)"));
    return m_head->value;
}


//This function removes last node, and returns the data T found in it
template <class T>
T CircularDoublyLinkedList<T> ::removeTail(){
    assert((!isEmpty()&& "LinkedList is Empty (in removeTail)"));
    if (m_head == m_tail) return removeHead();
    T returnVal = m_tail->value;
    Node * preTail = m_head;
    while (preTail->next != m_tail)
        preTail = preTail->next;
    preTail->next = nullptr;
    delete m_tail;
    m_tail = preTail;
    m_size--;
    return returnVal;
}

//This function returns data T in the last node
template <class T>
T CircularDoublyLinkedList<T> ::retrieveTail() const{
    assert((!isEmpty()&& "LinkedList is Empty (in retrieveTail)"));
    return m_tail->value;
}

//This function adds a new node containing an item in position n on the list
template <class T>
T CircularDoublyLinkedList<T> ::retrieve(unsigned int n) const{
    assert(((n >= 1) && (n <= size())&& "LinkedList index is out of bounds (in retrieve)"));
    if (n == 1) return retrieveHead();
    if (n == size()) return retrieveTail();
    Node * here = m_head;
    for (unsigned int k = 1; k < n; k++) here = here->next;
    return here->value;
}


//This function adds a new node containing an item in position n on the list
template <class T>
void CircularDoublyLinkedList<T> ::add(unsigned int n, T item){
    temp = new Node(item);
    if (m_head == m_tail && m_head == NULL)
    {
        //if adding to the first position
        if (n == 1){
            m_head = m_tail = temp;
            m_head->next = m_tail->next = NULL;
            m_head->previous = m_tail->previous = NULL;
        }
        else{
            cout<<"Position out of range"<<endl;
            return;
        }
    }
    else{
        if (m_size < n)
        {
            cout<<"Position out of range"<<endl;
            return;
        }
        
        s = m_head;
     int i =1;
        for (i; i <= m_size;i++)
        {
            ptr = s;
            s = s->next;
            if ( i == (n - 1))
            {
                ptr->next = temp;
                temp->previous = ptr;
                temp->next = s;
                s->previous = temp;
                cout<<"Element inserted"<<endl;
                m_size++;
                break;
            }
        }
    }
     
}

// This function replaces the data stored in position n of the list with item, and returns the replaced item
template <class T>
T CircularDoublyLinkedList<T> ::replace(unsigned int n, T item)
{
    assert(((n >= 1) && (n <= size())&& "LinkedList index is out of bounds (in replace)"));
    T returnValue;
    Node * here = m_head;
    for (unsigned int k = 1; k < n; k++)
        here = here->next;
    returnValue = here->value;
    here->value = item;
    return returnValue;
}


//This function removes the node at position n from the list, and returns the item it contained
template <class T>
T CircularDoublyLinkedList<T> ::remove(unsigned int n){
    assert(((n >= 1) && (n <= size())&& "LinkedList index is out of bounds (in remove)"));
    if (n == 1) return removeHead();
    if (n == size()) return removeTail();
    Node * here = m_head;
    for (unsigned int k = 1; k < n - 1; k++)
        here = here->next;
    Node * kill = here->next;
    T returnVal = kill->value;
    here->next = kill->next;
    delete kill;
    m_size--;
    return returnVal;
}

//This function swaps two nodes that are passed to it as parameters
template <class T>
void CircularDoublyLinkedList<T> ::swap(int a, int b){
    Node * temp1 = m_head;
    Node * temp2 = m_head;
    for (int i = 1; i<a; i++) temp1 = temp1->next;
    for (int i = 1; i<b; i++) temp2 = temp2->next;
    unsigned k = temp1-> value;
    temp1 -> value = temp2-> value;
    temp2 -> value = k;
}


//This destructor destroys a circular doubly linked list
template <class T>
CircularDoublyLinkedList<T> :: ~CircularDoublyLinkedList(){
    // loop until the tail is found then delete
    Node * here = m_head, *nextNode;
    Node * tail = m_tail;
    while (here != tail){
        nextNode = here->next;
        delete here;
        here = nextNode;
    }
}


