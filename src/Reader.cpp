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
// Cette méthode récupère une requête à partir d'une ligne d'un fichier logfile et la stocke dans un objet Request passé par référence.
// Elle lit chaque ligne du fichier journal, analyse et extrait les informations de la requête, puis les stocke dans l'objet Request.

{
    // Récupération d'une ligne
    string line;
    getline(logfile, line);

    // Lecture de la ligne dans les différents attributs de la requête
    if (logfile)
    {
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

//-------------------------------------------- Constructeurs - destructeur
Reader::Reader(const Reader &unReader)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Reader>" << endl;
#endif
} //----- Fin de Reader (constructeur de copie)

Reader::Reader(const string &path)
{
#ifdef MAP
    cout << "Appel au constructeur de <Reader>" << endl;
#endif

    this->path = path;
    logfile.open(this->path);

    // Erreur si mauvaise ouverture du fichier de log
    if (!logfile.is_open())
    {
        cerr << "Erreur d'ouverture de <" << path << "> dans Reader. Vérifiez que le chemin d'accès est correct et que le fichier existe bien." << endl;
        cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
        exit(1);
    }
} //----- Fin de Reader

Reader::~Reader()
{
#ifdef MAP
    cout << "Appel au destructeur de <Reader>" << endl;
#endif
    logfile.close();
} //----- Fin de ~Reader

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
