#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct
{
  int nombremots ;                      // nombre de mots de la liste
  struct liste_ligne * liste_suivant  ; // pointeur da la liste principale qui pointe sur la ligne suivante
  struct liste_mots * Pmot ; // pointeur pour la premiere case de liste chainee secondaire ( liste de mot )( colonne )
} liste_ligne , *listeP ;




typedef struct
{
  char mots[20];
  struct mots_listesecondaire* motsuivent ; // pointeur qui point sur la case suivante de la liste secondaire
} liste_mots , *listemotsP;



bool liste_est_vide(listeP l){  // fonction pour savoir est ce que la liste est vide
  if(l==NULL)
  return true ;
  return false ;
}

listeP nouvelle_liste(void)
{
  return NULL ;
}


int list_lenght(listeP l){
   int taille = 0 ;

   if (liste_est_vide(l) )
   return taille;

   if(!liste_est_vide(l))
     {
        while(l != NULL){
        taille +=1 ;
        l = l -> liste_suivant ;
         }
 }
 return taille ;
}




void Afficher_ligne(listeP l)
{
  if (liste_est_vide(l))
  {
    printf("la liste est vide. \n");
    return;
  }
  while(l != NULL)
  {
    printf("[%d]\n", list_lenght(l));
    l = l-> liste_suivant ;
  }
  printf("\n");
}



listeP Ajout_ligne(liste_ligne *li)
{
  listeP element  =  (listeP)malloc(sizeof(liste_ligne)) ;
   if (element == NULL )
    {
      printf("erreur");
     }

 element-> nombremots = 0 ;
 element -> Pmot = NULL ;
 element-> liste_suivant = NULL ;

 if (liste_est_vide(li))
   return element ;

   listeP l2 ;
    l2=li;
    while (l2->liste_suivant !=NULL )
    {
      l2 = l2->liste_suivant   ;

    } l2->liste_suivant = element;
    	printf("ligne ajoutee avec succes\n");
    return li ;
}

listemotsP Ajouter_mot(listemotsP pmot , listeP pliste , char text[20], int numrligne)
{

 listemotsP Pointeur_mots = (listemotsP)malloc(sizeof(liste_mots)) ;

  strcpy(Pointeur_mots -> mots,text) ;
  Pointeur_mots -> motsuivent = NULL ;
   // not correct

    if (liste_est_vide(pliste))
    {
      printf("la liste des ligne est vide \n");
      // menu() ;
    }

  else {
        listeP P_help = pliste ;  // p_help pointeur pour parcourir la liste ligne
        int cpt = 1 ;
        while (P_help != NULL)
         {

          if (cpt=numrligne)
         {
            if (liste_est_vide(pliste-> Pmot))    // si il'ya aucune liste mot , en attache la nouvelle liste avec pointeur
               {   P_help-> Pmot = Pointeur_mots ;
                   P_help-> nombremots +=1 ;
                   printf("[%s] ajouter avec succes.\n",pliste->Pmot);
                   return  pmot  ;
               }

           else {
                  listemotsP M_help = pmot  ;  // M_help pointeur pour parcourir la liste des mots
                  while (M_help-> motsuivent != NULL)
                   {
                      M_help = M_help->motsuivent ;
                   }

                   M_help-> motsuivent = Pointeur_mots ;   // attacher la nouvelle liste mot a la liste mots existe
                   P_help -> nombremots += 1 ;
                   return pmot ;
               }

       }
            P_help =P_help -> liste_suivant  ;
            cpt ++ ;
     }
       if (cpt != numrligne)
       {
         printf("cette ligne n'existe pas \n");
         return NULL ;
         // menu() ;
       }
   }
}

//_____________________________________________________________________________________


char Affiche_Ligne (listemotsP pmot, listeP pliste ,int numrligne)
{
   if(liste_est_vide(pliste))
       printf("il n'existe aucune ligne.\n");

    else {
      int cpt = 1 ;
      listeP P_help = pliste ;
        while (P_help->liste_suivant != NULL) // parcourir la liste ligne
        {
          if (cpt == numrligne)
            if (P_help->Pmot == NULL)
           {
           printf("erreur , NULL result!(y'a pas de liste mot)"); break;
           }
           else {
           while (P_help->Pmot != NULL) // parcourir la liste mot dans la ligne de numero donne
           {
                	    printf("[%s] ",P_help->Pmot);
                      pmot = pmot->motsuivent ; // en passe a la liste suivante

           }
           printf("\n");
           break;
         }

         P_help = P_help->liste_suivant;  // au cas ou ce cpt =! numeroligne donne , donc en inremenete
         cpt+=1;
        }
  if (cpt != numrligne )
  printf("la ligne de numero : %d n'existe pas \n",numrligne);
  return NULL ;
    }
}



// -------------------------------------------------------------------------
void afficher(liste_ligne *l)
{ int cpt ;

   if (liste_est_vide(l))
    {
      ("erreur , ajouter une liste d'abord \n");
    }
    listeP P_help = l ;
     // parcourir la liste ligne

     while (P_help != NULL) // parcourir la liste ligne   >= 1
     { listemotsP Pointeur = P_help->Pmot ;
      // cpt = 1 ;

       if (P_help-> Pmot = NULL)  // >= un mot
       printf("NULL\n");
          // parcourir la liste mot

          while (P_help-> Pmot != NULL)
         {
            printf("[%s]-> \t",Pointeur->mots);
           Pointeur=Pointeur->motsuivent ;
          //  afficher_text(P_help->Pmot->motsuivent); // fonction recursive
        }
        P_help = P_help-> liste_suivant ;
       }


}

//--------------------------------------------------------
int calucul_mot(listeP pliste){
int cpt = 0 ;
listeP l = pliste ;
  while (l->liste_suivant != NULL)
  {
      cpt = cpt + l->nombremots ;
    }
return cpt ;
}

// methode 1
char mot_palindromes(listeP pliste ) {

listeP  l = pliste ;
char tab[15];
char tab_mot_palindromes [100] ;
   while ( l-> liste_suivant != NULL ) // ou bien for (int j =0 ; j<=taille ; j++)
   { // pour parcourir la liste ligne

      for  (int i = 0 ; i < l-> nombremots ; i++ )
      {
        strcpy(tab,l->Pmot ) ;
       // strrev(tab );
        if (strcmp(tab, l->Pmot ) == 0)               // pour parcourir la liste mots
        {  // Comparing input string with the reverse string
              printf("The string is a palindrome.\n");
              strcpy(tab_mot_palindromes ,tab) ;
            }
            else
             printf("The string isn't a palindrome.\n");
      }
   }

return tab_mot_palindromes ;
}


void Maj_text(listeP pliste){
    listeP l=pliste;
    listemotsP mhelp;

    while(l!=NULL){
        mhelp= l->Pmot;
        if(mhelp->mots>='a' && mhelp->mots<='z'){ // instruction MAJ basé sur code ascii
            mhelp->mots[0]=+32;
        }
        while(mhelp!=NULL){  // affichage des mots
            printf("%s ",mhelp->mots);
            mhelp=mhelp->motsuivent; // en passe a la liste suivante
        }
        l=l->liste_suivant;
    }
}


main () {


  liste_ligne *maliste , *l2;
  maliste = nouvelle_liste() ;
  l2 = NULL ;
     // lignes
  maliste = Ajout_ligne(maliste);

  int a = list_lenght(maliste) ;
  printf("taille de liste =   %d:",a);


listemotsP mot1 =nouvelle_liste() ;
listemotsP mot2 =nouvelle_liste() ;
listemotsP mot3 =nouvelle_liste() ;

maliste = Ajouter_mot(mot1,maliste,"Asmae",1);

int n = calucul_mot(l2);
printf(" nombre mot = %d ------>",n);

afficher(maliste);


}
