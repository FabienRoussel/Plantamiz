#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include <stdio.h>
#include <windows.h>

void color(int flags);
// Nature : Proc�dure
// Utilit� : permet d'introduire de la couleur dans l'affichage � l'�cran
// Entr�es internes : couleurs primaires que l'on veut ajouter � la couleur souhait�e (bleu/rouge/vert)
// Sorties internes : d�finition de la couleur du texte affich� plus tard avec un printf
// Entr�es externes : aucune
// Sorties externes : aucune
// Auteur : INCONNU ( http://fvirtman.free.fr/recueil/04_02_01_color.c.php )


void mettons_de_la_couleur(char ch,int niveau_joueur);
// Nature : Proc�dure
// Utilit� : permet d'afficher les items avec leur couleur respective
// Entr�es internes : un caract�re - l'item trait�, un entier - le niveau
// Sorties internes : aucune
// Entr�es externes : aucune
// Sorties externes : affichage de l'item
// Auteur : Fabien Roussel


void mettons_de_la_surbrillance(char cha, int niveau_joueur);
// Nature : Proc�dure
// Utilit� : permet de mettre l'item s�lectionn� par le joueur en surbrillance
// Entr�es internes : un caract�re - l'item s�lectionn� ; un entier - le niveau
// Sorties internes : aucune
// Entr�es externes : aucune
// Sorties externes : affichage de l'item avec sa surbrillance
// Auteur : Fabien Roussel


void gotoligcol( int lig, int col );
// Nature : Proc�dure
// Utilit� : permet de positionner le curseur � l'�cran aux coordonn�es transmises en param�tres
// Entr�es internes : deux entiers : les coordonn�es
// Sorties internes : aucune
// Entr�es externes : aucune
// Sorties externes : affichage du curseur aux coordonn�es indiqu�es
// Auteur : Fr�d�ric Ravaut


#endif // AFFICHAGE_H_INCLUDED
