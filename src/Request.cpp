// /*************************************************************************
//                            Request  -  description
//                              -------------------
//     début                : $DATE$
//     copyright            : (C) $YEAR$ par $AUTHOR$
//     e-mail               : $EMAIL$
// *************************************************************************/

// //---------- Réalisation de la classe <Request> (fichier Request.cpp) ------------

// //---------------------------------------------------------------- INCLUDE

// //-------------------------------------------------------- Include système
// using namespace std;
// #include <iostream>
// #include <sstream>  


// //------------------------------------------------------ Include personnel
// #include "Request.h"

// //------------------------------------------------------------- Constantes

// //----------------------------------------------------------------- PUBLIC

// //----------------------------------------------------- Méthodes publiques
// // type Request::Méthode ( liste des paramètres )
// // Algorithme :
// //
// //{
// //} //----- Fin de Méthode

// //------------------------------------------------- Surcharge d'opérateurs
// Request &Request::operator=(const Request &unRequest)
// // Algorithme :
// //
// {
// } //----- Fin de operator =

// //-------------------------------------------- Constructeurs - destructeur
// Request::Request(const Request &unRequest)
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Request>" << endl;
// #endif
// } //----- Fin de Request (constructeur de copie)

// Request::Request(string &line)
// // Algorithme :
// //
// {
// istringstream sflux(line);
//     sflux >> IP; 
//     sflux.ignore(256, '[');      
//     getline(sflux, Sdate, ']');
//     sflux.ignore(256, '/');
//     getline(sflux, URL, '\"');
//     sflux >> Status >> Size;
//     sflux.ignore(256, '\"');
//     getline(sflux, Referer, '\"');
//     sflux.ignore(256, '\"');
//     getline(sflux, UserAgent, '\"');
// #ifdef MAP
//     cout << "Appel au constructeur de <Request>" << endl;
// #endif
// } //----- Fin de Request

// Request::~Request()
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au destructeur de <Request>" << endl;
// #endif
// } //----- Fin de ~Request

// //------------------------------------------------------------------ PRIVE

// //----------------------------------------------------- Méthodes protégées
