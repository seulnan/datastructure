#include <iostream>
#define MAX_VTXS 100
#define INF 9999


class Dijkstra{

protected:
    int size=0;
    char vertices[MAX_VTXS]; // 정점 정보(응용에 따라 확장필요)
    int adj[MAX_VTXS][MAX_VTXS]; // 각 정점의 인접리스트
public:
    AdjMatGraph() { reset(); }
    char getVertex(int i) { return vertices[i]; }
    int getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val){adj[i][j]=val;}
    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }

    void reset(){
        size = 0;
        for (int i = 0; i < MAX_VTXS; i++)
            for (int j = 0; j < MAX_VTXS; j++)
                setEdge(i, j, 0);
    }

    void insertVertex(char name){
        if(!isFull())
            vertices[size++] = name;
        else
            printf("error: 그래프정점개수 초과\n");
    }

    void insertEdge(int u, int v){
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    void display(FILE *fp= stdout){
        fprintf(fp, "%d\n", size);
        for (int i = 0; i < size;i++){
            fprintf(fp, "%c", getVertex(i));
            for (int j = 0; j < size;j++)
                fprintf(fp, "%3d", getEdge(i, j));
            fprintf(fp, "\n");
        }
    }
};