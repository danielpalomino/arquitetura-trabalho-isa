#include "systemc.h"

SC_MODULE(mux2) {
	sc_in<sc_logic> sel;
	sc_in<sc_int<32> > a, b;
	sc_out<sc_int<32> > s;

	void compute();

	SC_CTOR(mux2) {
		SC_METHOD(compute);
		sensitive << sel << a << b;
	}
};
