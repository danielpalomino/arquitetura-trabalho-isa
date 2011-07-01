#include "systemc.h"

SC_MODULE(decode) {
	sc_in<sc_uint<32> > word;
	sc_out<sc_uint<6> > opcode, funct;
	sc_out<sc_uint<5> > rs, rt, rd, shamt;

	void compute();

	SC_CTOR(decode) {
		SC_METHOD(compute);
		sensitive << word;
	}
};

