/*************************************************************************
                           Reader  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Reader> (fichier Reader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Reader.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Reader::GetRequest(Request &requete)
// Algorithme :
//
{
    string line;

    if (logfile)
    {
        getline(logfile, line);
        istringstream sflux(line);
        sflux >> requete.ip;
        sflux.ignore(numeric_limits<streamsize>::max(), '[');
        getline(sflux, requete.date, ':');
        getline(sflux, requete.heure, ' ');
        sflux.ignore(numeric_limits<streamsize>::max(), '"');
        getline(sflux, requete.action, ' ');
        getline(sflux, requete.URL, ' ');
        sflux.ignore(numeric_limits<streamsize>::max(), ' ');
        sflux >> requete.status >> requete.size;
        sflux.ignore(numeric_limits<streamsize>::max(), '\"');
        getline(sflux, requete.referer, '\"');
        sflux.ignore(numeric_limits<streamsize>::max(), '\"');
        getline(sflux, requete.user_agent, '\"');

        return 0;
    }

    return 1;

} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Reader &Reader::operator=(const Reader &unReader)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Reader::Reader(const Reader &unReader)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Reader>" << endl;
#endif
} //----- Fin de Reader (constructeur de copie)

Reader::Reader(const string &path)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Reader>" << endl;
#endif

    this->path = path;
    logfile.open(this->path);
    cout << "reader path : " << this->path << endl;
    if (!logfile.is_open())
    {
        cerr << "Erreur d’ouverture de <analog.log>" << endl;
        exit(1);
    }
} //----- Fin de Reader

Reader::~Reader()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Reader>" << endl;
#endif
    logfile.close();
} //----- Fin de ~Reader

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
