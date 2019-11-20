#ifndef CONTRAT_H_INCLUDED
#define CONTRAT_H_INCLUDED

#include <stdio.h>
#include "affichage.h"

void affichage_contrat(int contract[5]);
// Nature : Procédure
// Utilité : permet d'afficher l'état du contrat à l'écran en temps réel
// Entrées internes : l'adresse du vecteur d'entiers définissant le contrat
// Sorties internes : aucune
// Entrées externes : aucune
// Sorties externes : affichage pour chaque type d'item du nombre de points items qu'il reste à obtenir pour remplir le contrat
// Auteur : Nicolas Gorrity


int def_contrat(int niveau,int contract[5]);
// Nature : Fonction renvoyant un entier
// Utilité : permet de définir le contrat de chaque niveau
// Entrées internes : un entier - le niveau, ainsi que l'adresse du vecteur d'entiers définissant le contrat
// Sorties internes : modification du contrat par adresse et renvoi du nombre de coups pour le niveau spécifié
// Entrées externes : aucune
// Sorties externes : aucune
// Auteur : Nicolas Gorrity


#endif // CONTRAT_H_INCLUDED
