/*************************************************************************
                           DataManager  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <DataManager> (fichier DataManager.h) ----------------
#if !defined(DATAMANAGER_H)
#define DATAMANAGER_H

//--------------------------------------------------- Interfaces utilisées
#include "Reader.h"
#include "Node.h"
#include <iterator>
#include <map>
#include <vector>
#include <utility>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Node
{
    int hit = 0;
    map<string, int> dico;
} Node;
//------------------------------------------------------------------------
// Rôle de la classe <DataManager>
//
//
//------------------------------------------------------------------------

class DataManager
{
    //----------------------------------------------------------------- PUBLIC

public:
    friend ostream &operator<<(ostream &out, const DataManager &dm);
    //----------------------------------------------------- Méthodes publiques
    void top10();

    //------------------------------------------------- Surcharge d'opérateurs
    DataManager &
    operator=(const DataManager &unDataManager);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    DataManager(const DataManager &unDataManager);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DataManager(const string &path, int time, string graph, int htmlOnly);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DataManager();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    int GetData(Reader &r, int time, string graph, int htmlOnly);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string ReconstructURL(string &referent);
    // Mode d'emploi : L'URL des cibles n'est pas complète, il faut la reconstruire
    //
    // Contrat :
    //

    //----------------------------------------------------- Attributs protégés
    bool t = false;
    bool e = false;
    bool g = false;
    map<string, Node> data;
};

//-------------------------------- Autres définitions dépendantes de <DataManager>

#endif // DATAMANAGER_H
