 # caesar.py
 # 
 # Natalia Ostiak
 # Technology Nation
 # 
 # Encrypts messages using Caesar’s cipher.

import sys

if len(sys.argv) != 2:
    print(" Usage:python caesar.py key")
    exit(1) 
    
k = int(sys.argv[1])
s = input("plaintext:  ")
    
print("ciphertext: ", end="")

for c in s:
    if c.isalpha():        
        if c.islower():
            step = 97
        else: 
            step = 65
        print("{}".format(chr((ord(c) - step + k)%26 + step)), end="")        
    else:
        print("{}".format(c), end="")
        
print()        
exit(0)
