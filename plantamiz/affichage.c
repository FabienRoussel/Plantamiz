#include "affichage.h"

void gotoligcol( int lig, int col )
{
    // ressources
    COORD mycoord;
    mycoord.X = 2*col+1;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void color(int flags)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,(WORD)flags);
}

void mettons_de_la_couleur(char ch,int niveau_joueur)
{
    //0. Déclaration des ressources
    /// Toutes les variables utiles sont déclarées par le biais du tube

    //1. Evitement du niveau 1 dans lequel on ne doit pas mettre de couleur
    if (niveau_joueur>1)
    {
        //2. Attribution de la couleur en fonction de l'item reçu en paramètre
        if(ch=='O') color(FOREGROUND_BLUE | FOREGROUND_RED) ;
        else if(ch=='M') color(FOREGROUND_BLUE) ;
        else if(ch=='P') color(FOREGROUND_GREEN) ;
        else if(ch=='F') color(FOREGROUND_RED) ;
        else if(ch=='S') color(FOREGROUND_GREEN | FOREGROUND_RED) ;
    }
    //3. Affichage de l'item à l'écran
    printf("%c", ch);

    //4. Retour de la couleur au blanc pour les autres affichages (contrat, nombre de coups restants)
    color(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED) ;
}

void mettons_de_la_surbrillance(char cha,int niveau_joueur)
{
    //0. Déclaration des ressources
    /// Toutes les variables utiles sont déclarées par le biais du tube

    //1. Evitement du niveau 1 dans lequel on ne doit pas mettre de couleur
    if (niveau_joueur>1)
    {
        //2. Mise en surbrillance de l'item
        if(cha=='O') color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY) ;
        else if(cha=='M') color(FOREGROUND_BLUE| FOREGROUND_INTENSITY) ;
        else if(cha=='P') color(FOREGROUND_GREEN| FOREGROUND_INTENSITY) ;
        else if(cha=='F') color(FOREGROUND_RED| FOREGROUND_INTENSITY) ;
        else if(cha=='S') color(FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY) ;
    }
    //3. Affichage de l'item à l'écran
    printf("%c", cha);
    color(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED) ;

    //4. Retour de la couleur au blanc pour les autres affichages (contrat, nombre de coups restants)
    color(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED) ;
}
