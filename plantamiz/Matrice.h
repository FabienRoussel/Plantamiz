#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "affichage.h"


void gravity(char tab1[10][15],int niveau);
// Nature : Proc�dure
// Utilit� : permet de faire "tomber" le caract�re qui se trouve au dessus de chaque espace
// Entr�es internes : adresse de la matrice de jeu (tableau bidimensionnel de caract�res) ; et un entier : le niveau
// Sorties internes : modification de la matrice de jeu par adresse
// Entr�es externes : aucune
// Sorties externes : affichage de la "chute" des items
// Auteur : Fabien Roussel


void newtab(char tab1[10][15], int contrat[5],int niveau);
// Nature : Proc�dure
// Utilit� : permet de g�n�rer la matrice initiale au d�but du niveau et de traiter les combinaisons �ventuellement pr�sentes (gr�ce � l'appel de suppression_combinaisons et de gravity)
// Entr�es internes : l'adresse de la matrice de jeu (tableau bidimensionnel de caract�res), l'adresse du vecteur d'entiers d�finissant le contrat ; et le niveau du joueur (entier)
// Sorties internes : modification de la matrice de jeu par adresse
// Entr�es externes : aucune
// Sorties externes : affichage de chaque case de la matrice
// Auteur : Fabien Roussel

int rang_fonction_de_item(char val);
// Nature : Fonction renvoyant un entier
// Utilit� : permet d'acc�der � la bonne case du vecteur d'entiers correspondant au contrat en fonction de l'item actuellement trait� dans le tableau
// Entr�es internes : un caract�re - celui contenu dans la case du tableau
// Sorties internes : un entier - le rang du tableau contrat correspondant � l'item
// Entr�es externes : aucune
// Sorties externes : aucune
// Auteur : Nicolas Gorrity

int suppression_combinaisons(int contrat[5],char tableau[10][15],int leveljoueur);
// Nature : Fonction renvoyant un entier
// Utilit� : permet d'effacer les combinaisons du tableau, de modifier en cons�quence l'�tat du contrat, et de compter le nombre de combinaisons trouv�es
// Entr�es internes : l'adresse du vecteur d'entiers d�finissant le contrat, l'adresse de la matrice de jeu (tableau bidimensionnel de caract�res), et un entier - le niveau
// Sorties internes : un entier - le nombre de combinaisons trouv�es ; modification des valeurs de la matrice de jeu et de celles du contrat par adresse
// Entr�es externes : aucune
// Sorties externes : affichage d'espaces � la place des combinaisons trouv�es
// Auteur : Nicolas Gorrity


#endif // MATRICE_H_INCLUDED
