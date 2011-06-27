#include "systemc.h"

SC_MODULE(MemInstruction){
	sc_in<sc_uint<32> > pc;
	sc_out<sc_int<32> > instruction;

	//memoria
	sc_signal<sc_int<32> > mem[1024];

	void compute();

	SC_CTOR(MemInstruction) {
		SC_METHOD(compute);
		sensitive << pc;
	}
};

