# credit.py
# 
# Natalia Ostiak
# Technology Nation
# 
# Determines whether a provided credit card number is valid
# according to Luhn’s algorithm.

import cs50

sum_even = 0
sum_odd = 0

# Get credit card number
while True:
    print("Give me a credit card number: ", end="")
    cc_num = cs50.get_float()
    if cc_num > 0:
        break
    
cc_numS1 = str(cc_num) 
dot = cc_numS1.find('.')
cc_numS = cc_numS1[0:dot]
d_num = len(cc_numS)

if d_num!=15 and d_num!=16 and d_num!=13:
    print("INVALID")
    exit(0)
    
# Build the reverse list
cc_numL = list(cc_numS)
cc_numL.reverse()

# Build the reverse string
cc_numSRev = ''.join(cc_numL)
   
# Luhn’s algorithm
for i in range(1, d_num, 2):
    even = int(cc_numSRev[i]) * 2
    if even > 9:
        sum_even += even - 9
    else:
        sum_even += even
            
for i in range(0, d_num, 2):
    sum_odd += int(cc_numSRev[i])
    
sumCheck = (sum_odd + sum_even) % 10

if sumCheck != 0:
    print("INVALID")
elif d_num==15 and int(cc_numS[0])==3 and (int(cc_numS[1])==4 or int(cc_numS[1])==7):
    print("AMEX")
elif d_num==16 and int(cc_numS[0])==5 and (int(cc_numS[1])==1 or int(cc_numS[1])==2 or int(cc_numS[1])==3 
                                                              or int(cc_numS[1])==4 or int(cc_numS[1])==5):
    print("MASTERCARD")
elif (d_num==13 or d_num==16) and int(cc_numS[0])==4:
    print("VISA")
else:
    print("INVALID")
 
exit(0)   
