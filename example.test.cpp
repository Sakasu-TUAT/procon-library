# Problem: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
from bisect import bisect_left

def main():
    n = int(input())
    s = list(map(int, input().split()))
    q = int(input())
    
    s.sort()  # Pythonのリストをソート

    cnt = 0
    for _ in range(q):
        t_i = int(input())
        # bisect_leftで二分探索
        cnt += bisect_left(s, t_i) < n and s[bisect_left(s, t_i)] == t_i
    
    print(cnt)

if __name__ == "__main__":
    main()
