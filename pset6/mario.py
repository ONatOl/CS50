import cs50

while True:
    print("Height: ", end="")
    h = cs50.get_int()
    if h>0 and h<23:
        break
    
i = 1    
while i <= h:
    print(" " * (h-i), "#" * i, "  ", "#" * i, sep ="")
    i += 1
