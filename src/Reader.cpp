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


int Reader::CreateRequest(Request& requete)
{
    string Line;
    if (logfile)
    {
        getline(logfile, Line);
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
        return 1;
    }
    else
    {
        return 0;
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
    this->name=unReader.name;
    this->logfile=ifstream(this->name);
    logfile.open(this->name);
    if (logfile.is_open()) 
    {
        cout << "Log file open : file.log" << endl;
    }
    else
    {
        cerr<<"couldn't open log file"<<endl;
    }


} //----- Fin de Reader (constructeur de copie)

Reader::Reader(string nom)
// Algorithme :
//
{
    this->name=nom;
    this->logfile=ifstream(name);
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
