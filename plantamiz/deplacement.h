#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include "matrice.h"

void action_joueur(int contract[5],char table[10][15],int* pt_n_coups,int niveau);
// Nature : Proc�dure
// Utilit� : permet au joueur de d�placer le curseur et d'alterner deux items.
// Entr�es internes : l'adresse du vecteur d'entiers d�finissant le contrat, l'adresse de la matrice de jeu (tableau bidimensionnel de caract�res), l'adresse de l'entier "nombre de coups restants", ainsi qu'un entier - le niveau
// Sorties internes : d�cr�mentation du nombre de coups restants par adresse
// Entr�es externes : commandes du joueur : espace, 2, 4, 6, 8
// Sorties externes : affichage du d�placement du curseur et du nombre de coups restants en temps r�el
// Auteur : Nicolas Gorrity

int test_altern_fleches(char val,char tab[10][15],int i,int j,int level_joueur);
// Nature : Fonction renvoyant un entier
// Utilit� : permet de permuter deux items si le joueur en a s�lectionn� un puis a appuy� sur 2,4,6 ou 8
// Entr�es internes : un caract�re - la valeur de la touche press�e par le joueur apr�s avoir s�lectionn� l'item, l'adresse de la matrice de jeu (tableau bidimensionnel de caract�res), trois entiers - les coordonn�es de l'item s�lectionn� et le niveau
// Sorties internes : un entier - 1 si le joueur a d�plac� l'item, 0 s'il a d�s�lectionn� l'item ; modification par adresse des valeurs des cases des deux items permut�s
// Entr�es externes : aucune
// Sorties externes : aucune
// Auteur : Nicolas Gorrity


#endif // DEPLACEMENT_H_INCLUDED
