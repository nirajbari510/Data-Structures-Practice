#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

// Infix to postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;
    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(ch) ||
                  (precedence(stack[top]) == precedence(ch)
                   && ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Postfix to infix
void postfixToInfix(char postfix[], char infix[])
{
    char expstack[MAX][MAX];
    char a[MAX], b[MAX];
    int i;

    top = -1;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (isalnum((unsigned char)ch))
        {
            expstack[++top][0] = ch;
            expstack[top][1] = '\0';
        }
        else
        {
            strcpy(b, expstack[top--]);
            strcpy(a, expstack[top--]);

            sprintf(expstack[++top], "(%s%c%s)", a, ch, b);
        }
    }

    strcpy(infix, expstack[top]);
}

int main()
{
    char infix[MAX], postfix[MAX], result[MAX];
    int choice;

    printf("1. Infix to Postfix\n");
    printf("2. Postfix to Infix\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter infix expression: ");
        scanf("%99s", infix);

        infixToPostfix(infix, postfix);

        printf("Postfix expression: %s\n", postfix);
    }
    else if (choice == 2)
    {
        printf("Enter postfix expression: ");
        scanf("%99s", postfix);

        postfixToInfix(postfix, result);

        printf("Infix expression: %s\n", result);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}