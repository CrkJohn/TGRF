from sys import stdin;from collections import deque

def  Primero_ingreso(Nodos):
    for i in Orden_llegada:
        if i in Nodos:
            return i
def Siguiente_N():
    C = set(list(G.keys()))
    for V in G.values():
        C-=set(V)
    return C

def Ordenamiento(V):
    q = deque()
    q.append(V)
    Orden_sort=""
    while q:
        u = q.popleft()
        Orden_sort+=(str(u)+" ")
        del G[u]
        Gr_0 = Siguiente_N()
        longitud = len(Gr_0)
        if longitud ==1:
            q.append(Gr_0.pop())
        elif longitud>1:
            q.append(Primero_ingreso(Gr_0))
    return Orden_sort

def main():
    global G,Orden_llegada
    Lectura = stdin.readline().strip()
    Numero_caso = 1
    while len(Lectura)!=0:
        G = {}
        Orden_llegada = []
        for i in range(int(Lectura)):
            Cervezas_I=stdin.readline().strip()
            G[Cervezas_I]=[]
            Orden_llegada.append(Cervezas_I)
        Arcos_Entrantes= int(stdin.readline().strip())
        for i in range(Arcos_Entrantes):
            G_i,G_f=stdin.readline().strip().split()
            G[G_i].append(G_f)     
        Gr_0 = Siguiente_N()
        if len(Gr_0) ==1:
            Toposort_Final=Ordenamiento(Gr_0.pop())
        elif len(Gr_0) >1:
            Toposort_Final = Ordenamiento(Primero_ingreso(Gr_0))
        print("Case #{}: Dilbert should drink beverages in this order: {}.".format(Numero_caso,Toposort_Final.strip()))
        print()
        Numero_caso= Numero_caso + 1
        stdin.readline().strip()
        Lectura = stdin.readline().strip()
main()
