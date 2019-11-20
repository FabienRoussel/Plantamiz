#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Matrice.h"
#include "contrat.h"
#include "sauvegarde.h"
#include "deplacement.h"

void affichage_credits();
// Nature : Proc�dure
// Utilit� : permet d'afficher les cr�dits lorsque l'utilisateur le demande dans le menu
// Entr�es internes : aucune
// Sorties internes : aucune
// Entr�es externes : aucune
// Sorties externes : affichage des cr�dits
// Auteur : Fabien Roussel

void affichage_regles();
// Nature : Proc�dure
// Utilit� : permet d'afficher les r�gles et les commandes utiles au jeu lorsque l'utilisateur le demande dans le menu
// Entr�es internes : aucune
// Sorties internes : aucune
// Entr�es externes : aucune
// Sorties externes : affichage des r�gles et commandes
// Auteur : Nicolas Gorrity

int menu0(char tab1[10][15],int leveldumain,char nom[16]);
// Nature : Fonction renvoyant un entier
// Utilit� : permet d'afficher le menu � l'�cran et de traiter le choix du joueur
// Entr�es internes : l'adresse de la matrice de jeu (tableau bidimensionnel de caract�res) ; un entier - le niveau ; l'adresse de la cha�ne de caract�res d�finissant le nom du joueur
// Sorties internes : renvoi de la valeur du niveau au main
// Entr�es externes : obtention du choix de l'utilisateur
// Sorties externes : affichage du menu � l'�cran
// Auteur : Fabien Roussel

int nouveau_jeu(char tab1[10][15],int level,int* pt_vies,char nomjoueur[16]);
// Nature : Fonction renvoyant un entier
// Utilit� : g�re le d�roulement d'un niveau
// Entr�es internes : l'adresse de la matrice de jeu (tableau bidimensionnel de caract�res) ; un entier - le niveau ; l'adresse du nombre de vies restant ; l'adresse de la cha�ne de caract�res d�finissant le nom du joueur
// Sorties internes : renvoi de la valeur du niveau au main par le m�canisme de retour, et modification par adresse du nombre de vies
// Entr�es externes : obtention du choix du joueur apr�s la proposition de sauvegarde
// Sorties externes : affichage du nombre de coups initial, du num�ro du niveau, des modalit�s de fin de niveau (cas de victoire ou d'�chec), et proposition de sauvegarde
// Auteur : Fabien Roussel & Nicolas Gorrity


#endif // MENU_H_INCLUDED
