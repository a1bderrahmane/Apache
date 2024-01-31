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
#include "Reader.h"
#include "Request.h"
#include <string>
#include <map>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Node
{
    int Hits=0;
    map<string,int> Dico;
}Node;
//------------------------------------------------------------------------
// Rôle de la classe <DataManager>
//
//
//------------------------------------------------------------------------

class DataManager
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
    DataManager &operator=(const DataManager &unDataManager);
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

    DataManager(Reader & unReader,int time,int graph, int txtOnly);
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
    map<string,Node> data;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <DataManager>

#endif // DATAMANAGER_H
