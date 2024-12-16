#include <iostream>
using namespace std;

const int INF = 9999; // 무한대 값
const int MAX_VTXS = 100; // 최대 정점 개수

class Graph {
    int adj[MAX_VTXS][MAX_VTXS]; // 인접 행렬
    char vertices[MAX_VTXS];    // 정점 이름
    int size;                   // 정점 개수

public:
    Graph(int n) : size(n) {
        for (int i = 0; i < size; i++) {
            vertices[i] = 'A' + i; // 정점 이름 설정
            for (int j = 0; j < size; j++) {
                adj[i][j] = (i == j) ? 0 : INF; // 대각선은 0, 나머지는 INF
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        adj[u][v] = weight;
        adj[v][u] = weight; // 무방향 그래프
    }
    
    void Prim() {
        bool selected[MAX_VTXS] = {false}; // MST 포함 여부
        int dist[MAX_VTXS];               // MST와의 거리
        int parent[MAX_VTXS];             // MST 간선의 부모 정점

        for (int i = 0; i < size; i++) {
            dist[i] = INF; // 초기화
            parent[i] = -1;
        }
        dist[0] = 0; // 시작 정점

        for (int i = 0; i < size; i++) {
            int u = -1, minDist = INF;

            // MST에 포함되지 않은 정점 중 최단 거리 정점 선택
            for (int v = 0; v < size; v++) {
                if (!selected[v] && dist[v] < minDist) {
                    u = v;
                    minDist = dist[v];
                }
            }

            selected[u] = true;

            // 인접한 정점의 거리 갱신
            for (int v = 0; v < size; v++) {
                if (!selected[v] && adj[u][v] < dist[v]) {
                    dist[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

        // 결과 출력
        cout << "Prim MST:" << endl;
        int totalWeight = 0;
        for (int i = 1; i < size; i++) {
            cout << "(" << vertices[parent[i]] << ", " << vertices[i] << ") with weight " << dist[i] << endl;
            totalWeight += dist[i];
        }
        cout << "Total Weight: " << totalWeight << endl;
    }

    void Kruskal() {
        struct Edge {
            int u, v, weight;
        };

        Edge edges[MAX_VTXS * MAX_VTXS];
        int edgeCount = 0;

        // 간선 리스트 생성
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (adj[i][j] != INF) {
                    edges[edgeCount].u = i;
                    edges[edgeCount].v = j;
                    edges[edgeCount].weight = adj[i][j];
                    edgeCount++;
                }
            }
        }

        // 간선 정렬 (삽입 정렬)
        for (int i = 1; i < edgeCount; i++) {
            Edge temp = edges[i];
            int j = i - 1;
            while (j >= 0 && edges[j].weight > temp.weight) {
                edges[j + 1] = edges[j];
                j--;
            }
            edges[j + 1] = temp;
        }

        // Kruskal MST 구성
        int parent[MAX_VTXS];
        for (int i = 0; i < size; i++) parent[i] = i;

        auto find = [](int parent[], int x) {
            while (x != parent[x]) x = parent[x];
            return x;
        };

        auto unite = [](int parent[], int x, int y) {
            parent[find(parent, x)] = find(parent, y);
        };

        cout << "Kruskal MST:" << endl;
        int totalWeight = 0, edgeUsed = 0;

        for (int i = 0; i < edgeCount && edgeUsed < size - 1; i++) {
            int u = edges[i].u, v = edges[i].v, weight = edges[i].weight;

            if (find(parent, u) != find(parent, v)) {
                unite(parent, u, v);
                edgeUsed++;
                totalWeight += weight;
                cout << "(" << vertices[u] << ", " << vertices[v] << ") with weight " << weight << endl;
            }
        }
        cout << "Total Weight: " << totalWeight << endl;
    }
};


    void Dijkstra(int start) {
        int dist[MAX_VTXS];
        bool visited[MAX_VTXS] = {false};
        int path[MAX_VTXS];

        for (int i = 0; i < size; i++) {
            dist[i] = INF;
            path[i] = -1;
        }
        dist[start] = 0;

        for (int i = 0; i < size; i++) {
            int u = -1, minDist = INF;

            for (int j = 0; j < size; j++) {
                if (!visited[j] && dist[j] < minDist) {
                    u = j;
                    minDist = dist[j];
                }
            }

            visited[u] = true;

            for (int v = 0; v < size; v++) {
                if (!visited[v] && adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    path[v] = u;
                }
            }
        }

        cout << "Dijkstra (Start: " << vertices[start] << "):" << endl;
        for (int i = 0; i < size; i++) {
            cout << vertices[start] << " to " << vertices[i] << ": Distance = " << dist[i] << ", Path = ";
            printPath(start, i, path);
            cout << endl;
        }
    }

    void printPath(int start, int end, int path[]) {
        if (end == start) {
            cout << vertices[start];
            return;
        }
        if (path[end] == -1) {
            cout << "No Path";
            return;
        }
        printPath(start, path[end], path);
        cout << " -> " << vertices[end];
    }

    void Floyd() {
        int dist[MAX_VTXS][MAX_VTXS];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                dist[i][j] = adj[i][j];

        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        cout << "Floyd:" << endl;
        cout << "    ";
        for (int i = 0; i < size; i++) cout << vertices[i] << "    ";
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << vertices[i] << " ";
            for (int j = 0; j < size; j++) {
                if (dist[i][j] == INF)
                    cout << " INF ";
                else
                    cout << " " << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 4, E = 5;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.Prim();
    g.Kruskal();
    g.Dijkstra(0); // Start at 'A'
    g.Floyd();
    return 0;
}
