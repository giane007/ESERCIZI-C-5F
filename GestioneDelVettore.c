/*
Scrivere un programma in C che effettui, attraverso un menù, le seguenti operazione sugli array:
1) Visualizzi a video gli elementi dell’array inseriti o generati casualmente;
2) Visualizzi a video l’array invertito, cioè, sostituendo il primo elemento con l’ultimo, il secondo con il
penultimo e così via;
3) Visualizzi a video la somma e media degli elementi del vettore;
4) Visualizzi a video tutti i numeri pari;
5) Visualizzi a video tutti i numeri dispari;
6) Ricerchi un numero (letto in input) nell’array;
7) Elimini un elemento (letto in input) dell’array (se esistente);
8) Alterni (o scambi) a due a due le posizioni del vettore: esempio
vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);
9) Ordini il vettore (ordinamento a scelta).
*/


#include <stdio.h>
#define MAX 100

void inserisciArray(int array[], int *n);
void stampaArray(int array[], int n);
void invertiArray(int array[], int n);
void sommaMedia(int array[], int n);
void numeriPari(int array[], int n);
void numeriDispari(int array[], int n);
void cercaElemento(int array[], int n, int val);
void eliminaElemento(int array[], int *n, int val);
void alternaCoppie(int array[], int n);
void ordinaArray(int array[], int n);

int main() {
    int array[MAX];
    int n = 0;
    int scelta, val;

    do {
        printf("\n--- MENU OPERAZIONI ARRAY ---\n");
        printf("1. Inserisci elementi dell'array\n");
        printf("2. Visualizza array\n");
        printf("3. Visualizza array invertito\n");
        printf("4. Somma e media degli elementi\n");
        printf("5. Visualizza numeri pari\n");
        printf("6. Visualizza numeri dispari\n");
        printf("7. Ricerca di un numero\n");
        printf("8. Elimina un elemento\n");
        printf("9. Alterna a due a due gli elementi\n");
        printf("10. Ordina array\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta) {
            case 1:
                inserisciArray(array, &n);
                break;
            case 2:
                stampaArray(array, n);
                break;
            case 3:
                invertiArray(array, n);
                break;
            case 4:
                sommaMedia(array, n);
                break;
            case 5:
                numeriPari(array, n);
                break;
            case 6:
                numeriDispari(array, n);
                break;
            case 7:
                printf("Inserisci numero da cercare: ");
                scanf("%d", &val);
                cercaElemento(array, n, val);
                break;
            case 8:
                printf("Inserisci numero da eliminare: ");
                scanf("%d", &val);
                eliminaElemento(array, &n, val);
                break;
            case 9:
                alternaCoppie(array, n);
                break;
            case 10:
                ordinaArray(array, n);
                break;
            case 0:
                printf("Programma terminato.\n");
                break;
            default:
                printf("Scelta non valida.\n");
        }
    } while(scelta != 0);

    return 0;
}

// 1. Inserimento manuale da tastiera
void inserisciArray(int array[], int *n) {
    printf("Quanti elementi vuoi inserire (max %d)? ", MAX);
    scanf("%d", n);
    if (*n > MAX || *n <= 0) {
        printf("Numero non valido.\n");
        return;
    }
    for (int i = 0; i < *n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

// 2. Visualizzazione array
void stampaArray(int array[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 3. Visualizzazione array invertito
void invertiArray(int array[], int n) {
    printf("Array invertito: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 4. Somma e media
void sommaMedia(int array[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += array[i];
    }
    float media = (float)somma / n;
    printf("Somma = %d, Media = %.2f\n", somma, media);
}

// 5. Visualizza numeri pari
void numeriPari(int array[], int n) {
    printf("Numeri pari: ");
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0)
            printf("%d ", array[i]);
    }
    printf("\n");
}

// 6. Visualizza numeri dispari
void numeriDispari(int array[], int n) {
    printf("Numeri dispari: ");
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 != 0)
            printf("%d ", array[i]);
    }
    printf("\n");
}

// 7. Ricerca di un numero
void cercaElemento(int array[], int n, int val) {
    int trovato = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == val) {
            printf("Elemento trovato alla posizione %d\n", i);
            trovato = 1;
        }
    }
    if (!trovato)
        printf("Elemento non trovato.\n");
}

// 8. Elimina un elemento (solo la prima occorrenza)
void eliminaElemento(int array[], int *n, int val) {
    int i, j, trovato = 0;
    for (i = 0; i < *n; i++) {
        if (array[i] == val) {
            trovato = 1;
            for (j = i; j < *n - 1; j++) {
                array[j] = array[j + 1];
            }
            (*n)--;
            printf("Elemento eliminato.\n");
            break;
        }
    }
    if (!trovato)
        printf("Elemento non trovato.\n");
}

// 9. Alterna a due a due
void alternaCoppie(int array[], int n) {
    for (int i = 0; i < n - 1; i += 2) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
    printf("Array dopo alternanza: ");
    stampaArray(array, n);
}

// 10. Ordinamento (Bubble Sort)
void ordinaArray(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Array ordinato: ");
    stampaArray(array, n);
}
