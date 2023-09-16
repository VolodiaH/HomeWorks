#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Graph
{
public:
	enum class ConnectionType
	{
		undirected,
		directed
	};

	Graph(int vertixes, ConnectionType type = ConnectionType::undirected)
		: m_vertixes(vertixes), m_connectionType(type) {}

	virtual void addEdge(int v, int w) = 0;

	virtual void BFS(int vertex = 0) {}
	virtual void DFS(int vertex = 0, bool = true) {}

protected:
	unsigned int m_vertixes;
	ConnectionType m_connectionType;
};

// using adjacency list
class GraphAdjList : public Graph
{
public:

	GraphAdjList(int vertixes, ConnectionType type = ConnectionType::undirected);
	void addEdge(int v, int w) override;

	void BFS(int vertex = 0) override;
	void DFS(int vertex = 0, bool forceReset = true) override;

	int numberOfNodesInLevel(int level) ;
	size_t numberOfNodes() const { return m_adjacencyList.size(); }

	bool isStronglyConnected();

	void restoreVisited(){m_visited.assign(numberOfNodes(), false); }

private:
	using AdjacencyList = std::vector<std::vector<int>>;

	void DFSImpl(int vertex);
	static void DFSImpl(int vertex, AdjacencyList &adjacencyList, std::vector<bool> &visited);
	void DFSImplForNodeLevel(int vertex, int &currentLevel,
		int level, int &numberOfNodes);

	bool anyVisited();

	AdjacencyList getTranspose();

	AdjacencyList m_adjacencyList;
	std::vector<bool> m_visited;

};

//#TODO HW
class GraphAdjMatrix : public Graph
{
public:
	GraphAdjMatrix(int vertixes, ConnectionType type = ConnectionType::undirected) 
	: Graph(vertixes, type) 
	{
		m_adjacentMatrix.resize(vertixes);
		std::for_each(std::begin(m_adjacentMatrix), std::end(m_adjacentMatrix), [vertixes]
		(auto &v)
		{

		    v.assign(vertixes, 0);
		});
		m_visited.assign(vertixes, false);
		m_numberOfNodes = vertixes;

	} 

	void addEdge(int v, int w) override
	{
		m_adjacentMatrix[v][w] = 1;
		m_adjacentMatrix[w][v] = 1;
	};
	void DFS(int vertex = 0, bool = true) override
	{
		std::cout << "---DFS---" << '\n';

		DFSImpl(vertex);
	}
	void restoreVisited() { m_visited.assign(m_numberOfNodes, false); }
private:
	void DFSImpl(int vertex);
	using AdjacentMatrix = std::vector<std::vector<int>>;

	AdjacentMatrix m_adjacentMatrix;
	std::vector<bool> m_visited;
	size_t m_numberOfNodes;
};
