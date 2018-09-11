#pragma once
#include "Node.h"
#include <vector>
#include <algorithm>

class Astar
{
public:
	Astar(Node* node1, Node* node2, vector<Node*> nodeset)
	{
		startnode = node1;
		endnode = node2;
		nodes = nodeset;
	}
	void findshortestpath();
	static bool sortbyf(Node* node1, Node* node2) { return node1->getf() < node2->getf(); };
	void printpath();
private:
	Node* startnode;
	Node* endnode;
	vector<Node*> nodes;
	vector<Node*> CloseList;
	vector<Node*> OpenList;
};