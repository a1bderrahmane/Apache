/*************************************************************************
                           Node  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

/* //---------- Interface de la classe <Node> (fichier Node.h) ----------------
#if !defined(NODE_H)
#define NODE_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <utility>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Node>
//
//
//------------------------------------------------------------------------

class Node
{
    //----------------------------------------------------------------- PUBLIC

public:
    friend class DataManager;
    friend ostream &operator<<(ostream &out, const Node &n);
    //----------------------------------------------------- Méthodes publiques
    int MAJ(string &cible);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Node &
    operator=(const Node &unNode);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Node(const Node &unNode);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Node(string &nom, string &target);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Node();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    int hit = 1;
    map<string, int> cible;
};

//-------------------------------- Autres définitions dépendantes de <Node>

#endif // NODE_H
 */