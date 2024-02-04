/*************************************************************************
                           DataManager  -  description
                             -------------------
    début                : 01/02/2024
    copyright            : (C) 2023 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <DataManager> (fichier DataManager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "DataManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void DataManager::top10()
{
    // Algorithme :
    // Cette fonction récupère les 10 premières cibles en fonction de la valeur 'Hit' dans la map 'data'.
    // Elle crée une copie de la map d'origine pour éviter de modifier la map originale.

    //Créer une copie de la map 'data'
    map<string, Node> copyData = data;
    //Initialiser un vecteur pour stocker les paires d'URL et de compte de hits (10 maxima)
    vector<pair<string, int>> top;
    // Itérer 10 fois pour trouver les 10 premières entrées
    for (int i = 0; i < 10; ++i)
    {
        // Initialiser des variables pour suivre le nombre de hits maximum et l'URL correspondant
        int max = data.begin()->second.Hit;
        string URLmax = data.begin()->first;

        // Itérer à travers la map copyData pour trouver l'entrée avec le nombre de hits maximum
        for (map<string, Node>::iterator it = data.begin(); it != data.end(); ++it)
        {
            // Vérifier si le nombre de hits actuel est supérieur au maximum actuel
            if (it->second.Hit > max && it->second.Hit != -1)
            {
                // Mettre à jour le nombre de hits maximum et l'URL correspondant
                max = it->second.Hit;
                it->second.Hit = -1; //cette cible ne doit plus être prise en compte
                URLmax = it->first;
            }
        }
        //Ajouter la paire d'URL et de compte de hits au vecteur 'top'
        top.push_back(make_pair(URLmax, max));
    }
    //Afficher les 10 premières entrées
    for (vector<pair<string, int>>::iterator iter = top.begin(); iter != top.end(); ++iter)
    {
        cout << (*iter).first << "(" << (*iter).second << " hits)" << endl;
    }

} // Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &out, const DataManager &dm)
{
    cout << "data : " << endl;
    for (map<string, Node>::const_iterator it = dm.data.cbegin(); it != dm.data.cend(); ++it)
    {
        cout << "Noeud : " << it->first << endl
             << "Hit : " << it->second.Hit << endl
             << "Map : ";
        for (map<std::string, int>::const_iterator p = it->second.Dico.cbegin(); p != it->second.Dico.cend(); p++)
        {
            out << "{" << p->first;
            out << ":" << p->second << "}";
            if (p != next(it->second.Dico.end(), -1))
            {
                out << ",";
            }
        }
        cout << endl
             << endl;
    }
    return out;
} //----- Fin de Méthode

DataManager &DataManager::operator=(const DataManager &unDataManager)
// Algorithme :
//
{
    data=unDataManager.data;
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
DataManager::DataManager(const DataManager &unDataManager)
// Algorithme :
//
{
    data=unDataManager.data;
#ifdef MAP
    cout << "Appel au constructeur de copie de <DataManager>" << endl;
#endif
} //----- Fin de DataManager (constructeur de copie)


DataManager::DataManager(const string &path, int time, string graph, int htmlOnly)
// Algorithme :
//Utilise la méthode GetData pour créer un objet de DataManager
{
#ifdef MAP
    cout << "Appel au constructeur de <DataManager>" << endl;
#endif
    Reader reader(path); //instancie un Reader
    GetData(reader, time, graph, htmlOnly);
    if (!graph.empty())
    {
        cout << "Appeler les méthodes de Graph" << endl;
    }

} //----- Fin de DataManager

DataManager::~DataManager()
{
#ifdef MAP
    cout << "Appel au destructeur de <DataManager>" << endl;
#endif
} //----- Fin de ~DataManager

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int DataManager::GetData(Reader &r, int time, string graph, int htmlOnly)
// Algorithme :
// Cette méthode récupère des données à partir d'un objet Reader en fonction de certains critères.
// Elle analyse chaque requête, vérifie si elle satisfait les conditions spécifiées, et met à jour la structure de données (data).
{
    Request req;
    string referer = ReconstructURL(req.referer); //si l'URL est locale, garde seulement la partie locale
    bool flag;
    while (!r.GetRequest(req))
    {
        cout<<req.URL<<endl;
        flag = true;
        // Vérifier si le statut de la requête est 200 (OK)
        if (req.status != 200)
        {
            flag = false;
        }
        // Vérifier si la requête doit être de type HTML uniquement
        if (flag == true && htmlOnly == 1 && req.URL.substr(req.URL.size() - 4, 4) != "html")
        {
            flag = false;
            cout << "HTML Only" << endl;
        }
        // Vérifier si la requête est dans la plage horaire spécifiée

        if (flag == true && time != -1 && stoi(req.heure.substr(0, 2)) != time)
        {
            flag = false;
            cout << "Time : "
                 << time << endl;
        }
        // Mettre à jour les données en fonction de la requête
        if (data.find(req.URL) != data.end())
        {
            // La requête existe déjà dans les données, mettre à jour le compteur de hits
            data[req.URL].Hit++;
            // Mettre à jour le dictionnaire de référents si la fonctionnalité de graphe est activée
            if (graph.empty() == false)
            {
                if (data[req.URL].Dico.find(string(referer)) != data[req.URL].Dico.end()) //si l'URL est déjà présente dans dico
                {
                    data[req.URL].Dico[referer]++;
                }
                else //il faut créer l'URL dans dico
                {
                    data[req.URL].Dico[referer] = 1;
                }
            }
        }
        else
        {
            // La requête est nouvelle, créer un nouveau Node
            Node n;
            n.Hit++;
            cout<<n.Hit<<endl;
            // Mettre à jour la map de référents si la fonctionnalité de graphe est activée
            if (graph.empty() == false)
            {
                n.Dico[referer] = 1;
                data[req.URL] = n;
            }
        }
    }
    return 0;
} //----- Fin de Méthode

string DataManager::ReconstructURL(string &referent)
// Algorithme :
// Cette méthode reconstruit une URL à partir d'une chaîne de référence en considérant les caractères '/' et '.'.
// Elle recherche le dernier '/' et '.' dans la chaîne, puis reconstruit l'URL en prenant la sous-chaîne entre ces positions.

{
    // Variables pour suivre la présence des caractères '/' et '.'
    bool slash = false;
    bool point = false;
    // Position du dernier caractère '/'
    size_t slash_pos = 0;
    int i;
    for (i = referent.size(); i > 0; --i)
    {
        if (referent[i] == '/')
        {
            point = false;
            slash = true;
            slash_pos = i;
        }
        else if (referent[i] == '.')
        {
            point = true;
        }
        // Si à la fois le caractère '.' et '/' sont trouvés, arrêter la boucle
        if (point && slash)
        {
            break;
        }
    }
    // Reconstruction de l'URL à partir de la sous-chaîne entre le dernier '/' et '.'

    string result = referent.substr(slash_pos, referent.size() - 1);
    // Supprimer le dernier '/' s'il est présent à la fin de la sous-chaîne

    if (result[result.size() - 1] == '/')
    {
        result = result.substr(0, result.size() - 1);
    }
    cout << result << endl;
    return result;
} //----- Fin de Méthode


void MakeDotText(DataManager & SomeData)
// Algorithme :
// Cette fonction génère du code DOT pour représenter graphiquement les données stockées dans SomeData.
// Les données consistent en une map principale (data) contenant des nœuds, chacun associé à un label et un dictionnaire (dico)
// avec des relations vers d'autres nœuds et des poids pour ces relations.
{
// Vecteur pour suivre les nœuds déjà traités
vector<string> tab_node;
    cout<<"{"<<endl;
    // Parcours de la map principale
    for(map<string, Node>::iterator t = SomeData.data.begin();t!=SomeData.data.end();t++)
    {          
        // Vérifier si le nœud a déjà été traité
        vector<std::string>::iterator iter = find(tab_node.begin(), tab_node.end(), t->first);
        // Si le nœud n'a pas encore été traitéc
        if (iter == tab_node.end())
        {
            // Ajouter le nœud au vecteur et obtenir son indice
            tab_node.push_back(t->first);
            iter = find(tab_node.begin(), tab_node.end(), t->first);
            int indice_ = distance(tab_node.begin(), iter);
            // Afficher le nœud avec son libellé
            cout<< "node"<< indice_ << "[label :" << t->first << "]" << endl;
        }
        // Obtenir l'indice du nœud
        int  indice_ = distance(tab_node.begin(), iter);
        // Parcours de la map dans chaque nœud
        for(map<std::string, int>::iterator p = t->second.Dico.begin();p!=t->second.Dico.end();p++)
        {
            // Vérifier si le nœud a déjà été traité
            vector<std::string>::iterator it = find(tab_node.begin(), tab_node.end(), p->first);
            // Si le nœud n'a pas encore été traité

            if (it == tab_node.end())
            {
                // Ajouter le nœud au vecteur et obtenir son indice
                tab_node.push_back(p->first);
                it = find(tab_node.begin(), tab_node.end(), p->first);
                int indice = distance(tab_node.begin(), it);
                // Afficher le nœud avec son libellé
                cout<< "node"<< indice << "[label :" << p->first << "]" << endl;
            }
            // Obtenir l'indice du nœud
            int indice = distance(tab_node.begin(), it);
            // Afficher la relation entre les nœuds avec le libellé
            cout << "node" << indice << "-> node" << indice_ <<"[label : "<< p->second << "]"<< endl;
        }
    }
    cout<<"}"<<endl;
}