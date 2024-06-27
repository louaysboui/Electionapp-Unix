#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct{
    int jour ;
    int mois ;
    int annee ;
    }DateRec ;
typedef struct{
    DateRec  recDate;
    int ID_observateur   ;
    int ID_bureau_de_vote ;
    int ID_Rec ;
    int degre_durgence ;
    int  listereclamee ;
    char texte_Rec[200]  ;
    }GestRec ;

int ajouter_reclamation(GestRec rec );
void AffichRec(GtkWidget  *liste,GestRec rec);
int supprimer_rec(char * filename, int id_rec);
/*int modifier( char * filename, int id_rec, GestRec nouv ) ;
int supprimer(char * filename, int id_rec);
GestRec chercher(char *filename, int id_rec);
int nbreclamation(int nb[], char * fichierreclamation, char *  listeelectorale)
 void nbreclamation1( char * fichierreclamation, char * listeelectorale,int * nb[])  ;*/  
      
/*int  gagnant( Utilisateur gag[],  int nbhabitant, listelectorale t[]) ;

typedef struct
{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct Utilisateur
{
    char nom[100];
    char prenom[100];
    int cin;
    Date DDN;
    int role;
    int vote;
    int numBV;
    char login[100];
    char pass[100];
}Utilisateur;
Utilisateur chercher_utilisateur(int id, char * filename);

typedef struct
{

    int idliste,idtete;
    int idcand[3];
    char orientation[20];

}listelectorale;

int nbv (char * filename, char* fichier,int * T_nv[]);
int L_ordre( char *fichierListeElectorale,int T[], char * votefile);


//float TPE(char *filename);
int  gagnant( Utilisateur gag[],  int nbhabitant, listelectorale t[]);
void remplir( char * fichier ,listelectorale t[]);
int nb_rec(char*filename,int * listereclamee) ;*/
      


