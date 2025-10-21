//@author Riccardo Gianesella 
/*
Obiettivo: Scrivere un programma in linguaggio C che gestisca un archivio di studenti.

Struttura dati

Dichiara una struttura chiamata Studente con i seguenti campi:

nome

cognome

matricola (stringa)

corso_di_studio

anno_immatricolazione

media_voti (float)

città_residenza

Il programma deve:

Determinare lo studente con la media voti più alta e quello con la media più bassa, e visualizzarne:

nome, cognome, corso di studio e media voti.

Ordinare la lista degli studenti in base all’anno di immatricolazione (dal più vecchio al più recente) e visualizzarla.

Consentire la ricerca di uno studente tramite il numero di matricola inserito dall’utente.

Visualizzare tutti gli studenti con una media voti superiore o uguale a un valore scelto dall’utente.

Calcolare la media generale delle medie dei voti di tutti gli studenti registrati.

Visualizzare tutti gli studenti immatricolati in un anno specifico, scelto dall’utente.
*/

#include <stdio.h>
#include <string.h>

struct Studente{
    char nome[50];
    char cognome[50];
    char matricola[50];
    char corso_di_studio[50];
    int anno_immatricolazione;
    float media_voti;
    char citta_residenza[50];
};

//@brief Inserimento dei dati
//@param S struct degli studenti
//@param nStudenti numero degli studenti
void inserisci(struct Studente S[], int nStudenti){
    for(int i = 0; i < nStudenti; i++){
        printf("\n Inserisci studente %d", i+1);
        
        printf("\n Inserisci nome: ");
        scanf("%s", S[i].nome);

        printf("\n Inserisci cognome: ");
        scanf("%s", S[i].cognome);

        printf("\n Inserisci matricola: ");
        scanf("%s", S[i].matricola);

        printf("\n Inserisci corso di studio: ");
        scanf("%s", S[i].corso_di_studio);

        printf("\n Inserisci anno di immatricolazione: ");
        scanf("%d", &S[i].anno_immatricolazione);

        printf("\n Inserisci media dei voti: ");
        scanf("%f", &S[i].media_voti);

        printf("\n Inserisci città di residenza: ");
        scanf("%s", S[i].citta_residenza);
    }
}

//@brief Visualizzazione dei dati
//@param S struct degli studenti
//@param nStudenti numero degli studenti
void visualizza(struct Studente S[], int nStudenti){
    for(int i=0;i<nStudenti;i++){
        printf("\n Studente %d", i+1);
        printf("\n Nome : %s", S[i].nome);
        printf("\n Cognome : %s", S[i].cognome);
        printf("\n Matricola : %s", S[i].matricola);
        printf("\n Corso di studio : %s", S[i].corso_di_studio);
        printf("\n Anno di immatricolazione : %d", S[i].anno_immatricolazione);
        printf("\n Media voti : %f", S[i].media_voti);
        printf("\n Città di residenza : %s \n", S[i].citta_residenza);
    }
}

//@brief Visualizzazione di dati di uno studente
//@param S struct degli studenti
//@param indice posizione dello studente
void visualizzaUna(struct Studente S[], int indice){
    
        printf("\n Nome : %s", S[indice].nome);
        printf("\n Cognome : %s", S[indice].cognome);
        printf("\n Matricola : %s", S[indice].matricola);
        printf("\n Corso di studio : %s", S[indice].corso_di_studio);
        printf("\n Anno di immatricolazione : %d", S[indice].anno_immatricolazione);
        printf("\n Media voti : %f", S[indice].media_voti);
        printf("\n Città di residenza : %s \n", S[indice].citta_residenza);
    
}


//@brief mediaMax media più alta degli studenti
//@param S struct degli studenti
//@param nStudenti numero degli studenti
int mediaMax(struct Studente S[], int nStudenti){
    
    int indice = 0;
    
    for(int i = 1 ; i<nStudenti ; i++){
        
        if(S[i].media_voti > S[indice].media_voti){
            indice = i;
        }
    }
    return indice;
}

//@brief mediaMin media più alta degli studenti
//@param S struct degli studenti
//@param nStudenti numero degli studenti
int mediaMin(struct Studente S[], int nStudenti){
    
    int indice = 0;
    
    for(int i = 1 ; i<nStudenti ; i++){
        
        if(S[i].media_voti < S[indice].media_voti){
            indice = i;
        }
    }
    return indice;
}


//@brief ordinaAnnoMatricolazione ornina in ordine crescente per anno di matricolazione
//@param S struct degli studenti
//@param nStudenti numero degli studenti
void ordinaAnnoMatricolazione(struct Studente S[], int nStudenti){ //Bubble sort
    for(int i = 0 ; i < nStudenti -1; i++){
        for(int j = i+1 ; j < nStudenti ; j++){
            if(S[i].anno_immatricolazione > S[j].anno_immatricolazione){
                struct Studente temp;
                temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
    }
}

//@brief ricercaNumeroMatricola cerca lo studente con il numero della matricola scelto dall'utente
//@param S struct degli studenti
//@param nStudenti numero degli studenti
//@param matricola numero che ha inserito l'utente
void ricercaNumeroMatricola(struct Studente S[], int nStudenti, char matricola[]) {
    int trovato = 0;
    for(int i=0; i< nStudenti; i++) {
        if(strcmp(S[i].matricola, matricola) == 0) {
            visualizzaUna(S, i);
            trovato = 1;
        }
    }
    if(!trovato) {
        printf("\n Nessuno studente trovato con la matricola %s\n", matricola);
    }
}

//@brief visualizzaMediaMinima fa vedere tutti gli studenti con una media più alta di quella scelta dall'utente
//@param S struct degli studenti
//@param nStudenti numero degli studenti
//@media media minima inserita dall'utente
void visualizzaMediaMinima(struct Studente S[], int nStudenti,float media){
    for(int i = 0 ; i < nStudenti ; i++){
        if(S[i].media_voti >= media){
            visualizzaUna(S,i);
        }
    }
}
//@brief mediaGenerale trova la media di tutte le medie degli studenti
//@param S struct degli studenti
//@param nStudenti numero degli studenti
float mediaGenerale(struct Studente S[], int nStudenti){
    int somma = 0;
    float media = 0;
    
    for(int i = 0 ; i < nStudenti ; i++){
        somma = somma + S[i].media_voti;
    }
    media = (float) somma / nStudenti;
    
    return media;
}
//@brief ricercaAnnoMatricola cerca lo studente con l'anno della matricola uguale a quello inserito dall'utente
//@param S struct degli studenti
//@param nStudenti numero degli studenti
//@param anno anno inserito dall'utente
void ricercaAnnoMatricola(struct Studente S[], int nStudenti, int anno){
    for(int i=0; i< nStudenti; i++){
        if(S[i].anno_immatricolazione == anno){
            visualizzaUna(S,i);
        }
    }
}


int main(){
    
    struct Studente studenti [50];

    int nStudenti = 0;
    
    int uscita = 0;
    
    do{
        printf("\n 1 Inserimento \n 2 Visualizza \n 3 media MAX e media MIN \n 4 Ordina anno di matricolazione \n 5 Ricerca numero di matricola \n 6 Visualizza per media minima \n 7 Media generale \n 8 Immatricolazioni \n 9 Uscita \n");
            
            int scelta;
            printf("\n Inserisci il caso ");
            scanf("%d", & scelta);

            switch (scelta){

                case 1: {
                    printf("\n Numero studenti da inserire ");
                    scanf("%d", &nStudenti);
                    inserisci(studenti,nStudenti);
                break;
                }

                case 2:{
                    visualizza(studenti,nStudenti);
                break;
                }
                
                case 3:{
                    int indiceMax = mediaMax(studenti,nStudenti);
                    int indiceMin = mediaMin(studenti,nStudenti);
                    
                    printf("\n Media piu alta: %.2f",studenti[indiceMax].media_voti);
                    printf("\n Media piu bassa: %.2f",studenti[indiceMin].media_voti);
                break;
                }
                
                case 4:{
                    if (nStudenti == 0) {
                        printf("\n Nessuno studente inserito\n");
                    } else {
                        ordinaAnnoMatricolazione(studenti, nStudenti);
                        printf("\n Studenti ordinati per anno di immatricolazione: \n");
                        visualizza(studenti, nStudenti);
                    }
                break;
                }
                
                case 5:{
                    if (nStudenti == 0) {
                        printf("\n Nessuno studente inserito\n");
                    } else {
                        char numMatricola[50];
                        printf("\n Inserisci numero matricola da cercare: ");
                        scanf("%s", numMatricola);
                        ricercaNumeroMatricola(studenti,nStudenti,numMatricola);
                    }
                    
                break;
                }
                
                case 6:{
                    if (nStudenti == 0) {
                        printf("\n Nessuno studente inserito\n");
                    } else {
                        float mediaMinima;
                        printf("\n Inserisci media minima: \n");
                        scanf("%f", &mediaMinima);
                        visualizzaMediaMinima(studenti,nStudenti,mediaMinima);
                    }
                break;
                }
                
                case 7:{
                    if (nStudenti == 0) {
                        printf("\n Nessuno studente inserito\n");
                    } else {
                        printf("\n Media delle medie: %.2f",mediaGenerale(studenti,nStudenti));
                    }
                break;
                }
                
                case 8:{
                    if (nStudenti == 0) {
                        printf("\n Nessuno studente inserito\n");
                    } else {
                        int anno;
                        printf("\n Inserisci anno immatricolazione da cercare: ");
                        scanf("%d", &anno);
                        ricercaAnnoMatricola(studenti,nStudenti,anno);
                    }
                break;
                }
                
                case 9:{
                    uscita = 1;
                break;
                }
            }


    }while(uscita==0);

}

