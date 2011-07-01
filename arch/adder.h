#include "systemc.h"

SC_MODULE(adder) {
	sc_in<sc_int<32> > a, b;
	sc_out<sc_int<32> > s;

	void compute();

	SC_CTOR(adder) {
		SC_METHOD(compute);
		sensitive << a << b;
	}
};
