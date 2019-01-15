/*Programma per capire a fondo i record e i vettori di record*/
//Cosa sono i record? "Contenitori di tipi diversi di dato"
#include<iostream>
using namespace std;

//dichiarazione di uno tipo struttura con il relativo alis al tipo
struct tipo_struttura {
        int campo1;
        char campo2;
}tipo1,tipo2;
//o direttamente così (su)

//creazione di un array di struct
struct tipo_struttur {
        int a;
        char b;
};
//def array di record
tipo_struttur robeh[10];

int main(){
        //definizione del tipo record
        //struct tipo_struttura tipo1, tipo2;
        int r;
        cout<<"\nDammi il riempimento: ";
        cin>>r;
        //caricamento dei valori nell'array di strutture
        for (int i=0; i<r;i++) {
                cout<<"\nDammi i valori della struttura: ";
                cin>>robeh[i].a;
                cin>>robeh[i].b;
        }
        for (int i=0; i<r; i++) {
                cout<<"\nEcco il numero: "<<robeh[i].a;
                cout<<"\nEcco la lettera: "<<robeh[i].b;
        }

        cout<<"\n\n";

}
