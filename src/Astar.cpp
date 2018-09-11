#include"Astar.h"
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<iostream>

using namespace std;

void Astar::findshortestpath()
{
	for (size_t i = 0; i < nodes.size(); i++)
	{
		nodes[i]->initialh(nodes[i]->calculatedis(endnode));
		nodes[i]->initialg();
	}
	CloseList.push_back(startnode);
	bool continueAstar = true;
	while (continueAstar)
	{
		Node* curpoint = CloseList.back();
		vector<Node*> temprelatednodes = curpoint->getrelatednodes();
		for (size_t i = 0; i < temprelatednodes.size(); i++)
		{
			vector<Node*>::const_iterator iter = find(CloseList.begin(), CloseList.end(), temprelatednodes[i]);
			if (iter == CloseList.end())
			{
				vector<Node*>::const_iterator iter2 = find(OpenList.begin(), OpenList.end(), temprelatednodes[i]);
				if (iter2 == OpenList.end())
				{
					temprelatednodes[i]->updateparent(curpoint);
					temprelatednodes[i]->updateg();
					OpenList.push_back(temprelatednodes[i]);
				}
				else
				{
					if (temprelatednodes[i]->getg() > curpoint->getg() + temprelatednodes[i]->calculatedis(curpoint))
					{
						temprelatednodes[i]->updateparent(curpoint);
						temprelatednodes[i]->updateg();
					}
				}

			}
		}
		sort(OpenList.begin(), OpenList.end(), sortbyf);
		CloseList.push_back(OpenList[0]);
		OpenList.erase(OpenList.begin());
		vector<Node*>:: const_iterator iter3 = find(CloseList.begin(), CloseList.end(), endnode);
		if(iter3!=CloseList.end())
		{
			continueAstar = false;
		}
	}
}
void Astar::printpath()
{
	bool continuesearch = true;
	Node* curpoint = endnode;
	vector<Node*> shortestpath;
	shortestpath.push_back(endnode);
	while (continuesearch)
	{
		shortestpath.push_back(curpoint->getparent());
		if (curpoint->getparent() == startnode)
		{
			continuesearch = false;
		}
		curpoint = curpoint->getparent();
	}
	reverse(shortestpath.begin(), shortestpath.end());
	ofstream of("shortestpath.output");
	ostringstream ostring;
	for(size_t i=0;i<shortestpath.size()-1;i++)
	{
		ostring << shortestpath[i]->getnodeid() << "->";
		cout << shortestpath[i]->getnodeid() << "->";
	}
	ostring << shortestpath.back()->getnodeid();
	cout << shortestpath.back()->getnodeid();
	of << ostring.str();
	of.close();
}
