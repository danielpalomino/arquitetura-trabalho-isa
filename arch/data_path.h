#include "systemc.h"
#include "adder.h"
#include "alu.h"
#include "breg.h"
#include "control_unit.h"
#include "decode.h"
#include "mac.h"
#include "memData.h"
#include "memInstruction.h"
#include "multiplyer.h"
#include "mux2_5b.h"
#include "mux2.h"
#include "opcodes.h"
#include "reg_32b.h"
#include "sbreg.h"
#include "signext.h"
#include "stack.h"

SC_MODULE(data_path) {

	sc_in<sc_logic> clk;
	sc_in<sc_logic> reset;
	sc_in<sc_logic> pc_enable;
	sc_in<sc_logic> reg_stages_enable;

	sc_in<sc_logic> out_pc_mux_sel;
	//IF STAGE
	//INSTANCIAS
	adder *pc_adder;
	memInstruction *ins_mem;
	reg_32b *pc_reg;
	reg_32b *ins_reg;
	mux_2 *pc_mux;
	//SINAIS
	sc_signal<uint<32> > out_pc_adder;
	sc_signal<uint<32> > out_pc_reg;
	sc_signal<uint<32> > out_pc_mux;
	sc_signal<uint<32> > out_ins_mem;
	sc_signal<uint<32> > out_ins_reg;
	sc_signal<uint<32> > in1_pc_mux;//vem do alem TODO

	//ID STAGE
	decode *decoder;
	
	//SINAIS
	sc_signal<sc_uint<6> > opcode;
	sc_signal<sc_uint<6> > func;
	sc_signal<sc_uint<5> > rd;
	sc_signal<sc_uint<5> > rs;
	sc_signal<sc_uint<5> > rt;
	sc_signal<sc_uint<5> > shamt;
	

	//EXE STAGE

	//MEM STAGE

	//WB STAGE

	SC_CTOR(data_path) {
		//IF STAGE
		pc_adder = new adder("pc_adder");
		pc_adder->a(out_pc_reg);
		pc_adder->b(1); //nao eh um inteiro, mas sim uma referencia TODO
		pc_adder->s(out_pc_adder);

		pc_mux = new mux_2("pc_mux");
		pc_mux->sel(out_pc_mux_sel);
		pc_mux->a(out_pc_adder);
		pc_mux->b(in1_pc_mux);
		pc_mux->s(out_pc_mux);

		pc_reg = new reg_32b("pc_reg");
		pc_reg->clk(clk);
		pc_reg->rst(reset);
		pc_reg->enable(pc_enable);
		pc_reg->d(out_pc_mux);
		pc_reg->q(out_pc_reg);

		ins_mem = new memInstruction("instruction_memory");
		ins_mem->pc(out_pc_reg);
		ins_mem->instruction(out_ins_mem);

		ins_reg = new reg_32b("instruction_register");
		ins_reg->clk(clk);
		ins_reg->rst(reset);
		ins_reg->enable(reg_stages_enable);
		ins_reg->d(out_ins_mem);
		
		//ID STAGE
		decoder = new decode("decoder");
		decoder->word(out_ins_mem);
		decoder->opcode(opcode);
		decoder->funct(func);
		decoder->rs(rs);
		decoder->rt(rt);
		decoder->rd(rd);
		decoder->shamt(shamt);



	}

};

