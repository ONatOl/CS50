 # vigenere.py
 # 
 # Natalia Ostiak
 # Technology Nation
 # 
 # Encrypts messages using Vigenère’s cipher.

import sys

if len(sys.argv) != 2:
    print(" Usage:python vigenere.py key")
    exit(1) 
    
k = sys.argv[1]

for c in k:
    if not c.isalpha():
        print("Key is a set of characters from A to Z or from a to z")
        exit(1)
    
k1 = k.upper()   
s = input("plaintext:  ")
print("ciphertext: ", end="")
way = 0

for c in s:
    if c.isalpha():
        if c.isupper():
            step = 65
        else: 
            step = 97
        print("{}".format(chr((ord(c) - step + ord(k1[way%len(k1)]) - 65)%26 + step)), end="")
        way += 1
    else:
        print("{}".format(c), end="")
        
print()        
exit(0)
