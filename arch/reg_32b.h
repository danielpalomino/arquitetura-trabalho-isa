#include "systemc.h"

SC_MODULE(reg_32b) {
	sc_in<sc_logic> clk;
	sc_in<sc_uint<32> > pc_in;
	sc_out<sc_uint<32> > pc_out;

	void compute();

	SC_CTOR(reg_32b) {
		SC_METHOD(compute);
		sensitive << clk.pos();
	}
};

