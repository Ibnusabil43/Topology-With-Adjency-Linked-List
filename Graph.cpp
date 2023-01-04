#include "MultiListHeader.h"

//MENU
int selectMenu(){
    int userInput = 0;
    printf("\n\n\n\n");
    printf("\t\t\t\t\t  ============================== \n");
    printf("\t\t\t\t\t ||     .   ..__..__..   .      ||  \n");
    printf("\t\t\t\t\t ||     |'v'|[__ |  ||   |	||  \n");
    printf("\t\t\t\t\t ||     |   |[__ |  ||___|	||  \n");
    printf("\t\t\t\t\t  ============================== \n");
    printf("\n\t\t\t\t\tPILIHAN MENU : ");
    printf("\n\t\t\t\t\t 1. TAMPILKAN GRAPH AWAL \n\t\t\t\t\t 2. TAMPILKAN QUEUE KOTA SLA \n\t\t\t\t\t 3. TAMPILKAN PATH TO ONE SLA \n\t\t\t\t\t 4. TAMPILKAN PATH TO ALL SLA \n\t\t\t\t\t 5. TENTANG PROGRAM \n\t\t\t\t\t 0. KELUAR DARI PROGRAM" );
    printf("\n\t\t\t\t\t PILIHAN ANDA : ");

    cin>>userInput;
    cout << endl;

    return userInput;
}

//QUEUE
void createQueue(Queue &Q){
    firstQueue(Q) = NULL;
    tail(Q) = NULL;
}

adrQueue createElementQueue(infotype x){
    adrQueue P = new elementQueue;
    infoQueue(P) = x;
    nextQueue(P) = NULL;
    return P;
}

void enQueue(Queue &Q, adrQueue P){
    if(firstQueue(Q) == NULL){
        firstQueue(Q) = P;
        tail(Q) = P;
    }else{
        nextQueue(tail(Q)) = P;
        tail(Q) = P;
    }
}

void printQueue(Queue Q){
    adrQueue P = firstQueue(Q);
    if(firstQueue(Q) != NULL){
        while(P != NULL){
            cout << infoQueue(P).Optical_NE;
            if(nextQueue(P) != NULL){
                cout << " - ";
            }
            P = nextQueue(P);
    }
    cout << endl;
    }else{
        cout << "Queue Kosong !!" << endl;
    }

}

bool isVisited(Queue Q, string Optical_NE){
    adrQueue P = firstQueue(Q);
    while(P != NULL && infoQueue(P).Optical_NE != Optical_NE){
        P = nextQueue(P);
    }
    return P != NULL;
}

adrQueue deQueue(Queue &Q){
    adrQueue P;
    if(firstQueue(Q) == tail(Q)){
        P = firstQueue(Q);
        firstQueue(Q) = NULL;
        tail(Q) = NULL;
    }else if (firstQueue(Q) == NULL){
        P = NULL;
    }else{
        P = firstQueue(Q);
        firstQueue(Q) = nextQueue(P);
        nextQueue(P) = NULL;
    }
    return P;
}

void deleteLastQueue(Queue &Q, adrQueue &P){
    if(nextQueue(firstQueue(Q)) == NULL){
        P = firstQueue(Q);
        firstQueue(Q) = NULL;
    }else{
        adrQueue Z = firstQueue(Q);
        while(nextQueue(Z) != tail(Q)){
            Z = nextQueue(Z);
        }
        P = tail(Q);
        tail(Q) = Z;
        nextQueue(Z) = NULL;
    }
}

void inserFirstQueue(Queue &Q, adrQueue P){
    if(firstQueue(Q) == NULL){
        firstQueue(Q) = P;
        tail(Q) = P;
    }else{
        nextQueue(P) = firstQueue(Q);
        firstQueue(Q) = P;
    }
}

//GRAPH
void createGraph(Graph &G){
    first(G) = NULL;
}

adrVertex newVertex(infotype x){
    adrVertex P = new elementVertex;
    infoVertex(P) = x;
    nextVertex(P) = NULL;
    child(P) = NULL;
    return P;
}

void InsertNE(Graph &G, adrVertex P){
    if(first(G) == NULL){
        first(G) = P;
    }else{
        adrVertex Q = first(G);
        while(nextVertex(Q) != NULL){
            Q = nextVertex(Q);
        }
        nextVertex(Q) = P;
    }
}

adrVertex findNode(Graph G, int NE_ID){
    adrVertex Q = first(G);
    while(Q != NULL && infoVertex(Q).NE_ID != NE_ID){
        Q = nextVertex(Q);
    }
    return Q;
}

void setEdge(Graph &G, int ID_Vertex_IN, int ID_Vertex_OUT){
    if(first(G) != NULL){
        adrVertex P = findNode(G, ID_Vertex_IN);
        adrVertex Q = findNode(G, ID_Vertex_OUT);
        if(P != NULL){
            adrEdge Z = new elementEdge;
            infoEdge(Z) = infoVertex(Q);
            nextEdge(Z) = NULL;

            if(child(P) == NULL){
                child(P) = Z;
            }else{
                adrEdge Y = child(P);
                while(nextEdge(Y) != NULL){
                    Y = nextEdge(Y);
                }
                nextEdge(Y) = Z;
            }
        }else{
            cout << "Vertex Tidak Ditemukan !!" << endl;
        }
    }else{
        cout << "Graph Kosong !!" << endl;
    }
}

void printGraphLengkap(Graph G){
    if(first(G) != NULL){
        adrVertex P = first(G);
        while (P != NULL){
            cout << "============= Vertex =============" << endl;
            cout << "NE_ID      : " << infoVertex(P).NE_ID << endl;
            cout << "Optical_ID : " << infoVertex(P).Optical_NE << endl;
            cout << "City_Type  : " << infoVertex(P).City_Type << endl;
            cout << "Project    : " << infoVertex(P).Project<< endl << endl;
            adrEdge Q = child(P);
            while(Q != NULL){
                cout << "============= Edge =============" << endl;
                cout << "NE_ID      : " << infoEdge(Q).NE_ID << endl;
                cout << "Optical_ID : " << infoEdge(Q).Optical_NE << endl;
                cout << "City_Type  : " << infoEdge(Q).City_Type << endl;
                cout << "Project    : " << infoEdge(Q).Project<< endl << endl;
                Q =  nextEdge(Q);
            }
            P = nextVertex(P);
        }
    }else{
        cout << "Graph Kosong !!" << endl;
    }
}

void printGraph(Graph G){
    if(first(G) != NULL){
        adrVertex P = first(G);
        while(P != NULL){
                printf("\t\t\t\t\t");
                cout << "Node " << infoVertex(P).Optical_NE << " :";
                adrEdge Q = child(P);
                    while(Q != NULL){
                        cout << " - " << infoEdge(Q).Optical_NE;
                        Q = nextEdge(Q);
                    }
                cout << endl;
            P = nextVertex(P);
        }

    }else{
        cout << "Graph Kosong !!" << endl;
    }
}

bool isConnected(Graph G, int ID_Vertex, int ID_Edge){
    adrVertex P = findNode(G, ID_Vertex);
    if (P != NULL){
        adrEdge Q = child(P);
        while(Q != NULL && infoEdge(Q).NE_ID != ID_Edge){
            Q = nextEdge(Q);
        }
        return Q != NULL;
    }
}

int findIDbyName(Graph G, string Optical_NE){
    adrVertex P = first(G);
    while(P != NULL && infoVertex(P).Optical_NE != Optical_NE){
        P = nextVertex(P);
    }
    if(P != NULL){
        return infoVertex(P).NE_ID;
    }
}

//MAIN QUEST
void findAllSLA(Graph G, Queue &Q){
    adrVertex P = first(G);
    createQueue(Q);
    while(P != NULL){
        if(infoVertex(P).City_Type == "SLA"){
            adrQueue H = createElementQueue(infoVertex(P));
            enQueue(Q, H);
        }
        P = nextVertex(P);
    }
}

void FindLinkToSLA(Graph G, int ID_City, int ID_SLA, Queue &Visited){
    Queue Q;
    createQueue(Q);

    adrVertex P = findNode(G, ID_City);
    adrQueue J = createElementQueue(infoVertex(P));

    enQueue(Q, J);
    adrQueue x = firstQueue(Q);
    while(firstQueue(Q) != NULL && infoQueue(x).NE_ID != ID_SLA){
        x = deQueue(Q);
        if(isVisited(Q, infoQueue(x).Optical_NE) == false){
            if (isVisited(Visited, infoQueue(x).Optical_NE) == false){
                enQueue(Visited, x);
            }
            adrVertex H = findNode(G, infoQueue(x).NE_ID);
            adrEdge Z = child(H);
            while(Z != NULL){
                adrQueue L = createElementQueue(infoEdge(Z));
                if(!isVisited(Q, infoQueue(L).Optical_NE)){
                    enQueue(Q, L);
                }
                Z = nextEdge(Z);
            }
        }
    }
}

void BFS_Filter(Graph G, Queue Visited, Queue &Path){
    adrQueue P;
    deleteLastQueue(Visited, P);
    inserFirstQueue(Path, P);
    while(firstQueue(Visited) != NULL){
        deleteLastQueue(Visited, P);
        if (isConnected(G, infoQueue(P).NE_ID, infoQueue(firstQueue(Path)).NE_ID)){
            inserFirstQueue(Path, P);
        }
    }
}

void ShowAllLinkToSLA(Graph G, int ID_City, Queue SLAQueue){
    adrQueue P = firstQueue(SLAQueue);
    Queue Path;
    Queue Visited;
    while(P != NULL){
        createQueue(Path);
        createQueue(Visited);
        FindLinkToSLA(G, ID_City, infoQueue(P).NE_ID, Visited);
        if(firstQueue(Visited) == NULL){
            cout << infoQueue(P).Optical_NE << " Merupakan Kota SLA Tidak ada jalan menuju " << infoQueue(P).Optical_NE <<endl << endl;
        }else{
            cout << "Queue BFS : ";
            printQueue(Visited);
            BFS_Filter(G, Visited, Path);
            cout << "Queue Hasil : ";
            printQueue(Path);
            cout << endl;
        }
        P = nextQueue(P);
    }
}

void tentangprogram(){
    printf("\n");
    printf("\t\t\t      =====================================================\n");
    printf("\t\t\t      .___.       ,            .__                      \n");
    printf("\t\t\t        |   _ ._ -+- _.._  _   [__)._. _  _ ._. _.._ _  \n");
    printf("\t\t\t        |  (/,[ ) | (_][ )(_]  |   [  (_)(_][  (_][ | ) \n");
    printf("\t\t\t                          ._|            ._|            \n");
    printf("\t\t\t      =====================================================\n\n");
    printf("\t\t\t      TOPOLOGI JARINGAN WITH ADJENCY LIST AND BFS \n");
    printf("\t\t\t      -> (1) Zaidan Ibnusabil Iryanto           1301213501\n");
    printf("\t\t\t      -> (2) Endri Rizki Nugraha                1301210293\n");
    printf("\t\t\t      Penjelasan Program : \n");
    printf("\t\t\t      \n");
    printf("\t\t\t      Program ini dibuat untuk memenuhi kebutuhan tugas besar \n");
    printf("\t\t\t      Mata Kuliah Struktur Data menggunakan Tipe Linked List  \n");
    printf("\t\t\t      Adjency dan Algoritma Pencarian Graf BFS\n");
}


