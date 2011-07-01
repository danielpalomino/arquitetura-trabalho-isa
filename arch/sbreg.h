#include "systemc.h"

SC_MODULE(sbreg) {
	sc_in<sc_logic> clk, w_en;
	sc_in<sc_uint<4> > address_a, address_b;
	sc_in<sc_uint<32> > data_in;
	sc_out<sc_uint<32> > data_a, data_b;

	sc_signal<sc_uint<32> > bank[16];

	void read();
	void write();

	SC_CTOR(sbreg) {
		SC_METHOD(write);
		sensitive << clk.pos();
		SC_METHOD(read);
		sensitive << address;
	}
};
