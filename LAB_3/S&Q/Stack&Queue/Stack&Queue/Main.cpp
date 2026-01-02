#include"Stack.h"
#include"Queue.h"
#include"Matrix.h"
#include"Graph.h"
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
	if (maze.getElement(start.getX(), start.getY()) == 0) {
		cout << "Khong co cach di" << endl;
		return;
	}

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
	if (maze.getElement(start.getX(), start.getY()) == 0) {
		cout << "Khong co cach di" << endl;
		return;
	}
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

	Point start(1, 0);
	Point end(9, 9);
	maze.printMatrix();
	findByStack(maze, start, end); 
	findByQueue(maze, start, end);
}
void cau2() {
	Queue A;
	Stack B;
	Queue C;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		A.enqueue(i);
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		C.enqueue(t);
	}
	
	while (!C.isEmpty()) {
		if (!B.isEmpty() && B.top() == C.front()) {
			cout << "B->C"<<endl;
			C.dequeue();
			B.pop();
		}
		else if (!A.isEmpty()) {
			int t = A.dequeue();
			if (t == C.front()) {
				cout << "A->C" << endl;
				C.dequeue();
			}
			else {
				cout << "A->B" << endl;
				B.push(t);
			}
		}
		else {
			cout << "Khong the hoan thanh" << endl;
			break;
		}
	}
}
void cau3() {
	Queue A;
	Queue B;
	Queue C;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		A.enqueue(i);
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		C.enqueue(t);
	}

	while (!C.isEmpty()) {
		if (!B.isEmpty() && B.front() == C.front()) {
			cout << "B->C" << endl;
			C.dequeue();
			B.dequeue();
		}
		else if (!A.isEmpty()) {
			int t = A.dequeue();
			if (t == C.front()) {
				cout << "A->C" << endl;
				C.dequeue();
			}
			else {
				cout << "A->B" << endl;
				B.enqueue(t);
			}
		}
		else {
			cout << "Khong the hoan thanh" << endl;
			break;
		}
	}
}
void cau4() {
	Graph g(9);
	Node n0(element(0));
	Node n1(element(1));
	Node n2(element(2));
	Node n3(element(3));
	Node n4(element(4));
	Node n5(element(5));
	Node n6(element(6));
	Node n7(element(7));
	Node n8(element(8));

	g.addEdge(Edge(n0,n1));
	g.addEdge(Edge(n0, n3));
	g.addEdge(Edge(n0, n8));

	g.addEdge(Edge(n1, n7));

	g.addEdge(Edge(n2, n7));
	g.addEdge(Edge(n2, n3));
	g.addEdge(Edge(n2, n5));

	g.addEdge(Edge(n3, n4));

	g.addEdge(Edge(n4, n8));

	g.addEdge(Edge(n5, n6));

	g.printGraph();

	g.BFS(n0.getId());
	g.DFS(n0.getId());

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
	//cau1();
	//cau2();
	//cau3();
	//cau4();
}