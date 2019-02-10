#include<iostream>
using namespace std;

class QueueArr{
	int ar[50];
	int count;
	public:
	QueueArr(){
		count=0;
	}
	void enqueue(int val);
	void dequeue();
	void display();
};

void QueueArr::enqueue(int val){
	if (count>50){
		cout<<"OVERFLOW!!,CANNOT INSERT ANYMORE VALUES DUE TO LACK OF SPACE";
	}	
	else{
		ar[count]=value;
		count++;
	}
	
}

void QueueArr::dequeue(){
	if (count==0)
		cout<<"UNDERFLOW, FUNCTION TERMINATED";
	
	else{	
		for(int i=0;i<count;i++)
		ar[i]=ar[i+1];
		
		count--;
	}
}

void QueueArr::display(){
	if(count==0)
		cout<<"No elements to print";
	
	for(int i=0;i<count;i++)
		cout<<ar[i]<<" ";
		cout<<endl;
}

int main(){
	QueueArr q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	return 0;
}
