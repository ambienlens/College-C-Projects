balance.cpp ->
A bracket is considered to be any one of the following characters: (, ), {, }, [, or ]. Two brackets are
considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing
bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [],
{},and ().
A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example,
{[(])} is not balanced because the contents in between { and } are not balanced. The pair of square
brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single,
unbalanced closing square bracket, ].
By this logic, we say a sequence of brackets is balanced if the following conditions are met:
It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair
of brackets.
Given n strings of brackets, determine whether each sequence of brackets is balanced. If a string is
balanced, return YES. Otherwise, return NO.
SAMPLE INPUT
3
{[()]}
{[(])}
{{[[(())]]}}
SAMPLE OUTPUT
YES
NO
YES

maxsum.cpp ->
You are given a stack of N integers such that the first element represents the top of the stack and the
last element represents the bottom of the stack. You need to pop at least one element from the stack.
At any one moment, you can convert stack into a queue. The bottom of the stack represents the front of
the queue. You cannot convert the queue back into a stack. Your task is to remove exactly K elements
such that the sum of the K removed elements is maximised.
SAMPLE INPUT
10 5
10 9 1 2 3 4 5 6 7 8
SAMPLE OUTPUT
40
Explanation
Pop two elements from the stack. i.e {10,9}
Then convert the stack into queue and remove first three elements from the queue. i.e {8,7,6}.
The maximum possible sum is 10+9+8+7+6 = 40


maxtop.cpp ->
You are given a stack of N integers. In one operation, you can either pop an element from the stack
or push any popped element into the stack. You need to maximize the top element of the stack after
performing exactly K operations. If the stack becomes empty after performing K operations and there is
no other way for the stack to be non-empty, print -1.
SAMPLE INPUT
6 4
1 2 4 3 3 5
SAMPLE OUTPUT
4
Explanation
In 3 operations, we remove 1,2,4 and in the fourth operation, we push 4 back into the stack. Hence, 4 is
the answer.