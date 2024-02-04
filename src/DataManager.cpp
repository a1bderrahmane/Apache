/*************************************************************************
                           DataManager  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
    map<string, Node> copyData = data;
    vector<pair<string, int>> top;
    for (int i = 0; i < 10; ++i)
    {
        int max = data.begin()->second.hit;
        string URLmax = data.begin()->first;
        for (map<string, Node>::iterator it = data.begin(); it != data.end(); ++it)
        {
            if (it->second.hit > max && it->second.hit != -1)
            {
                max = it->second.hit;
                it->second.hit = -1;
                URLmax = it->first;
            }
        }
        top.push_back(make_pair(URLmax, max));
    }
    for (vector<pair<string, int>>::iterator iter = top.begin(); iter != top.end(); ++iter)
    {
        cout << (*iter).first << "(" << (*iter).second << " hits)" << endl;
    }

} // Fin de Méthode

ostream &operator<<(ostream &out, const DataManager &dm)
// Algorithme :
//
{
    cout << "data : " << endl;
    for (map<string, Node>::const_iterator it = dm.data.cbegin(); it != dm.data.cend(); ++it)
    {
        cout << "Noeud : " << it->first << endl
             << "Hit : " << it->second.hit << endl
             << "Map : ";
        for (map<std::string, int>::const_iterator p = it->second.dico.cbegin(); p != it->second.dico.cend(); p++)
        {
            out << "{" << p->first;
            out << ":" << p->second << "}";
            if (p != next(it->second.dico.end(), -1))
            {
                out << ",";
            }
        }
        cout << endl
             << endl;
    }
    return out;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
DataManager &DataManager::operator=(const DataManager &unDataManager)
// Algorithme :
//
{
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
DataManager::DataManager(const DataManager &unDataManager)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DataManager>" << endl;
#endif
} //----- Fin de DataManager (constructeur de copie)

DataManager::DataManager(const string &path, int time, string graph, int htmlOnly)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DataManager>" << endl;
#endif
    Reader reader(path);
    GetData(reader, time, graph, htmlOnly);
    if (!graph.empty())
    {
        cout << "Appeler les méthodes de Graph" << endl;
    }

} //----- Fin de DataManager

DataManager::~DataManager()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DataManager>" << endl;
#endif
} //----- Fin de ~DataManager

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int DataManager::GetData(Reader &r, int time, string graph, int htmlOnly)
// Algorithme :
//
{
    Request req;
    string referer = ReconstructURL(req.referer);
    bool flag;
    while (!r.GetRequest(req))
    {
        flag = true;
        if (req.status != 200)
        {
            /* cout << "status : " << req.status << endl; */
            flag = false;
        }

        if (flag == true && htmlOnly == 1 && req.URL.substr(req.URL.size() - 4, 4) != "html")
        {
            /* flag = false;
            cout << "HTML Only" << endl; */
        }

        if (flag == true && time != -1 && stoi(req.heure.substr(0, 2)) != time)
        {
            flag = false;
            /* cout << "Time : "
                 << time << endl; */
        }

        if (data.find(req.URL) != data.end())
        {
            data[req.URL].hit++;
            if (!graph.empty())
            {
                if (data[req.URL].dico.find(string(referer)) != data[req.URL].dico.end())
                {
                    data[req.URL].dico[referer]++;
                }
                else
                {
                    data[req.URL].dico[referer] = 1;
                }
            }
        }
        else
        {
            Node n;
            n.hit++;
            if (!graph.empty())
            {
                n.dico[referer] = 1;
            }
            data[req.URL] = n;
        }
    }

    return 0;
} //----- Fin de Méthode

string DataManager::ReconstructURL(string &referent)
// Algorithme :
//
{
    bool slash = false;
    bool point = false;
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
        if (point && slash)
        {
            break;
        }
    }
    cout << slash_pos << endl;
    string result = referent.substr(slash_pos, referent.size() - 1);
    if (result[result.size() - 1] == '/')
    {
        result = result.substr(0, result.size() - 1);
    }
    cout << result << endl;
    return result;
} //----- Fin de Méthode
