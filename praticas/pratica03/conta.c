#include <stdlib.h>
#include "conta.h"

struct conta_t {
    int numero;
    float saldo;
};

Conta conta_criar(int numero, float saldo_inicial) {
    Conta c = (Conta) malloc(sizeof(struct conta_t));
    if (c != NULL) {
        c->numero = numero;
        c->saldo = saldo_inicial;
    }
    return c;
}

void conta_depositar(Conta c, float valor) {
    if (c != NULL && valor > 0) {
        c->saldo += valor;
    }
}

int conta_sacar(Conta c, float valor) {
    if (c != NULL && c->saldo >= valor) {
        c->saldo -= valor;
        return 1;
    }
    return 0;
}

float conta_ver_saldo(Conta c) {
    return (c != NULL) ? c->saldo : 0.0;
}

void conta_destruir(Conta c) {
    if (c != NULL) {
        free(c);
    }
}