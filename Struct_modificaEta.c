#include <stdio.h>
#include <stdlib.h>

// Definizione della struct Persona
struct Persona {
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
};

// Funzione che stampa i dettagli della persona (passaggio per valore)
void stampaDettagliPersona(struct Persona p) {
    printf("\nDettagli della persona (da funzione):\n");
    printf("Nome: %s\n", p.nome);
    printf("Cognome: %s\n", p.cognome);
    printf("Età: %d\n", p.eta);
    printf("Altezza: %.2f\n", p.altezza);
}

// Funzione che aggiorna l'età (passaggio per indirizzo)
void aggiornaEta(struct Persona *p, int nuovaEta) {
    p->eta = nuovaEta;
}

int main() {
    struct Persona persona1 = {"Marco", "Rossi", 15, 1.85};

    stampaDettagliPersona(persona1);

    int nuovaEta;
    printf("Inserisci la nuova eta: ");
    scanf("%d", &nuovaEta);  // Bisogna usare &nuovaEta

    aggiornaEta(&persona1, nuovaEta);  // Bisogna passare l'indirizzo

    stampaDettagliPersona(persona1);  // Mostrare i dettagli aggiornati

    return 0;
}
