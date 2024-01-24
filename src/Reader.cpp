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
void Reader::Read(Request &req)
// Algorithme :
//
{
    getline(file, req.ip, ' ');
    file.ignore(100, '[');

    getline(file, req.date, ':');

    getline(file, req.heure, ' ');
    file.ignore(100, '"');

    getline(file, req.action, ' ');

    getline(file, req.cible, ' ');
    file.ignore(100, ' ');

    getline(file, req.status, ' ');

    getline(file, req.qty, ' ');
    file.ignore(100, '"');

    getline(file, req.referer, '"');
    file.ignore(100, '"');

    getline(file, req.idnav, '"');

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

    file.open(path);
    if ((file.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur d’ouverture de <analog.log>" << endl;
    }
} //----- Fin de Reader

Reader::~Reader()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Reader>" << endl;
#endif
    file.close();
} //----- Fin de ~Reader

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
