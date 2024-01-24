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
#include <sstream>  
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Reader.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Reader::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


void Reader::CreateRequest(string &Line,Request& requete)
{
    istringstream sflux(Line);
    sflux >> requete.IP; 
    sflux.ignore(256, '[');      
    getline(sflux, requete.Sdate, ']');
    sflux.ignore(256, '/');
    getline(sflux, requete.URL, '\"');
    sflux >> requete.Status >> requete.Size;
    sflux.ignore(256, '\"');
    getline(sflux, requete.Referer, '\"');
    sflux.ignore(256, '\"');
    getline(sflux, requete.UserAgent, '\"');    
}

void Reader::ReadLine(string &Line)
{
    if (logfile.is_open())
    {
        getline(logfile, Line);
        cout<<Line<<endl;
    }
    else
    {
        cout<<"Can't open file"<<endl;
    }
}
//-------------------------------------------- Constructeurs - destructeur
Reader::Reader(const Reader &unReader)
// Algorithme :
//
{
    
#ifdef MAP
    cout << "Appel au constructeur de copie de <Reader>" << endl;
#endif
} //----- Fin de Reader (constructeur de copie)

Reader::Reader(string nom)
// Algorithme :
//
{
    this->name=nom;
    this->logfile=ifstream(name);
    logfile.open(name);
    if (logfile.is_open()) 
    {
        cout << "Log file open : file.log" << endl;
    }
    else
    {
        cerr<<"couldn't open log file"<<endl;
    }

#ifdef MAP
    cout << "Appel au constructeur de <Reader>" << endl;
#endif
} //----- Fin de Reader

Reader::~Reader()
// Algorithme :
//
{
    logfile.close();
     
#ifdef MAP
    cout << "Appel au destructeur de <Reader>" << endl;
#endif
} //----- Fin de ~Reader

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
