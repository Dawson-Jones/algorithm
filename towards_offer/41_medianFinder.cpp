class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> que_min;
    priority_queue<int, vector<int>, greater<int>> que_max;
    MedianFinder() { }

    void addNum(int num) {
        if (que_min.empty() || num <= que_min.top()) {
            que_min.push(num);
            if (que_max.size() + 1 < que_min.size()) {
                que_max.push(que_min.top());
                que_min.pop();
            }
        } else {
            que_max.push(num);
            if (que_max.size() > que_min.size()) {
                que_min.push(que_max.top());
                que_max.pop();
            }
        }
    }

    double findMedian() {
        if (que_min.size() > que_max.size())
            return que_min.top();
        else
            return (que_min.top() + que_max.top()) / 2.;
    }
};