class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        if (q1.empty()) {
            q2.push(x);
        } else {
            q1.push(x);
        }
    }

    int pop() {
        if (empty()) {
            return 0;
        }

        if (q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int e = q2.front();
            q2.pop();
            return e;
        } else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int e = q1.front();
            q1.pop();
            return e;
        }
    }

    int top() {
        if (empty()) {
            return 0;
        }

        if (q1.empty()) {
            return q2.back();
        }

        return q1.back();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};