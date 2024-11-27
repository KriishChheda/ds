#include <stdio.h>
#include <ctype.h>

int stack[100]; // operand in case of evaluations are going to be numbers thats why integer array
int top = -1;

void push(int value);
int pop();

// this function is going to take a char array as an input and return a int value
int evaluatePostfixExp(char exp[]); // this is a function which is going to take a char array as input and return a float

int main()
{
    char exp[100]; // characater array to take input of postfix expression
    printf("\n Enter any postfix exprssion : ");
    gets(exp);

    int val = evaluatePostfixExp(exp); // val is going to store the final answer after evaluating the postfix expression
    printf("\n the value of the postfix expression = %d ", val);
    return 0;
}
// inside the exp array when we put a number then it will be stored as 1 ka ascii + 0

// postfix expression is passed to exp
// a char array is always null terminated
int evaluatePostfixExp(char exp[])
{
    int i = 0; // i is used for indexing of the char array
    int op1, op2, value;
    while (exp[i] != '\0') // all character arrays are null terminated
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
                value = op1 % op2;
                break;
            }
            push(value);
        }
        i++;
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

// postfix expression is ready with me . ill directlt take the input of the postfix only
// while evaluating a postfix expression we always go left to right
// initially my stack is empty
// a number in a character array will be stored in its ascii form