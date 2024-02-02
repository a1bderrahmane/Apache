/*************************************************************************
                           Node  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Node> (fichier Node.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
/*
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Node.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ostream &operator<<(ostream &out, const Node &n)
// Algorithme :
//
{
    cout << "Hits : " << n.hit << endl;
    cout << "Map : ";
    for (map<string, int>::const_iterator it = n.cible.cbegin(); it != n.cible.cend(); ++it)
    {
        cout << it->first << " " << it->second << ", ";
    }
    return out;
} //----- Fin de Méthode

int Node::MAJ(string &target)
// Algorithme :
//
{
    hit++;
    if (map<string, int>::iterator c = cible.find(target); c != cible.end())
    {
        (*c).second++;
        return 0;
    }
    else
    {
        cible.insert(make_pair(target, 1));
        return 0;
    }

    return 1;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Node &Node::operator=(const Node &unNode)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Node::Node(const Node &unNode)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Node>" << endl;
#endif
    hit = unNode.hit;
    cible = unNode.cible;
} //----- Fin de Node (constructeur de copie)

Node::Node(string &nom, string &target)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Node>" << endl;
#endif
    cible.insert(make_pair(target, 1));
} //----- Fin de Node

Node::~Node()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Node>" << endl;
#endif
} //----- Fin de ~Node

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
*/