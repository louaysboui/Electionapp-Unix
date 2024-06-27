#include <gtk/gtk.h>
typedef struct{
int j;
int m;
int a;
}Date;


typedef struct
{
int id_liste;
int id_election;
Date d;
int id_electeur2;
int id_electeur3;
char orientation [20];
}liste;



int ajouter_liste(liste l);
int modifier_liste(int id ,liste nouv);
int supprimer_liste(int id);
liste chercher_liste(int id);
void afficher_liste(GtkWidget *pListView);



