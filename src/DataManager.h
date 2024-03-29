/*************************************************************************
                           DataManager  -  description
                             -------------------
    début                : 01/02/2024
    copyright            : (C) 2024 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <DataManager> (fichier DataManager.h) ----------------
#if !defined(DATAMANAGER_H)
#define DATAMANAGER_H

//--------------------------------------------------- Interfaces utilisées
#include "Reader.h"
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <algorithm>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Node
{
    int Hit = 0;
    map<string, int> Dico;
} Node;

//------------------------------------------------------------------------
// Rôle de la classe <DataManager>
// La classe DataManager permet de récupérer et traiter les données du Reader en les normalisant et en
// les stockant.
//------------------------------------------------------------------------

class DataManager
{
    //----------------------------------------------------------------- PUBLIC

public:
    friend ostream &operator<<(ostream &out, const DataManager &dm);
    // Permet de pouvoir afficher le contenu de notre data manager durant la phase de développement

    friend void MakeDotText(DataManager &SomeData);
    // Mode d'emploi :
    // SomeData: Référence d'un objet de DataManager
    // La méthode crée le texte correspondant au fichier.dot

    //----------------------------------------------------- Méthodes publiques
    void top10();
    // Mode d'emploi :
    // Méthode qui fournit le top 10 des URL visités
    // Contrat :
    // En cas d'égalité, on prend le top 10 en tenant en compte l'ordre alphabétique

    //------------------------------------------------- Surcharge d'opérateurs
    DataManager &operator=(const DataManager &unDataManager);

    //-------------------------------------------- Constructeurs - destructeur
    DataManager(const DataManager &unDataManager);

    DataManager(const string &path, int time, string graph, int htmlOnly);
    // Mode d'emploi :
    // path     : réference de l'adresse du fichier.log
    // time     :si -1 , ne prend pas le temps en compte, sinon conserve uniquement les requêtes entre t et t+1
    // graph    :si non vide , crée un fichier graph.dot
    // htmlOnly :si 1 , ne prend pas en compte les requetes qui ne sont pas en html
    // Contrat  :
    // Pour prendre en compte les requêtes en temps entre t et t+1 , prend en compte les requetes entre T:00 et T:59 inclu

    virtual ~DataManager();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    int GetData(Reader &r, int time, string graph, int htmlOnly);
    // Mode d'emploi :
    // r        :référence d'un objet Reader
    // htmlOnly :si 1 , ne prend pas en compte les requetes qui ne sont pas en html
    // graph    :si non vide , crée un fichier graph.dot
    // time     :si -1 , ne prend pas le temps en compte, sinon conserve uniquement les requêtes entre t et t+1

    void ReconstructURL(string &referent, string &cible);
    // Paramètres:
    // referent : URL du référent de la requête courante
    // cible    : URL de la cible de la requête courante
    // Mode d'emploi :
    // Permet de normaliser les cibles et les référents en ne prennant en compte que le chemin relatif,
    // sans les éventuelles options de recherche et caractère indésirables

    //----------------------------------------------------- Attributs protégés
    map<string, Node> data;
};

//-------------------------------- Autres définitions dépendantes de <DataManager>

#endif // DATAMANAGER_H
