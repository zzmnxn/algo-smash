from collections import deque

N, M = list(map(int, input().split()))
elec_list = list(map(int, input().split()))

elec_list.sort()
elec_list = deque(elec_list)

consent = [0]*M
while(len(elec_list)!=0):
    x=elec_list.pop()
    consent[0]+=x
    consent.sort()

print(max(consent))                                           