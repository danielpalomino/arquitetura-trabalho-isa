#include "noclib.h"

int coef[720] = {60,-92,-13,99,-38,-79,38,-92,92,-38,-38,92,13,-38,60,-79,92,-99,-13,38,-60,79,-92,99,-38,92,-92,38,38,-92,-60,92,13,-99,38,79,-79,38,99,13,-92,-60,-92,-38,38,92,92,38,-99,-92,-79,-60,-38,-13,-99,-92,-79,-60,-38,-13,-92,-38,38,92,92,38,-79,38,99,13,-92,-60,
	67,-79,-53,88,38,-95,-21,99,4,-99,13,97,-30,-92,46,84,-60,-73,60,-92,-13,99,-38,-79,79,38,-99,13,92,-60,-60,92,13,-99,38,79,53,-99,30,73,-92,4,88,-79,-21,97,-60,-46,99,-38,-67,95,-13,-84,46,-99,67,21,-92,84,-4,-79,95,-30,-60,99,-53,-38,97,-73,-13,88,
	38,-92,92,-38,-38,92,-92,38,38,-92,92,-38,-38,92,-92,38,38,-92,30,-79,99,-84,38,21,-73,99,-88,46,13,-67,97,-92,53,4,-60,95,21,-60,88,-99,92,-67,30,13,-53,84,-99,95,-73,38,4,-46,79,-97,13,-38,60,-79,92,-99,99,-92,79,-60,38,-13,-13,38,-60,79,-92,99,
	4,-13,21,-30,38,-46,53,-60,67,-73,79,-84,88,-92,95,-97,99,-99,-4,13,-21,30,-38,46,-53,60,-67,73,-79,84,-88,92,-95,97,-99,99,-13,38,-60,79,-92,99,-99,92,-79,60,-38,13,13,-38,60,-79,92,-99,-21,60,-88,99,-92,67,-30,-13,53,-84,99,-95,73,-38,-4,46,-79,97,
	-30,79,-99,84,-38,-21,73,-99,88,-46,-13,67,-97,92,-53,-4,60,-95,-38,92,-92,38,38,-92,92,-38,-38,92,-92,38,38,-92,92,-38,-38,92,-46,99,-67,-21,92,-84,4,79,-95,30,60,-99,53,38,-97,73,13,-88,-53,99,-30,-73,92,-4,-88,79,21,-97,60,46,-99,38,67,-95,13,84,
	-60,92,13,-99,38,79,-79,-38,99,-13,-92,60,60,-92,-13,99,-38,-79,-67,79,53,-88,-38,95,21,-99,-4,99,-13,-97,30,92,-46,-84,60,73,-73,60,84,-46,-92,30,97,-13,-99,-4,99,21,-95,-38,88,53,-79,-67,-79,38,99,13,-92,-60,60,92,-13,-99,-38,79,79,-38,-99,-13,92,60,
	-84,13,95,67,-38,-99,-46,60,97,21,-79,-88,4,92,73,-30,-99,-53,-88,-13,73,97,38,-53,-99,-60,30,95,79,-4,-84,-92,-21,67,99,46,-92,-38,38,92,92,38,-38,-92,-92,-38,38,92,92,38,-38,-92,-92,-38,-95,-60,-4,53,92,97,67,13,-46,-88,-99,-73,-21,38,84,99,79,30,
	-97,-79,-46,-4,38,73,95,99,84,53,13,-30,-67,-92,-99,-88,-60,-21,-99,-92,-79,-60,-38,-13,13,38,60,79,92,99,99,92,79,60,38,13,-99,-99,-97,-95,-92,-88,-84,-79,-73,-67,-60,-53,-46,-38,-30,-21,-13,-4,-99,-99,-97,-95,-92,-88,-84,-79,-73,-67,-60,-53,-46,-38,-30,-21,-13,-4,
	-99,-92,-79,-60,-38,-13,13,38,60,79,92,99,99,92,79,60,38,13,-97,-79,-46,-4,38,73,95,99,84,53,13,-30,-67,-92,-99,-88,-60,-21,-95,-60,-4,53,92,97,67,13,-46,-88,-99,-73,-21,38,84,99,79,30,-92,-38,38,92,92,38,-38,-92,-92,-38,38,92,92,38,-38,-92,-92,-38,
	-88,-13,73,97,38,-53,-99,-60,30,95,79,-4,-84,-92,-21,67,99,46,-84,13,95,67,-38,-99,-46,60,97,21,-79,-88,4,92,73,-30,-99,-53,-79,38,99,13,-92,-60,60,92,-13,-99,-38,79,79,-38,-99,-13,92,60,-73,60,84,-46,-92,30,97,-13,-99,-4,99,21,-95,-38,88,53,-79,-67};

int entrada[6] = {2, 3, 4, 5, 6, 7};
int saida[12];

int main() {
	int i ,j, acum, k=0;
	for(i=0; i<12; i++) {
		acum = 0;
		for(j=0; j<6; j++) {
			acum += entrada[j] * coef[k];
			k++;
		}
		saida[i] = acum;
	}
	memstore(MAPPED_OUTPUT0, 0);


}
