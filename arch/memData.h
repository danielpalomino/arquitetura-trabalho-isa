#include "systemc.h"

#define memSIZE 4096
#define memUsedSIZE 1024

SC_MODULE(memData){

  	sc_in<sc_uint<32> > address_a, address_b;
	sc_in<sc_uint<1> > we;
	sc_in<sc_uint<1> > re;
	sc_in<sc_int<32> > data_in;

	sc_out<sc_int<32> > data_out_a, data_out_b;

	//memoria
	sc_signal<sc_int<32> > mem[memSIZE];
	
	void initialize();
	void read_data();
	void write_data();

	SC_CTOR(memData) {
	  SC_METHOD(read_data);
	  sensitive << address_a << address_b;
	  SC_METHOD(write_data);
	  sensitive << address_a << data_in;
	}
};

