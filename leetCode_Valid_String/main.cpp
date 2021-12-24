#include <iostream>
#include <stack>
using namespace std;

// Helper method that compares parentheses and returns if it matches
bool compareCharPar(char c1, char c2)
{
    if (c1 == '{' && c2 == '}')
        return true;
    else if (c1 == '(' && c2 == ')')
        return true;
    else if (c1 == '[' && c2 == ']')
        return true;
    else
    {
        return false;
    }
}

bool isValid(string s)
{
    // Return false if the string has a odd length
    if (s.length() % 2 == 1)
        return false;
    bool result = true;

    stack<char> startPar;
    // Parse through the string and compare open parenthesis
    for (int i = 0; i < s.length(); i++)
    {
        char currChar = s[i];

        // If character is a open parenthesis add to stack
        if (currChar == '{' || currChar == '(' || currChar == '[')
            startPar.push(currChar);
        else
        {
            // If the stack is empty and the char is a closed parenthesis
            // return false
            if (startPar.empty())
                return false;

            // Compare the value of the characters
            result = compareCharPar(startPar.top(), currChar);
            startPar.pop();
        }

        // If the characters did not match then return false
        if (!result)
            return result;
    }
    // If the stack is empty and the string has been parsed through
    // then return true
    if (startPar.empty())
        return true;
    else
    {
        // If the stack still has characters in it the return false
        return false;
    }
}

int main()
{
    cout << isValid("[][");

    return 0;
}
