#include "graph.h"
// graph.cpp
/*************************************
* Student name Xuan Zhang
* Student ID 916409525
* Email xzhang8@mail.sfsu.edu
* Compiler used to test program (including version) gcc version 4.9.3 (GCC)
*************************************/


using namespace std;

Graph::Graph() { }

void Graph::addEdge(char vertex1, char vertex2) {
	bool found1 = false;
	bool found2 = false;
	for (vector<Vertex>::size_type i = 0; (!found1 || !found2) && i < vertices.size(); i++) {	// logic should be correct
		if (vertices[i].getLabel() == vertex1) {
			vertices[i].addEdge(vertex2);
			found1 = true;
		}

		if (vertices[i].getLabel() == vertex2)
			found2 = true;
	}

	if (found1 == false) {	// don't forget if vertex has not been added
		vertices.push_back(vertex1);
		vertices[vertices.size() - 1].addEdge(vertex2);
	}

	if (found2 == false) 
		vertices.push_back(vertex2);
}

int Graph::vertexCount() {
	return vertices.size();
}

bool Graph::vertexExists(char vertex) {
	bool found = false;

	for (vector<Vertex>::size_type i = 0; !found && i < vertices.size(); i++) {
		if (vertices[i].getLabel() == vertex)
			found = true;
	}

	return found;
}

bool Graph::pathExists(char vertex1, char vertex2) {
	unordered_map<char, bool> visited;
	for (vector<Vertex>::size_type i = 0; i < vertices.size(); i++) {
		visited[vertices[i].getLabel()] = false;
	} 

	DFS(vertex1, visited);
	// BFS(vertex1, visited);
	if (visited[vertex2] == true)
		return true;
	else 
		return false;
}


void Graph::DFS(char vertex, unordered_map<char, bool> & visited) {	// we should pass map address, & is very important!
	visited[vertex] = true;
	// cout << vertex << endl;
	queue<char> myQueue;
	bool found = false;
	vector<char> edges;
	for (vector<Vertex>::size_type i = 0; !found && i < vertices.size(); i++) {
		if (vertices[i].getLabel() == vertex) {
			edges = vertices[i].getEdges();
			found = true;
		}
	} 
	for (vector<char>::size_type i = 0; i < edges.size(); i++) {
		if (visited[edges[i]] == false)	// this is very important, in case of loop 
			DFS(edges[i], visited);
	}
} 

void Graph::BFS(char vertex, unordered_map<char, bool> & visited) {
	visited[vertex] = true;
	// cout << vertex << endl;
	queue<char> myQueue;
	vector<char> edges;

	do {
		if (!myQueue.empty()) {
			vertex = myQueue.front();
			// cout << vertex << endl;
			myQueue.pop();
		}

		bool found = false;	// don't forget to set this in the loop!
		for (vector<Vertex>::size_type i = 0; !found && i < vertices.size(); i++) {
			if (vertices[i].getLabel() == vertex) {
				found = true;
				edges = vertices[i].getEdges();
			}
		}

		for (vector<char>::size_type i = 0; i < edges.size(); i++) {
			if (visited[edges[i]] == false) {
				visited[edges[i]] = true;
				// cout << edges[i] << endl;
				myQueue.push(edges[i]);
			}
		}
	} while (!myQueue.empty());
}