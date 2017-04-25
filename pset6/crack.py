# crack.py
# 
# Natalia Ostiak
# Technology Nation
# 
# Cracks passwords.
 
import sys
import crypt

salt = "50"
letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'

if len(sys.argv) != 2:
    print(" Usage:python crack.py hash")
    exit(1) 
    
# if the password is one character
for c in letters: 
    key = c
    result = crypt.crypt(key, salt)
    if result == sys.argv[1]:
        print("{}".format(key))
        exit(0)
       
# if the password is two characters
for c in letters: 
    key21 = c
    for c in letters:
        key2 = key21 + c
        result = crypt.crypt(key2, salt)
        if result == sys.argv[1]:
            print("{}".format(key2))
            exit(0)
                
# if the password is three characters
for c in letters: 
    key31 = c
    for c in letters:
        key32 = c
        for c in letters:
            key3 = key31 + key32 + c
            result = crypt.crypt(key3, salt)
            if result == sys.argv[1]:
                print("{}".format(key3))
                exit(0)
                   
# if the password is four characters
for c in letters: 
    key41 = c
    for c in letters:
        key42 = c
        for c in letters:
            key43 = c
            for c in letters:
                key4 = key41 + key42 + key43 + c
                result = crypt.crypt(key4, salt)
                if result == sys.argv[1]:
                    print("{}".format(key4))
                    exit(0) 
