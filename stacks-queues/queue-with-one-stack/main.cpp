#include <bits/stdc++.h>
using namespace std;

class QueueWithStack {
private:
	stack<int> s;

public:
	QueueWithStack() {}

	void enque(int i) {
		s.push(i);
	}

	int deque() {
		int poppedNum = s.top();
		s.pop();

		if (s.empty()) {
			return poppedNum;
		}
		else {
			int returnVal = deque();
			s.push(poppedNum);
			return returnVal;
		}
	}
};

int main() {
	QueueWithStack q;
	q.enque(1);
	q.enque(2);
	q.enque(3);
	q.enque(4);
	q.enque(5);

	cout << q.deque() << endl;
	cout << q.deque() << endl;

	q.enque(6);
	q.enque(7);

	cout << q.deque() << endl;

	return 0;
}