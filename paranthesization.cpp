// program to check paranthesization
#include<iostream>
#include<string>
using namespace std;
class stack
{
	private:
		int top;
		char para[100];
	public:
		stack()
		{
			top=-1;
		}
		int isempty();
		int isfull();
		void push(int);
		int pop();
};
int stack::isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int stack::isfull()
{
	if(top==99)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void stack::push(int x)
{
	if(isfull())
	{
		cout<<"\nStack overflow";
	}
	else
	{
		para[++top]=x;
	}
}
int stack::pop()
{
	if(isempty())
	{
		cout<<"\nStack underflow";
	}
	else 
	{
		return para[top--];
	}
}
int main()
{
	char exp[100];
	int A=0;
	cout<<"\nEnter an expression";
	cin.getline(exp,100);
	stack S;
	int i=0;
	while(exp[i]!='\0')
	{	
		
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[' )
		{
			S.push(exp[i]);
		
		}
		else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']')
		{
			if(S.isempty())
			{
				A=1;
			}
			else
			{
				char b=S.pop();
				if((exp[i]==')' && b !='(') || (exp[i]=='{' && b!='}') || (exp[i]=='[' && b!=']') )
					A=1;
			}
		}
		i++;
	}
	if(A==1)
	{
		cout<<"\n Incorrect paranthesization";
	}
	else
	{
		if(S.isempty())
		{
			cout<<"\n Correct paranthesization";
		}
		else
		{
			cout<<"\n Incorrect paranthesization";
		}
	}
	return 0;
}

		
