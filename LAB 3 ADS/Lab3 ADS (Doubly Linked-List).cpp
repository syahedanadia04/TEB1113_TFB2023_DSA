#include <iostream>
#include <string>
using namespace std;

struct Node{
	string data;
	Node* next_ptr;
	Node* prev_ptr;
};

int main(){
	Node node1;
	Node node2;
	Node node3;
	
	node1.data= "test1";
	node2.data= "test2";
	node3.data= "test3";
	
	node1.next_ptr = &node2;
    node1.prev_ptr = nullptr;
	
	node2.next_ptr= &node3;
	node2.prev_ptr = &node1;
	
	node3.next_ptr= nullptr; // last node has no next
	node1.prev_ptr = &node2;
	
	// traverse forward 
	cout << "Forward traversal: ";
	Node * current = &node1;
	while (current!= nullptr){
		cout << current -> data << " ";
		current = current ->next_ptr;
	}
	
	cout << endl;
	
	//traverse backward
	cout << "Backward traversal:";
	current = &node3; //start from last node
	while (current != nullptr){
		cout << current->data << " ";
		current = current ->prev_ptr;
	}
	
	cout << endl;
	
	return 0;
	
}
