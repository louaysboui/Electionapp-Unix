#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
typedef struct
{
    int jour;
    int mois;
    int annee;
} dateObs;
typedef struct
{
    int id;
    char nom[20];
    char prenom[20];
    char nationalite[20];
    int profession;
    int sexe;
    dateObs date;
} observateurMG;
int ajouterObs(observateurMG obs );
int modifierObs( char *filename, int id, observateurMG nouv);
int supprimerObs(char *filename, int idObs);
observateurMG chercherObs(char *filename, int id);
//int nbobserver( char * filename );
//void trier( char* filename);
void afficherObs(GtkWidget *liste);

