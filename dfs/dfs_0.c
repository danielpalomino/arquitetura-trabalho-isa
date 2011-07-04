#define NULL 0x0
#include "noclib.h"

struct nodo{
	int dado;
	struct nodo *esq, *dir;
};

struct nodo n1;
struct nodo n2;
struct nodo n3;

void dfs(struct nodo *n) {
	if(n != NULL) {
		dfs(n->esq);
		dfs(n->dir);
	}	
}

int main(void) {
	struct nodo *n = &n1;
	n1.esq = &n2;
	n1.dir = &n3;

	n2.esq = NULL;
	n2.dir = NULL;

	n3.esq = NULL;
	n3.dir = NULL;


	memstore(MAPPED_OUTPUT0, 10);

	dfs(n);
	
	memstore(MAPPED_OUTPUT0, 20);
}

