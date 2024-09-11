#include <iostream>
#include <stack>  // Use the STL stack for simplicity
#include <cctype> // For isalpha function
#include <cstring> // For strlen function

using namespace std;

// Function to determine the precedence of operators
int precedence(char c) 
{
    if (c == '+' || c == '-')
     {
        return 1;
    }
     else if (c == '*' || c == '/')
      {
        return 2;
    }
     else if (c == '^') 
     {
        return 3;
    }
     else
      {
        return -1;
    }
}

// Function to convert infix expression to postfix expression
void infix_to_postfix(const char infix[])
 {
    stack<char> s; // Stack to hold operators
    int len = strlen(infix);
    cout << "The postfix expression is: ";
    
    for (int i = 0; i < len; ++i) 
    {
        char c = infix[i];
        
        if (isalnum(c)) 
        { // If the character is an operand (a-z, A-Z, or digits)
            cout << c;
        }
         else if (c == '(')
          {
            s.push(c);
        } 
        else if (c == ')')
         {
            while (!s.empty() && s.top() != '(') 
             {
                cout << s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') 
            {
                s.pop(); // Remove the '(' from the stack
            }
        } 
        else
         { // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(c))
             {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all the remaining operators in the stack
    while (!s.empty())
     {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() 
{
    char infix[30]; // Array to store the infix expression
    cout << "Enter the infix expression: ";
    cin >> infix; // Read the infix expression from the user
    
    infix_to_postfix(infix); // Convert infix to postfix
    
    return 0;
}

