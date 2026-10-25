# https://ac.nowcoder.com/acm/contest/141878/A
import sys


def main():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()


    answer = -1


    if s[-1] == ")":
        for i in range(n-2,-1,-1):
            if s[i] == "(":
                answer = i+1
                break
            if s[i] == ")":
                break
    print(answer)



if __name__ == "__main__":
    main()
