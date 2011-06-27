NULL = 0x0;

struct nodo{
	struct nodo *esq, *dir;
};

void dfs(struct nodo *n) {
	if(n != NULL) {
		dfs(n->esq);
		dfs(n->dir);
	}	
}

int main(void) {
	struct nodo *n;

	dfs(n);
}

