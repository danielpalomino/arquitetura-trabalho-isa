#include "control_unit.h"

void control_unit::compute() {
	if(reset.read() == '1') {
		/* do reset operations */
	}
	else {
		switch(curr) {
			case s0: /* Instruction Fetch */
				
				break;
			case s1: /* Instruction Decode */
								
				break;
			case s2:

			default:

				break;
		}
			
	}
}

int decodeOpcode(sc_uint<6>) {
}


void control_unit::computeNextState() {
	switch(curr) {
		case s0:
			next = s1;
			break;
		case s1:	
			if(opcode.read() == R_TYPE) {
				next = s2; 
			}
			//TODO implement other possibilities		
			break;
		default:
			next = s0;

		curr = next;
	}
	 	
}
