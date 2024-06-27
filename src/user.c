#include "user.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ajouterutilisateur(char *usefile, UserMAG u )
{

FILE * f=fopen("userfile.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s\t",u.UserNom);
        fprintf(f,"%s\t",u.UserPrenom);
        fprintf(f,"%s\t",u.UserLogin);
        fprintf(f,"%s\t",u.UserPassword);
        fprintf(f,"%d\t",u.UserCIN);
        fprintf(f,"%d\t",u.UserRole);
        fprintf(f,"%d\t",u.UserVote);
        fprintf(f,"%d\t",u.UserGenre);
        fprintf(f,"%d\t",u.UserNumBV); 
        fprintf(f,"%d\t",u.UserDate.JourUser);
        fprintf(f,"%d\t",u.UserDate.MoisUser);
        fprintf(f,"%d\t\n",u.UserDate.AnneeUser);
        
        fclose(f);
        return 1;
    }
    else return 0;}


int ajouterutilisateurr(char *usefile, UserMAG u )
{

FILE * f=fopen("userfile1.txt", "w");
    if(f!=NULL)
    {
        fprintf(f,"%s\t",u.UserNom);
        fprintf(f,"%s\t",u.UserPrenom);
        fprintf(f,"%s\t",u.UserLogin);
        fprintf(f,"%s\t",u.UserPassword);
        fprintf(f,"%d\t",u.UserCIN);
        fprintf(f,"%d\t",u.UserRole);
        fprintf(f,"%d\t",u.UserVote);
        fprintf(f,"%d\t",u.UserGenre);
        fprintf(f,"%d\t",u.UserNumBV); 
        fprintf(f,"%d\t",u.UserDate.JourUser);
        fprintf(f,"%d\t",u.UserDate.MoisUser);
        fprintf(f,"%d\t\n",u.UserDate.AnneeUser);
        
        fclose(f);
        return 1;
    }
    else return 0;}



int modifierutilisateur( char *userfile, int id, UserMAG eu )
{

int tr=0;
    UserMAG u;
    FILE * f=fopen("userfile.txt", "r");
    FILE * f2=fopen("edituser.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
               while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
        {
            if(u.UserCIN== id)
            {
            fprintf(f2,"%s\t",eu.UserNom);
        fprintf(f2,"%s\t",eu.UserPrenom);
        fprintf(f2,"%s\t",eu.UserLogin);
        fprintf(f2,"%s\t",eu.UserPassword);
        fprintf(f2,"%d\t",eu.UserCIN);
        fprintf(f2,"%d\t",eu.UserRole);
        fprintf(f2,"%d\t",eu.UserVote);
        fprintf(f2,"%d\t",eu.UserGenre);
        fprintf(f2,"%d\t",eu.UserNumBV); 
        fprintf(f2,"%d\t",eu.UserDate.JourUser);
        fprintf(f2,"%d\t",eu.UserDate.MoisUser);
        fprintf(f2,"%d\t\n",eu.UserDate.AnneeUser);
                tr=1;
            }
            else
        {
           fprintf(f2,"%s\t",u.UserNom);
        fprintf(f2,"%s\t",u.UserPrenom);
        fprintf(f2,"%s\t",u.UserLogin);
        fprintf(f2,"%s\t",u.UserPassword);
        fprintf(f2,"%d\t",u.UserCIN);
        fprintf(f2,"%d\t",u.UserRole);
        fprintf(f2,"%d\t",u.UserVote);
        fprintf(f2,"%d\t",u.UserGenre);
        fprintf(f2,"%d\t",u.UserNumBV); 
        fprintf(f2,"%d\t",u.UserDate.JourUser);
        fprintf(f2,"%d\t",u.UserDate.MoisUser);
        fprintf(f2,"%d\t\n",u.UserDate.AnneeUser);}

        }
    }
    fclose(f);
    fclose(f2);
    remove("userfile.txt");
    rename("edituser.txt", "userfile.txt");
    return tr;

}

int supprimerutilisateur(char *userfile, int id ){

 int tr=0;
    UserMAG u;
    FILE * f=fopen("userfile.txt", "r");
    FILE * f2=fopen("duser.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
        {
            if(u.UserCIN== id)
              {  tr=1;}
            else{
        fprintf(f2,"%s\t",u.UserNom);
        fprintf(f2,"%s\t",u.UserPrenom);
        fprintf(f2,"%s\t",u.UserLogin);
        fprintf(f2,"%s\t",u.UserPassword);
        fprintf(f2,"%d\t",u.UserCIN);
        fprintf(f2,"%d\t",u.UserRole);
        fprintf(f2,"%d\t",u.UserVote);
        fprintf(f2,"%d\t",u.UserGenre);
        fprintf(f2,"%d\t",u.UserNumBV); 
        fprintf(f2,"%d\t",u.UserDate.JourUser);
        fprintf(f2,"%d\t",u.UserDate.MoisUser);
        fprintf(f2,"%d\t\n",u.UserDate.AnneeUser);
        }}
    }
    fclose(f);
    fclose(f2);
    remove("userfile.txt");
    rename("duser.txt", "userfile.txt");
    return tr; }



 UserMAG chercherutilisateur(char *userfile, int id){


 UserMAG u ;
    int tr=0;
    FILE * f=fopen("userfile.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
        {
            if(u.UserCIN== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.UserCIN=-1;
    return u;
}

int chercheu(char *userfile, int id){


 UserMAG u ;
    int tr=0;
    FILE * f=fopen("userfile.txt", "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
        {
            if(u.UserCIN== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.UserCIN=-1;
    return tr;
}



float agemoyen(char *userfile,int  ann){

float m =0;

float cmpt =0;

    UserMAG u;
    FILE * f=fopen("userfile.txt", "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
        {
           
              
                 cmpt = cmpt+1 ;
                 m = m+(ann-u.UserDate.AnneeUser);  
                          

 
                   
}
 }
    m= m/cmpt;

    fclose(f);
  

    
return m;

}



int nbe( char *userfile, int id ){ 

int  n =0;
int tr =0;

    UserMAG u;
    FILE * f=fopen("userfile.txt", "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
        {
           
              if(u.UserNumBV==id && u.UserRole==2){ 
                
                
                 n = n+1 ;}
                

 
                    
}
 }
   

    fclose(f);

  

    
return n;

}

int verifuser(char login[20],char pass[20]){
 

  int tr=0;
    UserMAG u;
    FILE * f=fopen("userfile.txt", "r");
           
 while(tr==0&&fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",u.UserNom,u.UserPrenom,u.UserLogin,u.UserPassword,&u.UserCIN,&u.UserRole,&u.UserVote,&u.UserGenre,&u.UserNumBV,&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser)!=EOF)
{

if((strcmp(login,u.UserLogin)==0)&&(strcmp(pass,u.UserPassword)==0))

{
 tr =u.UserRole;

}
}


return tr;

}



enum
{

        NOM,
        PRENOM,
        LOGIN,
        MDP,
        CIN,
        ROLE,
        VOTE,
        GENRE,
        NUMBV,
        DATE,
        COLUMNS,
};


void showusers(GtkWidget     *liste){

GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

       char nom[20];
       char prenom[20];
       char login[20];
       char mdp[20];
       char date[20];
       int  cin;
       int  role;
       int  vote;
       int  genre;
       int  numbv ;
       int  jour;
       int  mois;
       int  annee;
 
   store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("login",renderer,"text",LOGIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",MDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("vote",renderer,"text",VOTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("numbv",renderer,"text",NUMBV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);



renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);




f = fopen("userfile.txt","r");
if (f==NULL){return;}


else { f = fopen("userfile.txt","a+");

while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",nom,prenom,login,mdp,&cin,&role,&vote,&genre,&numbv,&jour,&mois,&annee)!=EOF)

{

gtk_list_store_append (store, &iter);  
sprintf(date,"%d/%d/%d",jour,mois,annee);

gtk_list_store_set (store, &iter,NOM, nom, PRENOM, prenom, LOGIN, login, MDP, mdp,CIN,cin,ROLE,role,VOTE,vote,GENRE,genre,NUMBV,numbv,DATE,date,-1);
}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
}
}



void showuserss(GtkWidget     *liste){

GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

       char nom[20];
       char prenom[20];
       char login[20];
       char mdp[20];
       char date[20];
       int  cin;
       int  role;
       int  vote;
       int  genre;
       int  numbv ;
       int  jour;
       int  mois;
       int  annee;
 
   store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("login",renderer,"text",LOGIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",MDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("vote",renderer,"text",VOTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("numbv",renderer,"text",NUMBV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);



renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);




f = fopen("userfile1.txt","r");
if (f==NULL){return;}


else { f = fopen("userfile1.txt","a+");

while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",nom,prenom,login,mdp,&cin,&role,&vote,&genre,&numbv,&jour,&mois,&annee)!=EOF)

{

gtk_list_store_append (store, &iter);  
sprintf(date,"%d/%d/%d",jour,mois,annee);

gtk_list_store_set (store, &iter,NOM, nom, PRENOM, prenom, LOGIN, login, MDP, mdp,CIN,cin,ROLE,role,VOTE,vote,GENRE,genre,NUMBV,numbv,DATE,date,-1);
}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
}
}

int voteunvotezero( char *userfile )
{

int tr=-1;
int br=-1;
    
    UserMAG eu;
    FILE * f=fopen("userfile.txt", "r");
    FILE * f2=fopen("voteun.txt", "w");
    FILE * f3=fopen("votezero.txt", "w");
    FILE * f4=fopen("votex.txt", "w");

    if((f!=NULL) && (f2!=NULL) && (f3!=NULL)&& (f4!=NULL))
    {
               while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",eu.UserNom,eu.UserPrenom,eu.UserLogin,eu.UserPassword,&eu.UserCIN,&eu.UserRole,&eu.UserVote,&eu.UserGenre,&eu.UserNumBV,&eu.UserDate.JourUser,&eu.UserDate.MoisUser,&eu.UserDate.AnneeUser)!=EOF)
        {
           
            
                                                  
                if(eu.UserVote!=-1)
       {
           fprintf(f4,"%s\t",eu.UserNom);
        fprintf(f4,"%s\t",eu.UserPrenom);
        fprintf(f4,"%s\t",eu.UserLogin);
        fprintf(f4,"%s\t",eu.UserPassword);
        fprintf(f4,"%d\t",eu.UserCIN);
        fprintf(f4,"%d\t",eu.UserRole);
        fprintf(f4,"%d\t",eu.UserVote);
        fprintf(f4,"%d\t",eu.UserGenre);
        fprintf(f4,"%d\t",eu.UserNumBV); 
        fprintf(f4,"%d\t",eu.UserDate.JourUser);
        fprintf(f4,"%d\t",eu.UserDate.MoisUser);
        fprintf(f4,"%d\t\n",eu.UserDate.AnneeUser);


     if(eu.UserVote==0)
        {
           fprintf(f3,"%s\t",eu.UserNom);
        fprintf(f3,"%s\t",eu.UserPrenom);
        fprintf(f3,"%s\t",eu.UserLogin);
        fprintf(f3,"%s\t",eu.UserPassword);
        fprintf(f3,"%d\t",eu.UserCIN);
        fprintf(f3,"%d\t",eu.UserRole);
        fprintf(f3,"%d\t",eu.UserVote);
        fprintf(f3,"%d\t",eu.UserGenre);
        fprintf(f3,"%d\t",eu.UserNumBV); 
        fprintf(f3,"%d\t",eu.UserDate.JourUser);
        fprintf(f3,"%d\t",eu.UserDate.MoisUser);
        fprintf(f3,"%d\t\n",eu.UserDate.AnneeUser);


                                                     }

 if(eu.UserVote!=0) 
            {
            fprintf(f2,"%s\t",eu.UserNom);
        fprintf(f2,"%s\t",eu.UserPrenom);
        fprintf(f2,"%s\t",eu.UserLogin);
        fprintf(f2,"%s\t",eu.UserPassword);
        fprintf(f2,"%d\t",eu.UserCIN);
        fprintf(f2,"%d\t",eu.UserRole);
        fprintf(f2,"%d\t",eu.UserVote);
        fprintf(f2,"%d\t",eu.UserGenre);
        fprintf(f2,"%d\t",eu.UserNumBV); 
        fprintf(f2,"%d\t",eu.UserDate.JourUser);
        fprintf(f2,"%d\t",eu.UserDate.MoisUser);
        fprintf(f2,"%d\t\n",eu.UserDate.AnneeUser);
               
            }







        }}
    }
    fclose(f);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    return tr;

}



void voterech(GtkWidget     *liste, char *userfile){

GtkCellRenderer *renderer;
GtkTreeViewColumn *Column;
GtkTreeIter iter;
GtkListStore *store;

       char nom[20];
       char prenom[20];
       char login[20];
       char mdp[20];
       char date[20];
       int  cin;
       int  role;
       int  vote;
       int  genre;
       int  numbv ;
       int  jour;
       int  mois;
       int  annee;
 
   store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column= gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("login",renderer,"text",LOGIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("mdp",renderer,"text",MDP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("vote",renderer,"text",VOTE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("numbv",renderer,"text",NUMBV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);



renderer=gtk_cell_renderer_text_new();
Column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),Column);

store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING);




f = fopen(userfile,"r");
if (f==NULL){return;}


else { f = fopen(userfile,"a+");

while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d %d",nom,prenom,login,mdp,&cin,&role,&vote,&genre,&numbv,&jour,&mois,&annee)!=EOF)

{

gtk_list_store_append (store, &iter);  
sprintf(date,"%d/%d/%d",jour,mois,annee);

gtk_list_store_set (store, &iter,NOM, nom, PRENOM, prenom, LOGIN, login, MDP, mdp,CIN,cin,ROLE,role,VOTE,vote,GENRE,genre,NUMBV,numbv,DATE,date,-1);
}
fclose (f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

g_object_unref (store);
}
}
}




