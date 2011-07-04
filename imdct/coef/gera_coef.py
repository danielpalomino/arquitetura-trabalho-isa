from math import *

def geraCoef(N,m,k):
	a = m + 1/2.0000 + N/2.0000
	b = k + 1/2.0000
	c = pi/N
	return cos(a*b*c)

def intToBin(n, size):
	word = ''
	for i in range(0,size):
		x = 1 << i
		char = n & x
		if(char == 0):
			word = '0' + word
		else:
			word = '1' + word
	return word


fp_in = open('in','r')
buff = fp_in.readlines()
fp_in.close()

coefList = []
cont=1
for line in buff:
#	coefList.append(' N ' + str(int(line)))
	for i in range(0,(int(line)*2)):
#		coefList.append('  Y ' + str(i))
		for k in range(0, int(line)):
#			coefList.append(str(int(geraCoef(int(line),i,k)*100)))
			coefList.append(str(int(geraCoef(int(line),i,k)*100)))
			cont = cont + 1

fp_out = open('out','w')

i = 0
for coef in coefList:
	fp_out.write(str(coef) + ',')
	i += 1
	if i%72 == 0:
		fp_out.write('\n')


fp_out.close()
