#define NULL 0x0

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
		
	n2.esq = &n4;
	n2.dir = &n5;

	n3.esq = &n6;
	n3.dir = &n7;
	
	n4.esq = &n8;
	n4.dir = &n9;

	n5.esq = &n10;
	n5.dir = &n11;

	n6.esq = &n12;
	n6.dir = &n13;

	n7.esq = &n14;
	n7.dir = &n15;
	
	n8.esq = NULL;
	n8.dir = NULL;

	n9.esq = NULL;
	n9.dir = NULL;

	n10.esq = NULL;
	n10.dir = NULL;

	n11.esq = NULL;
	n11.dir = NULL;

	n12.esq = NULL;
	n12.dir = NULL;

	n13.esq = NULL;
	n13.dir = NULL;

	n14.esq = NULL;
	n14.dir = NULL;

	n15.esq = NULL;
	n15.dir = NULL;

	dfs(n);
}

