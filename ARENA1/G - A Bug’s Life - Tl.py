from sys import stdin
from collections import deque
from sys import setrecursionlimit
setrecursionlimit(9000)

def bfs(src):
    global vis,g,n,esMarica,p
    q = deque()
    q.append(src)
    isBipartite = True
    esMarica[src]=0
    while  q and isBipartite:
            u = q.popleft()
            for v in g[u]:
                if(esMarica[v]==float('inf')):
                        esMarica[v] = 1-esMarica[u]
                        q.append(v)
                elif esMarica[v] == esMarica[u]:
                        isBipartite = False
                        break
    return isBipartite

def main():
    global vis,g,n,esMarica,p
    ntc = int(stdin.readline().strip())
    for ctn in range(1,ntc+1):
        n , m = [int(x) for x in stdin.readline().strip().split()]
        g =  [[] for edges in range(n+1)]
        for uv in range(m):
            u , v = [int(x) for x in stdin.readline().strip().split()]
            g[u].append(v)
            g[v].append(u)
        vis = [0]*(n+5)
        esFloor = True
        esMarica = [float('inf')]*(n+1)
        for u in range(n):
            if not vis[u]:
                esFloor = bfs(u)
                if esFloor == False:
                    break
        print("Scenario #%d:"%(ctn))
        if not esFloor:
            print("Suspicious bugs found!")
        else:
            print("No suspicious bugs found!")
main()
