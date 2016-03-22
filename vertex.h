#ifndef __VERTEX_H__
#define __VERTEX_H__

// vertex.h
/*************************************
* Student name Xuan Zhang
* Student ID 916409525
* Email xzhang8@mail.sfsu.edu
* Compiler used to test program (including version) gcc version 4.9.3 (GCC)
*************************************/
#include <iostream> 
#include <vector>


class Vertex {
public:
	 Vertex(char);

	 void addEdge(char);
	 char getLabel();
	 const std::vector<char> getEdges();

private:
	std::vector<char> edges;
	char label;
};


#endif