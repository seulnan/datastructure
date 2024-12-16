#include <iostream>
using namespace std;

// 간선 구조체 정의
struct Edge {
    int u, v, weight; // 시작 정점, 끝 정점, 가중치
};

// // Union-Find 구조체 정의
// struct UnionFind {
//     int parent[100];
//     int rank[100];

//     // 초기화
//     void initialize(int n) {
//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//             rank[i] = 0;
//         }
//     }

//     // Find 연산 (경로 압축)
//     int find(int x) {
//         if (parent[x] != x) {
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }

//     // Union 연산
//     void unite(int x, int y) {
//         int rootX = find(x);
//         int rootY = find(y);

//         if (rootX != rootY) {
//             if (rank[rootX] > rank[rootY]) {
//                 parent[rootY] = rootX;
//             } else if (rank[rootX] < rank[rootY]) {
//                 parent[rootX] = rootY;
//             } else {
//                 parent[rootY] = rootX;
//                 rank[rootX]++;
//             }
//         }
//     }
// };

// 그래프 클래스 정의
class Graph {
    int V; // 정점 개수
    int E; // 간선 개수
    Edge edges[100]; // 간선 배열
    int edgeCount; // 현재까지 추가된 간선 개수

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        this->edgeCount = 0;
    }

    // 간선 추가
    void addEdge(int u, int v, int weight) {
        edges[edgeCount].u = u;
        edges[edgeCount].v = v;
        edges[edgeCount].weight = weight;
        edgeCount++;
    }

    // Kruskal MST
    // void kruskalMST() {
    //     // 간선을 가중치 기준으로 정렬
    //     for (int i = 0; i < edgeCount - 1; i++) {
    //         for (int j = 0; j < edgeCount - i - 1; j++) {
    //             if (edges[j].weight > edges[j + 1].weight) {
    //                 Edge temp = edges[j];
    //                 edges[j] = edges[j + 1];
    //                 edges[j + 1] = temp;
    //             }
    //         }
    //     }

    //     UnionFind uf;
    //     uf.initialize(V);

    //     cout << "Kruskal MST: ";
    //     for (int i = 0; i < edgeCount; i++) {
    //         int u = edges[i].u;
    //         int v = edges[i].v;

    //         if (uf.find(u) != uf.find(v)) {
    //             cout << "(" << u << ", " << v << ") ";
    //             uf.unite(u, v);
    //         }
    //     }
    //     cout << endl;
    // }

    // Prim MST
    void primMST() {
        bool visited[100] = { false }; // 방문 여부
        int key[100]; // 최소 가중치 값
        int parent[100]; // 연결된 부모 정점

        for (int i = 0; i < V; i++) {
            key[i] = INT_MAX;
            parent[i] = -1;
        }

        key[0] = 0; // 시작 정점
        for (int count = 0; count < V - 1; count++) {
            int minKey = INT_MAX, u;

            // 방문하지 않은 정점 중 최소 가중치 정점 찾기
            for (int i = 0; i < V; i++) {
                if (!visited[i] && key[i] < minKey) {
                    minKey = key[i];
                    u = i;
                }
            }

            visited[u] = true;

            // u와 연결된 모든 정점의 가중치 갱신
            for (int i = 0; i < edgeCount; i++) {
                int v = edges[i].u == u ? edges[i].v : (edges[i].v == u ? edges[i].u : -1);
                if (v != -1 && !visited[v] && edges[i].weight < key[v]) {
                    key[v] = edges[i].weight;
                    parent[v] = u;
                }
            }
        }

        cout << "Prim MST: ";
        for (int i = 1; i < V; i++) {
            cout << "(" << parent[i] << ", " << i << ") ";
        }
        cout << endl;
    }

    // Dijkstra 최단 경로
    void dijkstra(int start) {
        bool visited[100] = { false };
        int dist[100];

        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
        }
        dist[start] = 0;

        for (int count = 0; count < V - 1; count++) {
            int minDist = INT_MAX, u;

            for (int i = 0; i < V; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            visited[u] = true;

            for (int i = 0; i < edgeCount; i++) {
                int v = edges[i].u == u ? edges[i].v : (edges[i].v == u ? edges[i].u : -1);
                if (v != -1 && !visited[v] && dist[u] != INT_MAX && dist[u] + edges[i].weight < dist[v]) {
                    dist[v] = dist[u] + edges[i].weight;
                }
            }
        }

        cout << "Dijkstra: ";
        for (int i = 0; i < V; i++) {
            cout << dist[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int V = 4, E = 5;
    Graph g(V, E);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.primMST();
    g.dijkstra(0);

    return 0;
}
