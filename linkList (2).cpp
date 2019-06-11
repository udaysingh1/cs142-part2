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
};

class queue
{
	public:
		linkList l1;
	
		void push(int val)
		{
			l1.insertAt(1,val);
		}
		
		int pop()
		{
			return l1.delAt(l1.count());
		}
		
		void display()
		{
			l1.display();
		}
}

;

int main()
{

	queue s1;
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
