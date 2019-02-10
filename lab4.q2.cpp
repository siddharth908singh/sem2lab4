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

class stack{
	Node *top;
	
	public:
	stack(){
		top=NULL;
	}
	void push(int value);
	int pop();
	int size();
	void display();
};

void stack::push(int value){
	Node *ptr=new Node;
	ptr->data=value;
	
	if(top!=NULL){
		ptr->next=top;
	}
	 
	top=ptr;
}

int stack::pop(){
	Node *ptr=top;
	top=top->next;
	int temp=ptr->data;
	ptr->next=NULL;
	delete ptr;
	return temp;
}

int stack::size(){
	Node *ptr=top;int i=0;
	while(ptr!=NULL){
		ptr=ptr->next;i+=1;
	}
	
	return i;
}

void stack::display(){
	Node *ptr=top;
	while(ptr!=NULL){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
}

class queue{
	stack s1,s2;
	public:
	void enq(int val);
	void deq();	
	void display();
	int size();
};

void queue::enq(int val){
	s1.push(val);
}

void queue::deq(){
	if(s1.size()==0){
		cout<<"UNDERFLOW!!";return;
	}
	int l=s1.size();
	while(l!=1){
		s2.push(s1.pop());
		l--;
	}
	s1.pop();
	l=s2.size();
	while(l!=0){
		s1.push(s2.pop());l--;
	}
}

void queue::display(){
	s1.display();
}

int queue::size(){
	s1.size();
}

int main(){
	queue q;
	q.enq(1);
	q.enq(2);
	q.enq(3);
	q.enq(4);
	q.display();
	q.deq();
	q.display();
	return 0;
}
