#include<iostream>
using namespace std; 
class Stack{
	
	public: 
	int top; 
	int arr[5];

	Stack()
	{ 
		top= -1;
		for(int i=0;i<5;i++)
		{
		arr[i]=0;
		}
	}
	
	bool isEmpty()
	{
		if(top== -1)
		return true; 
		else 
		return false;
	}
	
	bool isFull()
	{
		if(top== 4)
		return true;
		else 
		return false;
	}
	
	void push(int num)
	{
		if(isFull())
		{
			cout<<"Stack Overflow! "<<endl;
		}
		else 
		{
			top++; //0 
			arr[top]=num;
		}
	}
	
	int pop()
	{
		if(isEmpty())
		{
			cout<<"Stack Underflow! "<<endl;
		}
		else
		{
			int temp= arr[top];
			arr[top]=0;
			top--;
			return temp;
		}	
	}
	
};

class Queue{
	
	int front;
	int rear; 
	int arr[5];
	
	public: 
	
	Queue()
	{
		front=-1; rear=-1; 
		for(int i=0;i<5;i++)
		{
			arr[i]=0;
		}	
	}
	
	bool isEmpty()
	{
		if(front==-1 && rear==-1)
		return true;
		else 
		return false;
	}
	
	bool isFull()
	{
		if(rear==sizeof(arr)-1)
		return true; 
		else 
		return false;	
	}
	
	void enqueue(int num)
	{
		if(isFull())
		{
			cout<<"Queue is full! "<<endl;
			return;
		}
		else if (isEmpty())
		{
			rear=0;
			front=0;
			arr[rear]=num;
		}
		else 
		{
			rear++;
			arr[rear]=num;
		}
	}
	
	int dequeue()
	{
		int temp;
		if(isEmpty())
		{
			cout<<"Queue is Empty! "<<endl;
			return 0;
		}
		else if(front==rear)
		{
			temp=arr[front];
			arr[front]=0; 
			rear=-1;
			front=-1;
			return temp;
		}
		else
		{
			temp=arr[front];
			arr[front]=0; 
			front++;
			return temp;
		}
	}
	
	int count()
	{
		return(rear-front+1);
	}
	
	void display()
	{
		cout<<"Values in Queue: "<<endl;
		for(int i=0;i<5;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}	
	
	int reverse(Queue q,Stack s)
	{
		int temp=0;
		while(!q.isEmpty())
		{
			temp=q.dequeue(); //temp contains the dequeued value of queue
			s.push(temp);	 //values are pushed onto the stack 
		}
		
		temp=0;
		while(!s.isEmpty())
		{
			temp=s.pop(); //temp holds the reversed values that are poped from stack
			enqueue(temp); //values are enqueued into the queue
		}
		cout<<endl;
	//	cout<<"After Reversing"<<endl;
	//	q.display();
	}	
	
};

		
int main()
{
	Queue q,q1,q2; 
	Stack s;
	int num;
	cout<<"Enter Values in Queue: "<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>num;
		q.enqueue(num);
	}
	cout<<endl;
	q.display();
	cout<<endl;
	
	cout<<"After Reversing";
	q1.reverse(q,s);
	q1.display();
}
