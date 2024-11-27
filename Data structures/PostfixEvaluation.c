#include <stdio.h>
#include <ctype.h>

int stack[100]; // operands in case of postfix evaluation is going to be an integer
int top = -1;

void push(int stack[], int value);  // the push function is going to take a float array and a float value as inputs
int pop(int stack[]);               // this function is going to take a float array as an input and return a float value
int evaluatePostfixExp(char exp[]); // this is a function which is going to take a char array as input and return a float

int main()
{
    char exp[100]; // characater array to take my postfix expression ka input
    printf("\n Enter any postfix exprssion : ");
    gets(exp);
    int val = evaluatePostfixExp(exp); // val is going to store the final answer after evaluating the postfix expression
    printf("\n the value of the postfix expression = %d ", val);
    return 0;
}
// inside the exp array when we put a number then it will be stored as 1 ka ascii + 0

int evaluatePostfixExp(char exp[])
{
    int i = 0; // i is used for indexing of the char array
    int op1, op2, value;
    while (exp[i] != '\0') // all character arrays are null terminated
    {
        // if is used for handling operands(1,2,3.....)
        if (isdigit(exp[i]))
        {
            push(stack, exp[i] - '0');
        }
        // else is for handling operators
        else
        {
            op2 = pop(stack); // topmost element will get popped
            op1 = pop(stack); // topmost element will get popped
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
            push(stack, value);
        }
        i++;
    }
    return (pop(stack));
}

void push(int stack[], int value)
{
    top = top + 1;
    stack[top] = value;
}

int pop(int stack[])
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