
test  = int(input())
while(test > 0):
  test -= 1
  n = int(input())
  
  ans = 0
  b=[]
  
  for i in range(n):
    b.append([int(x) for x in input().split()])
  for p in range(n-1,0,-1):
    doing = b[p][p-1]+1
    if doing!=b[p][p]:
      ans += 1
      danadan = p+1
      for i in range(danadan):
        for j in range(i,danadan):
          # transposing the given matrix by swapping the elements
          temp = b[i][j]
          b[i][j] = b[j][i]
          b[j][i] = temp
          
          
  print(ans)        
