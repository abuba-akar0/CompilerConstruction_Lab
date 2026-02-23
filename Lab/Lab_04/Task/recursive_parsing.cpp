#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char input[100];
int position = 0;
int length;
char token;

char advance()
{
    return input[position++];
}

void match(char expected)
{
    if(token == expected)
        token = advance();
    else
    {
        printf("\nRejected\n");
        exit(0);
    }
}

void E();
void Eprime();
void T();
void Tprime();
void F();

void E()
{
    printf("E -> T E'\n");
    T();
    Eprime();
}

void Eprime()
{
    if(token == '+')
    {
        printf("E' -> + T E'\n");
        match('+');
        T();
        Eprime();
    }
    else if(token == '-')
    {
        printf("E' -> - T E'\n");
        match('-');
        T();
        Eprime();
    }
    else
    {
        printf("E' -> null\n");
    }
}

void T()
{
    printf("T -> F T'\n");
    F();
    Tprime();
}

void Tprime()
{
    if(token == '*')
    {
        printf("T' -> * F T'\n");
        match('*');
        F();
        Tprime();
    }
    else if(token == '/')
    {
        printf("T' -> / F T'\n");
        match('/');
        F();
        Tprime();
    }
    else
    {
        printf("T' -> null\n");
    }
}

void F()
{
    if(isalpha(token))
    {
        printf("F -> id (%c)\n", token);
        token = advance();
    }
    else if(isdigit(token))
    {
        printf("F -> num (%c)\n", token);
        token = advance();
    }
    else if(token == '(')
    {
        printf("F -> (E)\n");
        match('(');
        E();
        match(')');
    }
    else
    {
        printf("\nRejected\n");
        exit(0);
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%s", input);

    length = strlen(input);
    input[length] = '$';

    token = advance();

    E();

    if(position == length + 1 && input[position - 1] == '$')
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}