import sys

def solve() -> None:
    data = iter(map(int,sys.stdin.buffer.read().split()))
    t = next(data)
    answers = []

    for _ in range(t):
        n = next(data)
        k = next(data)

        unused = 0
        used = float("-inf")
        answer=-1

        for i in range(1,n+1):
            a = next(data)

            unused,used = (
                a+unused,
                max(used+a,unused+a*2)
            )

            if answer == -1 and max(unused,used)>=k:
                answer = i
        answers.append(answer)

    print("\n".join(map(str,answers)))





if __name__ == "__main__":
    solve()