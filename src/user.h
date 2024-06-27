#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


typedef struct{
int JourUser;
int MoisUser;
int AnneeUser;}DateUser; 
typedef struct{
char UserNom[20];
char UserPrenom[20];
int UserCIN;
int UserNumBV;
int UserRole;
int UserGenre;
int UserVote;
DateUser UserDate ;
char UserLogin[20]; 
char UserPassword[20];}UserMAG;


int ajouterutilisateur(char *usefile, UserMAG u );
int ajouterutilisateurr(char *usefile, UserMAG u );
int modifierutilisateur( char *userfile, int id, UserMAG eu );
int supprimerutilisateur(char *userfile, int id );
UserMAG chercherutilisateur(char *userfile, int id);
float agemoyen(char *userfile,int  ann);
int nbe( char *userfile, int id );
int verifuser(char login[20],char pass[20]);
void showusers(GtkWidget    *liste);
void showuserss(GtkWidget    *liste);
int chercheu(char *userfile, int id);



 
