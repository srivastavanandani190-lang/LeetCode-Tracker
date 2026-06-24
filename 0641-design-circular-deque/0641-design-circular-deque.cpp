class MyCircularDeque {
    vector<int> dq;
    int front, rear, size, cap;

public:
    MyCircularDeque(int k) {
        cap = k;
        dq.resize(k);
        front = 0;
        rear = 0;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        front = (front - 1 + cap) % cap;
        dq[front] = value;
        size++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        dq[rear] = value;
        rear = (rear + 1) % cap;
        size++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % cap;
        size--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        rear = (rear - 1 + cap) % cap;
        size--;

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return dq[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return dq[(rear - 1 + cap) % cap];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};