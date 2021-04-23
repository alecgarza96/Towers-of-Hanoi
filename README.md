# Towers-of-Hanoi
ToH implementation with Linked List based Stack

Towers of Hanoi requires shifting disks amongst three different towers (source, temporary, destination). The goal is to move all disks from the the first tower to the third tower. Constraints to be followed are that only one disk may be moved at a time, and a disk can only be placed on top of another disk if it has a smaller diameter than the disk that it is trying to placed on top of.

We are going to utilize an iterative approach. We will need to find out the number of moves needing to be made in order to determine how long our loop runs; we can use the formula (2^n)-1. 

Next, we determine if the number of disks is even or odd, as we will have different strategies for each approach. If the number of disks is even, we can interchange the the destination tower and the temporary tower. However, we will not implement that approach here for the sake of simplicity and a general introduction to the algorithm.

Algorithm:

constraints:
- only one disk can be moved at a time
- disk cannot be placed on top of smaller sized disk

create 3 stack objects to represent three different towers

total number of moves = (2^n)-1

If the number of disks is even:
  for i=1 and while i is less than total number of moves:
      if i%3==1:
        move disks between source tower and temporary tower according to constraints
      else if i%3==2
        move disks between source tower and destination tower according to constraints
      else if 1%3==0:
        move disks between temporary tower and destination tower according to constriaints
Else if the number of disks is odd:
  for i=1 and while i is less than total number of moves:
      if i%3==1:
        move disks between source tower and destination tower according to constraints
      else if i%3==2
        move disks between source tower and temporary tower according to constraints
      else if 1%3==0:
        move disks between temporary tower and destination tower according to constriaints
