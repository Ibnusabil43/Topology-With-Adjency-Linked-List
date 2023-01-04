#include "MultiListHeader.h"

using namespace std;

int main()
{
    //Add Vertex
    Graph G;
    createGraph(G);
    adrVertex P;
    infotype city;


    city.NE_ID = 921;
    city.Optical_NE = "TIMIKA";
    city.City_Type = "SLA";
    city.Project = "SLA";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 923;
    city.Optical_NE = "NABIRE";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P11";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 925;
    city.Optical_NE = "RAISEI";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P11";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 927;
    city.Optical_NE = "RANSIKI";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P13";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 929;
    city.Optical_NE = "MANOKWARI";
    city.City_Type = "SLA";
    city.Project = "SLA";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 935;
    city.Optical_NE = "BIAK";
    city.City_Type = "SLA";
    city.Project = "SLA";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 937;
    city.Optical_NE = "SERUI";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P11";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 939;
    city.Optical_NE = "BOTAWA";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P11";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 949;
    city.Optical_NE = "TANGGUH";
    city.City_Type = "SLA";
    city.Project = "SLA";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 953;
    city.Optical_NE = "BINTUNI";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P13";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 955;
    city.Optical_NE = "KIGAMANI";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P15";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 957;
    city.Optical_NE = "ENAROTALI";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P15";
    P = newVertex(city);
    InsertNE(G, P);

    city.NE_ID = 959;
    city.Optical_NE = "TIGI";
    city.City_Type = "INTERCONNECTION";
    city.Project = "P15";
    P = newVertex(city);
    InsertNE(G, P);

    //Add Edge

    //TIMIKA
    setEdge(G, 921, 959);
    //TIGI
    setEdge(G, 959, 957);
    setEdge(G, 959, 921);
    //ENAROTALI
    setEdge(G, 957, 955);
    setEdge(G, 957, 959);
    //KIGAMANI
    setEdge(G, 955, 923);
    setEdge(G, 955, 957);
    //NABIRE
    setEdge(G, 923, 925);
    setEdge(G, 923, 939);
    setEdge(G, 923, 955);
    //BOTAWA
    setEdge(G, 939, 937);
    setEdge(G, 939, 923);
    //SERUI
    setEdge(G, 937, 935);
    setEdge(G, 937, 939);
    //RAISEI
    setEdge(G, 925, 927);
    setEdge(G, 925, 923);
    //RANSIKI
    setEdge(G, 927, 929);
    setEdge(G, 927, 925);
    setEdge(G, 927, 953);
    //BINTUNI
    setEdge(G, 953, 949);
    setEdge(G, 953, 927);
    //BIAK
    setEdge(G, 935, 937);
    //MANOKOWARI
    setEdge(G, 929, 927);
    //TANGGUH
    setEdge(G, 949, 953);

    //Queue ALL SLA
    Queue allSLA;
    createQueue(allSLA);

    Queue Path;
    Queue Visited;

    string Optical_NE_asal;
    string Optical_NE_SLA;

    int ID_Asal = 0;
    int ID_SLA = 0;

    int pilihan = selectMenu();
    string x;
    while(pilihan != 0){
        switch(pilihan){
        case 1 :
            printf("\t\t\t\t\t ================= GRAPH AWAL ================ \n") ;
            printGraph(G);
            printf("\t\t\t\t\t ============================================= \n");
            break;
        case 2 :
            printf("\t\t\t\t\t =============== QUEUE KOTA SLA ============== \n");
            findAllSLA(G, allSLA);
            printf("\t\t\t\t              ");
            printQueue(allSLA);
            printf("\t\t\t\t\t ============================================= \n");
            break;
        case 3 :
            printf("\t\t\t\t\t =============== PATH TO ONE SLA ============== \n");
            createQueue(Path);
            createQueue(Visited);
            printf("\t\t\t\t\t Silakan Masukkan Nama Kota Asal : ");
            cin >> Optical_NE_asal;
            printf("\t\t\t\t\t Silakan Masukkan Nama Kota SLA : ");
            cin >> Optical_NE_SLA;
            printf("\t\t\t\t\t ============================================= \n");
            ID_Asal = findIDbyName(G, Optical_NE_asal);
            ID_SLA = findIDbyName(G, Optical_NE_SLA);
            FindLinkToSLA(G, ID_Asal, ID_SLA, Visited);
            while(firstQueue(Visited) == NULL){
                printf("\t\t\t\t\t HARAP MASUKKAN KOTA ASAL DAN KOTA TUJUAN YANG BERBEDA !! \n");
                printf("\t\t\t\t\t Silakan Masukkan Nama Kota Asal : ");
                cin >> Optical_NE_asal;
                printf("\t\t\t\t\t Silakan Masukkan Nama Kota SLA : ");
                cin >> Optical_NE_SLA;
                printf("\t\t\t\t\t ============================================= \n");
                ID_Asal = findIDbyName(G, Optical_NE_asal);
                ID_SLA = findIDbyName(G, Optical_NE_SLA);
                FindLinkToSLA(G, ID_Asal, ID_SLA, Visited);
            }
            cout << "Queue BFS : ";
            printQueue(Visited);
            BFS_Filter(G, Visited, Path);
            cout << "Queue Hasil : ";
            printQueue(Path);
            printf("\t\t\t\t\t ============================================= \n");
            break;
        case 4 :
            printf("\t\t\t\t\t =============== PATH TO ALL SLA ============== \n");
            createQueue(allSLA);
            findAllSLA(G, allSLA);
            printf("\t\t\t\t\t Silakan Masukkan Nama Kota Asal : ");
            cin >> Optical_NE_asal;
            ID_Asal = findIDbyName(G, Optical_NE_asal);
            ShowAllLinkToSLA(G, ID_Asal, allSLA);
            printf("\t\t\t\t\t ============================================= \n");
            break;
        case 5 :
            tentangprogram();
            break;
        }
        cout << endl;
        printf("\t\t\t\t\t Kembali Ke Menu Utama? (Y/N) : ");
        cin >> x;
        cout << endl;
        if(x == "N" || x == "n"){
            break;
        }else if(x == "Y" || x == "y"){
            pilihan = selectMenu();
        }
    }
    printf("\t\t\t\t\tANDA TELAH KELUAR DARI PROGRAM");
    printf("\n\n\n\n\n\n");

;

}
