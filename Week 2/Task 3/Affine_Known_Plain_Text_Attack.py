a = input("Input Plain Text: ")
b = input("Output Cipher Text: ")
A = []

for letter in a:
  number = ord(letter) - 96
  A.append(number)
B = []

for letter in b:
  number = ord(letter) - 96
  B.append(number)

m = (B[0]-B[1])/(A[0]-A[1])
c = B[0]-m*A[0]

if(m<0):
	m+=26
if(m>26):
	m%=26
if(c<0):
	c+=26
if(c>26):
	c%=26

print("Keys=(a,b) : ", m, " ", c)
