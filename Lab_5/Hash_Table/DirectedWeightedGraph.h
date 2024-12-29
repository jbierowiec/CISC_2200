#pragma once
#include <unordered_map>
#include <queue>
#include "ItemType.h"
using namespace std;

enum MARK { DEFAULT, VISITED, QUEUED };

class VertexType {
public:
    void initializeItem(ItemType theItem) {
        item = theItem;
    }
    void initializeMark(MARK theMark) {
        mark = theMark;
    }
    ItemType getItem() const {
        return item;
    }
    MARK getMark() const {
        return mark;
    }

private:
    ItemType item;
    MARK mark;
};

class DirectedWeightedGraph {
public:
    DirectedWeightedGraph() {}
    ~DirectedWeightedGraph() {}

    bool IsEmpty() const {
        return vertices.empty();
    }

    void AddVertex(VertexType v) {
        int key = v.getItem().getVal();
        vertices[key] = v;
        edges[key] = unordered_map<int, int>();
    }

    void AddEdge(VertexType v1, VertexType v2, int weight) {
        int key1 = v1.getItem().getVal();
        int key2 = v2.getItem().getVal();
        if (vertices.find(key1) != vertices.end() && vertices.find(key2) != vertices.end()) {
            edges[key1][key2] = weight;
        }
    }

    void DeleteVertex(VertexType v) {
        int key = v.getItem().getVal();
        vertices.erase(key);
        edges.erase(key);
        for (auto& src_and_destinations : edges) {
            src_and_destinations.second.erase(key);
        }
    }

    void DeleteEdge(VertexType v1, VertexType v2) {
        int key1 = v1.getItem().getVal();
        int key2 = v2.getItem().getVal();
        if (edges.find(key1) != edges.end()) {
            edges[key1].erase(key2);
        }
    }

    void PrintVertices() const {
        for (const auto& key_and_vertex : vertices) {
            cout << key_and_vertex.first << " ";
        }
        cout << endl;
    }

    void PrintEdges() const {
        for (const auto& src_and_destinations : edges) {
            cout << src_and_destinations.first << ": ";
            for (const auto& dst_and_weight : src_and_destinations.second) {
                cout << "(" << dst_and_weight.first << ", " << dst_and_weight.second << ") ";
            }
            cout << endl;
        }
    }

    void GetNeighbors(VertexType v, queue<VertexType>& nq) {
        ResetMarks();
        int key = v.getItem().getVal();
        nq.push(vertices[key]);
        while (!nq.empty()) {
            int currentKey = nq.front().getItem().getVal();
            vertices[currentKey].initializeMark(VISITED);
            cout << nq.front().getItem().getVal() << " ";
            nq.pop();
            for (const auto& neighbor_and_weight : edges[currentKey]) {
                if (vertices[neighbor_and_weight.first].getMark() == DEFAULT) {
                    nq.push(vertices[neighbor_and_weight.first]);
                    vertices[neighbor_and_weight.first].initializeMark(QUEUED);
                }
            }
        }
        cout << endl;
    }

    void ResetMarks() {
        for (auto& key_and_vertex : vertices) {
            key_and_vertex.second.initializeMark(DEFAULT);
        }
    }

private:
    unordered_map<int, VertexType> vertices;                  // Maps vertex ID to vertex
    unordered_map<int, unordered_map<int, int> > edges;       // Adjacency list
};
