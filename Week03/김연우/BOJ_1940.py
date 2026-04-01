N = int(input())
M = int(input())
materials = list(map(int, input().split()))

materials.sort()

left=0
right=len(materials)-1

output=0

while(left < right):
    if materials[left]+materials[right]>M:
        right-=1
    else:
        if materials[left]+materials[right]==M:
            output+=1
        left+=1

print(output)