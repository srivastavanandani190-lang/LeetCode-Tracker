class MyQueue {
    stack<int> inStack;
    stack<int> outStack;

public:
    MyQueue() {
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (empty()) return -1;

        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek() {
        if (empty()) return -1;

        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};