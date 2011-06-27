int tabela[20];

void insere(int elem, int chave) {
	tabela[chave] = elem;
}

int recupera(int chave) {
	return tabela[chave];
}

int main(void) {
	int i,a;

	for(i=0; i<10; i++) {
		insere(i+10,i);
	}

	for(i=0; i<10; i++) {
		a=recupera(i);
	}
}
