#!/usr/bin/env python

import sys
import os

def mod_inv (num, mod):
    for x in range(0,mod + 1):
        if ((num*x)%mod == 1):
            return x
    sys.exit('ERROR: Modulo %d Inverse of %d does not exists!' % (mod, num))

msg_file = input("Enter the Cipher Text\n")

# Brute force algorithm
for i in range(0,26):
    if (i%2 != 0) and (i != 13):
        for j in range(0,26):
            print('\n\nFor Key(a.b) = <%d,%d>\nMessage :\n' % (i,j), end='')
            inv = mod_inv(i,26)
            for c in msg_file:
                v = ord(c)
                if (v >= 65) and (v <= 90):
                    # uppercase
                    cip = ((v - 65 - j)*inv + 26)%26 + 65
                elif (v >= 97) and (v <= 122):
                    # lowercase
                    cip = ((v - 97 - j)*inv + 26)%26 + 97
                else:
                    # other characters
                    cip = v
                print('%c' % cip, end='')

