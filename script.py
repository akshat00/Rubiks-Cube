import kociemba

file = open('./POSITION.txt', 'r')
x = str(file.read())
file.close()

ans = kociemba.solve(x)
ans = str(ans)

file1 = open('SOLUTION.txt', 'w', )
file1.write(ans)
file1.close()