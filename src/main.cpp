#include "ObjMgr.h"
#include <iostream>
#include "Astar.h"


using namespace std;

int main(int argc, char* argv[])
{
	try {
		ObjMgr::instance()->loadNodePosition();
		ObjMgr::instance()->loadRelationship();
		cout << "input startnode"<<endl;
		int startnode;//node start from 1 to 9
		cin >> startnode;
		cout << "input endnode"<<endl;
		int endnode;
		cin >> endnode;
		vector<Node*> nodeset = ObjMgr::instance()->getnodes();
		Astar Astaralgorithm(nodeset[startnode - 1], nodeset[endnode - 1], nodeset);
		Astaralgorithm.findshortestpath();
		Astaralgorithm.printpath();
	}
	catch (int i) { std::cout << i; }
	return 0;
}