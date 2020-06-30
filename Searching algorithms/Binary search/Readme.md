# Binary search

<strong>Binary search</strong>, also known as half-interval search, logarithmic search,<br> or binary chop, is a search algorithm that finds the position<br> of a target value within a sorted array. Binary search compares<br> the target value to the middle element of the array.<br> If they are not equal, the half in which the target cannot<br> lie is eliminated and the search continues on the remaining half,<br> again taking the middle element to compare to the target value, <br>and repeating this until the target value is found.<br> If the search ends with the remaining half being empty, the target is not in the array.

<strong>(This image is taken codecademy to illustrate the working of the algorithm visually)</strong>

![image](https://news.codecademy.com/content/images/2018/10/binary-search-small.gif)

Binary search runs in logarithmic time in the worst case, making<br> <strong>O(log n)</strong> comparisons, where n is the number of elements in the array,<br> the O is Big O notation, and log is the logarithm.<br> Binary search is faster than linear search except for small arrays.<br> However, the array must be sorted first to be able to apply binary search.<br> There are specialized data structures designed for fast searching,<br> such as hash tables, that can be searched more efficiently than binary search.<br> However, binary search can be used to solve a wider range of problems,<br> such as finding the next-smallest or next-largest element in the array relative to the target even <br>if it is absent from the array. 
