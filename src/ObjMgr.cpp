#include"ObjMgr.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include"Node.h"
#include <string>

using namespace std;

ObjMgr* ObjMgr::_instance = 0;

ObjMgr* ObjMgr::instance()
{
	if (!_instance)
		_instance = new ObjMgr();
	return _instance;
}
void ObjMgr::loadNodePosition()
{
	ifstream openf("NodePosition.input");
	if (!openf)
	{
		cout << "Error:openfile";
		throw(0);
	}
	string aline;
	while (openf.good())
	{
		getline(openf, aline);
		if (aline.empty())
		{
			continue;
		}
		string nodeid;
		double positionx;
		double positiony;
		istringstream pausealine(aline);
		pausealine >> nodeid;
		pausealine >> positionx;
		pausealine >> positiony;
		Node* tempnode = new Node();
		tempnode->setnodeid(nodeid);
		pair<double, double> position(positionx, positiony);
		tempnode->setposition(position);
		_node.push_back(tempnode);
	}
	openf.close();
}
void ObjMgr::loadRelationship()
{
	ifstream openf("Relationship.input");
	if (!openf)
	{
		cout << "Error:openfile";
		throw(0);
	}
	string aline;
	int i = 0;
	while (openf.good())
	{

		getline(openf, aline);
		size_t nodesize = _node.size();
		istringstream pausealine(aline);
		for (size_t j = 0; j < nodesize; j++)
		{
			int temprelated;
			pausealine >> temprelated;
			if (temprelated == 1)
			{
				_node[i]->addrelatednodes(_node[j]);
			}
		}
		i++;
	}
	openf.close();
}