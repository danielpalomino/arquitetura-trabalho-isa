#define NULL 0x0
#include "noclib.h"

struct nodo{
	int dado;
	struct nodo *esq, *dir;
};

struct nodo n1;
struct nodo n2;
struct nodo n3;
struct nodo n4;
struct nodo n5;
struct nodo n6;
struct nodo n7;

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
	
	n2.esq = &n4;
	n2.dir = &n5;

	n3.esq = &n6;
	n3.dir = &n7;
	
	n4.esq = NULL;
	n4.dir = NULL;

	n5.esq = NULL;
	n5.dir = NULL;

	n6.esq = NULL;
	n6.dir = NULL;

	n7.esq = NULL;
	n7.dir = NULL;

	memstore(MAPPED_OUTPUT0, 10);
	dfs(n);
	memstore(MAPPED_OUTPUT0, 20);
}

