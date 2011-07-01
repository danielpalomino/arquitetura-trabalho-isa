#include "demux4x2.h"

void demux4x2::compute() {
	if(sel.read() == 0) {
		s0.write(a0.read());
		s1.write(b0.read());
	} else {
		s0.write(a1.read());
		s1.write(b1.read());
	}
}

