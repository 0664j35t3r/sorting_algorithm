#! /usr/bin/python

def Compare(H, x, k):
  global i
  global passed
  if(not(passed < k)):
    return False
  
  if(H[i] > x):
    passed = passed + 1
  
  if(not(passed < k)):
    return False
  
  if(2*i+1 > len(H)):
    return False

  if(H[2*i+1] > x):
    i = 2*i+1
    Compare(H, x, k)
  
  if(not(passed < k)):
    return False
  
  if(H[2*i+2] > x):
    i = 2*i+2
    Compare(H, x, k)
  
  print(passed)
  
  if(not(passed < k)):
    return False
    
  return True



H = [8 ,6 ,5 ,4 ,1 ,1 ,1, 0, 0, 0, 0, 0, 0, 0, 0]
print(H)

i = 0
passed = 0
print(Compare(H, 2, 4))
