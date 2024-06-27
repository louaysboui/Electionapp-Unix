#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include"reclamation.h"

int ajouter_reclamation(GestRec rec )
{
    FILE *f;
    f=fopen("raclamation.txt","a");
    if(f!=NULL)
    {
       fprintf(f,"%d %d %d %d %d %d %d %d %s \n",rec.recDate.jour,rec.recDate.mois,rec.recDate.annee,rec.ID_observateur,rec.ID_bureau_de_vote,rec.ID_Rec,rec.degre_durgence,rec.listereclamee,rec.texte_Rec);
        fclose(f);
        return 1;
    }
    else return 0;
}

/*int modifier( char * filename, int id_rec, GestRec nouv )
{
    int tr=0;
    GestRec rec;
    FILE * f=fopen(filename , "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %d %d %s \n",&rec.recDate.jour,&rec.recDate.mois,&rec.recDate.annee,&rec.ID_observateur,&rec.ID_bureau_de_vote,&rec.ID_Rec,&rec.degre_durgence,&rec.listereclamee,rec.texte_Rec)!=EOF)
        {
            if(rec.ID_Rec==id_rec)
            {
                fprintf(f2,"%d %d %d %d %d %d %d %d %s \n",rec.recDate.jour,rec.recDate.mois,rec.recDate.annee,rec.ID_observateur,rec.ID_bureau_de_vote,rec.ID_Rec,rec.degre_durgence,rec.listereclamee,rec.texte_Rec);
                tr=1;
            }
            else
                fprintf(f2,"%d %d %d %d %d %d %d %d %s \n",rec.recDate.jour,rec.recDate.mois,rec.recDate.annee,rec.ID_observateur,rec.ID_bureau_de_vote,rec.ID_Rec,rec.degre_durgence,rec.listereclamee,rec.texte_Rec);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}*/
int supprimer_rec(char * filename, int ID_Rec)
{
    int tr=0;
    GestRec rec;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %d %d %d %d %s \n",&rec.recDate.jour,&rec.recDate.mois,&rec.recDate.annee,&rec.ID_observateur,&rec.ID_bureau_de_vote,&rec.ID_Rec,&rec.degre_durgence,&rec.listereclamee,rec.texte_Rec)!=EOF)
        {
            if(rec.ID_Rec==ID_Rec)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %d %d %d %d %s \n",rec.recDate.jour,rec.recDate.mois,rec.recDate.annee,rec.ID_observateur,rec.ID_bureau_de_vote,rec.ID_Rec,rec.degre_durgence,rec.listereclamee,rec.texte_Rec);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

/*GestRec chercher(char * filename, int id_Rec)
{
    GestRec rec;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%d %d %d %d %d %d %d %d %s \n",&rec.recDate.jour,&rec.recDate.mois,&rec.recDate.annee,&rec.ID_observateur,&rec.ID_bureau_de_vote,&rec.ID_Rec,&rec.degre_durgence,&rec.listereclamee,rec.texte_Rec)!=EOF)
        {
            if(rec.ID_Rec==id_Rec)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        rec.ID_Rec=-1;
    return rec;

}*/


enum {
DATE,
IDOBS  ,
IDBV ,
IDREC ,
DEGREC ,
LISTEREC ,
TEXTREC  ,
COLUMNS,
};


void AffichRec(GtkWidget  *liste,GestRec rec)
{

  

GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

   char date[30],idobs[30],idbv[30],degrec[30],listerec[30], idrec[30];
            
 
   store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);


if (store==NULL)
{renderer = gtk_cell_renderer_text_new();
Column = gtk_tree_view_column_new_with_attributes(" date",renderer,"text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), Column);


renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("idobs",renderer,"text",IDOBS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("idbv",renderer,"text",IDBV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("idrec",renderer,"text",IDREC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);


renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("degrec",renderer,"text",DEGREC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("listerec",renderer,"text",LISTEREC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("textrec",renderer,"text",TEXTREC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);



	
}

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);




f = fopen("raclamation.txt","r");
if (f==NULL){return;}


else { f = fopen("raclamation.txt","a+");

while(fscanf(f,"%d %d %d %d %d %d %d %d %s\n",&rec.recDate.jour,&rec.recDate.mois,&rec.recDate.annee,&rec.ID_observateur,&rec.ID_bureau_de_vote,&rec.ID_Rec,&rec.degre_durgence,&rec.listereclamee,rec.texte_Rec)!=EOF)

{
sprintf(date,"%d/%d/%d",rec.recDate.jour,rec.recDate.mois,rec.recDate.annee);
sprintf(idobs,"%d",rec.ID_observateur);
sprintf(idbv,"%d",rec.ID_bureau_de_vote);
sprintf(idrec,"%d",rec.ID_Rec);
sprintf(degrec,"%d",rec.degre_durgence);
sprintf(listerec,"%d",rec.listereclamee);


gtk_list_store_append (store, &iter);  

gtk_list_store_set (store, &iter, TEXTREC,rec.texte_Rec, IDOBS, idobs,IDBV,idbv,IDREC,idrec,DEGREC,degrec,LISTEREC,listerec,DATE,date,-1);
}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
     
       
}

/*int  gagnant( Utilisateur gag[],  int nbhabitant, listelectorale t[])
{
    int nbcons,q,r,c,i;
    if(nbhabitant<=5000)
        nbcons=10;
    else if(nbhabitant>5000 && nbhabitant<=10000)
        nbcons=12;
    else if(nbhabitant>10000 && nbhabitant<=25000)
        nbcons=16;
    else if(nbhabitant>25000 && nbhabitant<=50000)
        nbcons=22;
    else if(nbhabitant>50000 && nbhabitant<=100000)
        nbcons=30;
    else if(nbhabitant>100000 && nbhabitant<=500000)
        nbcons=40;
    else if(nbhabitant>500000)
        =60;
    else
        nbcons=-1;
    q=nbcons/3;
    r=nbcons%3;
    c=0;
    for(i=0;i<q;i++)
    {
        gag[i+c]=chercher_utilisateur(t[i].idcand[0],"utilisateur.txt");
        c++;
        gag[i+c]=chercher_utilisateur(t[i].idcand[1],"utilisateur.txt");
        c++;
        gag[i+c]=chercher_utilisateur(t[i].idcand[2],"utilisateur.txt");
    }
	for(i=0;i<r;i++)
    {
	gag[i+nbcons-1]=chercher_utilisateur(t[q].idcand[i],"utilisateur.txt");
    }
    return(nbcons);
}

float TPE(char *filename)
{
Utilisateur U;
float nbelec=0.0,totelec=0.0,TPE;
    FILE *f=fopen(filename, "r");
if(f!=NULL )
{
while(fscanf(f,"%s %s %d %d %d %d %d %d %d %s %s \n",U.nom,U.prenom,&U.cin,&U.DDN.jour,&U.DDN.mois,&U.DDN.annee,&U.role,&U.vote,&U.numBV,U.login,U.pass)!=EOF)
{
if(U.vote!=-1 && U.role!=0)
nbelec++;
if(U.role!=0)
totelec++;
}
TPE=1.0*(nbelec/totelec);
return(TPE);
}
}



void remplir( char *fichier ,listelectorale t[])
{
    int i;
    listelectorale L ;
    FILE * f=fopen(fichier, "r");
    if(f!=NULL)
    {
	i=0;
        while(fscanf(f,"%d %d %d %d %d %s \n",&L.idliste,&L.idtete,&L.idcand[0],&L.idcand[1],&L.idcand[2],L.orientation)!=EOF)
        {
		t[i]=L;
		i++;
        }
    }
    fclose(f);
}



Utilisateur chercher_utilisateur(int id, char * filename)
{
	Utilisateur U;
	int tr=0;
	FILE * f = fopen(filename, "r");
	if(f != NULL)
	{
		while(fscanf(f,"%s %s %d %d %d %d %d %d %d %s %s \n",U.nom,U.prenom,&U.cin,&U.DDN.jour,&U.DDN.mois,&U.DDN.annee,&U.role,&U.vote,&U.numBV,U.login,U.pass)!=EOF && tr==0)
		{
		   if(id==U.cin)
		   {
		   	tr=1;
		   	break;
		   }
		}
	}
	if (tr==0) U.cin=-1;
	fclose(f);
	return U;
}*/





      



