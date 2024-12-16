#include <iostream>
#include "Node.h"
#define MAX_VTXS 100


class AdjListGraph{

protected:
    int size;
    char vertices[MAX_VTXS]; // 정점 정보(응용에 따라 확장필요)
    Node *adj[MAX_VTXS];     // 각 정점의 인접리스트
public:
    AdjListGraph():size(0){}
    ~AdjListGraph() { reset(); }
    void reset(void){
        for (int i = 0; i < size;i++)
            if(adj[i]!=NULL)
                delete adj[i];
    }
    bool isFull() {
        return size >= MAX_VTXS;
    }

    void insertVertex(char val){
        if(!isFull()){
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else
            printf("error: 그래프 정점개수초과\n");
    }

    char getVertex(int i) {
        return vertices[i];
    }


    void insertEdge(int u, int v){
        // 정점 u의 인접리스트에 정점 v를 추가함
        adj[u] = new Node(v, adj[u]); 
        // 정점 v의 인접리스트에 정점 u를 추가함
        adj[v] = new Node(u, adj[v]); 
    }

    void display(){
        printf("%d\n", size);
        for (int i = 0; i < size;i++){
            printf("%c", getVertex(i));
            for (Node *v = adj[i]; v != NULL;v= v->getLink())
                printf("%c", getVertex(v->getId()));
            // printf("%3d",v->getId());
            printf("\n");
        }
    }

    Node *adjacent(int v) { return adj[v];}
};