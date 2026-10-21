s = input("Enter a number: ")
try:
    n = int(s)
    # if no error is found, we can print the digits
    while n > 0:
        print(n % 10)
        n = n // 10
except ValueError as e:
    print("You must enter an integer")
    print("Error message: ", e)
