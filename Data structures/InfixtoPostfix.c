#include <stdio.h>
#include <ctype.h>
void infixToPostfix(char infix[], char postfix[]); // this function takes to char arrays as input
void push(char c);
char pop();
char stack[100]; // this is our stack to temporarily store the operators
int top = -1;    // every stack has a top associated to it
int priority(char d);

void main()
{

    char infix[100];   // taking input of the infix expression
    char postfix[100]; // postfix will be stored in this array
    printf("\nEnter your infix expression:\n");
    scanf("%s", infix);
    infixToPostfix(infix, postfix); // passed both infix and postfix to the function which will convert my expression
    printf("postfix expression is :");
    puts(postfix); // could have also used printf("%s",postfix);
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    // top will always have the address of the topmost element of the stack
    else
    {
        char temp = stack[top];
        top = top - 1;
        return temp;
    }
}

void push(char c)
{
    top = top + 1;
    stack[top] = c;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char temp, x;
    // i is used for the indexing of infix and j is used for the indexing of postfix
    //  temp is used for holding every individual char of infix
    //  x is used to store the characters which are popped from the stack
    while (infix[i] != '\0')
    {
        temp = infix[i];
        if (temp == '(')
        {
            push(temp);
        }
        else if (temp == ')')
        {
            while ((x = pop()) != '(')
            {
                postfix[j++] = x;
            }
        }
        // is it is a num or an alphabet then it will directly be pushed into the postfix expression
        else if (isalnum(temp))
        {
            postfix[j++] = temp;
        }
        // else statement is going to deal with the operators
        else
        {
            while (priority(stack[top]) >= priority(temp))
            {
                postfix[j++] = pop();
            }
            push(temp);
        }
        i++;
    }
    while (top != -1)
    {
        x = pop();
        postfix[j++] = x;
    }
}
int priority(char d)
{
    if (d == '*' || d == '/')
    {
        return 2;
    }
    else if (d == '(' || d == ')')
    {
        return 0;
    }
    else
    {
        return 1; // in case of + , - return 1
    }
}