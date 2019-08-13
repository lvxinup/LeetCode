#define  _CRT_SECURE_NO_WARNINGS 1

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		if (min.empty() || x <= min.top())
			min.push(x);
	}

	void pop() {
		if (s.top() == min.top()){
			min.pop();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min.top();
	}
private:
	std::stack<int> s;//保存栈中的元素
	std::stack<int> min;//保存栈中的最小值
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/