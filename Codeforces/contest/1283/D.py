import queue
q = queue.Queue()
occupied = {}
n, m = map(int, input().split())
a = list(map(int, input().split()))
for i in a:
    occupied[i] = 0
    q.put(i)

print
sum_consume = 0
cnt = 0
output = []
while not q.empty():
    top = q.get()
    if top-1 not in occupied:
        sum_consume += occupied[top]+1
        occupied[top-1] = occupied[top] +1 
        cnt += 1
        output.append(top-1)
        q.put(top-1)
    if cnt == m:
        break

    if top+1 not in occupied:
        sum_consume += occupied[top]+1
        occupied[top+1] = occupied[top] +1 
        cnt += 1
        output.append(top+1)
        q.put(top+1)
    if cnt == m:
        break
print(sum_consume)

print(" ".join(str(i) for i in output))
