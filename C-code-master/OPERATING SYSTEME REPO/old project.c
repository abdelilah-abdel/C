#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

 struct login {
    char identificateur[30];
    char motdepasse[30];
};

struct login Tlogin[20];   // tableau d'utilisateurs
int N =1 ;       //  pour numerote les utilisateur , besoin au moins d'un administrateur

int Password();
int menu1 () ;  // pour l'admin
int menu2 ();    // pour utilisateurs
void liste_utilisateur();   // affichage
void changermotdepasse_admin();
void changermotdepasse_utilisateur();
void supprimer_utilisateur();   // par l'admin
int ajouter ();  // SIGN UP

void main ()
{
    Password();
}

int Password() {
    int N =1 ;
     int ON;
     char cle1[20] , cle2[20];
     int found ;
     int tentatives = 0 ;   // nombre de tentatives
     int i = 0, j;

     strcpy (Tlogin[0].identificateur,"ADMIN") ;
      strcpy(Tlogin[0].motdepasse,"ADMIN123") ;


          printf(" \xB2\xB2\xB2\xB2\xB2\xB2  Bienvenue  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n\n\n");

 do{
             printf ("pour vous connecter entrez 0  ||  pour vous inscrire entrez 1 :");
              scanf("%d",&ON);
            }while(ON<0 || ON >1);

        if (ON==0)
        {

                     system ("cls");
                     printf(" \xB2\xB2\xB2\xB2\xB2\xB2    LOGIN    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n\n ");

                  I:
                            printf("\xB2\xB2\xB2\xB2 entrer l'identificateur :");
                            scanf("%s",&cle1);

                            printf("\n \xB2\xB2\xB2\xB2 entrer le mot de passe :");
                            scanf("%s",&cle2);


                    if ( strcmp(cle1,Tlogin[0].identificateur)==0 && strcmp(cle2,Tlogin[0].motdepasse)==0)   // cas d'admin
                    {
                        menu1(); // menu d'administrateur
                        return N ;
                    }

                    else  // cas d'un autre utilisateur
                      {

                          for (i=1;i<N; i++)
                          {
                                if (strcmp(cle1,Tlogin[i].identificateur)== 0 && strcmp(cle2,Tlogin[i].motdepasse)== 0)
                                {
                                    printf("Mot de passe accepté \n");
                                    printf("Acces a la session");
                                    N++ ;                                                    // incrementation le nombre d'utilisateur
                                    system ("cls");                                          // vider l'ecran
                                    menu2();                                                // menu pour les utilisateurs
                                }
                                 else
                                 {

                                    printf("\a Attention ! Informations incorrectes (3 tentatives)");
                                    tentatives ++ ;
                                    getch();
                                    goto I ;
                                    if (tentatives > 3);
                                    {
                                        exit(EXIT_SUCCESS);
                                    }
                                 }
                          }
                             return N;
                       }
            }
        else if ( ON==1)
        {  system("cls");
            ajouter();
            return N ;
        }
          // retourne nombre d'utilisateurs
}


int  menu1 (int N)
{
  int choix ;

              system("cls");
             printf(" \xB2\xB2\xB2\xB2\xB2\xB2  ADMINISTRATEUR  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");

             printf("\n\t\t 1. Ajouter utilisateur   \n  ");
             printf("\n\t\t 2. Supprimer un utilisateur \n ");
             printf("\n\t\t 3. Afficher la listes des utilisateur \n");
             printf("\n\t\t 4. changer de mot de passe d'Admin \n");
             printf("\n\t\t 5. changer de mot de passe d'utilisateur \n");
             printf("\n\t\t 6. LOGOUT \n");


             printf("entrer un numero de choix ");
             scanf("%i", &choix);


               switch (choix) // getch prend la variable de choix (1 bit)
              {
               case 1:
                      ajouter();
                      return N;
                      break;
               case 2:
                      supprimer_utilisateur();
                      break;
               case 3:
                       liste_utilisateur();
                      break;
               case 4:
                      changermotdepasse_admin ();
                      break;
               case 5:
                      changermotdepasse_utilisateur ();
                      break;
               case 6:


              system("cls");
              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2   AU REVOIR  \t\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2 \n ");

              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2 Ecole Marocaine des Sciences de l?Ing?nieur   \t \xB2\xB2\xB2\xB2\xB2\xB2 \n ");

              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2 \t \t SYSTEME d exploitation - LOGIN PROGRAMME  \t     \xB2\xB2\xB2\xB2\xB2\xB2 \n");

              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2 \t \t PAR : AIT HAMOU ABDELILAH  && AIT AHMED NOSSAIR  \t \xB2\xB2\xB2\xB2\xB2\xB2  \n");

              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2 \t \t encadre par : Mr. Abdellatif CHRAIBI   \t \xB2\xB2\xB2\xB2\xB2\xB2 \n");
              printf("System Exit");

              exit(0);


           default:


              printf("\a Saisie incorrecte , Veuillez saisir a nouveau l'option correcte(1-6) ");
              getch();  // if entring in key , will get to mainmenu again
              menu1(N);
   }
   return N;

}

int menu2 (int N) {
  int choix1 ;


             printf(" \xB2\xB2\xB2\xB2\xB2\xB2  Bonjour  %s  ! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n",Tlogin[N].identificateur);

             printf("\n\t\t 1. Afficher la listes des utilisateur \n");
          printf("\n\t\t 2. changer  mon mot de passe" );
          printf("\n\t\t 3. LOGOUT \n");


                printf("entrer un numero de choix ");
                scanf("%i", &choix1);



       switch (choix1) // getch prend la variable de choix (1 bit)
      {


       case 1:
               liste_utilisateur();
              break;

       case 2:
              changermotdepasse_utilisateur ();
              break;

       case 3:


              system("cls");
              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2   AU REVOIR  \xB2\xB2\xB2\xB2\xB2\xB2 \n ");

              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2 Ecole Marocaine des Sciences de l Ingenieur   \xB2\xB2\xB2\xB2\xB2\xB2 \n ");

              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2 \t \t SYSTEME d exploitation - LOGIN PROGRAMME   \t      \xB2\xB2\xB2\xB2\xB2\xB2 \n");

              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2 \t \t PAR : AIT HAMOU ABDELILAH  && AIT AHMED NOSSAIR    \xB2\xB2\xB2\xB2\xB2\xB2  \n");

              printf("\t \xB2\xB2\xB2\xB2\xB2\xB2 \t \t encadre par : Mr. Abdellatif CHRAIBI    \xB2\xB2\xB2\xB2\xB2\xB2 \n");
              printf("System Exit");

              exit(0);


           default:


              printf("\a Saisie incorrecte , Veuillez saisir a nouveau l'option correcte(1-6) ");
              getch();  // if entring in key , will get to mainmenu again
              menu2(N);
   }
   return N;

}

void liste_utilisateur()          // might be wrong
   {
       int i ;
       char click ;



             do {    system("cls");

                     printf(" \xB2\xB2\xB2\xB2\xB2\xB2  LISTES DES UTILISATEUR  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");

                     for (i=0;i<N;i++)
                     {
                         printf("utilisateur [%d] : %s",i,Tlogin[i].identificateur);
                     }

                     printf("\n click  'Enter' pour Actualiser la liste / cliquez sur n'importe quelle touche pour revenir au menu...");


             } while ((click = getch()) =='\r'); // conio.h
                menu2(N);

   }

void changermotdepasse_admin()
   {
                     system("cls");

                     printf(" \xB2\xB2\xB2\xB2\xB2\xB2  CHANGER MOT DE PASSE - ADMIN   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n");

                     printf("\xB2\xB2\xB2\xB2 voulez-vous changer le mot de passe (O/N) :");

                     if (getch() == 'O'|| getch() == 'o')
                     {
                         printf("\n \xB2\xB2\xB2\xB2 entrez un nouveau mot de passe :");
                         scanf("%s",Tlogin[0].motdepasse) ;
                         printf("\n \xB2\xB2\xB2\xB2 le mot de passe est modifie avec succees");

                     }
                       else if (getch() == 'N' || getch() == 'n')
                         {
                         menu1(N);
                         }
}

void changermotdepasse_utilisateur ()
{    int i ;
     int found1;
     char cle3[20];
     int tentatives2 = 3 ;
     system("cls");

                     printf(" \xB2\xB2\xB2\xB2\xB2\xB2  CHANGER - MOT DE PASSE  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n");

            do{        J :
                      printf("\xB2\xB2\xB2\xB2 Entrer l'identificateur :");
                scanf("%s",&cle3);

                        for (i=0;i<N;i++)
                        {       found1 = strcmp(cle3,Tlogin[i].identificateur);
                                   if (found1==0)
                                   {
                                        printf(" identificateur trouver \n");
                                        printf("voulez-vous changer le mot de passe (O/N) :");

                                             if (getch() == 'O'|| getch() == 'o')
                                             {
                                                 printf("entrez un nouveau mot de passe :");
                                                 scanf("%s",Tlogin[i].motdepasse) ;
                                                 printf("le mot de passe a Ã©tÃ© modifiÃ© avec succÃ¨s \n\n");
                                                 printf("vos informations sont  -  id: [%s] -mot de passe : [%s] ",Tlogin[i].identificateur,Tlogin[i].motdepasse);
                                                 Password(N);
                                             }
                                   }
                                     else if (getch() == 'N'|| getch() == 'n' )
                                     {
                                          printf("\xB2\xB2\xB2\xB2 identificateur n existe pas \xB2\xB2\xB2\xB2   \n");
                                          tentatives2 ++ ;
                                          goto J;
                                     }
                         }
            }while (tentatives2 < 3);

               Password(N);
}

int ajouter (int N)
  {
       char cle4[20];
       int i ;

                    system ("cls");
                    printf(" \xB2\xB2\xB2\xB2\xB2\xB2  s'inscrire  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n");


                    printf("\xB2\xB2\xB2\xB2 entrer l'identificateur :");
                    scanf("%s",&cle4);
                    printf("N=%d \n ",N);


         for (i=0;i<N;i++)  // traitement si l'identificateur deja existe
                            {
                                if (strcmp(cle4,Tlogin[i].identificateur)==0)
                                {
                                 printf(" identificateur deja existe ; entrer un nouveau indentificateur \n");
                                   exit(0);
                                 }
                              if (strcmp(cle4,Tlogin[i].identificateur)!=0)
                             {
                                  strcpy(Tlogin[N+1].identificateur,cle4);
                                  printf("\n \xB2 entrer le mot de passe :");
                                  scanf("%s",&Tlogin[N+1].motdepasse) ;
                                  N++ ;
                             }

                    }
                    printf("vous avez  ajoute l utilisateur  avec succees \n");

   getch();
                    Password(N);
                    return N;
  }

 void supprimer_utilisateur( )
 {
     char cle5[20];
    int i,j,k ,I;
   char click1;
   do{
        system("cls");
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2  Supprime un utilisateur  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n");


                    printf("\xB2\xB2\xB2\xB2 entrer l'identificateur :");
                    scanf("%s",&cle5);

          for (i=0;i<N;i++)  // traitement si l'identificateur deja existe
            {

                     if (strcmp(cle5,Tlogin[i].identificateur)==0)
                      {
                                printf(" identificateur  trouve \n");
                                I=i ;

                               printf("\xB2\xB2\xB2\xB2 voulez-vous supprime l'utilisateur (O/N) :");

                                if (getch() == 'O'|| getch() == 'o')
                                {
                                    for (k= i ; i<N ; k++)
                                        {
                                             for (j=k-1 ; j<N-1; j++)                // traitement ; decalage des variables dans un tableau
                                              {
                                                    Tlogin[j]=Tlogin[j+1];
                                                 }
                                         }
                                            N-- ;
                                  }
                       }
                                else {
                                     printf(" identificateur est n'a pas  trouve \n");
                                }
               }

                printf("\n click  'Enter' pour supprimer un autre utilisateur /  cliquez sur n'importe quelle touche pour revenir au menu...");

  } while ((click1 = getch()) =='\r');

 }
