#include "Graph.h"

#include <ostream>
#include <fstream>

CGraph::CGraph(std::string _fileName)
	: fileName(_fileName), data("digraph {\n"), isFlushed(false)
{

}

CGraph::~CGraph()
{
	if (!isFlushed) {
		Flush();
	}
}

void CGraph::AddEdge(std::string from, std::string to)
{
	decorateName(from);
	decorateName(to);
	data += from + " -> " + to + " ; \n";
}

void CGraph::AddEdge(std::string from, std::string to, std::string edgeName)
{
	decorateName(from);
	decorateName(to);
	decorateName(edgeName);
	data += from + " -> " + to + " [ label=\"" + edgeName + "\"] ; \n";
}

void CGraph::Flush()
{
	data += "\n}";
	std::ofstream out(fileName);
	out << data;
	out.close();
	isFlushed = true;
}

void CGraph::SetNodeLabel(std::string nodeName, std::string nodeLabel)
{
	decorateName(nodeName);
	decorateName(nodeLabel);
	data += nodeName + " [ label=\"" + nodeLabel + "\" ]; \n";
}


void CGraph::decorateName(std::string& stringToDecorate)
{
	for (int i = 0; i < stringToDecorate.size(); i++) {
		if (stringToDecorate[i] == '.' || stringToDecorate[i] == ':' || stringToDecorate[i] == '=') {
			stringToDecorate[i] = '_';
		}
	}
}