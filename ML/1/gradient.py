def gradient_descent(x, learning_rate, iterations):
    # Function to minimize: y = (x + 3)^2
    def function_to_minimize(x):
        return (x + 3) ** 2

    # Derivative of the function: 2 * (x + 3)
    def derivative(x):
        return 2 * (x + 3)

    for _ in range(iterations):
        gradient = derivative(x)
        x = x - learning_rate * gradient

    return x, function_to_minimize(x)

if _name_ == "_main_":
    # Initial point
    initial_x = 2

    # Learning rate
    learning_rate = 0.1

    # Number of iterations
    iterations = 100

    # Run gradient descent algorithm
    final_x, min_value = gradient_descent(initial_x, learning_rate, iterations)

    # Print the result
    print(f"Local minimum found at x = {final_x}")
    print(f"Minimum value of the function: {min_value}")