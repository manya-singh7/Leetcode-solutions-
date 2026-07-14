/*Easy*/

#include <stack>
#include<iostream>
#include<unordered_map>
#include <string>
using namespace std;

bool isValid(string s) {
    stack <char> st;

    unordered_map <char,char> mp ={
        {')','('},
        {'}','{'},
        {']','['}
    };

    for (char c:s) {
        if (c=='('|| c=='{'|| c=='[') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                return false;
            }
            if (st.top()!=mp[c]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

/*int main() {

    string s;

    cout << "Enter the bracket string: ";
    cin >> s;

    if (isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}*/