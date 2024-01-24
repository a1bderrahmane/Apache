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
#include <fstream>
#include "Request.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
    void Read(Request &req);
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
    ifstream file;
};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif // READER_H
