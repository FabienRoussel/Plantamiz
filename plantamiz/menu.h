#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Matrice.h"
#include "contrat.h"
#include "sauvegarde.h"
#include "deplacement.h"

void affichage_credits();
// Nature : Procédure
// Utilité : permet d'afficher les crédits lorsque l'utilisateur le demande dans le menu
// Entrées internes : aucune
// Sorties internes : aucune
// Entrées externes : aucune
// Sorties externes : affichage des crédits
// Auteur : Fabien Roussel

void affichage_regles();
// Nature : Procédure
// Utilité : permet d'afficher les règles et les commandes utiles au jeu lorsque l'utilisateur le demande dans le menu
// Entrées internes : aucune
// Sorties internes : aucune
// Entrées externes : aucune
// Sorties externes : affichage des règles et commandes
// Auteur : Nicolas Gorrity

int menu0(char tab1[10][15],int leveldumain,char nom[16]);
// Nature : Fonction renvoyant un entier
// Utilité : permet d'afficher le menu à l'écran et de traiter le choix du joueur
// Entrées internes : l'adresse de la matrice de jeu (tableau bidimensionnel de caractères) ; un entier - le niveau ; l'adresse de la chaîne de caractères définissant le nom du joueur
// Sorties internes : renvoi de la valeur du niveau au main
// Entrées externes : obtention du choix de l'utilisateur
// Sorties externes : affichage du menu à l'écran
// Auteur : Fabien Roussel

int nouveau_jeu(char tab1[10][15],int level,int* pt_vies,char nomjoueur[16]);
// Nature : Fonction renvoyant un entier
// Utilité : gère le déroulement d'un niveau
// Entrées internes : l'adresse de la matrice de jeu (tableau bidimensionnel de caractères) ; un entier - le niveau ; l'adresse du nombre de vies restant ; l'adresse de la chaîne de caractères définissant le nom du joueur
// Sorties internes : renvoi de la valeur du niveau au main par le mécanisme de retour, et modification par adresse du nombre de vies
// Entrées externes : obtention du choix du joueur après la proposition de sauvegarde
// Sorties externes : affichage du nombre de coups initial, du numéro du niveau, des modalités de fin de niveau (cas de victoire ou d'échec), et proposition de sauvegarde
// Auteur : Fabien Roussel & Nicolas Gorrity


#endif // MENU_H_INCLUDED
