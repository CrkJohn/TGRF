from sys import stdin

def dfs(u):
    global num,low,g,dfsCounter,vis,dfsParent,child,p, ap,el
    num[u] = low[u] = dfsCounter
    dfsCounter+=1
    vis[u] = 1
    for v in g[u]:
        if not vis[v]:
            p[v] = u 
            dfs(v)
            if( v == dfsParent) :child+=1
            if low[v]>=num[u]:
                if  low[v] > num[u] :
                    if (u,v) not in ap or (v,u) not in ap:
                        el.append((u,v)); el.append((v,u))
                        ap.append((u,v)); ap.append((v,u))     
            if (u,v) not in ap  or (v,u) not in ap:
                el.append((u,v))
                ap.append((u,v))
                ap.append((v,u))
            low[u] = min(low[v],low[u])
        elif p[u]!=v:
            if (u,v) not in ap or (v,u) not in ap :
                el.append((u,v));
                ap.append((u,v))
                ap.append((v,u))
            low[u] = min(low[u],num[v])

"""
Prueba points and Bridges
    6 6
    1 6
    1 2
    2 3
    2 4
    4 3
    3 5
"""
    
def main():
    global num,low,g,dfsCounter,vis,dfsParent,child,p,ap,el
    ntc = 1
    while 1:
        n , m = [int(x) for x in stdin.readline().strip().split()]
        if not  (n+m):
            break
        n+=1
        ap = []
        el = []
        g  = [[] for edge in range(1000+5)]
        for edge in range(m):
             u , v  = [int(x) for x in stdin.readline().strip().split()]
             g[u].append(v)
             g[v].append(u)
        dfsCounter = 0
        num = [0]*(1000 + 5)
        low = [0]*(1000 + 5)
        vis = [0]*(1000 + 5)
        p = [i for i in range(1000+5)]
        print(ntc)
        print()
        for nodos in range(1,n):
            if not vis[nodos]:
                 dfsParent = nodos
                 child = 0
                 dfs(nodos)
        el.sort()
        for e in el:
            print(*e)
        ntc+=1
        print("#")

main()
