#pragma once
#include<string>
#include<utility>
#include<vector>

using namespace std;

class Node
{
public:
	void setnodeid(string nodeid) { _nodeid = nodeid; };
	void setposition(pair<double, double> position) { _position = position; };
	string getnodeid() { return _nodeid; };
	pair <double, double> getposition() { return _position; };
	void addrelatednodes(Node* node) { _relatednodes.push_back(node); };
	vector<Node*> getrelatednodes() { return _relatednodes; };
	double calculatedis(Node* node) {
		pair<double, double> p1 = _position;
		pair<double, double> p2 = node->getposition();
		double dx = p1.first - p2.first;
		double dy = p1.second - p2.second;
		return sqrt(dx*dx + dy * dy);
	}
	void initialh(double value) { h = value; };
	void initialg() { g = 0; };
	void updateparent(Node* node) { parentnode = node; };
	Node* getparent() { return parentnode; };
	double getg() { return g; };
	void updateg() { g = parentnode->getg() + this->calculatedis(parentnode); };
	double getf() { return g + h; };
private:
	pair<double, double> _position;
	string _nodeid;
	vector<Node*> _relatednodes;
	Node* parentnode;
	double f;
	double g;
	double h;
};