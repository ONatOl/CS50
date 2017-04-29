# greedy.py
# 
# Natalia Ostiak
# Technology Nation
# 
# Calculates the minimum number of coins required to give a user change.

import cs50

while True:
    print("How much change is owed?")
    n = cs50.get_float()
    if n >= 0:
        break
    
i = round(n * 100)

c = i // 25
i = i % 25

c += i//10
i = i % 10
     
c += i//5    

c += i%5
      
print(c)
