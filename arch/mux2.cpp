#include "mux2.h"

void mux2::compute() {
	if(sel.read() == SC_LOGIC_0) {
		s.write(a.read());
	}
	else {
		s.write(b.read());
	}
}
