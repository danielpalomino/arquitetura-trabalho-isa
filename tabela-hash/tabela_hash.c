#include "noclib.h"
#define NULL 0

int keys[30] = {
1804289383,
846930886,
1681692777,
1714636915,
1957747793,
424238335,
719885386,
1649760492,
596516649,
1189641421,
1025202362,
1350490027,
783368690,
1102520059,
2044897763,
1967513926,
1365180540,
1540383426,
304089172,
1303455736,
35005211,
521595368,
294702567,
1726956429,
336465782,
861021530,
278722862,
233665123,
2145174067,
468703135
};

struct nodo {
	int	chave, elem;
	struct nodo *prox;
};

struct nodo *tabela[16] = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

struct nodo dados[30];

struct nodo *n;
int fm=0, dado;
int a,b,c,d;
int acum;
int flag;

int hash(int key) {
	a = (key & 0x000000FF) >> 0;
	b = (key & 0x0000FF00) >> 8;
	c = (key & 0x00FF0000) >> 16;
	d = (key & 0xFF000000) >> 24;
	acum = 0;

	acum += a * b;
	acum += b * c;
	acum += (c * d);
	acum = acum %16;

	return acum;
}

void insere(int chave, int elem) {

	acum = hash(chave);
	n = tabela[acum];
	flag = 1;

	if(n == NULL) {
		flag = 0;
	}
	else {
		while(n->chave != chave) {
			n = n->prox;
			if(n == NULL) {
				flag = 0;
				break;
			}
		}
	}

	if(flag == 0) {
		dados[fm].chave = chave;
		dados[fm].elem = elem;
		dados[fm].prox = tabela[acum];
		tabela[acum] = &dados[fm];
		fm ++;
	}
}

int recupera(int chave) {
	flag = 1;
	acum = hash(chave);
	n = tabela[acum];

	if(n == NULL) {
		flag = 0;
	}
	else {
		while(n->chave != chave) {
			if(n->prox == NULL) {
				flag = 0;
				break;
			}
			n = n->prox;
		}
	}

	return flag == 0 ? 0xFFFFFFFF : n->elem;
}

int main(void) {
	

	int i;

	memstore( MAPPED_OUTPUT0, 10 );
	for(i=0; i<30; i++) {
		insere(keys[i],i);
	}
	for(i=0; i<30; i++) {
		dado = recupera(keys[i]);
	}
	memstore( MAPPED_OUTPUT0, 20 );

}
