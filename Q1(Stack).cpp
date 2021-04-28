#include<iostream>
using namespace std; 

class Stack{
	int top; 
	int arr[10];
	
	public: 
	
	Stack()
	{ 
		top= -1;
		for(int i=0;i<10;i++)
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
		if(top== 10)
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
	
	int count()
	{
		return(top+1);
	}
	
	int peek(int pos)
	{
		if(isEmpty())
		{
			cout<<"Stack Underflow! "<<endl;
		}
		else 
		{
			return arr[pos];
		}	
	}
	
	void change(int pos,int num)
	{
		arr[pos]=num;
		cout<<"Value at position= "<<pos<<"changed to "<<num<<endl;    
	}
	
	void display()
	{
		cout<<"Stack Values: "<<endl;
		for(int i=4;i>=0;i--)
		{
			cout<<arr[i]<<endl;
		}
	}	
	
	void reverse( Stack s1)
	{
		int temp;
		while(s1.top>=0)
		{
			temp=s1.pop();
			push(temp);
		}
	}

		
};

int main()
{
	Stack s1,s2,s3;
	int num;
	cout<<"Enter 5 Value In The Stack : "<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>num;
		s1.push(num);
	}	
	s1.display();
	
	cout<<"Reversing in 1st Alternative Stack "<<endl;
	s2.reverse(s1);
	s2.display();
	
	cout<<"Reversing in 1st Alternative Stack "<<endl;
	s3.reverse(s2);
	s3.display();	
	
}
