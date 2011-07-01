#include "decode.h"

void decode::compute() {
	opcode.write(word.read().range(31,26));
	rs.write(word.read().range(25,21));
	rt.write(word.read().range(20,16));
	rd.write(word.read().range(15,11));
	shamt.write(word.read().range(10,6));
	funct.write(word.read().range(5,0));
}
