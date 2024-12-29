// Included Libraries
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    // Variables are declared here for future reference
    string StringInput;
    stack<char> List;

    // The user is prompted to enter in a set of strings
    cout << "Please enter a string with parenthesis:" << endl;
    getline(cin, StringInput);

    // This loops through the user's input through the whole string
    for (int i = 0; i < StringInput.length(); i++)
    {

        // This portion checks to see if the string at i is (, {, or [,and then puts it in itemlist
        if (StringInput[i] == '(' || StringInput[i] == '[' || StringInput[i] == '{')
        {
            List.push(StringInput[i]);
        }

        // This is the case if the string at i is ), }, or ]
        if (StringInput[i] == ')' || StringInput[i] == ']' || StringInput[i] == '}')
        {

            // If the itemList is empty, then the code will automatically read it to be unbalanced, then ends the code
            if (List.empty())
            {
                cout << "The string is not balanced!" << endl;
                return 1;
            }

            // This puts the top of stack in itemList in char top
            char top = List.top();

            // This then removes the top of stack
            List.pop();

            // If the expressions do not correlate to any scenario it will end the code
            if ((top == '(' && StringInput[i] != ')') ||
                (top == '[' && StringInput[i] != ']') ||
                (top == '{' && StringInput[i] != '}'))
            {
                cout << "The string is not balanced!" << endl;
                return 1;
            }
        }
    }

    // If the itemList is found empty by the end of the string then it will output a balanced string message
    if (List.empty())
    {
        cout << "The string is balanced!" << endl;
        return 0;
    }
    // If the itemList is not found empty by the end of the string then it will output a unbalanaced string message
    else
    {
        cout << "The string is not balanced!" << endl;
        return 1;
    }
}
