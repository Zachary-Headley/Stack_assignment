#include<vector>
#include<iostream>
#include<stack>
using namespace std;

class Stack{
    private:
        vector<char> stack;

    public:
        Stack(){
            stack = {};
        }

        void push(char top){
            stack.push_back(top);
        }
        int getSize(){
            return stack.size();
        }
        void pop(){
            int size = getSize();
            if(size == 0){
                cout << "Stack is empty" << endl;
                return;
            }
            stack.pop_back();
        }
        char peek() {
            int size = getSize();
            if(size == 0){
                cout << "Stack is empty" << endl;
                return 'o';
            }
            return stack[size - 1];
            cout << stack[size-1];
        }

         bool match(char open, char close) {
            return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
        }

        void isBalanced() {
            Stack check;
            for (char& c : stack) {
                if (c == '(' || c == '[' || c == '{') {
                    check.push(c); // Push opening parentheses onto the stack
                } else if (c == ')' || c == ']' || c == '}') {
                        char open = check.peek(); // Get the most recent opening parenthesis
                        // pop(); // Pop the opening parenthesis from the stack
                        if (!match(open, c)) {
                            cout << "Unbalanced: Mismatched parentheses" << endl;
                            return;
                        } else {
                            check.pop();
                        }
                 }
            }
            if (check.getSize() > 0) {
                cout << "Unbalanced: Extra parenthesis" << endl;
                return;
            } else {
                cout << "Balanced: Parentheses are balanced" << endl;
                return;
            }
        }
};

int main(){
    string s;
    Stack balance;
    cout << "Enter your parenthesis: ";
    cin >> s;
    for(char& c : s){
        balance.push(c);
    }
    
    balance.isBalanced();


    return 0;
}