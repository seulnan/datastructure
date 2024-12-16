#include <iostream>
using namespace std;

const int INF = 1e9; // 무한대 값 설정

struct Edge {
    int u, v, weight;
};

class Graph {
    int V;              // 정점의 개수
    int** adjMatrix;    // 인접 행렬
    Edge edges[100];    // 간선 리스트
    int edgeCount;      // 간선 개수

public:
    Graph(int V) : V(V), edgeCount(0) {
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INF;
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
        edges[edgeCount++] = {u, v, weight};
    }

    void kruskalMST() {
        // 간선을 가중치 기준으로 정렬 (버블 정렬)
        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = 0; j < edgeCount - i - 1; j++) {
                if (edges[j].weight > edges[j + 1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        // Union-Find 구조체 구현
        int parent[100];
        for (int i = 0; i < V; i++) parent[i] = i;

        auto find = [&](int x) {
            while (parent[x] != x) x = parent[x];
            return x;
        };

        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) parent[rootY] = rootX;
        };

        cout << "Kruskal MST: ";
        for (int i = 0; i < edgeCount; i++) {
            int u = edges[i].u, v = edges[i].v;
            if (find(u) != find(v)) {
                cout << "(" << u << ", " << v << ") ";
                unite(u, v);
            }
        }
        cout << endl;
    }

    void primMST() {
        bool visited[100] = {false};
        int key[100];
        int parent[100];

        for (int i = 0; i < V; i++) {
            key[i] = INF;
            parent[i] = -1;
        }
        key[0] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = -1, minKey = INF;
            for (int v = 0; v < V; v++) {
                if (!visited[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] && !visited[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
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

    void dijkstra(int start) {
        int dist[100]; // 모든 정점까지의 최단 거리를 저장할 배열
        bool visited[100] = {false}; // 각 정점이 방문되었는지 여부를 저장하는 배열

        // 초기화: 모든 정점까지의 거리를 무한대로 설정
        for (int i = 0; i < V; i++) dist[i] = INF; 

        // 시작 정점의 거리는 0으로 설정(자기자신까지의 거리)
        dist[start] = 0;

        // 정점의 개수만큼 반복(최대 v-1개의 간선 탐색)
        for (int i = 0; i < V - 1; i++) {
            int u = -1; // 현재 선택된 정점(최단거리를 가진 정점)
            
            int minDist = INF; // 현재까지 발견된 최단 거리

            // 방문되지 않은 정점 중에서 최단 거리를 가진 정점을 선택
            for (int v = 0; v < V; v++) {
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v]; // 최단거리 갱신
                    u = v; // 해당 정점을 선택
                }
            }

            // 선택된 정점방문처리
            visited[u] = true;

            // u와 인접한 정점들의 거리 갱신
            for (int v = 0; v < V; v++) {
                // 방문하지않았는지, 인접한 정점인지, u를 경유하는 경로가 더 짧은지 확인
                if (!visited[v] && adjMatrix[u][v] != INF &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    // u를 경우하여 v에 도달하는 최단거리로 갱신
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        cout << "Dijkstra: ";
        for (int i = 0; i < V; i++) cout << dist[i] << " ";
        cout << endl;
    }

    void floydWarshall() {
        int dist[100][100];

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = adjMatrix[i][j];
            }
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        cout << "Floyd-Warshall:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();
    g.primMST();
    g.dijkstra(0);
    g.floydWarshall();

    return 0;
}
