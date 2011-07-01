#include "systemc.h"

SC_MODULE(reg_32b) {
	sc_in<sc_logic> clk, rst, enable;
	sc_in<sc_uint<32> > d;
	sc_out<sc_uint<32> > q;

	void compute();
	void reset();

	SC_CTOR(reg_32b) {
		SC_METHOD(compute);
		sensitive << clk.pos();
		SC_METHOD(reset);
		sensitive << rst;
	}
};

