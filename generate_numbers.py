#! /bin/python3

import random

def generate_unique_numbers(count, range_start, range_end):
    # Ensure the range can provide enough unique numbers
    if range_end - range_start + 1 < count:
        raise ValueError("The range is too small for the required count of unique numbers.")
    # Generate 'count' unique numbers within the specified range
    unique_numbers = random.sample(range(range_start, range_end + 1), count)
    return unique_numbers

def main():
    # Generate 100 unique numbers from a specified range
    unique_100 = generate_unique_numbers(100, -2500, 2500)  # Adjust range as needed
    # Generate 500 unique numbers from a different or same range
    unique_500 = generate_unique_numbers(500, 1, 5000)  # Adjust range to ensure enough unique numbers

    #print(" ".join(map(str, unique_100)))
    #print("\nSequence of 500 unique numbers:")
    print(" ".join(map(str, unique_500)))

# Execute the main function
if __name__ == "__main__":
    main()
