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
//CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>

#define SERVERPORT 1450
#define DIM 100

int main(){
    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    int socketfd,opzione;
    char stringa[DIM];

    if((socketfd = socket(AF_INET,SOCK_STREAM,0))== -1){
        printf("Te ghÃ¨ sbaiÃ el socket");
        exit(1);
    }

    if(connect (socketfd,(struct sockaddr*)&servizio, sizeof(servizio))== -1){
        printf("Te ghÃ¨ sbaia il connect");
        exit(1);
    }

    printf("Inserisci la stringa redi ");
    fgets(stringa,DIM,stdin);

    printf("Inserisci l'opzione: ");
    scanf("%d", &opzione);

    write(socketfd,stringa,sizeof(stringa));
    write(socketfd,&opzione,sizeof(opzione));

    read(socketfd,stringa,sizeof(stringa));

    printf("%s",stringa);

    close(socketfd);
    return 0;
}
