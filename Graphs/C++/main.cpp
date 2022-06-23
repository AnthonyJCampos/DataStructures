
#include<iostream>
#include<vector>

#include "UndirectedMatrixGraph.h"



int main() {

   std::vector<std::vector<int>> matrix = { {0, 0, 0, 0, 0},
                                             {0, 0, 1, 1, 0},
                                             {0, 1, 0, 0, 1},
                                             {0, 1, 0, 0, 1},
                                             {0, 0, 0, 0, 0}, };

   std::vector<std::vector<int>> matrix1 = { {0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 1, 1, 1, 0, 0, 0},
                                         {0, 1, 0, 1, 0, 0, 0, 0},
                                         {0, 1, 1, 0, 1, 1, 0, 0},
                                         {0, 1, 0, 1, 0, 1, 0, 0},
                                         {0, 0, 0, 1, 1, 0, 1, 1},
                                         {0, 0, 0, 0, 0, 1, 0, 0},
                                         {0, 0, 0, 0, 0, 1, 0, 0} };



   //                                         0  1  2  3  4  5  6  7  8  9  10 11 12 13
   std::vector<std::vector<int>> matrix2 = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

   UndirectedMatrixGraph g1 (matrix2);
   UndirectedMatrixGraph g2 (matrix);

   std::cout << "Breadth First Searchs:" << std::endl;
   g2.breadthFirstSearch(1);

   std::cout << "\nDepth First Searchs:" << std::endl;

   std::cout << "\nNon Recursive" << std::endl;
   g2.depthFirstSearch(1);

   std::cout << "\nRecursive" << std::endl;
   g2.depthFirstSearchRecursive(1);

   std::cout << "\n\nShortest Path" << std::endl;

   g2.shortestPath(1);

   std::cout << "\nBREAK\n" << std::endl;



   


	return 0;


} // End of Main