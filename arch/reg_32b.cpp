#include "reg_32b.h"

void reg_32b:: reset() {
	if(rst.read() == 1)
		pc_out.write(0);
}

void reg_32b::compute() {
	pc_out.write(pc_in.read());
}

