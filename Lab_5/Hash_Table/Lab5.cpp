#include "DirectedWeightedGraph.h"
#include "ItemType.h"
#include <iostream>
using namespace std;

int main()
{
    ItemType item1,item2,item3,item4,item5,item6,item7;
    item1.Initialize(1);
    item2.Initialize(2);
    item3.Initialize(3);
    item4.Initialize(4);
    item5.Initialize(5);
    item6.Initialize(6);
    item7.Initialize(7);
    DirectedWeightedGraph PlanePath;
    VertexType v1,v2,v3,v4,v5,v6,v7;
    v1.initializeItem(item1);
    v2.initializeItem(item2);
    v3.initializeItem(item3);
    v4.initializeItem(item4);
    v5.initializeItem(item5);
    v6.initializeItem(item6);
    v7.initializeItem(item7);
    PlanePath.AddVertex(v1);
    PlanePath.AddVertex(v2);
    PlanePath.AddVertex(v3);
    PlanePath.AddVertex(v4);
    PlanePath.AddVertex(v5);
    PlanePath.AddVertex(v6);
    PlanePath.AddVertex(v7);
    PlanePath.AddEdge(v1,v2,100);
    PlanePath.AddEdge(v1,v3,50);
    PlanePath.AddEdge(v1,v4,150);
    PlanePath.AddEdge(v3, v1, 10);
    PlanePath.AddEdge(v3, v7, 50);
    PlanePath.AddEdge(v4, v5, 200);
    PlanePath.AddEdge(v4, v6, 100);
    PlanePath.AddEdge(v5, v6, 100);
    PlanePath.AddEdge(v7, v6, 30);

    cout << endl;
    cout << "After inserting all 7 vertices and 9 edges:" << endl;
    cout << endl;
    cout << "There are 7 vertices in this Graph" << endl;
    PlanePath.PrintVertices();
    
    cout << endl;
    cout << "Edges are: " << endl;
    PlanePath.PrintEdges();
    
    cout << endl;
    cout << "The Breadth First Traversal Results:" << endl;
    queue<VertexType> nq;
    PlanePath.GetNeighbors(v1,nq);
    
    cout << endl;
    cout << "Delete v4 (vertex 4)" << endl;
    cout << endl;
    cout << "There are 6 vertices in this Graph" << endl;
    PlanePath.DeleteVertex(v4);
    PlanePath.PrintVertices();
    
    cout << endl;
    cout << "Edges are:" << endl;
    
    PlanePath.PrintEdges();
    cout << endl;

    return 0;
}
