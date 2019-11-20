#include "menu.h"

int main()
{
    //0. Déclaration des variables
    char c=250;
    char a=178;
    int i;
    char tab1[10][15], name[16];
    srand(time(NULL));
    int leveldumain=1;

    //1. Affichage de "PLANTAMIZ" à l'écran
    for (i=0;i<80;i++)
    {
        printf("%c",c);
    }
    printf("\n");
    printf("       %c%c%c%c%c  %c       %c%c%c   %c     %c  %c%c%c%c%c%c%c   %c%c%c   %c     %c  %c  %c%c%c%c%c%c%c \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    Sleep(250);
    printf("       %c   %c  %c      %c   %c  %c%c    %c     %c     %c   %c  %c%c   %c%c  %c       %c \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    Sleep(250);
    printf("       %c   %c  %c      %c   %c  %c %c   %c     %c     %c   %c  %c %c %c %c  %c      %c \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    Sleep(250);
    printf("       %c%c%c%c%c  %c      %c%c%c%c%c  %c  %c  %c     %c     %c%c%c%c%c  %c  %c  %c  %c     %c \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    Sleep(250);
    printf("       %c      %c      %c   %c  %c   %c %c     %c     %c   %c  %c     %c  %c    %c  \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    Sleep(250);
    printf("       %c      %c      %c   %c  %c    %c%c     %c     %c   %c  %c     %c  %c   %c  \n",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    Sleep(250);
    printf("       %c      %c%c%c%c%c  %c   %c  %c     %c     %c     %c   %c  %c     %c  %c  %c%c%c%c%c%c%c \n\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    for (i=0;i<80;i++)
    {
        printf("%c",c);
    }
    printf("\n");
    Sleep(800);

    //2. Identification du joueur (éventuel chargement d'une progression antérieure)
    printf("Bonjour !!!\n\n\n");
    do
    {
        printf("Souhaitez vous charger une ancienne partie ? \n\nSi oui appuyez sur espace.\nSinon appuyez sur une autre touche. \nVous devrez tout de meme saisir un nom pour vous identifier.\n\n");
    } while ((load_name(&leveldumain,getch(),name))!=' ');

    //3. Le menu
    leveldumain=menu0(tab1,leveldumain,name);

    //4. Fin du programme
    //4.1. Cas où le joueur a gagné le dernier niveau
    if (leveldumain==5)
    {
        printf("\n\n\t\t\t    TOUTES NOS FELICITATIONS\n\n\n\n\t\t\t   VOUS AVEZ GAGNE LE JEU !!!\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t  ");
    }
    //4.2. Autres cas : l'utilisateur a quitté volontairement, ou n'a plus de vie
    else printf("\n\nVoici venue l'heure de faire une pause. A bientot !\n\n\n\t\t  ");
    system("PAUSE");
    return 0;
}
