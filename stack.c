#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE],rear=-1,front=-1;

int isFull()
{
	
	if((rear==MAX_SIZE-1&&front==0)||rear+1==front)
	return 1;
	return 0;
	
}

int isEmpty()
{
	if(rear==-1&&front==-1)
	return 1;
	return 0;
	
}

void display()
{
	int i=front;
	while(i!=rear)
	{
		
		printf("%d\n",queue[i]);
	i=(i+1)%MAX_SIZE;
	}
	printf("%d",queue[i]);
}

void insert(int d)
{
	if(!isFull())
	{
		if(!isEmpty())
		{
			front++;
		}
		rear=(rear+1)%MAX_SIZE;
		queue[rear]=d;
		printf("Element inserted succesfully");
	}
	else
	{
		printf("Element not inserted");
	}
}

void delete()
{
	int d;
	if(!isEmpty())
	{
		d=queue[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%MAX_SIZE;
		}
		printf("Element deleted sucessfully 	%d",d);
	}
	else
	{
		printf("the queue is empty");
	}
}



int main()
{
	int choice,e;
	do
	{
		printf("\nEnter\n1.Display\n2.Insert\n3.Delete\n4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);	//take input in choice variable
		switch(choice)
		{
			case 1:
				if(!isEmpty())
					display();//display
				else
					printf("Queue is Empty");
				break;
			case 2:
				printf("\nEnter the elment to be inserted: ");
				scanf("%d",&e);
				insert(e);
				break;
			case 3:
				delete();
				break;
			case 4:
				exit(0);//call exit(0) function or return 0
				break;
			default:
				printf("\nInvalid Choice");//invalid choice
				break;				
		}
	}while(1);
	return 0;
}
