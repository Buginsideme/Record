/*Si progettino tre funzioni:
1) leggi_mat, che legge da file i riempimenti ed i valori di una matrice;
2) crea_vett, che riceve in ingresso rig, col ed M e costruisce due vettori,
V_Ind e V_Rig. Il primo vettore (V_Ind) dovrà contenere un elemento per ogni
riga della matrice che ha almeno un valore negativo. Il valore di tale elemento
sarà l'indice della colonna che contiene il primo valore negativo di quella riga.
Se in una riga non vi è nessun elemento negativo, per quella riga nessun elemento
dovrà essere aggiunto a V_Ind. Il secondo vettore (V_Rig) conterrà gli indici
delle righe per le quali esiste almeno un elemento negativo;
3) stampa_vett, con la quale stampare a video un vettore o un opportuno messaggio
nel caso in cui esso non contenga elementi;*/
#include<iostream>
using namespace std;

const int md=20;
typedef int matrice[md][md];
typedef int vettore[md];
//PROTOTTIPI
void controllo(int&);
void leggi_mat(int&, int&, matrice&);
void stampa_mat(int&, int&, const matrice&);
void crea_vett(int&, int&, const matrice&, vettore&, vettore&, int&, int&);
void stampa_vett(int&, vettore&);

int main(){
  matrice mat;
  vettore v_ind, v_rig;
  int rig, col, k=0, z=0;
  cout<<"\nDammi il numero di righe (1-"<<md<<"): ";
  cin>>rig;
  controllo(rig);
  cout<<"\nDammi il numero di colonne (1-"<<md<<"): ";
  cin>>col;
  controllo(col);
  leggi_mat(rig,col,mat);
  stampa_mat(rig,col,mat);
  crea_vett(rig,col,mat,v_ind,v_rig,k,z);
  stampa_vett(k,v_ind);
  stampa_vett(z,v_rig);


  cout<<"\n\n";
}
//FUNZIONI
void controllo(int& n){
  while(n<1 || n>md){
    cout<<"\nValore errato, reinseriscilo (1-"<<md<<"): ";
    cin>>n;
  }
}
void leggi_mat(int& rig, int& col, matrice& mat){
  for(int i=0; i<rig; i++){
    for(int j=0; j<col; j++){
      cout<<"\nInserisci l'elemento in "<<i+1<<"° riga e in "<<j+1<<"° colonna: ";
      cin>>mat[i][j];
    }
  }
}
void stampa_mat(int& rig, int& col, const matrice& mat){
  cout<<"\nEcco la matrice: "<<endl;
  for(int i=0; i<rig; i++){
    for(int j=0; j<col; j++)
      cout<<mat[i][j]<<" ";
    cout<<"\n";
  }
}
void stampa_vett(int& n, vettore& vet){
  if(n==0)
    cout<<" Non contiene nessun elemento.";
  else {
  cout<<"\nEcco il vettore degli indici: {";
  for(int i=0; i<n; i++)
    cout<<" "<<vet[i]<<";";
  cout<<"}";
  }
}
void crea_vett(int& rig, int& col, const matrice& mat, vettore& v1, vettore& v2, int& k, int& z){
  bool trovato=false;
  int i,j;
  for(i=0;i<rig;i++){
    j=0;
    trovato=false;
    while(j<col && !trovato)
      if(mat[i][j]<0){
        v1[k++]=j;
        v2[z++]=i;
        trovato=true;
      }
      else
        j++;
  }
}
