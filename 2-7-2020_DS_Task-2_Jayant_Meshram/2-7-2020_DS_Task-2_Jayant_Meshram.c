#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int push(char element, char *stack, int top)
{   
    if(top<99)
    {
        top = top + 1;
        stack[top] = element;
        return top;    
    }
}
int pop(int top)
{   
    top = top - 1;
    return top;
}
int main()
{
    int top=-1,i=0;
    const int MAX=100;
    char brackets[MAX];
    char stack[MAX];
    printf("Enter the brackets: ");
    scanf("%s",brackets);
    int limit=strlen(brackets);
    if(limit<=MAX)
    {
        while(brackets[i]!=0)
        {   
            if(brackets[i]=='(')
            {
                top=push(brackets[i],stack,top);
            }
            else if(brackets[i]==')')
            {
                top=pop(top);
            }
            i++;
        }
    }
    else
    {
        printf("Limit Exceeded!!!!!");
        exit(0);
    }
    if(top==-1)
    {   
        printf("Balanced");
    }
    else
    {
        printf("Unbalanced");
    }
}