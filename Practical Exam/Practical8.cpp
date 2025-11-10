#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int precidence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

string infixToPostfix(string s){

    stack<char> st;
    string ans;

    for(char c: s){

        if(isalnum(c)) ans += c; // for numeric and alphabetic values in expression
        else if(c == '(') st.push(c); // for opening "("
        else if(c == ')') { // for closing ")"
            
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{ // for operators '+-*/'
            while(!st.empty() && precidence(st.top()) >= precidence(c)){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }

    }

    while(!st.empty()) { ans += st.top(); st.pop();}

    return ans;
}

string infixToPrefix(string s){

    reverse(s.begin(), s.end());

    for(int i=0; i<s.length(); i++){
        if(s[i] == ')') s[i] == '(';
        else if(s[i] == '(') s[i] == ')';
    }

    string post = infixToPostfix(s);
    reverse(post.begin(), post.end());

    return post;
}

int evalPostFix(string s){

    stack<char> st;

    for(char c: s){

        if(isdigit(c)) st.push(c - '0');
        else{
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(c == '+') st.push(a+b);
            else if(c == '-') st.push(a-b);
            else if(c == '*') st.push(a*b);
            else st.push(a/b);
        }
    }

    return st.top();
}

int evalPrefix(string s) {
    reverse(s.begin(), s.end());
    return evalPostFix(s);  
}


int main(){

    string exp;

    cout << "Enter your expration: ";
    cin >> exp;

    string postfix = infixToPostfix(exp);
    string prefix = infixToPrefix(exp);

    cout << "PostFix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    cout << "PostFix Evaluation: " << evalPostFix(postfix) << endl;
    cout << "PostFix Evaluation: " << evalPrefix(prefix) << endl;

    return 0;
}