import sys

for line in sys.stdin:
	f = line[0:6]
	n = int(line[7:9].strip())
	f1, f2 = f.split('.')

	while(f2.endswith('0')):
		f2 = f2[:-1]

	ex = len(f2) * n
	f = int(''.join((f1, f2)))
	f = str(f ** n)
	before = len(f) - ex
	if before < 0:
		print('.' + '0' * (-before) + f)
	else:
		if ex == 0:
			print(f)
		else:
			print(f[:before] + '.' + f[before:])