*This project has been created as part of the 42 curriculum by samudgal, sliang*

# Description
## 🎯 Goal of this project
The goal is to write a C program called push_swap which is focused on working with data algorithm. The integers received as arguments, according to different flags and disorder metrics, it calculates and displays how many operations for sorting on bench mode.</br>

## 💡 Overview
- This is a group project. This project is a group project completed by 2 learners working together. Both learners must contribute meaningfully to the project and understand all implemented algorithms.</br>
- Sort rules of push swap 
	1. There are two stacks name a and b. The stack a contains a random amount of negative and/or positive numbers without any duplicate. The stack b is empty.</br>
	2. There are 11 operations to sort data.</br>

	| Code  | Instruction                         | Action                                                 |
	| ----- | ----------------------------------- | ------------------------------------------------------ |
	| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
	| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
	| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
	| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
	| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
	| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
	| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
	| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
	| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
	| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
	| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

	3. Algorithm requirements. There are 4 distinct sorting strategies must be implemented. Based on disorder metric (between 0% to 100%), the program will 


# Instruction

Here is an overview how to run this program with C compiler and Bash terminal.</br>
After download the program directory, you can run `make` to compile push_swap.</br>
```
make
```
Now, push_swap is ready and you can run! Valid inputs look like:
```
./push_swap 1 2 3
```
Intergers are seperated by ' '.
```
./push_swap --simple 1 2 3
```
You can choose 4 flags for algorithms: `--simple` `--medium` `--complex` `--adaptive`. If no algorithm is choosed, adaptive algorithm is by default.</br>
```
./push_swap --simple --bench 1 2 3
```
You can also add a bench mode to display more information about disorder metric, operations, and choosed strategy.</br>

Invalid examples
```
./push_swap 1 1 2					#passing the same numbers
./push_swap 2147483648 -2147483649	#passing integers outside of INT_MAX and INT_MIN (32 bit intergers)
./push_swap one 1 2					#passing string
./push_swap --simple --adaptive		#passing multiple algorithms
./push_swap 1 2 4 --simple			#passing flags and integers in wrong orders
```

# Algorithms

## Data structure
This project we choosed to use singly linked list as data structure. Linked list contains nodes which at lease include two elements: a data, which is a value stored in the node, and a pointer points to the next node. The reason why we choose singly linked list is linked list is the flexibility of the list size and easier to manage operations when rotate and swap data.</br>
This proram converts arguments as intergers and assign linked list stack a, which contains all values; later an empty stack b will be created. If not forced algorithm is chose, this program will calculate disorder metric of stack a and choose suitable algorithms. After data are sorted, two stacks will be free and cleaned.</br>

## Selection sort
There are three phases for selection sort. Selection always find the smallest value in stack_a first and push it to the stack_b and then push back.</br>
- The 1st while loop only apply to above three data. After calculating the size of the stack_a, a helper function will find the min value postion.</br>
- If the current index is equal to the min value's position, then push the data to stack_b; else it is rotated to the bottom of the top depends on where it is located.
- In the end, stack_b will push all data back to stack_a and stack_a will be sorted in ascending order.

## Bucket sort
In general. there are two phases.Phase 1 push data to stack_b as chunks, phase 2 push back sorted data back.</br> 
- In phase 1, there are three condiotns are checked (compare data's index and chunck window): if index < i; if index <= i + chunck_size; and index > i + chunck_size. If index is left behind the current chunck window, it is pushed to stack_b and rotate it to the bottom; if index is within the current chunck window, the data is pushed to stack_b normally; it the index is behind, then rotate this data to the bottom of stack_a and wait for later.</br>
- In phase 2, function find the max integer will push the current maxium data back to stack a first, therefore, when stack_b is empty, stack_a is a sorted linked list.</br> 

## Radix sort
Radix sort will compare data in bit level, in other words, we use bitwise operators to right shift bit postion to compare data.</br>
- After get the stack_a's size, the outer while loop starts when stack_a is not sorted, and assign already compared bits variabl bits_done as 0.
- The 1st nested while loop compares the data's index in stack_a with two bitwise operators `>>` and `&` . If the index right bit is 1, the data will be rotated at the bottom of stack_a; if it is 0, it will be pushed to stack_b. bits_done increments.</br>
- When the bits_done is equal to the value of list size, stack_b will push data into stack_a again. After all data are pushed to stack_b, bit_position will increment until stack_a is sorted.

# Task seperation

| intra    | Task                         		  |
| -----    | -----------------------------------  |
| slaing   | make linked list                     |
|          | computer disorder                    | 
|          | bench mode                           | 
| samudgal | parsing data                         | 
|          | operations                           | 
|          | simple algo                          |
|          | mediuem algo                         |
|          | complex algo                         |
|          | adaptive algo                        |

# Resources

[Linked list in c](https://www.geeksforgeeks.org/c/linked-list-in-c/)
[Selection sort adaptation](https://www.geeksforgeeks.org/dsa/comparison-among-bubble-sort-selection-sort-and-insertion-sort/) </br>
[CS50x 2026 - Lecture 5 - Data Structures](https://www.youtube.com/watch?v=PmAI76OGE_E)</br>
[Chunk-based sorting](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81)</br>
[push swap tutorial](https://www.youtube.com/watch?v=wRvipSG4Mmk)

# AI usage
AI is used as a guider to guide through logic of resolving problems or discuss solutions.
