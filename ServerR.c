/*
  Scrivere il codice in C di unâ€™applicazione socket CLIENTâ€“SERVER.
  Il client invia al server una stringa e un codice di operazione (0, 1, 2, 3).
  Il server, in base al codice ricevuto, elabora la stringa e restituisce:

  Operazioni

  0 â†’ Convertire la stringa in MAIUSCOLO

  1 â†’ Restituire la lunghezza della stringa (numero di caratteri)

  2 â†’ Contare il numero di cifre (0â€“9) presenti nella stringa

  3 â†’ Restituire la stringa con gli spazi sostituiti da '_' (underscore)
*/
//SERVER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define SERVERPORT 1450
#define DIM 100

void Conversione(char stringa[]){
    for(int i=0;i<strlen(stringa);i++){
        stringa[i] = toupper(stringa[i]);
    }
}

int LunghezzaStr(char stringa[]){
    return sizeof(stringa);
}

int NCifre(char stringa[]){
    int num = 0;
    for(int i=0;i<strlen(stringa);i++){
        if(isdigit(stringa[i])){
            num++;
        }
    }
    return num;
}

void StringaDown(char stringa[]){
    for(int i=0;i<strlen(stringa);i++){
        if(stringa[i] == ' '){
            stringa[i] = '_';
        }
    }
}

int main(){
    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    int socketfd,soa,opzione,fromlen = sizeof(servizio);
    char stringa[DIM];

    if((socketfd = socket(AF_INET,SOCK_STREAM,0))== -1){
        printf("Te ghÃ¨ sbaiÃ el socket");
        exit(1);
    }

    if(bind (socketfd,(struct sockaddr*)&servizio, sizeof(servizio))== -1){
        printf("Te ghÃ¨ sbaia il bind");
        exit(1);
    }

    if(listen (socketfd,10)==-1){
        printf("Te ghÃ¨ sbaia il listen");
        exit(1);
    }
    
    for(;;){
        printf("Server in ascolto");

        if((soa = accept(socketfd,(struct sockaddr*)&servizio,&fromlen))== -1){
            printf("Te ghe sbaia accept");
            exit(1);
        }

        read(soa,stringa,sizeof(stringa));
        read(soa,&opzione,sizeof(opzione));

        switch(opzione){
            case 0:
                Conversione(stringa);
            break;


            case 1:
                sprintf(stringa,"Lunghezza del chilichetto: %d",LunghezzaStr(stringa));
            break;


            case 2:
                sprintf(stringa,"Numero di cifre : %d",NCifre(stringa));
            break;


            case 3:
                StringaDown(stringa);
            break;

            default:
                printf("Bravo coion");
            break;
        }

        write(soa,stringa,sizeof(stringa));
        close (soa);
    }
    return 0;

}

