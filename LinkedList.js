class Node{
    constructor(data, next = null){
        this.data = data;
        this.next = next;
    }
};

class LinkedList{
    constructor(){
        this.head = null;
        // this.length = 0;
    }
    isEmpty(){
        return (this.head == null);
    }
    insertAtBeginning(value){
        if(this.head == null)
        {
            this.head = value;
        }
        let temp = new Node(value);
        temp.next
        this.head = temp;
        // this.length++;
    }
    insertAtLast(value)
    {
        if(this.isEmpty())
        {
            this.insertAtBeginning(value);
        }
        else{
            let temp = this.head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            var temp1 = new Node(value);
            temp.next = temp1;
            // this.length++;
        }
    }
     getFirstValue(){
        if(!this.isEmpty())
        {
            return this.head.data;
        }
        return -9999;
    }
    getLastValue(){
        if(!this.isEmpty())
        {
            var temp = this.head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            return temp.data;
        }
    }
    getLength(){
        if(!this.isEmpty()){
            var count=0;
            var temp=this.head;
            while(temp.next!=null){
                temp=temp.next;
                count++;
            }
            return count;
        }
        return 0;
    }
    print(){
        var temp=this.head;
        var val="";
        while(temp!=null){
            val += (temp.data + "->")
            temp=temp.next;
        }
        console.log(val+"null\n")
    }
    
};

l1 = new LinkedList();
l1.insertAtBeginning(10);
l1.insertAtLast(20);
l1.insertAtLast(30);
console.log("Head = " + l1.getFirstValue());
console.log("Last = " + l1.getLastValue());
l1.print();
console.log("length= "+ l1.getLength());
