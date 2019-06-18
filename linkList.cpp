#include<iostream>


using namespace std;


class node
{
	public:
	int value;
	node* next;
	
	node(int value)
	{
		this->value=value;
		next=NULL;
	}
};



class linkList
{
	public:
		node* head;

		linkList()
		{
			head=NULL;
		}

		void insert(int val)
		{
			node* test= new node(val);
			test->next=head;
			head=test;
		}

		void display()
		{
			node* curr=head;
			while(curr!=NULL)
			{
				cout<<curr->value<<"->";
				curr=curr->next;
			}
			cout<<endl;
		}

		int del()
		{
			int val;
			if(head==NULL)
			{
				cout<<"under flow";
				return 0;
			}
			else
			{
				node* temp=head;
				head=head->next;
				val=temp->value;

				delete temp;

				return val;
			}
		}

		int count()
		{
			node* curr=head;
			int C=0;
			while(curr!=NULL)
			{
				curr=curr->next;
				C++;
			}
			return C;
		}
			

		void insertAt(int pos,int val)
		{
			
			if(pos>(this->count()+1))
			{
				cout<<"this position is not valide";
			}
			else
			{
				if(pos==1)
				{
					this->insert(val);
				}
				else
				{
					node*temp = new node(val);
					node*curr = head;
					for(int i=0;i<pos-2;i++)
					{
						curr=curr->next;
					}
					temp->next=curr->next;
					curr->next=temp;
				}
				
			}
		}
		int delAt(int pos)
		{
			int val=0;
			if(pos>this->count())
			{
				cout<<"this position is not valide";
			}
			else
			{
				if(pos==1)
				{
					return	del();
				}
				else
				{
					node*curr = head;
					for(int i=0;i<pos-2;i++)
					{
						curr=curr->next;
					}
					node* temp=curr->next;
					curr->next=curr->next->next;
					val= temp->value;
					delete temp;
				}
				
			}
			return val;
		}
				
};



class stack
{
	public:
		linkList l1;

		void push(int val)
		{
			l1.insertAt(1,val);
		}
		
		int pop()
		{
			return l1.delAt(1);
		}
		
		void display()
		{
			l1.display();
		}
		int count()
		{
			return l1.count();
		}
};

class queue
{
	public:
		linkList l1;
	
		void equeue(int val)
		{
			l1.insertAt(1,val);
		}
		
		int dequeue()
		{
			return l1.delAt(l1.count());
		}
		
		void display()
		{
			l1.display();
		}
		
		int count()
		{
			return l1.count();
		}
};

class queue_using_stack
{
	public:
		stack s1;
		
		void equeue(int val)
		{
			s1.push(val);
		}
		
		int dequeue()
		{
			stack s2;
			while(s1.count()>1)
			{
				s2.push(s1.pop());
			}

			int temp = s1.pop();
			
			while(s2.count()>0)
			{
				s1.push(s2.pop());
			}
			
			return temp;
		}
		
		void display()
		{
			s1.display();
		}
};



class stack_using_queue
{
	public:
		queue q1;

		void push(int val)
		{
			q1.equeue(val);
		}
		
		int pop()
		{
			queue q2;
			while(q1.count()>1)
			{
				q2.equeue(q1.dequeue());
			}

			int temp = q1.dequeue();
			
			while(q2.count()>0)
			{
				q1.equeue(q2.dequeue());
			}
			
			return temp;
		}
		
		void display()
		{
			q1.display();
		}
		int count()
		{
			return q1.count();
		}
};






int main()
{

	cout<<endl;

	stack_using_queue s1;
	s1.display();
	s1.push(5);
	s1.display();
	for(int i=1;i<11;i++)
	s1.push(i);
	s1.display();
	cout<<s1.pop()<<endl;
	s1.display();
	
	
	
	return 0 ;

}
