#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

#define true 1
#define false 0





//---------------------------------------------------------------------------------------------------------------------------------------
typedef struct{
  char nom[20] ; // nom symbolique
  char ID[10];
  char emplacementPHY[10]; //   nom du fichier précédé par le caractère ‘@’
  char etat_partage[8];
}catalogue ; // blocs , secteurs
catalogue TAB_catalogue[50] ;  // tableau de type struct catalogie

//----------------------------------------------------------------------------------------------------------------------------------------
void Ajout_fichier(  char nom[20] , char ID[10],char emplacement[10], char etat_partage[8] ,catalogue  TAB_catalogue[50] , int position )
{
  FILE *fichier = fopen(nom,"w"); // mode d'ajout : écriture (prive au debut)

  strcpy (TAB_catalogue[position].nom,nom) ;
  strcpy (TAB_catalogue[position].ID,ID) ;
  strcpy (TAB_catalogue[position].emplacementPHY,emplacement) ;
  strcpy (TAB_catalogue[position].etat_partage,etat_partage);

   fclose(fichier);
}

//--------------------------------------------------------------------------------------------
int Recherche_fichier(char nom[20],catalogue  TAB_catalogue[50]){

bool trouver ; int aider ;

  for( int i =0 ; i < 50 ; i++ )
  {
     if(strcmp(nom,TAB_catalogue[i].nom)==0)
     {
       trouver = true;
       aider = i ;
       return 1 ;
       break;
     }
      else
        { trouver = false ;
        return 0; }
 }

     if (trouver == true)
     printf(" fichier trouve , information sur le fichier [%s] :[ID:%s]",TAB_catalogue[aider].nom ,TAB_catalogue[aider].ID);

    if (trouver != true)
          printf("le fichier [%s] ,'existe pas",TAB_catalogue[aider].nom);


  }

//-----------------------------------------------------------------------------------------------
void changement_du_nom (  char nom[20] , char nouveau_nom[20],catalogue  TAB_catalogue[50] ){


      if (Recherche_fichier(nom,TAB_catalogue) == 1) // verifier si deja le le fichier existe
      {
        for (int i=0 ; i<50;i++)
        {
          if(strcmp(nouveau_nom,TAB_catalogue[i].nom)==0)  // un match entre les deux nom
          {
            strcpy(TAB_catalogue[i].nom,nouveau_nom); // changement de nom d'enregistrement
            printf("changement du nom a etait effectue \n");
          }
        }
      }
      else {
        printf("le fichier n'existe pas ,clicker sur un button pour  un nouveau essay\n");
        getch();
        main() ;

      }
}
//-----------------------------------------------------------------------------
void suppression_fichier(char nom[20] , catalogue  TAB_catalogue[50] )
{  int N=50 ;
  if (Recherche_fichier(nom,TAB_catalogue) == 1)
  {
    for(int i =0 ; i <50 ; i++)
    {
        if(strcmp(nom,TAB_catalogue[i].nom )==0)
        {
          for(int j=1 ; j<N;j++)
         {  TAB_catalogue[j]=TAB_catalogue[j+1] ; // ALogorithme : supression avec decalage des element du tableau
           N-=1;
          }
          realloc(TAB_catalogue,sizeof(catalogue)*N);  // pour diminuer la  la taille de la mémoire  , allocation dynamique

        }
        printf("le fichier a été supprimé avec succès  \n");
          break ;
    }
}
else {
  printf("le fichier que vous voulez supprimer n'existe pas .. clicker sur un button pour revenir au menu ... \n");
  getch();
  main();
  }
}

//-----------------------------------------------------------------------------
void Partage_fichier(char nom[20] , catalogue  TAB_catalogue[50])
{
  if (Recherche_fichier(nom,TAB_catalogue) == 1) // si le fichier existe dans le catalogue
  {
    for(int i =0 ; i <50 ; i++)
    {
      if(strcmp(nom,TAB_catalogue[i].nom)==0) // parcourir le tableau et trouver idencation
       {
           strcpy (TAB_catalogue[i].etat_partage,"Public");
           printf("le partage de fichier a etait effectue \n");
         }
      }
}
else  {
  printf("le fichier que vous voulez partager n'existe pas .. clicker sur un button pour revenir au menu ... \n" );
  getch();
  main() ;
  }
}//-----------------------------------------------------------------------------------

void Retrait_Partage(char nom[20] , catalogue  TAB_catalogue[50])
{
  if (Recherche_fichier(nom,TAB_catalogue) == 1) // si le fichier existe dans le catalogue
  {
    for(int i =0 ; i <50 ; i++)
    {
      if(strcmp(nom,TAB_catalogue[i].nom)==0) // parcourir le tableau et trouver idencation
       {
           strcpy (TAB_catalogue[i].etat_partage,"Privé");
           printf("le Retrait du partage de fichier a etait effectue \n");
         }
      }
}
else  {
  printf("le fichier que vous voulez Retirer le partager n'existe pas .. clicker sur un button pour revenir au menu ... \n" );
  getch();
  main() ;
  }
}
//----------------------------------------------------------------------------------------

void affichage_catalogue(char ID , catalogue  TAB_catalogue[50] )
{
  for( int i= 0;i<50 ; i++)
  {
    if(strcmp(ID,TAB_catalogue[i].ID)==0)
    {
      // affichage
      printf("fichier num %d : [%s]__[ID:%s]",i,TAB_catalogue[i].nom,TAB_catalogue[i].ID);
    }
    else printf("le fichier ID=%s n'existe pas sur le block",ID);
  }
}
// ----------------------------------------------------------------------------------------

void main(){
  int choix ;   // j'ai utilise les meme notations/noms  ,pour la facilite de lecture de code ; les noms de variable , pointeurs , parametres ...
  char nom[20] ;
  char ID[10];
  char emplacementPHY[10];
  char etat_partage[8];
  int position ; // pour la fonction ajout_fichier , en
  catalogue sigment[50] ;
  char nouveau_nom[20] ;
  system("cls");
  printf(" \xB2\xB2  SYSTEME-GESTION-FICHIER \xB2\xB2 \n");
  printf("\n\t\t 1. Ajouter_fichier   \n  ");
  printf("\n\t\t 2. Recherche_fichier\n ");
  printf("\n\t\t 3. changement_du_nom \n");
  printf("\n\t\t 4. suppression_fichier \n");
  printf("\n\t\t 5. Partage_fichier \n");
  printf("\n\t\t 6. Retrait_Partage \n");
  printf("\n\t\t 7. affichage_catalogue \n");
  printf("8_Quitter\n");
do{
  printf("entrer un numero de choix ");
  scanf("%d",&choix);
  }while (choix<1 || choix >8);

  switch (choix)
 {
   case 1:
   printf("Entrez le nom :"); scanf("%s",nom);
   printf("/n Entrez le ID :"); scanf("%s",ID);
   printf("/n Entrez le l'emplacement physique :"); scanf("%s",emplacementPHY);
   printf("/n Entrez l'etat de partage [Prive-Public]"); scanf("%s",etat_partage);
   printf("/n Entrez le ID :"); scanf("%s",ID);

   Ajout_fichier(nom,ID,emplacementPHY,etat_partage,sigment,position);
   position +=1;
          break;

   case 2:
   printf("/n Entrez le nom :"); scanf("%s",nom);
   Recherche_fichier (nom,sigment );
          break ;

  case 3 :
  printf("Entrez le nom de fichier :"); scanf("%s",nom);
  printf("Entrez le nom de nouveau fichier  :"); scanf("%s",nouveau_nom);
  changement_du_nom(nom,nouveau_nom,sigment);
  break ;

  case 4 :
   printf("/n Entrez le nom de fichier :"); scanf("%s",nom);
  suppression_fichier(nom , sigment);
  break;

  case 5 :
  printf("/n Entrez le nom de fichier :"); scanf("%s",nom);
  Partage_fichier(nom,sigment);
  break;


  case 6 :
  printf("/n Entrez le nom de fichier :"); scanf("%s",nom);
  Retrait_Partage(nom,sigment) ;
  break;

  case 7 :
   printf("/n Entrez l’identifiant de propriétaire de fichier :"); scanf("%s",ID);
   affichage_catalogue(ID,sigment);

   case 8 :
   { system("cls");
   printf("\t \xB2\xB2   AU REVOIR   \n ");

   printf("\t \xB2\xB2 Ecole Marocaine des Sciences de l?Ing?nieur   \n ");

   printf("\t \xB2\xB2 SYSTEME d exploitation - SGF  \n");

   printf("\t \xB2\xB2 PAR : AIT HAMOU ABDELILAH   \n");

   printf("\t \xB2\xB2 encadre par : Mr. Abdellatif CHRAIBI \n");

   printf("System Exit");

   exit(0); }

 }

}
