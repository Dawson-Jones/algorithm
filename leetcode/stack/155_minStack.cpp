class MinStack {
private:
    stack<int> stk;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int val) {
        stk.push(val);
        int cur_min = astk.top();
        astk.push(min(val, cur_min));
    }

    void pop() {
        stk.pop();
        astk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return astk.top();
    }
};