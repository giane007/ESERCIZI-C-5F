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
#include <ctype.h>

#define MAX_LEN 100

int isOnlyLetters(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (!isalpha(str[i])) return 0;
    }
    return 1;
}

int countLetter(char str[], char ch) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (tolower(str[i]) == tolower(ch)) count++;
    }
    return count;
}

void splitEvenOddPositions(char str[], char even[], char odd[]) {
    int e = 0, o = 0;
    for (int i = 0; str[i]; i++) {
        if (i % 2 == 0) even[e++] = str[i];
        else odd[o++] = str[i];
    }
    even[e] = '\0';
    odd[o] = '\0';
}

int hasDoubleLetters(char str[]) {
    for (int i = 0; str[i+1]; i++) {
        if (tolower(str[i]) == tolower(str[i+1])) return 1;
    }
    return 0;
}

int countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count++;
    }
    return count;
}

int countConsonants(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) count++;
    }
    return count;
}

void commonLetters(char str1[], char str2[]) {
    int found[26] = {0};
    printf("Lettere comuni: ");
    for (int i = 0; str1[i]; i++) {
        char ch1 = tolower(str1[i]);
        if (!isalpha(ch1)) continue;
        for (int j = 0; str2[j]; j++) {
            char ch2 = tolower(str2[j]);
            if (ch1 == ch2 && !found[ch1 - 'a']) {
                printf("%c ", ch1);
                found[ch1 - 'a'] = 1;
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    char letter;
    char even[MAX_LEN], odd[MAX_LEN];

    printf("Inserisci la prima stringa (solo lettere): ");
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Rimuove il newline

    if (!isOnlyLetters(str1)) {
        printf("Errore: La stringa deve contenere solo lettere!\n");
        return 1;
    }

    printf("Inserisci la lettera da contare: ");
    scanf(" %c", &letter);

    int count = countLetter(str1, letter);
    printf("La lettera '%c' compare %d volte.\n", letter, count);

    splitEvenOddPositions(str1, even, odd);
    printf("Lettere in posizioni pari: %s\n", even);
    printf("Lettere in posizioni dispari: %s\n", odd);

    if (hasDoubleLetters(str1))
        printf("La stringa contiene doppie.\n");
    else
        printf("La stringa NON contiene doppie.\n");

    // Pulisce il buffer prima del nuovo input
    while (getchar() != '\n');

    printf("\nInserisci la seconda stringa: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // Confronto lunghezze
    if (strlen(str1) > strlen(str2))
        printf("La prima stringa è più lunga.\n");
    else if (strlen(str1) < strlen(str2))
        printf("La seconda stringa è più lunga.\n");
    else
        printf("Le due stringhe hanno la stessa lunghezza.\n");

    // Lettere comuni
    commonLetters(str1, str2);

    // Vocali
    int v1 = countVowels(str1);
    int v2 = countVowels(str2);
    printf("Vocali: prima stringa = %d, seconda stringa = %d\n", v1, v2);
    if (v1 > v2)
        printf("La prima stringa ha più vocali.\n");
    else if (v1 < v2)
        printf("La seconda stringa ha più vocali.\n");
    else
        printf("Le due stringhe hanno lo stesso numero di vocali.\n");

    // Consonanti
    int c1 = countConsonants(str1);
    int c2 = countConsonants(str2);
    printf("Consonanti: prima stringa = %d, seconda stringa = %d\n", c1, c2);
    if (c1 > c2)
        printf("La prima stringa ha più consonanti.\n");
    else if (c1 < c2)
        printf("La seconda stringa ha più consonanti.\n");
    else
        printf("Le due stringhe hanno lo stesso numero di consonanti.\n");

    return 0;
}
