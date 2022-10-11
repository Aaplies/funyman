endings = [1000,1000000,1000000000,1000000000000,1000000000000000,1000000000000000000,1000000000000000000000,1000000000000000000000000]
k,m,b,t,qa,qi,sx,sp = endings
numStr = input("What is your number?: ")
length = len(numStr)
ending = numStr[(length-1):(length)].lower()
if ending == 'k':
    num = float(numStr[0:(length-1)])
    finalNum = int(num*k)
elif ending == 'm':
    num = float(numStr[0:(length-1)])
    finalNum = int(num*m)
elif ending == 'b':
    num = float(numStr[0:(length-1)])
    finalNum = int(num*b)
elif ending == 't':
    num = float(numStr[0:(length-1)])
    finalNum = int(num*t)
elif ending == 'a':
    ending = numStr[(length-2):(length)].lower()
    num = float(numStr[0:(length-2)])
    finalNum = int(num*qa)
elif ending == 'i':
    ending = numStr[(length-2):(length)].lower()
    num = float(numStr[0:(length-2)])
    finalNum = int(num*qi)
elif ending == 'x':
    ending = numStr[(length-2):(length)].lower()
    num = float(numStr[0:(length-2)])
    finalNum = int(num*sx)
elif ending == 'p':
    ending = numStr[(length-2):(length)].lower()
    num = float(numStr[0:(length-2)])
    finalNum = int(num*sp)
print(finalNum) # Returns final number
