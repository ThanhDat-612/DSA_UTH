#include"Stack.h"
#include"Queue.h"

using namespace std;
void toBinary(int n) {
	Stack s;
	if (n == 0) {
		cout << "0";
		return;
	}
	while (n > 0) {
		s.push(n % 2);
		n /= 2;
	}
	s.printStack();
}
void cau1() {
	int m = 5, n = 5;
	int maze[5][5] = {
		{1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 0, 1, 0, 0},
		{1, 1, 1, 1, 0},
		{1, 0, 0, 1, 1}
	};
	Point start(0, 0);
	Point end(4, 4);

}
int main() {
	Stack s;
	Queue q;
	int size = 3;
	int n;
	/*for (int i = 0;i < size;i++) {
		cin >> n;
		s.push(n);
		q.enqueue(n);
	}
	for (int i = 0;i <= size;i++) {
		s.pop();
		q.dequeue();
	}*/
	//s.printStack();
	//q.printQueue();

	//toBinary(11);

}