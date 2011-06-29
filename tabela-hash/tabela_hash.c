#include "noclib.h"

int tabela[32];

void insere(int elem, int chave) {
	tabela[chave%32] = elem;
}

int recupera(int chave) {
	return tabela[chave%32];
}

int main(void) {

	insere(1,1);
	insere(2,2);
	insere(3,3);
	insere(4,4);

	memstore( MAPPED_OUTPUT0, recupera(1) );
	memstore( MAPPED_OUTPUT1, recupera(2) );
	memstore( MAPPED_OUTPUT2, recupera(3) );
	memstore( MAPPED_OUTPUT3, recupera(4) );

}
