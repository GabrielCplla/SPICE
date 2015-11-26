#include "stdafx.h"
#include "NodeStorage.h"


NodeStorage::NodeStorage(void)
{
}


NodeStorage::~NodeStorage(void)
{
}

unsigned long NodeStorage::getNodeAmount() {
	return nodeMap.size(); 
}

Node* NodeStorage::addNode(std::string identifier) {
	
	std::map<std::string, Node*>::iterator it;

	it = nodeMap.find(identifier);
	if (it != nodeMap.end()) { //found the node
		return it->second; //return existing Node
	} else {
		Node* newNode = new Node(identifier);
		nodeMap[identifier] = newNode;
		return newNode;
	}
}

unsigned long NodeStorage::allocateNodeNumbers() {

	unsigned long matrixPosition = 1; // the 0 is always the ground

	std::map<std::string, Node*>::iterator it;

	for(it = nodeMap.begin(); it != nodeMap.end(); it++) {
		if(!(it->first.compare("0"))) {
			it->second->setNodeNumber(0);
		} else {
			it->second->setNodeNumber(matrixPosition);
			matrixPosition++;
		}
	}
	return matrixPosition - 1;//the for iterates one time too much
}