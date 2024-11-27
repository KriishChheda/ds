#include <stdio.h>
#include <string.h>
void reverse(char rev[]);
void main()
{
    char infix[100];
    printf("Enter your infix expression");
    gets(infix);
    reverse(infix);
    printf("Reversed infix expression is: ");
    puts(infix);
}

void reverse(char rev[])
{
    int i = 0, j, n;
    char temp;
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

// Method 2 to reverse the string & brackets

// #include <stdio.h>
// #include<string.h>
// void reverse(char rev[]);
// void main()
// {
//     char infix[100];
//     printf("Enter your infix expression");
//     gets(infix);
//     reverse(infix);
//     printf("Reversed infix expression is: ");
//     puts(infix);
// }

// void reverse(char rev[])
// {
//     int i = 0, j , n;
//     char temp;
//     n = strlen(rev);

//     for (i = 0, j = n - 1; i < j; i++, j--)
//     {
//         if (rev[i] == '(')
//         {
//             rev[i] = ')';
//         }

//        else if (rev[i] == ')')
//         {
//             rev[i] = '(';
//         }

//         if (rev[j] == ')')
//         {
//             rev[j] = '(';
//         }

//        else if( rev[j] == '(')
//         {
//             rev[j]=')';
//         }

//         temp = rev[i];
//         rev[i] = rev[j];
//         rev[j] = temp;

//     }
// }