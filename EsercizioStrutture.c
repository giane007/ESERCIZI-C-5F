#include <stdio.h>
#include <string.h>

#define MAX_AUTO 100

typedef struct {
    char modello[50];
    char marca[50];
    int cilindrata;
    float prezzo;
    int anno_immatricolazione;
    char targa[15];
} Auto;

void trovaPrezzoEstremo(Auto autoList[], int n) {
    if (n == 0) {
        printf("Nessuna auto inserita.\n");
        return;
    }
    float maxPrezzo = autoList[0].prezzo;
    float minPrezzo = autoList[0].prezzo;
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (autoList[i].prezzo > maxPrezzo) {
            maxPrezzo = autoList[i].prezzo;
            maxIndex = i;
        }
        if (autoList[i].prezzo < minPrezzo) {
            minPrezzo = autoList[i].prezzo;
            minIndex = i;
        }
    }
    printf("Prezzo massimo: %.2f, Modello: %s\n", maxPrezzo, autoList[maxIndex].modello);
    printf("Prezzo minimo: %.2f, Modello: %s\n", minPrezzo, autoList[minIndex].modello);
}

void ordinaPerAnno(Auto autoList[], int n) {
    Auto temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (autoList[i].anno_immatricolazione > autoList[j].anno_immatricolazione) {
                temp = autoList[i];
                autoList[i] = autoList[j];
                autoList[j] = temp;
            }
        }
    }
}

void visualizzaAutoDaPrezzo(Auto autoList[], int n, float prezzoMin) {
    int trovate = 0;
    printf("Auto con prezzo >= %.2f:\n", prezzoMin);
    for (int i = 0; i < n; i++) {
        if (autoList[i].prezzo >= prezzoMin) {
            printf("Modello: %s\n", autoList[i].modello);
            trovate = 1;
        }
    }
    if (!trovate) {
        printf("Nessuna auto trovata con prezzo >= %.2f\n", prezzoMin);
    }
}

void ricercaAutoPerTarga(Auto autoList[], int n, char targa[]) {
    int trovata = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(autoList[i].targa, targa) == 0) {
            printf("Auto trovata:\n");
            printf("Modello: %s\n", autoList[i].modello);
            printf("Marca: %s\n", autoList[i].marca);
            printf("Cilindrata: %d\n", autoList[i].cilindrata);
            printf("Prezzo: %.2f\n", autoList[i].prezzo);
            printf("Anno immatricolazione: %d\n", autoList[i].anno_immatricolazione);
            printf("Targa: %s\n", autoList[i].targa);
            trovata = 1;
            break;
        }
    }
    if (!trovata) {
        printf("Auto con targa %s non trovata.\n", targa);
    }
}

void mediaPrezzi(Auto autoList[], int n) {
    if (n == 0) {
        printf("Nessuna auto inserita.\n");
        return;
    }
    float somma = 0;
    for (int i = 0; i < n; i++) {
        somma += autoList[i].prezzo;
    }
    printf("Prezzo medio delle auto: %.2f\n", somma / n);
}

void visualizzaAutoPerAnno(Auto autoList[], int n, int anno) {
    int trovate = 0;
    printf("Auto immatricolate nell'anno %d:\n", anno);
    for (int i = 0; i < n; i++) {
        if (autoList[i].anno_immatricolazione == anno) {
            printf("Modello: %s, Marca: %s, Targa: %s, Prezzo: %.2f, Cilindrata: %d\n",
                   autoList[i].modello, autoList[i].marca, autoList[i].targa, autoList[i].prezzo, autoList[i].cilindrata);
            trovate = 1;
        }
    }
    if (!trovate) {
        printf("Nessuna auto trovata per l'anno %d.\n", anno);
    }
}

int main() {
    Auto autoList[MAX_AUTO];
    int n;

    printf("Quante auto vuoi inserire? ");
    scanf("%d", &n);
    getchar(); // pulire buffer

    for (int i = 0; i < n; i++) {
        printf("Inserisci i dati dell'auto %d:\n", i+1);
        printf("Modello: ");
        fgets(autoList[i].modello, sizeof(autoList[i].modello), stdin);
        autoList[i].modello[strcspn(autoList[i].modello, "\n")] = 0; // rimuovere newline

        printf("Marca: ");
        fgets(autoList[i].marca, sizeof(autoList[i].marca), stdin);
        autoList[i].marca[strcspn(autoList[i].marca, "\n")] = 0;

        printf("Cilindrata: ");
        scanf("%d", &autoList[i].cilindrata);

        printf("Prezzo: ");
        scanf("%f", &autoList[i].prezzo);

        printf("Anno immatricolazione: ");
        scanf("%d", &autoList[i].anno_immatricolazione);
        getchar();

        printf("Targa: ");
        fgets(autoList[i].targa, sizeof(autoList[i].targa), stdin);
        autoList[i].targa[strcspn(autoList[i].targa, "\n")] = 0;

        printf("\n");
    }

    // 1) Prezzo massimo e minimo
    trovaPrezzoEstremo(autoList, n);

    // 2) Ordinare per anno
    ordinaPerAnno(autoList, n);
    printf("\nLista auto ordinata per anno di immatricolazione:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s (%d)\n", i+1, autoList[i].modello, autoList[i].anno_immatricolazione);
    }

    // 3) Visualizza auto da prezzo minimo scelto
    float prezzoMin;
    printf("\nInserisci un prezzo minimo per filtrare le auto: ");
    scanf("%f", &prezzoMin);
    visualizzaAutoDaPrezzo(autoList, n, prezzoMin);

    // 4) Ricerca auto per targa
    char targaRicerca[15];
    getchar(); // pulire buffer
    printf("\nInserisci la targa dell'auto da cercare: ");
    fgets(targaRicerca, sizeof(targaRicerca), stdin);
    targaRicerca[strcspn(targaRicerca, "\n")] = 0;
    ricercaAutoPerTarga(autoList, n, targaRicerca);

    // 5) Media prezzi
    mediaPrezzi(autoList, n);

    // 6) Visualizza auto per anno scelto
    int annoScelto;
    printf("\nInserisci un anno per visualizzare le auto immatricolate in quell'anno: ");
    scanf("%d", &annoScelto);
    visualizzaAutoPerAnno(autoList, n, annoScelto);

    return 0;
}
