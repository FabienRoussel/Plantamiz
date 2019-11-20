#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include "matrice.h"

void action_joueur(int contract[5],char table[10][15],int* pt_n_coups,int niveau);
// Nature : Procédure
// Utilité : permet au joueur de déplacer le curseur et d'alterner deux items.
// Entrées internes : l'adresse du vecteur d'entiers définissant le contrat, l'adresse de la matrice de jeu (tableau bidimensionnel de caractères), l'adresse de l'entier "nombre de coups restants", ainsi qu'un entier - le niveau
// Sorties internes : décrémentation du nombre de coups restants par adresse
// Entrées externes : commandes du joueur : espace, 2, 4, 6, 8
// Sorties externes : affichage du déplacement du curseur et du nombre de coups restants en temps réel
// Auteur : Nicolas Gorrity

int test_altern_fleches(char val,char tab[10][15],int i,int j,int level_joueur);
// Nature : Fonction renvoyant un entier
// Utilité : permet de permuter deux items si le joueur en a sélectionné un puis a appuyé sur 2,4,6 ou 8
// Entrées internes : un caractère - la valeur de la touche pressée par le joueur après avoir sélectionné l'item, l'adresse de la matrice de jeu (tableau bidimensionnel de caractères), trois entiers - les coordonnées de l'item sélectionné et le niveau
// Sorties internes : un entier - 1 si le joueur a déplacé l'item, 0 s'il a désélectionné l'item ; modification par adresse des valeurs des cases des deux items permutés
// Entrées externes : aucune
// Sorties externes : aucune
// Auteur : Nicolas Gorrity


#endif // DEPLACEMENT_H_INCLUDED
