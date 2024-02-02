#include <cstring>
#include <iostream>
#include <fstream>


#include "Request.h"
#include "Reader.h"
#include "DataManager.h"
#include "Graph.h"
using namespace std;

int main(int argc, char *argv[])
{ 
    string line;
    Request requete;
    Reader rd = Reader("/tmp/test.log");
    
    rd.CreateRequest(requete);
    
    cout<<"le requete: "<<endl;
    cout<<"IP: "<<requete.IP<<endl;
    cout<<"Sdate: "<< requete.Sdate<<endl;
    cout<<"URL: "<< requete.URL<<endl;
    cout<<"Status: "<< requete.Status<<endl;
    cout<<"Size: "<< requete.Size<<endl;

    // rd.CreateRequest(requete);
    // cout<<"le requete: "<<endl;
    // cout<<"IP: "<<requete.IP<<endl;
    // cout<<"Sdate: "<< requete.Sdate<<endl;
    // cout<<"URL: "<< requete.URL<<endl;
    // cout<<"Status: "<< requete.Status<<endl;
    // cout<<"Size: "<< requete.Size<<endl;
    DataManager DM = DataManager(rd,0,0,0);
    cout<<DM<<endl;
    DM.top10();
    //Graph graph("court.dot");
    //graph.MakeGraph(DM);

    return 0;
}

