#include "systemc.h"

/* CONTROL STATE MACHINE STATES */
#define s0 0
#define s1 1
#define s2 2
#define s3 3
#define s4 4
#define s5 5
#define s6 6
#define s7 7

SC_MODULE(control_unit) {
	sc_in<sc_logic> clk, reset;
	sc_in<sc_uint<6> > opcode;
	//TODO declare output control signals
	

	void compute();
	void computeNextState();

	sc_signal<int> curr, next;

	SC_CTOR(control_unit) {
		SC_METHOD(compute);
		sensitive << curr;

		SC_METHOD(computeNextState);
		sensitive << clk.pos() << reset;
	}
};

