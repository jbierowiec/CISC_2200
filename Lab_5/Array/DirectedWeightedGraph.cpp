#include "DirectedWeightedGraph.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

DirectedWeightedGraph::DirectedWeightedGraph()
{
    numberOfVertices = 0;
    maxVertices = 50;
    vertices = new VertexType[50];
    for (int i = 0; i < maxVertices; i++)
    {
        for (int j = 0; j < maxVertices; j++)
        {
            edges[i][j] = 0;
        }
    }
}

DirectedWeightedGraph::DirectedWeightedGraph(int max)
{
    numberOfVertices = 0;
    maxVertices = max;
    const int theMax = max;
    vertices = new VertexType[theMax];

    for (int i = 0; i < maxVertices; i++)
    {
        for (int j = 0; j < maxVertices; j++)
        {
            edges[i][j] = 0;
        }
    }

}

DirectedWeightedGraph::~DirectedWeightedGraph()
{
    delete[] vertices;
}

bool DirectedWeightedGraph::IsEmpty() const
{
    return (numberOfVertices == 0);
}

bool DirectedWeightedGraph::IsFull() const
{
    return(numberOfVertices == maxVertices);
}

void DirectedWeightedGraph::AddVertex(VertexType v)//see dynamic array
{
    numberOfVertices++;
    vertices[numberOfVertices - 1] = v;
}

void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int weight)
{
    int one = IndexIs(v1);
    int two = IndexIs(v2);
    edges[one][two] = weight;
}

void DirectedWeightedGraph::DeleteVertex(VertexType v)
{
    int index = IndexIs(v);
    vertices[index] = vertices[numberOfVertices - 1];
    for (int i = 0; i < numberOfVertices; i++)
    {
        edges[i][index] = edges[i][numberOfVertices - 1];
        edges[index][i] = edges[numberOfVertices - 1][i];
    }
    numberOfVertices--;
}

void DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2)
{
    int one = IndexIs(v1);
    int two = IndexIs(v2);
    edges[one][two] = 0;
}

int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2)
{
    int one = IndexIs(v1);
    int two = IndexIs(v2);
    return edges[one][two];
}

bool DirectedWeightedGraph::VertexExists(VertexType v)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        if (vertices[i].getItem().ComparedTo(v.getItem()) == EQUAL)
        {
            return true;
        }
    }
    return false;
}

bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2)
{
    int one = IndexIs(v1);
    int two = IndexIs(v2);
    if (edges[one][two] == 0)
    {
        return false;
    }
    return true;
}

void DirectedWeightedGraph::PrintVertices() const
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << vertices[i].getItem().getVal()<<" ";
    }
    cout << endl;
}

void DirectedWeightedGraph::PrintEdges() const
{
    cout << " ";
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << setw(6) <<i;
    }
    cout << endl;
    for (int i = 0; i < numberOfVertices; i++)
    {
        cout << i;
        for (int j = 0; j < numberOfVertices; j++)
        {
            cout << setw(6) << edges[i][j];
        }
        cout << endl;
    }
}

int DirectedWeightedGraph::VertexNumb() const
{
    return numberOfVertices;
}

void DirectedWeightedGraph::MarkVertex(VertexType v, MARK m)
{
    v.initializeMark(m);
}

void DirectedWeightedGraph::ResetMarks()
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        vertices[i].initializeMark(DEFAULT);
    }
}

void DirectedWeightedGraph::GetNeighbors(VertexType v, queue<VertexType>& nq)//neighbor queue
{
    ResetMarks();
    int index = IndexIs(v);
    int theIndex;
    nq.push(vertices[index]);
    while (!nq.empty())
    {
        theIndex = IndexIs(nq.front());
        vertices[theIndex].initializeMark(VISITED);
        cout << nq.front().getItem().getVal() << " ";
        nq.pop();
        for (int i = 0; i < numberOfVertices; i++)
        {
            if (vertices[i].getMark() == DEFAULT)
            {
                if (edges[theIndex][i] != 0)
                {
                    nq.push(vertices[i]);
                    vertices[i].initializeMark(QUEUED);

                }
            }
        }
    }
    cout << endl;
}

int DirectedWeightedGraph::IndexIs(VertexType v)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        if (v.getItem().ComparedTo(vertices[i].getItem()) == EQUAL) {
            return i;
        }
    }
    return -1;
}
