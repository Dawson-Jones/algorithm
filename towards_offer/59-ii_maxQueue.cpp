class MaxQueue {
private:
    queue<int> q;
    deque<int> dq;
public:
    MaxQueue() {}

    int max_value() {
        if (dq.empty())
            return -1;
        return dq.front();
    }

    void push_back(int value) {
        while (!dq.empty() && dq.back() < value)
            dq.pop_back();
        
        dq.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == dq.front())
            dq.pop_front();
        
        q.pop();
        return ans;
    }
};