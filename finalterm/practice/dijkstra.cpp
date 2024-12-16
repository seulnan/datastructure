#include <stdio.h>
#include <string.h>

#define MAX_VTXS 100
#define INF 9999

// 정점과 간선 관리
char vertices[MAX_VTXS];        // 정점을 저장
int adj[MAX_VTXS][MAX_VTXS];    // 가중치 인접 행렬
int size = 0;                   // 정점의 수


// 정점 이름 가져오기
char getVertex(int i) { return vertices[i]; }
// 간선의 가중치 가져오기
int	 getEdge(int i, int j) { return adj[i][j]; }

void setEdge(int i, int j, int val) { adj[i][j] = val; }
bool isFull() { return size >= MAX_VTXS; }

// 정점 추가
void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else printf("Error: 더이상 정점 추가못함\n");
	}
    
void insertEdge( int u, int v, int weight ) {
		if( weight == INF ) weight = INF;
		setEdge(u, v, weight);
	}    

// WGraphDijkstra 클래스
class WGraphDijkstra {
    int path[MAX_VTXS];  // 특정 정점으로 가는 경로 저장
    int dist[MAX_VTXS];  // 시작점에서 각 정점까지의 최소 거리
    int found[MAX_VTXS]; // 정점이 최단 경로에 포함되었는지 여부

public:
    WGraphDijkstra() { }
    ~WGraphDijkstra() { }

    // 최단 거리 출력
    void PrintDistance() {
        for (int i = 0; i < size; i++)
            printf("%c: %d ", getVertex(i), dist[i]);
        printf("\n");
    }

    // 최단 경로 출력
    void PrintPath(int start, int end) {
        printf("[최단 경로: %c<-%c] %c", getVertex(start), getVertex(end), getVertex(end));
        while (path[end] != start) {
            printf("-%c", getVertex(path[end]));
            end = path[end];
        }
        printf("-%c\n", getVertex(path[end]));
    }

    // min 현재 발견된 가장 작은 거리값 저장
	// minpos 최소거리의 정점 번호 저장
    // 방문하지 않은 정점 중 최소 거리 선택
    int chooseVertex() {
        int min = INF;
        int minpos = -1;
        for (int i = 0; i < size; i++) {
            if (dist[i] < min && !found[i]) {
                min = dist[i];
                minpos = i;
            }
        }
        return minpos;
    }

    // 다익스트라 알고리즘
    void ShortestPath(int start) {
        // 초기화 작업
        for (int i = 0; i < size; i++) {
            dist[i] = getEdge(start, i); // 시작점에서 i까지의 초기 거리 설정
            path[i] = start;            // 초기 경로를 시작점으로 설정
            found[i] = 0;               // 모든 정점을 방문하지 않은 상태로 초기화
        }
        found[start] = 1;
        dist[start] = 0;

        // 모든 정점 탐색
        for (int i = 0; i < size; i++) {
            int u = chooseVertex(); // 방문하지 않은 정점 중 최소 거리 선택
            found[u] = 1;           // 선택된 정점을 방문한 것으로 설정

            // 선택된 정점으로부터 다른 정점의 거리 갱신
            for (int w = 0; w < size; w++) {
                if (!found[w] && dist[u] + getEdge(u, w) < dist[w]) {
                    dist[w] = dist[u] + getEdge(u, w); // 최소 거리 갱신
                    path[w] = u;                       // 경로 갱신
                }
            }
        }
    }
    
    void display() {
    printf("%d\n", size); // 정점의 개수를 출력
    for (int i = 0; i < size; i++) {
        printf("%c  ", getVertex(i)); // 정점 이름 출력
        for (int j = 0; j < size; j++) {
            printf(" %3d", getEdge(i, j)); // 간선의 가중치 출력
        }
        printf("\n"); // 한 줄 출력 후 개행
    }}

    // void display(FILE *fp = stdout) {
	// 	fprintf(fp, "%d\n", size);
	// 	for (int i = 0; i<size; i++) {
	// 		fprintf(fp, "%c  ", getVertex(i));
	// 		for (int j = 0; j<size; j++)
	// 			fprintf(fp, " %3d", getEdge(i, j));
	// 		fprintf(fp, "\n");
	// 	}
	// }
};

int main() {
    // 초기화: 인접 행렬을 INF로 설정
    for (int i = 0; i < MAX_VTXS; i++) {
        for (int j = 0; j < MAX_VTXS; j++) {
            adj[i][j] = (i == j) ? 0 : INF; // 대각선은 0, 나머지는 INF
        }
    }

    // 정점 추가
    insertVertex('A');
    insertVertex
    ('B');
    insertVertex('C');
    insertVertex('D');

    // 간선 추가 (가중치 그래프)
    insertEdge(0, 1, 10); // A-B: 10
    insertEdge(0, 2, 15); // A-C: 15
    insertEdge(1, 3, 12); // B-D: 12
    insertEdge(2, 3, 10); // C-D: 10

    // 그래프 출력
    printf("그래프 인접 행렬:\n");


    // 다익스트라 실행
    WGraphDijkstra graph;
    graph.display();
    graph.ShortestPath(0); // A를 시작 정점으로 설정

    // 결과 출력
    printf("\n최단 거리 출력:\n");
    graph.PrintDistance();

    printf("\n경로 출력 (A -> D):\n");
    graph.PrintPath(0, 3); // A -> D 경로 출력

    return 0;
}
