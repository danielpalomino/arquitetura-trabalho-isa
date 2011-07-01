#include "systemc.h"
#define SIZE 256

SC_MODULE(stack) {
	sc_in<sc_uint<32> > data_in;
	
	sc_out<sc_uint<32> > data_out;

	sc_signal<sc_uint<32> > pilha [SIZE];
	sc_signal<sc_uint<1> > stack_full, stack_empty;
	sc_signal<sc_uint<8> > pc;
	
	void initialize();
	void push();
	void pop();

	SC_CTOR(stack) {
		SC_METHOD(initialize);
		SC_METHOD(push);
		SC_METHOD(pop);
	}
};

