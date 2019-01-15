/*Data una matrice sparsa generare un elenco che riporti le posizioni di riga
e colonna ed il valore degli elementi non nulli. (sparsa=pochi elementi non
nulli)*/
#include<iostream>
#include<cstdlib>
using namespace std;

const int md=20;
typedef int matrice[md][md];
struct tipo_struttura {
        int riga,colonna,valore;
}cordinate;
typedef tipo_struttura vettore_str[md];
//PROTOTIPI
void controllo(int&);
void leggi_mat(int&, int&, matrice&);
void stampa_mat(int&, int&, matrice&);
void inserisci(int&, int&, int&, matrice&, vettore_str&);
void stampa(vettore_str&, int&);

int main(){
        matrice mat;
        vettore_str positivi;
        int rig, col, k=0;
        cout<<"\nDammi il numero di righe (1-"<<md<<"): ";
        cin>>rig;
        controllo(rig);
        cout<<"\nDammi il numero di colonne (1-"<<md<<"): ";
        cin>>col;
        controllo(col);
        leggi_mat(rig,col,mat);
        stampa_mat(rig,col,mat);
        inserisci(k,rig,col,mat,positivi);
        stampa(positivi,k);
        cout<<"\n\n";
}
//FUNZIONI
void controllo(int& n)
{
        while (n<1 || n>md) {
                cout<<"\nErrore! Reinserisci il valore (1-"<<md<<"): ";
                cin>>n;
        }
}
void leggi_mat(int& rig, int& col, matrice& mat)
{
        for (int i=0; i<rig; i++) {
                for (int j=0; j<col; j++) {
                        cout<<"\nDammi l'elemento in riga "<<i<<" e in colonna "<<j<<": ";
                        cin>>mat[i][j];
                }
        }
}
void stampa_mat(int& rig, int& col, matrice& mat)
{
        cout<<"\nEcco la matrice: "<<endl;
        for (int i=0; i<rig; i++) {
                for (int j=0; j<col; j++)
                        cout<<mat[i][j]<<" ";
                cout<<"\n";
        }
}
void inserisci(int& k, int& rig, int& col, matrice& mat, vettore_str& positivi)
{
        for (int i=0; i<rig; i++) {
                for (int j=0; j<col; j++)  {
                        if (mat[i][j]>0) {
                                positivi[k].valore=mat[i][j];
                                positivi[k].riga=i+1;
                                positivi[k].colonna=j+1;
                                k++;
                        }
                }
        }
}
void stampa(vettore_str& positivi, int& k)
{
        cout<<"\nRiga\tColonna\tValore"<<endl;
        for(int i=0; i<k; i++) {
                cout<<positivi[i].riga<<"\t";
                cout<<positivi[i].colonna<<"\t";
                cout<<positivi[i].valore<<"\t";
                cout<<"\n";
        }
}
