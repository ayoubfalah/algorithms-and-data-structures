# Uses python3

n = int(input())

def get_fibonacci_last_digit(n):
    if n < 2:
        return n
    else:
        k = n % 60
        previous = 0
        current = 1
        for _ in range(2, k+1):
            previous, current = current, (previous + current) % 10
    return current 

print(get_fibonacci_last_digit(n))
