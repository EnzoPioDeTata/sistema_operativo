#include "standard_c.h"
#include "prototipi.h"
#define MAX_FILE 2

// funzione principale
int main(){
    // dichiarazione variabili
    int i;
    char comando[100];
    fil files[MAX_FILE];
    
    // inizializzazione array di tipo struct File
    for(i = 0; i < MAX_FILE; i++){
        files[i].data[0] = '\0';
        files[i].nome[0] = '\0';
        files[i].contenuto[0] = '\0';
        files[i].esiste = 0;
    }

    printf("VirtualC OS - v1.0\n");
    printf("\n--- \033[1;36mBenvenuti su VirtualC OS\033[0m ---\n\n");
    printf("Digita '\033[33mhelp\033[0m' per visualizzare l'elenco dei comandi\n");

    // ciclo infinito per visualizzare il prompt del sistema operativo
    while(1){
        printf("\033[36mVirtualC OS> \033[0m");
        if(fgets(comando, 100, stdin) == NULL){
            printf("\033[31mErrore input. Uscita\033[0m\n");
            break;
        }

        pulisci_comando(comando);

        // gestione caso uscita
        if(strcmp(comando, "exit") == 0){
            printf("Uscita dal sistema in corso...\n");
            printf("\033[92mLoagout avvenuto con successo!\033[0m\n");
            return 0;
        }
        
        scelta_comando(comando, files);
    }
}
