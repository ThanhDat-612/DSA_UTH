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

	if (maze[start.getX()][start.getY()] == 0) {
		cout << "Khong co duong di" << endl;
		return;
	}
	Stack s;
	bool visited[5][5] = { false };
	Point parent[5][5];
	bool found = false;
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	s.pushPoint(start);
	visited[start.getX()][start.getY()] = true;
	while (!s.isEmpty()) {
		Point current = s.popPoint();
		if (current.getX() == end.getX() && current.getY() == end.getY()) {
			found = true;
			break;
		}	
		for (int i = 0; i < 4; i++) {
			int nx = current.getX() + dx[i];
			int ny = current.getY() + dy[i];
			if (nx >= 0 && nx < m && ny>=0 && ny < n && maze[nx][ny] == 1 && visited[nx][ny] != true) {
				visited[nx][ny] = true;
				parent[nx][ny] = current;
				s.pushPoint(Point(nx, ny));
			}
		}
	}
	if (found) {
		cout << "DFS tim thay duong di:" << endl;

		// Dùng một Stack khác để đảo ngược đường đi từ parent (từ đích về đầu) thành (từ đầu đến đích)
		Stack pathStack;
		Point temp = end;
		while (!(temp.getX() == start.getX() && temp.getY() == start.getY())) {
			pathStack.pushPoint(temp);
			temp = parent[temp.getX()][temp.getY()];
		}
		pathStack.pushPoint(start);

		// In danh sách tọa độ
		while (!pathStack.isEmpty()) {
			Point p = pathStack.popPoint();
			cout << "(" << p.getX() << "," << p.getY() << ")";
			if (!pathStack.isEmpty()) cout << " -> ";
		}
		cout << endl;
	}
	else {
		cout << "Khong tim thay duong di bang DFS!" << endl;
	}

}
int main() {
	/*Stack s;
	Queue q;
	int size = 3;
	int n;*/
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
	cau1();

}