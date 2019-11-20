#ifndef SAUVEGARDE_H_INCLUDED
#define SAUVEGARDE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void save_game(int level,char nameplayer[16]);
// Nature : Procédure
// Utilité : permet de sauvegarder le niveau du joueur dans le fichier sauvegardejoueur.txt
// Entrées internes : un entier - le niveau, et l'adresse de la chaîne de caractères correspondant au nom du joueur
// Sorties internes : aucune
// Entrées externes : lecture des différents noms figurant dans le fichier
// Sorties externes : écriture dans le fichier du niveau du joueur ainsi que du nom du joueur s'il n'existait pas auparavant ; affichage à l'écran de la confirmation de sauvegarde ou de l'échec d'ouverture du fichier
// Auteur : Fabien Roussel

char load_name(int* ptlevel,char test,char name[16]);
// Nature : Fonction renvoyant un caractère
// Utilité : permet d'identifier le joueur dès le début du jeu pour une éventuelle sauvegarde ultérieure, de charger son ancienne progression si elle existait
// Entrées internes : l'adresse du niveau déclaré dans le main, un caractère définissant si le joueur est nouveau ou veut charger son ancienne progression, et l'adresse de la chaîne de caractères correspondant au nom déclaré dans le main
// Sorties internes : modification par adresse de name jusqu'à ce qu'il soit valide, qui sera finalement le nom du joueur
// Entrées externes : obtention du nom saisi par le joueur ; lecture des noms figurant dans le fichier, lecture du niveau si chargemant d'une progression antérieure
// Sorties externes : instructions de saisie et de blindage du nom ; confirmation de l'identification du joueur ; prévient le joueur de l'erreur d'ouverture de fichier si tel est le cas ; écriture dans le fichier du nom s'il n'existait pas déjà et du numéro 1 (pour le niveau)
// Auteur : Nicolas Gorrity

#endif // SAUVEGARDE_H_INCLUDED
