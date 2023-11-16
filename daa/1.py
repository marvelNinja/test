def iStepFibbonacci(n):
    f = [0, 1]
    for i in range(2, n + 1):
        f.append(f[i - 1] + f[i - 2])
    return f[n]
def rStepFibbonacci(n):
    if n < 0:
        return 0
    elif n == 0 or n == 1:
        return 1
    else:
        return rStepFibbonacci(n - 1) + rStepFibbonacci(n - 2)
def main():
    n = int(input("Enter NO: "))
    fibI = iStepFibbonacci(n)
    fibR = rStepFibbonacci(n)
    print(f"Fibonacci Value (Iteration): {fibI}")
    print(f"Fibonacci Value (Recursion): {fibR}")
    print(f"Steps required using Iteration: {n}")
    print(f"Steps required using Recursion: {rStepFibbonacci(n)}")
if __name__ == "__main__":
    main()