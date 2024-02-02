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
#include <fstream>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Node
{
    int Hits=0;
    map<string,int> Dico;
    ostream & operator <<(ostream & out)
    {
        out<<"Nombre de hits : "<<Hits<<endl;
        //affichage de Dico à suivre
    }
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
    //affiche le top 10 des html les plus consultés sur la console
    void top10();
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
    friend ostream & operator<<(ostream& out, DataManager & SomeData);
    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    map<string,Node> data;
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <DataManager>

#endif // DATAMANAGER_H
