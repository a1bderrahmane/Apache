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

    // Créer une copie de la map 'data'
    map<string, Node> copyData = data;
    // Initialiser un vecteur pour stocker les paires d'URL et de compte de hits (10 maxima)
    vector<pair<string, int>> top;
    // Itérer 10 fois pour trouver les 10 premières entrées
    for (int i = 0; i < 10; ++i)
    {
        // Initialiser des variables pour suivre le nombre de hits maximum et l'URL correspondant
        /* int max = data.begin()->second.Hit;
        string URLmax = data.begin()->first; */

        bool found = false;
        map<string, Node>::iterator maxi = copyData.begin();

        // Itérer à travers la map copyData pour trouver l'entrée avec le nombre de hits maximum
        for (map<string, Node>::iterator it = copyData.begin(); it != copyData.end(); ++it)
        {
            /* cout << "url :" << it->first << endl;
            cout << "hit :" << it->second.Hit << endl; */
            // Vérifier si le nombre de hits actuel est supérieur au maximum actuel
            if (it->second.Hit >= maxi->second.Hit && it->second.Hit != -1)
            {
                found = true;
                maxi = it;
                // Mettre à jour le nombre de hits maximum et l'URL correspondant
                /* max = it->second.Hit;
                it->second.Hit = -1; // cette cible ne doit plus être prise en compte
                URLmax = it->first; */
            }
        }
        /* cout << "final :" << maxi->first << endl; */
        if (found)
        {
            // Ajouter la paire d'URL et de compte de hits au vecteur 'top'
            top.push_back(make_pair(maxi->first, maxi->second.Hit));
            maxi->second.Hit = -1;
        }
    }

    // Vérifier si le fichier fournit est vide (classement vide)
    if (top.empty())
    {
        cerr << "Le fichier fourni est vide." << endl;
        cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
        exit(1);
    }
    else
    {
        // Afficher les 10 premières entrées
        int i = 1;
        for (vector<pair<string, int>>::iterator iter = top.begin(); iter != top.end(); ++iter, ++i)
        {
            cout << i << ". " << (*iter).first << "(" << (*iter).second << " hits)" << endl;
        }
    }

} // Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &out, const DataManager &dm)
{
    cout << "data : " << endl;

    // Itération à travers le datamanager et les noeuds pour les afficher
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
{
    data = unDataManager.data;
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
DataManager::DataManager(const DataManager &unDataManager)
{
    data = unDataManager.data;
#ifdef MAP
    cout << "Appel au constructeur de copie de <DataManager>" << endl;
#endif
} //----- Fin de DataManager (constructeur de copie)

DataManager::DataManager(const string &path, int time, string graph, int htmlOnly)
// Algorithme :
// Utilise la méthode GetData pour récupérer les données et la méthode top10() pour réaliser et afficher le top10
{
#ifdef MAP
    cout << "Appel au constructeur de <DataManager>" << endl;
#endif
    Reader reader(path); // instancie un Reader
    GetData(reader, time, graph, htmlOnly);
    top10();
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
    bool flag;
    while (!r.GetRequest(req)) // Tant qu'on est pas à la fin du fichié
    {
        ReconstructURL(req.referer, req.URL); // si l'URL est locale, garde seulement la partie locale
        flag = true;                          // Drapeau permettant de spécifier si la requête courante doit être prise en compte (true) ou non (false)

        // Vérifier si le statut de la requête est 200 (OK)
        if (req.status >= 400)
        {
            flag = false;
        }

        // Vérifier si la requête ne soit pas de type image, javascript ou css si on est en mode -e
        set<string> EXTENSIONS_INTERDITES = {
            ".js",
            ".jsx",
            ".css",
            ".svg",
            ".jpg",
            ".jpeg",
            ".gif",
            ".png",
            ".bmp"
            ".tiff",
            ".tif",
            ".ai",
            ".eps",
            ".ico",
            ".webp",
            ".raw"};
        size_t pos_point = req.URL.find_last_of('.');
        if (pos_point != string::npos)
        {
            if (flag == true && htmlOnly == 1 && find(EXTENSIONS_INTERDITES.begin(), EXTENSIONS_INTERDITES.end(), req.URL.substr(pos_point, req.URL.size() - pos_point)) != EXTENSIONS_INTERDITES.end())
            {
                flag = false;
                /* cout << "HTML Only" << endl; */
            }
        }

        // Vérifier si la requête est dans la plage horaire spécifiée si on est en mode -t
        if (flag == true && time != -1 && stoi(req.heure.substr(0, 2)) != time)
        {
            flag = false;
            /* cout << "Time : "
                 << time << endl; */
        }

        // Mettre à jour les données en fonction de la requête
        if (flag == true)
        {
            if (data.find(req.URL) != data.end())
            {
                // La requête existe déjà dans les données, mettre à jour le compteur de hits
                data[req.URL].Hit++;
                // Mettre à jour le dictionnaire de référents si la fonctionnalité de graphe est activée
                if (graph.empty() == false)
                {
                    if (data[req.URL].Dico.find(string(req.referer)) != data[req.URL].Dico.end()) // si l'URL est déjà présente dans dico
                    {
                        data[req.URL].Dico[req.referer]++;
                    }
                    else // il faut créer l'URL dans dico
                    {
                        data[req.URL].Dico[req.referer] = 1;
                    }
                }
            }
            else
            {
                // La requête est nouvelle, créer une nouveau Node
                Node n;
                n.Hit++;
                // Mettre à jour la map de référents si la fonctionnalité de graphe est activée
                if (graph.empty() == false)
                {
                    n.Dico[req.referer] = 1;
                }
                data[req.URL] = n;
            }
        }
    }
    return 0;
} //----- Fin de Méthode

void DataManager::ReconstructURL(string &referent, string &cible)
// Algorithme :
// Cette méthode "reconstruit" le referent pour ne garder que le chemin relatif.
// Elle retrouve la position du '/' précedant le chemin relatif en partant du principe qu'en partant de la fin
// de la chaine, si on croise un '/' puis en '.' dans cet ordre ci et sans autre '/' entre les deux, alors on
// a atteint la position du '/' recherché.
// Elle permet aussi de supprimer les '/' en trop à la fin des cibles et/ou référents.
// Elle permet aussi de se débarrasser des options (suivant les caractères '?', ';' ou '#') dans les requêtes
{
    // Supprimer les '/' en trop à la fin du référent
    if (referent.size() > 0)
    {
        int j = referent.size();
        while (referent[j - 1] == '/')
        {
            referent = referent.substr(0, j - 1);
            j--;
        }
    }

    // Retrouver le chemin relatif pour le référent
    // Variables pour suivre la présence des caractères '/' et '.'
    bool slash = false;
    bool point = false;
    // Position du caractère '/' après lequel apparait l'url relatif
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
        else if (referent[i] == '.' || referent[i] == ':')
        {
            point = true;
        }
        // Si à la fois le caractère '.' et '/' sont trouvés, arrêter la boucle
        if (point && slash)
        {
            break;
        }
    }
    // Reconstruction de l'URL
    referent = referent.substr(slash_pos, referent.size());

    // Supprimer les options du référent
    size_t opt_pos = min(referent.find('?'), min(referent.find(';'), referent.find('#')));
    if (opt_pos != string::npos)
    {
        /*         cout << referent[opt_pos] << endl; */
        referent.resize(opt_pos);
    }

    // Supprimer les '/' en trop à la fin de la cible
    if (cible.size() > 0)
    {
        int t = cible.size();
        while (cible[t - 1] == '/')
        {
            cible = cible.substr(0, t - 1);
            t--;
        }
    }

    // Supprimer les options de la cible
    size_t opt_pos_c = min(cible.find('?'), min(cible.find(';'), cible.find('#')));
    if (opt_pos_c != string::npos)
    {
        cible.resize(opt_pos_c);
    }
} //----- Fin de Méthode

void MakeDotText(DataManager &SomeData)
// Algorithme :
// Cette fonction génère du code DOT pour représenter graphiquement les données stockées dans SomeData.
// Les données consistent en une map principale (data) contenant des nœuds, chacun associé à un label et un dictionnaire (dico)
// avec des relations vers d'autres nœuds et des poids pour ces relations.
{
    // Vecteur pour suivre les nœuds déjà traités
    vector<string> tab_node;
    cout << "digraph {" << endl
         << "fontname=\"Helvetica,Arial,sans-serif\";" << endl
         << "node [fontname=\"Helvetica,Arial,sans-serif\"];" << endl
         << "edge [fontname=\"Helvetica,Arial,sans-serif\"];" << endl
         << "overlap = scale;"
         << "layout=sfdp;" << endl
         << "graph [ranksep=3, overlap=prism];" << endl;

    for (map<string, Node>::iterator t = SomeData.data.begin(); t != SomeData.data.end(); t++)
    {
        // Vérifier si le nœud a déjà été traité
        vector<std::string>::iterator iter = find(tab_node.begin(), tab_node.end(), t->first);
        // Si le nœud n'a pas encore été traité
        if (iter == tab_node.end())
        {
            // Ajouter le nœud au vecteur et obtenir son indice
            tab_node.push_back(t->first);
            iter = find(tab_node.begin(), tab_node.end(), t->first);
            int indice_ = distance(tab_node.begin(), iter);
            // Afficher le nœud avec son libellé
            cout << "node" << indice_ << "[label=\"" << t->first << "\"]" << endl;
        }
        // Obtenir l'indice du nœud
        int indice_ = distance(tab_node.begin(), iter);
        // Parcours de la map dans chaque nœud
        for (map<std::string, int>::iterator p = t->second.Dico.begin(); p != t->second.Dico.end(); p++)
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
                cout << "node" << indice << "[label=\"" << p->first << "\"]" << endl;
            }
            // Obtenir l'indice du nœud
            int indice = distance(tab_node.begin(), it);
            // Afficher la relation entre les nœuds avec le libellé
            cout << "node" << indice << " -> node" << indice_ << "[label=\"" << p->second << "\"]" << endl;
        }
    }
    cout << "}" << endl;
}