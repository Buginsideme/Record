//sorry i'll traslate it later
/*Si progettino tre funzioni:
1) leggi_mat, che legge i riempimenti di riga e colonna ed i valori di una matrice di numeri reali;
2) med_pos_mat, che riceve in ingresso una matrice M di numeri reali e
restituisce come parametro di di uscita la media dei soli elementi positivi di M.
La funzione dovrà anche restituire come valore di ritorno un valore booleano,
che deve essere pari a false qualora non vi siano in M elementi strettamente
maggiori di 0 (zero), e pari a true altrimenti;
3) calc_mag, che riceve in ingresso una matrice M ed il valore med_pos pari
alla media dei soli valori positivi di M, e restituisce come valore di ritorno
una struttura contenente tre campi: un campo di tipo reale (mag) che contiene
il valore del primo elemento della matrice maggiore della media degli elementi
positivi della matrice stessa, e due campi di tipo intero (rig e col) che
contengono l'indice di riga e di colonna di tale valore;*/
#include<iostream>
using namespace std;

const int md=20;
typedef float matrice[md][md];
struct struttura{
  float magg;
  int riga,colonna;
}cordinate;
//PROTOTIPI
void controllo(int&);
void leggi_mat(int&, int&, matrice&);
void stampa_mat(int&, int&, matrice&);
void med_pos_mat(int&, int&, matrice&, float&, float&, bool&, int&, int&);
void calc_mag(int&, int&, matrice&, float&, struttura&);


int main(){
  matrice mat;
  int rig,col, flag=0, contapos=0;
  float media, somma=0, massimo;
  bool positivi=true;
  cout<<"\nDammi il numero di righe (1-"<<md<<"): ";
  cin>>rig;
  controllo(rig);
  cout<<"\nDammi il numero di colonne (1-"<<md<<"): ";
  cin>>col;
  controllo(col);
  leggi_mat(rig,col,mat);
  stampa_mat(rig,col,mat);
  med_pos_mat(rig,col,mat,somma,media,positivi,flag,contapos);
  if(!positivi)
    cout<<"\nNon ci sono elementi positivi.";
  else{
    cout<<"\nLa media di tutti gli elementi della matrice è: "<<media;
    calc_mag(rig,col,mat,massimo,cordinate);
    cout<<"\nIl primo valore maggiore della media è: "<<cordinate.magg;
    cout<<"\nIn "<<cordinate.riga<<"° riga e in "<<cordinate.colonna<<"° colonna.";
  }
  cout<<"\n\n";
}
//FUNZIONI
void controllo(int& n){
  while(n<1 || n>md){
    cout<<"\nErrore! Inserisci un valore consono (1-"<<md<<"): ";
    cin>>n;
  }
}
void leggi_mat(int& rig, int& col, matrice& mat){
  for(int i=0; i<rig; i++){
    for(int j=0; j<col; j++){
      cout<<"\nDammi l'elemento in "<<i+1<<"° riga e in "<<j+1<<"° colonna: ";
      cin>>mat[i][j];
    }
  }
}
void stampa_mat(int& rig, int& col, matrice& mat){
  cout<<"\nEcco la matrice: "<<endl;
  for(int i=0; i<rig; i++){
    for(int j=0; j<col; j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void med_pos_mat(int& rig, int& col, matrice& mat, float& somma, float& media, bool& positivi, int& flag
,int& contapos){
  for(int i=0; i<rig; i++){
    for(int j=0; j<col; j++){
      if(mat[i][j]>0){
        somma+=mat[i][j];
        contapos++;
      }
      else
        flag++;
    }
  }
  media=somma/contapos;
  if(flag==(rig*col))
    positivi=false;
}
void calc_mag(int& rig, int& col, matrice& mat, float& massimo, struttura& cordinate){
  bool trovato=false;
  int i, j;
  massimo=mat[0][0];
  for(i=0; i<rig; i++){
    j=0;
    trovato=false;
    while(j<col && !trovato)
      if(mat[i][j]>massimo){
        massimo=mat[i][j];
        cordinate.magg=massimo;
        cordinate.riga=i+1;
        cordinate.colonna=j+1;
        trovato=true;
      }
      else
        j++;
  }
}
