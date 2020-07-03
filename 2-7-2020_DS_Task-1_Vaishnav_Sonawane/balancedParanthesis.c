#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define full 20
struct mystack
{
    char stk[full];
    int top;
} stack;

void push(char item)
{
    if (stack.top == (full - 1))
        printf ("Stack got full\n");
    else
    {
        stack.top = stack.top + 1;
        stack.stk[stack.top] = item;
    }
}

void pop()
{
    if (stack.top == - 1)
    {
        printf ("Stack is Empty\n");
    }
    else
    {
        stack.top = stack.top - 1;
    }
}

int main()
{
    char exp[full];
    int i = 0;
    stack.top = -1;
    printf("\nPlease enter bracket expression: ");
    gets(exp);
    for(i = 0; i < strlen(exp); i++)
    {
        if(exp[i] == '(' )
        {
            push(exp[i]);
            continue;
        }
        else if(exp[i] == ')' )
        {

            if(stack.stk[stack.top] == '(')
            {
                pop();
            }
            else
            {
                printf("\n the exopression is UNBALANCED \n");
                break;
            }
        }


        if(stack.top == -1)
        {
            printf("\nthe exopression is BALANCED  :)\n");
        }
        else
        {
            printf("\n the exopression is UNBALANCED !!\n");
            break;
        }
    }

    return 0;

}
