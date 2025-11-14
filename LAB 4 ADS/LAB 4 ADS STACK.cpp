#include <iostream> 
using namespace std;

struct Node{
	string data;
	Node * next_ptr;
};

class Stack {
private:
	Node * top;
	
public :
	Stack(){
		top = nullptr;
	}		
	
	void push (string value){
		Node * newNode = new Node;
		newNode -> data= value;
		newNode -> next_ptr= top;
		top= newNode;
	}
	
	void pop(){
		if (top == nullptr){
			cout << "Stack is empty! Cannot pop.\n";
			return;
		}
		
		Node * temp = top;
		top= top-> next_ptr;
		cout << "Popped:" << temp ->data << endl;
		delete temp;
	}
	
	void peek (){
		if (top == nullptr){
			cout << "Stack is empty !\n";
			return;
		}
		cout << "Top element: " << top->data << endl;
	}
	
	void display (){
		Node* current = top;
		cout << "Stack (top -> bottom):";
		while (current != nullptr){
			cout << current -> data << " ";
			current = current -> next_ptr;
		}
		
	cout << endl;
	}
};

int main (){
	Stack s;
	
	s.push ("A");
	s.push ("B");
	s.push ("C");
	
	s.peek();
	s.pop();
	s.display();
	
	return 0;
}
