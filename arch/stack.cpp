#include "stack.h"

void stack::initialize() {
	pc.write(0);
	stack_full.write(0);
	stack_empty.write(1);
}

void stack::push() {
	if(pc.read() < stackSIZE) {
		pc.write(pc.read()+1);
		pilha[pc.read()].write(data_in.read());
		if(pc.read() < stackSIZE)
			stack_full.write(0);
		else
			stack_full.write(1);
	}
	else
		stack_full.write(1);
}

void stack::pop() {
	if(pc.read() > 0) {
		data_out.write(pilha[pc.read()].read());
		pc.write(pc.read()-1);
		if(pc.read() > 0)
			stack_empty.write(0);
		else
			stack_empty.write(1);
	}
	else
		stack_empty.write(1);
}

