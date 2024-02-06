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

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Graph.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Graph::MakeGraph(DataManager &SomeData)
// Algorithme :
// On utilise la méthode amie de la classe DataManager MakeDotText pour faire l'affichage dans le fichier.dot
{
    // Redirection du stream buffer associé à l’objet cout sur le stream buffer associé à OutputFile
    // en conservant l’adresse de l’ancien stream buffer de cout
    streambuf *originalCoutBuffer = cout.rdbuf();
    cout.rdbuf(outputFile.rdbuf());
    MakeDotText(SomeData);
    // Restauration du stream buffer par défaut pour cout
    cout.rdbuf(originalCoutBuffer);
}

//-------------------------------------------- Constructeurs - destructeur
Graph::Graph(const Graph &unGraph)
{
    this->name = unGraph.name;
    this->outputFile = ofstream(unGraph.name);

    if (!outputFile.is_open())
    {
        cerr << "Erreur d'ouverture de <" << unGraph.name << ">" << endl;
    }
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
} //----- Fin de Graph (constructeur de copie)

Graph::Graph(string name)
{
    this->name = name;
    this->outputFile = ofstream(name);

    if (!outputFile.is_open())
    {
        cerr << "Erreur d'ouverture de <" << name << ">" << endl;
        cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
        exit(1);
    }

#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
} //----- Fin de Graph

Graph::~Graph()
{
    outputFile.close();
#ifdef MAP
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
} //----- Fin de ~Graph

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées