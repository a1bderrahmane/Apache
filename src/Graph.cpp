/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "DataManager.h"
#include "Reader.h"
#include<fstream>
#include <string>
 #include <cstdio>

//------------------------------------------------------ Include personnel
#include "Graph.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graph::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Graph &Graph::operator=(const Graph &unGraph)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Graph::Graph(const Graph &unGraph)
// Algorithme :
//
{
    this->name=unGraph.name;
    this->outputFile=ofstream(unGraph.name);

    if (!outputFile.is_open()) 
    {
        cerr << "couldn't create or open dot file: " << name << endl;
    }
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
} //----- Fin de Graph (constructeur de copie)

void Graph::MakeGraph(DataManager & SomeData)
{
    streambuf *originalCoutBuffer =cout.rdbuf(); 
    cout.rdbuf(outputFile.rdbuf());
    cout<<SomeData<<endl;
    cout.rdbuf(originalCoutBuffer);
}
Graph::Graph(string name)
// Algorithme :
//
{
    // string filename = "court.dot";
    this->name=name;
    this->outputFile=ofstream(name);

    if (!outputFile.is_open()) 
    {
        cerr << "couldn't create or open dot file: " << name << endl;
    }

#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
} //----- Fin de Graph

Graph::~Graph()
// Algorithme :
//
{
    outputFile.close();
#ifdef MAP
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
} //----- Fin de ~Graph

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
