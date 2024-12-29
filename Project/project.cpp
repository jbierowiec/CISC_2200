#include<iostream>
#include<stack>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stdexcept>

using namespace std;
using std::runtime_error; 

// With the addition of the runtime error class, whenever the throw operator references this class to check for any errors for input. In the case an error occurs
// this message appears for them 
class SError: public runtime_error
{ 
    public: 
        SError(): runtime_error("ERROR: Expression is not correct! Please try again") {}

}; 

// function definitions
bool isOperator(char c);
int precedence(char op);
string infixToPostfix(string expression);
double evaluatePostfix(string postfix);

// operator function to check the operator used in the user input, if
// none or something outside the operators are detected returns false
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}

// This functions creates a priority for operators to show which one 
// should come first in a the outputted postfix sequence notation
int precedence(char op)
{
    if(op == '+' || op == '-') {
        return 1;
    }
    else if(op == '*' || op == '/') {
        return 2;
    }
    else if(op == '^') {
        return 3;
    }
    else {
       return 0; 
    }
}

// This function takes an infix expression as input and converts it to postfix notation using a stack
// and returns the postfix expression as a string. 
// The function also throws error messages if the input is not in the correct format.
string infixToPostfix(string expression)
{
    stack<char> s;
    string postfix = "";
    bool last_was_operator = true; // initialize to true to catch expressions that start with an operator

    for(int i = 0; i < expression.length(); i++)
    {
        if(isdigit(expression[i]))
        {
            // This is the case for a number comntaining a negative sign indicating a negative number, 
            // or a number with a decimal point
            stringstream ss;
            while(i < expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
            {
                ss << expression[i];
                i++;
            }
            i--;
            postfix += ss.str();
            postfix += " ";
            last_was_operator = false; // number was encountered, so last character wasn't an operator
        }
        else if(expression[i] == '(')
        {
            s.push('(');
            last_was_operator = true; // '(' is not an operator, but it could mean a new term starts
        }
        else if(expression[i] == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.pop();
            last_was_operator = false; // ')' is not an operator, so last character wasn't an operator
        }
        else if(isOperator(expression[i]))
        {
            if (i == 0 || i == expression.length()-1 || last_was_operator)
            {
                throw runtime_error("ERROR: Expression cannot start or end with an operator! Please try again!");
            }
            while(!s.empty() && precedence(s.top()) >= precedence(expression[i]))
            {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.push(expression[i]);
            last_was_operator = true; // an operator was encountered
        }
    }

    // if statement to output error message if expression starts or ends with operator
    if (last_was_operator) // catch expressions that end with an operator
    {
        throw runtime_error("ERROR: Expression cannot start or end with an operator! Please try again!");
    }
    
    // while loop used to check if expression has equal amount of parenthesis
    // otherwise an error message is outputted
    while(!s.empty())
    {
        if(s.top() == '(' || s.top() == ')')
        {
            throw runtime_error("ERROR: Expression is not syntactically correct! Please try again!");
        }
        postfix += s.top();
        postfix += " ";
        s.pop();
    }

    return postfix;
}

// This function is used to evaluate any given sequence in a post fix string
// that is make the calculation and output it
double evaluatePostfix(string postfix)
{    
    // Creates an empty stack for the sequence
    stack<double> s;
    for(int i = 0; i < postfix.length(); i++)
    {
        // This checks to see if the current character it is viewing
        // is an operator, and if so it pushes it into the stack
        if(isdigit(postfix[i]))
        {
            stringstream ss;
            while(i < postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.'))
            {
                ss << postfix[i];
                i++;
            }
            i--;
            double num;
            ss >> num;
            s.push(num);
        }
        // else if to continue evaluating the expression if a space is encountered
        else if(postfix[i] == ' ')
        {
            continue;
        }
        else
        {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();

            // this evaluates the two operators (op1 and op2). Afterwards it puts the results back into the stack
            switch(postfix[i])
            {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        throw runtime_error("ERROR: Division by zero is undefined! Please try again!");
                    } else {
                        s.push(operand1 / operand2);
                    }
                    break;
                case '^':
                    s.push(pow(operand1, operand2));
                    break;
                default:
                    throw runtime_error("ERROR: Invalid operator! Please try again!");
            }
        }
    }

    // The now emptied stack only has the result of the operators left 
    // in. This now calls the results to use back in the main function.
    return s.top();
}

// main function that runs the program
int main()
{
    // here the infix (expression) variable is initialized
    string expression;

    // user is asked to enter an infix expression
    cout << "Please type the expression in the format of Infix notation: " << endl;
    getline(cin, expression);

    // here the postfix (postfix) variable is inialitized and
    // the infixToPostfix function is called 
    string postfix = infixToPostfix(expression);

    // the result variable is initialized and it evaluated the 
    // postfix expression using the evaluatePostfix function
    double result = evaluatePostfix(postfix);

    // the postfix expression and result are outputted onto the screen
    cout << "The postfix notation: " << endl;
    cout << postfix << endl;
    cout << "The result: " << result << endl;
    
    return 0;
}
