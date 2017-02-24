#pragma once
class Edge {
public:
	int from;
	int to;
	int weight;
	Edge() {
		from = -1; to = -1; weight = 0;
	}
	Edge(int f, int t, int w) {
		from = f;
		to = t;
		weight = w;
	}
};
class Graph {
public:
	int numVertice;
	int numEdge;
	int *mark;
	int *indegree;

	int verticesNum();
	int edgesNum();
	void visit(Graph &g, int v);
	Edge firstEdge(int oneVertice);
	Edge nextEdge(Edge preEdge);
	bool setEdge(int fromVertice, int toVertice, int weight);
	bool delEdge(int fromVertice, int toVertice);
	bool isEdge(Edge oneEdge);
	int fromVertice(Edge oneEdge);
	int ToVertice(Edge oneEdge);
	int weight(Edge oneEdge);
	void traverse(Graph &g);
	void DFS(Graph &g,int v);
	void BFS(Graph &g,int v);
};