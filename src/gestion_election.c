#include "gestion_election.h"
#include "user.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>



int ajouter_election(election e)
{
    FILE *f;
f=fopen("gestion_election.txt","a");
    if(f!=NULL)
    {
	fprintf(f,"%d %d %s %s %d %d %d\n",e.id_election,e.nb_habitant,e.region,e.municipalite,e.date_election.jour,e.date_election.mois,e.date_election.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier_election(int id,election nouv )
{
    int tr=0;
    election anc;
    FILE *f=fopen("gestion_election.txt","r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %d %d %d\n",&anc.id_election,&anc.nb_habitant,anc.region,anc.municipalite,&anc.date_election.jour,&anc.date_election.mois,&anc.date_election.annee)!=EOF)
        {
            if(anc.id_election==id)
            {
                fprintf(f2,"%d %d %s %s %d %d %d\n",nouv.id_election,nouv.nb_habitant,nouv.region,nouv.municipalite,nouv.date_election.jour,nouv.date_election.mois,nouv.date_election.annee);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %s %s %d %d %d\n",anc.id_election,anc.nb_habitant,anc.region,anc.municipalite,anc.date_election.jour,anc.date_election.mois,anc.date_election.annee);

        }
    }
    fclose(f);
    fclose(f2);
    remove("gestion_election.txt");
    rename("nouv.txt","gestion_election.txt");
    return tr;

}
int supprimer_election(int id)
{
    int tr=0;
    election e;
    FILE *f=fopen("gestion_election.txt","r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %d %d %d\n",&e.id_election,&e.nb_habitant,e.region,e.municipalite,&e.date_election.jour,&e.date_election.mois,&e.date_election.annee)!=EOF)
        {
            if(e.id_election==id)
                tr=1;
            else
                fprintf(f2,"%d %d %s %s %d %d %d\n",e.id_election,e.nb_habitant,e.region,e.municipalite,e.date_election.jour,e.date_election.mois,e.date_election.annee);
        }
    }
    fclose(f);
    fclose(f2);
    remove("gestion_election.txt");
    rename("nouv.txt","gestion_election.txt");
    return tr;
}



election chercher_election1(int id)
{
    election e;
    int tr=0;
    FILE *f=fopen("gestion_election.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %s %s %d %d %d\n",&e.id_election,&e.nb_habitant,e.region,e.municipalite,&e.date_election.jour,&e.date_election.mois,&e.date_election.annee)!=EOF)
        {
            if(e.id_election==id)
                tr=1;
            else 
             e.id_election=-1;
        }
    }
    
    fclose(f);

   
    return e;

}
int chercher_election(int id)
{
    election e;
    int tr=0;
    FILE *f=fopen("gestion_election.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %s %s %d %d %d\n",&e.id_election,&e.nb_habitant,e.region,e.municipalite,&e.date_election.jour,&e.date_election.mois,&e.date_election.annee)!=EOF)
        {
            if(e.id_election==id)
                tr=1;
        }
    }
    fclose(f);
   
    return tr;

}

enum {
IDELECTION,
NBHABITANT,
REGION,
MUNICIPALITE,
DATE,
COLUMNS,
};


void afficher_election(GtkWidget  *liste,election e)
{

  

GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

   char date[30],id[30],nbr[30];
            
 
   store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("id_election",renderer,"text",IDELECTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("nb_habitant",renderer,"text",NBHABITANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("region",renderer,"text",REGION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",MUNICIPALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

	
}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);




f = fopen("gestion_election.txt","r");
if (f==NULL){return;}


else { f = fopen("gestion_election.txt","a+");

while(fscanf(f,"%d %d %s %s %d %d %d\n",&e.id_election,&e.nb_habitant,e.region,e.municipalite,&e.date_election.jour,&e.date_election.mois,&e.date_election.annee)!=EOF)

{
sprintf(date,"%d/%d/%d",e.date_election.jour,e.date_election.mois,e.date_election.annee);
sprintf(id,"%d",e.id_election);
sprintf(nbr,"%d",e.nb_habitant);
gtk_list_store_append (store, &iter);  

gtk_list_store_set (store, &iter, IDELECTION,id, NBHABITANT, nbr, REGION, e.region, MUNICIPALITE, e.municipalite,DATE,date,-1);
}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
     
       
}


void cherchers(char region1[20],char region2[20])
{
    int tr=0;
    election e;
    FILE *f=fopen("gestion_election.txt","r");
    FILE *f2=fopen("gestion_electionrs.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %d %d %d\n",&e.id_election,&e.nb_habitant,e.region,e.municipalite,&e.date_election.jour,&e.date_election.mois,&e.date_election.annee)!=EOF)
        {
            if((strcmp(e.region,region1)==0) || (strcmp(e.region,region2)==0))
                fprintf(f2,"%d %d %s %s %d %d %d\n",e.id_election,e.nb_habitant,e.region,e.municipalite,e.date_election.jour,e.date_election.mois,e.date_election.annee);
           
        }
    }
    fclose(f);
    fclose(f2);

 

}
void afficher_rech(GtkWidget *liste,election e)

{        
GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

   char date[30],id[30],nbr[30];
            
 
   store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("id_election",renderer,"text",IDELECTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("nb_habitant",renderer,"text",NBHABITANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("region",renderer,"text",REGION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",MUNICIPALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

	
}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);




f = fopen("gestion_electionrs.txt","r");
if (f==NULL){return;}


else { f = fopen("gestion_electionrs.txt","a+");

while(fscanf(f,"%d %d %s %s %d %d %d\n",&e.id_election,&e.nb_habitant,e.region,e.municipalite,&e.date_election.jour,&e.date_election.mois,&e.date_election.annee)!=EOF)

{
sprintf(date,"%d/%d/%d",e.date_election.jour,e.date_election.mois,e.date_election.annee);
sprintf(id,"%d",e.id_election);
sprintf(nbr,"%d",e.nb_habitant);
gtk_list_store_append (store, &iter);  

gtk_list_store_set (store, &iter, IDELECTION,id, NBHABITANT, nbr, REGION, e.region, MUNICIPALITE, e.municipalite,DATE,date,-1);
}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
     
}
void chercherid(int id)
{
    int tr=0;
    election e;
    FILE *f=fopen("gestion_election.txt","r");
    FILE *f2=fopen("gestion_electionrid.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %d %d %d\n",&e.id_election,&e.nb_habitant,e.region,e.municipalite,&e.date_election.jour,&e.date_election.mois,&e.date_election.annee)!=EOF)
        {
            if(e.id_election==id)
                fprintf(f2,"%d %d %s %s %d %d %d\n",e.id_election,e.nb_habitant,e.region,e.municipalite,e.date_election.jour,e.date_election.mois,e.date_election.annee);
           
        }
    }
    fclose(f);
    fclose(f2);

 

}
void afficher_rechid(GtkWidget *liste,election e)

{        
GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

   char date[30],id[30],nbr[30];
            
 
   store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("id_election",renderer,"text",IDELECTION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("nb_habitant",renderer,"text",NBHABITANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("region",renderer,"text",REGION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("municipalite",renderer,"text",MUNICIPALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);

	
}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);




f = fopen("gestion_electionrid.txt","r");
if (f==NULL){return;}


else { f = fopen("gestion_electionrid.txt","a+");

while(fscanf(f,"%d %d %s %s %d %d %d\n",&e.id_election,&e.nb_habitant,e.region,e.municipalite,&e.date_election.jour,&e.date_election.mois,&e.date_election.annee)!=EOF)

{
sprintf(date,"%d/%d/%d",e.date_election.jour,e.date_election.mois,e.date_election.annee);
sprintf(id,"%d",e.id_election);
sprintf(nbr,"%d",e.nb_habitant);
gtk_list_store_append (store, &iter);  

gtk_list_store_set (store, &iter, IDELECTION,id, NBHABITANT, nbr, REGION, e.region, MUNICIPALITE, e.municipalite,DATE,date,-1);
}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
     
}
void TPHF(float *th,float *tf)
{float nv=0;
int nh=0,nf=0;
 
    UserMAG u;
    FILE * f=fopen("userfile.txt", "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
        {   if((u.UserRole==2) && (u.UserVote!=-1))
              { 
		nv+=1;
                if(u.UserGenre==1)
                  {nh=nh+1;}
               else 
                 {nf=nf+1;}
                }
         }
    }
    fclose(f);
*th=(nh/nv)*100;
*tf=(nf/nv)*100;
}
void TPE(float *te)
{float nv=0;
int ne=0;
    UserMAG u;
    FILE * f=fopen("userfile.txt", "r");
    if(f!=NULL)
    {
         while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
        {   nv+=1;
            if((u.UserRole==2) && (u.UserVote!=-1))
              {ne=ne+1;}
            }
        }
    fclose(f);
*te=(ne/nv)*100;
}

