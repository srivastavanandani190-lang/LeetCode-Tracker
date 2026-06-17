class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minSt.push(value);
        } else {
            st.push(value);
            minSt.push(min(value, minSt.top()));
        }
    }

    void pop() {
        if (st.empty()) return;

        st.pop();
        minSt.pop();
    }

    int top() {
        if (st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if (minSt.empty()) return -1;
        return minSt.top();
    }
};