#include "stack.h"

void stack::initialize() {
	sp.write(0);
	stack_full.write(0);
	stack_empty.write(1);
}

void stack::push() {
	if(sp.read() < stackSIZE) {
		sp.write(sp.read()+1);
		pilha[sp.read()].write(data_in.read());
		if(sp.read() < stackSIZE)
			stack_full.write(0);
		else
			stack_full.write(1);
	}
	else
		stack_full.write(1);
}

void stack::pop() {
	if(sp.read() > 0) {
		data_out.write(pilha[sp.read()].read());
		sp.write(sp.read()-1);
		if(sp.read() > 0)
			stack_empty.write(0);
		else
			stack_empty.write(1);
	}
	else
		stack_empty.write(1);
}

