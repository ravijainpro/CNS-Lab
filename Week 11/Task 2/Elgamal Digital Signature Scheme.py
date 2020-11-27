#!/usr/bin/env python
# encoding:UTF-8
"""

Implement the ElGamal Digital Signature Scheme.

Algorithm
Key Generation
1. Select a large random prime p and a generator α of Z∗p.
2. Generate a random integer x such that 1≤x≤p−2. 
3. Compute y = α**x mod p.
4. A’s public key is (p, α, y).
5. A’s private key is x.

Signature Generation
A generates a signature for a message m (0 ≤ m < p−1) as follows:
1. Generatea random integer k such that 1≤k≤p−2 and gcd(k,p−1)=1.
2. Compute r = α**k mod p.
3. Compute k**−1 mod (p − 1).
4. Computes=k**−1(m−xr)mod(p−1). 
5. A’s signature for m is the pair (r, s),

Signature Verification
A signature (r, s) produced by A can be verified as follows:
1. Verify that 1 ≤ r ≤ (p−1); if not return False.
2. Compute v1 = (y**r)(r**s) mod p. 
3. Compute v2 = α**m mod p. 
4. Return v1 = v2.

"""
import Crypto.Util.number as num
import random
import Crypto.Util.number as num
import random

def pair(s):
    safe_prime = 0
    while(True):
        p = num.getPrime(s)
        safe_prime = 2*p+1
        if(num.isPrime(safe_prime)):
            break
    while(True):
        a = random.randint(2, safe_prime-1) 
        if((safe_prime-1)%a != 1):
            break
    return safe_prime, a


#####################################################################
# Tests

import Crypto.Util.number as CUN

#if __name__ == "__main__":
	#print(pair(10))
	#print(pair(100))
	#print pair(300)

def egKey(s):
    a, p = pair(s)
    x = random.randint(1, p-2)
    y = pow(a,x,p)
    return p, a, x, y

""" Signature Generation 
"""
def egGen(p, a, x, m):
	while 1:
		k = random.randint(1,p-2)
		if num.GCD(k,p-1)==1: break
	r = pow(a,k,p)
	l = num.inverse(k, p-1)
	s = l*(m-x*r)%(p-1)
	return r,s

""" Signature Verification 
"""
def egVer(p, a,	y, r, s, m):
	if r < 1 or r > p-1 : return False
	v1 = pow(y,r,p)%p * pow(r,s,p)%p
	v2 = pow(a,m,p)
	return v1 == v2

#####################################################################
# Tests

if __name__ == "__main__":
	
	message = 36
	print("Message: ", message)
	prime,alpha,private,public = egKey(10)
	print("Prime: ", prime, "\nAlpha: ", alpha, "\nPrivate: ", private, "\nPublic: ,", public)
	rr,ss = egGen(prime,alpha,private, message)
	print("RR: ", rr,"\nSS: ", ss)
	isValid = egVer(prime, alpha, public, rr, ss, message)
	print("Valid Signature: " ,  isValid)


