#include <iostream>
#include <stack>
#include <string>
using namespace std;


struct Bracket {
    Bracket(char type, int position) :
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {



    std::string text;
    getline(std::cin, text);
    bool toOutput = true;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket x(next, position);

            opening_brackets_stack.push(x);

        }

        if (next == ')' || next == ']' || next == '}') {

            if (opening_brackets_stack.empty()) {
                cout << position + 1 << endl;
                toOutput = false;
                break;
            }
            if (opening_brackets_stack.empty() == false) {
                Bracket now = opening_brackets_stack.top();
                if (now.Matchc(next)) {
                    opening_brackets_stack.pop();
                }
                else {
                    cout << position + 1 << endl;
                    toOutput = false;
                    break;
                }

            }

        }
    }

    if (toOutput) {
        if (opening_brackets_stack.empty()) {
            cout << "Success" << endl;
        }
        else {
            Bracket res = opening_brackets_stack.top();
            while (!opening_brackets_stack.empty()) {
                res = opening_brackets_stack.top();
                opening_brackets_stack.pop();
            }


            cout << res.position + 1 << endl;
        }
    }

    return 0;
}
