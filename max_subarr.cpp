#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// MAXIMUM SUM SUBARRAY

ostream& operator<< (ostream& os,vector<int> & arr){
    // overload ostream operator for easy output
    for(auto elem : arr)
        os<<elem<<" ";
    os<<endl;
    return os;
}


// O(n^2)
tuple<int, int, int> bruteForcemax(const int& low, const int &high, const vector<int> & arr){

    int maxSum = 0, temp, maxLow, maxHigh;

    for(int i = low; i < high; i++){
        temp = arr[i];
        for (int j = i + 1 ; j <= high; j++){

            temp += arr[j];
            if (temp > maxSum){
                maxSum = temp;
                maxLow = i;
                maxHigh = j;
            }
        }
    }
    return make_tuple(maxLow, maxHigh, maxSum);
}

 tuple<int, int, int> divideConqMaxCrossing(const int & low, const int & mid, const int & high, const vector<int> & arr){
    // Combines the max sum subarray from low..mid and mid +1 .. high
    // returns the indices that make up the crossing subarray and return their crossing sum

    int leftSum = INT_MIN, leftMax;
    int sum = 0;

    //Now do the same brute force step as we did earlier
    // The arrerence lies in the fact that we are now very deep in recursion
    // at a point where this brute is the only efficient way
    for (int i = mid; i >= low; i--){
        sum += arr[i];
        if (sum >=  leftSum){
            leftSum = sum;
            leftMax = i;
        }
    }

    int rightSum = INT_MIN, rightMax;
    sum = 0;

    for (int i = mid + 1; i <= high; i++){
        sum += arr[i];
        if (sum >= rightSum){
            rightSum = sum;
            rightMax = i;
        }
    }

    return make_tuple(leftMax, rightMax, leftSum + rightSum);
 }

 // O(nlogn)
 tuple<int,int,int> divideConqMax(const int & low, const int & high, const vector<int> & arr){
    // Procedure to find max SUBARRAY sum using divide and conquer
    // Find sum either in left half, right half, or crossing sum
    // recur until the array is of a single size
    if (high == low)
        return make_tuple(low, high, arr[low]);

    else{
        int mid = (low + high)/2;
        int leftLow, leftHigh, leftSum;
        int rightLow, rightHigh, rightSum;
        int crossLow, crossHigh, crossSum;

        tie(leftLow, leftHigh, leftSum) =  divideConqMax(low, mid, arr);
        tie(rightLow, rightHigh, rightSum) = divideConqMax(mid +1, high, arr);
        tie(crossLow, crossHigh, crossSum) = divideConqMaxCrossing(low, mid, high, arr);

        if (leftSum >= rightSum && leftSum >= crossSum)
            return make_tuple(leftLow, leftHigh, leftSum);

        else if (rightSum >= leftSum && rightSum >= crossSum)
            return make_tuple(rightLow, rightHigh, rightSum);

        else return make_tuple(crossLow, crossHigh, crossSum);
    }
}

// O(n) Kadane's Algorithm
tuple<int, int, int> linearMax(const int & low, const int & high, const vector<int> & arr){

    // Max subaaray of A[i..j+1] is either A[i..j] or A[i..j + 1]
    int max_so_far = 0, max_ending_here = 0;
    int max_index = 0;

    for (int i = low; i <= high; i++){
        max_ending_here += arr[i];

        if (max_ending_here < 0)
            max_ending_here = 0;

        if (max_ending_here > max_so_far){
            max_index = i;
            max_so_far = max_ending_here;
        }
    }

    int temp = 0, low_index = max_index;
    for (int i = max_index; i >= low; i--){

        temp += arr[i];
        if (temp < max_so_far)
            low_index -= 1;

        if (temp == max_so_far)
            break;
    }
    return make_tuple(low_index, max_index, max_so_far);
}

int main(){

    int n,lower,upper,maxSum;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    tie(lower, upper, maxSum) =  bruteForcemax(0, n- 1, arr);
    cout<<"\nMax Sum (Brute): "<<maxSum<<" occuring between "<<lower +1<<" and "<<upper +1<<endl;

    tie(lower, upper, maxSum) = divideConqMax(0, n -1, arr);
    cout<<"\nMax Sum (Divide): "<<maxSum<<" occuring between "<<lower +1<<" and "<<upper +1<<endl;

    tie(lower, upper, maxSum) =  linearMax(0, n- 1, arr);
    cout<<"\nMax Sum (Linear): "<<maxSum<<" occuring between "<<lower +1<<" and "<<upper +1<<endl;


    return 0;
}
