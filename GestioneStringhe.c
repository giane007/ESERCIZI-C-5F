#include <stdio.h>
#include <string.h>

#define dim 200

// Funzione per controllare se un carattere è una lettera 
int Elettera(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Funzione per convertire carattere in minuscolo
char minuscola(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

// Funzione per verificare se un carattere è una vocale
int e_vocale(char c) {
    c = minuscola(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Funzione per contare le vocali in una stringa
int conta_vocali(char str[]) {
    int conta = 0;
    for (int i = 0; str[i]; i++)
        if (Elettera(str[i]) && e_vocale(str[i]))
            conta++;
    return conta;
}

// Funzione per contare le consonanti in una stringa
int conta_consonanti(char str[]) {
    int conta = 0;
    for (int i = 0; str[i]; i++)
        if (Elettera(str[i]) && !e_vocale(str[i]))
            conta++;
    return conta;
}

int main() {
    char str1[dim], str2[dim];
    char pari[dim], dispari[dim];
    char lettera;
    int i, len1, len2;
    int solo_lettere = 1;

    // Input prima stringa
    printf("Inserisci la prima stringa: ");
    fgets(str1, dim, stdin);

    // Rimuove newline manualmente
    for (i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == '\n') {
            str1[i] = '\0';
            break;
        }
    }

    // Verifica che contenga solo lettere
    for (i = 0; str1[i]; i++) {
        if (!Elettera(str1[i])) {
            solo_lettere = 0;
            break;
        }
    }

    if (!solo_lettere) {
        printf("La stringa contiene caratteri non alfabetici. Fine programma.\n");
        return 1;
    }

    printf("La stringa contiene solo lettere.\n");

    // Conteggio di una lettera
    printf("Inserisci la lettera da contare: ");
    scanf(" %c", &lettera);
    getchar();  // elimina newline rimasto nel buffer

    int conta = 0;
    for (i = 0; str1[i]; i++)
        if (minuscola(str1[i]) == minuscola(lettera))
            conta++;

    printf("La lettera '%c' compare %d volte.\n", lettera, conta);

    // Pari / dispari
    int p = 0, d = 0;
    for (i = 0; str1[i]; i++) {
        if (i % 2 == 0)
            pari[p++] = str1[i];
        else
            dispari[d++] = str1[i];
    }
    pari[p] = '\0';
    dispari[d] = '\0';

    printf("Lettere in posizione pari: %s\n", pari);
    printf("Lettere in posizione dispari: %s\n", dispari);

    // Doppie
    int ha_doppie = 0;
    for (i = 0; str1[i + 1]; i++) {
        if (minuscola(str1[i]) == minuscola(str1[i + 1])) {
            ha_doppie = 1;
            break;
        }
    }

    if (ha_doppie)
        printf("La stringa contiene doppie.\n");
    else
        printf("La stringa NON contiene doppie.\n");

    // Seconda stringa
    printf("Inserisci la seconda stringa: ");
    fgets(str2, dim, stdin);

    // Rimuove newline manualmente
    for (i = 0; str2[i] != '\0'; i++) {
        if (str2[i] == '\n') {
            str2[i] = '\0';
            break;
        }
    }

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 > len2)
        printf("La prima stringa è più lunga.\n");
    else if (len2 > len1)
        printf("La seconda stringa è più lunga.\n");
    else
        printf("Le due stringhe hanno la stessa lunghezza.\n");

    // Lettere comuni
    int comuni[26] = {0};
    for (i = 0; str1[i]; i++) {
        char c1 = minuscola(str1[i]);
        if (Elettera(c1)) {
            for (int j = 0; str2[j]; j++) {
                char c2 = minuscola(str2[j]);
                if (Elettera(c2) && c1 == c2) {
                    comuni[c1 - 'a'] = 1;
                    break;
                }
            }
        }
    }

    printf("Lettere comuni: ");
    int found = 0;
    for (i = 0; i < 26; i++) {
        if (comuni[i]) {
            printf("%c ", i + 'a');
            found = 1;
        }
    }
    if (!found)
        printf("Nessuna");
    printf("\n");

    // Vocali / Consonanti
    int vocali1 = conta_vocali(str1);
    int vocali2 = conta_vocali(str2);
    int cons1 = conta_consonanti(str1);
    int cons2 = conta_consonanti(str2);

    if (vocali1 > vocali2)
        printf("La prima stringa ha più vocali (%d).\n", vocali1);
    else if (vocali2 > vocali1)
        printf("La seconda stringa ha più vocali (%d).\n", vocali2);
    else
        printf("Entrambe le stringhe hanno lo stesso numero di vocali (%d).\n", vocali1);

    if (cons1 > cons2)
        printf("La prima stringa ha più consonanti (%d).\n", cons1);
    else if (cons2 > cons1)
        printf("La seconda stringa ha più consonanti (%d).\n", cons2);
    else
        printf("Entrambe le stringhe hanno lo stesso numero di consonanti (%d).\n", cons1);

    return 0;
}
