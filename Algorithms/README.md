O (big O notation): order of the upper bound. 
    Examples:
        O(n)
        O(n log n)
        O(n²)
        O(log n)
        O(1)
Ω (big omega): order of the lower bound.
    Examples:
        Ω(n)
        Ω(n log n)
        Ω(n²)
        Ω(log n)
        Ω(1)
Θ (big theta): O and Ω are the same.
    Examples:
        Θ(n)
        Θ(n log n)
        Θ(n²)
        Θ(log n)
        Θ(1)

The larger the mathematical expression, the slower your algorithm will be
because it'll take more steps.

==========================================================================
Linear search: O(n) Ω(1)
- Searches one by one

==========================================================================
Binary search: O(log n) Ω(1)
- Look for the middle number.
- If the number we want is bigger than the number we found, search the right half.
Otherwise, search the left half.
- Continue.

Example: We have an array [0, 1, 2, 3, 4, 5, 6], and we want to search for the 5 number.
- Search middle: 3
- 5 is > than 3. Get middle of right half. Right half = [4, 5, 6] middle of right half = 5.
- Found!

==========================================================================
Selection Sort algorithm: O(n²) Ω(n²) Θ(n²)
for i from 0 to n-1:
  find the smallest number in this range
  swap it with the number at i (number[i])

==========================================================================
Bubble Sort algorithm: O(n²) Ω(n)
repeat (n-1) times:
  for i from 0 to (n-2):
    if numbers[i] and numbers[i+1] out of order:
      swap then
  if no swaps:
    quit

==========================================================================
Merge Sort algorithm: O(n log n) Ω(n log n) Θ(n log n)
If only one number:
  Quit
Else:
  Sort left half of numbers
  Sort right half of numbers
  Merge sorted halves
