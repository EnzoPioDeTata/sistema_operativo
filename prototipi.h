// definizione struttura File
typedef struct File{
    char data[100];
    char nome[100];
    char contenuto[100];
    bool esiste;
}fil;

// prototipi di funzione del sistema operativo
void mostra_file(fil files[]);
void crea_file(fil files[]);
void elimina_file(fil files[]);
void elenco_comandi();
void scelta_comando(char comando[], fil files[]);
void pulisci_comando(char comando[]);
void data_orario();

// prototipi di funzione della calcolatrice
int somma(int op1, int op2);
int sottrazione(int op1, int op2);
int moltiplicazione(int op1, int op2);
float divisione(float div1, float div2);
float radice_quadrata(float div1);

// prototipo di funzione per il gioco
void gioco();