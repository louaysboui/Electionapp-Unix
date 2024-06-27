#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gestion_election.h"
#include "reclamation.h"
#include "liste.h"
#include "user.h"
#include "observateurMG.h"
#include "bureau.h"

election e;

int obsg=1;
int t[1]={0};
int nug=1;

election e;
GestRec r;
liste l;
int orient=1;
UserMAG u;
int mdsup=0;
int idelaz;
observateurMG obs;

char adminlogin[20];
int dsa=0;
int daj=0;
int voteu=0;
int votez=0;
int idineed=0;
int yes;









void
on_button2_MG_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Addnewobs ,*Gobs;

Gobs=lookup_widget(objet,"mahmoud_INTERFACE1");
Addnewobs=lookup_widget(objet,"mahmoud_INTERFACE2");

gtk_widget_destroy(Gobs);

Addnewobs=create_mahmoud_INTERFACE2();
gtk_widget_show(Addnewobs);
}


void
on_button1_MG_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	observateurMG obs;
   

char ch1[20];
char ch2[20];
char ch3[20];
char ch4[200];
int a;

a=supprimerObs( "observateurs.txt",obs.id);

GtkWidget *mod, *mahmoud_INTERFACE1;
mahmoud_INTERFACE1=lookup_widget(GTK_WIDGET(objet),"mahmoud_INTERFACE1");



gtk_widget_destroy(mahmoud_INTERFACE1);
mod=lookup_widget(GTK_WIDGET(objet),"mahmoud_INTERFACE2");
mod=create_mahmoud_INTERFACE2();
gtk_widget_show(mod);
GtkWidget *id=lookup_widget(mod,"entryObsId");
sprintf(ch1,"%d",obs.id);
gtk_entry_set_text(GTK_ENTRY(id),ch1);
GtkWidget *nom=lookup_widget(mod,"entryObsNom");
sprintf(ch2,"%s",obs.nom);
gtk_entry_set_text(GTK_ENTRY(nom),ch2);
GtkWidget *prenom=lookup_widget(mod,"entryObsPrenom");
sprintf(ch3,"%s",obs.prenom);
gtk_entry_set_text(GTK_ENTRY(prenom),ch3);
GtkWidget *nationalite=lookup_widget(mod,"entryObsNationalite");
sprintf(ch4,"%s",obs.nationalite);
gtk_entry_set_text(GTK_ENTRY(nationalite),ch4);


GtkWidget *profession=lookup_widget(mod,"comboboxprofobs_MG");
gtk_combo_box_set_active(profession,1);




GtkWidget *jour=lookup_widget(mod,"jour_MG");
gtk_spin_button_set_value(jour,obs.date.jour);
GtkWidget *mois=lookup_widget(mod,"mois_MG");
gtk_spin_button_set_value(mois,obs.date.mois);
GtkWidget *annee=lookup_widget(mod,"annee_MG");
gtk_spin_button_set_value(annee,obs.date.annee);

}


void
on_button3_MG_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
int x=supprimerObs("observateurs.txt",obs.id);
}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton1_MG_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button4_MG_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{


}


void
on_radiobutton2_MG_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button7_MG_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *retour1, *Ajout;
	Ajout=lookup_widget(objet,"mahmoud_INTERFACE2");
	retour1=lookup_widget(objet,"mahmoud_INTERFACE1");
gtk_widget_destroy(Ajout);
retour1=create_mahmoud_INTERFACE1();
gtk_widget_show(retour1);

}

void
on_button8_MBG_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affiche ,*ge;

ge=lookup_widget(GTK_WIDGET(button),"maissa_1");

affiche=lookup_widget(GTK_WIDGET(button),"WindowAzizUserLogin");

gtk_widget_destroy(ge);

affiche=create_WindowAzizUserLogin();

gtk_widget_show(affiche);

}


void
on_button2_MBG_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affiche ,*ge;

ge=lookup_widget(GTK_WIDGET(button),"maissa_1");

affiche=lookup_widget(GTK_WIDGET(button),"maissa_3");

gtk_widget_destroy(ge);

affiche=create_maissa_3();

gtk_widget_show(affiche);
}


void
on_button1_MBG_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affiche ,*ge;

ge=lookup_widget(GTK_WIDGET(button),"maissa_1");

affiche=lookup_widget(GTK_WIDGET(button),"maissa_4");

gtk_widget_destroy(ge);

affiche=create_maissa_4();

gtk_widget_show(affiche);


}


void
on_radiobutton1_MBG_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ((gtk_toggle_button_get_active(togglebutton)))
	orient=1;
 
}


void
on_radiobutton2_MBG_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if ((gtk_toggle_button_get_active(togglebutton)))
	orient=2;
}


void
on_radiobutton3_MBG_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ((gtk_toggle_button_get_active(togglebutton)))
	orient=3;
 
}


void
on_button7_MBG_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_MBG_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
int a;
a=supprimer_liste(l.id_liste);
}


void
on_button4_MBG_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *retour1, *Ajout;
	Ajout=lookup_widget(objet,"maissa_3");
	retour1=lookup_widget(objet,"maissa_2");
gtk_widget_destroy(Ajout);
retour1=create_maissa_2();
gtk_widget_show(retour1);
}


void
on_button5_MBG_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button18_MBG_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton5_MBG_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button17_MBG_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_return_ajout_bv_JE_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *tree_bv;


fenetre_ajout=lookup_widget(GTK_WIDGET(button),"Jamel1");
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(GTK_WIDGET(button),"jamel_2");
fenetre_afficher=create_jamel_2();
gtk_widget_show(fenetre_afficher) ;
tree_bv=lookup_widget(fenetre_afficher,"treebv");
afficher_bureau(tree_bv);
}


void
on_button_ajout_bv_JE_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
int a;
GtkWidget *id_bv,*id_ag,*munic,*ecole,*num_salle,*cap_obs,*cap_elect,*sortie;
GtkWidget *tree_bv;
bureau b,o;



id_bv=lookup_widget(GTK_WIDGET(button),"entry_Id_bv_JE");
id_ag=lookup_widget(GTK_WIDGET(button),"entry_id_ag_JE");
munic=lookup_widget(GTK_WIDGET(button),"combo_munic_JE");
ecole=lookup_widget(GTK_WIDGET(button),"combo_ecol_JE");
num_salle=lookup_widget(GTK_WIDGET(button),"spin_num_sal_JE");
cap_obs=lookup_widget(GTK_WIDGET(button),"spin_cap_obs_JE");
cap_elect=lookup_widget(GTK_WIDGET(button),"spin_cap_elec_JE");
sortie=lookup_widget(GTK_WIDGET(button),"label_verif_JE");




b.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));
b.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));

strcpy(b.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munic)));
strcpy(b.ecole,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ecole)));

b.num_salle= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_salle));
b.capacite_des_observateurs= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cap_obs));
b.capacite_des_electeurs= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cap_elect));

o=b;
o=chercher(b.id_bureau,"bureau.txt");

if(o.id_bureau != -1){
	gtk_label_set_text(GTK_LABEL(sortie),"Bureau existe deja ! {Echec Ajout}");}
else{
a=ajouter(b,"bureau.txt");
	/*if (a==1)
		gtk_label_set_text(GTK_LABEL(sortie),"Ajout avec succes!");
		}*/


GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;


fenetre_ajout=lookup_widget(GTK_WIDGET(button),"Jamel1");

gtk_widget_destroy(fenetre_ajout);

fenetre_affiche=lookup_widget(GTK_WIDGET(button),"jamel_2");

fenetre_affiche=create_jamel_2();

gtk_widget_show(fenetre_affiche) ;

tree_bv=lookup_widget(fenetre_affiche,"treebv");
afficher_bureau(tree_bv);
}

}


void
on_button_return_affic_bv_JE_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion,*affiche;
gestion=lookup_widget(GTK_WIDGET(button),"windowAdminConnected");
affiche=lookup_widget(GTK_WIDGET(button),"jamel_2");

gtk_widget_destroy(affiche);

gestion=create_windowAdminConnected();
gtk_widget_show(gestion);

}

void
on_radio_yes_supp_bv_JE_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	yes=1;
}


void
on_radio_non_supp_bv_JE_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	yes = 0;
}

int T[4]={0,0,0,0};
void
on_check_id_agent_JE_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	T[1]=1;
}


void
on_check_id_bureau_JE_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	T[0]=1;

}


void
on_check_municipalite_JE_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	T[3]=1;
}


void
on_check_ecole_JE_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	T[2]=1;
}



void
on_button_recher_affic_bv_JE_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
int a;
GtkWidget *id_bv,*id_ag,*munic,*ecole;
GtkWidget *tree_bv;
bureau b1;

id_bv=lookup_widget(GTK_WIDGET(button),"entry_recher_id_bureau");
id_ag=lookup_widget(GTK_WIDGET(button),"entry_recher_id_agent");
munic=lookup_widget(GTK_WIDGET(button),"entry_recher_munic");
ecole=lookup_widget(GTK_WIDGET(button),"entry_recher_ecole");





if (T[0]==1 &&  (T[1]==0)&& (T[3]==0) &&(T[2]==0)){
b1.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));
a=chercher_id_bureau(b1.id_bureau, "bureau.txt");
T[0]=0;
}

 if (T[1]==1 &&  (T[0]==0)&& (T[3]==0) &&(T[2]==0)){
b1.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));
a=chercher_id_agent(b1.id_agent,"bureau.txt");
T[1]=0;
}

if (T[2]==1 &&  (T[1]==0)&& (T[3]==0) &&(T[0]==0) ){
strcpy(b1.ecole,gtk_entry_get_text(GTK_ENTRY(ecole)));
a=chercher_ecole(b1.ecole,"bureau.txt");
T[2]=0;

}
if (T[3]==1 &&  (T[0]==0)&& (T[1]==0) &&(T[2]==0)){
strcpy(b1.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));
a=chercher_municipalite(b1.municipalite, "bureau.txt");
T[3]=0;
}

if ((T[0]==1) &&  (T[1]==1) && (T[3]==0) &&(T[2]==0)){
b1.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));
b1.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));
a=chercher_bv_ag(b1.id_bureau,b1.id_agent,"bureau.txt");
T[0]=0;T[1]=0;


}

if ((T[0]==1) &&  (T[1]==1)&& (T[3]==1) &&(T[2]==1)){
b1.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));
b1.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));
strcpy(b1.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));
strcpy(b1.ecole,gtk_entry_get_text(GTK_ENTRY(ecole)));

a=chercher_ecole_munic_bv_ag(b1.id_bureau,b1.id_agent,b1.ecole,b1.municipalite, "bureau.txt");
T[0]=0;T[1]=0;T[2]=0;T[3]=0;
}

if ((T[0]==1)&& (T[3]==1) &&(T[2]==1)  &&(T[1]==0)){
b1.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));
strcpy(b1.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));
strcpy(b1.ecole,gtk_entry_get_text(GTK_ENTRY(ecole)));
a=chercher_ecole_munic_bv(b1.id_bureau,b1.ecole,b1.municipalite,"bureau.txt");
T[0]=0;T[2]=0;T[3]=0;
}
if ((T[3]==1) &&(T[2]==1) && (T[1]==0) &&(T[0]==0)){
strcpy(b1.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));
strcpy(b1.ecole,gtk_entry_get_text(GTK_ENTRY(ecole)));
a=chercher_ecole_munic(b1.ecole,b1.municipalite,"bureau.txt");
T[2]=0;T[3]=0;

}

if((T[0]==1) &&  (T[1]==0)&& (T[3]==1) &&(T[2]==0)){
b1.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));

strcpy(b1.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));

a=chercher_munic_bv(b1.id_bureau,b1.municipalite,"bureau.txt");
T[0]=0;T[3]=1;
}

if((T[0]==0) &&  (T[1]==1)&& (T[3]==1) &&(T[2]==0)){

b1.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));
strcpy(b1.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));

a=chercher_munic_ag(b1.id_agent,b1.municipalite,"bureau.txt");
T[1]=0;T[3]==0;
}

if((T[0]==0) &&  (T[1]==1)&& (T[3]==1) &&(T[2]==1)){

b1.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));
strcpy(b1.municipalite,gtk_entry_get_text(GTK_ENTRY(munic)));
strcpy(b1.ecole,gtk_entry_get_text(GTK_ENTRY(ecole)));
a=chercher_ecole_munic_ag(b1.id_agent ,b1.ecole,b1.municipalite,"bureau.txt");
T[1]=0;T[2]=0;T[3]=0;T[0]=0;
}

if((T[0]==1) &&  (T[1]==1)&& (T[3]==0) &&(T[2]==1)){
b1.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));
b1.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));
strcpy(b1.ecole,gtk_entry_get_text(GTK_ENTRY(ecole)));
a=chercher_ecole_bv_ag(b1.id_bureau,b1.id_agent ,b1.ecole,"bureau.txt");
T[1]=0;T[2]=0;T[0]=0;
}

if((T[0]==0) &&  (T[1]==1)&& (T[3]==0) &&(T[2]==1)){

b1.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));

strcpy(b1.ecole,gtk_entry_get_text(GTK_ENTRY(ecole)));
a=chercher_ecole_ag(b1.id_agent ,b1.ecole, "bureau.txt");
T[1]=0;T[2]=0;
}

if((T[0]==1) &&  (T[1]==0)&& (T[3]==0) &&(T[2]==1)){
b1.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));

strcpy(b1.ecole,gtk_entry_get_text(GTK_ENTRY(ecole)));
a=chercher_ecole_bv(b1.id_bureau,b1.ecole, "bureau.txt");
T[0]=0;T[2]=0;

}

GtkWidget *fenetre;
GtkWidget *fenetre_afficher;


fenetre_afficher=lookup_widget(GTK_WIDGET(button),"jamel_2");

gtk_widget_destroy(fenetre_afficher);

fenetre=lookup_widget(GTK_WIDGET(button),"jamel_2");
fenetre=create_jamel_2();

gtk_widget_show(fenetre) ;

tree_bv=lookup_widget(fenetre,"treebv");
afficher_recherche(tree_bv);
}


void
on_button_modif_affic_bv_JE_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;


fenetre_afficher=lookup_widget(GTK_WIDGET(button),"jamel_2");

gtk_widget_destroy(fenetre_afficher);

fenetre_modif=lookup_widget(GTK_WIDGET(button),"jamel3_JE");
fenetre_modif=create_jamel3_JE();

gtk_widget_show(fenetre_modif) ;
}


void
on_button_ajout_affic_bv_JE_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;


fenetre_afficher=lookup_widget(GTK_WIDGET(button),"jamel_2");

gtk_widget_destroy(fenetre_afficher);

fenetre_ajout=lookup_widget(GTK_WIDGET(button),"Jamel1");
fenetre_ajout=create_Jamel1();

gtk_widget_show(fenetre_ajout) ;
}


void
on_button_supp_affic_bv_JE_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supp;
GtkWidget *fenetre_afficher;


fenetre_afficher=lookup_widget(GTK_WIDGET(button),"jamel_2");

gtk_widget_destroy(fenetre_afficher);

fenetre_supp=lookup_widget(GTK_WIDGET(button),"Supp_JE");
fenetre_supp=create_Supp_JE();

gtk_widget_show(fenetre_supp) ;

}


void
on_buttonUserLOGIN_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
char chlogin[50],chpassword[50];

GtkWidget *authentification ,*espace_administrateur,*lerror,*login,*password,*labelUserName;
login=lookup_widget(objet,"entryUserLogin");
password=lookup_widget(objet,"entryUserMotDePasse");
lerror=lookup_widget(objet,"labelerrorlogin");
strcpy(chlogin,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(chpassword,gtk_entry_get_text(GTK_ENTRY(password)));
authentification=lookup_widget(objet,"WindowAzizUserLogin");
espace_administrateur=lookup_widget(objet,"windowAdminConnected");





if(verifuser(chlogin,chpassword)==0){
gtk_widget_show(authentification);
char ch1[20],ch2[20];

const char *format;

char msg[50], *markup;

GtkWidget       *output;


output = lookup_widget(objet, "labelerrorlogin");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"Login ou mot de passe invalide");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
}
else if(verifuser(chlogin,chpassword)==1)
{

gtk_widget_destroy(authentification);

espace_administrateur=create_windowAdminConnected();
gtk_widget_show(espace_administrateur);

labelUserName = lookup_widget(objet, "labelUserName");
gtk_label_set_text(GTK_LABEL(labelUserName), chlogin);

}
else if(verifuser(chlogin,chpassword)==2)
{

gtk_widget_destroy(authentification);





espace_administrateur=create_maissa_1();
gtk_widget_show(espace_administrateur);
}
else if(verifuser(chlogin,chpassword)==3)
{
gtk_widget_destroy(authentification);

espace_administrateur=create_mahmoud_INTERFACE1();
gtk_widget_show(espace_administrateur);
}
else if(verifuser(chlogin,chpassword)==4)
{
gtk_widget_destroy(authentification);

espace_administrateur=create_Louay1();
gtk_widget_show(espace_administrateur);
}
}


void
on_buttonGestionnaireUtilisateurs_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_administrateur ,*Gu;



Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
espace_administrateur=lookup_widget(objet,"windowAdminConnected");

gtk_widget_destroy(espace_administrateur);

Gu=create_windowGestionnaireUtilisateurs();
gtk_widget_show(Gu);

//tr=lookup_widget(Gu,"treeviewUsers");

//showusers(tr);
}


void
on_buttonGestionBV_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *gestion,*affiche;
gestion=lookup_widget(GTK_WIDGET(button),"windowAdminConnected");
affiche=lookup_widget(GTK_WIDGET(button),"jamel_2");

gtk_widget_destroy(gestion);

affiche=create_jamel_2();
gtk_widget_show(affiche);




}


void
on_buttonGestionElections_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *yahAzizListeElections ,*espace_administrateur;

yahAzizListeElections=lookup_widget(objet,"yahAzizListeElections");
espace_administrateur=lookup_widget(objet,"windowAdminConnected");

gtk_widget_destroy(espace_administrateur);

yahAzizListeElections=create_yahAzizListeElections();
gtk_widget_show(yahAzizListeElections);

}


void
on_buttonUserDisconnect_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_administrateur ,*loginwindow;

loginwindow=lookup_widget(objet,"WindowAzizUserLogin");
espace_administrateur=lookup_widget(objet,"windowAdminConnected");

gtk_widget_destroy(espace_administrateur);

loginwindow=create_WindowAzizUserLogin();
gtk_widget_show(loginwindow);

}

void
on_buttonBacktoAdminconnected_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_administrateur ,*Gu;

Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
espace_administrateur=lookup_widget(objet,"windowAdminConnected");

gtk_widget_destroy(Gu);

espace_administrateur=create_windowAdminConnected();
gtk_widget_show(espace_administrateur);
}


void
on_buttonAddNewUser_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Addnewuser ,*Gu;
daj=1;
Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
Addnewuser=lookup_widget(objet,"windowAddUsern");

gtk_widget_destroy(Gu);

Addnewuser=create_windowAddUsern();
gtk_widget_show(Addnewuser);
}


void
on_buttonEdit0User_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
char ch1[20];
char ch2[20];
int a;

dsa =1;
GtkWidget *nom ,*prenom,*login,*pass,*cin,*role,*numbv,*jour,*mois,*annee,*windowAddUser,*windowUserAddedSucc,*check1;

GtkWidget *Addnewuser ,*Gu,*h,*f;

Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
Addnewuser=lookup_widget(objet,"windowAddUsern");

gtk_widget_destroy(Gu);

Addnewuser=create_windowAddUsern();
gtk_widget_show(Addnewuser);

nom=lookup_widget(Addnewuser,"entryUserNom");
prenom=lookup_widget(Addnewuser,"entryUserPrenom");
login=lookup_widget(Addnewuser,"entryADDUserLogin");
pass=lookup_widget(Addnewuser,"entryADDUserPassword");
cin=lookup_widget(Addnewuser,"entryUserCIN");
role=lookup_widget(Addnewuser,"comboboxUserRole");
numbv=lookup_widget(Addnewuser,"entryUserBV");
jour=lookup_widget(Addnewuser,"spinbuttonUserJour");
mois=lookup_widget(Addnewuser,"spinbuttonUserMois");
annee=lookup_widget(Addnewuser,"spinbuttonUserAnnee");
check1=lookup_widget(Addnewuser,"checkbutton2_chek_ag"); 




idineed=u.UserCIN;


sprintf(ch1,"%d",u.UserCIN);
gtk_entry_set_text(GTK_ENTRY(cin),ch1);

sprintf(ch2,"%d",u.UserNumBV);
gtk_entry_set_text(GTK_ENTRY(numbv),ch2);

gtk_entry_set_text(GTK_ENTRY(nom),u.UserNom);
gtk_entry_set_text(GTK_ENTRY(prenom),u.UserPrenom);
gtk_entry_set_text(GTK_ENTRY(login),u.UserLogin);
gtk_entry_set_text(GTK_ENTRY(pass),u.UserPassword);

int i;


if (u.UserRole==1) i=0;
else if (u.UserRole==2) i=1;
else if (u.UserRole==3) i=2;

gtk_combo_box_set_active(GTK_COMBO_BOX (role),i);

h=lookup_widget(objet,"radiobuttonUserHomme");

f=lookup_widget(objet,"radiobuttonUserFemme");




if (u.UserGenre==2)
{gtk_toggle_button_set_active (GTK_RADIO_BUTTON (f), TRUE );}




gtk_spin_button_set_value(jour,u.UserDate.JourUser);

gtk_spin_button_set_value(mois,u.UserDate.MoisUser);

gtk_spin_button_set_value(annee,u.UserDate.AnneeUser);


}


void
on_buttonDelete0User_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ays ,*Gu;

Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
Ays=lookup_widget(objet,"windowAreUSure");

gtk_widget_destroy(Gu);

Ays=create_windowAreUSure();
gtk_widget_show(Ays);
}


void
on_radiobuttonUserHomme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
nug = 1;
else nug =2;
}


void
on_radiobuttonUserFemme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active((togglebutton)))
nug = 2;
else nug =1;
}


void
on_buttonUserAddsave_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
UserMAG au ;


GtkWidget *nom ,*prenom,*login,*pass,*cin,*role,*numbv,*jour,*mois,*annee,*windowAddUser,*windowUserAddedSucc,*check1;
const char *format;

char msg[50], *markup;

GtkWidget       *output,*output1,*output3;


windowAddUser=lookup_widget(objet,"windowAddUsern");
nom=lookup_widget(objet,"entryUserNom");
prenom=lookup_widget(objet,"entryUserPrenom");
login=lookup_widget(objet,"entryADDUserLogin");
pass=lookup_widget(objet,"entryADDUserPassword");
cin=lookup_widget(objet,"entryUserCIN");
role=lookup_widget(objet,"comboboxUserRole");
numbv=lookup_widget(objet,"entryUserBV");
jour=lookup_widget(objet,"spinbuttonUserJour");
mois=lookup_widget(objet,"spinbuttonUserMois");
annee=lookup_widget(objet,"spinbuttonUserAnnee");
check1=lookup_widget(objet,"checkbutton2_chek_ag"); 



char ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20];
int choix=0;
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check1)))
                {  
                  choix=1;
                }

strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(ch4,gtk_entry_get_text(GTK_ENTRY(pass)));
strcpy(ch5,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(ch6,gtk_entry_get_text(GTK_ENTRY(numbv)));
int x=atoi(gtk_entry_get_text(GTK_ENTRY(cin)));
if ( (strcmp(ch1,"")==0)||(strcmp(ch2,"")==0)||(strcmp(ch3,"")==0)||(strcmp(ch4,"")==0)||(strcmp(ch5,"")==0)||(strcmp(ch6,"")==0) )
{
output = lookup_widget(objet, "labelusererreur");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"Rempilr tout !");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);

}
else if ((chercheu("userfile.txt",x)==1) && ( daj==1)){

output1 = lookup_widget(objet, "labelusererreur");
gtk_label_set_text(GTK_LABEL(output1), "");
output = lookup_widget(objet, "labelcinerreur");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"CIN existe !");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);

/*if ((dsa==1)&&(idineed!=x)) {
output1 = lookup_widget(objet, "labelusererreur");
gtk_label_set_text(GTK_LABEL(output1), "");
output = lookup_widget(objet, "labelcinerreur");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"erreur mdif cin !");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);}*/
}







else if (strlen(ch5)!=8){
output1 = lookup_widget(objet, "labelusererreur");
gtk_label_set_text(GTK_LABEL(output1), "");
output = lookup_widget(objet, "labelcinerreur");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"Inserer 8 chiffres !");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);




}

 


else if(choix==0)
{
output3 = lookup_widget(objet, "labelusererreur");
gtk_label_set_text(GTK_LABEL(output3), "");
output1 = lookup_widget(objet, "labelcinerreur");
gtk_label_set_text(GTK_LABEL(output1), "");

output = lookup_widget(objet, "labelsaveedituser");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"Cocher la case !");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);

}


else {

strcpy(au.UserNom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(au.UserPrenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(au.UserLogin,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(au.UserPassword,gtk_entry_get_text(GTK_ENTRY(pass)));





au.UserDate.JourUser=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
au.UserDate.MoisUser=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
au.UserDate.AnneeUser=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if (strcmp("Admin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
{au.UserRole=1;}

else if (strcmp("Electeur",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
{au.UserRole=2;}

else if (strcmp("Agen BV",gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)))==0)
{au.UserRole=3;}
au.UserCIN = atoi(gtk_entry_get_text(GTK_ENTRY(cin)));
au.UserNumBV=atoi(gtk_entry_get_text(GTK_ENTRY(numbv)));
int id = atoi(gtk_entry_get_text(GTK_ENTRY(cin)));


if (nug==1){au.UserGenre=1;}
else if(nug==2){au.UserGenre=2;}

if (dsa==1)
{
au.UserVote =u.UserVote ;
if(nug==2){au.UserGenre=2;}
else {au.UserGenre=1;}
modifierutilisateur("userfile.txt", id,au);

gtk_widget_destroy(windowAddUser);

windowUserAddedSucc=lookup_widget(objet,"windowUserAddedSucc");
windowUserAddedSucc=create_windowUserAddedSucc ();
gtk_widget_show(windowUserAddedSucc);
dsa=0;
idineed =0;
}
else if (daj==1){
au.UserVote =-1;
ajouterutilisateur("usefile.txt",au);

gtk_widget_destroy(windowAddUser);

windowUserAddedSucc=lookup_widget(objet,"windowUserAddedSucc");
windowUserAddedSucc=create_windowUserAddedSucc ();
gtk_widget_show(windowUserAddedSucc);
daj=0;
}}


}


void
on_buttonUserCancelAdd_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Addnewuser ,*Gu,*tr;

Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
Addnewuser=lookup_widget(objet,"windowAddUsern");

gtk_widget_destroy(Addnewuser);

Gu=create_windowGestionnaireUtilisateurs();
gtk_widget_show(Gu);


tr=lookup_widget(Gu,"treeviewUsers");

showusers(tr);
}


void
on_buttonOKUserAdded_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)  
{
GtkWidget *OK ,*Gu,*tr;

Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
OK=lookup_widget(objet,"windowUserAddedSucc");

gtk_widget_destroy(OK);

Gu=create_windowGestionnaireUtilisateurs();
gtk_widget_show(Gu);

tr=lookup_widget(Gu,"treeviewUsers");

showusers(tr);
}





void
on_buttonYesDeleteUser_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
int a;
a=supprimerutilisateur("userfile.txt",u.UserCIN);
GtkWidget *Ays ,*Gu,*tr;

Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
Ays=lookup_widget(objet,"windowAreUSure");

gtk_widget_destroy(Ays);

Gu=create_windowGestionnaireUtilisateurs();

gtk_widget_show(Gu);
}


void
on_buttonNoDont_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ays ,*Gu,*tr;

Gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
Ays=lookup_widget(objet,"windowAreUSure");

gtk_widget_destroy(Ays);

Gu=create_windowGestionnaireUtilisateurs();

gtk_widget_show(Gu);



tr=lookup_widget(Gu,"treeviewUsers");

showusers(tr);
}


void
on_button_yah_Aziz_Deconnecter_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ad;
gtk_widget_destroy(lookup_widget(GTK_WIDGET(objet),"yahAzizListeElections"));
ad=create_windowAdminConnected();
gtk_widget_show(ad);
}


void
on_button_yah_Aziz_supprimer_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *yahAzizListeElections;


int a;

yahAzizListeElections = lookup_widget(GTK_WIDGET(objet),"yahAzizListeElections");
 GtkWidget *dialog2 = create_dialog2 ();
  gtk_widget_show (dialog2);
}


void
on_button_yah_Aziz_Modifier_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char ch1[20];
char ch2[20];


GtkWidget *mod, *yahAzizListeElections;
yahAzizListeElections=lookup_widget(objet,"yahAzizListeElections");

gtk_widget_destroy(yahAzizListeElections);
mod=create_yah_aziz_ajouter_moudifier();
gtk_widget_show(mod);
GtkWidget *id=lookup_widget(mod,"entry6");
sprintf(ch1,"%d",e.id_election);
gtk_entry_set_text(GTK_ENTRY(id),ch1);
GtkWidget *nbh=lookup_widget(mod,"entry7");
sprintf(ch2,"%d",e.nb_habitant);
gtk_entry_set_text(GTK_ENTRY(nbh),ch2);

/*GtkWidget *combobox1=lookup_widget(mod,"combobox_yah_Aziz_region");
gtk_combo_box_set_active_text(GTK_COMBO_BOX(combobox1));
GtkWidget *combobox2=lookup_widget(mod,"combobox_yah_Aziz_municipalite");
gtk_combo_box_set_active_text(GTK_COMBO_BOX(combobox2));*/
GtkWidget *rg=lookup_widget(mod,"combobox_yah_Aziz_region");
gtk_combo_box_set_active(rg,1);
GtkWidget *mun=lookup_widget(mod,"combobox_yah_Aziz_municipalite");
gtk_combo_box_set_active(mun,1);




GtkSpinButton *jr=lookup_widget(mod,"spinbutton_yahaziz_jour");
gtk_spin_button_set_value(jr,e.date_election.jour);
GtkSpinButton *m=lookup_widget(mod,"spinbutton_yahaziz_mois");
gtk_spin_button_set_value(m,e.date_election.mois);
GtkSpinButton *ann=lookup_widget(mod,"spinbutton_yahaziz_annee");
gtk_spin_button_set_value(ann,e.date_election.annee);
mdsup=1;

}


void
on_button_yah_Aziz_Ajout_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *yahAzizListeElections ,*yah_aziz_ajouter_moudifier;

yahAzizListeElections=lookup_widget(objet,"yahAzizListeElections");

gtk_widget_destroy(yahAzizListeElections);
yah_aziz_ajouter_moudifier=create_yah_aziz_ajouter_moudifier();
gtk_widget_show(yah_aziz_ajouter_moudifier);
mdsup=0;
}



void
on_button_yah_Aziz_Actualiser_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *yahAzizListeElections;
GtkWidget *treeview1;

yahAzizListeElections=lookup_widget(objet,"yahAzizListeElections");
gtk_widget_show(yahAzizListeElections);

treeview1=lookup_widget(yahAzizListeElections,"treeview1");
afficher_election(treeview1,e);
}


void
on_buttonchercher2az_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
 GtkWidget *treeview1;
char ch1[20];
int idc;
window1=lookup_widget(objet,"yahAzizListeElections");
treeview1=lookup_widget(window1,"treeview1");
GtkWidget *re=lookup_widget(GTK_WIDGET(objet),"yah_Aziz_Input_Recherche");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(re)));
if( (strcmp(ch1,"")!=0) ){
idc=atoi(gtk_entry_get_text(GTK_ENTRY(re)));
chercherid(idc);
afficher_rechid(treeview1,e);
}

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        gchar *data0;
	gchar *data1;
	gchar *data2;
	gchar *data3;
	gchar *data4;

	GtkListStore *list_store;
	list_store=gtk_tree_view_get_model(treeview);
	GtkTreeIter   iter;

          if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
 	    {
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &data0, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,1, &data1, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,2, &data2, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &data3, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,4, &data4, -1);

               
	sscanf (data0,"%d",&e.id_election);
        sscanf  (data1,"%d",&e.nb_habitant);

	strcpy (e.region, data2);
	strcpy (e.municipalite, data3);
	sscanf (data4,"%d/%d/%d",&e.date_election.jour,&e.date_election.mois,&e.date_election.annee);
idelaz=e.id_election;
}
}


void
on_button_yah_Aziz_Rech_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *check1;
	GtkWidget *check2;
	GtkWidget *window1;
	GtkWidget *treeview2;
	char type[40];
        char type1[40];
	election e;
        int choix[]={0,0};
	check1=lookup_widget(objet,"checkbutton1rs"); 
	check2=lookup_widget(objet,"checkbutton2rs"); 


        window1=lookup_widget(objet,"yahAzizListeElections");
        treeview2=lookup_widget(window1,"treeview2az");
           if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check1)))
                {  
                  choix[0]=1;
                }
            if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check2)))
                {   
                 choix[1]=1;
                }

	    if ((choix[0]==1) && (choix[1]==0))
                {  
                  strcpy(type,"tunis");
                  strcpy(type1,"tunis");
                  cherchers(type,type1);
                }
            else if ((choix[0]==0) && (choix[1]==1))
                {   
                 strcpy(type,"ariana");
                 strcpy(type1,"ariana");
               
                }
            else if ((choix[0]==1) && (choix[1]==1))
             { strcpy(type,"tunis");
              strcpy(type1,"ariana");}
            else 
             { strcpy(type,"chy");
               strcpy(type1,"chy");}
           
        cherchers(type,type1);
        afficher_rech(treeview2,e);
	

}


void
on_button_yah_Aziz_Confsupp_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dialog2=lookup_widget(objet,"dialog2");
int a;
 GtkWidget *radiobutton1=lookup_widget(objet,"radiobutton_yah_Aziz_ok") ;  
 GtkWidget *radiobutton2=lookup_widget(objet,"radiobutton_yah_Aziz_Non");
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1))==TRUE)
    		 {
        	   a=supprimer_election(e.id_election);  
                   gtk_widget_destroy(dialog2); 
     		 }

             else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2))==TRUE)
                 {
         	      gtk_widget_destroy(dialog2);

                 }
GtkWidget *treeview1;
treeview1=lookup_widget(objet,"treeview1");
afficher_election(treeview1,e);

}


void
on_button_yah_Aziz_back_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *yahAzizListeElections,*treeview1,*treeview2;
gtk_widget_destroy(lookup_widget(GTK_WIDGET(objet),"yah_aziz_ajouter_moudifier"));
yahAzizListeElections=create_yahAzizListeElections();
gtk_widget_show(yahAzizListeElections);
treeview1=lookup_widget(yahAzizListeElections,"treeview1");
afficher_election(treeview1,e);

treeview2=lookup_widget(yahAzizListeElections,"treeview2az");
afficher_rech(treeview2,e);

}





void
on_button_yah_Aziz_confirmer_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
const char *format;
char msg[50], *markup;
char ch1[20];
char ch2[20];
int a,b,choix=0;
GtkWidget *check1;
GtkWidget       *output;
GtkWidget       *output1;
GtkWidget *id=lookup_widget(GTK_WIDGET(objet),"entry6");
GtkWidget *nbh=lookup_widget(GTK_WIDGET(objet),"entry7");
GtkWidget *combobox1=lookup_widget(GTK_WIDGET(objet),"combobox_yah_Aziz_region");
GtkWidget *combobox2=lookup_widget(GTK_WIDGET(objet),"combobox_yah_Aziz_municipalite");
GtkWidget *jr=lookup_widget(GTK_WIDGET(objet),"spinbutton_yahaziz_jour");
GtkWidget *m=lookup_widget(GTK_WIDGET(objet),"spinbutton_yahaziz_mois");
GtkWidget *ann=lookup_widget(GTK_WIDGET(objet),"spinbutton_yahaziz_annee");
check1=lookup_widget(objet,"checkbutton_yah_aziz_saveModif"); 
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check1)))
                {  
                  choix=1;
                }
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(nbh)));


if( (strcmp(ch1,"")==0) || (strcmp(ch2,"")==0) )
{ 
GtkWidget *dialog3;
dialog3=create_dialog3() ;
gtk_widget_show(dialog3) ;
}
else if(strlen(gtk_entry_get_text(GTK_ENTRY(id)))!=4)
{
output = lookup_widget(objet, "label106");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg, "Inserer 4 chiffres");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);}

	
else if( (mdsup==0 && chercher_election(atoi(gtk_entry_get_text(GTK_ENTRY(id))))==1) ||( mdsup==1 && chercher_election(atoi(gtk_entry_get_text(GTK_ENTRY(id))))==1 && atoi(gtk_entry_get_text(GTK_ENTRY(id)))!=idelaz))
{

output = lookup_widget(objet, "label106");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg, "Identifant existe");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);}
	
else if(choix==0){
output1 = lookup_widget(objet, "label106");
gtk_label_set_text(GTK_LABEL(output1), "");
output = lookup_widget(objet, "label107");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg, "Ce champ est obligatoire");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
	}

else{
output1 = lookup_widget(objet, "label107");
gtk_label_set_text(GTK_LABEL(output1), "");
e.id_election=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
e.nb_habitant=atoi(gtk_entry_get_text(GTK_ENTRY(nbh)));
strcpy(e.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(e.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
e.date_election.jour= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jr));
e.date_election.mois= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
e.date_election.annee= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ann));
GtkWidget *dialog4;
dialog4=create_dialog4() ;
gtk_widget_show(dialog4) ;
if (mdsup==0){
a=ajouter_election(e);}
else {

a=modifier_election(idelaz,e);
}
}

}


void
on_button_modif_bv_JE_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
int y;
GtkWidget *id_bv,*id_ag,*munic,*ecole,*num_salle,*cap_obs,*cap_elect,*sortie;
GtkWidget *tree_bv;

bureau nouv;



id_bv=lookup_widget(GTK_WIDGET(objet),"entry_modif_id_bv_JE");
id_ag=lookup_widget(GTK_WIDGET(objet),"entry_modif_id_ag_JE");
munic=lookup_widget(GTK_WIDGET(objet),"combo_modif_munic_JE");
ecole=lookup_widget(GTK_WIDGET(objet),"combo_modif_ecol_JE");
num_salle=lookup_widget(GTK_WIDGET(objet),"spin_modif_num_sal_JE");
cap_obs=lookup_widget(GTK_WIDGET(objet),"spin_modif_cap_obs_JE");
cap_elect=lookup_widget(GTK_WIDGET(objet),"spin_modif_cap_elec_JE");



nouv.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));
nouv.id_agent=atoi(gtk_entry_get_text(GTK_ENTRY(id_ag)));

strcpy(nouv.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(munic)));
strcpy(nouv.ecole,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ecole)));

nouv.num_salle= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_salle));
nouv.capacite_des_observateurs= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cap_obs));
nouv.capacite_des_electeurs= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cap_elect));


y=modifier(nouv.id_bureau,nouv,"bureau.txt");

	


GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;


fenetre_modif=lookup_widget(GTK_WIDGET(objet),"jamel3_JE");
gtk_widget_destroy(fenetre_modif);
fenetre_afficher=lookup_widget(GTK_WIDGET(objet),"jamel_2");
fenetre_afficher=create_jamel_2();
gtk_widget_show(fenetre_afficher) ;
tree_bv=lookup_widget(fenetre_afficher,"treebv");
afficher_bureau(tree_bv);

}


void
on_button_return_modif_bv_JE_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;
GtkWidget *tree_bv;



fenetre_modif=lookup_widget(GTK_WIDGET(objet),"jamel3_JE");
gtk_widget_destroy(fenetre_modif);
fenetre_afficher=lookup_widget(GTK_WIDGET(objet),"jamel_2");
fenetre_afficher=create_jamel_2();
gtk_widget_show(fenetre_afficher) ;
tree_bv=lookup_widget(fenetre_afficher,"treebv");
afficher_bureau(tree_bv);
}


void
on_button_confir_supp_bv_JE_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *tree_bv,*id_bv;
bureau b ;

GtkWidget *fenetre_supp;
GtkWidget *fenetre_afficher;


id_bv=lookup_widget(GTK_WIDGET(objet),"entry_supp_JE");
b.id_bureau=atoi(gtk_entry_get_text(GTK_ENTRY(id_bv)));

if (yes==1)
{int a=supprimer(b.id_bureau,"bureau.txt");



fenetre_supp=lookup_widget(GTK_WIDGET(objet),"Supp_JE");
gtk_widget_destroy(fenetre_supp);
fenetre_afficher=lookup_widget(GTK_WIDGET(objet),"jamel_2");
fenetre_afficher=create_jamel_2();
gtk_widget_show(fenetre_afficher) ;
tree_bv=lookup_widget(fenetre_afficher,"treebv");
afficher_bureau(tree_bv);

}
else if (yes==0){
fenetre_supp=lookup_widget(GTK_WIDGET(objet),"Supp_JE");
gtk_widget_destroy(fenetre_supp);
fenetre_afficher=lookup_widget(GTK_WIDGET(objet),"jamel_2");
fenetre_afficher=create_jamel_2();
gtk_widget_show(fenetre_afficher) ;
tree_bv=lookup_widget(fenetre_afficher,"treebv");
afficher_bureau(tree_bv);}
}


void
on_closebutton_controle_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dialog3=lookup_widget(GTK_WIDGET(objet),("dialog3"));

gtk_widget_destroy(dialog3);

}


void
on_closebutton_succes_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dialog4=lookup_widget(GTK_WIDGET(objet),("dialog4"));

gtk_widget_destroy(dialog4);

}


void
on_button4_LS_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod, *louay1;
louay1=lookup_widget(GTK_WIDGET(button),"Louay2");



gtk_widget_destroy(louay1);
mod=lookup_widget(GTK_WIDGET(button),"Louay1");
mod=create_Louay1();
gtk_widget_show(mod);

}


void
on_button5_LS_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{char ch1[20];
char ch2[20],ch3[20];
int a;
int choix[]={0,0,0};

GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
check1=lookup_widget(objet,"radiobutton1LS"); 
check2=lookup_widget(objet,"radiobutton2LS");
check3=lookup_widget(objet,"radiobutton3LS"); 
GtkWidget *idrec=lookup_widget(GTK_WIDGET(objet),"entryIdRec");
GtkWidget *id=lookup_widget(GTK_WIDGET(objet),"entry4LS");
GtkWidget *nbh=lookup_widget(GTK_WIDGET(objet),"entryidobs");
GtkWidget *combobox1=lookup_widget(GTK_WIDGET(objet),"combobox1ls");
GtkWidget *jr=lookup_widget(GTK_WIDGET(objet),"spinbutton1LS");
GtkWidget *m=lookup_widget(GTK_WIDGET(objet),"spinbutton2LS");
GtkWidget *ann=lookup_widget(GTK_WIDGET(objet),"spinbutton3LS");
GtkWidget *rec=lookup_widget(GTK_WIDGET(objet),"entry3LS");


 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check1)))
                {  
                  choix[0]=1;
                }
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check2)))
                {   
                 choix[1]=1;
                }
 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(check3)))
                {  
                  choix[2]=1;
                }
if ((choix[0]==1) && (choix[1]==0) && (choix[2]==0))
                {  
                  r.degre_durgence=1;
                }
  else if ((choix[0]==0) && (choix[1]==1)&& (choix[2]==0))
                {     
               r.degre_durgence=2;
                }
    else if ((choix[0]==0) && (choix[1]==0)&& (choix[2]==1))
             { r.degre_durgence=3;
              }
            
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(idrec)));
strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(nbh)));

r.ID_Rec=atoi(gtk_entry_get_text(GTK_ENTRY(idrec)));
r.ID_bureau_de_vote=atoi(gtk_entry_get_text(GTK_ENTRY(id)));
r.ID_observateur=atoi(gtk_entry_get_text(GTK_ENTRY(nbh)));

if (strcmp("liste1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
{r.listereclamee=1;}

else if (strcmp("liste2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
{r.listereclamee=2;}

else if (strcmp("liste3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
{r.listereclamee=3;}



          



r.recDate.jour= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jr));
r.recDate.mois= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
r.recDate.annee= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ann));

strcpy(r.texte_Rec,gtk_entry_get_text(GTK_ENTRY(rec)));
ajouter_reclamation(r);
}
void
on_button9_LS_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod, *louay1;
louay1=lookup_widget(GTK_WIDGET(button),"Louay2");



gtk_widget_destroy(louay1);
mod=lookup_widget(GTK_WIDGET(button),"Louay1");
mod=create_Louay1();
gtk_widget_show(mod);


}


void
on_buttonbacklouay1_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod, *WindowAzizUserLogin;
WindowAzizUserLogin=lookup_widget(GTK_WIDGET(button),"Louay1");



gtk_widget_destroy(WindowAzizUserLogin);
mod=lookup_widget(GTK_WIDGET(button),"WindowAzizUserLogin");
mod=create_WindowAzizUserLogin();
gtk_widget_show(mod);
}


void
on_treeviewlouay_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{       gchar *data0;
	gchar *data1;
	gchar *data2;
	gchar *data3;
	gchar *data4;
	gchar *data5;
	gchar *data6;

	GtkListStore *list_store;
	list_store=gtk_tree_view_get_model(treeview);
	GtkTreeIter   iter;

          if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
 	    {
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &data0, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,1, &data1, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,2, &data2, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &data3, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,4, &data4, -1);
                gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,5, &data5, -1);
                gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,6, &data6, -1);

        sscanf (data0,"%d/%d/%d",&r.recDate.jour,&r.recDate.mois,&r.recDate.annee);     
	sscanf (data1,"%d",&r.ID_observateur);
        sscanf  (data2,"%d",&r.ID_bureau_de_vote);
	sscanf (data3,"%d",&r.ID_Rec);
        sscanf  (data4,"%d",&r.degre_durgence);
        sscanf  (data5,"%d",&r.listereclamee);

	
	strcpy (r.texte_Rec,data6);
	
}

}


void
on_buttonAjouterrec1_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *louay1 ,*louay2;

louay1=lookup_widget(objet,"Louay1");

gtk_widget_destroy(louay1);
louay2=create_Louay2();
gtk_widget_show(louay2);
}





void
on_buttonSuppRec_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
int a;

a=supprimer_rec("raclamation.txt",r.ID_Rec);
}


void
on_buttonActualiserlouay_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GestRec r;
GtkWidget *louay1;
GtkWidget *treeview1;

louay1=lookup_widget(objet,"Louay1");
treeview1=lookup_widget(louay1,"treeviewlouay");
AffichRec(treeview1,r);
}


void
on_button3_MBG_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
int a;
GtkWidget *id_liste,*id_electeur2,*id_electeur3,*orientation,*election,*jour,*mois,*annee;
GtkWidget *tree_bv;
char elect2[20];
char elect3[20];
char elect[20];




id_liste=lookup_widget(GTK_WIDGET(button),"entry5_MBG");
id_electeur2=lookup_widget(GTK_WIDGET(button),"combobox_MBG");
id_electeur3=lookup_widget(GTK_WIDGET(button),"combobox2_MBG");
election=lookup_widget(GTK_WIDGET(button),"combobox3_MBG");
jour=lookup_widget(GTK_WIDGET(button),"spinbutton1_MBG");
mois=lookup_widget(GTK_WIDGET(button),"spinbutton2_MBG");
annee=lookup_widget(GTK_WIDGET(button),"spinbutton3_MBG");





l.id_liste=atoi(gtk_entry_get_text(GTK_ENTRY(id_liste)));


strcpy(elect2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id_electeur2)));
strcpy(elect3,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id_electeur3)));
strcpy(elect,gtk_combo_box_get_active_text(GTK_COMBO_BOX(election)));
l.id_electeur2=atoi(elect2);

l.id_electeur3=atoi(elect3);
l.id_election=atoi(elect);



l.d.j= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
l.d.m= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
l.d.a= (int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(orient==1)
{strcpy(l.orientation,"Gauche");
}
if(orient==2)
{strcpy(l.orientation,"Droite");
}
if(orient==3)
{strcpy(l.orientation,"Centre");
}



a=ajouter_liste(l);
	


GtkWidget *affiche ,*ge;

ge=lookup_widget(GTK_WIDGET(button),"maissa_2");

affiche=lookup_widget(GTK_WIDGET(button),"maissa_3");

gtk_widget_destroy(ge);

affiche=create_maissa_3();

gtk_widget_show(affiche);


tree_bv=lookup_widget(affiche,"treeview3_MBG");
afficher_liste(tree_bv);
}


void
on_treeview3_MBG_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        gchar *data0;
	gchar *data1;
	gchar *data2;
	gchar *data3;
	gchar *data4;
	gchar *data5;
	gchar *data6;
        gchar *data7;

	GtkListStore *list_store;
	list_store=gtk_tree_view_get_model(treeview);
	GtkTreeIter   iter;

          if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
 	    {
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &data0, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,1, &data1, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,2, &data2, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,3, &data3, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,4, &data4, -1);
                gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,5, &data5, -1);
                gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,6, &data6, -1);
                gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,7, &data7, -1);

        sscanf (data0,"%d",&l.id_liste);     
	sscanf (data1,"%d",&l.id_election);
        sscanf  (data2,"%d",&l.d.j);
	sscanf (data3,"%d",&l.d.m);
        sscanf  (data4,"%d",&l.d.a);
        sscanf  (data5,"%d",&l.id_electeur2);
        sscanf  (data6,"%d",&l.id_electeur3);
 

	
	strcpy (l.orientation,data7);
}}


void
on_treeviewUsers_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	gchar *data0;
	gchar *data1;
	gchar *data2;
	gchar *data3;
	gchar *data4;
	gchar *data5;
	gchar *data6;
	gchar *data7;
	gchar *data8;
	gchar *data9;
	
	

	GtkListStore *list_store;
	list_store=gtk_tree_view_get_model(treeview);
	GtkTreeIter   iter;

          if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
 	    {
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 0, &data0, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 1, &data1, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 2, &data2, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 3, &data3, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 4, &data4, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 5, &data5, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 6, &data6, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 7, &data7, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 8, &data8, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter, 9, &data9, -1);

        strcpy (u.UserNom,data0);
        strcpy (u.UserPrenom,data1);
	strcpy (u.UserLogin, data2);
	strcpy (u.UserPassword,data3);
	/*sscanf (data4,"%d",&u.UserCIN);
        sscanf (data5,"%d",&u.UserRole);
	sscanf  (data6,"%d",&u.UserVote);
        sscanf  (data7,"%d",&u.UserGenre);
        sscanf  (data8,"%d",&u.UserNumBV);*/
        u.UserCIN=data4;
	u.UserRole=data5;
	u.UserVote=data6;
	u.UserGenre=data7;
	u.UserNumBV=data8;
	sscanf (data9,"%d/%d/%d",&u.UserDate.JourUser,&u.UserDate.MoisUser,&u.UserDate.AnneeUser);
	
}
}

void
on_button_act_ag_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gu;
GtkWidget *tr;



gu=lookup_widget(objet,"windowGestionnaireUtilisateurs");
gtk_widget_destroy(gu);
gu=create_windowGestionnaireUtilisateurs() ;
gtk_widget_show (gu);

tr=lookup_widget(gu,"treeviewUsers");
showusers(tr);
}


void
on_button_rech_ag_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window1;
GtkWidget *treeview1;
char ch1[20];
int idc,a;
UserMAG ur;

GtkWidget *re=lookup_widget(GTK_WIDGET(objet),"entry8_rech_ag");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(re)));

idc=atoi(gtk_entry_get_text(GTK_ENTRY(re)));
a=chercheu("userfile.txt",  idc);
window1=lookup_widget(objet,"windowGestionnaireUtilisateurs");
treeview1=lookup_widget(window1,"treeviewUsers");

voteunvotezero( "userfile.txt" );

if ((voteu==1)&&(votez!=1))
{ 

window1=lookup_widget(objet,"windowGestionnaireUtilisateurs");
gtk_widget_destroy(window1);
window1=create_windowGestionnaireUtilisateurs() ;
gtk_widget_show (window1);
treeview1=lookup_widget(window1,"treeviewUsers");

voterech(treeview1, "voteun.txt");

}

else if ((voteu!=1)&&(votez==1))
{
window1=lookup_widget(objet,"windowGestionnaireUtilisateurs");
gtk_widget_destroy(window1);
window1=create_windowGestionnaireUtilisateurs() ;
gtk_widget_show (window1);
treeview1=lookup_widget(window1,"treeviewUsers");
voterech(treeview1, "votezero.txt");
}

else if ((voteu==1)&&(votez==1))

{

window1=lookup_widget(objet,"windowGestionnaireUtilisateurs");
gtk_widget_destroy(window1);
window1=create_windowGestionnaireUtilisateurs() ;
gtk_widget_show (window1);
treeview1=lookup_widget(window1,"treeviewUsers");
voterech(treeview1, "votex.txt");



}
else if ( (strcmp(ch1,"")!=0)&&(voteu!=1)&&(votez!=1)){


if (a==1){
ur=chercherutilisateur("userfile.txt", idc);

ajouterutilisateurr("usefile1.txt",ur);
window1=lookup_widget(objet,"windowGestionnaireUtilisateurs");
gtk_widget_destroy(window1);
window1=create_windowGestionnaireUtilisateurs() ;
gtk_widget_show (window1);

treeview1=lookup_widget(window1,"treeviewUsers");

showuserss(treeview1);}


}voteu=0;
votez=0;
}



void
on_checkbutton2_chek_ag_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button1sta_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{const char *format;
char msg[50], *markup;
char ch1[50];
GtkWidget       *output;
float te;

TPE(&te);
output = lookup_widget(objet, "label1sta");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#0008ff\"><b>\%s</b></span>";
sprintf(msg,"le taux de participation des electeur =%.2f ./.",te);
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);



}


void
on_button2sta_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{const char *format;
const char *format2;
const char *format3;
char msg[50], *markup;
char msg1[50],msg3[50];
GtkWidget       *output;
GtkWidget       *output2;
GtkWidget       *output3;
float th,tf;
TPHF(&th,&tf);
int a,b;
a=(int)th;
b=(int)tf;
if(a>b){
output = lookup_widget(objet, "label2sta");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground='green'><b>\%s</b></span>";
sprintf(msg,"le taux de participation des homme =%.2f ./.",th);
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
output2 = lookup_widget(objet, "label3sta");
gtk_label_set_text(GTK_LABEL(output2), "");
format2 = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg1,"le taux de participation des femme =%.2f ./.",tf);
markup= g_markup_printf_escaped(format2, msg1);
gtk_label_set_markup(GTK_LABEL(output2), markup);}

else if(a<b){
output = lookup_widget(objet, "label2sta");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground='green'><b>\%s</b></span>";
sprintf(msg,"le taux de participation des femme =%.2f ./.",tf);
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
output2 = lookup_widget(objet, "label3sta");
gtk_label_set_text(GTK_LABEL(output2), "");
format2 = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg1,"le taux de participation des homme =%.2f ./.",th);
markup= g_markup_printf_escaped(format2, msg1);
gtk_label_set_markup(GTK_LABEL(output2), markup);}

else {
output = lookup_widget(objet, "label2sta");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground='green'><b>\%s</b></span>";
sprintf(msg,"le taux de participation des homme =%.2f ./.",th);
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
output2 = lookup_widget(objet, "label3sta");
gtk_label_set_text(GTK_LABEL(output2), "");
format2 = "<span foreground='green'><b>\%s</b></span>";
sprintf(msg1,"le taux de participation des femme =%.2f ./.",tf);
markup= g_markup_printf_escaped(format2, msg1);
gtk_label_set_markup(GTK_LABEL(output2), markup);


}}


void
on_backsta_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *stat ,*Gu;



Gu=lookup_widget(objet,"windowAdminConnected");
stat=lookup_widget(objet,"stat");

gtk_widget_destroy(stat);

Gu=create_windowAdminConnected();
gtk_widget_show(Gu);
}


void
on_backvote_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *stat ,*Gu;



Gu=lookup_widget(objet,"maissa_1");
stat=lookup_widget(objet,"maissa_4");

gtk_widget_destroy(stat);

Gu=create_maissa_1();
gtk_widget_show(Gu);
}


void
on_confirmervote_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
char ch1[20],ch2[20];
int ide,idu,v,x;
const char *format;
const char *format2;
const char *format3;
char msg[50], *markup;
char msg1[50],msg3[50];
GtkWidget       *output;
GtkWidget       *output2;
GtkWidget       *output3;
GtkWidget *id1=lookup_widget(GTK_WIDGET(objet),"entry1vote");
GtkWidget *id2=lookup_widget(GTK_WIDGET(objet),"entry2vote");
GtkWidget *vote=lookup_widget(GTK_WIDGET(objet),"spinbutton1vote");

strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(id1)));
strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(id2)));

idu=atoi(ch1);
ide=atoi(ch2);
v=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(vote));
u=chercherutilisateur("userfile",idu);
e=chercher_election1(ide);
if( (strcmp(ch1,"")==0) || (strlen(ch1)!=8))
{ 
output = lookup_widget(objet, "label1vote");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"inserer 8 chiffre");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
}
else if((strcmp(ch2,"")==0)|| (strlen(ch2)!=4))
{output = lookup_widget(objet, "label1vote");
 gtk_label_set_text(GTK_LABEL(output), "");
output2 = lookup_widget(objet, "label2vote");
gtk_label_set_text(GTK_LABEL(output2), "");
format2 = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg1,"inserer 4 chiffre");
markup= g_markup_printf_escaped(format2, msg1);
gtk_label_set_markup(GTK_LABEL(output2), markup);
}
else if( (u.UserCIN==-1) || (u.UserRole!=2))
{output2 = lookup_widget(objet, "label2vote");
 gtk_label_set_text(GTK_LABEL(output2), "");
output = lookup_widget(objet, "label1vote");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"electeur n'existe pas ");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
}
else if (e.id_election==-1)
{output = lookup_widget(objet, "label1vote");
gtk_label_set_text(GTK_LABEL(output), "");
output2 = lookup_widget(objet, "label2vote");
gtk_label_set_text(GTK_LABEL(output2), "");
format2 = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg1,"cette election n'exixte pas");
markup= g_markup_printf_escaped(format2, msg1);
gtk_label_set_markup(GTK_LABEL(output2), markup);
}
else if (u.UserVote==0)
{
output2 = lookup_widget(objet, "label2vote");
 gtk_label_set_text(GTK_LABEL(output2), "");
output = lookup_widget(objet, "label3vote");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"vous avez deja fait un vote blanc");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);}
else if (u.UserVote!=-1){
output2 = lookup_widget(objet, "label2vote");
gtk_label_set_text(GTK_LABEL(output2), "");
output = lookup_widget(objet, "label3vote");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#FF0000\"><b>\%s</b></span>";
sprintf(msg,"vous avez voter la liste %d",u.UserVote);
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
}
else
{
u.UserVote=v;
x=modifierutilisateur("userfile",u.UserCIN,u);
output = lookup_widget(objet, "label3vote");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground='green'><b>\%s</b></span>";
sprintf(msg,"voter avec succe");
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);
}




}


void
on_checkbuttonvote0_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active((togglebutton)))
{votez=1;}
else votez=0;

}


void
on_checkbuttonvote1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active((togglebutton)))
{voteu=1;}
else voteu=0;

}


void
on_buttonazizyahyaouideconect2_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ad;
gtk_widget_destroy(lookup_widget(GTK_WIDGET(objet),"yahAzizListeElections"));
ad=create_WindowAzizUserLogin();
gtk_widget_show(ad);
}


void
on_buttonstatistique_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_administrateur ,*Gu;



Gu=lookup_widget(objet,"stat");
espace_administrateur=lookup_widget(objet,"windowAdminConnected");

gtk_widget_destroy(espace_administrateur);

Gu=create_stat();
gtk_widget_show(Gu);

}


void
on_actualiser_JE_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre;
GtkWidget *fenetre_afficher;
GtkWidget *tree_bv;

fenetre_afficher=lookup_widget(GTK_WIDGET(button),"jamel_2");

gtk_widget_destroy(fenetre_afficher);

fenetre=lookup_widget(GTK_WIDGET(button),"jamel_2");
fenetre=create_jamel_2();

gtk_widget_show(fenetre) ;

tree_bv=lookup_widget(fenetre,"treebv");
afficher_bureau(tree_bv);
}



void
on_treeview_bv_JE_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}





void
on_radiobuttonHomme_MG_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

   if (gtk_toggle_button_get_active((togglebutton)))
     obsg = 1;
}


void
on_radiobuttonFemme_MG_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{ if (gtk_toggle_button_get_active((togglebutton)))
     obsg = 2;

}


void
on_buttonsaveobs_MG_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

   GtkWidget *id, *nom ,*prenom,*nationalite,*profession,*sexe,*jour,*mois,*annee,*mahmoud_INTERFACE2,*windowobsAddedSuccess;
   
char ch1[20];
int a;
mahmoud_INTERFACE2=lookup_widget(objet,"mahmoud_INTERFACE2");
nom=lookup_widget(objet,"entryObsNom");
prenom=lookup_widget(objet,"entryObsPrenom");
nationalite=lookup_widget(objet,"entryObsNationalite");
profession=lookup_widget(objet,"comboboxprofobs_MG");
jour=lookup_widget(objet,"jour_MG");
mois=lookup_widget(objet,"mois_MG");
annee=lookup_widget(objet,"annee__MG");
id=lookup_widget(objet,"entryObsId");

strcpy(obs.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(obs.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(obs.nationalite,gtk_entry_get_text(GTK_ENTRY(nationalite)));
obs.date.jour=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
obs.date.mois=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
obs.date.annee=(int)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if (strcmp("journalist",gtk_combo_box_get_active_text(GTK_COMBO_BOX(profession)))==0)
{obs.profession=1;}

else if (strcmp("hote",gtk_combo_box_get_active_text(GTK_COMBO_BOX(profession)))==0)
{obs.profession=2;}

else if (strcmp("interprète",gtk_combo_box_get_active_text(GTK_COMBO_BOX(profession)))==0)
{obs.profession=3;}

else if (strcmp("organisation mondiale",gtk_combo_box_get_active_text(GTK_COMBO_BOX(profession)))==0)
{obs.profession=4;}

obs.id = atoi(gtk_entry_get_text(GTK_ENTRY(id)));
if (obsg==1){obs.sexe=1;}
else if(obsg==2){obs.sexe=2;}

a = ajouterObs(obs);
GtkWidget *stat ,*Gu,*treeview1;



Gu=lookup_widget(objet,"mahmoud_INTERFACE1");
stat=lookup_widget(objet,"mahmoud_INTERFACE2");

gtk_widget_destroy(stat);

Gu=create_mahmoud_INTERFACE1();
gtk_widget_show(Gu);
//treeview1=lookup_widget(Gu,"treeviewobs");
//afficherObs(treeview1);
/*if(a==1) {
gtk_widget_destroy(mahmoud_INTERFACE2);

windowobsAddedSuccess=lookup_widget(objet,"windowobsAddedSuccess");
windowobsAddedSuccess=create_windowobsAddedSuccess ();
gtk_widget_show(windowobsAddedSuccess);*/
   
//}

}


void
on_button22_MG_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *gu;
GtkWidget *tr;



gu=lookup_widget(objet,"mahmoud_INTERFACE1");
gtk_widget_destroy(gu);
gu=create_mahmoud_INTERFACE1() ;
gtk_widget_show (gu);

tr=lookup_widget(gu,"treeviewobs_MG");
afficherObs(tr);
}


void
on_recheche_obs_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
 GtkWidget *treeview1;
char ch1[20];
int idc;
window1=lookup_widget(objet,"mahmoud_INTERFACE1");
treeview1=lookup_widget(window1,"treeviewobs_MG");
GtkWidget *re=lookup_widget(GTK_WIDGET(objet),"entryrech_MG");
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(re)));
if( (strcmp(ch1,"")!=0) )
{
idc=atoi(gtk_entry_get_text(GTK_ENTRY(re)));
chercherObs("observateurs.txt",idc);
afficherObs(treeview1);
}}


void
on_treeviewobs_MG_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 	gchar *data0;
	gchar *data1;
	gchar *data2;
	gchar *data3;
	gchar *data4;
	gchar *data5;
	gchar *data6;
	char id;

	GtkListStore *list_store;
	list_store=gtk_tree_view_get_model(treeview);
	GtkTreeIter   iter;

          if (gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store), &iter, path))
 	    {
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0, &data0, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,1, &data1, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,2, &data2, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,3, &data3, -1);
		gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,4, &data4, -1);
                gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,5, &data5, -1);
                gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,6, &data6, -1);


	sscanf (data0,"%d",&obs.id);
	strcpy (obs.nom,data1);
	strcpy (obs.prenom,data2);
	strcpy (obs.nationalite,data3);
 	sscanf (data4,"%d",&obs.profession);
	sscanf (data5,"%d",&obs.sexe);
	sscanf (data6,"%d/%d/%d",&obs.date.jour,&obs.date.mois,&obs.date.annee);     
	

        
	
		
	
}}


void
on_buttoncalnepbv_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
char calbvch[20];
int id ;


GtkWidget *bv,*lbv,*result;

bv=lookup_widget(objet,"entrybureaucalcul");

lbv = lookup_widget(objet, "labelnbpbv") ;

result = lookup_widget(objet, "labelchoisirbv") ;

id = atoi(gtk_entry_get_text(GTK_ENTRY(bv)));


int calbv=nbe("userfile.txt",id);

sprintf(calbvch, "%d" , calbv);

gtk_label_set_text(GTK_LABEL(result),calbvch);




}


void
on_buttoncalculagep_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

char calage[20];
int ann ;


GtkWidget *ac,*result;

ac=lookup_widget(objet,"entryAnneactuelle");


result = lookup_widget(objet, "labelgiveyearp") ;

ann = atoi(gtk_entry_get_text(GTK_ENTRY(ac)));
if (ann!=0){

float fcalage= agemoyen("userfile.txt", ann);

sprintf(calage, "%f" , fcalage);

gtk_label_set_text(GTK_LABEL(result),calage);}

else {

gtk_label_set_text(GTK_LABEL(result),"Donner l'annee actuelle");}



}





void
on_button_stat_vb_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{float b;
GtkWidget *rs;
char chaine[50];

rs=lookup_widget(GTK_WIDGET(button),"label_vbb");
b=TVB ("user.txt");
sprintf(chaine, "les votes blancs : %.2f %%" ,b);

gtk_label_set_text(GTK_LABEL(rs),chaine);


}

float tn;
float te;
void
on_button_taux_obs_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *rt,*re;
char chaine1[100];
char chaine2[100];

float tn=0,x;
float te=0,y;


rt=lookup_widget(GTK_WIDGET(button),"label_obs_tnn");

x=taux1("obs.txt",tn);


sprintf(chaine1,"\nle taux des obs tunisiennes %.2f %% \n",x);
gtk_label_set_text(GTK_LABEL(rt),chaine1);
re=lookup_widget(GTK_WIDGET(button),"label_obs_etr");
y=taux2("obs.txt",te);
sprintf(chaine2,"\net le taux des obs etranges %.2f %%\n",y);

gtk_label_set_text(GTK_LABEL(re),chaine2);



}


void
on_checkbutton1LS__toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}
void
on_buttonModifiRec1_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[200];
int a;

a=supprimer_rec( "raclamation.txt",r.ID_Rec) ; 

GtkWidget *mod, *louay1;
louay1=lookup_widget(GTK_WIDGET(button),"Louay1");



gtk_widget_destroy(louay1);
mod=lookup_widget(GTK_WIDGET(button),"Louay2");
mod=create_Louay2();
gtk_widget_show(mod);
GtkWidget *id=lookup_widget(mod,"entryIdRec");
sprintf(ch1,"%d",r.ID_Rec);
gtk_entry_set_text(GTK_ENTRY(id),ch1);
GtkWidget *bv=lookup_widget(mod,"entry4LS");
sprintf(ch2,"%d",r.ID_bureau_de_vote);
gtk_entry_set_text(GTK_ENTRY(bv),ch2);
GtkWidget *obs=lookup_widget(mod,"entryidobs");
sprintf(ch3,"%d",r.ID_observateur);
gtk_entry_set_text(GTK_ENTRY(obs),ch3);
GtkWidget *tr=lookup_widget(mod,"entry3LS");
sprintf(ch4,"%s",r.texte_Rec);
gtk_entry_set_text(GTK_ENTRY(tr),ch4);


GtkWidget *lr=lookup_widget(mod,"combobox1ls");
gtk_combo_box_set_active(lr,1);




GtkWidget *jr=lookup_widget(mod,"spinbutton1LS");
gtk_spin_button_set_value(jr,r.recDate.jour);
GtkWidget *m=lookup_widget(mod,"spinbutton2LS");
gtk_spin_button_set_value(m,r.recDate.mois);
GtkWidget *ann=lookup_widget(mod,"spinbutton3LS");
gtk_spin_button_set_value(ann,r.recDate.annee);

}



/*void
on_buttonstatRec1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{const char *format;
char msg[50], *markup;
char ch1[50];
GtkWidget       *output;
int nbcons ,nbhabitant,listelectorale;

gagnant(&nbcons,&nbhabitant , &listelectorale );
output = lookup_widget(button, "label4444");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#0008ff\"><b>\%s</b></span>";
sprintf(msg,"le nombre des candidat gagnant est   =%d ./.",nbcons);
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);


}*/


/*void
on_statNBobs_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{const char *format;
char msg[50], *markup;
char ch1[50];
GtkWidget       *output;
int x ;

nbobserver(&x);
output = lookup_widget(button, "label3333");
gtk_label_set_text(GTK_LABEL(output), "");
format = "<span foreground=\"#0008ff\"><b>\%s</b></span>";
sprintf(msg,"le nombre total des observateurs  =%d ./.",x);
markup= g_markup_printf_escaped(format, msg);
gtk_label_set_markup(GTK_LABEL(output), markup);

}*/


void
on_aficher_maissa_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *gu;
GtkWidget *tr;



gu=lookup_widget(objet,"maissa_3");
gtk_widget_destroy(gu);
gu=create_maissa_3() ;
gtk_widget_show (gu);

tr=lookup_widget(gu,"treeview3_MBG");
afficher_liste(tr);

}

