
#include<iostream>

using namespace std;

struct Node{
  string data;
   Node* next_ptr;
};

int main(){
	//create nodes
  Node node1;
  Node node2;
  Node node3;
  
  //assign data
  node1.data = "test1";
  node2.data = "test2";
  node3.data = "test3";
  
  //link nodes
  node1.next_ptr = &node2;
  node2.next_ptr = &node3;
  node3.next_ptr= nullptr;
  
  // traverse list 
  Node* current = &node1;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next_ptr;
    }
    cout << endl;
    return 0;
}
