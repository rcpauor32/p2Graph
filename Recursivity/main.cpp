#include <stdio.h>
#include "graph.h"

int main() {

	Graph<char> graph1;

	printf("\nGraph1 Properties:\n  Size: %d\n  Empty: %s", graph1.size(), graph1.empty() ? "true :>" : "false :<");

	Graph<char>::Vertex* a = graph1.Push('A');
	Graph<char>::Vertex* b = graph1.Push('B');
	Graph<char>::Vertex* c = graph1.Push('C');
	Graph<char>::Vertex* d = graph1.Push('D');

	a->AddEdge(a);
	a->AddEdge(b);
	b->AddEdge(c);
	c->AddEdge(b);

	printf("\n\nGraph1 Properties:\n  Size: %d\n  Empty: %s", graph1.size(), graph1.empty() ? "true :>" : "false :<");

	graph1.clear();

	getchar();
	return 0;
}