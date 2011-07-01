#include "systemc.h"

SC_MODULE(demux4x2) {
	sc_in<sc_uint<32> > a0, a1, b0, b1;
	sc_in<sc_logic> sel;

	sc_out<sc_uint<32> > s0, s1;

	void compute();

	SC_CTOR(demux4x2) {
		SC_METHOD(compute);
		sensitive << a0 << a1 << b0 << b1 << sel;
	}
};

