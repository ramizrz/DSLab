
#include<stdio.h>
#include<ctype.h>
#define MAX 100

typedef struct stack
{
	char a[MAX];
	int top;
}stack;

void push(struct stack *ps,char n)
{
	if(ps->top!=MAX-1)
	{
		ps->top++;
		ps->a[ps->top]=n;
	}
	else
		printf("\nSTACK IS FULL");
}

char pop(struct stack *ps)
{
	return(ps->a[ps->top--]);
}
void isMatchingpair(char left,char right)
{
 switch(left)
 {
	 case '(':(right==')')?return 1:return	0;
	 break;
	 case '{':(right=='}')?return 1:return	0;
	 break;
	 case '[':(right==']')?return 1:return	0;
	 break;
	 default:return	0;
 }
}
void checkbalanced(char exp[])
{
	char c;
	char stack s;
	s.top=-1;
	int i;
	for(i=0<;i<top;i++)
	{
		while(exp[i]!='\0')
		{
			if(exp[i]=='('||'{'||'[')
			{
				push(&s,exp[i]);
			}
			else if(top==-1)
				{
					printf("invalid expression");
					return;
				}
				c=pop(&s);
				if(isMatchingpair(c,exp[i]))
				continue;
				else
				{
					printf("exp is inavlid");
		          return;
				}
		  }
	  }
  }

		
		
int main()
{
	char exp[30];
	printf("ENTER THE EXPRESSION\n");
	scanf("%s",exp);
	checkbalanced(exp);
	return 0;
}

