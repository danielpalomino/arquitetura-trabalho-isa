#include "systemc.h"
#include "adder.h"
#include "multiplyer.h"

SC_MODULE(mac) {
	sc_in<sc_int<32> > input0, input1, input_reg;
	
	sc_out<sc_int<32> > output;
	
	//Instancias do somador e multiplicador
	adder *adder0;
	multiplyer *mult0;

	sc_signal<sc_int<32> > out_mult;

	SC_CTOR(mac) {
		mult0 = new multiplyer("mac_mult");
		adder0 = new adder("mac_adder");

		mult0.input0(input0);
		mult0.input1(input1);
		mult0.output(out_mult);

		adder0.a(input_reg);
		adder0.b(out_mult);
		adder0.s(output);
	}
};

