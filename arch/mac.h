#include "systemc.h"
#include "adder.h"
#include "multiplyer.h"

SC_MODULE(mac) {
	sc_in<sc_int<32> > input0, input1, input_reg;
	
	sc_out<sc_int<32> > output;
	
	//Instancias do somador e multiplicador
	adder adder0;
	multiplyer mult0;

	sc_signal<sc_int<32> > out_mult;

	void compute();

	SC_CTOR(mac) : adder0("somador"), mult0("multiplicador") {
		SC_METHOD(compute);
		sensitive << input0 << input1 << input_reg;
	}
};

