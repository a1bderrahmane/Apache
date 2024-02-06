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
    // Détecter si le paramètre est help
    if (argc == 2)
    {
        if (string(argv[1]) == "-h" || string(argv[1]) == "--help")
        {
            string line;
            // Chemin du fichier help.txt contenant le texte d'aide à afficher dans le terminal
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

    // Variables à passer au DataManager représentant les différentes options
    int time = -1;
    int htmlOnly = 0;
    string graph;

    // Détection des différents paramètres
    int i;
    for (i = 1; i < argc - 1; i++)
    {
        if (string(argv[i]) == "-t")
        {
            if (stoi(argv[i + 1]) >= 0 && stoi(argv[i + 1]) < 24)
            {
                time = stoi(argv[i + 1]);
            }
            else // Erreur si l'heure n'est pas au bon format
            {
                cerr << "Veuillez entrer une heure entre 0 et 24." << endl;
                cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
                exit(1);
            }
        }
        else if (string(argv[i]) == "-e")
        {
            htmlOnly = 1;
        }
        else if (string(argv[i]) == "-g")
        {
            if (string(argv[i + 1]).size() > 3 && string(argv[i + 1]).substr(string(argv[i + 1]).size() - 4, 4) == ".dot")
            {
                graph = string(argv[i + 1]);
            }
            else // Erreur si le chemin du fichier .dot n'est pas au bon format
            {
                cerr << "Format du fichier .dot incorrect." << endl;
                cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
                exit(1);
            }
        }
    }

    // Le chemin du fichier de log à traiter se trouve forcément à la fin de la commande
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
    catch (const std::exception &e) // Erreur si on ne peut pas faire substr parce que path est trop petit
    {
        cerr << "Format du fichier invalide, veuillez entrer un fichier .log ou .txt." << endl;
        cerr << "Entrez './analog -h' ou './analog --help' pour obtenir la liste des commandes" << endl;
        exit(1);
    }

    // On appelle le datamanager
    DataManager dm(path, time, graph, htmlOnly);

    // On appelle la classe graph pour créer le .dot
    if (graph.empty() == false)
    {
        Graph(graph).MakeGraph(dm);
    }
    return 0;
}