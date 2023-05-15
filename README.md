# push_swap
Given a set of integers, sort it using a predefined set of instructions using two stacks. The instruction set is defined below. This program outputs a program in push_swap instructions that sorts the input integers.

### Instruction set
We must be able to sort a random set of integers in a minimum amount of steps using only the following set of action. The goal is to learn algorithmic sorting using only operation that are stack related.

| Code    | Instruction	         | Action |
| ------- | -------------------- | ------ |
| **pa**  |	push a	              | moves the top element of stack b at the top of stack a, doesn't do anything if stack b is empty |
| **pb**  |	push b	              | moves the top element of stack a at the top of stack b, doesn't do anything if stack a is empty |
| **sa**  |	swap a                |	swaps the 2 top elements of stack a, doesn't do anything if there is one element or less |
| **sb**  |	swap b                |	swaps the 2 top elements of stack b, doesn't do anything if there is one element or less |
| **ss**  |	swap a + swap b       |	both sa and sb |
| **ra**  |	rotate a              |	shifts all elements of stack a from bottom to top, the first element of the stack becomes the last |
| **rb**  |	rotate b	            | shifts all elements of stack b from bottom to top, the first element of the stack becomes the last |
| **rr**  | rotate a + rotate b   |	both ra and rb at the same time |
| **rra** |	reverse rotate a	    | shifts all elements of stack a from top to bottom, the last element of the stack becomes the first |
| **rrb** |	reverse rotate b	    | shifts all elements of stack b from top to bottom, the last element of the stack becomes the first |
| **rrr** | reverse rotate        | both rra and rrb at the same time |

## Algorithm

To solve this challenge, we will develop two algorithms. One algorithm tailored to sort three numbers and one algorithm for all cases above three numbers.
Regarding the algorithm for all cases above three numbers, most of the heavy lifting will be done using a sorting by insertion algorithm. 
We will implement a chained list that will allow us to compute for every action the most efficient one. 

**0. The Chained List**  
 
The chained list will be composed of : 
- **value** : the actual int we have to sort.
- **index** : the final position he will occupy once all numbers are sorted.
- **pos** : his actual position in the stack he belongs to.
- **target_pos** : the target position in the stack A where the element of stack B should end up.
- **cost_a** : how many action will be made to pivot the stack A so the target node element ends up at the top of stack A.
- **cost_b** : how many action will be made to pivot the stack B so the current node element ends up at the top of stack B.
- **next** : a *ptr* to the next node of the chained list.

**1. Attributing Indexes**  
When the program launches, the first step will be to fill the stack A with all the values we have to sort. This is when we will be creating the linked list that is associated with the stack A.
When building the first linked list, we will assign to each element an index, for the smallest to the biggest value. The index will start from one to the total number of value inserted in the program.

**2. Choosing an algorithm based on the number of value to sort**  
The same algorithm will be used for value from 500 values to 4 values. But we need a different algorithm for 3 values. Before choosing an algorithm, we must always check if stack A is not already sorted.
If it's not sorted and we have two values: we just have to do an **sa**. 
Else : 

**3. Algorithm to sort three values**  
We have to sort these three numbers in three actions or less. We will never use more than two actions. There are six possibles configurations.
- 1 2 3 : Already sorted.
- 1 3 2 : RRA + SA.
- 2 1 3 : SA.
- 2 3 1 : RRA.
- 3 1 2 : RA.
- 3 2 1 : RA + SA.

The algorithm to sort three values will choose between three actions **RA**, **RRA**, and **SA** based on the position of the biggest number.
- If the index of the first number is the biggest, we use **RA**.
- Else, if the index of the second number is the biggest, we use **RRA**.
- Then, if the index of the first number if greater than the index of the second number, we use **SA**.

**4. Algorithm to sort more than three numbers**  
 To decide which is the most efficiant action to sort each number, we have to calculate the position of each element in his own stack. Then we compare the number of action we must perform to move each element at the top of the stack. Finally we choose the most efficient sequence.
 
We must perform seventh steps, unless stack A is already sorted.
 1. Push to stack B (PB) all elements in stack A except three. 
 2. Sort the three remaining element of stack A.
 As long as we have elements in stack B, we repeat : 
 3. Find the actual position of each element in both stack.
 4. Calculate the target position in stack A where each element of stack B should be.
 5. Calculate the number of action to put each element of stack B to the target position in stack A et choose the most efficient one.
 6. Carry out the action sequence to move the selected element of stack B into stack A. 
 7. If stack A is not correctly sorted, choose either RA or RRA to pivot it until it is ordered.

**Step 1: Sending all numbers of the stack B to the stack A.**    
- Sending all elements of stack B to stack A doesn't mean we have to do it in an unordered way. Thanks to the indexing system we can do a crude sorting in two steps.
- First we send all the small value. If an element has a smaller index than the median of all elements (total number of elements divided by two), we send it to stack B, else, we rotate A. Once we went through the stack once, we just push all remaining elements to stack B except three.

**Step 2: Sort the three remaining element of stack A.**    
We use the algorithm aforementionned to sort the three values.
From here on, we have to run a loop that insert each element of stack B in the right place in stack A. In doing so, we must only select the cheapest set of action for each iteration.

**Step 3: Find the position of each element.**  
Finding the position of an element, is simply finding where he is in the stack: 
| value | index | position |
| ----- | ----- | -------- |
| 111   | 4     | 1        | 
| 0     | 1     | 2        |
| 3     | 2     | 3        |
| 8     | 3     | 4        |

We can obtain the position simply by travelling through the stack from beginning to end and assigning  to each element a position that is incremented step by step. We have to calculate the position of each element in each of the stack. We have to update these position everything we calculate the most efficient sequence of action. 


**Step 4: Find the target position for each element of stack B.**  
The target position is the position for the elements in stack A where they should end up in stack B. It's the position of the element that must end up at the top of the stack when we're going to send this element from stack B to stack A. We can locate this position simply by searching in the stack A the index closest but always superior to the index of the element in the stack B. The position of the element that has this index in stack A will be the target position of our element

**Stack A**
| **value** | **index** | **position** |
| ----- | ----- | -------- |
| 111   | 8     | 1        | 
| 0     | 1     | 2        |
| 3     | 2     | 3        |
| 8     | 5     | 4        |

**Stack B**
| value | index | position | target_pos | 
| ----- | ----- | -------- | ---------- |
| 7     | 4     | 1        | 4          |
| 110   | 7     | 2        | 1          |
| 4     | 3     | 3        | 4          |
| 9     | 6     | 4        | 1          |

**Nota Bene**: If an element of stack B as an index superior to all the element of stack A, we use as a target position the position of the smallest index in stack A.

With theses values we will be able to calculate which element of stack B is the most efficient to move. 

**Step 5: Calculate the most efficient move.**  
Once the position and target position have been calculated, we can find the most efficient move.
For each element of stack B, we want to compute two costs. The first one will be the cost to get the element on top of stack B. The second will be the cost of bringing to bring the target position to the top of stack A. 
In both case we will make a difference for the classic rotate (**ra** and **rb**) and the reverse rotate (**rra** ou **rrb**).

To distinguish between rotate and reverse rotate we calculate first the length of the stack that we divide by two. Then it's easy to know if the position of our element is greater or smaller than the middle of the stack. If it's smaller we use rotate, otherwise we use reverse rotate.
It would be useful to make the cost of the reverse rotate negative. When applying the moves we will only need to look at the sign of the cost to choose between a reverse rotate or a rotate. We can even make a more efficient choice by applying **rr** and **rrr** when the sign of both cost are the same.
Finally, we will compare the cost to move each element of stack B to stack A and choose the most efficient one, the one that cost the less amount of moves. We just have to sum up the absolute values of the cost of each element of stack B and their corresponding target of stack A.

**Stack A**
| **value** | **index** | **position** |
| ----- | ----- | -------- |
| 111   | 8     | 1        | 
| 0     | 1     | 2        |
| 3     | 2     | 3        |
| 8     | 5     | 4        |

**Stack B**
| value | index | position | target_pos | cost_b | cost_a |
| ----- | ----- | -------- | ---------- | ------ | ------ |
| 7     | 4     | 1        | 4          |  1     | -1     |
| 110   | 7     | 2        | 1          | 1      | 0      |
| 4     | 3     | 3        | 4          | -2     | -1     |
| 9     | 6     | 4        | 1          |  -1    | 0      |

**Nota bene**: We don't use swap action (**sa**, **sb**, **ss**) because they do not modify the position of all the elements in the stack.

**Step 6: Execute the sequence of action choosen.**  
We save the cost for the element of stack B and it's target in stack A. The negative or positive cost allows us to know if we use rotate or reverse rotate. We make some moves by using **rrr** when both sign are the same.

**Step 7: Pivot stack A.**  
Once the stack B is empty it does not mean that stack A is ordered. We might need to adjust it using rotate or reverse rotate so that the element with the smallest index is moved at the beginning.
