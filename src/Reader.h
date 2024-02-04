/*************************************************************************
                           Reader  -  description
                             -------------------
    début                : 01/02/2024
    copyright            : (C) 2024 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
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
    //req:Objet de Request passé en référence

    // Contrat :
    //La ligne lu par GetRequest doit être bien formulée et respect la syntaxe conventionelle

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
    //path: référence de l'adresse de <analog.log>
    // La méthode essaie d'ouvrir le fichier à l'adresse donnée
    // S'il n'arrrive pas , la méthode renvoie un message d'erreur
    

    virtual ~Reader();
    // Mode d'emploi :
    //Ferme le fichier ouvert auparavant


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string path;
    std::ifstream logfile;
};

//-------------------------------- Autres définitions dépendantes de <Reader>
#endif // READER_H
