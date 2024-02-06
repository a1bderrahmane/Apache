/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 01/02/2024
    copyright            : (C) 2024 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "DataManager.h"
#include "Graph.h"
#include "Reader.h"

int main(int argc, char *argv[])
{
    /*
        Request requete;
       Reader rd = Reader("/tmp/log");

       rd.GetRequest(requete);

       cout << "le requete: " << endl;
       cout << "IP: " << requete.ip << endl;
       cout << "Sdate: " << requete.date << endl;
       cout << "Heure: " << requete.heure << endl;
       cout << "URL: " << requete.URL << endl;
       cout << "Status: " << requete.status << endl;
       cout << "Size: " << requete.size << endl;
       cout << "Referer: " << requete.referer << endl;
       cout << "User_agent: " << requete.user_agent << endl;
    */
    if (argc == 2)
    {
        if (string(argv[1]) == "-h" || string(argv[1]) == "--help")
        {
            string line;
            ifstream help("../src/help.txt");
            if (help.is_open())
            {
                while (getline(help, line))
                {
                    cout << line << '\n';
                }
                help.close();
            }
            exit(0);
        }
    }
    int time = -1;
    int htmlOnly = 0;
    string graph;
    int i;
    for (i = 1; i < argc - 1; i++)
    {
        if (string(argv[i]) == "-t")
        {
            if (stoi(argv[i + 1]) >= 0 && stoi(argv[i + 1]) < 24)
            {
                time = stoi(argv[i + 1]);
                /* cout << "Time : " << time << endl; */
            }
            else
            {
                cerr << "Veuillez entrer une heure entre 0 et 24." << endl;
                cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
                exit(1);
            }
        }
        else if (string(argv[i]) == "-e")
        {
            htmlOnly = 1;
            /*  cout << "htmlOnly : " << htmlOnly << endl; */
        }
        else if (string(argv[i]) == "-g")
        {
            if (string(argv[i + 1]).size() > 3 && string(argv[i + 1]).substr(string(argv[i + 1]).size() - 4, 4) == ".dot")
            {
                graph = string(argv[i + 1]);
                /* cout << "graph : " << graph << endl; */
            }
            else
            {
                cerr << "Format du fichier .dot incorrect." << endl;
                cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
                exit(1);
            }
        }
    }
    string path = argv[argc - 1];

    try
    {
        if (path.substr(path.size() - 4, 4) != ".log" && path.substr(path.size() - 4, 4) != ".txt")
        {
            cerr << "Format du fichier invalide, veuillez entrer un fichier .log ou .txt." << endl;
            cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
            exit(1);
        }
    }
    catch (const std::exception &e)
    {
        cerr << "Format du fichier invalide, veuillez entrer un fichier .log ou .txt." << endl;
        cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
        exit(1);
    }
    /* cout << "path : " << path << endl; */
    DataManager dm(path, time, graph, htmlOnly);
    if (graph.empty() == false)
    {
        Graph(graph).MakeGraph(dm);
    }
    /*  cout << dm; */
    /* string a = "a";
    string b = "b";
    string c = "c";
    string d = "d";
    Node n(a, b);
    n.MAJ(c);
    n.MAJ(c);
    cout << n << endl;

    for (int i = 0; i < argc; i++)
    {
        string str(argv[i]);
        if (str == "-g")
        {
        }
    }
    DataManager d("/tmp/analog.log");
    */
    return 0;
}