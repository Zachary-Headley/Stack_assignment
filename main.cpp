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

    // Adds a char to the stack

        void push(char top){
            stack.push_back(top);
        }

    // returns how many parenthesis are in the stack

        int getSize(){
            return stack.size();
        }
    // Makes sure there is something to pop, then removes top of stack if there is something there.

        void pop(){
            int size = getSize();
            if(size == 0){
                cout << "Stack is empty" << endl;
                return;
            }
            stack.pop_back();
        }

    // Makes sure something is there, then returns the top of the stack

        char peek() {
            int size = getSize();
            if(size == 0){
                cout << "Stack is empty" << endl;
                return 'o';
            }
            return stack[size - 1];
        }

    // Checks to see if the parenthesis match one another

         bool match(char open, char close) {
            return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
        }

    //Makes sure the string from main is balanced, and returns the appropriate error if parenthesis are not balanced.

        void isBalanced() {
            Stack check;
            for (char& c : stack) {
                if (c == '(' || c == '[' || c == '{') {
                    check.push(c); // Push opening parentheses onto the stack
                } else if (c == ')' || c == ']' || c == '}') {
                        char open = check.peek(); // Get the most recent opening parenthesis
                        if (!match(open, c)) { // Checks to see if they equal one another
                            cout << "Unbalanced: Mismatched parentheses" << endl;
                            return;
                        } else {
                            check.pop(); // pops top parenthesis
                        }
                 }
            }
            if (check.getSize() > 0) { //checks to see if there is any parenthesis left over
                cout << "Unbalanced: Extra parenthesis" << endl;
                return;
            } else {
                cout << "Balanced: Parentheses are balanced" << endl;
                return;
            }
        }
};

//Creates a string, and inputs the string char by char into the stack balance.
//Then checks if the stack is balanced.

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