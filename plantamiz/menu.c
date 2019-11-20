#include "menu.h"

void affichage_regles()
{
    //0. Déclaration des ressources
    ///Pas de variable à utiliser dans ce sous-programme

    //1. Ecriture des règles
    system("CLS");
    printf("\n\t  Un tableau comportant differents items vous est presente.\n\n\n");
    printf("\tLe but du jeu est de reussir le dernier niveau : le niveau 4.\n");
    printf("     Pour reussir un niveau, il faut remplir le contrat affiche a l'ecran \n\t\t\ten un nombre de coups limite.\n");
    printf("   Il vous faut donc obtenir autant de points items que l'indique le contrat.\n\n\n");
    Sleep(9000);
    printf("\t    Pour gagner ces points, vous devez creer des combinaisons\n    en alignant horizontalement ou verticalement au moins 3 items identiques.\n\n");
    printf("\t  La creation de combinaisons se fait par permutation des items.\n\t\t\tUn coup equivaut a une permutation.\n");
    printf("\t     Vous pouvez permuter deux items meme si cela n'engendre\n\t\t\tpas la formation d'une combinaison.\n\n\n");
    Sleep(15000);
    printf("   Pour effectuer une permutation, servez-vous des touches 2, 4, 6 et 8 pour\n    deplacer le curseur respectivement en bas, a gauche, a droite, en haut.\n");
    printf("\tSelectionnez un item en appuyant sur espace lorsque le curseur\n\t\t\t    est situe sur sa position.\n\n");
    printf("  Reutilisez les chiffres 2, 4, 6 et 8 pour permuter l'item dans la direction\n\t\t\t\t    souhaitee.\n");
    printf("  Vous pouvez desselectionner l'item en appuyant sur espace une seconde fois.\n\n\n");
    Sleep(15000);
    printf("\t       Pour trois items alignes, vous gagnez trois points.\n\t       Pour quatre items alignes, vous gagnez huit points.\n");
    printf("     Pour cinq items alignes, l'ensemble des items similaires sont supprimes\n\t\tet vous gagnez autant de points qu'il y a d'items.\n");
    printf("\t  Pour des items formant des L, des T, ou des croix, vous gagnez\n\t      12, 14 ou 16 points selon les dimensions de la figure.\n\n\n");
    Sleep(15000);
    printf("    Si vous atteignez le nombre maximal de coups et que le contrat n'est pas\n   rempli integralement, vous perdez une vie et devrez recommencer le niveau.\n");
    printf("  Ayant 5 vies au lancement du jeu, si vous les perdez toutes, le jeu s'arrête.\n");
    printf("   Cependant, vous regagnez toutes vos vies lorsque vous reussissez un niveau.\n\n");
    printf("       A la fin de chaque niveau, vous avez la possibilite de sauvegarder\n\t\t\t       votre progression.\n");
    printf("Recuperez-la plus tard a l'aide du nom que vous avez saisi au lancement du jeu.\n\n\n\n\t\t\t\t   BON JEU !!\n\n\n\n\t\t   ");
    system("PAUSE");
}

void affichage_credits()
{
    //0. Déclaration des ressources
    ///Pas de variable à utiliser dans ce sous-programme

    //1. Ecriture des crédits
    system("CLS");
    printf("\n\t\t\t\t   PLANTAMIZ\n\n\t\t\t\t    CREDITS\n\n\n"); Sleep(5000);
    printf("\n\t\t\t\t Chef de projet\n\t\t\t\t Fabien Roussel \n\n\n"); Sleep(2500);
    printf("\t\t\t\t  Programmeurs \n\t\t\t\t Nicolas Gorrity \n\t\t\t\t Fabien Roussel\n\n\n"); Sleep(5000);
    printf("\t\t\t\t  Concepteurs\n\t\t\t\t Nicolas Gorrity \n\t\t\t\t Fabien Roussel\n\n\n\t\t   "); Sleep(5000);
    system("PAUSE");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu0(char tab1[10][15],int niveau,char nom[16])
{
    //0. Déclaration des ressources locales
    int vies=5;
    char choice='a';

    while ((vies)&&(choice!=27)&&(niveau<5))
    {
        //1. Affichage du menu
        printf("%s, il vous reste %d vie(s).\n\n\nQue voulez-vous faire ?\n\nTaper:\n\n",nom,vies);
        if (niveau>1) printf("-0 pour jouer le niveau %d\n",niveau);
        printf("-1 pour commencer une partie\n-2 pour consulter les regles et les commandes\n-3 pour regarder les credits\n-4 pour acheter la version complete\n-Echap pour quitter le jeu\n\n");

        //2. Obtention du choix de l'utilisateur
        choice=getch();

        //3. Analyse du choix
        switch (choice)
        {
            if (niveau>1)
            {
                //3.1. Choix du lancement du niveau suivant
                case '0' : system("CLS");
                niveau=nouveau_jeu(tab1,niveau,&vies,nom);
                break;
            }
            //3.2. Choix du lancement d'une nouvelle partie (même si le joueur est à un niveau supérieur)
            case '1' : niveau=nouveau_jeu(tab1,niveau=1,&vies,nom);
                break;
            //3.3. Choix de l'affichage des règles et commandes
            case '2' : affichage_regles();
                break;
            //3.4. Choix de l'affichage des crédits
            case '3' : affichage_credits();
                break;
            //3.5. Choix de l'achat du jeu....
            case '4' : system("CLS");
                printf("\nOuuups, la version payante n'est pas encore en ligne. \nNous sommes desoles de la gene occasionee.\nCependant il se trouve que vous êtes deja un membre premium:\nUn niveau a donc ete rajoute a votre jeu.\n\n");
                system("PAUSE");
                break;
            //3.6. Cas d'une saisie erronée : lancement d'un bip sonore
            default : printf("\a");
        }
        system("CLS");
    }
    //4. Lorsque le jeu se termine : renvoi du niveau au main
    return niveau;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

int nouveau_jeu(char tab1[10][15],int level,int* pt_vies,char nomjoueur[16])
{
    //0. Déclaration des ressources
    char choix_fin;
    int contrat[5]={0,0,0,0,0};  //contrat : {N_OIGNONS, N_MANDARINES,N_POMMES,N_SOLEILS,N_FRAISES}
    int nombre_coups;

    //1. Initialisation de la partie
    system("CLS");
    newtab(tab1, contrat,level);
    gotoligcol(0,24);
    printf("NIVEAU  %d",level);
    nombre_coups=def_contrat(level,contrat);
    affichage_contrat(contrat);
    gotoligcol(7,23);
    printf("COUPS RESTANTS");
    gotoligcol(9,26);
    printf("%d   ",nombre_coups);

    //2. Lancement de la partie
    //2.1. La partie continue tant que le contrat n'est pas rempli ou tant qu'il reste des coups au joueur
    while (((contrat[0]>0)||(contrat[1]>0)||(contrat[2]>0)||(contrat[3]>0)||(contrat[4]>0)) && (nombre_coups!=0))
    {
        //2.1.1. Déplacement du curseur par le joueur et éventuelle permutation
        action_joueur(contrat,tab1,&nombre_coups,level);
        //2.1.2. Tant que l'on compte des combinaisons dans la matrice on les supprime et
        while (suppression_combinaisons(contrat,tab1,level))
        {
            //2.1.2.1. Mise à jour du contrat
            affichage_contrat(contrat);
            //2.1.2.2. On execute la gravité pour re-remplir la matrice
            gravity(tab1,level);
        }
    }
    //3. Fin de la partie
    gotoligcol(10,0);
    //3.1. Cas de réussite du niveau
    if ((contrat[0]<=0)&&(contrat[1]<=0)&&(contrat[2]<=0)&&(contrat[3]<=0))
    {
        printf("\n\n\n\n\t\tFelicitations. Vous avez reussi le niveau %d.\n\n\t\t  ",level);
        system("PAUSE");
        //3.1.1. Incrémentation de 1 du niveau
        level+=1;
        system("CLS");
        //3.1.2. Le joueur récupère l'intégralité de ses vies
        if ((*pt_vies)<5)
        {
            printf("\n\n\t\tBravo ! Vous avez recupere toutes vos vies !\n\n\t\t  ");
            (*pt_vies)=5;
            system("PAUSE");
        }
    }

    //3.2. Cas d'échec
    else
    {
        printf("\n\n\n\n\t\tDommage ! Vous n'avez pas rempli le contrat !\n\n\t\t  ");
        system("PAUSE");
        system("CLS");
        //3.2.1. Décrémentation de 1 du nombre de vies du joueur
        printf("\n\n\t\tVous avez perdu une vie ! Il vous en reste %d.\n\n\t\t  ",--(*pt_vies));
        system("PAUSE");
    }
    system("CLS");

    //4. Proposition de sauvegarde de la progression
    if (level<5)
    {
        printf("Souhaitez-vous sauvegarder votre progression ?\n\n\nSi oui appuyez sur espace.\n\nSinon appuyez sur une autre touche pour revenir au menu.\n\n");
        choix_fin=getch();
        if (choix_fin==' ') save_game(level,nomjoueur);
    }

    //5. Renvoi de la valeur du niveau au sous-programme menu0 par le mécanisme de retour
    return level;
}
