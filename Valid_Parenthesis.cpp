/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    if( s.size() % 2 != 0 ) {
        return false;
    }

    for( char c : s ) {
        if( c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty() ||
                (c == '(' && st.top() != ')') ||
                (c == '{' && st.top() != '}') ||
                (c == '[' && st.top() != ']')
            ) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "({{}})";
    
    if(isValid(s)) {
        cout << "String is balanced." << endl;
    } else {
        cout << "String is not balanced" << endl;
    }
}