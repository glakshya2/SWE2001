#include<iostream>
using namespace std;

class queue{
	int front=-1, rear=-1, n, *a;
	public:
	queue();
	void enqueue(int);
	void dequeue();
	bool isFull();
	bool isEmpty();
	void display();
};

queue::queue(){
	cout<<"Enter size of Queue\n";
	cin>>n;
	a = new int[n];
}

bool queue::isEmpty(){
	if(front==-1 && rear == -1){
		return true;
	}
	else{
		return false;
	}
}

bool queue::isFull(){
	if(rear==n-1){
		return true;
	}
	else{
		return false;
	}
}

void queue::enqueue(int x){
	if(isEmpty()){
		a[0]=x;
		front++; rear++;
	}
	else if(isFull()){
		cout<<"Already full\n";
	}
	else{
		rear++;
		a[rear]=x;
	}
}

void queue::dequeue(){
	if(isEmpty()){
		cout<<"Alreay Empty\n";
	}
	else if(!isEmpty() || front==-1){
		front++;
	}
}

void queue::display(){
	for(int i = front; i<=rear; i++){
		cout<<a[i];
	}
}

int main(void){
	queue a;
	int ch, in;
	cout<<"1.enqueue\n";
	cout<<"2.dequeue\n";
	cout<<"3.display\n";
	cout<<"4.exit\n";
	cin>>ch;
	while(ch!=4){
		switch(ch){
			case 1:
				
				cout<<"Enter element";
				cin>>in;
				a.enqueue(in);
				break;
			case 2:
				a.dequeue();
				break;
			case 3:
				a.display();
				break;
		}
		cin>>ch;
	}
}	
