#include <cstring>
#include "Reader.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    
    string line;
    Request requete;
    Reader rd = Reader("/tmp/file.log");
    
    rd.ReadLine(line);
    cout<<line<<endl;
    rd.CreateRequest(line, requete);
    
    
    cout<<"le requete :"<<endl;
    cout<<"IP"<<requete.IP<<endl;
    cout<<"Sdate"<< requete.Sdate<<endl;
    cout<<"URL"<< requete.URL<<endl;
    cout<<"Status"<< requete.Status<<endl;
    cout<<"Size"<< requete.Size<<endl;

    return 0;
}

