#pragma once
#include<vector>
#include"Node.h"

using namespace std;

class ObjMgr
{
public:
	static ObjMgr* instance();
protected:
	static ObjMgr* _instance;
public:
	void loadNodePosition();
	void loadRelationship();
	vector<Node*> getnodes() { return _node; };
private:
	vector<Node*> _node;
};