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
	sc_in<sc_logic> sel_breg_mux;

	sc_in<sc_logic> sel_out_pc_mux;
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
	//INSTANCIAS
	decode *decoder;
	mux2_5b *breg_mux;
	breg *bank_reg;
	sbreg *spec_bank_reg;
	demux4x2 *demux_breg;
	reg_32b *a_reg;
	reg_32b *b_reg;

	//SINAIS
	sc_signal<sc_uint<6> > opcode;
	sc_signal<sc_uint<6> > func;
	sc_signal<sc_uint<5> > rd;
	sc_signal<sc_uint<5> > rs;
	sc_signal<sc_uint<5> > rt;
	sc_signal<sc_uint<5> > shamt;
	
	sc_signal<sc_uint<32> > out_breg_mux;
	sc_signal<sc_uint<32> > out_breg_a;
	sc_signal<sc_uint<32> > out_breg_b;
	sc_signal<sc_uint<32> > out_mux_write;

	sc_signal<sc_logic > sbreg_we;
	sc_signal<sc_uint<32> > out_sbreg_a;
	sc_signal<sc_uint<32> > out_sbreg_b;
	
	sc_signal<sc_uint<32> > out_demux_a;
	sc_signal<sc_uint<32> > out_demux_b;

	sc_signal<sc_uint<32> > out_a_reg;
	sc_signal<sc_uint<32> > out_b_reg;

	//EXE STAGE
	//INSTANCIAS
	alu *ula;
	mac *mac;
	reg_32b *ula_reg;
	reg_32b *mac_reg;

	//SINAIS
	sc_signal<sc_uint<32> > out_mux_op_a;
	sc_signal<sc_uint<32> > out_mux_op_b;
	sc_signal<sc_uint<32> > out_ula;
	sc_signal<sc_logic> out_flag_z;

	sc_signal<sc_uint<32> > out_ula_reg;

	sc_signal<sc_uint<32> > out_mac;
	
	sc_signal<sc_uint<32> > out_mac_reg;



	//MEM STAGE
	//INSTANCIAS
	memData *memData;
	reg_32b *memData_reg_a;
	reg_32b *memData_reg_b;

	//SINAIS
	sc_signal<uint<32> > out_memData_a;
	sc_signal<uint<32> > out_memData_b;

	//WB STAGE

	SC_CTOR(data_path) {
		//IF STAGE
		pc_adder = new adder("pc_adder");
		pc_adder->a(out_pc_reg);
		pc_adder->b(1); //nao eh um inteiro, mas sim uma referencia TODO
		pc_adder->s(out_pc_adder);

		pc_mux = new mux_2("pc_mux");
		pc_mux->sel(sel_out_pc_mux);
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

		breg_mux = new mux_2_5b("breg_mux");
		breg_mux->a(rt);
		breg_mux->b(rd);
		breg_mux->s(out_breg_mux);
		breg_sel->sel(sel_breg_mux);


		bank_reg = new breg("bank_reg");
		bank_reg->clk(clk);
		bank_reg->w_en(breg_we);
		bank_reg->address_a(rs);
		bank_reg->address_b(rt);
		bank_reg->address_w(out_breg_mux);
		bank_reg->data_a(out_breg_a);
		bank_reg->data_b(out_breg_b);
		bank_reg->data_w(out_mux_write);

		spec_bank_reg = new sbreg("specific_bank_reg");
		spec_bank_reg->clk(clk);
		spec_bank_reg->w_en(sbreg_we);
		spec_bank_reg->address_a(rs);
		spec_bank_reg->address_b(rt);
		spec_bank_reg->data_in(out_mux_write);
		spec_bank_reg->data_a(out_sbreg_a);
		spec_bank_reg->data_b(out_sbreg_b);

		demux_breg = new demux4x2("demux_breg");
		demux_breg->a0(out_breg_a);
		demux_breg->b0(out_breg_b);
		demux_breg->a1(out_sbreg_a);
		demux_breg->b1(out_sbreg_b);
		demux_breg->sel();//ultimo bit de algum lugar
		demux_breg->s0(out_demux_a);
		demux_breg->s1(out_demux_b);
		
		a_reg = new reg_32b("op_a_reg");
		a_reg->clk(clk);
		a_reg->rst(reset);
		a_reg->d(out_demux_a);
		a_reg->q(out_a_reg);

		b_reg = new reg_32b("op_b_reg");
		b_reg->clk(clk);
		b_reg->rst(reset);
		b_reg->d(out_demux_b);
		b_reg->q(out_b_reg);

		//EXE STAGE
		ula = new alu("ula");
		ula->funct(ceu); //vem do controle TODO
		ula->op_a(out_mux_op_a);
		ula->op_b(out_mux_op_b);
		ula->alu_out(out_ula);
		ula->z(out_flag_z);

		ula_reg = new reg_32b("ula_reg");
		ula_reg->clk(clk);
		ula_reg->rst(reset);
		ula_reg->d(out_ula);
		ula_reg->q(out_ula_reg);

		mac = new mac("mac");
		mac->input0(xxx); //vem da saida da memoria de dados TODO
		mac->input1(yyy); //vem da saida da memoria de dados TODO
		mac->inputreg(zzz); //entrada que será somada, provavelmente vem da saida de um mux TODO
		mac->output(out_mac);

		mac_reg = new reg_32b("mac_reg");
		mac_reg->clk(clk);
		mac_reg->rst(reset);
		mac_reg->d(out_mac);
		mac_reg->q(out_mac_reg);

		//MEM STAGE
		memData = new memData("memData");
		memData->adress(xxx); //vem da saida do mux da entrada
		memData->we(memData_we);
		memData->re(memData_re);
		//PAREI AQUI
		//TEM QUE REVER A QTDADE DE PORTAS DE ENTRADA E SAIDA DA MEMORIA DE DADOS



	}

};

