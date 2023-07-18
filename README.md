# Prerequisites - Installing GCC
``` c
sudo apt update
sudo apt install build-essential
```

# [ Question No. 1 ] Fibonacci sequence using dynamic programming
### Problem
``` c
Node is defined as follows:
typedef struct Node
{
    TypeTag type;
} Node;

typedef enum TypeTag {
    ...
}

Using this structure, please write a function that returns fibonacci sequence based on the following arithmetic operations and conditions
The fibonacci function should be implemented using Dynamic Programming

main()
{
    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4);
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fibo = (*makeFunc(SUB))(sub, NULL);
    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo)
}

Output
add : 16
mul : 20
sub : 4
fibo : 2
```

### Testing the program
``` c
gcc -Wall -Werror -Wextra --pedantic --std=gnu99 fibonacci.c -o result && ./result
```

# [ Question No. 2 ] Piecewise recurrence relations
### Problem
``` c
▪ Implement the following piecewise recurrence relation in the 3 different ways.
▪ Explain the differences (advantages, disadvantages) between the 3.
▪ Must be written in C

The problem
F(n) = F(n - 3) + F(n - 2) where F(0) = 0, F(1) = 1, and F(2) = 2.

Assume that n will be less than or equal to the maximum integer value and non negative. 
You only need to write the function(s).
```

## 1. Fibonacci sequence using recursion
This approach calculates F(n) recursively by directly applying the recurrence relation.
##### Advantages of Recursive Implementation:
- Easy to understand and implement.

##### Disadvantages of Recursive Implementation:
- Inefficiency: The recursive implementation has exponential time complexity. It recalculates the same values repeatedly, leading to redundant computations.
- High memory usage: The recursive calls create a large number of stack frames, which can lead to stack overflow issues for large values of n.

##### Testing the program
``` c
gcc -Wall -Werror -Wextra --pedantic --std=gnu99 piecewise_recursive.c -o result && ./result
```

## 2. Fibonacci sequence using dynamic programming (Top-Down)
Uses memoization to store previously computed values and avoids redundant calculations. The memo array is initialized with -1 to indicate that the corresponding values have not been calculated yet. Recursively calculates F(n) while checking the memo array for precomputed values.
##### Advantages of Top-Down Implementation:
- Efficient: By storing the computed values in a memoization table, redundant computations are avoided. Each value is computed only once.
- Improved time complexity: The time complexity is significantly reduced to linear O(n) as each value is computed and stored only once.
- Better memory management: The memoization approach can handle larger values of n as it avoids stack overflow issues.
- Can handle larger values of n compared to the recursive approach.

##### Disadvantages of Top-Down Implementation:
- Requires additional space: The memoization table requires additional memory space to store the computed values. The space complexity is O(n) to accommodate the table.
- Slightly more complex implementation compared to the recursive approach.

##### Testing the program
``` c
gcc -Wall -Werror -Wextra --pedantic --std=gnu99 piecewise_top_down.c -o result && ./result
```

## 3. Fibonacci sequence using dynamic programming (Bottom-Up)
Solves the problem iteratively from the bottom up, starting from the base cases and uses an array to store the intermediate results and builds up to the final result.
##### Advantages of Bottom-Up Implementation:
- Efficient: This approach avoids redundant computations by iteratively computing and storing the values.
- Improved time complexity: The time complexity is linear O(n) as each value is computed and stored only once.
- Space optimization: Unlike the memoization approach, this approach uses only a single array to store computed values, resulting in better space efficiency.

##### Disadvantages of Bottom-Up Implementation:
- Requires additional space: The output array requires additional memory space to store the computed values. The space complexity is O(n) to accommodate the output array.

##### Testing the program
``` c
gcc -Wall -Werror -Wextra --pedantic --std=gnu99 piecewise_botttom_up.c -o result && ./result
```
