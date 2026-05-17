#include "standard_c.h"
#include "prototipi.h"

// corpo della funzione per la somma
int somma(int op1, int op2){
    int risultato;

    risultato = op1 + op2;

    return risultato;
}

// corpo della funzione per la sottrazione
int sottrazione(int op1, int op2){
    int risultato;

    risultato = op1 - op2;

    return risultato;
}

// corpo della funzione per la moltiplicazione
int moltiplicazione(int op1, int op2){
    int risultato;

    risultato = op1 * op2;

    return risultato;
}

// corpo della funzione per la divisione
float divisione(float div1, float div2){
    float risultato;

    risultato = div1 / div2;

    return risultato;
}

// corpo della funzione per la radice quadrata
float radice_quadrata(float div1){
    float risultato;

    risultato = sqrt(div1);

    return risultato;
}