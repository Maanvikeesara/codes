#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int stack[1000];
int top=-1;
void push(int n)
{
    top++;
    stack[top]=n;
    
}
int pop()
{
    int x=stack[top];
    top--;
    return x;
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char postfix[100];
    int values[1000];
    scanf("%s",postfix);
    int i=0,c=0;
    while(postfix[i])
    {
        if(postfix[i]>=65&&postfix[i]<=90)
        {
            c++;
        }
        i++;
    }
    for(i=0;i<c;i++){
        scanf("%d",&values[i]);
        }
    i=0;
    int j=0;
    while(postfix[i])
    {
        if(postfix[i]>=65&&postfix[i]<=90)
        {
            push(values[j]);
            j++;
        }
        else{
            int x,y;
            x=pop();
            y=pop();
            if(postfix[i]=='+')
            {
                
                int r=y+x;
                push(r);
            }
            else if(postfix[i]=='-'){
                int r=y-x;
                push(r);
            }
             else if(postfix[i]=='*'){
                int r=y*x;
                push(r);
            }
            else {
                int r=y/x;
                push(r);
            }
        }
        i++;
    }
    printf("%d",stack[top]);
    
    return 0;
}
