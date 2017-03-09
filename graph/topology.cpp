#include<stdio.h>
#include"graph.h"
#include<queue>
#include<iostream>
#define UNVISITED 0
#define VISITED 1
using namespace std;

void Graph::visit(Graph &g, int v) {}

int *topology(Graph &G) {
	//initialize
	for (int i = 0; i < G.verticesNum(); ++i)
		G.mark[i] = UNVISITED;
	int *res = new int[G.verticesNum()];
	int index = 0;
	//do recursion on each vertice
	for (int i = 0; i < G.verticesNum(); ++i) {
		if (G.mark[i] = UNVISITED)
			DFS(G, i, result, index);
	}
	//visit vertices reversely
	for (int i = G.verticesNum() - 1; i >= 0; --i) {
		//visit(G, res[i]);
	}
	return res;
}
void DFS(Graph& G, int v, int *res, int index) {
	G.mark[v] = VISITED;
	for (Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e)) {
		if (G.mark[G.ToVertice(e)] == UNVISITED) {
			DFS(G, G.ToVertice(e), res, index);
		}
	}
	res[index++] = v;
}
//topology implemented by queue
void topologyByQueue(Graph &G) {
	for (int i = 0; i < G.verticesNum(); ++i)
		G.mark[i] = UNVISITED;
	queue<int> q;
	//push vertices whose indegree is 0 into queue
	for (int i = 0; i < G.verticesNum(); ++i) {
		if (G.indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()){
		int v = q.front();
		q.pop();
		//visit(G, v);
		G.mark[v] = VISITED;
		for (Edge e = G.firstEdge(v); G.isEdge(e); e = G.nextEdge(e)) {
			G.indegree[G.ToVertice(e)]--;
			if (G.indegree[G.ToVertice(e)] == 0)
				q.push(G.ToVertice(e));
		}
	}
	//判断图中是否有环,如果此时图中还有顶点未被访问，则说明有环
	for (int i = 0; i < G.verticesNum(); ++i) {
		if (G.mark[i] == UNVISITED) {
			cout << "此图有环";
			break;
		}
	}

}