#include "mac.h"

void mac::compute() {
	mult0.input0(input0);
	mult0.input1(input1);
	mult0.output(out_mult);

	adder0.a(input_reg);
	adder0.b(out_mult);
	adder0.s(output);
}

