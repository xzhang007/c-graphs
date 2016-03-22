#ifndef __GRAPH_H__
#define __GRAPH_H__

// graph.h
/*************************************
* Student name Xuan Zhang
* Student ID 916409525
* Email xzhang8@mail.sfsu.edu
* Compiler used to test program (including version) gcc version 4.9.3 (GCC)
*************************************/
#include "vertex.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Graph {
public:
	Graph();

	void addEdge(char, char);
	int vertexCount();
	bool vertexExists(char);
	bool pathExists(char, char);

private:
	void DFS(char, std::unordered_map<char, bool> &);	// we should pass map address, & is very important!
	void BFS(char, std::unordered_map<char, bool> &);

	std::vector<Vertex> vertices;
};

#endif