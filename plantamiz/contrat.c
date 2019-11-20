#include "contrat.h"


void affichage_contrat(int contract[5])
{
    //0. Déclaration des ressources
    int i,contrat_affiche[5];

    //1. Conservation du contrat à 0 s'il est passé en dessous
    for (i=0;i<5;i++)
    {
        if (contract[i]<0) contrat_affiche[i]=0;
        else contrat_affiche[i]=contract[i];
    }

    //2. Affichage du nombre d'items restants pour remplir le contrat
    gotoligcol(5,17);
    printf("%d  ",contrat_affiche[0]);
    gotoligcol(5,22);
    printf("%d  ",contrat_affiche[1]);
    gotoligcol(5,27);
    printf("%d  ",contrat_affiche[2]);
    gotoligcol(5,31);
    printf("%d  ",contrat_affiche[3]);
    gotoligcol(5,36);
    printf("%d  ",contrat_affiche[4]);
    gotoligcol(3,15);
    printf(" OIGNONS  MANDARINES  POMMES  SOLEILS  FRAISES");
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

int def_contrat(int level,int contract[5])
{
    //0. Déclaration des variables locales
    int n_coups;

    //1. Définition du contrat selon le niveau
    if (level==1)
    {
        contract[0]=5;
        contract[1]=10;
        contract[2]=0;
        contract[3]=0;
        contract[4]=5;
        n_coups=10;
    }
    if (level==2)
    {
        contract[0]=15;
        contract[1]=4;
        contract[2]=20;
        contract[3]=4;
        contract[4]=15;
        n_coups=22;
    }
    if (level==3)
    {
        contract[0]=20;
        contract[1]=8;
        contract[2]=8;
        contract[3]=20;
        contract[4]=20;
        n_coups=20;
    }
    if (level==4)
    {
        contract[0]=11;
        contract[1]=9;
        contract[2]=15;
        contract[3]=9;
        contract[4]=11;
        n_coups=15;
    }
    //2. Renvoi par le mécanisme de retour de la valeur du nombre de coups autorisés selon le niveau
    return n_coups;
}
