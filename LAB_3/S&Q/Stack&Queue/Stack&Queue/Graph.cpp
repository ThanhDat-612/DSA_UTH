#include "Graph.h"
Graph::Graph(int num) {
    this->numNodes = num;
    this->adj = new linkedlist * [num];
    for (int i = 0; i < num; i++) {
        this->adj[i] = new linkedlist(); 
    }
}
void Graph::addEdge(Edge e) {
    int u = e.getU().getId(); //
    int v = e.getV().getId(); //
    if (u >= 0 && u < numNodes && v >= 0 && v < numNodes) {
        this->adj[u]->InsertTail(new element(v)); // Thêm v vào u
        this->adj[v]->InsertTail(new element(u)); // Thêm u vào v (vô hướng)
    }
}
int Graph::getNumNodes() {
	return this->numNodes;
}

void Graph::printGraph() {
    for (int i = 0; i < numNodes; i++) {
        cout << "Nut " << i << ": ";
        this->adj[i]->Traversal();
        cout << endl;
    }
}
void Graph::BFS(int startNode) {
    bool* visited = new bool[numNodes] {false};
    Queue q;

    visited[startNode] = true;
    q.enqueue(startNode);

    cout << "BFS: ";
    while (!q.isEmpty()) {
        int u = q.front();
        q.dequeue();
        cout << u << " ";

        // Duyệt các nút kề
        element* curr = adj[u]->Gethead();
        while (curr != nullptr) {
            int v = curr->Getdata();
            if (!visited[v]) {
                visited[v] = true;
                q.enqueue(v);
            }
            curr = curr->Getpointer();
        }
    }
    cout << endl;
    delete[] visited;
}

// Thuật toán DFS (Duyệt theo chiều sâu - Dùng Stack)
void Graph::DFS(int startNode) {
    if (startNode < 0 || startNode >= numNodes) return;

    bool* visited = new bool[numNodes] {false};
    Stack s; // Lớp Stack của bạn

    s.push(startNode);

    cout << "DFS: ";
    while (!s.isEmpty()) {
        int u = s.pop();

        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;

            // Lấy danh sách kề của nút u
            element* curr = adj[u]->Gethead();
            while (curr != nullptr) {
                int v = curr->Getdata();
                if (!visited[v]) {
                    s.push(v);
                }
                curr = curr->Getpointer(); // Sẽ không lỗi nếu InsertTail đã sửa ở trên
            }
        }
    }
    cout << endl;
    delete[] visited;
}