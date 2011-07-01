#include "systemc.h"

SC_MODULE(mux2_5b) {
	sc_in<sc_logic> sel;
	sc_in<sc_int<5> > a, b;
	sc_out<sc_int<5> > s;

	void compute();

	SC_CTOR(mux2_5b) {
		SC_METHOD(compute);
		sensitive << sel << a << b;
	}
};
