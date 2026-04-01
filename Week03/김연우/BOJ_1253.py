N = int(input())
numbers = list(map(int, input().split()))

numbers.sort()
output=0

for i in range(len(numbers)):
    x = numbers[i]
    left=0
    right=len(numbers)-1
    
    while(left<right):
        
        if(left==i): 
            left+=1
            continue
        if(right==i):
            right-=1
            continue

        if numbers[left]+numbers[right]==x:
            output+=1
            break
        else: 
            if numbers[left]+numbers[right]>x:
                right-=1
            else: left+=1
          
print(output)