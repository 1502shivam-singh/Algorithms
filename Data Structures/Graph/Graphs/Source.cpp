#include <iostream>
#include <list>
#include <array>
#include <vector>
/*
graphNode in it self is a good set structure
Constructor needs	
	1) user must enter id and data or meaningless node
	2) color set to 0 (white) initially considered unvisited, can be provided for special case
	3) AdjList can be provided if finalised, or can be entered later by stepwise insertion (insertAdjNode() function)
*/

template<typename T>
class graphNode {
private:	
	
	bool color = 0;
	
	int dist;
	
public:
	std::list<graphNode*> AdjList;
	T data;
	int id;
	graphNode(int id, T data) :id(id), data(data) {};
	graphNode(int id, T data, const std::list<graphNode*>& AdjList) :id(id), AdjList(AdjList), data(data) {};
	graphNode(int id, T data, const std::list<graphNode*>& AdjList, bool color) :id(id), AdjList(AdjList), color(color) , data(data) {};

	void insertAdjNode(graphNode* node) {
		AdjList.emplace_back(node, ...);
	}
};

/*
graph - 
	contains graphNodes connected via the adjList,
	so when we define a graph class, it has 
	A data structure to store pointers to individual graphNodes, that have linked lists of pointers to different nodes.
*/
template<typename T>
class graph {
	friend graphNode<T>;
private:
	std::vector<graphNode<T>*> graphList;
public:
	graph() {};
	graph(const std::vector<graphNode<T>*>& graphList) :graphList(graphList) {};
	graph(const std::vector<graphNode<T>*>& graphList, size_t size) :graphList(graphList) {		//Space efficient choice, if number of nodes is known
		graphList.reserve(size);
	};

	void insertNode(graphNode<T>* node) {
		graphList.emplace_back(node);
	}

	void printGraph() {
		for (auto i : graphList) {
			std::cout << i->data << "\n";
			std::cout << i->id << "\n";
		}
	}

	~graph() {
		graphList.clear();
		std::cout << "clear";
	}
};

int main() {
	graph<int> graph;
	for (int i = 0; i < 10; i++) {
		graphNode<int>* node = new graphNode<int>(i, i * 10);
		graph.insertNode(node);
	}
	graph.printGraph();
	std::cin.get();
}