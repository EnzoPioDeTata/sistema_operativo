#include "standard_c.h"
#include "prototipi.h"
#define MAX_FILE 2

// corpo della funzione per visualizzare i file salvati
void mostra_file(fil files[]){
    int i, cont;

    cont = 0;

    for(i = 0; i < MAX_FILE; i++){
        if(files[i].esiste == 1){
            cont++;
        }
    }

    if(cont == 0){
        printf("Non e\' stato salvato nessun file\n");
        return;
    }
    
    for(i = 0; i < MAX_FILE; i++){
        if(files[i].esiste == 1){
            printf("\033[32mData: \033[0m%s\n", files[i].data);
            printf("\033[32mNome: \033[0m%s\n", files[i].nome);
            printf("\033[32mContenuto: \033[0m%s\n\n", files[i].contenuto);
        }
    }
}

// corpo della funzione per salvare dei file
void crea_file(fil files[]){
    int i;

    for(i = 0; i < MAX_FILE; i++){
        if(files[i].esiste == false){
            printf("Inserisci la data:\n");
            fgets(files[i].data, 100, stdin);
            files[i].data[strcspn(files[i].data, "\n")] = '\0';

            printf("Inserisci il nome del file:\n");
            fgets(files[i].nome, 100, stdin);
            files[i].nome[strcspn(files[i].nome, "\n")] = '\0';

            printf("Inserisci il contenuto del file:\n");
            fgets(files[i].contenuto, 100, stdin);
            files[i].contenuto[strcspn(files[i].contenuto, "\n")] = '\0';
            
            files[i].esiste = true;
            
            printf("\033[92mFile '%s' creato con successo!\033[0m\n", files[i].nome);

            return;
        }
    }

    printf("\033[33mMemoria piena!\033[0m\n");
}

// corpo della funzione per eliminare i file salvati
void elimina_file(fil files[]){
    int i;
    char elimina[100];

    printf("Inserisci il nome del file che desideri eliminare:\n");
    fgets(elimina, 100, stdin);
    elimina[strcspn(elimina, "\n")] = '\0';

    for(i = 0; i < MAX_FILE; i++){
        if(strcmp(files[i].nome, elimina) == 0){
            files[i].data[0] = '\0';
            files[i].contenuto[0] = '\0';
            files[i].esiste = false;
            printf("\033[92mFile '%s' eliminato con successo!\033[0m\n", files[i].nome);
            files[i].nome[0] = '\0';
            return;
        }
    }

    printf("\033[33mFile '%s' non trovato\033[0m\n", elimina);
}

// corpo della funzione per visualizzare la data e l'orario
void data_orario(){
    time_t ora;

    setenv("TZ", "Europe/Rome", 1);     // imposta fuso orario
    tzset();

    ora = time(NULL);

    char buffer[100];

    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", localtime(&ora));

    printf("%s\n", buffer);
}

// corpo della funzione per visualizzare l'elenco dei comandi del sistema operativo
void elenco_comandi(){
    printf("\033[33mhelp - mostra l'elenco dei comandi\n");
    printf("mf - mostra i file\n");
    printf("cf - crea i file\n");
    printf("df - elimina i file\n");
    printf("tp - mostra l'orario e la data\n");
    printf("calc - apre la calcolatrice\n");
    printf("game - avvia Indovina il Numero\n");
    printf("clear - pulisci schermo\n");
    printf("exit - chiusura del sistema\033[0m\n");
}

// corpo della funzione per inizializzare la variabile 'comando'
void pulisci_comando(char comando[]){
    comando[strcspn(comando, "\n")] = '\0';
}

// corpo della funzione della gestione dei comandi da eseguire
void scelta_comando(char comando[], fil files[]){
    if(comando[0] == '\0') return;

    if(strcmp(comando, "help") == 0) elenco_comandi();
    else if(strcmp(comando, "mf") == 0) mostra_file(files);
    else if(strcmp(comando, "cf") == 0) crea_file(files);
    else if(strcmp(comando, "df") == 0) elimina_file(files);
    else if(strcmp(comando, "tp") == 0) data_orario();
    else if(strcmp(comando, "calc") == 0){
        int op1, op2, ris_int, operazione;
        float div1, div2, ris_float;

        // ciclo infinito per la calcolatrice
        while(1){
            printf("Scegli una delle seguenti operazioni:\n");
            printf("1. Somma\n");
            printf("2. Sottrazione\n");
            printf("3. Moltiplicazione\n");
            printf("4. Divisione\n");
            printf("5. Radice quadrata\n");
            printf("6. Esci\n");
            scanf(" %d", &operazione);

            // gestione caso uscita dalla calcolatrice
            if(operazione == 6) break;

            switch(operazione){
                case 1:
                    printf("Inserisci il primo operando\n");
                    scanf("%d", &op1);

                    printf("Inserisci il secondo operando\n");
                    scanf("%d", &op2);

                    ris_int = somma(op1, op2);

                    printf("%d + %d = %d\n", op1, op2, ris_int);

                    break;
                case 2:
                    printf("Inserisci il primo operando\n");
                    scanf("%d", &op1);

                    printf("Inserisci il secondo operando\n");
                    scanf("%d", &op2);

                    ris_int = sottrazione(op1, op2);

                    printf("%d - %d = %d\n", op1, op2, ris_int);
                    
                    break;
                case 3:
                    printf("Inserisci il primo operando\n");
                    scanf("%d", &op1);

                    printf("Inserisci il secondo operando\n");
                    scanf("%d", &op2);

                    ris_int = moltiplicazione(op1, op2);

                    printf("%d * %d = %d\n", op1, op2, ris_int);

                    break;
                case 4:
                    printf("Inserisci il dividendo\n");
                    scanf("%f", &div1);

                    printf("Inserisci il divisore\n");
                    scanf("%f", &div2);

                    // gestione divisione per zero
                    if(div2 == 0){
                        printf("\033[33mErrore divisione per zero\033[0m\n");
                        printf("%.2f / %.2f = valore indefinito\n", div1, div2);
                        break;
                    }

                    ris_float = divisione(div1, div2);

                    printf("%.2f / %.2f = %.2f\n", div1, div2, ris_float);

                    break;
                case 5:
                    printf("Inserisci il numero di cui vuoi conoscere la sua radice\n");
                    scanf("%f", &div1);

                    ris_float = radice_quadrata(div1);

                    printf("La radice quadrata di %.2f e\' %.2f\n", div1, ris_float);

                    break;
                default:
                    printf("\033[31mComando non riconosciuto. Riprova!\033[0m\n");
            }
        }

        // pulizia del buffer
        int c;
        while((c = getchar()) != '\n' && c != EOF);     // EOF indica che non c'è più input da leggere
        // EOF ritorna -1 nella funzione getchar()
    }
    else if(strcmp(comando, "game") == 0) gioco();
    else if(strcmp(comando, "clear") == 0){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    else printf("\033[31mInput non definito. Riprova\033[0m\n");
}