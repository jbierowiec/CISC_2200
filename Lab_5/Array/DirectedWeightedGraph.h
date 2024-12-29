#ifndef DirectedWeightedGraph_H
#define DirectedWeightedGraph_H

#include <iostream>
#include <queue>
#include "ItemType.h"
using namespace std;

enum  MARK { DEFAULT, VISITED, QUEUED };

class VertexType{

    public:
        
        void initializeItem(ItemType theItem)
        {
            item=theItem;
        }
        void initializeMark(MARK theMark)
        {
            mark=theMark;
        }
        ItemType getItem() const
        {
            return item;
        }
        MARK getMark() const
        {
            return mark;
        }

    private:
        ItemType item;
        MARK mark;          //default mark = DEFAULT; if visited, mark= VISITED; 
                            //if queued, mark = QUEUED;
     
};

class DirectedWeightedGraph{

   public:

        DirectedWeightedGraph();
        DirectedWeightedGraph(int max);

        ~DirectedWeightedGraph();

        bool IsEmpty() const;
        bool IsFull() const;

        void AddVertex(VertexType v);
        void AddEdge(VertexType v1, VertexType v2, int weight);
  
        void DeleteVertex(VertexType v);
        void DeleteEdge(VertexType v1, VertexType v2);

        int GetWeight(VertexType v1, VertexType v2);

        bool EdgeExists(VertexType v1, VertexType v2);
        bool VertexExists(VertexType v);

        void PrintVertices() const;
        void PrintEdges() const;
        int VertexNumb() const;
        void MarkVertex(VertexType v, MARK m);          //mark whether the vertex has been visited or queued
        void ResetMarks();
        void GetNeighbors(VertexType v, queue<VertexType>& nq);

   private:

        int numberOfVertices;
        int maxVertices;
        
        VertexType * vertices;  //save all the vertices

        int edges[50][50];      //save all the edges

        int IndexIs(VertexType v);

};

#endif