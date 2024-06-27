#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "observateurMG.h"

int ajouterObs(observateurMG obs )
{
    FILE *f; 
    f=fopen("observateurs.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %d %d %d %d %d\n",obs.id,obs.nom,obs.prenom,obs.nationalite,obs.profession,obs.sexe,obs.date.jour,obs.date.mois,obs.date.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifierObs( char *filename, int id, observateurMG nouv )
{
    int tr=0;
    observateurMG obs;
    FILE *f=fopen(filename, "r");
    FILE *f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %d %d %d %d %d\n",&obs.id,obs.nom,obs.prenom,obs.nationalite,&obs.profession,&obs.sexe,&obs.date.jour,&obs.date.mois,&obs.date.annee)!=EOF)
        {
            if(obs.id== id)
            {
                fprintf(f2,"%d %s %s %s %d %d %d %d %d\n",nouv.id,nouv.nom,nouv.prenom,nouv.nationalite,nouv.profession,nouv.sexe,nouv.date.jour,nouv.date.mois,nouv.date.annee);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %s %d %d %d %d %d\n",obs.id,obs.nom,obs.prenom,obs.nationalite,obs.profession,obs.sexe,obs.date.jour,obs.date.mois,obs.date.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimerObs(char *filename, int idObs)
{
    int tr=0;
    observateurMG obs;
    FILE *f=fopen(filename, "r");
    FILE *f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %d %d %d %d %d\n",&obs.id,obs.nom,obs.prenom,obs.nationalite,&obs.profession,&obs.sexe,&obs.date.jour,&obs.date.mois,&obs.date.annee)!=EOF)
        {
            if(obs.id==idObs)
                tr=1;
            else
                fprintf(f2,"%d %s %s %s %d %d %d %d %d\n",obs.id,obs.nom,obs.prenom,obs.nationalite,obs.profession,obs.sexe,obs.date.jour,obs.date.mois,obs.date.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
observateurMG chercherObs(char *filename, int id)
{
    observateurMG obs;
    int tr=0;
    FILE *f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %s %s %d %d %d %d %d\n",&obs.id,obs.nom,obs.prenom,obs.nationalite,&obs.profession,&obs.sexe,&obs.date.jour,&obs.date.mois,&obs.date.annee)!=EOF)
        {
            if(obs.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        obs.id=-1;
    return obs;

}
/*int nbobserver( char * filename )
{
    int x=0;
    observateurMG obs;
    FILE * f=fopen(filename, "r");

    if(f!=NULL )
    {
        while(fscanf(f,"%d %s %s %s %d %d %d %d %d\n",&obs.id,obs.nom,obs.prenom,obs.nationalite,&obs.profession,&obs.sexe,&obs.date.jour,&obs.date.mois,&obs.date.annee)!=EOF)

           x++;


    }
    fclose(f);

    return x;

}
void trier( char * filename )
{
    observateurMG T[10];
    observateurMG obs;
    int i=0,n=0;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");

    if(f!=NULL && f2!=NULL  )
    {observateurMG tampon;
    int min,j;
while(fscanf(f,"%d %s %s %s %d %d %d %d %d\n",&obs.id,obs.nom,obs.prenom,obs.nationalite,&obs.profession,&obs.sexe,&obs.date.jour,&obs.date.mois,&obs.date.annee)!=EOF)
{T[i]=obs;
i++;
n++;}

for (i=0;i<n-1;i++)
{
   min=i ;
   for (j=i+1;j<n;j++)              
   {
       if (T[j].nom[0]<T[min].nom[0])
        min=j;
   }
 tampon=T[i];
 T[i]=T[min];
 T[min]=tampon;
}

     for(i=0;i<n;i++)
    {
        obs=T[i];
     fprintf(f2,"%d %s %s %s %d %d %d %d %d\n",obs.id,obs.nom,obs.prenom,obs.nationalite,obs.profession,obs.sexe,obs.date.jour,obs.date.mois,obs.date.annee);
    }

    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);



}*/

enum
{
	ID,
	NOM,
	PRENOM,
	NATIONALITE,
	PROFESSION,
	SEXE,
	DATE,
	COLUMNS
};

void afficherObs(GtkWidget *liste){

GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

       char nom[20];
       char prenom[20];
       char nationalite[20];
       char date[20];
       int  id;
       int  profession;
       int  sexe;
       int  jour;
       int  mois;
       int  annee;
 
   store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);

if (store==NULL)
{

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

 
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("nationalite",renderer,"text",NATIONALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);


renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("profession",renderer,"text",PROFESSION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);


renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);


renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

store = gtk_list_store_new(COLUMNS,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);




f = fopen("observateurs.txt","r");
if (f==NULL){return;}


else { f = fopen("observateurs.txt","a+");

while(fscanf(f,"%d %s %s %s %d %d %d %d %d ",&id,nom,prenom,nationalite,&profession,&sexe,&jour,&mois,&annee)!=EOF)

{

gtk_list_store_append (store, &iter);  
sprintf(date,"%d/%d/%d",jour,mois,annee);

gtk_list_store_set (store, &iter, ID, id, NOM, nom, PRENOM, prenom, NATIONALITE, nationalite, PROFESSION, profession, SEXE, sexe, DATE, date, -1);
}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
}
} 












