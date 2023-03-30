#include <iostream>
#include <ctime>
#include "List.h"

using namespace std;

/* A program to test the class List */
int main(int argc, char* argv[]) {
	List* lists[2];
	int numItems = 10;

	lists[0] = new List();
	lists[1] = new List();

	srand(time(0));
	numItems = (numItems < MAX_LENGTH ? numItems : MAX_LENGTH);

	for (int i = 0; i < numItems; i++) {
		int n = rand() % 100;
		for (List* e : lists)
			e->Insert(n);
	}

	for (List* e : lists)
		cout << typeid(*e).name() << ":\n" << *e << endl;

	cout << "SelSort() class List object: " << *lists[0] <<endl;
	lists[0]->SelSort();

	lists[0]->Reset();
	for (int i = 0; i < numItems; i++)
		cout << lists[0]->GetNextItem() << " ";
	cout << endl;


}