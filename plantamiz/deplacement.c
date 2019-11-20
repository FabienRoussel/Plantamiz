#include "deplacement.h"

int test_altern_fleches(char val,char tab[10][15],int i,int j,int level_joueur)
{
    //0. Déclaration des ressources locales
    char save_val;
    int coup=0;

    //1. Alternance de deux items si le joueur a appuyé sur une flèche
    //1.1. Test si le joueur a appuyé sur 2
    if ((val=='2')&&(!((tab[i+1][j]=='/')||(tab[i+1][j]=='\\')||(tab[i+1][j]=='X'))))
    {
        if (i==9) printf("\a");
        else
        {
            save_val=tab[i][j];
            tab[i][j]=tab[i+1][j]; //Le gotoligcol est déjà sur i,j
            mettons_de_la_couleur(tab[i][j],level_joueur);
            tab[i+1][j]=save_val;
            gotoligcol(i+1,j);
            mettons_de_la_couleur(tab[i+1][j],level_joueur);
            coup=1;
        }
    }
    //1.2. Test si le joueur a appuyé sur 4
    else if ((val=='4')&&(!((level_joueur>=3)&&(j==8)))&&(!((tab[i][j-1]=='/')||(tab[i][j-1]=='\\')||(tab[i][j-1]=='X'))))
    {
        if (j==0) printf("\a");
        else
        {
            save_val=tab[i][j];
            tab[i][j]=tab[i][j-1]; //Le gotoligcol est déjà sur i,j
            mettons_de_la_couleur(tab[i][j],level_joueur);
            tab[i][j-1]=save_val;
            gotoligcol(i,j-1);
            mettons_de_la_couleur(tab[i][j-1],level_joueur);
            coup=1;
        }
    }
    //1.3. Test si le joueur a appuyé sur 6
    else if ((val=='6')&&(!((level_joueur>=3)&&(j==6)))&&(!((tab[i][j+1]=='/')||(tab[i][j+1]=='\\')||(tab[i][j+1]=='X'))))
    {
        if (j==14) printf("\a");
        else
        {
            save_val=tab[i][j];
            tab[i][j]=tab[i][j+1]; //Le gotoligcol est déjà sur i,j
            mettons_de_la_couleur(tab[i][j],level_joueur);
            tab[i][j+1]=save_val;
            gotoligcol(i,j+1);
            mettons_de_la_couleur(tab[i][j+1],level_joueur);
            coup=1;
        }
    }
    //1.4. Test si le joueur a appuyé sur 8
    else if ((val=='8')&&(!((tab[i-1][j]=='/')||(tab[i-1][j]=='\\')||(tab[i-1][j]=='X'))))
    {
        if (i==0) printf("\a");
        else
        {
            save_val=tab[i][j];
            tab[i][j]=tab[i-1][j]; //Le gotoligcol est déjà sur i,j
            mettons_de_la_couleur(tab[i][j],level_joueur);
            tab[i-1][j]=save_val;
            gotoligcol(i-1,j);
            mettons_de_la_couleur(tab[i-1][j],level_joueur);
            coup=1;
        }
    }
    return coup;
}


void action_joueur(int contract[5],char table[10][15],int* pt_n_coups,int niveau)
{
    //0. Déclaration des variables
    static int coordX=0,coordY=0;
    char key='a',key2='a';

    //1. Déplacement du curseur par le joueur

    //1.1. Affichage du curseur là où le joueur l'a utilisé au dernier coup
    gotoligcol(coordY,coordX);

    //1.2. Attente de la pression sur une touche de l'utilisateur puis obtention de la valeur saisie
    key=getch();

    //1.3. Blindage de la saisie
    while (!((key==' ')||(key=='2')||(key=='4')||(key=='6')||(key=='8')))
    {
        if (niveau>1) printf("\a");
        key=getch();
    }
    //1.4. Traitement de la commande du joueur une fois qu'elle est valide
    //1.4.1. Déplacement du curseur si le joueur a appuyé sur 2, 4, 6 ou 8
    if (key=='2')
    {
        if (coordY==9) {if (niveau>1) printf("\a");}
        else
        {
            gotoligcol(++coordY,coordX);
            //On évite les croix au niveau 4
            if ((niveau==4)&&((table[coordY][coordX]=='/')||(table[coordY][coordX]=='\\')||(table[coordY][coordX]=='X'))) gotoligcol(++coordY,coordX);
        }
    }
    else if (key=='4')
    {
        if (coordX==0) {if (niveau>1) printf("\a");}
        else
        {
            gotoligcol(coordY,--coordX);
            //On évite les croix au niveau 4 et la barrière aux niveaux 3 et 4
            if ((niveau>=3)&&((coordX==7)||((table[coordY][coordX]=='/')||(table[coordY][coordX]=='\\')||(table[coordY][coordX]=='X')))) gotoligcol(coordY,--coordX);
        }
    }
    else if (key=='6')
    {
        if (coordX==14) {if (niveau>1) printf("\a");}
        else
        {
            gotoligcol(coordY,++coordX);
            //On évite les croix au niveau 4 et la barrière aux niveaux 3 et 4
            if ((niveau>=3)&&((coordX==7)||((table[coordY][coordX]=='/')||(table[coordY][coordX]=='\\')||(table[coordY][coordX]=='X')))) gotoligcol(coordY,++coordX);
        }
    }
    else if (key=='8')
    {
        if (coordY==0) {if (niveau>1) printf("\a");}
        else
        {
            gotoligcol(--coordY,coordX);
            //On évite les croix au niveau 4
            if ((niveau==4)&&((table[coordY][coordX]=='/')||(table[coordY][coordX]=='\\')||(table[coordY][coordX]=='X'))) gotoligcol(--coordY,coordX);
        }
    }
    //1.4.2. Sélection de l'item si le joueur a appuyé sur espace
    else if (key==' ')
    {
        //1.4.2.1. Surbrillance de l'item sélectionné
        mettons_de_la_surbrillance(table[coordY][coordX],niveau);
        gotoligcol(coordY,coordX);
        //1.4.2.2. Attente jusqu'à une nouvelle commande du joueur
        key2=getch();
        //1.4.2.3. Blindage de la deuxième saisie
        while (!((key2==' ')||(key2=='2')||(key2=='4')||(key2=='6')||(key2=='8')))
        {
            if (niveau>1) printf("\a");
            key2=getch();
        }
        //1.4.2.4. Désactivation de la surbrillance de l'item
        mettons_de_la_couleur(table[coordY][coordX],niveau);
        gotoligcol(coordY,coordX);
        //1.4.2.5. Test de la pression sur 2, 4, 6, ou 8 ; permutation et décrémentation de 1 du nombre de coups si nécéssaire
        (*pt_n_coups)-=test_altern_fleches(key2,table,coordY,coordX,niveau);
        //1.4.2.6. Affichage du nouveau nombre de coups
        gotoligcol(9,26);
        printf("%d   ",(*pt_n_coups));
    }
}
