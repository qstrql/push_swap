
42's push_swap
Grade : 125/125 !
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.
How to use :
- Clone this repo
- make
- ./push_swap <numbers> (Note : any number from INT_MIN to INT_MAX)
- make bonus
- ARG="5 1 2 6 8 4 3 7 9 0"; ./push_swap $ARG | ./checker $ARG

[![qstrql's github activity graph](https://activity-graph.herokuapp.com/graph?username=qstrql)](https://github.com/ashutosh00710/github-readme-activity-graph)

The rules :
You have 2 stacks named a and b. At the beginning, stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. The stack b is empty.
The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.
