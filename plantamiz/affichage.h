#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include <stdio.h>
#include <windows.h>

void color(int flags);
// Nature : Procédure
// Utilité : permet d'introduire de la couleur dans l'affichage à l'écran
// Entrées internes : couleurs primaires que l'on veut ajouter à la couleur souhaitée (bleu/rouge/vert)
// Sorties internes : définition de la couleur du texte affiché plus tard avec un printf
// Entrées externes : aucune
// Sorties externes : aucune
// Auteur : INCONNU ( http://fvirtman.free.fr/recueil/04_02_01_color.c.php )


void mettons_de_la_couleur(char ch,int niveau_joueur);
// Nature : Procédure
// Utilité : permet d'afficher les items avec leur couleur respective
// Entrées internes : un caractère - l'item traité, un entier - le niveau
// Sorties internes : aucune
// Entrées externes : aucune
// Sorties externes : affichage de l'item
// Auteur : Fabien Roussel


void mettons_de_la_surbrillance(char cha, int niveau_joueur);
// Nature : Procédure
// Utilité : permet de mettre l'item sélectionné par le joueur en surbrillance
// Entrées internes : un caractère - l'item sélectionné ; un entier - le niveau
// Sorties internes : aucune
// Entrées externes : aucune
// Sorties externes : affichage de l'item avec sa surbrillance
// Auteur : Fabien Roussel


void gotoligcol( int lig, int col );
// Nature : Procédure
// Utilité : permet de positionner le curseur à l'écran aux coordonnées transmises en paramètres
// Entrées internes : deux entiers : les coordonnées
// Sorties internes : aucune
// Entrées externes : aucune
// Sorties externes : affichage du curseur aux coordonnées indiquées
// Auteur : Frédéric Ravaut


#endif // AFFICHAGE_H_INCLUDED
