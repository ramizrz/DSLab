#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1

int isFull()
{
return (top==MAX_SIZE?1:-1);
}

int isEmpty()
{
	return (top!=MAX_SIZE?1:-1);
}
int peek()
{
	int a
	return (a=stack[MAX_SIZE-1);
void push(int e)
{
	if(!isFull())
	{
		top++;
		stack[MAX_SIZE]=e;
		printf("element is succesfully inserted");
	}
	else{
		printf("Stack is overload");
	}
}
void peek(int d)
{
	if(!iseEmpty())
	{
		d=top;
		top--;
		printf("element is deleted");
	}
	else
	printf("stack is underflow");
}

int main()
{
	int choice,e,d;
	do
	{
		printf("Enter your choice\n 1.)peek\n2.)push3.)pop\n4.)exit");
		sacnf("%d,&choice);
		
