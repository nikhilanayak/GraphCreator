#include <iostream>
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

void addEdge(int** adj, Vertex** nodeList, int& numNodes, int nodeA, int nodeB, int weight){
	adj[nodeA][nodeB] = weight;
	adj[nodeB][nodeA] = weight;	
}


void print_adj(int**& adj, int& numNodes){
	for(int i = 0; i < numNodes; i++){
		for(int j = 0; j < numNodes; j++){
			std::cout << adj[i][j] << " ";
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

	int a  = addNode(adjacencyMatrix, nodeList, numNodes, (char*)"a");
	int b  = addNode(adjacencyMatrix, nodeList, numNodes, (char*)"b");

	addEdge(adjacencyMatrix, nodeList, numNodes, 0, 1, 100);

	print_adj(adjacencyMatrix, numNodes);

}
