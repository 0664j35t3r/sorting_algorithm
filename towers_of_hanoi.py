a = [2,3,1,5,4]

b = []
c = []
ndisks = len(a)
print("-----------test---------")
print( a.count(3)) #print an der listenstelle 3
print(a.pop(0))    #first item
print(a.pop())     #last item
print("--------testende--------")

print(ndisks)
def hanoi(ndisks, a, b, c):
  if(ndisks == 1):
    print("move disk", a, " to ", b, "\n")
  else:
    hanoi(ndisks-1,a,c,b)
    print("Move disc from ", a, " to ", b ,"\n")
    hanoi(ndisks-1,c,b,a)


print(hanoi(ndisks,a,b,c))
