#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS	256
#define INF			9999

class WGraph
{
protected:
	int	size;					
	int	adj[MAX_VTXS][MAX_VTXS];
	int	data[MAX_VTXS];			
	char name[128];				

public:
	WGraph( )				{ size=0; }
	~WGraph(void)			{  }
	int& getEdge(int i, int j)	{ return adj[i][j]; }
	int& Vertex(int i)		{ return data[i]; }
	bool IsFull()			{ return size>=MAX_VTXS; }

	void AddVertex( int val ) {	
		if( !IsFull() ) data[size++] = val;
		else printf("그래프: 정점의 개수 초과\n");
	}
	void AddgetEdge( int u, int v, int weight) {
		if( weight == 0 && u != v ) weight = INF;
		getEdge(u,v) = getEdge(v,u) = weight;
	}
	void Load( FILE *fp = stdin ) {
		int n, val;
		fgets( name, 128, fp );			
		fscanf(fp, "%d", &n);			
		for(int i=0 ; i<n ; i++ ) {
			fscanf(fp, "%d", &val);
			AddVertex( val );			
			for(int j=0 ; j<n ; j++ ) {
				fscanf(fp, "%d", &val );
				if( i<=j )
					AddgetEdge( i, j, val);
			}
		}
	}
	void Print(const char *name="Graph", FILE *fp = stdout ) {
		fprintf(fp, "%s\n", name);			
		fprintf(fp, "%d\n", size);			
		for( int i=0 ; i<size ; i++ ) {		
			fprintf(fp," %3d ", Vertex(i));	
			for( int j=0 ; j<size ; j++ )	
				fprintf(fp, " %3d",
					(getEdge(i,j)<INF) ? getEdge(i,j): 0);
			printf("\n");
		}
	}
	void Load(const char *filename) {
		FILE *fp = fopen(filename, "r");
		if( fp != NULL ) {
			Load(fp);
			fclose(fp);
		}
	}
	void Store(const char *filename) {
		FILE *fp = fopen(filename, "w");
		if( fp != NULL ) {
			Print( name, fp );
			fclose(fp);
		}
	}
};




