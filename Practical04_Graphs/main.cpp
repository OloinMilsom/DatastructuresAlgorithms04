
#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;


typedef GraphArc<int, int> Arc;
typedef GraphNode<int, int> Node;

void visit( Node * pNode ) {
	cout << "Visiting: " << pNode->data() << endl;
}

int main(int argc, char *argv[]) {
   
	Graph<int, int> graph(25);
	
	int c = 0;
	int i = 0;
	ifstream myfile;
	myfile.open ("Q2Nodes.txt");

	while ( myfile >> c ) {
		graph.addNode(c, i++);
	}

	myfile.close();
	myfile.open("Q2Arcs.txt");

	int from, to, weight;
	while ( myfile >> from >> to >> weight ) {
		graph.addArc(from, to, weight);
	}
    myfile.close();

	// Now traverse the graph.
	//graph.breadthFirst( graph.nodeArray()[0], visit );
	graph.breadthFirstSearch(graph.nodeArray()[23], graph.nodeArray()[15], visit);

	system("PAUSE");
	
}
