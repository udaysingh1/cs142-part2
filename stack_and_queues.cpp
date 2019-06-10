#include <iostream>
using namespace std;

class node {
    public:
    int val;
    node * next; 
    // constructor
    node(int newval)
    {val = newval;
    next = NULL;}
};

class linkedlist{
    public:
    node * head;

    linkedlist(){
        head = NULL;
    }
    void insert(int newval){
        node * temp = new node(newval);
        temp->next = head;
        head = temp;
    }

    void display(){
        node * current = head;
        while(current != NULL){
            cout << current->val << "->";
            current = current-> next;
        }
        cout << "NULL" << endl;
    }
 
    

    int numberofItems(){
        // start at head
        node * current =  head;
        int count = 0;
        while (current != NULL){
            count++;
            current = current->next;
        }
        return count;
    }

    node * gettail(){
                     int cnt = 0;
                     node * current = head;
                     while(cnt != numberofItems()){
                                                   current = current->next;
                                                   cnt++;
                                                   }
                      return current;
               }


    node * getPos(int pos){
        int cnt = 0;
        node * current = head;
        while(cnt < (pos-1)){
            current = current->next; 
            cnt++;
        }
        return current;
    }
    

void delet(){ 
             node*temp = head;
             head = head-> next;
             delete temp;
             }
void deleteat(int pos){ 
                      node* current  = head;
                      node* temp = head;
                      if (pos>=1&&pos<=numberofItems())
                      { if ( pos == 1){ delet();}
                        else{ int c= 1;
                              while(c!= (pos-1)){
                                                 current = current -> next;
                                                 c++;
                                                 }
                                                 temp = current -> next ;
                                                 current -> next = (current -> next )-> next ;
                                                 delete temp;
                              }
                       } 
}  



};

class stack{
            public:
            node * top;
            linkedlist l1;
            stack(){
                    top = l1.head;
                    }

void push(int newval){
                      l1.insert(newval);
                      top = l1.head;
                     }

void pop(){
           
           if(top!=NULL){
                        l1.delet(); 
                        top = l1.head;
                  }
           else{
                cout << " no more elements to pop" << endl;
               }
           
          }

int count(){
           return l1.numberofItems();
           }

void display(){
               l1.display();
              }
};

class queue{
            public:
            linkedlist l1;
            node * front ;
            node * end;
            queue(){
                    front = l1.head;
                    end = l1.gettail();
                    }

   int count(){
           return l1.numberofItems();
           }

   void display(){
               l1.display();
              } 

   void enqueue(int newval){
                            l1.insert(newval);
                            front = l1.head;
                            }

   
   void dequeue(){
                  if(front != NULL){
                                    l1.deleteat(count());
                                    front = l1.head;
                                     end = l1.gettail();
                                    }
                   else{
                        cout<< " no more elements to dequeue" << endl;
                       }
                 }
};



int main(){
           stack s1;
           s1.push(0);
           s1.push(7);
           s1.push(9);
           s1.push(8);
           s1.push(3);
           cout << " number of items " << s1.count() << endl;
           s1.display();
           s1.pop();
           s1.display();
           s1.pop();
           s1.display();
           s1.pop();
           s1.display();
           s1.pop();
           s1.display();
           s1.pop();
           s1.display();
           s1.pop();
           s1.display();
           cout << " number of items " << s1.count() << endl;
           
           
           queue q1;
           q1.enqueue(0);
           q1.enqueue(7);
           q1.enqueue(9);
           q1.enqueue(8);
           q1.enqueue(3);
           q1.display();
           cout << " number of items " << q1.count() << endl;
           q1.dequeue();
           q1.display();
           q1.dequeue();
	   q1.display();
           q1.dequeue();
           q1.display();
           q1.dequeue();
           q1.display();
           q1.dequeue();
           q1.display();
           cout << " number of items " << q1.count() << endl;
                      
}
