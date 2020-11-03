#include <iostream>
#include <queue>

class No {
public:
    int valor;
    No* esq;
    No* dir;
};

class Arvore {
public:
    No* raiz;
};

int somaFolhas(No* no) {
    if(!no) {
        return 0;
    }
    
    if(!no->esq && !no->dir) {
        return no->valor;
    }

    return somaFolhas(no->esq) + somaFolhas(no->dir);
}

int somaFolhas(Arvore* arvore) {
    return somaFolhas(arvore->raiz);
}

void percursoPreOrdem(No* no) {
    if(!no) {
        return;
    }

    printf("%d\n", no->valor);

    percursoPreOrdem(no->esq);
    percursoPreOrdem(no->dir);
}

void percursoPreOrdem(Arvore* arvore) {
    percursoPreOrdem(arvore->raiz);
}

void percursoEmOrdem(No* no) {
    if(!no) {
        return;
    }

    percursoEmOrdem(no->esq);

    printf("%d\n", no->valor);
    
    percursoEmOrdem(no->dir);
}

void percursoEmOrdem(Arvore* arvore) {
    percursoEmOrdem(arvore->raiz);
}

void percursoPosOrdem(No* no) {
    if(!no) {
        return;
    }

    percursoPosOrdem(no->esq);
    percursoPosOrdem(no->dir);

    printf("%d\n", no->valor);
}

void percursoPosOrdem(Arvore* arvore) {
    percursoPosOrdem(arvore->raiz);
}

int calcularAlturaNo(No* no) {
    if(!no) {
        return 0;
    }

    int alturaSubArvEsq = calcularAlturaNo(no->esq);
    int alturaSubArvDir = calcularAlturaNo(no->dir);
    return (alturaSubArvEsq > alturaSubArvDir ? alturaSubArvEsq : alturaSubArvDir) + 1;
}

int calcularFatorBalanceamento(No* no) {
    if(!no) {
        return 0;
    }

    return calcularAlturaNo(no->esq) - calcularAlturaNo(no->dir);
}

void percorrerEmNiveis(Arvore* arvore) {
    std::queue<No*> fila = std::queue<No*>{};
    fila.push(arvore->raiz);

    while(!fila.empty()) {
        No* topo = fila.front();
        fila.pop();

        if(!topo) {
            continue;
        } 

        printf("%d\n", topo->valor);

        if(topo->esq) {
            fila.push(topo->esq);
        }

        if(topo->dir) {
            fila.push(topo->dir);
        }
    }
}

int produtoNos(No* no) {
    if(!no) {
        return 1;
    }

    return no->valor * produtoNos(no->esq) * produtoNos(no->dir);
}

int produtoNos(Arvore* arvore) {
    return produtoNos(arvore->raiz);
}

int main() {
    Arvore arvore;
    auto* no2 = new No{.valor = 2};
    auto* no1 = new No{.valor = 1};
    auto* no4 = new No{.valor = 4, .esq = no1, .dir = no2};
    auto* no7 = new No{.valor = 7};
    auto* no10 = new No{.valor = 10, .esq = no4, .dir = no7};
    auto* no8 = new No{.valor = 8};
    auto* no3 = new No{.valor = 3,};
    auto* no15 = new No{.valor = 15, .esq = no8, .dir = no3};
    auto* no20 = new No{.valor = 20, .esq = no10, .dir = no15};
    arvore.raiz = no20;

    //printf("%d", somaFolhas(&arvore));
    percorrerEmNiveis(&arvore);
}