/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : 01/02/2024
    copyright            : (C) 2024 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ----------------
#if !defined(GRAPH_H)
#define GRAPH_H
#include "DataManager.h"
#include "Reader.h"
#include <fstream>
#include <string>
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
    void MakeGraph(DataManager &SomeData);
    // Mode d'emploi :
    //Somedata: référence d'un objet DataManager
    // La méthode écrit dans le fichier.dot 

    //-------------------------------------------- Constructeurs - destructeur
    Graph(const Graph &unGraph);
    // Mode d'emploi (constructeur de copie) :
    //Ouvre le fichier de même nom que celui de unGraph


    Graph(string name);
    // Mode d'emploi :
    //Ouvre le fichier de nom name, s'il n'existe pas déjà , elle le crée


    virtual ~Graph();
    //Destructeur de la classe

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string name;
    ofstream outputFile;
};

//-------------------------------- Autres définitions dépendantes de <Graph>

#endif // GRAPH_H