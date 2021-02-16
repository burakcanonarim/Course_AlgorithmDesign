#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "/home/burak/workspace/Demo/LinkedList.h"
#include "/home/burak/workspace/Demo/AVL.h"


using namespace std;

int main(int argc, char **argv){
	
	int size = 19;
	int nums[size];
	
	string inFileName = "Inputs.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());
	
	if(inFile.is_open()){
		for (int i = 0; i < size; i++){
			inFile >> nums[i];
		}
		inFile.close();
	}
	else {
		cout << inFileName << "not found!" << endl;
	}
	
	LinkedList LL;
	
	for(int k = 0; k < size; k++){
		LL.addNode(nums[k]);
	}
	LL.printList();
		
	AVL avl;
	
	for(int k = 0; k < size; k++){
		avl.insertion(root, nums[k]);
	}
	
	for (int k = size; k >= 0; k--)
	{
		avl.deletion(root, nums[k]);
	}
	return 0;
}
