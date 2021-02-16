#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
	
private:

	typedef struct node{
		int data;
		node* next;
	}* nodePtr;
	
	nodePtr head;
	nodePtr current;
	nodePtr temp;

public:
	int List();
	void addNode(int addData);
	void printList();

};

#endif /* LINKEDLIST_H */