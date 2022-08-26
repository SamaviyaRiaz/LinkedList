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
        return 0;
    }
	
    void print(){
        Node * temp = head;
        while (temp != NULL){
            cout << temp -> getData()<< "->";
            temp = temp -> getNext();
        }
        cout << "NULL\n";
    }
	
    Node * getNodebyId(int index){ // Node
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

    int getLastElement(){
        if (!isEmpty())
            return getNodebyId(getLength())->getData();
        return -1;
    }

    int getFirstElement(){
        if (!isEmpty())
            return head->getData();
        return -1;
    }
	
    void insertAtBeginning(int value){
        Node * newNode = new Node(value);
        newNode -> setNext(head);
        head = newNode;
    }
	
    void insertAtLast(int value){
        Node * newNode = new Node(value);
        if (!isEmpty()){
            Node * temp = getNodebyId(getLength());
            temp -> setNext(newNode);
        } else {
            head = newNode;
        }
    }
	
    void removeLast(){
        if (!isEmpty() && getLength() > 1){
            Node * secLast = getNodebyId(getLength() - 1);
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
    void removeAt(int index){
        if (index == 1){
            removeFromBegining();
        }
        else if (index == getLength()){
            removeLast();
        }
        else {
            Node * prev = NULL;
            Node * temp = head;
            int count = 1;
            while (count != index){
                count++;
                prev = temp;
                temp = temp->getNext();
            }
            prev->setNext(temp->getNext());
            delete temp;
        }
    }
    void delElementOfValue(int value){
        if (value == head->getData()){
            removeFromBegining();
        }
        else {
            Node * prev = head;
            Node * temp = head->getNext();
            while (temp != NULL){
                if (value == temp -> getData()){
                    prev->setNext(temp->getNext());
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp -> getNext();
            }
        }
    }

};
int main(){
    LinkedList l1;
    l1.insertAtLast(1);
    l1.insertAtLast(2);
    l1.insertAtLast(3);
    l1.insertAtLast(4);
    l1.insertAtLast(5);
    l1.print();
    l1.removeAt(1);
    l1.delElementOfValue(2);
    l1.print();
    return 0;
}
