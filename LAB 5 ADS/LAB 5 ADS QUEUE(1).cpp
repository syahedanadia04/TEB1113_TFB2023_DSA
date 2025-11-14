#include <iostream>
using namespace std;

struct Node{
	string data;
	Node * next_ptr;
};

class Queue{
private:
	Node * front;
	Node * rear;
	
	public:
		Queue(){
			front = nullptr;
			rear = nullptr;
		}
		
		void enqueue (string value){
			Node * newNode = new Node;
			newNode ->data = value;
			newNode ->next_ptr = nullptr;
			
			// if queue empt
			if (rear == nullptr){
				front = rear = newNode;
			} else{
				rear -> next_ptr = newNode;
				rear = newNode;
			} 
			cout << "Enqueued" << value << endl;
		}
		
		//dequeue
		void dequeue (){
			if (front == nullptr){
				cout << "Queue is empty! Cannot dequeue.\n";
				return;
			}
			
			Node * temp = front;
			cout << "Dequeued: " << temp->data << endl;
			
			front = front-> next_ptr;
			if (front == nullptr)
				rear = nullptr;
				
			delete temp;
		}
		
		void peek (){
			if (front == nullptr)
				cout << "Queue is empty! \n";
			else 
				cout << "Front element: " << front->data << endl;			
		}
		
		bool isEmpty(){
			return front == nullptr;
		}
		
		void display(){
			Node * current = front;
			cout << "Queue (front-> rear):";
			while (current != nullptr){
				cout << current-> data << " ";
				current = current -> next_ptr;
			}
			cout << endl;
		}
};

int main (){
	Queue q;
	
	q.enqueue ("A");
	q.enqueue ("B");
	q.enqueue ("C");
	
	q.display ();
	
	q.peek();
	q.dequeue();
	q.display();
	
	return 0;
}