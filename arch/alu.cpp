#include "alu.h"

#define ADD 0x20
#define SUB 0x22

void alu::compute() {
	switch(funct.read()) {
		case ADD:
			alu_out.write(op_a.read() + op_b.read());
			break;
		case SUB:
			alu_out.write(op_a.read() - op_b.read());
			if( alu_out.read() == 0 ) {
				z.write(SC_LOGIC_0);
			}
			break;
	}
}

