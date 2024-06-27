#include "liste.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <gtk/gtk.h>
int ajouter_liste(liste l)
{
    FILE * 
    f=fopen("liste.txt", "a");
    if(f!=NULL)
    {
      fprintf(f,"%d %d %d %d %d %d %d %s\n",l.id_liste,l.id_election,l.d.j,l.d.m,l.d.a,l.id_electeur2,l.id_electeur3,l.orientation);
      fclose(f);
      return 1;
    }
    else return 0;
}


liste chercher_liste(int id)
{
    liste l;
    int tr=0;
    FILE *f=fopen("liste.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%d %d %d %d %d %d %d %s\n",&l.id_liste,&l.id_election,&l.d.j,&l.d.m,&l.d.a,&l.id_electeur2,&l.id_electeur3,l.orientation)!=EOF)
            { if(l.id_liste==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        l.id_liste=-1;
    return l;
}



int modifier_liste(int id,liste nouv)
{
int tr=0;
liste anc;
    FILE * f=fopen("liste.txt", "r");
    FILE * f2 =fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
while(fscanf(f,"%d %d %d %d %d %d %d %s\n",&anc.id_liste,&anc.id_election,&anc.d.j,&anc.d.m,&anc.d.a,&anc.id_electeur2,&anc.id_electeur3,anc.orientation)!=EOF)
{
if(anc.id_liste==id)
  {
      fprintf(f2,"%d %d %d %d %d %d %d %s\n",nouv.id_liste,nouv.id_election,nouv.d.j,nouv.d.m,nouv.d.a,nouv.id_electeur2,nouv.id_electeur3,nouv.orientation);
      tr=1;

   }
else
    fprintf(f2,"%d %d %d %d %d %d %d %s\n",anc.id_liste,anc.id_election,anc.d.j,anc.d.m,anc.d.a,anc.id_electeur2,anc.id_electeur3,anc.orientation);
    

   }
}
        fclose(f);
        fclose(f2);
remove("liste.txt");
rename("nouv.txt","liste.txt");
        return tr;
}

int supprimer_liste(int id)
{
    int tr=0;
    liste l;
    FILE *f=fopen("liste.txt","r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %d %s\n",&l.id_liste,&l.id_election,&l.d.j,&l.d.m,&l.d.a,&l.id_electeur2,&l.id_electeur3,l.orientation)!=EOF)
        {
            if(l.id_liste==id)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %d %d %d %s\n",l.id_liste,l.id_election,l.d.j,l.d.m,l.d.a,l.id_electeur2,l.id_electeur3,l.orientation);
        }
    }
    fclose(f);
    fclose(f2);
    remove("liste.txt");
    rename("nouv.txt","liste.txt");
    return tr;
}



enum {
ID_LISTE,
ID_ELECTION,
ID_ELECTEUR2,
ID_ELECTEUR3,
DATE,
ORIENTATION,
N_COLUMN,
//TOGGLE_COLUMN
};


void afficher_liste(GtkWidget *pListView)
{

 


GtkListStore *pListStore;

GtkTreeViewColumn *pColumn;

GtkCellRenderer *pCellRenderer;

GtkTreeIter pIter;


liste l;
int id_liste;
int id_election;
Date date;
int id_electeur2;
int id_electeur3;
char orientation [20];

char var1[50],var2[50],var3[50],var4[50],var5[50];

pListStore=NULL;


FILE *f;

pListStore=gtk_tree_view_get_model(pListView);


/*

void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),&iter,ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),&iter,4,&boolean,-1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,4, !boolean,-1);
 
 
}
*/
if (pListStore== NULL) {

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_liste",pCellRenderer,"text", ID_LISTE,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_election",pCellRenderer,"text",ID_ELECTION,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("date",pCellRenderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_electeur2",pCellRenderer,"text", ID_ELECTEUR2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("id_electeur3",pCellRenderer,"text",ID_ELECTEUR3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("orientation",pCellRenderer,"text",ORIENTATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


/*
pCellRenderer = gtk_cell_renderer_toggle_new();

pColumn=gtk_tree_view_column_new_with_attributes("select",pCellRenderer,"active",TOGGLE_COLUMN,NULL);
g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	*/



pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("liste.txt","r");
if (f==NULL){return;}
else{f=fopen("liste.txt","a+");
while(fscanf(f,"%d %d %d %d %d %d %d %s\n",&l.id_liste,&l.id_election,&l.d.j,&l.d.m,&l.d.a,&l.id_electeur2,&l.id_electeur3,l.orientation)!=EOF)
	{
sprintf(var1,"%d",l.id_liste);
sprintf(var2,"%d",l.id_election);
sprintf(var3,"%d",l.id_electeur2);
sprintf(var4,"%d",l.id_electeur3);
sprintf(var5,"%d/%d/%d",l.d.j,l.d.m,l.d.a);

///

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,ID_LISTE,var1,ID_ELECTION,var2,ID_ELECTEUR2,var3,ID_ELECTEUR3,var4,DATE,var5,ORIENTATION,l.orientation,-1);


}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);
       }
}

}









