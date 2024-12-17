#include <stdio.h>
#include <string.h>

#define MAX_VTXS 100
#define INF 9999

char vertices[MAX_VTXS];
int adj[MAX_VTXS][MAX_VTXS];
int size = 0;

int setEdge(int i, int j, int weight) { adj[i][j] = weight; }

void insertVertex(char name){return vertices[size++] = name;}

void insertEdge(int u, int v, int weight){
    setEdge(u, v, weight);
    setEdge(v, u, weight);
}

class WDijkstra{
    int path[MAX_VTXS];
    int dist[MAX_VTXS];
    int found[MAX_VTXS];

public:
    WDijkstra(){
        for (i = 0; i < MAX_VTXS;i++){
            for (j = 0; j < MAX_VTXS;j++){
                adj[i][j] = (i == j) ? 0 : INF;
            }
        }
    }
    ~WDijkstra(){}
    
    void display(){
        printf("%c\n", size);
        for (int i=0; i<size;i++){
            for(int j=0)
        }
    }

    int ShortestPath
};

int main(){
    
    insertVertex('A');
    insertVertex('B');
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
}