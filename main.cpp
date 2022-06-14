/*
 Implementation of the graph datatype in C++
 Nikhil Nayak
 June 14, 2022
 */


// headers
#include <iostream>
#include <cstring>
#include <map>



class Vertex{ // vertex of the graph
public:
	char* label;
	Vertex(char* label){
		this->label = label;
	}
	Vertex(){

	}


};

int addNode(int** adj, Vertex** nodeList, int& numNodes, char* label){ // adds a node to the list and adj matrix
	nodeList[numNodes++] = new Vertex(label);
	return numNodes;
}

void removeNode(int** adj, int& numNodes, Vertex** nodes, int nodeNum){ // removes a node from the list and adj matrix
	std::cout << "\n";
	for(int i = 0; i < numNodes; i++){ 
		adj[i][nodeNum] = 0;
		adj[nodeNum][i] = 0;
	}

	for(int i = 0; i < 20; i++){ // shift the adj matrix
		adj[nodeNum][i] = adj[numNodes - 1][i];
		adj[i][nodeNum] = adj[i][numNodes - 1];
		adj[numNodes-1][i] = 0;
	}

	nodes[nodeNum] = nodes[numNodes - 1]; // shift the list
	nodes[numNodes-1] = NULL;

	numNodes--; // decrement the length
}


void setEdge(int** adj, Vertex** nodeList, int& numNodes, int nodeA, int nodeB, int weight){ // sets an edge to "weight". If weight is 0, effectively removes the edge
	adj[nodeA][nodeB] = weight;
	adj[nodeB][nodeA] = weight;	
}


void print_adj(int**& adj, int& numNodes, Vertex** nodeList){ // prints the adj matrix
	printf("%10s ", "");
	for(int i = 0; i < numNodes; i++){
		printf("%10s", nodeList[i]->label);
	}
	printf("\n");

	for(int i = 0; i < numNodes; i++){
		printf("%10s ", nodeList[i]->label);
		for(int j = 0; j < numNodes; j++){
			printf("%10i", adj[i][j]);
			//std::cout << adj[i][j] << " ";
		}
		std::cout << "\n";
	}
}


int main(){ // main fn
	int numNodes = 0;
		
	int** adjacencyMatrix = new int*[20];
	for(int i = 0; i < 20; i++){
		adjacencyMatrix[i] = new int[20];
	}

	Vertex* nodeList[20];


	while(1){ // get input, parse, run command accordingly
		std::cout << "Enter Command(V=Create Vertex, E=Create Edge, X=Remove Vertex, Y=Remove Edge, A=Adjancency Matrix): ";
		char cmd;
		std::cin >> cmd;
		switch(cmd){
			case 'V': { // new vertex
				std::cout << "Vertex name: ";
				char* name = new char[256];
				std::cin >> name;
				addNode(adjacencyMatrix, nodeList, numNodes, name);
				break;
			};

			case 'E': { // new edge
				std::cout << "Vertex A name: ";
				char* aName = new char[256];
				std::cin >> aName;

				std::cout << "Vertex B name: ";
				char* bName = new char[256];
				std::cin >> bName;

				int indA = -1;
				int indB = -1;

				
				for(int i = 0; i < numNodes; i++){
					if(strcmp(aName, nodeList[i]->label) == 0){
						indA = i;
					}
					if(strcmp(bName, nodeList[i]->label) == 0){
						indB = i;
					}

				}

				if(indA == -1 || indB == -1){
					std::cout << "Could not find one (or more) nodes.\n";
					break;
				}

				std::cout << "Weight: ";
				int weight;
				std::cin >> weight;

				setEdge(adjacencyMatrix, nodeList, numNodes, indA, indB, weight);
				break;
			};
			
			case 'X': { // remove vertex
				std::cout << "Vertex name: ";
				char* vertexName = new char[256];
				std::cin >> vertexName;
				//removeNode(adjacencyMatrix, nodeList, numNodes, vertexName);
				
				int vertexNum = -1;
				for(int i = 0; i < numNodes; i++){
					if(strcmp(vertexName, nodeList[numNodes]->label) == 0){
						vertexNum = i;	
					}
				}

				if(vertexNum == -1){
					std::cout << "Could not find node\n";
				}

				removeNode(adjacencyMatrix, numNodes, nodeList, vertexNum);
				break;
			};

			case 'Y': { // remove edge
				std::cout << "Vertex A name: ";
				char* aName = new char[256];
				std::cin >> aName;

				std::cout << "Vertex B name: ";
				char* bName = new char[256];
				std::cin >> bName;

				int indA = -1;
				int indB = -1;

				
				for(int i = 0; i < numNodes; i++){
					if(strcmp(aName, nodeList[i]->label) == 0){
						indA = i;
					}
					if(strcmp(bName, nodeList[i]->label) == 0){
						indB = i;
					}

				}

				if(indA == -1 || indB == -1){
					std::cout << "Could not find one (or more) nodes.\n";
					break;
				}

				setEdge(adjacencyMatrix, nodeList, numNodes, indA, indB, 0);

				break;
			};

			case 'A': { // print adj matrix
				print_adj(adjacencyMatrix, numNodes, nodeList);
				break;
			};


		}
	}
}
