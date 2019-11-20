#include "Matrice.h"


void gravity(char tab1[10][15],int niveau)
{
    //0. Déclaration des variables
    int i, j, space=1, alea;

    //1. Application de la gravité sur la matrice tant que des espaces sont détectés
    while (space)
    {
        Sleep(250);
        space=0;
        for(i=9;i>0;i--)
        {
            for(j=14; j>=0; j--)
            {
                //1.1 Pour chaque caractère, si c'est un espace, permutation avec le caractère au-dessus de lui
                if(tab1[i][j] == ' ')
                {
                    //1.1.1. Blindage des croix du niveau 4
                    if (!((tab1[i-1][j]=='/')||(tab1[i-1][j]=='\\')||(tab1[i-1][j]=='X')))
                    {
                        tab1[i][j] = tab1[i-1][j];
                        tab1[i-1][j]=' ';
                        gotoligcol(i-1,j);
                        printf(" ");
                        gotoligcol(i,j);
                        mettons_de_la_couleur(tab1[i][j],niveau);
                    }
                    else
                    {
                        //1.1.2. S'il y a une croix on permute avec la case deux fois au-dessus
                        tab1[i][j] = tab1[i-2][j];
                        tab1[i-2][j]=' ';
                        gotoligcol(i-2,j);
                        printf(" ");
                        gotoligcol(i,j);
                        mettons_de_la_couleur(tab1[i][j],niveau);
                    }
                }
            }
        }
        //1.2 Génération de caractères aléatoires sur les vides de la première ligne du tableau
        for(j=0; j<15; j++)
        {
            if (tab1[0][j] == ' ')
            {
                alea = rand()%5;
                if(alea==0) tab1[0][j]='O';
                if(alea==1) tab1[0][j]='M';
                if(alea==2) tab1[0][j]='P';
                if(alea==3) tab1[0][j]='S';
                if(alea==4) tab1[0][j]='F';
                gotoligcol(0,j);
                mettons_de_la_couleur(tab1[0][j],niveau);
            }
        }
        //1.3 Comptage des espaces restants dans la matrice
        for(i=0; i<10; i++)
        {
            for (j=0; j<15; j++)
            {
                if (tab1[i][j] == ' ') space++;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void newtab(char tab1[10][15], int contrat[5],int niveau)
{
    //0. Déclaration des varaiables locales
    int i, j, alea;

    //1. Construction du tableau
    for(i=0; i<10; i++)
    {
        for (j=0; j<15; j++)
        {
            //1.1. Barrière centrale dans les niveaux 3 et 4
            if ((niveau>2)&&(j==7))
            {
                tab1[i][j]=186;
                color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN ) ;
            }
            //1.2. Croix dans le niveau 4
            //1.2.1. Cas des "\"
            else if ((niveau==4)&&((((i==1)||(i==6))&&((j==2)||(j==10)))||(((i==3)||(i==8))&&((j==4)||(j==12)))))
            {
                tab1[i][j]='\\';
                color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN ) ;
            }
            //1.2.2. Cas des "/"
            else if ((niveau==4)&&((((i==1)||(i==6))&&((j==4)||(j==12)))||(((i==3)||(i==8))&&((j==2)||(j==10)))))
            {
                tab1[i][j]='/';
                color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN ) ;
            }
            //1.2.3. Cas des "x"
            else if ((niveau==4)&&(((i==2)||(i==7))&&((j==3)||(j==11))))
            {
                tab1[i][j]='X';
                color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN ) ;
            }
            //1.3. Autres cases
            else
            {
                alea=rand()%5;
                if(alea==0)
                {
                    tab1[i][j]='O';
                    if (niveau>1) color(FOREGROUND_BLUE | FOREGROUND_RED ) ;
                }
                else if(alea==1)
                {
                    tab1[i][j]='M';
                    if (niveau>1) color(FOREGROUND_BLUE ) ;
                }
                else if(alea==2)
                {
                    tab1[i][j]='P';
                    if (niveau>1) color(FOREGROUND_GREEN) ;
                }
                else if(alea==3)
                {
                    tab1[i][j]='S';
                    if (niveau>1) color(FOREGROUND_RED | FOREGROUND_GREEN ) ;
                }
                else if(alea==4)
                {
                    tab1[i][j]='F';
                    if (niveau>1) color(FOREGROUND_RED ) ;
                }
            }
            printf("%2c", tab1[i][j]);
        }
        printf("\n");
    }
    //2. supressions des combinaisons et application de la gravité
    while (suppression_combinaisons(contrat,tab1,niveau)!=0)
    {
        gravity(tab1,niveau);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

int rang_fonction_de_item(char val)
{
    //0. Déclaration des ressources
    int rang_tab_contrat;

    //1. Détermination de la case du tableau contrat en fonction de l'objet qui est en combinaison
    if (val=='O') rang_tab_contrat=0;
    else if (val=='M') rang_tab_contrat=1;
    else if (val=='P') rang_tab_contrat=2;
    else if (val=='S') rang_tab_contrat=3;
    else if (val=='F') rang_tab_contrat=4;

    return rang_tab_contrat;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

int suppression_combinaisons(int contrat[5],char tableau[10][15],int leveljoueur)
{
    //0. Déclaration des variables locales
    int rang_contrat,longueur,i,j,x,y,r,hauteur,m,compteur=0;
    int niveau_vertical[3]={0,1,-1};

    //1. Détection des combinaisons et traitement de celles-ci
    for (i=0;i<10;i++)
    {
        for (j=0;j<15;j++)
        {
            //1.1. Evitement des barrières et des cases déjà traitées lors de la détection d'une combinaison antérieure
            if (((tableau[i][j])!=' ')&&(!((leveljoueur>=3)&&(j==7))))
            {
                //1.2. Détermination de l'élément traité (est-ce une fraise? un soleil? un oignon? etc)
                rang_contrat=rang_fonction_de_item(tableau[i][j]);

                //1.3. Cas où 5 items identiques sont alignés
                if ( ( (j<11) && (tableau[i][j]==tableau[i][j+1]) && (tableau[i][j]==tableau[i][j+2]) && (tableau[i][j]==tableau[i][j+3]) && (tableau[i][j]==tableau[i][j+4]) ) || ( ( i<6) && ( (tableau[i][j]==tableau[i+1][j]) && (tableau[i][j]==tableau[i+2][j]) && (tableau[i][j]==tableau[i+3][j]) && (tableau[i][j]==tableau[i+4][j]) ) ) )
                {           ///Si ligne de 5 mêmes éléments consécutifs                   ..                       ..                            ..                   ou            colonne de 5 éléments consécutifs
                    //1.3.1. Incrémentation de 1 du compteur de combinaisons
                    compteur+=1;
                    //1.3.2. Suppression de tous les éléments du tableau identiques à ceux alignés par 5
                    for (x=0;x<10;x++)
                    {
                        for (y=0;y<15;y++)
                        {
                            if (rang_fonction_de_item(tableau[x][y])==rang_contrat)
                            {
                                tableau[x][y]=' ';
                                gotoligcol(x,y);
                                printf(" ");
                                //1.3.3. Obtention d'autant de points items qu'il y a d'items supprimés
                                contrat[rang_contrat]-=1;
                            }
                        }
                    }
                }
                //1.4. Cas où 3 items identiques sont alignés horizontalement
                else if ( (j<13 ) && (tableau[i][j]==tableau[i][j+1]) && (tableau[i][j]==tableau[i][j+2]) )
                {
                    longueur=3;  /// déclaration de longueur afin de savoir si c'est 3 ou 4 items
                    //1.4.1. Tester si la case suivante (à droite des 3 cases) leur est identique
                    if ((j<12)&&(tableau[i][j]==tableau[i][j+3])) longueur=4;
                    //1.4.2. Tester chaque type de forme complexe (angle supérieur, angle inférieur, et angle au milieu)
                    for (m=0;m<3;m++)
                    {
                        hauteur=niveau_vertical[m]; ///hauteur prend chronologiquement les valeurs 0 , 1 , -1
                        ///C'est la hauteur de la barre horizontale dans une forme complexe (-1 si angle inférieur, 0 si angle au milieu, 1 si angle supérieur)
                        //1.4.2.1. Pour chaque case de la ligne horizontale, test si elle forme un angle avec une ligne verticale d'items identiques
                        for (r=0;r<longueur;r++)        ///En faisant varier hauteur et r : on teste toutes les formes complexes
                        {
                            if ( (i>(-1*hauteur)) && (i<9-hauteur) && ((tableau[i][j])!=' ') && (tableau[i+hauteur][j+r]==tableau[i+hauteur-1][j+r]) && (tableau[i+hauteur][j+r]==tableau[i+hauteur+1][j+r]) ) //1.4.2.1.1. Cas de la branche verticale qui fait 3 cases
                            {
                                //1.4.2.1.1. Cas de la branche verticale qui fait 4 cases (1 de plus en haut)
                                if ((i>(-1*(hauteur-1)))&&(tableau[i][j+r]==tableau[i-2+hauteur][j+r]))
                                {
                                    //1.4.2.1.1.1. Effacement de cette 4ème case
                                    tableau[i-2+hauteur][j+r]=' ';
                                    gotoligcol(i-2+hauteur,j+r);
                                    printf(" ");
                                    //1.4.2.1.1.2. Attribution de 2 points items pour cette case
                                    contrat[rang_contrat]-=2;
                                }
                                //1.4.2.1.2. Cas de la branche verticale qui fait 4 cases (1 de plus en bas)
                                else if ((i<8-hauteur)&&(tableau[i][j+r]==tableau[i+2+hauteur][j+r]))
                                {
                                    //1.4.2.1.2.1. Effacement de cette 4ème case
                                    tableau[i+2+hauteur][j+r]=' ';
                                    gotoligcol(i+2+hauteur,j+r);
                                    printf(" ");
                                    //1.4.2.1.2.2. Attribution de 2 points items pour cette case
                                    contrat[rang_contrat]-=2;
                                }
                                //1.4.2.1.3. Si la branche horizontale fait 4 cases : traitement de la quatrième case (la plus à droite)
                                if (longueur==4)
                                {
                                    //1.4.2.1.3.1 Effacement de cette 4ème case
                                    tableau[i][j+3]=' ';
                                    gotoligcol(i,j+3);
                                    printf(" ");
                                    //1.4.2.1.3.2. Attribution de 2 points items pour cette case
                                    contrat[rang_contrat]-=2;
                                }
                                //1.4.2.1.4. Traitement de la combinaison sans les éventuelles 4èmes cases
                                //1.4.2.1.4.1. Effacement de la combinaison
                                for (x=(-1);x<2;x++)
                                {
                                    tableau[i+x+hauteur][j+r]=tableau[i][j+x+1]=' ';
                                    gotoligcol(i+x+hauteur,j+r);
                                    printf(" ");
                                    gotoligcol(i,j+x+1);
                                    printf(" ");
                                }
                                //1.4.2.1.4.2 Attribution des points contrats
                                contrat[rang_contrat]-=12;
                                //1.4.2.1.5. Incrémentation de 1 du compteur de combinaisons
                                compteur+=1;
                            }
                        }
                    }
                    //1.4.3. Tester si aucune forme complexe trouvée : traitement de la ligne simple
                    if (tableau[i][j]!=' ')
                    {
                        //1.4.3.1. Effacement de la ligne
                        for (x=0;x<longueur;x++)
                        {
                            tableau[i][j+x]=' ';
                            gotoligcol(i,j+x);
                            printf(" ");
                        }
                        //1.4.3.2. Attribution des points contrat
                        contrat[rang_contrat]-=3;
                        if (longueur==4) contrat[rang_contrat]-=5;
                        //1.4.3.3. Incrémentation de 1 du compteur de combinaisons
                        compteur+=1;
                    }
                }
                //1.5. Cas où 3 items identiques sont alignés verticalement
                else if ((i>1)&&(tableau[i][j]==tableau[i-1][j])&&(tableau[i][j]==tableau[i-2][j]))
                {
                    //1.5.1. Tester si la case au-dessus de la ligne verticale est identique aux 3 autres cases
                    longueur=3;
                    if ((i>2)&&(tableau[i][j]==tableau[i-3][j])) longueur=4;
                    //1.5.2. Evitement du rognage d'une forme plus grande qui contiendrait une barre verticale de 4 cases
                    if (tableau[i][j]!=tableau[i+1][j])
                    {
                        //1.5.3. Effacement de la ligne verticale
                        for (x=0;x<longueur;x++)
                        {
                            tableau[i-x][j]=' ';
                            gotoligcol(i-x,j);
                            printf(" ");
                        }
                        //1.5.4. Attribution des points contrat
                        contrat[rang_contrat]-=3;
                        if (longueur==4) contrat[rang_contrat]-=5;
                        //1.5.5. Incrémentation de 1 du compteur de combinaisons
                        compteur+=1;
                    }
                }
            }
        }
    }
    //2. Renvoi du nombre de combinaisons détectées au sous-programme nouveau_jeu par le biais du mécanisme de retour
    return compteur;
}
