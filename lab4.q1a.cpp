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
	void pop();
	bool isempty();
	int size();
	void topdisplay();
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

bool stack::isempty(){
	if(top==NULL){
		return 1;
	}
	return 0;
}

void stack::pop(){
	if(top!=NULL){
		Node *ptr=top;
	 	top=top->next;
	 	delete ptr;
	}
	else
		cout<<"Sorry No elements in the stack";
}

void stack::topdisplay(){
	cout<<top->data<<endl;
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

int main(){
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.display();
	cout<<"Size of stack now is :"<<s.size()<<endl;
	s.pop();
	s.topdisplay();
	s.pop();
	s.topdisplay();
	cout<<"Checking if the stack is empty "<<s.isempty()<<endl;

}
