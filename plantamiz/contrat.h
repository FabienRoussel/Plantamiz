#ifndef CONTRAT_H_INCLUDED
#define CONTRAT_H_INCLUDED

#include <stdio.h>
#include "affichage.h"

void affichage_contrat(int contract[5]);
// Nature : Proc�dure
// Utilit� : permet d'afficher l'�tat du contrat � l'�cran en temps r�el
// Entr�es internes : l'adresse du vecteur d'entiers d�finissant le contrat
// Sorties internes : aucune
// Entr�es externes : aucune
// Sorties externes : affichage pour chaque type d'item du nombre de points items qu'il reste � obtenir pour remplir le contrat
// Auteur : Nicolas Gorrity


int def_contrat(int niveau,int contract[5]);
// Nature : Fonction renvoyant un entier
// Utilit� : permet de d�finir le contrat de chaque niveau
// Entr�es internes : un entier - le niveau, ainsi que l'adresse du vecteur d'entiers d�finissant le contrat
// Sorties internes : modification du contrat par adresse et renvoi du nombre de coups pour le niveau sp�cifi�
// Entr�es externes : aucune
// Sorties externes : aucune
// Auteur : Nicolas Gorrity


#endif // CONTRAT_H_INCLUDED
