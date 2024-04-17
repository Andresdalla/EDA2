#include "Graph.cpp"

class GraphMatrix : public Graph {
public:
    GraphMatrix(int maxV, bool isDirected) {
        this->directed = directed;
        this->matrix = new int*[maxV+1];
        for(int i = 1; i < maxV+1; i++) {
            this->matrix[i] = new int[maxV+1];
        }
    }
    void addEdge(int v, int w) override {
        addWeigthedEdge(v, w, 1);
    }
    void addWeigthedEdge(int v, int w, int weight) override {
        this->matrix[v][w] = weight;
        if(!this->directed) {
            this->matrix[w][v] = weight;
        }
    }
private:
    int **matrix;
    bool directed;
};