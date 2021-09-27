class CQueue {
private:
    stack<int> in_stk;
    stack<int> out_stk;
public:
    CQueue() {
        in_stk = stack<int>();
        out_stk = stack<int>();
    }

    void appendTail(int value) {
        in_stk.push(value);
    }

    int deleteHead() {
        if (out_stk.empty()) {
            if (in_stk.empty()) {
                return -1;
            } else {
                while (!in_stk.empty()) {
                    int x = in_stk.top();
                    in_stk.pop();
                    out_stk.push(x);
                }
            }
        }

        int x = out_stk.top();
        out_stk.pop();
        return x;
    }
};