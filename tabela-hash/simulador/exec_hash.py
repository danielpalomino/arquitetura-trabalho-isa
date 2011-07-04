def insert(key, f):
	c = 0
	suc = 0
	for elem in hash[f]:
		if elem == key:
			suc = 1
			return c
		else:
			c += 1
	hash[f].insert(0,key)
	return (c,suc)

def search(key, f):
	c = 0
	for elem in hash[f]:
		if elem == key:
			return c
		else:
			c += 1
	return c

hash = []
for i in range(0,16):
	hash.append([])

fp = open('hash_f_30.txt', 'r')
buff = fp.readlines()
l = []
f_key = []

for i in range(0,40,2):
	f = int(buff[i])
	key = int(buff[i+1])
	f_key.append([f,key])
	l.append(insert(key,f))

print len(l)

c = 0
#INICIO
c += 20

for e in l:
	c += 12 #hash
	c += 4 + e[0]*4 #esforco do search
	if e[1] == 0: #esforco do insert
		c += 7
	else:
		c += 4
	c += 15 #other
c += 10 #lws
print c
j = 0
for e in l:
	c += 12 #hash
	f = f_key[j][0]
	k = f_key[j][1]
	c += search(key, f) #esforco do search
	c += 11 #other
	j += 1

print 'resultado', c


