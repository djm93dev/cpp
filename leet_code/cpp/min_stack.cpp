#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
     stack<pair<int, int>> st;

public:
    void push(int x) {
        int min; // min value in the stack
        if (st.empty()) { // if stack is empty
            min = x; // min value is x
        }
        else {
            min = std::min(st.top().second,x); // min value is the minimum of the top of the stack and x
        }
        st.push({x, min}); // push the pair of x and min value
    }

    void pop() {
        st.pop(); // pop the top of the stack
    }

    int top() {
        return st.top().first; // return the top of the stack
    }

    int getMin() {
        return st.top().second; // return the minimum value in the stack
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->push(6);
    obj->push(7);

    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->getMin() << endl;

    return 0;
}
