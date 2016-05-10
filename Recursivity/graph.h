#ifndef __GRAPH_H__
#define	__GRAPH_H__

#include "dynarray.h"

typedef unsigned int uint;

template<class T>

class Graph {
	// Vertex ---
public:
	struct Vertex {
		T data;
		DynArray<Vertex*> edges;

		Vertex(const T& value) : data(value) {}
		bool AddEdge(Vertex* other) {
			bool is_once = false;
			for (int i = 0; i < edges.n_size() && is_once == false; i++) {
				if (edges[i] == other)
					is_once = true;
			}

			if (is_once == false)
				edges.push_back(other);
			
			return !is_once;
		}
	};

public:
	DynArray<Vertex*> vertices;

public:
	Graph(){}
	virtual ~Graph(){}

	// Push() ---
	Vertex* Push(const T& value = NULL) {
		Vertex* newvert = new Vertex(value);
		vertices.push_back(newvert);

		return newvert;
	}

	// Size() ---
	uint size() const {
		return vertices.n_size();
	}

	// Empty() ---
	const bool empty() const {
		return (vertices.n_size() ? false : true);
	}

	// Clear() ---
	void clear() {
		vertices.clear();
	}

};

#endif // __GRAPH_H__