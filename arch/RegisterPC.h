#include "sytemc.h"

SC_MODULE(RegisterPC) {
	sc_in<bool> clk;
	sc_in<sc_uint<32> > pc_in;
	sc_out<sc_uint<32> > pc_out;

	void compute();

	SC_CTOR(RegisterPC) {
		SC_METHOD(compute);
		sensitive << clk.pos();
	}
};

