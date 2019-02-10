#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node(){
		next=NULL;
	}
};

class Queue{
	Node *head,*tail;
	
	public:
	Queue(){
		head=NULL;
		tail=NULL;
	}
	void enq(int value);
	int deq();
	void display();
	int size();		
};

void Queue::enq(int value){
	Node *ptr= new Node;
	ptr->data=value;	
	if (head==NULL){
		head=ptr;tail=ptr;
	}
	else {
		ptr->next=head;
		head=ptr;
	}
}

int Queue::deq(){
	Node *ptr=head;
	while(ptr->next!=tail)
		ptr=ptr->next;
		tail=ptr;
		ptr=ptr->next;
	
	int temp = ptr->data;
	delete ptr;
	tail->next=NULL;
	return temp;
}

void Queue::display(){
	if(head==NULL)
		cout<<"Nothing To Display!!"<<endl;	
	else{
		Node *ptr=head;
		while(ptr!=NULL){
			cout<<ptr->data<<"->";	
			ptr=ptr->next;
		}
		cout<<"NULL"<<endl;
	}		
}

int Queue::size(){
	int t=0;
	Node *ptr=head;
	while(ptr!=NULL){
		t++;
		ptr=ptr->next;
	}
	return t;	
}
class Stack{
	Queue Q;	
	
	public:
	void push(int value);
	void pop();
	void display();
	int size();
};

void Stack::push(int val){
	Q.enq(val);
}

void Stack::pop(){
	if(Q.size()==0){
		cout<<"Underflow!! No Elements"<<endl;
		return;
	}
	int l=Q.size();
	while(l!=1){
		Q.enq(Q.deq());
		l--;
	}
	Q.deq();	
}

void Stack::display(){
	Q.display();
}

int Stack::size(){
	return Q.size();	
}
int main(){
	Stack S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.display();
	S.pop();
	S.display();	
	return 0;
}
