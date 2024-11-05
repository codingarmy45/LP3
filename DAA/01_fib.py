def recursive_fibonacci(n):  # defining a recursive function
    if n <= 1:
        return n
    else:
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2)  # will return sum of two terms

def non_recursive_fibonacci(n):
    first = 0
    second = 1
    step_count = 2
    
    if n >= 1:
        print(first)  # Print the first term
    if n >= 2:
        print(second)  # Print the second term
        
    while step_count < n:
        third = first + second
        print(third)  # Print the next term in the sequence
        first = second
        second = third
        step_count += 1
        
    return step_count

n = int(input("Enter the nth term: "))

print("The Fibonacci sequence using recursive function:")
for i in range(n):
    print(recursive_fibonacci(i))

print("The Fibonacci sequence using non-recursive function:")
steps = non_recursive_fibonacci(n)
print(f"Steps: {steps}")
