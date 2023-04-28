#include<iostream>

using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
}; 

node* head = NULL;
node* tail = NULL;

void insertBegin(int data){
	node* temp = new node();
	if(head == NULL){
		head = temp;
		tail = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	temp->data = data;
	temp->prev = NULL;
}

void insertTail(int data){
	node* temp = new node();
	if(tail == NULL){
		head = temp;
		tail = temp;
	}
	else{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	temp->data = data;
	temp->next = NULL;
}

void insertAfter(int data, int after){
	node* temp = new node();
    node* search = head;
    while(search->data!=after){
    	search = search->next;
	}
	temp->prev = search;
	temp->next = search->next;
	temp->next->prev = temp;
	search->next = temp;
	temp->data = data;
}

void deleteFirst(){
	node* temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
}

void deleteEnd(){
	node* temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete temp;
}

void deleteAfter(int after){
	node* temp = head;
	while(temp->data!=after){
		temp = temp->next;
	}
	node* del = temp->next;
	temp->next = del->next;
	del->next->prev = temp;
	delete del;
}

void deleteKey(int key){
	node* temp = head;
	while(temp->data!=key){
		temp=temp->next;
	}
	node* previous = temp->prev;
	previous->next = temp->next;
	temp->next->prev = previous;
	delete temp;
}

void display(){
	node* temp = head;
	if(temp->next == NULL){
		cout<<temp->data<<endl;
		return;
	}
	while(temp->next!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}
int main(void){
	insertBegin(5);
	insertBegin(2);
	insertTail(10);
	insertTail(20);
	insertAfter(6,10);
	display();
	deleteEnd();
	display();
	deleteFirst();
	display();
	deleteKey(10);
	insertTail(6);
	display();
}
