#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int value);              // the push function is going to take a float array and a float value as inputs
int pop();                         // this function is going to take a float array as an input and return a float value
int evaluatePrefixExp(char exp[]); // this is a function which is going to take a char array as input and return a float

int main()
{
    char exp[100]; // characater array to take my postfix expression ka input
    printf("\n Enter any prefix exprssion : ");
    gets(exp);
    int val = evaluatePrefixExp(exp); // val is going to store the final answer after evaluating the postfix expression
    printf("\n the value of the prefix expression = %d ", val);
    return 0;
}
// inside the exp array when we put a number then it will be stored as 1 ka ascii + 0

int evaluatePrefixExp(char exp[])
{
    int n = strlen(exp); // n contains the total length of the character array (prefix exp)
    int i;               // i is used for indexing of the char array
    int op1, op2, value;
    for (i = n - 1; i >= 0; i--) // all character arrays are null terminated
    {
        // if is used for handling operands(1,2,3.....)
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        // else is for handling operators
        else
        {
            op2 = pop(); // topmost element will get popped
            op1 = pop(); // topmost element will get popped
            switch (exp[i])
            {
            case '+':
                value = op2 + op1;
                break;

            case '-':
                value = op1 - op2;
                break;

            case '*':
                value = op1 * op2;
                break;

            case '/':
                value = op1 / op2;
                break;

            case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(value);
        }
    }
    return (pop());
}

void push(int value)
{
    top = top + 1;
    stack[top] = value;
}

int pop()
{
    int val;
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        val = stack[top];
        top--;
    }
    return val; // this value will be returned to op1 and op2
}