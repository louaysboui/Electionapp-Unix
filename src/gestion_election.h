
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct{
int jour,mois,annee;
}date;
typedef struct{
int id_election;
int nb_habitant;
char region[20];
char municipalite[20];
date date_election;
}election;


int ajouter_election(election e );
int modifier_election( int id,election nouv);
int supprimer_election(int id );
int chercher_election(int id);
void afficher_election(GtkWidget *liste,election e);
void afficher_rech(GtkWidget *liste,election e);
void cherchers(char region1[20],char region2[20]);
void afficher_rechid(GtkWidget *liste,election e);
void chercherid(int id);
void TPHF(float *th,float *tf);
void TPE(float *te);
election chercher_election1(int id);



