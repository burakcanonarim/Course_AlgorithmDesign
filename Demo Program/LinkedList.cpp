#include <cstdlib>
#include <iostream>
#include "LinkedList.h"

using namespace std;

int LinkedList::List(){
	head = NULL;
	current = NULL;
	temp = NULL;
	
	return 0;
}

void LinkedList::addNode(int addData){
	nodePtr n = new node;
	n -> next = NULL;
	n -> data = addData;
	
	if(head != NULL){
		current = head;
		while(current -> next != NULL){
			current = current -> next;
		}
		
		current -> next = n;
	}
	
	else {
		head = n;
	}
}

void LinkedList::printList(){
	current = head;
	while(current != NULL){
		cout << current -> data << endl;
		current = current -> next;
	}
}