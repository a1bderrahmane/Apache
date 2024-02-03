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
#include <string>
#include <map>
#include <utility>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
//------------------------------------------------------ Include personnel
#include "DataManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void DataManager::top10(){
//Algorithme :
    map<string,Node> copyData = data;
    vector <pair<string,int>> top;
    for(int i=0;i<10;++i)
    {
        int max=data.begin()->second.Hits;
        string URLmax=data.begin()->first;
        for(map<string,Node>::iterator it=data.begin();it!=data.end();++it)
        {
                if(it->second.Hits>max && it->second.Hits!=-1)
                {
                    max=it->second.Hits;
                    it->second.Hits=-1;
                    URLmax=it->first;
                }
        }
        top.push_back(make_pair(URLmax,max));
    }
    for(vector<pair<string,int>>::iterator iter=top.begin();iter!=top.end();++iter)
    {
        cout<<iter->first<<"("<<iter->second<<" hits)"<<endl;
    }

} // Fin de Méthode

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
    data=unDataManager.data;
} //----- Fin de DataManager (constructeur de copie)

DataManager::DataManager(Reader & unReader,int time,int graph, int txtOnly)
// Algorithme :
//
{
    Request rqt;
    bool flag;
    while(unReader.CreateRequest(rqt))
    {
        flag=true;
        if(rqt.Status!=200)
        {
            flag=false;
        }
        cout<<"statut ok"<<flag<<endl;
        if(flag==true && txtOnly==1 && rqt.URL.substr(rqt.URL.length()-4, 4)!="html")
        {
            flag=false;
        }
        cout<<"html ok"<<flag<<endl;
        if(flag ==true && time!=-1 && stoi(rqt.Sdate.substr(12,2))!=time){
            flag=false;
        }
        cout<<"time ok"<<flag<<endl;
        if(flag==true)
        {
            if (data.find(rqt.URL)!=data.end()){
                data[rqt.URL].Hits++;
                if (data[rqt.URL].Dico.find(string(rqt.Referer))!=data[rqt.URL].Dico.end())
                {
                    data[rqt.URL].Dico[rqt.Referer]++;
                }else{
                    data[rqt.URL].Dico[rqt.Referer]=1;
                }
            }else {
                Node n;
                n.Hits ++;
                n.Dico[rqt.Referer]=1;
                data[rqt.URL]=n;            }
        }

    }
#ifdef MAP
    cout << "Appel au constructeur de <DataManager>" << endl;
#endif
} //----- Fin de DataManager

DataManager::~DataManager()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DataManager>" << endl;
#endif
} //----- Fin de ~DataManager

ostream & operator<<(ostream & out, DataManager & SomeData)
{
    for(map<string, Node>::iterator t = SomeData.data.begin();t!=SomeData.data.end();t++)
    {
        out<<t->first <<"= {";
        for(map<std::string, int>::iterator p = t->second.Dico.begin();p!=t->second.Dico.end();p++)
        {
            out<<"{"<<p->first;
            out<<":"<< p->second<<"}";
            if(p!=next(t->second.Dico.end(),-1))
            {
                out<<",";
            }

        }
        out<<"}"<<endl;
    }
    return out;
}


void MakeDotText(DataManager & SomeData)
{
vector<string> tab_node;
    cout<<"{"<<endl;
    for(map<string, Node>::iterator t = SomeData.data.begin();t!=SomeData.data.end();t++)
    {  
        vector<std::string>::iterator iter = find(tab_node.begin(), tab_node.end(), t->first);
        if (iter == tab_node.end())
        {
            tab_node.push_back(t->first);
            iter = find(tab_node.begin(), tab_node.end(), t->first);
            int indice_ = distance(tab_node.begin(), iter);
            cout<< "node"<< indice_ << "[label :" << t->first << "]" << endl;
        }
        int  indice_ = distance(tab_node.begin(), iter);
        
        for(map<std::string, int>::iterator p = t->second.Dico.begin();p!=t->second.Dico.end();p++)
        {
            vector<std::string>::iterator it = find(tab_node.begin(), tab_node.end(), p->first);
            if (it == tab_node.end())
            {
                tab_node.push_back(p->first);
                it = find(tab_node.begin(), tab_node.end(), p->first);
                int indice = distance(tab_node.begin(), it);
                cout<< "node"<< indice << "[label :" << p->first << "]" << endl;
            }
            int indice = distance(tab_node.begin(), it);
            cout << "node" << indice << "-> node" << indice_ <<"[label : "<< p->second << "]"<< endl;
        }
    }
    cout<<"}"<<endl;
}
   
