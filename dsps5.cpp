#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char stack[30];
int top = -1, len;

void push(char ele)
 {
    if (top == len - 1)
     {
        cout << "stack is overflow\n";
    }
     else
      {
        top++;
        stack[top] = ele;
    }
}

char pop()
 {
    if (top == -1)
     {
        cout << "stack is underflow\n";
        return '\0';
    }
     else
      {
        char ele = stack[top];
        top--;
        return ele;
    }
}

int palindrome(char str[]) 
{
    // Initialize the stack
    top = -1;

    // Push all characters of the string onto the stack (excluding spaces)
    for (int i = 0; i < len; i++)
     {
        if (str[i] != ' ')
         {
            push(tolower(str[i]));
        }
    }

    // Check if the characters match by popping from the stack
    for (int i = 0; i < len; i++) 
    {
        if (str[i] != ' ') 
        {
            char ch = tolower(str[i]);
            char stackChar = pop();
            if (ch != stackChar)
             {
                return 0;
            }
        }
    }

    return 1;
}

int main() 
{
    char m[30];
    cout << "Enter string to check: ";
    cin.getline(m, 30);
    len = strlen(m);

    if (palindrome(m)) 
    {
        cout << "String is a palindrome\n";
    }
     else
      {
        cout << "String is not a palindrome\n";
    }

    return 0;
}
