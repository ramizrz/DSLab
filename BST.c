#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

void traverse_inorder(node *r)
{
	if(r!=NULL)
	{
		traverse_inorder(r->left);
		printf("%d\t",r->data);
		traverse_inorder(r->right);
	}
}

void insert(node **r,int num)
{
	node *temp,*ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->right=ptr->left=NULL;
	temp=*r;
	if(temp==NULL)
		*r=ptr;
	else
	{
		if(num> temp->data)
		{
			if(temp->right!=NULL)
				insert(&temp->right,num);
			else
					temp->right=ptr;
		}
		else
			{
				if(temp->left!=NULL)
					insert(&temp->left,num);
				else
					temp->left=ptr;
			}
	}
}

void search_node(node **x,node *root,node **parent,int num,int *f)
{
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			*f=1;
			*x=temp;
			return;
		}
		*parent=temp;
		if(num > temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
}

int search_bst(node *root,int num)
{
	node *temp;
	temp=root;
	if(temp==NULL)
		return 0;
	while(temp!=NULL)
	{
		if(temp->data==num)
			return 1;
		if(num > temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
	return 0;
}
	
void delete(node **r,int num)
{
	node *temp, *parent,*x,*xsucc;
	int f=0;
	parent=NULL,x=NULL,xsucc=NULL;
	temp=*r;
	search_node(&x,temp,&parent,num,&f);
	if(f==0)
	{
		printf("\n The Node Is Not Found");
		return;
	}
	if(x->left==NULL && x->right==NULL)
	{
		if(x->data>parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	else if(x->left!=NULL && x->right==NULL)
	{
			if(x->data>parent->data)
				parent->right=x->left;
			else
				parent->left=x->left;
	}
		
	else if(x->right!=NULL && x->left==NULL)
	{
		if(x->data>parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
	}
		
	else if(x->right!=NULL && x->left==NULL)
	{
		xsucc=x->right;
		parent=x;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		x->data=xsucc->data;
		x=xsucc;
		if(x->data > parent->data)
			parent->right=NULL;
			else
				parent->left=NULL;
			
		}
		free(x);
}
int main()
{
	node *root=NULL;
	int j,no;
	do{
		printf("\nENTER YOUR CHOICE\n");
		printf("\n1-INSERTION\n2-DELETION\n3-TRAVERSE\n4-Searchuig\n Exit\n\n");
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				printf("\nENTER THE NUMBER TO BE INSERTED: ");
				scanf("%d",&no);
				insert(&root,no);
				break;
			case 2:
				printf("\nENTER THE NUMBER TO BE DELETED: ");
				scanf("%d",&no);
				delete(&root,no);
				break;
			case 3:traverse_inorder(root);
				break;
			case 4:
				printf("Enter data to be insert");
				scanf("%d",&no);
				search_bst(root,no);
				break;
			
			case 5:
				exit(0);
			default:
				printf("\nInvalid Input.");
				break;		
			}
		}while(1);	
	return 0;
}
