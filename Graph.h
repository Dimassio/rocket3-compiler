#pragma once

#include <string>

class CGraph {
public:

	CGraph(std::string _fileName);
	~CGraph();

	void SetNodeLabel(std::string nodeName, std::string nodeLabel);

	void AddEdge(std::string from, std::string to);
	void AddEdge(std::string from, std::string to, std::string edgeName);
	void Flush();

private:

	bool isFlushed;

	std::string fileName;
	std::string data;

	void decorateName(std::string& stringToDecorate);

};
