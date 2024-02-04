/*************************************************************************
                           Reader  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Reader> (fichier Reader.h) ----------------

#if !defined(READER_H)
#define READER_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <fstream>
#include <sstream>
#include <limits>
#include "Request.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Request
{
    string ip;
    string date;
    string heure;
    string action;
    string URL;
    int status;
    int size;
    string referer;
    string user_agent;
} Request;

//------------------------------------------------------------------------
// Rôle de la classe <Reader>
//
//
//------------------------------------------------------------------------

class Reader
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    int GetRequest(Request &req);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Reader &operator=(const Reader &unReader);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Reader(const Reader &unReader);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Reader(const string &path);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Reader();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string path;
    std::ifstream logfile;
};

//-------------------------------- Autres définitions dépendantes de <Reader>
#endif // READER_H
