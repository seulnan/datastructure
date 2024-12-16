#pragma once

class WGraphDijkstra : 
{
	static int		path[MAX_VTXS]; // 특정 정점으로 가는 경로 저장
	static int		dist[MAX_VTXS]; // 시작점에서 각 정점까지의 최소거리
	static int		found[MAX_VTXS]; // 정점이 최단 경로에 포함되었는지 여부 저장
public:
	WGraphDijkstra(void) { }
	~WGraphDijkstra(void) { }

	void PrintDistance() {
		for (int i = 0; i<size; i++)
		// 모든 정점의 거리를 출력하기 위해
			printf("%5d", dist[i]);
		printf("\n");
	}

	// start에서 end까지의 최단 경로를 역추적하려 출력
	void PrintPath(int start, int end) {
		printf("[최단경로: %c<-%c] %c", getVertex(start), getVertex(end), getVertex(end));
		// end에서 출발정점 start까지 경로를 역순으로 따라감
		while (path[end] != start) {
			printf("-%c", getVertex(path[end]));
			end = path[end];
		}
		printf("-%c\n", getVertex(path[end]));
	}

	// min 현재 발견된 가장 작은 거리값 저장
	// minpos 최소거리의 정점 번호 저장
	int chooseVertex() {
		int min = INF;
		int minpos = -1;
		for (int i = 0; i<size; i++)
			if (dist[i]< min && !found[i]) {
				min = dist[i];
				minpos = i;
			}
		return minpos;
	}

	// 초기화 작업 수행
	void ShortestPath(int start) {

		for (int i = 0; i<size; i++) {
			// 시작점에서 i번째까지의 초기거리 설정
			dist[i] = getEdge(start, i);
			// 경로 초기화, 모든 정점의 이전 정점은 start로
			path[i] = start;
			// 모든정점을 아직 방문하지않은 상태로
			found[i] = 0;
		}
		found[start] = 1;
		dist[start] = 0;

		for (int i = 0; i<size; i++) {
			/// 방문하지않은 정점중 최소거리를 가진 정점 선택
			int u = chooseVertex();
			// 선택된 정점을 방문한것으로 설정
			found[u] = 1;


			// 모든 정점 확인
			for (int w = 0; w<size; w++) {
				// 방문하지않은 정점이면
				if (found[w] == 0) {
					// 현재 선택된 정점 u까지의 거리 + u에서 w까지의 가중치 < w까지의 거리
					if (dist[u] + getEdge(u, w) < dist[w]) {
						// 짧은걸로 갱신
						dist[w] = dist[u] + getEdge(u, w);

						path[w] = u;
					}
				}
			}
		}
	}
};