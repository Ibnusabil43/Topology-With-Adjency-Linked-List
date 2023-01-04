#ifndef MULTILISTHEADER_H_INCLUDED
#define MULTILISTHEADER_H_INCLUDED

#include <cstdio>
#include <iostream>
using namespace std;

//MACRO VERTEX
#define first(G) (G).first
#define infoVertex(P) (P)->infoVertex
#define nextVertex(P) (P)->nextVertex
#define child(P) (P)->child

//MACRO EDGE
#define infoEdge(P) (P)->infoEdge
#define nextEdge(P) (P)->nextEdge
#define bobot(P) (P)->bobot

//MACRO QUEUE
#define infoQueue(P) (P)->infoQueue
#define nextQueue(P) (P)->nextQueue
#define firstQueue(Q) (Q).firstQueue
#define tail(Q) (Q).tail

struct cityProject{
    int NE_ID;
    string Optical_NE;
    string City_Type;
    string Project;
};
typedef cityProject infotype;

//ADT QUEUE
typedef struct elementQueue *adrQueue;

struct elementQueue{
    infotype infoQueue;
    adrQueue nextQueue;
};

struct Queue {
    adrQueue firstQueue;
    adrQueue tail;
};

void createQueue(Queue &Q);
adrQueue createElementQueue(infotype x);
void enQueue(Queue &Q, adrQueue P);
void printQueue(Queue Q);
bool isVisited(Queue Q, string Optical_NE);
adrQueue deQueue(Queue &Q);
void deleteLastQueue(Queue &Q, adrQueue &P);
void inserFirstQueue(Queue &Q, adrQueue P);

//ADT GRAPH
typedef struct elementVertex *adrVertex;
typedef struct elementEdge *adrEdge;

struct elementVertex{
    infotype infoVertex;
    adrVertex nextVertex;
    adrEdge child;
};

struct elementEdge{
    infotype infoEdge;
    int bobot;
    adrEdge nextEdge;
};

struct Graph{
    adrVertex first;
};


void createGraph(Graph &G);
adrVertex newVertex(infotype x);
adrVertex findNode(Graph G, int NE_ID);
void printGraphLengkap(Graph G);
void printGraph(Graph G);
bool isConnected(Graph G, int ID_Vertex, int ID_Edge);
int findIDbyName(Graph G, string Optical_NE);

//MAIN QUEST
void InsertNE(Graph &G, adrVertex P);
void setEdge(Graph &G, int ID_Vertex_IN, int ID_Vertex_OUT);
void findAllSLA(Graph G, Queue &Q);
void BFS_Filter(Graph G, Queue Visited, Queue &Path);
void FindLinkToSLA(Graph G, int ID_City, int ID_SLA, Queue &Visited);
void ShowAllLinkToSLA(Graph G, int ID_City, Queue SLAQueue);

//MENU and other
int selectMenu();
void tentangprogram();

#endif // MULTILISTHEADER_H_INCLUDED
