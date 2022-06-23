#pragma once

#include<vector>
#include<queue>
#include<stack>
#include<iostream>



class UndirectedMatrixGraph{


public:

	
	// Constructors
	UndirectedMatrixGraph(int vertices, int edges);

	UndirectedMatrixGraph(const std::vector<std::vector<int>>& matrix);

	// Mutators

	void breadthFirstSearch(int startVertex) const;

	void shortestPath(int startVertex) const;

	void depthFirstSearch(int startVertex) const;


	void depthFirstSearchRecursive(int startVertex) const;



private:


	// Graph Matrix
	std::vector<std::vector<int>> matrix_;

	void dfsRecursive(int startVertex, std::vector<bool>& visited) const;

}; // End Of UndirectedMatrixGraph

