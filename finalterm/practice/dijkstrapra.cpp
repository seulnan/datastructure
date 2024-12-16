#include <stdio.h>
#include <string.h>

#define MAX_VTXS 100
#define INF 9999

char vertices[MAX_VTXS];
int adj[MAX_VTXS][MAX_VTXS];
int size = 0;

char getVertex(int i) { return vertices[i]; }
int getEdge(int i, int j) { return adj[i][j]; }
void insertEdge(int i, int j, int val) { adj[i][j] = val; }
bool isFull() { return size >= MAX_VTXS; }

void insertVertex(char name){
    if(!isFull()) 
        vertices[size++] = name;
    else
        printf("error:더이상정점추가못함\n");

}

class WGraphDijkstra{
    int path[MAX_VTXS];
    int dist[MAX_VTXS];
    int found[MAX_VTXS];
public:
    WGraphDigkstra() {}
    ~WGraphDigkstra() {}

    void PrintDistance(){
        for (int i = 0; i < size;i++)
            printf("%c: %d", getVertex(i), dist[i]);
        printf("\n");
    }

    void PrintPath(int start, int end){
        printf("[최단경로: %c<-%c] %c", getVertex(start), getVertex(end), getVertex(end));
        while(path[end]!=start){
            print("-%c", getVertex(path[end]));
            end = path[end];
        }
        print("-%c\n", getVertex(path[end]));
    }

    int chooseVertex(){
        int min = INF;
        int minpos = -1;
        for (int i = 0; i < size; i++){
            if(dist[i]<min && !found[i]){
                min = dist[i];
                minpos = i;
            }
        }
        return minpos;
    }

    void ShortestPath(int start){
        // 초기화 작업
        for (int i = 0; i < size; i++){
            dist[i] = getEdge(start, i);
            path[i] = start;
            found[i] = 0;
        }
        found[start] = 1;
        dist[start] = 0;

        for (int i = 0; i < size;i++){
            int u = chooseVertex();
            found[u] = 1;

            for (int w = 0; w < size;w++){
                if(!found[w]&&dist[u]+getEdge(u,w)<dist[w]){
                    dist[w] = dist[u] + getEdge(u, w);
                    path[w] = u;
                }
            }
        }
    }

    void display(){
        printf("사이즈%d\n", size);
        for (int i = 0; i < size;i++){
            printf("%c", getVertex(i));
            for (int j = 0; j < size;j++){
                printf("%c", getEdge(i, j));
            }
            printf("\n");
        }
    }
};

int main(){
    for (int i = 0; i < MAX_VTXS;i++){
        for (int j = 0; j < MAX_VTXS;j++){
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }

    insertVertex('A');
    insertVertex('B');
    insertVertex('C');
    insertVertex('D');

    insertEdge(0, 1, 10);
    insertEdge(0, 2, 15); // A-C: 15
    insertEdge(1, 3, 12); // B-D: 12
    insertEdge(2, 3, 10); // C-D: 10

        // 그래프 출력
    printf("그래프 인접 행렬:\n");
    
    // 결과 출력
    printf("\n최단 거리 출력:\n");
    graph.PrintDistance();

    printf("\n경로 출력 (A -> D):\n");
    graph.PrintPath(0, 3); // A -> D 경로 출력

    // Floyd 알고리즘 실행
    int A[MAX_VTXS][MAX_VTXS];
    ShortestPathFloyd(adj, A, size);
        // 최단 거리 행렬 출력
    printf("모든 정점 쌍 최단 거리 행렬:\n");
    printA(A, vertices, size);

    return 0;
}
