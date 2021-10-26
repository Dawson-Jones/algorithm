class MinStack {
private:
    stack<int> stk;
    stack<int> astk;
public:
    MinStack() {
        astk.push(INT32_MAX);
    }

    void push(int x) {
        stk.push(x);
        astk.push(x < astk.top() ? x : astk.top());
    }

    void pop() {
        astk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int min() {
        return astk.top();
    }
};
