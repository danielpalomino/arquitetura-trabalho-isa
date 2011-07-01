#include "mux2_5b.h"

void mux2_5b::compute() {
	if(sel.read() == SC_LOGIC_0) {
		s.write(a.read());
	}
	else {
		s.write(b.read());
	}
}
