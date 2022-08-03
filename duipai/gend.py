import random


fout = open("/home/mars/source-code/duipai/data.txt", "w")
n = random.randint(1, 10000)
m = random.randint(1, 10000)
fout.write("%d %d\n" %(n, m))
for i in range(n):
    t = random.randint(1, 10000)
    fout.write("%d "%t)
fout.write('\n')
for i in range(m):
    op = random.randint(1, 2)
    if op==1: 
        x = random.randint(1, n)
        y = random.randint(1, 10000)
    else:
        x = random.randint(1, n)
        y = random.randint(x, n)
    fout.write("%d %d %d\n" %(op, x, y))

fout.close()

