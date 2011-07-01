#include "systemc.h"

SC_MODULE(alu) {
	sc_in<sc_uint<6> > funct;
	sc_in<sc_uint<32> > op_a, op_b;
	sc_out<sc_uint<32> > alu_out;
	sc_out<sc_logic> z;

	void compute();

	SC_CTOR(alu) {
		SC_METHOD(compute);
		sensitive << funct << op_a << op_b;
	}


};
