#include "UndirectedMatrixGraph.h"



// Constructors
UndirectedMatrixGraph::UndirectedMatrixGraph(int vertices, int edges) {

	// resizing 2d vector according to required space only
	matrix_.resize(vertices, std::vector<int>(edges));

} // End of Constructor


UndirectedMatrixGraph::UndirectedMatrixGraph(const std::vector<std::vector<int>>& matrix)
: matrix_(matrix){} // End of Constructor


void UndirectedMatrixGraph::breadthFirstSearch(int startVertex) const{
	
	std::cout << "Vertex:" << startVertex << " -> ";
	int vertices = matrix_.size();
	std::vector<bool> visited(vertices, false);

	std::cout << startVertex;
	visited[startVertex] = true;

	std::queue<int> queue;

	queue.emplace(startVertex);

	while (!queue.empty()) {

		int curVert = queue.front();
		queue.pop();

		for (int vertex = 1; vertex < vertices; ++vertex) {

			if (matrix_[curVert][vertex] == 1 && !visited[vertex]) {

				std::cout << " " << vertex;

				visited[vertex] = true;
				queue.emplace(vertex);

			} // End if


		} // End while

	} // End while

	std::cout << std::endl;

} // End of breadthFirstSearch


void UndirectedMatrixGraph::shortestPath(int startVertex) const {
	
	std::cout << "Source Vertex:" << startVertex << " -> ";
	const int vertices = matrix_.size();
	std::vector<bool> visited(vertices, false);

	// mark startVertex visited
	visited[startVertex] = true;

	// initial vertex position 
	std::queue<int> queue{};
	queue.emplace(startVertex);

	// distance 
	std::vector<int> distance(vertices, -1);

	// previous vertex
	std::vector<int> previousV(vertices, 0);
	previousV[startVertex] = startVertex;

	// distance to itself is zero
	distance[startVertex] = 0;

	while (!queue.empty()) {

		int curVert = queue.front();
		queue.pop();

		for (int vertex = 1; vertex < vertices; ++vertex) {

			if (matrix_[curVert][vertex] == 1 && !visited[vertex]) {

				if (distance[vertex] == -1) {

					distance[vertex] = 0;

				} // end if

				visited[vertex] = true;
				distance[vertex] = distance[curVert] + 1;
				previousV[vertex] = curVert;

				queue.emplace(vertex);

			} // end if

		} // End for

	} // End of while

	std::cout << "\nDistance from " << startVertex << ": " << std::endl;

	for (int i = 1; i < vertices; ++i) {

		std::cout << "Distance to " << i << " is " << distance[i];
		std::cout << " from path " << previousV[i] << std::endl;

	} // End for

} // End of shortestPath


void UndirectedMatrixGraph::depthFirstSearch(int startVertex) const {
	
	std::cout << "Vertex:" << startVertex << " -> ";

	int vertices = matrix_.size();
	std::vector<bool> visited(vertices, false);

	std::cout << startVertex;


	std::stack<int> stack;

	visited[startVertex] = true;
	stack.push(startVertex);

	while (!stack.empty()) {

		int x = stack.top();

		for (int vertex = 1; vertex < vertices; ++vertex) {
	
			// this search is complete
			if ((vertices - 1) == vertex) {

				if ((matrix_[x][vertex] == 1 && visited[vertex]) || matrix_[x][vertex] == 0) {
					
					stack.pop();

				} // End if
			
			} // End if
			
			if (matrix_[x][vertex] == 1 && !visited[vertex]) {

				std::cout << " " << vertex;

				visited[vertex] = true;
				stack.push(vertex);

				// stop search
				vertex = vertices;

			} // End if

		} // End for

	} // End while

	std::cout << std::endl;

} // End of depthFirstSearch


void UndirectedMatrixGraph::depthFirstSearchRecursive(int startVertex) const {

	std::cout << "Vertex:" << startVertex << " ->";

	int vertices = matrix_.size();
	std::vector<bool> visited(vertices, false);
	
	dfsRecursive(startVertex, visited);


} // End of depthFirstSearchRecursive


void UndirectedMatrixGraph::dfsRecursive(int startVertex, std::vector<bool>& visited) const {

	if (!visited[startVertex]) {
		
		std::cout << " " << startVertex;
		visited[startVertex] = true;

		for (unsigned int vertex = 1; vertex < matrix_.size(); ++vertex) {

			if (matrix_[startVertex][vertex] == 1 && !visited[vertex]) {

				dfsRecursive(vertex, visited);

			} // End if

		} // End for
		
	} // End if

} // End of dfsRecursive
