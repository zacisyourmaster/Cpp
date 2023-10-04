#include "stack_L_T.h" // Include the custom stack implementation header
#include <iostream>
using namespace std;

// Function to determine the precedence of an operator
int precedance(char str);

// Function to check if a character is an operator
bool isOperator(char ch);

// Function to check if a character is an operand (digit)
bool isOperand(char ch);

// Function to convert an infix expression to postfix notation
string toPost(string s);

// Function to evaluate a postfix expression
double postCalc(string str);

// Function to validate the input infix expression
bool isValid(string infix);

int main() {
    string infix;
    cin >> infix;

    try 
    {
        // Convert the infix expression to postfix notation
        string postfix = toPost(infix);
        cout << postfix << endl;

        // Validate the infix expression
        isValid(infix);

        // Evaluate the postfix expression and print the result
        double result = postCalc(postfix);
        cout << result << endl;
    }
    catch (Stack<char>::Underflow)
    {
        cout << "The expression is in a wrong format1" << endl;
    }
    catch (Stack<double>::Underflow)
    {
        cout << "The expression is in a wrong format2" << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}

string toPost(string infix) {
    string postfix = "";
    Stack<char> st;

    // Check if the expression is too short to be valid
    if (infix.size() <= 2)
        throw "The expression is in a wrong format";

    for (int i = 0; i < infix.size(); i++) {
        char ch = infix[i];
        if (isOperand(ch)) {
            postfix += ch;
        }
        else if (isOperator(ch)) {

            // Pop operators with higher precedence from the stack
            while (!st.empty() && precedance(ch) <= precedance(st.getTop())) {
                postfix += st.getTop();
                st.pop();
            }

            // Push the current operator onto the stack
            st.push(ch);
        }
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')') {
            if (st.empty())
                throw "The expression is in a wrong format";

            // Pop operators until an opening parenthesis is encountered
            while (st.getTop() != '(') {
                postfix += st.getTop();
                st.pop();
            }
            st.pop(); // Remove the opening parenthesis
        }
        else
            throw "The expression is in a wrong format";
    }

    // Pop any remaining operators from the stack
    while (!st.empty()) {
        postfix += st.getTop();
        st.pop();
    }
    return postfix;
}

int precedance(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '*' || ch == '/' || ch == '-');
}

double postCalc(string post) {
    Stack<double> st;
    double answer;

    for (int i = 0; i < post.size(); i++) {
        char ch = post[i];
        if (isOperand(ch))
            st.push(ch - '0'); // Convert the character to a numeric value
        else if (isOperator(ch)) {
            double a = st.getTop();
            st.pop();
            if (st.empty())
                throw "The expression is in a wrong format";
            double b = st.getTop();
            st.pop();

            // Perform the operation and push the result onto the stack
            if (ch == '+')
                st.push(b + a);
            else if (ch == '-')
                st.push(b - a);
            else if (ch == '/')
                st.push(b / a);
            else if (ch == '*')
                st.push(b * a);
        }
    }

    // Get the final result from the stack
    answer = st.getTop();
    st.pop();

    // Ensure the stack is empty, or the expression is invalid
    if (!st.empty())
        throw "The expression is in a wrong format";

    return answer;
}

bool isValid(string infix) {
    int operatorcount = 0;
    int operandcount = 0;

    // Check if the first token is an operator
    if (isOperator(infix[0]))
        throw "The expression is in a wrong format";

    for (int i = 0; i < infix.size(); i++) {

        // Check for two operands in a row
        if (isOperand(infix[i]) && isOperand(infix[i + 1]))
            throw "The expression is in a wrong format";

        // Check for two operators in a row
        if (isOperator(infix[i]) && isOperator(infix[i + 1]))
            throw "The expression is in a wrong format";

        if (isOperator(infix[i]))
            operatorcount++;
        if (isOperand(infix[i]))
            operandcount++;
    }

    // Ensure there are more operands than operators
    if (operatorcount >= operandcount)
        throw "The expression is in a wrong format";
}
