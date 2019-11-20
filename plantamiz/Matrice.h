#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "affichage.h"


void gravity(char tab1[10][15],int niveau);
// Nature : Procédure
// Utilité : permet de faire "tomber" le caractère qui se trouve au dessus de chaque espace
// Entrées internes : adresse de la matrice de jeu (tableau bidimensionnel de caractères) ; et un entier : le niveau
// Sorties internes : modification de la matrice de jeu par adresse
// Entrées externes : aucune
// Sorties externes : affichage de la "chute" des items
// Auteur : Fabien Roussel


void newtab(char tab1[10][15], int contrat[5],int niveau);
// Nature : Procédure
// Utilité : permet de générer la matrice initiale au début du niveau et de traiter les combinaisons éventuellement présentes (grâce à l'appel de suppression_combinaisons et de gravity)
// Entrées internes : l'adresse de la matrice de jeu (tableau bidimensionnel de caractères), l'adresse du vecteur d'entiers définissant le contrat ; et le niveau du joueur (entier)
// Sorties internes : modification de la matrice de jeu par adresse
// Entrées externes : aucune
// Sorties externes : affichage de chaque case de la matrice
// Auteur : Fabien Roussel

int rang_fonction_de_item(char val);
// Nature : Fonction renvoyant un entier
// Utilité : permet d'accéder à la bonne case du vecteur d'entiers correspondant au contrat en fonction de l'item actuellement traité dans le tableau
// Entrées internes : un caractère - celui contenu dans la case du tableau
// Sorties internes : un entier - le rang du tableau contrat correspondant à l'item
// Entrées externes : aucune
// Sorties externes : aucune
// Auteur : Nicolas Gorrity

int suppression_combinaisons(int contrat[5],char tableau[10][15],int leveljoueur);
// Nature : Fonction renvoyant un entier
// Utilité : permet d'effacer les combinaisons du tableau, de modifier en conséquence l'état du contrat, et de compter le nombre de combinaisons trouvées
// Entrées internes : l'adresse du vecteur d'entiers définissant le contrat, l'adresse de la matrice de jeu (tableau bidimensionnel de caractères), et un entier - le niveau
// Sorties internes : un entier - le nombre de combinaisons trouvées ; modification des valeurs de la matrice de jeu et de celles du contrat par adresse
// Entrées externes : aucune
// Sorties externes : affichage d'espaces à la place des combinaisons trouvées
// Auteur : Nicolas Gorrity


#endif // MATRICE_H_INCLUDED
