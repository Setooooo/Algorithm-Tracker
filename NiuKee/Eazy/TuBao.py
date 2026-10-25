import sys

def solve():
    data = iter(map(int,sys.stdin.buffer.read().split()))
    t = next(data)
    answers = []
    for _ in range(t):
        q = next(data)
        black = set()
        x = next(data)
        y = next(data)
        black.add((x, y))

        min_x = max_x = x
        min_y = max_y = y
        min_sum = max_sum = x + y
        min_diff = max_diff = x - y

        for _ in range(q - 1):
            x = next(data)
            y = next(data)
            black.add((x, y))

            point_sum = x + y
            point_diff = x - y

            min_x = min(min_x, x)
            max_x = max(max_x, x)
            min_y = min(min_y, y)
            max_y = max(max_y, y)
            min_sum = min(min_sum, point_sum)
            max_sum = max(max_sum, point_sum)
            min_diff = min(min_diff, point_diff)
            max_diff = max(max_diff, point_diff)

        total_points = 0

        for x in range(min_x, max_x+1):
            low = max(min_y,min_sum-x,x-max_diff)
            high = min(max_y,max_sum-x,x-min_diff)
            if low <= high:
                total_points += high - low +1
        answers.append(total_points-len(black))

    print("\n".join(map(str,answers)))



if __name__ == "__main__":
    solve()
