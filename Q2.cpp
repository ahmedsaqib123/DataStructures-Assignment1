#include<iostream>
#include<algorithm> //lib used to reverse the string inorder to save time. 
using namespace std; 

class Stack{
	int top; 
	int arr[5];
	
	public: 
	
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
	
	char pop()
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
	
	char top1()
	{
		return arr[top];
	}
	
	bool check_operator(char x)
	{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
	return true;
	
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
		return -1;
	}

	string infix_prefix(string infix)
	{
		Stack s; 
		string prefix,postfix;
		reverse(infix.begin(),infix.end()); // the entered string is reversed! 
		
		for(int i=0;i<infix.length();i++)
		{
			if(infix.at(i)=='(')			// this line of code converts 
			{								// '(' to ')' and ')' to  '('
				infix.at(i)=')';
			}
			else if(infix.at(i)==')')
			{
				infix.at(i)='(';
			}
		}
		
		for(int i=0;i<infix.length();i++)
		{
			if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i]<= 'Z'))  //condition to check if num or alphabet..
			{
				prefix += infix.at(i);			// if an operand then just display..
			}
			
			else if (infix.at(i) == '(')     //openeing brackets to be pushed on stack..
			{
				s.push(infix[i]);
			}
			
			else if (infix.at(i) == ')')					
			{
				while ((s.top1() != '(') && (!s.isEmpty()))
				{
					prefix+=s.top1();
					s.pop();
				}
				if(s.top1()=='(')
				{
					s.pop();
				}
			}
			
			else if(check_operator(infix.at(i)))
			{
				if(s.isEmpty())
				{
					s.push(infix.at(i));
				}	
				else
				{
					if(priority(infix[i])>priority(s.top1()))
					{
						s.push(infix.at(i));
					}
					else if ((priority(infix[i]) == priority(s.top1())))
					{
                    while ((priority(infix[i]) == priority(s.top1())))
					{
                        prefix += s.top1();
                        s.pop();
                    }
                    s.push(infix[i]);
            		}
            		
            		else if (priority(infix[i]) == priority(s.top1()))  //if the priority is equal then we push..
					{
                    s.push(infix[i]);
                	}
                	else 
					{
                    while ((!s.isEmpty()) && (priority(infix[i]) < priority(s.top1()))) 
					{
                        prefix += s.top1();
                        s.pop();
                    }
                    s.push(infix[i]);
                	}
				}
			}
		}	
		while (!s.isEmpty()) 
		{
        prefix += s.top1();
        s.pop();
    }
 
    reverse(prefix.begin(), prefix.end()); // the prefix value is again reversed for the proper answer..
    return prefix;
				
	}
	
};

int main()
{
	Stack s;
	string infix,prefix;
	cout<<"Enter Infix Expression: "<<endl; 
	cin>>infix;
	prefix= s.infix_prefix(infix);
	cout<<endl; 
	cout<<"Prefix Expression: "<<endl; 
	cout<<prefix<<endl; 
}
