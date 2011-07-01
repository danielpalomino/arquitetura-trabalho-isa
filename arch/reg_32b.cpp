#include "reg_32b.h"

void reg_32b::compute() {
	pc_out.write(pc_in.read());
}

