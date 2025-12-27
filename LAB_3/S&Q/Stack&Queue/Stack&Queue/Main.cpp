#include"Stack.h"
#include"Queue.h"
#include"Matrix.h"
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
void printPath(Point start, Point end, Point** parent) {
	Stack pathStack;
	Point temp = end;


	while (!(temp.getX() == start.getX() && temp.getY() == start.getY())) {
		pathStack.pushPoint(temp);
		temp = parent[temp.getX()][temp.getY()];
	}
	pathStack.pushPoint(start);

	
	cout << "Duong di: ";
	while (!pathStack.isEmpty()) {
		Point p = pathStack.popPoint();
		cout << "(" << p.getX() << "," << p.getY() << ")";
		if (!pathStack.isEmpty()) cout << " -> ";
	}
	cout << endl;
}
void findByStack(Matrix& maze, Point start, Point end) {
	int r = maze.getRows();
	int c = maze.getCols();

	bool** visited = new bool* [r];
	Point** parent = new Point * [r];
	for (int i = 0; i < r; i++) {
		visited[i] = new bool[c] {false};
		parent[i] = new Point[c];
	}

	Stack s;
	s.pushPoint(start);
	visited[start.getX()][start.getY()] = true;
	bool found = false;

	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	while (!s.isEmpty()) {
		Point curr = s.popPoint();

		if (curr.getX() == end.getX() && curr.getY() == end.getY()) {
			found = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			Point next(curr.getX() + dx[i], curr.getY() + dy[i]);
			if (maze.isValid(next) && !visited[next.getX()][next.getY()]) {
				visited[next.getX()][next.getY()] = true;
				parent[next.getX()][next.getY()] = curr;
				s.pushPoint(next);
			}
		}
	}

	if (found) {
		cout << "STACK (DFS): Tim thay duong di!" << endl;
		printPath(start, end, parent);
	}
	else {
		cout << "STACK (DFS): Khong tim thay duong di." << endl;
	}
	for (int i = 0; i < r; i++) { delete[] visited[i]; delete[] parent[i]; }
	delete[] visited; delete[] parent;
}
void findByQueue(Matrix& maze, Point start, Point end) {
	int r = maze.getRows();
	int c = maze.getCols();

	bool** visited = new bool* [r];
	Point** parent = new Point * [r];
	for (int i = 0; i < r; i++) {
		visited[i] = new bool[c] {false};
		parent[i] = new Point[c];
	}

	Queue q;
	q.enqueuePoint(start);
	visited[start.getX()][start.getY()] = true;
	bool found = false;

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	while (!q.isEmpty()) {
		Point curr = q.dequeuePoint();

		if (curr.getX() == end.getX() && curr.getY() == end.getY()) {
			found = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			Point next(curr.getX() + dx[i], curr.getY() + dy[i]);
			if (maze.isValid(next) && !visited[next.getX()][next.getY()]) {
				visited[next.getX()][next.getY()] = true;
				parent[next.getX()][next.getY()] = curr;
				q.enqueuePoint(next);
			}
		}
	}

	if (found) {
		cout << "QUEUE (BFS): Tim thay duong ngan nhat!" << endl;
		printPath(start, end, parent);
	}
	else {
		cout << "QUEUE (BFS): Khong tim thay duong di." << endl;
	}
	for (int i = 0; i < r; i++) { delete[] visited[i]; delete[] parent[i]; }
	delete[] visited; delete[] parent;
}
void cau1() {
	int m = 10, n = 10;
	Matrix maze(m, n);
	maze.generateRandom(0.2);

	Point start(0, 0);
	Point end(9, 9);
	maze.printMatrix();
	findByStack(maze, start, end);
	findByQueue(maze, start, end);
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