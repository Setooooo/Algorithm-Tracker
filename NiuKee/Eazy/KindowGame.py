import sys

def solve():
    n,m = map(int,sys.stdin.readline().split())
    attackers = [ [] for i in range(n+1) ]
    for _ in range(m):
        u,v = map(int,sys.stdin.readline().split())
        attackers[v].append(u)

    answers = []
    win = [ False for i in range(n+1) ]
    for i in range (1,n+1):
        win[i] = True
        for j in attackers[i]:
            if win[j]:
                win[i] = False
                break
    fina = ["1" if win[i] else "0" for i in range(1,n+1)]
    print("\n".join(fina))


if __name__ == "__main__":
    solve()