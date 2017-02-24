#include"graph.h"
#include<stdio.h>

#define UNVISITED 0
#define VISITED 1

using namespace std;

int Graph::verticesNum(){}
int Graph::edgesNum(){}
void Graph::visit(Graph &g, int v){}
Edge Graph::firstEdge(int oneVertice){}
Edge Graph::nextEdge(Edge preEdge){}
bool Graph::setEdge(int fromVertice, int toVertice, int weight){}
bool Graph::delEdge(int fromVertice, int toVertice){}
bool Graph::isEdge(Edge oneEdge){}
int Graph::fromVertice(Edge oneEdge){}
int Graph::ToVertice(Edge oneEdge){}
int Graph::weight(Edge oneEdge){}
void Graph::traverse(Graph &g) {
	//set each node to be unvisited
	for (int i = 0; i < g.verticesNum(); ++i) {
		g.mark[i] = UNVISITED;
		for (int i = 0; i < g.verticesNum(); ++i) {
			if (g.mark[i] == UNVISITED) {
				DFS(g, i);
				BFS(g, i);
			}

		}
	}
}
	void Graph::DFS(Graph &g,int v) {
		g.mark[v] = VISITED;
		visit(g, v);
		for (Edge e = g.firstEdge(v); g.isEdge(e); e = g.nextEdge(e)) {
			if (g.mark[g.ToVertice(e)] == UNVISITED)
				DFS(g, g.ToVertice);
		}
		postVisit(g, v);
	}
