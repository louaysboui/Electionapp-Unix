#ifndef BUREAU_H_INCLUDED
#define BUREAU_H_INCLUDED

#include <gtk/gtk.h>


typedef struct{
    int id_bureau;
    char municipalite[50];
    char ecole[50];
    int num_salle;
    int id_agent;
    int capacite_des_observateurs;
    int capacite_des_electeurs;
    
    
}bureau; 
float taux1( char * filename , float tn);
float taux2( char * filename , float te);


float TVB (char * filename);
void tauxii( char * filename , float * tn, float * te);








int ajouter(bureau b , char filename []);
int modifier(int id, bureau nouv , char * filename);
int supprimer(int id, char * filename);
bureau chercher(int id, char * filename);


void afficher_recherche(GtkWidget *pListView);

void afficher_bureau(GtkWidget *pListView);





int  chercher_id_bureau(int id, char * filename);
int chercher_id_agent(int id, char * filename);
int chercher_ecole(char ecole[], char * filename);
int chercher_municipalite(char municipalite[], char * filename);
int chercher_bv_ag(int bv,int ag , char * filename);
int chercher_ecole_munic_bv_ag(int bv,int ag ,char ecole[],char municipalite[], char * filename);
int chercher_ecole_munic_bv(int bv,char ecole[],char municipalite[], char * filename);
int chercher_ecole_munic(char ecole[],char municipalite[], char * filename);



int chercher_munic_bv(int bv,char municipalite[], char * filename);
int chercher_munic_ag(int ag,char municipalite[], char * filename);
int chercher_ecole_munic_ag(int ag ,char ecole[],char municipalite[], char * filename);

int chercher_ecole_bv_ag(int bv,int ag ,char ecole[], char * filename);
int chercher_ecole_ag(int ag ,char ecole[], char * filename);
int chercher_ecole_bv(int bv,char ecole[], char * filename);




#endif // BUREAU_H_INCLUDED

