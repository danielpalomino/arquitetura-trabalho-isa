#include "systemc.h"

SC_MODULE(multiplyer) {
	sc_in<sc_int<32> > input0, input1;
	
	sc_out<sc_int<32> > output;

	void compute();

	SC_CTOR(multiplyer) {
		SC_METHOD(compute);
		sensitive << input0 << input1;
	}
};
