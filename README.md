# tower-of-hanoi
A pattern-seeking solution to the Tower of Hanoi game.

I tried to look for number patterns in the solution of the Tower of Hanoi game with $\large{n}$ size-different disks.

If we number the stacks in the game $\large{1}$, $\large{2}$ and $\large{3}$ from left to right, then we must move the disks from stack $\large{1}$ to stack $\large{3}$.

The solution for $n=3$ is:

1 3  
1 2  
3 2  
1 3  
2 1  
2 3  
1 3  

Each line describes a disk moved from stack $x$ to stack $y$, so the first line says: move the disk from stack $\large{1}$ to stack $\large{3}$, and so on.  
The solution for $n=4$ is:    

1 2  
1 3  
2 3  
1 2  
3 1  
3 2  
1 2  
1 3  
2 3  
2 1   
3 1  
2 3  
1 2  
1 3  
2 3  

What I first noticed is, that if $\large{n}$ is odd then the first move is always to stack $\large{3}$ and if it was even then the first move is always to stack $\large{2}$. The first
move in the solution is always of the smallest disk. If we write the first move of the other disks it's always from stack $\large{1}$ to either stack $\large{2}$ or stack $\large{3}$.  
We can notice a pattern in the solution for the first move of each disk, if the $\large{i}$'th disk's first move is to stack $\large{2}$, 
then the first move of disk $\large{i+1}$ is to stack $\large{3}$, and otherwise. ($\large{i=1}$ is the smallest disk and $\large{i=n}$ is the largest disk).
For example: for $\large{n=3}$, the first move of disk $\large{1}$ is to stack $\large{3}$, then the first move of disk $\large{2}$ is to stack $\large{2}$ and the first move of 
disk $\large{3}$ is to stack $\large{3}$, and so on.  
Now that we have the first move of each disk, we can calculate all next moves of a particular disk from its first move.  
If $\large{n}$ is odd, then for odd numbered disks ($\large{i}$ is odd): Starting from the first move, the source stack and the destination stack numbers are decreasing by one
each time in cyclic manner. That is, if the first move is (1 3) then the second move is (3 2), so we calculate the next source stack from the previous source stack, and the same for
destination stacks. The operation is clearly mod 3, but since stack numbers are (1, 2, 3), then we have to subtract 1 at first from each stack number so we have (0, 1, 2),
and then we can work with those numbers mod 3, because they maintain their order after applying mod 3 to them and (1, 2, 3) don't.  
So for a stack $\large{x}$, the final operation is $\large{((x-1-1)\\% 3)+1=((x-2)\\% 3)+1}$, we add 1 to return from (0, 1, 2) to (1, 2, 3).
Remember that this operation is only for odd $\large{n}$ and odd numbered disks. But turns out it's also true for even $\large{n}$ and even numbered disks.  
For odd $\large{n}$ and even numbered disks, or even $\large{n}$ and odd numbered disks, the stack number is increasing by 1, and we already subtract 1 for the reason we said
before, so -1 and +1 cancel out and the final operation is: $\large{((x-1+1)\\% 3)+1=(x\\% 3)+1}$.  

We can now calculate the moves of the disks, but we don't know the order of the moves (in each move, we don't which disk is moving so we can't just calculate any move blindly).  

**Remember, until now we know each disk's first move, and we know how to calculate the remaining moves using the first moves.**  

Here's the order of disk moves for $\large{n=5}$ :  $\hspace{5pt}$    1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1  
for $\large{n=6}$ :   $\hspace{5pt}$     1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 6 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1  

Each number is the number of the moved disk. We can notice a pattern here of $\large{ 1 \hspace{5pt} 2 \hspace{5pt} 1}$ 
then some number $\large{x}$.  
$\large{x}$ is not random, if we consider every occurence of $\large{ 1 \hspace{5pt} 2 \hspace{5pt} 1 \hspace{5pt} x}$ as one block,
then for blocks ($\large{1, 3, 5, 7, ...}$), we have $\large{x=3}$, and for blocks ($\large{2, 6, 10, 14, ...}$), we have $\large{x=4}$, and for blocks ($\large{4, 12, 20, 28, ...}$)
, we have $\large{x=5}$.  
Notice that the first block in which $\large{x=3}$ occurs is $\large{2^0=1}$, and the first block in which $\large{x=4}$ occurs is $\large{2^1=2}$, and so on.  
So if a block's number is $\large{y=2^i ; i\in \mathbb{N}}$, then $\large{x=3+i}$.  
Notice also the difference between each consecutive block for each $\large{x}$, when $\large{x=3}$ we have $\large{(3-1)=(5-3)=(7-5)=2=2^1}$. For $\large{x=4}$, we have
$\large{(6-2)=(10-6)=(14-10)=4=2^2}$, and so on.  
So, the first block for a particular $\large{x}$ is given by $\large{2^i}$, and the all other blocks that have this particular $\large{x}$ are
calculated from $\large{y=2^i+2^{i+1}\times a \hspace{10pt} ... (1)}$ where $\large{a \in \mathbb{N}}$.  
So to calculate $\large{x}$, we need to find integer $\large{i}$ that results in integer $\large{a}$ in equation $\large{(1)}$, and then we substitute the value of $\large{i}$
in $\large{x=3+i}$.  
To do that we iterate over $\large{i=0,1,2,...,n-1}$ and check if $\large{(y-2^i)\\% (2^{i+1})=0}$, if it is then this is our $\large{i}$.  
Now we know the order of every move, we can iterate over the array of moved disks and calculate next moves.  
See attached file "main.cpp" for implementation.  
