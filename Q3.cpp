#include<iostream>
#include <sstream> 
using namespace std;

class Stack {

public:
	int top;
	char arr[20];

	Stack()
	{
		top = -1;
		for (int i=0; i<20; i++)
		{
			arr[i]=0;
		}
	}

	bool isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if (top == 20)
			return true;
		else
			return false;
	}

	void push(int num)
	{
		if (isFull())
		{
			cout << "Stack Overflow! " << endl;
		}
		else
		{
			top++; //0 
			arr[top] = num;
		}
	}

	char pop()
	{
		if (isEmpty())
		{
			cout << "Stack Underflow! " << endl;
			return 0;
		}
		else
		{
			char temp = arr[top];
			arr[top] = 0;
			top--;
			return temp;
		}
	}
	
	char top1() 
	{
		return arr[top];
	}
	


bool check_operator(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
	return true;
					// if operator matches return true else return false
	else
	return false;
}

int priority(char x)
{
	if (x == '^')
		return 3;
	else if (x == '*' || x == '/')
		return 2;
	else if (x == '+' || x == '-')
		return 1;
	else
		return -1;    //brackets donot play a role in priority list..
}

string infix_postfix(string infix)
{
	Stack s;
	string postfix;
	
	for(int i=0; i<infix.length(); i++)
	{
		if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i]<= 'Z'))
		{
			postfix += infix.at(i);  //adds the operand 
		}
		else if (infix.at(i) == '(') //bracket open we push values on the stack 
		{
			char temp = infix.at(i);
			s.push(temp);
		}
		else if (infix.at(i) == ')') //bracket close we pop out the values from the stack
		{
			while ((s.top1() != '(') && (!s.isEmpty()))
			{
				char temp = s.top1();
				s.pop();
				postfix += temp;
			}
			if (s.top1() == '(')
			{
				char temp = s.top1();
				s.pop();
			}
		}
		else if (check_operator(infix.at(i)))
		{
			while (!s.isEmpty() && priority(infix.at(i)) <= priority(s.top1()))
			{
				char temp = s.top1();
				s.pop();
				postfix += temp;
			}
			s.push(infix.at(i));
		}
	}
	while (!s.isEmpty())
	{
		char temp = s.top1();
		s.pop();
		postfix += temp;
	}
	return postfix;
}
	/*void sum(string postfix)
	{
		
	}*/

};

int main()
{
	Stack s,s1;
	string infix,postfix;
	cout<<"Enter an Infix Expression: "<<endl; 
	cin>>infix; 
	postfix=s.infix_postfix(infix);
	cout<<endl;
	cout<<"Postfix Expression: "<<endl;
	cout<<postfix<<endl;
	//s1.sum(postfix);
}
