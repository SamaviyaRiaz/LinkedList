#include<iostream>
using namespace std;

class Node {
    private:
        int data;
        Node * next;
    public:
        Node(){
            int data = 0;
            next = NULL;
        }
    Node(int data, Node * next = NULL){
        setData(data);
        setNext(next);
    }
    void setData(int data){
        this-> data = data;
    }
    void setNext(Node * next){
        this-> next = next;
    }
    int getData(){
        return this-> data;
    }
    Node * getNext(){
        return this-> next;
    }
};
class LinkedList {
    private:
        Node * head;
    public:
        LinkedList(){
            head = NULL;
        }
	
    void setHead(Node * head){
        this -> head = head;
    }
	
    Node * getFirst(){
        if (!isEmpty())
            return head;
        return NULL;
    }
	
    bool isEmpty(){
        return (head == NULL);
    }
	
    int getLength(){
        if (!isEmpty()){
            int count = 0;
            Node * temp = head;
            while (temp != NULL){
                temp = temp -> getNext();
                count++;
            }
            return count;
        }
        return -1;
    }
	
    void print(){
        Node * temp = head;
        while (temp != NULL){
            cout << temp -> getData()<< "->";
            temp = temp -> getNext();
        }
        cout << "NULL\n";
    }
	
    Node * getNthElement(int index){ // Node
        if (!isEmpty()&& (index <= getLength())&& (index > 0)){
            Node * temp = head;
            int count = 1;
            while (count != index){
                temp = temp -> getNext();
                count++;
            }
            return temp;
        }
        return NULL;
    }

    Node * getLastElement(){
        return getNthElement(getLength());
    }

    Node * getFirstElement(){
        if (!isEmpty())
            return head;
        return NULL;
    }
	
    void addToBegining(int value){
        Node * newNode = new Node(value);
        newNode -> setNext(head);
        head = newNode;
    }
	
    void addAtLast(int value){
        Node * newNode = new Node(value);
        if (!isEmpty()){
            Node * temp = getLastElement();
            temp -> setNext(newNode);
        } else {
            head = newNode;
        }
    }
	
    void dellLastElement(){
        if (!isEmpty() && getLength() > 1){
            Node * secLast = getNthElement(getLength() - 1);
            Node * last = secLast->getNext();
            delete last;
            secLast->setNext(NULL);
        }
        else {
            delete head;
            head = NULL;
        }
    }
    void removeFromBegining(){
        if (!isEmpty()){
            if (head->getNext() == NULL){
                delete head;
                head = NULL;
            }
            else {
                Node * temp = head;
                temp = head -> getNext();
                delete head;
                head = temp;
            }
        }
    }
    void delNthElement(int index){
        Node * temp1 = head;
        Node * temp2 = temp1 -> getNext();
        for (int i = 0; i < index - 2; i++){
            temp1 = temp1 -> getNext();
            temp2 = temp2 -> getNext();
        }
        delete temp2;
        temp1 -> getNext();
    }
    void delElementOfValue(int value){
        Node * temp = head;
        while (temp != NULL){
            if (value == temp -> getData()){
                delete temp;
                temp = temp -> getNext();
            }
        }
    }

};
int main(){
    LinkedList l1;
    l1.addToBegining(1);
    l1.addAtLast(0);
    l1.dellLastElement();
    l1.removeFromBegining();
    l1.addToBegining(1);
    l1.addAtLast(0);
    l1.print();
    return 0;
}
