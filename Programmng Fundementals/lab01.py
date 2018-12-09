"""
Find the smallest number m
from the Fibonacci sequence, defined by f[0]=f[1]=1, f[n]=f[n-1]+f[n-2],
for n>2, larger than the given natural number n. So, find k and m such that
f[k]=m, m>n and f[k-1] <=n
"""
def afisare(n):
    print(n)
def rezolvare(n,k,m):
    a=1
    b=1
    
    while (m<=n and k<n):
        m=a+b
        k=k+1
        a=b
        b=m
    return k
def rezolvare2(n,k,m):
    a=1
    b=1
    for i in range(3,k+2):
        m=a+b
        a=b
        b=m
    return m
def test_rezolvare():
    n=5
    k=1
    m=0
    assert rezolvare(n,k,m)==5
    k=5
    assert rezolvare2(n,k,m)==8


def main():
    test_rezolvare()
    n=int(input("dati nr: "))
    
    k=1
    m=0
    k=rezolvare(n,k,m)
    m=rezolvare2(n,k,m)
    if m<=n:
        print("nu exista")
    
    else:
        afisare(k)
        afisare(m)
main()
