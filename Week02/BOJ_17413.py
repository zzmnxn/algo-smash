from collections import deque

dq = deque()
sentence = input()
output = ""

for ch in sentence:
    if ch==' ':
        if len(dq)==0:
            output=output+ch
        else:
            if dq[0]=='<':
                dq.append(ch)
            else:
                while(len(dq)!=0):
                    x=dq.pop()
                    output=output+x
                output=output+ch
    elif ch=='<':
        if len(dq)==0:
            dq.append(ch)
        else:
            while(len(dq)!=0):
                x=dq.pop()
                output=output+x
            dq.append(ch)
    elif ch=='>':
        while(len(dq)!=0):
            x=dq.popleft()
            output=output+x
        output=output+ch
    else:
        dq.append(ch)

while(len(dq)!=0):
    x=dq.pop()
    output=output+x

print(output)