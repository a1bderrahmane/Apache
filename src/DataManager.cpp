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
    if (data.find("URL_test")!=data.end()){
        cout<<"existe"<<endl;
    }else {
        Node n;
        n.Hits ++;
        n.Dico[rqt.Referer]=1;
        data[rqt.URL]=n;
        //cout<<data[rqt.URL]<<endl;
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
