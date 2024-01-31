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
#include <string>
#include <fstream>
using namespace std;
//--------------------------------------------------- Interfaces utilisées
typedef struct Request
{
    string IP;
    string Sdate;
    string URL;
    int Status;
    int Size;
    string Referer;
    string UserAgent;
}Request;

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ReadLine(string &Line);
    //------------------------------------------------- Surcharge d'opérateurs
    void CreateRequest(string &Line,Request& requete);
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

    Reader(string nom);
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
    string name;
    std::ifstream logfile;
    
    //----------------------------------------------------- Attributs protégés
   
};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif // READER_H
