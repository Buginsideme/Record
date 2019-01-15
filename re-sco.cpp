/*Scrivere un programma che gestisca i dati degli scontrini emessi da una cassa utilizzando le struct*/
#include<iostream>
using namespace std;

typedef struct tipo_data{
  int giorno, mese, anno;
}day;

typedef struct tipo_orario{
  int ora, minuti;
}orario;

struct tipo_scontrino{
  day data;
  orario ora;
}scontrino;


int main(){
  cout<<"\nInserisci la data dello scontrino.";
  cout<<"\nDammi il giorno (gg): ";
  cin>>scontrino.data.giorno;
  cout<<"\nDammi il mese (mm): ";
  cin>>scontrino.data.mese;
  cout<<"\nDammi l'anno (aaa): ";
  cin>>scontrino.data.anno;




  cout<<"\n\n";
}
