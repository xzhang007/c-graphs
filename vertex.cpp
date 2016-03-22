#include "vertex.h"
// Vertex.cpp
/*************************************
* Student name Xuan Zhang
* Student ID 916409525
* Email xzhang8@mail.sfsu.edu
* Compiler used to test program (including version) gcc version 4.9.3 (GCC)
*************************************/

using namespace std;

Vertex::Vertex(char vername): label(vername) { }

void Vertex::addEdge(char vername) {
		edges.push_back(vername);
}

char Vertex::getLabel() {
	return label;
}

const vector<char> Vertex::getEdges() {
	return edges;
}



