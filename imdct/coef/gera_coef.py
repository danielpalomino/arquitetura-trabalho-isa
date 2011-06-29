from math import *

def geraCoef(N,m,k):
	a = m + 1/2.0000 + N/2.0000
	b = k + 1/2.0000
	c = pi/N
	return cos(a*b*c)

fp_in = open('in','r')
buff = fp_in.readlines()
fp_in.close()

coefList = []
for line in buff:
	coefList.append(' N ' + str(int(line)))
	for i in range(0,(int(line)*2)):
		coefList.append('  Y ' + str(i))
		for k in range(0, int(line)):
			coefList.append('   coef ' + str(k) + ": " + str(int(geraCoef(int(line),i,k)*100)))

fp_out = open('out','w')

for coef in coefList:
	fp_out.write(str(coef) + '\n')

fp_out.close()
