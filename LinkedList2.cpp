using namespace std;
#include<iostream>
class Node{
private:
	int data;
	Node *next;
public:
	Node(){
		int data=0;
		next=NULL;
	}
	Node(int data,Node* next=NULL){
		setData(data);
		setNext(next);
	}
	void setData(int data){
		this->data=data;
	}
	void setNext(Node* next){
		this ->next=next;
	}
	int getData(){
		return this->data;
	}
	Node* getNext(){
		return this->next;
	}
};
class LinkedList{
private:
	Node* head;
public:
	LinkedList(){
		head=NULL;
	}
	LinkedList(Node* head){
		setHead(head);
	}
	void setHead(Node* head){
		this ->head=head;
	}
	Node* getHead(){
		return head;
	}
	bool isEmpty(){
		return (head->getNext()==NULL);
	}
	int getLength(){
		int count=0;
		if(!isEmpty()){
			Node* temp=head;
			while(temp!=NULL){
				temp=temp->getNext();
				count++;
			}
		}
		return count;
	}
	void print(){
		if(!isEmpty()){
			Node* temp=head;
			while(temp!=NULL){
				cout<<temp->getData() << '\n';
				temp = temp->getNext();
			}
		}
	}
	Node* getNthElement(int index=0){
		if(! isEmpty()){
		Node* temp=head;
		for(int i=0;i<index-1;i++){
			temp=temp->getNext();
		}
		return temp;
	}
	return head;	
	}
	Node* getLastElement(){
		return getNthElement(getLength()-1);
	}
	Node* getFirstElement(){
		return head;
	}
	void addToBegining(int value){
		if (!isEmpty())
		{
			Node* newNode = new Node(value);
			newNode->setNext(head);
			head = newNode;
		}
	}
	void addAtLast(int value){
		Node* newNode = new Node(value);
		Node* temp = getLastElement();
		temp->setNext(newNode);	
	}
	void dellLastElement(){
		{
			Node *temp1=head;
			Node *temp2=temp1->getNext();
			while(temp2!=NULL){
				temp1=temp1->getNext();
				temp2=temp2->getNext();
			}
			delete temp2;
			temp1->setNext(NULL);
		}

	}
	void removeFromBegining(){
		Node* temp=head;
		temp = head->getNext();
		delete head;
		head=temp;
	}
	void delNthElement(int index){
		Node* temp1=head;
		Node* temp2=temp1->getNext();
		for(int i=0; i<index-2;i++){
			temp1=temp1->getNext();
			temp2=temp2->getNext();
		}
		delete temp2;
		temp1->getNext();
	}
	void delElementOfValue(int value){
		Node* temp=head;
		while(temp!=NULL){
			if(value==temp->getData()){
				delete temp;
				temp=temp->getNext();
			}
		}
	}

};
int main(){
	Node* head=new Node(2);
	LinkedList l1(head);
	l1.addAtLast(10);
	l1.addToBegining(1);
	l1.print();
	delete head;
	return 0;
}
