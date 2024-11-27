#include <stdio.h>
#include <ctype.h>
#include <string.h>

void infixToPostfix(char infix[], char postfix[]);
void reverse(char rev[]);
char stack[100];
int top = -1;

void push(char c);
char pop();
int priority(char d);

void main()
{

    char infix[100];
    printf("Enter your infix expression: ");
    gets(infix);

    reverse(infix); // reverse of infix will happen in infix itself

    char postfix[100]; // reverse infix ka postfix will be stored here

    infixToPostfix(infix, postfix);

    reverse(postfix); // reverse of postfix in postfix itself
    printf("Prefix expression is :");
    puts(postfix);
}

void reverse(char rev[])
{
    int i = 0, j, n;
    char temp; // used for reversing
    n = strlen(rev);

    while (rev[i] != '\0')
    {
        if (rev[i] == '(')
        {
            rev[i] = ')';
        }
        else if (rev[i] == ')')
        {
            rev[i] = '(';
        }
        i++;
    }
    // the while loop will reverse the brackets of the array which is passed to it .
    for (i = 0, j = n - 1; i <= j; i++, j--)
    {
        temp = rev[i];
        rev[i] = rev[j];
        rev[j] = temp;
    }
    // this loop will reverse the array in itself
}

void push(char c)
{
    top = top + 1;
    stack[top] = c;
}

char pop()
{
    char x;
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        x = stack[top];
        top = top - 1;
        return x;
    }
}
void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char temp, x;
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

        else if (isalnum(temp))
        {
            postfix[j++] = temp;
        }

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
        return 1;
    }
}