class MinStack {
public:
    stack<int> s;
    MinStack() {

    }

    void push(int val) {
        s.push(val);
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        stack<int> tmp;
        int mn = s.top();
        while (s.size()) {
            mn = min(mn, s.top());
            tmp.push(s.top());
            s.pop();
        }

        while (tmp.size()) {
            s.push(tmp.top());
            tmp.pop();
        }

        return mn;
    }
};
