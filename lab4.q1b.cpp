#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node(){
		next=NULL;
	}
};

class queue{
	Node *front;
	Node *end;
	public:
	queue(){
		front=NULL;
		end=NULL;
	}
	void enqueue(int value);
	void dequeue();
	bool isempty();
	int size();
	void display();
	//void topdisplay();
};

void queue::enqueue(int value){
	Node *ptr=new Node;
	ptr->data=value;
	
	if(this->isempty()){
		front=ptr;
	}
	else{
		end->next=ptr;
	}
	end=ptr;
	
}

bool queue::isempty(){
	if(front==NULL)
		return 1;
	
	return 0;
}

void queue::dequeue(){
	if(this->isempty()==0){
		Node *ptr=front;
	 	front=front->next;
	 	delete ptr;
	}
	else
		cout<<"Sorry No elements in the queue";
}

int queue::size(){
	Node *ptr=front;int i=0;
	while(ptr!=NULL){
		ptr=ptr->next;i+=1;
	}
	
	return i;
}

void queue::display(){
	Node *ptr=front;
	while(ptr!=NULL){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
}

int main(){
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.display();
	cout<<"Now Size of the queue is "<<q.size()<<endl;
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	cout<<"Now Size of the queue is "<<q.size()<<endl;
	return 0;
}
