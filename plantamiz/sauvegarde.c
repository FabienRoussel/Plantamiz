#include "sauvegarde.h"

void save_game(int level,char nameplayer[16])
{
    //0. Déclaration des ressources
    FILE* fichier=NULL;
    long position;
    char comparaison_prenom[16]={'A','A','A','A','A','A','A','A','A','A','A','A','A','A','A','\0'};

    //1. Ouverture du fichier de sauvegarde
    fichier=fopen("sauvegardejoueur.txt", "r");

    //2. Sauvegarde de la partie actuelle
    if(fichier!=NULL)
    {
        //2.1 Comparaison du prénom de l'utilisateur avec les prénoms déjà présents dans le fichier
        fscanf(fichier, "%s", comparaison_prenom);
        while (!((strcmp(comparaison_prenom, nameplayer))==0))
        {
            fseek(fichier,2,SEEK_CUR);
            fscanf(fichier, "%s", comparaison_prenom);
        }
        //2.2. Dès que le nom correspondant est trouvé
        //2.2.1. Mémorisation de la position dans le fichier
        position=ftell(fichier);
        //2.2.2. Fermeture et réouverture du fichier en mode écriture sans écrasement
        fclose(fichier);
        fichier=fopen("sauvegardejoueur.txt", "r+");
        //2.2.3. Repositionnement à l'endroit mémorisé
        fseek(fichier,position,SEEK_SET);
        //2.2.4. Ecriture du niveau
        fprintf(fichier," %d", level);
        printf("Votre progression a ete correctement enregistree.\n\n\n");
        system("PAUSE");
        //3. Fermeture du fichier
        fclose(fichier);
    }
    else printf("Le fichier de sauvegarde n'a pas pu etre ouvert.\nVeuillez agreer nos plus sinceres et plates excuses.");
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

char load_name(int* ptlevel,char test, char name[16])
{
    //0. Déclaration des ressources
    FILE* fic=NULL;
    int i,blind_maj=0;
    char test2=' ',blindname[100],testname[16]={'A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'};

    //1. Obtention du nom de l'utilisateur
    if (test==' ') printf("Saisissez le nom sous lequel vous aviez enregistre votre progression.");
    else printf("Saisissez un nom pour vous identifier.\nLorsque vous aurez enregitre votre progression, vous pourrez la recuperer\ngrace a ce nom.");
    printf("\n\nNotes : Les majuscules et les espaces ne sont pas toleres.\n        Le nom ne doit pas depasser 15 caracteres.\n\n");
    gets(blindname);

    //1.1. Blindage de la saisie
    for (i=0;i<15;i++)
    {
        if (((blindname[i]>='A')&&(blindname[i]<='Z'))||(blindname[i]==' ')) blind_maj=1;
    }
    while ((strlen(blindname)>15)||(blind_maj==1))
    {
        system("CLS");
        printf("La saisie est erronee. Ressaisissez votre nom.\n\nLes majuscules et les espaces ne sont pas toleres.\nLe nom ne doit pas depasser 15 caracteres.\n\n");
        gets(blindname);
        blind_maj=0;
        for (i=0;i<15;i++)
        {
            if (((blindname[i]>='A')&&(blindname[i]<='Z'))||(blindname[i]==' ')) blind_maj=1;
        }
    }
    strcpy(name,blindname);

    //2. Ouverture du fichier en mode lecture+écriture
    fic=fopen("sauvegardejoueur.txt","a+");
    fseek(fic,0,SEEK_SET);

    //3. Test pour s'assurer que le fichier a été trouvé
    if (fic!=NULL)
    {
        //3.1. Parcours du fichier pour trouver le nom saisi
        fscanf(fic,"%s",testname);
        while ((strcmp(name,testname))&&(!feof(fic)))
        {
            fseek(fic,2,SEEK_CUR);
            fscanf(fic,"%s",testname);
        }
        //3.2. Si la fin du fichier est atteinte c'est que le nom n'a pas été trouvé
        if (feof(fic))
        {
            if (test==' ')
            {
                printf("\n\nLe nom que vous avez saisi n'est pas repertorie.\n\n");
                test2='a';
            }
            else
            {
                fprintf(fic,"\n%s 1", name);
                printf("\n\nVotre nom a bien ete enregistre.\n\n");
            }
        }
        //3.3. Si elle n'a pas été atteinte
        else
        {
            if (test!=' ')
            {
                printf("\n\nLe nom que vous avez saisi est deja repertorie.\n\nSi vous souhaitez l'utiliser appuyez sur espace.\nSinon appuyez sur une autre touche.\n\n");
                test2=getch();
            }
            if ((test==' ')&&(test2==' '))
            {
                //3.3.1. Obtention du niveau correspondant
                fscanf(fic,"%d",ptlevel);
                printf("\n\n%s, votre niveau a bien ete recupere.\n\n",name);
            }
        }
        system("PAUSE");
        system("CLS");
    }
    //3.2. Si le fichier n'est pas trouvé on en informe l'utilisateur
    else printf("\n\nLe fichier n'a pas ete trouve.");
    fclose(fic);

    return test2;
}
