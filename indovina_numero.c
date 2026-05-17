#include "standard_c.h"
#include "prototipi.h"
#define TENTATIVI 5

void gioco(){
    int i, numero, tentativo, min, max;

    // inizializzazione funzione rand()
    srand(time(NULL));

    // generatore dell'intervallo minimo e massimo
    min = rand() % 50 + 1;
    max = min + (rand() % 100 + 10);

    // generatore nel numero da indovinare
    numero = rand() % (max - min + 1) + min;

    printf("--- \033[3m\033[91mBenvenuti a Indovina il Numero!\033[0m ---\n");
    printf("Ho pensato ad un numero tra %d e %d\n", min, max);
    printf("Hai %d tentativi\n", TENTATIVI);

    for(i = 0; i < TENTATIVI; i++){
        printf("Tentativo numero %d: ", i + 1);
        if(scanf("%d", &tentativo) != 1){
            printf("\033[31mInput non valido. Riprova!\033[0m\n");
            while(getchar() != '\n');
            i--; // annulla il tentativo
            continue;
        }

        if(tentativo < numero){
            printf("Numero troppo basso\n");
        }else if(tentativo > numero){
            printf("Numero troppo alto\n");
        }else if(tentativo == numero){
            printf("\033[92mHai indovinato il numero, complimenti!\033[0m\n");
            break;
        }
    }

    if(i == TENTATIVI){
        printf("\033[33mHai terminato i tentativi, il numero pensato era %d\033[0m\n", numero);
    }

    // pulizia del buffer
        int c;
        while((c = getchar()) != '\n' && c != EOF);     // EOF indica che non c'è più input da leggere
        // EOF ritorna -1 nella funzione getchar()
}