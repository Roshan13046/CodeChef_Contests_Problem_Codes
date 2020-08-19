# cook your dish here
#Solved by ROSHAN-RAUT in PYTHON ON 9-8-2020

from copy import deepcopy

for test in range(int(input())):
  
  str = list(input())
  pat = list(input())
  
  for i in pat:
    str.remove(i)
    
  str.sort() 
  
  deep = deepcopy(str)
  deep.append(pat[0])
  deep = sorted(deep,reverse=True)
  
  if pat[0] not in str:
    print(''.join(str[0:len(deep) - deep.index(pat[0]) - 1])+''.join(pat)+
    ''.join(str[len(deep) - deep.index(pat[0])-1:]))
    
  else:
    ans = ''.join(str[0:str.index(pat[0])]) +''.join(pat)+''.join(str[str.index(pat[0]):])
    
  
    print(min(ans,''.join(str[0:len(deep) - deep.index(pat[0]) - 1]) + ''.join(pat) + ''.join(str[len(deep) - deep.index(pat[0])-1:])))
