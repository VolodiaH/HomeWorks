#include "Graph.h"
#include <unordered_set>
#include <iostream>
#include <queue>

using AdjacencyList = std::vector<std::vector<int>>;

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
	: Graph(Vertixes, type)
{
	m_adjacencyList.resize(Vertixes);
	m_visited.resize(Vertixes, false);
}

void GraphAdjList::addEdge(int v, int w)
{
	//Check if w is not already in the list of v
	m_adjacencyList[v].push_back(w);

	if (m_connectionType == ConnectionType::undirected)
	{
		m_adjacencyList[w].push_back(v);
	}
}

void GraphAdjList::DFS(int vertex, bool forceReset )
{
	std::cout << "---DFS---" << '\n';
    
    DFSImpl(vertex);
	if(forceReset)
        restoreVisited();
}

void GraphAdjList::DFSImpl(int vertex)
{
	m_visited[vertex] = true;

	std::cout << vertex << " ";

	for (size_t i{}; i < m_adjacencyList[vertex].size(); ++i)
	{
		const int current = m_adjacencyList[vertex][i];

		if (!m_visited[current])
			DFSImpl(current);
	}
}

void GraphAdjList::DFSImpl(int vertex, AdjacencyList &adjacencyList, std::vector<bool> &visited)
{
	visited[vertex] = true;

	std::cout << vertex << " ";

	for (size_t i{}; i < adjacencyList[vertex].size(); ++i)
	{
		const int current = adjacencyList[vertex][i];

		if (!visited[current])
			DFSImpl(current, adjacencyList, visited);
	}
}

AdjacencyList GraphAdjList::getTranspose()
{
	AdjacencyList graph;
	graph.reserve(numberOfNodes());
	for (int i = 0; i < numberOfNodes(); ++i)
	{
		for (auto j = m_adjacencyList[i].begin(); j != m_adjacencyList[i].end(); ++j)
			m_adjacencyList[*j].push_back(i);
	}
	return graph;
}

bool GraphAdjList::isStronglyConnected()
{
	restoreVisited();

	DFSImpl(0);

	if(anyVisited())
		return false;

	AdjacencyList graph = getTranspose();

	restoreVisited();

	DFSImpl(0, graph, m_visited);

	if (anyVisited())
		return false;

	return true;
}

void GraphAdjList::DFSImplForNodeLevel(int vertex, int &currentLevel, int level, int &numberOfNodes)
{
    m_visited[vertex] = true;

	if (level == currentLevel) 
		numberOfNodes++;
	else if (level < currentLevel)
		return;
	else
	{
		for (size_t i{}; i < m_adjacencyList[vertex].size(); ++i)
		{
			const int current = m_adjacencyList[vertex][i];
			// I know 4 deep nest - bad
			if (!m_visited[current])
			{
				++currentLevel;
				DFSImplForNodeLevel(current, currentLevel, level, numberOfNodes);
			}
		}
	}
	--currentLevel;
}

int GraphAdjList::numberOfNodesInLevel(int level)
{
	int curr_level = 0;

	int NumberOfNodes = 0;
	restoreVisited();

	DFSImplForNodeLevel(0, curr_level, level, NumberOfNodes);

	restoreVisited();
	return NumberOfNodes;
}

bool GraphAdjList::anyVisited()
{
    return std::any_of(m_visited.begin(), m_visited.end(), [](bool b){ return b == false; });
}

void GraphAdjList::BFS(int vertex)
{
	// Mark all the vertices as not visited
	std::unordered_set<int> visited;
	std::queue<int> queue;
	
	// Mark the current node as visited and enqueue it
	visited.insert(vertex);
	queue.push(vertex);

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int currentVertex = queue.front();
		std::cout << currentVertex << " ";  //or make anything else with it: push to vector, string, another object, whatever
		queue.pop();

		// Get all adjacent vertices
		for (int adjacent : m_adjacencyList[currentVertex])
		{
			if (!visited.count(adjacent))
			{
				visited.insert(adjacent);
				queue.push(adjacent);
			}
		}
	}
}

void GraphAdjMatrix::DFSImpl(int vertex)
{
	m_visited[vertex] = true;

	std::cout << vertex << " ";

	for (size_t i{}; i < m_adjacentMatrix[vertex].size(); ++i)
	{
		if (m_adjacentMatrix[vertex][i] == 1 && !m_visited[i])
			DFSImpl(i);
	}
}
