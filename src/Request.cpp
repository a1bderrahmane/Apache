/*************************************************************************
                           Request  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Request> (fichier Request.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Request.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ostream &operator<<(ostream &out, const Request &r)
// Algorithme :
{
    out << r.ip << "," << endl
        << r.date << "," << endl
        << r.heure << "," << endl
        << r.action << "," << endl
        << r.cible << "," << endl
        << r.status << "," << endl
        << r.qty << "," << endl
        << r.referer << "," << endl
        << r.idnav << endl;
    return out;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Request &Request::operator=(const Request &unRequest)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Request::Request(const Request &unRequest)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Request>" << endl;
#endif
} //----- Fin de Request (constructeur de copie)

Request::Request()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Request>" << endl;
#endif
} //----- Fin de Request

Request::~Request()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Request>" << endl;
#endif
} //----- Fin de ~Request

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées