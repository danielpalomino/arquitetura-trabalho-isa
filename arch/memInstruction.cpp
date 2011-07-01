#include "memInstruction.h"

void memInstruction::compute() {
	instruction.write(mem[pc.read()].read());
}
