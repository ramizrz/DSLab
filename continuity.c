#include<stdio.h>
#define max 30
char stack[max];
int top=-1;
void push(char x){
    stack[++top]=x;
}
void pop(){
    top--;
}
int main(){
    printf("Enter the Expression\n");
    char exp[30],*c;
    scanf("%s",exp);
    c=exp;
    while(*c!='\0'){
        if(*c=='(' || *c=='{' || *c=='['){
        push(*c);
        }
        else if(*c==')'){
            if(stack[top]=='(')
            pop();
            else{
            
            break;
            }
        }
        else if(*c=='}'){
            if(stack[top]=='{')
            pop();
            else{
            
            break;
            }
        }
        else if(*c==']'){
            if(stack[top]=='[')
            pop();
            else{
            
            break;
            }
        }
        c++;
    }
    if(top==-1)
    printf("expression is valid");
    else
    printf("Expression is invalid");
}

