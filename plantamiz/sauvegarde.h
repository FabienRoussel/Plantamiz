#ifndef SAUVEGARDE_H_INCLUDED
#define SAUVEGARDE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void save_game(int level,char nameplayer[16]);
// Nature : Proc�dure
// Utilit� : permet de sauvegarder le niveau du joueur dans le fichier sauvegardejoueur.txt
// Entr�es internes : un entier - le niveau, et l'adresse de la cha�ne de caract�res correspondant au nom du joueur
// Sorties internes : aucune
// Entr�es externes : lecture des diff�rents noms figurant dans le fichier
// Sorties externes : �criture dans le fichier du niveau du joueur ainsi que du nom du joueur s'il n'existait pas auparavant ; affichage � l'�cran de la confirmation de sauvegarde ou de l'�chec d'ouverture du fichier
// Auteur : Fabien Roussel

char load_name(int* ptlevel,char test,char name[16]);
// Nature : Fonction renvoyant un caract�re
// Utilit� : permet d'identifier le joueur d�s le d�but du jeu pour une �ventuelle sauvegarde ult�rieure, de charger son ancienne progression si elle existait
// Entr�es internes : l'adresse du niveau d�clar� dans le main, un caract�re d�finissant si le joueur est nouveau ou veut charger son ancienne progression, et l'adresse de la cha�ne de caract�res correspondant au nom d�clar� dans le main
// Sorties internes : modification par adresse de name jusqu'� ce qu'il soit valide, qui sera finalement le nom du joueur
// Entr�es externes : obtention du nom saisi par le joueur ; lecture des noms figurant dans le fichier, lecture du niveau si chargemant d'une progression ant�rieure
// Sorties externes : instructions de saisie et de blindage du nom ; confirmation de l'identification du joueur ; pr�vient le joueur de l'erreur d'ouverture de fichier si tel est le cas ; �criture dans le fichier du nom s'il n'existait pas d�j� et du num�ro 1 (pour le niveau)
// Auteur : Nicolas Gorrity

#endif // SAUVEGARDE_H_INCLUDED
