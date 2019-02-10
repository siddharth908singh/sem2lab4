#include<iostream>
using namespace std;

class StackArr{
	int ar[50];
	int count;
	public:
	StackArr(){
		count=0;
	}
	void push(int val);
	void pop();
	void display();
};

void StackArr::push(int value){
	if (count>50){
		cout<<"OVERFLOW!!,CANNOT INSERT ANYMORE VALUES DUE TO LACK OF SPACE";
	}	
	else{
		for(int i=count;i>0;i--)
			ar[i]=ar[i-1];
		
			ar[0]=value;
			count++;
	}
	
}

void StackArr::pop(){
	if (count==0)
	cout<<"UNDERFLO, FUNCTION TERMINATED";
	
	else {	
		for(int i=0;i<count;i++)
		ar[i]=ar[i+1];
		
		count--;
	}
}

void StackArr::display(){
	if(count==0)
		cout<<"No elements to print";
	
	for(int i=0;i<count;i++)
		cout<<ar[i]<<" ";
		cout<<endl;
}

int main(){
	StackArr s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5):
	s.push(6);
	s.display();
	s.pop();
	s.display();
	s.pop();
	s.display();
	return 0;
}
