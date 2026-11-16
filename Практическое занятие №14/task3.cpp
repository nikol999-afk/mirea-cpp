
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> mins;

public:
    void push(int x) {
        st.push(x);

        if (mins.empty() || x <= mins.top()) {
            mins.push(x);
        }
    }

    void pop() {
        if (st.empty()) return;

        if (st.top() == mins.top()) {
            mins.pop();
        }

        st.pop();
    }

    bool empty() {
        return st.empty();
    }

    int getMin() {
        return mins.top();
    }
};

int main() {
    MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << s.getMin() << endl;

    s.pop();

    cout << s.getMin() << endl;

    return 0;
}
