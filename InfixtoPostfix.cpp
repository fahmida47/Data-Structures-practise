#include <bits/stdc++.h>
using namespace std;

int Priority (char s){
if(s=='^')
    return 100;
else if(s=='*'|| s=='/')
    return 50;
else if (s=='+'|| s=='-')
    return 20;
else
    return 0;
}

string InfixToPostfix(string s) {
    stack<char>S;
    string st;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ')
            continue;
        if (isdigit(s[i])) {
            while (i<n && isdigit(s[i])) {
                st+= s[i];
                i++;
            }
            st+= ' ';
            i--;
        }

        else if (s[i] == '(') {
            S.push(s[i]);
        }

        else if (s[i] == ')') {
            while (!S.empty() && S.top() != '(') {
                st+= S.top();
                st+= ' ';
                S.pop();
            }
            if (!S.empty()) S.pop();
        }

        else { 
            while (!S.empty() && Priority(s[i]) <= Priority(S.top())) {
                st += S.top();
                st += ' ';
                S.pop();
            }
            S.push(s[i]);
        }
    }

    while (!S.empty()) {
        st+= S.top();
        st+= ' ';
        S.pop();
    }
    cout << "Postfix: " << st << endl;
    return st;
}

double evaluate(string s) {
    stack<double>S;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ')
            continue;

        else if (isdigit(s[i])) {
            double num = 0;
            while (i < s.length() && isdigit(s[i])) {
                num = (num * 10) + (s[i] - '0');
                i++;
            }
            i--;
            S.push(num);
        }
        else {
            double a = S.top(); S.pop();
            double b = S.top(); S.pop();

            switch (s[i]) {
                case '+':
                    S.push(b+a);
                    break;
                case '-':
                    S.push(b-a);
                    break;
                case '*':
                    S.push(b*a);
                    break;
                case '/':
                    S.push(b/a); 
                    break;
                case '^':
                    S.push(pow(b,a));
                    break;
                default:
                    cout << "Invalid operator" << endl;
                    return -1;
            }
        }
    }
    return S.top();
}

int main() {
    string cal = "(12 + 34) * 56 - 78 / 9";
    string postEvlt = InfixToPostfix(cal);
    cout << "Evaluation: " << evaluate(postEvlt) << endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
stack<char>S;

int priority (char s){
if(s=='^')
    return 100;
else if(s=='*'|| s=='/')
    return 50;
else if (s=='+'|| s=='-')
    return 20;
else
    return 0;

}

int main(){
    string infix,postfix="";
    cin>>infix;
    for(int i=0;i<infix.size();i++){
        char symbol=infix[i];
        if(symbol>='A'&& symbol<='Z'){
            postfix=postfix+symbol;
        }
        else if(symbol=='('){
                    S.push(symbol);
        }
        else if(symbol==')'){
            while(S.empty()&& S.top()!='('){
                 postfix=postfix+S.top();
                 S.pop();
            }
            S.pop();
        }
        else{
            while(!S.empty() && priority(S.top())>=priority(symbol)){
                postfix=postfix+S.top();
                S.pop();
            }
            S.push(symbol);
        }
    }
    while(!S.empty()){
        postfix=postfix+S.top();
        S.pop();
    }
    cout<<postfix<<endl;
    return 0;
}

