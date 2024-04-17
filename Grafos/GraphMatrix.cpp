#pragma once
#include "Graph.cpp"

class GraphMatrix : public Graph {
public:
    GraphMatrix(int maxV, bool isDirected) 
    {
        this->size = maxV;
        this->directed = directed;
        this->matrix = new int*[maxV+1];
        for(int i = 1; i < maxV+1; i++) 
        {
            this->matrix[i] = new int[maxV+1];
            for(int j = 1; j < maxV+1; j++)
            {
                this->matrix[i][j] = 0;
            }
        }
    }
    void addEdge(int v, int w) override 
    {
        addWeigthedEdge(v, w, 1);
    }
    void addWeigthedEdge(int v, int w, int weight) override 
    {
        this->matrix[v][w] = weight;
        if(!this->directed) {
            this->matrix[w][v] = weight;
        }
    }
    void removeEdge(int v, int w) override
    {
        addWeigthedEdge(v, w, 0);
    }

    bool hasEdge(int v, int w) override
    {
        return this->matrix[v][w] != 0;
    } 
    
    int getEdge(int v, int w) override 
    {
        return this->matrix[v][w];
    }

    Graph* grafoSubyaciente() 
    {
        GraphMatrix *newGraph = new GraphMatrix(this->size,this->directed);
        for(int i = 1; i < this->size; i++) 
        {
            for(int j = 1; j < this->size; j++)
            {
                this->matrix[i][j] = 0;
            }
        }
        return newGraph;
    }

private:
    int **matrix;
    bool directed;
    int size;
};