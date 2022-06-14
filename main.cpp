#include <iostream>
#include <cstring>
#include <map>

typedef struct Node Node;
struct Node{
	char* data;
	Node* next;
};

/*class Vector{
public:
	Node* head = NULL;
	int length = 0;

	Vector(){
		
	}

	char* get(int index){
		Node* curr = head;
		while(index--){
			curr = curr->next;
			if(curr == NULL) std::cout << "WARNING: getting NULL value in LL\n";
		}
		return curr->data;
	}

	char* operator[](int index){
		return get(index);
	}

	void push(char* data){
		if(head == NULL){
			head = new Node();
			head->data = data;
			return;
		}

		Node* curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = new Node()
	}

};*/



/*
template <class T>
class Vector{
private:
public:
	int length = 0;
	int maxsize = 0;

	T* data = NULL;

	Vector(){
		data = NULL;
		length = 0;
		maxsize = 0;
	}

	int operator[](int index){
		return *(data + index);
	}

	int size(){
		return length;
	}

	void push(T item){
		//std::cout << this->length << "\n";
		this->length += 1;
		if(data == NULL){
			// first insert
			data = (T*) malloc(sizeof(T));
			memcpy((void*)data, &item, sizeof(T));
			maxsize = 1;
			return;
		}

		if(length + 1 > maxsize){
			// need to realloc
			maxsize *= 2;
			data = (T*) realloc(data, sizeof(T) * maxsize);
		}

		else{
			// don't need to realloc
			memcpy((data + length + 1), &item, sizeof(T));
		}
	}

	~Vector(){
		free(data);
	}


};
*/


class Edge;

class Vertex{
public:
	char* label;
	Vertex(char* label){
		this->label = label;
	}
	Vertex(){

	}


};

class Edge{
public:
	Vertex* a;
	Vertex* b;
	
	Edge(Vertex* a, Vertex* b){
		this->a = a;
		this->b = b;
	}

};




/*typedef Vector<Vertex*> node_list_t;
typedef int* adjacency_t;

void addNode(node_list_t*& nodes, adjacency_t*& adj_list, char* label){
	nodes->push(new Vertex(label));
	adj_list->push(new Vector<int>());
	std::cout << adj_list->size() << "\n";
	for(int i = 0; i < adj_list->size() -1; i++){
		adj_list->data[i]->push(0);
	}

	for(int i = 0; i < adj_list->size(); i++){
		adj_list->data[adj_list->size() - 1]->push(0);
	}

}

void addEdge(node_list_t*& nodes, adjacency_t*& adj_list, Vertex* a, Vertex* b, int weight){
	int firstIndex = 0;
	int secondIndex = 0;
	for(int i = 0; i < nodes->size(); i++){
		if(a == nodes->data[i]){
			firstIndex = i;
		}
		if(b == nodes->data[i]){
			secondIndex = i;
		}
	}

	adj_list->data[firstIndex]->data[secondIndex] = weight;
	adj_list->data[secondIndex]->data[firstIndex] = weight;
}

void print_adj(adjacency_t*& adj_list){
	for(int i = 0; i < adj_list->size(); i++){
		Vector<int>* v = adj_list->data[i];
		for(int j = 0; j < v->size(); j++){
			std::cout << v->data[j] << " ";
		}
		std::cout << "\n";
	}
}
*/

int addNode(int** adj, Vertex** nodeList, int& numNodes, char* label){
	nodeList[numNodes++] = new Vertex(label);
	return numNodes;
}

void removeNode(int** adj, int& numNodes, Vertex** nodes, int nodeNum){
	std::cout << "\n";
	for(int i = 0; i < numNodes; i++){
		adj[i][nodeNum] = 0;
		adj[nodeNum][i] = 0;
	}

	for(int i = 0; i < 20; i++){
		adj[nodeNum][i] = adj[numNodes - 1][i];
		adj[i][nodeNum] = adj[i][numNodes - 1];
		adj[numNodes-1][i] = 0;
	}

	nodes[nodeNum] = nodes[numNodes - 1];
	nodes[numNodes-1] = NULL;

	numNodes--;
}


void setEdge(int** adj, Vertex** nodeList, int& numNodes, int nodeA, int nodeB, int weight){
	adj[nodeA][nodeB] = weight;
	adj[nodeB][nodeA] = weight;	
}


void print_adj(int**& adj, int& numNodes, Vertex** nodeList){
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


int main(){
	int numNodes = 0;
	/*int** adjacencyMatrix = new int*[20];
	for(int i = 0; i < 20; i++){
		adjacencyMatrix[i] = new int[20]();
	}*/
	//int adjacencyMatrix[20][20];
	
	int** adjacencyMatrix = new int*[20];
	for(int i = 0; i < 20; i++){
		adjacencyMatrix[i] = new int[20];
	}

	Vertex* nodeList[20];


	while(1){
		std::cout << "Enter Command(V=Create Vertex, E=Create Edge, X=Remove Vertex, Y=Remove Edge, A=Adjancency Matrix): ";
		char cmd;
		std::cin >> cmd;
		switch(cmd){
			case 'V': {
				std::cout << "Vertex name: ";
				char* name = new char[256];
				std::cin >> name;
				addNode(adjacencyMatrix, nodeList, numNodes, name);
				break;
			};

			case 'E': {
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
			
			case 'X': {
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

			case 'Y': {
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

			case 'A': {
				print_adj(adjacencyMatrix, numNodes, nodeList);
				break;
			};


		}



	}



}
