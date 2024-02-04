/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ----------------
#if !defined(GRAPH_H)
#define GRAPH_H
#include "DataManager.h"
#include "Reader.h"
#include <fstream>
#include <cstdio>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graph>
//
//
//------------------------------------------------------------------------

class Graph
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Graph &operator=(const Graph &unGraph);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Graph(const Graph &unGraph);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graph(string name);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void MakeGraph(DataManager &SomeData);
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~Graph();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string name;
    ofstream outputFile;
};

//-------------------------------- Autres définitions dépendantes de <Graph>

#endif // GRAPH_H