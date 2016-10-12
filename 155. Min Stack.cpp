class MinStack {
private:
	stack<long long> st;
	long long m;
public:
    /** initialize your data structure here. */
    MinStack() {
		m = INT_MAX;
    }

    void push(int x) {
		if(st.empty()) {
			st.push(0LL);
			m = x;
		} else {
			st.push(x-m);
			if(x<m)  m = x;
		}
    }

    void pop() {
		if(st.empty()) return;
		long long tmp = st.top();
		st.pop();
		if(tmp<0) m = m-tmp;
    }

    int top() {
		long long tmp = st.top();
		if(tmp>0) return tmp+m;
		else return m;
    }

    int getMin() {
		return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
