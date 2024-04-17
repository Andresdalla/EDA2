#pragma once
#include "../Iterable/Iterable.cpp"
class Graph {

virtual void addEdge(int v, int w) = 0;

virtual void addWeigthedEdge(int v, int w, int weight) = 0;

virtual void removeEdge(int v, int w) = 0;

virtual bool hasEdge(int v, int w) = 0;

virtual int getEdge(int v, int w) = 0;

virtual iterable<int> getNeightbours(int v) = 0;

virtual bool tieneCiclo(Graph g) = 0; 
//devuelve true si y solo si g tiene un ciclo, es decir, 
//una secuencia de vertices

virtual Graph grafoSubyaciente(Graph g) = 0;
//Retorna el grafo subyacente de g: siendo g un grafo dirigido,
// el grafo subyacente es 
//el grafo no dirigido que tiene los mismos vertices y aristas que g.

virtual Graph complementario(Graph g) = 0;
//Retorna el grafo complementario de g: siendo g un grafo dirigido,
// el grafo complementario es aquel que tiene los mismos vertices que g,
// y tiene una arista entre dos vertices si y solo si no hay una arista entre ellos en g.
};