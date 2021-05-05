#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

// Specification file array-based list (“List.h”)

const  int  MAX_LENGTH = 50;
class  List {
public: 	          // Public member functions
    typedef int   ItemType;
    List();           // constructor
    List(const List&);
    bool IsEmpty() const;
    bool IsFull()  const;
    size_t  Length()  const; // Returns length of list 
    void Insert(ItemType  item);
    void Delete(ItemType  item);
    bool IsPresent(ItemType  item)  const;
    void SelSort();
    void Reset();
    ItemType GetNextItem();

    friend ostream& operator << (ostream&, const List&);

protected:	      // Private data members
    size_t length; // Number of values currently stored
    Node* head_ptr;
    Node* tail_ptr;
    Node* currentPosPtr; // Used in iteration
       
  };