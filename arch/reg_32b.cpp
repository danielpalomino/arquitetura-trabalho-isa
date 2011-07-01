#include "reg_32b.h"

void reg_32b:: reset() {
	if(rst.read() == 1)
		q.write(0);
}

void reg_32b::compute() {
	if(enable.read() == 1)
		q.write(d.read());
}

