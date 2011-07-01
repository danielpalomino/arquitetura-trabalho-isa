#include "systemc.h"

SC_MODULE(signext) {
	sc_in<sc_int<16> > in;
	sc_out<sc_int<32> > out;

	void compute();

	SC_CTOR(signext) {
		SC_METHOD(compute);
		sensitive << in;
	}
};
