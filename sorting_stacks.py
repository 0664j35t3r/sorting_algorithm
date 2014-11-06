
## Function
#
def PopPush(s1, s2):
  if(not s1):
    return False
  item = s1.pop()
  s2.append(item)


def Compare(s1, s2):
  if(len(s1) == 0):
    return False
  if(len(s2) == 0):
    return True
  if(s1[-1] > s2[-1]):
    return True
  else:
    return False
    
    
## Main
#

#S1 = [6,5,4,3,2,1]   #11 Schritte
#S1 = [1,2,3,4,5,6]  #41 Schritte
#S1 = [3,1,2,8,6,7]  #33 Schritte
S1 = [3,8,2,1,6,4]  #33 Schritte
S2 = []
S3 = []

anzahl_alle_schritte = 0

PopPush(S1,S2)
count_1 = 0
i = 0
while(i < len(S1)):
  anzahl_alle_schritte += 1
  count_1 += 1
  print"while_1", count_1, anzahl_alle_schritte
  if(Compare(S1, S2)):
    PopPush(S1, S2)
  else:
    j = len(S2)
    count_2 = 0
    while(Compare(S2,S1)):
      anzahl_alle_schritte += 1
      count_2 += 1
      print"while_2", count_2, anzahl_alle_schritte
      PopPush(S2,S3)
      j -= 1
    PopPush(S1, S2)
    count_3 = 0
    while(len(S3) > 0):
      anzahl_alle_schritte += 1
      count_3 += 1
      print"while_3", count_3, anzahl_alle_schritte
      PopPush(S3, S2)

while(len(S2) > 0):
  anzahl_alle_schritte += 1
  print"while_4", anzahl_alle_schritte
  PopPush(S2, S3)
  
print(S1)
print(S2)
print(S3)


print count_1, count_2, count_3


