// Computing Structures Fall 2022
// DSA 5005
// Project 1 code
// Bhavya Reddy Kanuganti

//headers
#include <iostream>
#include <string>

using namespace std;

// class to store one edge's details
class Edge {
	int id;//field to store the node
	string name;//field to store the name of node
	string relation;//field to store the edge information (i.e) relation
	int index;// field to store index
public:
	Edge();//Default constructor
	//getters
	int getId();
	string getName();
	string getRelation();
	int getIndex();
	//setters
	void setId(int newId);
	void setName(string newName);
	void setRelation(string newRelation);
	void setIndex(int newIndex);
};
//default constructor
Edge::Edge() {
	id = -1;
	relation = "";
}
//getter which returns id
int Edge::getId() {
	return id;
}
// getter which returns name
string Edge::getName() {
	return name;
}
//getter which returns relation
string Edge::getRelation() {
	return relation;
}
// id setter
void Edge::setId(int newId) {
	id = newId;
}
//name setter
void Edge::setName(string newName) {
	name = newName;
}
//relation setter
void Edge::setRelation(string newRelation) {
	relation = newRelation;
}
//index getter
int Edge::getIndex() {
	return index;
}
//index setter
void Edge::setIndex(int newIndex) {
	index = newIndex;
}
//Class to print nodes and edges
class PrintNode {
	string name;//field to store name
	Edge edge;//field to store edge
public:
	PrintNode();//default constructor
	//getters
	string getName();
	Edge getEdge();
	//setters
	void setName(string newName);
	void setEdge(Edge newEdge);
};
//default constructor
PrintNode::PrintNode() {
	name = "";
}
//getter which returns name
string PrintNode::getName() {
	return name;
}
//getter which returns edge
Edge PrintNode::getEdge() {
	return edge;
}
// name setter
void PrintNode::setName(string newName) {
	name = newName;
}
//edge setter
void PrintNode::setEdge(Edge newEdge) {
	edge = newEdge;
}

// class node to store one node's details
class Node {
protected:
	int nodeNumber; // field to store node's number
	string nodeInfo; // field to store node's information
	Edge* edges; // field to store node's edges
	int edgeLength;// field to store edge length
public:
	Node();// default constructor
	//getters
	string getNodeInfo();
	int getNodeNumber();
	//setters
	void setNodeInfo(string newInfo);
	void setNodeNumber(int newNum);
	void setEdge(int newId, string newName, string newRelation, int index);

	void printEdges();//calling to print the edges
	bool isEdgeExists(int nodeNo);//calling function that checks if edge exist or not
	void removeEdge(int nodeNo);// calling function that removes edges
	void display();//calling display function
	Edge* getEdges();//getter
	int getEdgeLength();//getter
};
//defaullt constructor
Node::Node() {
	nodeNumber = -1;
	nodeInfo = "";
	edges = new Edge[100];
	edgeLength = 0;
}
//getter which returns nodeinfo
string Node::getNodeInfo() {
	return nodeInfo;
}
//getter which returns nodeNumber
int Node::getNodeNumber() {
	return nodeNumber;
}
//nodeInfo setter
void Node::setNodeInfo(string newInfo) {
	nodeInfo = newInfo;
}
//nodeNumber setter
void Node::setNodeNumber(int newNum) {
	nodeNumber = newNum;
}
// display function
void Node::display() {
	cout << nodeNumber << " " << nodeInfo;
}
// edge setter
void Node::setEdge(int newId, string newName, string newRelation, int index) {
	edges[edgeLength].setId(newId);
	edges[edgeLength].setName(newName);
	edges[edgeLength].setRelation(newRelation);
	edges[edgeLength].setIndex(index);
	edgeLength++;
}
//Function that checks edge existance 
bool Node::isEdgeExists(int nodeNo) {
	for (int i = 0; i < edgeLength; i++) {
		if (edges[i].getId() == nodeNo)//returns true if edge exists {
			return true;
	}
}
return false;//returns false if edge doesn't exist
}

//Function to remove edge. In this function if the is found then that edge is removed.
void Node::removeEdge(int nodeNo) {
	int n = edgeLength;
	Edge* newEdges = new Edge[100];
	int j = 0;
	bool isFound = false;
	for (int i = 0; i < n; i++) {
		if (edges[i].getId() != nodeNo) {
			newEdges[j].setId(edges[i].getId());
			newEdges[j].setName(edges[i].getName());
			newEdges[j].setRelation(edges[i].getRelation());
			newEdges[j].setIndex(edges[i].getIndex());
			j++;
		}
		else {
			isFound = true;
		}
	}
	if (isFound) {
		edges = newEdges;
		edgeLength--;
	}
}

//function to print edges
void Node::printEdges() {
	for (int i = 0; i < edgeLength; i++) {
		cout << nodeInfo << " - " << edges[i].getName() << " " << edges[i].getRelation() << endl;
	}
}
// edge getter
Edge* Node::getEdges() {
	return edges;
}
// edgelength getter
int Node::getEdgeLength() {
	return edgeLength;
}

int main() {
	int numNodes;// field to store numNodes
	int maxEdges;// field to store max Edges
	int nodeNum;// field to store nodeNum
	char command;// field to store command
	int index = 0;//index set to 0
	int u, v;// field to store u and v

	Node* allNodes;//array of nodes

	string nodeLabel;//field to store nodel label
	string edgeLabel;// field to store edge label

	cin >> numNodes;//user input for number of nodes
	cin >> maxEdges;// user input for max number of edges

	cout << "numNodes: " << numNodes << endl;//prints number of nodes
	cout << "maxEdges: " << maxEdges << endl << endl;// prints number of edges

	allNodes = new Node[numNodes]; //gives the address of the first node object

	for (int i = 0; i < numNodes; i++) {
		cin >> nodeNum >> nodeLabel;//user input for node number and label
		//cout << nodeNum << " " << nodeLabel << endl;

		allNodes[i].setNodeNumber(nodeNum);// setting node numbers
		allNodes[i].setNodeInfo(nodeLabel);// setting node labels

		// allNodes[i].display();
		// cout << endl;

	}

	cin >> command;// takes in the command
	while (!cin.eof()) {
		switch (command) {
		case 'I'://Inserting the node 
		{
			cin >> u >> v >> nodeLabel;
			cout << "Inserting " << u << " " << v << ": " << nodeLabel << endl << endl;
			string vname;
			for (int j = 0; j < numNodes; j++) {
				if (v == allNodes[j].getNodeNumber()) {
					vname = allNodes[j].getNodeInfo();
				}
			}
			for (int i = 0; i < numNodes; i++) {
				if (u == allNodes[i].getNodeNumber()) {
					allNodes[i].setEdge(v, vname, nodeLabel, index);
					index++;
				}
			}
			break;
		}
		case 'E': //Checks if there exists an edge between the given two nodes
		{
			cin >> u >> v;
			string vname;
			for (int j = 0; j < numNodes; j++) {
				if (v == allNodes[j].getNodeNumber()) {
					vname = allNodes[j].getNodeInfo();
				}
			}
			for (int i = 0; i < numNodes; i++) {
				if (u == allNodes[i].getNodeNumber()) {
					if (allNodes[i].isEdgeExists(v)) {
						cout << "Edge exists between " << allNodes[i].getNodeInfo() << " and " << vname << endl << endl;
					}
					else {
						cout << "No edge exists between " << allNodes[i].getNodeInfo() << " and " << vname << endl << endl;
					}
				}
			}
			break;
		}
		case 'R': //the remove edge command is followed by the edge we want to remove represented 
			//by the two nodes the edge is connecting
		{
			cin >> u >> v;
			cout << "Removing " << u << " " << v << endl << endl;
			for (int i = 0; i < numNodes; i++) {
				if (u == allNodes[i].getNodeNumber()) {
					allNodes[i].removeEdge(v);
				}
			}
			break;
		}
		case 'D': //the display command displays the nodes and edges that are currently in the data 
			//structure
		{
			cout << "Displaying myNodes:" << endl;
			for (int i = 0; i < numNodes; i++) {
				allNodes[i].display();
				cout << endl;
			}
			cout << "Displaying myEdges:" << endl;
			PrintNode* printNodes = new PrintNode[100];
			int k = 0;
			for (int i = 0; i < numNodes; i++) {
				string uname = allNodes[i].getNodeInfo();
				Edge* edges = allNodes[i].getEdges();
				for (int j = 0; j < allNodes[i].getEdgeLength(); j++) {
					Edge edge = edges[j];
					printNodes[k].setName(uname);
					printNodes[k].setEdge(edge);
					k++;
				}
			}
			for (int i = 0; i < k - 1; i++) {
				for (int j = 0; j < k - i - 1; j++) {
					if (printNodes[j].getEdge().getIndex() > printNodes[j + 1].getEdge().getIndex()) {
						PrintNode temp = printNodes[j];
						printNodes[j] = printNodes[j + 1];
						printNodes[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < k; i++) {
				cout << printNodes[i].getName() << " - " << printNodes[i].getEdge().getName() << " " << printNodes[i].getEdge().getRelation() << endl;
			}
			cout << endl;
			break;
		}
		default: cout << "Default Case" << endl;
		}
		cin >> command;
	}
	return 0;
}