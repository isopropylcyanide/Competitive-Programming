// C program to show segment tree operations like construction, query
// and update
#include <stdio.h>
#include <math.h>

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }

/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.

    st    --> Pointer to segment tree
    si    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    l & r  --> Starting and ending indexes of the segment represented
                 by current node, i.e., st[si]
    s & e  --> Starting and ending indexes of query range */
int getSumUtil(int *st, int l, int r, int s, int e, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (s <= l && e >= r)
        return st[si];

    // If segment of this node is outside the given range
    if (r < s || l > e)
        return 0;

    // If a part of this segment overlaps with the given range
    int mid = getMid(l, r);
    return getSumUtil(st, l, mid, s, e, 2*si+1) +
           getSumUtil(st, mid+1, r, s, e, 2*si+2);
}

/* A recursive function to update the nodes which have the given
   index in their range. The following are parameters
    st, si, l and r are same as getSumUtil()
    i    --> index of the element to be updated. This index is
             in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(int *st, int l, int r, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    if (i < l || i > r)
        return;

    // If the input index is in range of this node, then update
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (r != l)
    {
        int mid = getMid(l, r);
        updateValueUtil(st, l, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, r, i, diff, 2*si + 2);
    }
}

// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }

    // Get the difference between new value and old value
    int diff = new_val - arr[i];

    // Update the value in array
    arr[i] = new_val;

    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

// Return sum of elements in range from index s (quey start)
// to e (query end).  It mainly uses getSumUtil()
int getSum(int *st, int n, int s, int e)
{
    // Check for erroneous input values
    if (s < 0 || e > n-1 || s > e)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(st, 0, n-1, s, e, 0);
}

// A recursive function that constructs Segment Tree for array[l..r].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int l, int r, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (l == r)
    {
        st[si] = arr[l];
        return arr[l];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(l, r);
    st[si] =  constructSTUtil(arr, l, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, r, st, si*2+2);
    return st[si];
}

/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree

    //Height of segment tree
    int x = (int)(ceil(log2(n)));

    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;

    // Allocate memory
    int *st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);

    // Return the constructed segment tree
    return st;
}

// Driver program to test above functions
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    int *st = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
            getSum(st, n, 1, 3));

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(arr, st, n, 1, 10);

    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
             getSum(st, n, 1, 3));
    return 0;
}
