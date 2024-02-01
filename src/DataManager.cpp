/*************************************************************************
                           DataManager  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <DataManager> (fichier DataManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "DataManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type DataManager::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream & operator<<(ostream & out, DataManager & SomeData)
{
    for(map<string, Node>::iterator t = SomeData.data.begin();t!=SomeData.data.end();t++)
    {
        out<<t->first <<"= {";
        for(map<std::string, int>::iterator p = t->second.Dico.begin();p!=t->second.Dico.end();p++)
        {
            out<<"{"<<p->first;
            out<<":"<< p->second<<"}";
            if(p!=next(t->second.Dico.end(),-1))
            {
                out<<",";
            }

        }
        out<<"}"<<endl;
    }
    return out;
}
DataManager &DataManager::operator=(const DataManager &unDataManager)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
DataManager::DataManager(const DataManager &unDataManager)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DataManager>" << endl;
#endif
} //----- Fin de DataManager (constructeur de copie)

DataManager::DataManager(Reader & unReader,int time,int graph, int txtOnly)
// Algorithme :
//
{
    Request rqt;
    while(unReader.CreateRequest(rqt))
    {
    if (data.find(rqt.URL)!=data.end()){
        data[rqt.URL].Hits++;
        if (data[rqt.URL].Dico.find(string(rqt.Referer))!=data[rqt.URL].Dico.end())
        {
            cout<<"oui"<<endl;
            //data[rqt.URL].Dico[rqt.Referer]++;
        }else{
            cout<<"non"<<endl;

            //data[rqt.URL].Dico[rqt.Referer]=1;
        }
    }else {
        Node n;
        n.Hits ++;
        n.Dico[rqt.Referer]=1;
        data[rqt.URL]=n;
        cout<<data[rqt.URL].Hits<<endl;
    }
    }
#ifdef MAP
    cout << "Appel au constructeur de <DataManager>" << endl;
#endif
} //----- Fin de DataManager

DataManager::~DataManager()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DataManager>" << endl;
#endif
} //----- Fin de ~DataManager

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
