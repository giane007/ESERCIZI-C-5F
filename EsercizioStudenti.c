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
    
void visualizza(struct Studente S[], int nStudenti){
    for(int i=0;i<nStudenti;i++){
        printf("\n Studente %d", i+1);
        printf("\n Nome : %s", S[i].nome);
        printf("\n Cognome : %s", S[i].cognome);
        printf("\n Matricola : %s", S[i].matricola);
        printf("\n Corso di studio : %s", S[i].corso_di_studio);
        printf("\n Anno di immatricolazione : %d", S[i].anno_immatricolazione);
        printf("\n Media voti : %f", S[i].media_voti);
        printf("\n Città di residenza : %s", S[i].citta_residenza);
    }
}

int mediaMax(struct Studente S[], int nStudenti){
    
    int indice = 0;
    
    for(int i = 1 ; i<nStudenti ; i++){
        
        if(S[i].media_voti > S[indice].media_voti){
            indice = i;
        }
    }
    return indice;
}

int mediaMin(struct Studente S[], int nStudenti){
    
    int indice = 0;
    
    for(int i = 1 ; i<nStudenti ; i++){
        
        if(S[i].media_voti < S[indice].media_voti){
            indice = i;
        }
    }
    return indice;
}

void ordinaAnnoMAtricolazione(struct Studente S[], int nStudenti){ //Bubble sort
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



int main(){
    
    struct Studente studenti [50];

    int nStudenti = 0;
    
    int uscita = 0;
    
    do{
        printf("\n 1 Inserimento \n 2 Visualizza \n 3 media MAX e media MIN \n 4 Ordina anno di matricolazione \n 5 Ricerca numero di matricola \n 6 Visualizza per media minima \n 7 Media generale \n 8 Immatricolazioni \n");


            
            int scelta;
            printf("\n Inserisci il caso ");
            scanf("%d", & scelta);

            switch (scelta){

                case 1: 
                    printf("\n Numero studenti da inserire ");
                    scanf("%d", &nStudenti);
                    inserisci(studenti,nStudenti);
                break;

                case 2:
                    visualizza(studenti,nStudenti);
                break;

                case 3:
                    int indiceMax = mediaMax(studenti,nStudenti);
                    int indiceMin = mediaMin(studenti,nStudenti);
                    
                    printf("\n Media piu alta: %.2f",studenti[indiceMax].media_voti);
                    printf("\n Media piu bassa: %.2f",studenti[indiceMin].media_voti);
                
                    //printf("\n Media max: %d",mediaMax(studenti,nStudenti));
                    //printf("\n Media min: %d",mediaMin(studenti,nStudenti));
                break;

                case 4:
                    printf("\n");
                    ordinaAnnoMAtricolazione(studenti,nStudenti);
                break;

                case 5:
                break;

                case 6:
                break;

                case 7:
                break;

                case 8:
                    
                break;

                case 9:
                    uscita = 1;
                break;
            }


    }while(uscita==0);

}




