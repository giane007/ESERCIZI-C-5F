/*
Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1) Che contenga solo lettere;
2) Il conteggio di una lettera (se presente) scelta dall’utente;
3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione
dispari;
4) Verifichi se contiene doppie.
Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quali sono le lettere contenute in ambedue le stringhe;
3) Quale delle 2 stringhe contiene più vocali;
4) Quale delle 2 stringhe contiene più consonanti;
*/

#include <stdio.h>
#include <string.h>

// Funzione per controllare se un carattere è una lettera (senza isalpha)
int is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Funzione per convertire carattere in minuscolo (senza tolower)
char to_lower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

// Funzione per verificare se un carattere è una vocale
int is_vowel(char c) {
    c = to_lower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Funzione per contare le vocali in una stringa
int count_vowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (is_letter(str[i]) && is_vowel(str[i]))
            count++;
    return count;
}

// Funzione per contare le consonanti in una stringa
int count_consonants(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (is_letter(str[i]) && !is_vowel(str[i]))
            count++;
    return count;
}

int main() {
    char str1[201], str2[201];
    char pari[201], dispari[201];
    char lettera;
    int i, len1, len2;
    int solo_lettere = 1;

    // Input prima stringa
    printf("Inserisci la prima stringa (max 200 caratteri): ");
    fgets(str1, 201, stdin);
    str1[strcspn(str1, "\n")] = 0;  // Rimuove il newline

    // Verifica che contenga solo lettere
    for (i = 0; str1[i]; i++) {
        if (!is_letter(str1[i])) {
            solo_lettere = 0;
            break;
        }
    }

    if (solo_lettere)
        printf("La stringa contiene solo lettere.\n");
    else {
        printf("La stringa contiene caratteri non alfabetici. Fine programma.\n");
        return 1;
    }

    // Conteggio di una lettera scelta dall'utente
    printf("Inserisci la lettera da contare: ");
    scanf(" %c", &lettera);
    getchar(); // Consuma il newline rimasto

    int count = 0;
    for (i = 0; str1[i]; i++) {
        if (to_lower(str1[i]) == to_lower(lettera))
            count++;
    }
    printf("La lettera '%c' compare %d volte.\n", lettera, count);

    // Stringhe di posizione pari e dispari
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

    // Verifica se contiene doppie
    int has_double = 0;
    for (i = 0; str1[i+1]; i++) {
        if (to_lower(str1[i]) == to_lower(str1[i+1])) {
            has_double = 1;
            break;
        }
    }
    if (has_double)
        printf("La stringa contiene doppie.\n");
    else
        printf("La stringa NON contiene doppie.\n");

    // Input seconda stringa
    printf("Inserisci la seconda stringa (max 200 caratteri): ");
    fgets(str2, 201, stdin);
    str2[strcspn(str2, "\n")] = 0;  // Rimuove il newline

    len1 = strlen(str1);
    len2 = strlen(str2);

    // Confronta le lunghezze
    if (len1 > len2)
        printf("La prima stringa è più lunga.\n");
    else if (len2 > len1)
        printf("La seconda stringa è più lunga.\n");
    else
        printf("Le due stringhe hanno la stessa lunghezza.\n");

    // Trova lettere comuni
    int comuni[26] = {0};
    for (i = 0; str1[i]; i++) {
        char c1 = to_lower(str1[i]);
        if (is_letter(c1)) {
            for (int j = 0; str2[j]; j++) {
                char c2 = to_lower(str2[j]);
                if (is_letter(c2) && c1 == c2) {
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

    // Conteggio vocali e consonanti
    int vocali1 = count_vowels(str1);
    int vocali2 = count_vowels(str2);
    int cons1 = count_consonants(str1);
    int cons2 = count_consonants(str2);

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
