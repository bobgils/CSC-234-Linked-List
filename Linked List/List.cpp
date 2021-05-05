#include "List.h"
#include "linkplus.h"
#include "Node.h"

// Implementation file linked-list list 
// 
//no parameter constructor
List::List(): length(0)
	// Constructor
	// Post: length == 0
{
	head_ptr = NULL;
	tail_ptr = NULL;
	currentPosPtr = NULL;
}

// copy constructor
List::List(const List& rhs) {
	list_copy(rhs.head_ptr, head_ptr, tail_ptr);
	length = rhs.length;

}

size_t  List::Length() const {
	return (length);
}


void  List::Insert(ItemType  item)
	// Pre: length < MAX_LENGTH && item is assigned
	// Post: data[length@entry] == item && 
	//       length == length@entry + 1
{
	if (head_ptr == NULL) {
		list_head_insert(head_ptr, item);
		tail_ptr = head_ptr;
	}
	else {
		list_insert(tail_ptr, item);
		tail_ptr = tail_ptr->link();
	}
	length++;
}

bool  List::IsFull()  const
// Post: Return value is true 
//       if length is equal
//  to MAX_LENGTH and false otherwise
{
	return length >= MAX_LENGTH;
}

bool  List::IsEmpty()  const
// Post: Return value is true if length is equal
//  to zero and false otherwise
{
	return (length == 0);
}


bool List::IsPresent( /* in */ ItemType item) const
	// Searches the list for item, reporting 
	//   whether found
	// Post: Function value is true, if item is in 
	//   data[0 . . length-1] and is false otherwise
{
	return  (list_search(head_ptr, item) != NULL);
}



void  List::Delete( ItemType  item)
	// Pre: length > 0  &&  item is assigned
	// Post: IF item is in data array at entry
	//		First occurrence of item is no longer 
	//   in array
	//		   && length == length@entry - 1
	//		ELSE
	//       length and data array are unchanged
{
	Node* previousPtr = NULL;
	Node* cursorPtr = head_ptr;

	while (cursorPtr != NULL) {
		if (cursorPtr->data() == item){
			if (cursorPtr == head_ptr)
				list_head_remove(head_ptr);
			else
				list_remove(previousPtr);
			break;
		}
		previousPtr = cursorPtr;
		cursorPtr = cursorPtr->link();
	}

}

void List::Reset()
	// Post-condition: currentPos has been initialized
{
	currentPosPtr = head_ptr;
}

List::ItemType List::GetNextItem()
	// Pre: No transformer has been executed since last call
	// Post:Return value is currentPos@entry
	//   Current position has been updated
	//   If last item returned, next call returns first item
{
	ItemType item;
	item = currentPosPtr->data();
	if (currentPosPtr->link() == NULL)
		currentPosPtr = head_ptr;
	else
		currentPosPtr = currentPosPtr->link();
	return item;

}

void  List::SelSort()
	// Sorts list into ascending order 
{
	ItemType temp;
	Node* passCountPtr = head_ptr;
	Node* sIndxPtr;
	Node* minIndxPtr; // Index of minimum so far    
	while (passCountPtr != NULL)
	{
		minIndxPtr = passCountPtr;
		// Find index of smallest value left
		sIndxPtr = passCountPtr->link();
		while (sIndxPtr != NULL) {
			if (sIndxPtr->data() <= minIndxPtr->data())
				minIndxPtr = sIndxPtr;
			sIndxPtr = sIndxPtr->link();
		}
		temp = minIndxPtr->data();		// Swap 
		minIndxPtr->set_data(passCountPtr->data());
		passCountPtr->set_data(temp);
		passCountPtr = passCountPtr->link();
	}

}

ostream& operator << (ostream& os, const List& l) {
	// Post: If the list is not empty, the elements are
	//       printed on the screen in increasing order;
	//       otherwise "The list is empty" is
	//       printed on the screen.
	int index = 0;
	List sl(l);

	sl.Reset();
	while (index < sl.length) {
		os << sl.GetNextItem() << " ";
		index++;
	}
	os << endl;
	return os;
}
