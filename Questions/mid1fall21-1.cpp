/*
Mr Jonathan is a software engineer in a renowned company as a part of his job responsibility he has to arrange several online meeting with
different stockholders via different platform. unfortunately he forget his zoom password before an important meeting.
But he remembered the number of digits N as well as the sum S of all the digits of his password. he know that his password is the largest number of N digits
 that can be made with given sum S. Help him retrieving his password. 

Example 1:
Input : N= 5, S = 12
Output : 93000

Explanation : Sum of elements is 12 . Largest possible 5 digit number is 93000 with sum 12
*/

#include<bits/stdc++.h>
using namespace std;

int findLargestPassword(int N, int S) {
    // If the sum is not possible with the given number of digits
    if (S > 9 * N) {
        return -1; // Indicate that it's not possible
    }

    int password = 0;

    for (int i = 0; i < N; ++i) {
        // Assign the maximum possible digit (9) to the current position
        int digit = min(9, S);

        // Update the remaining sum and add the digit to the password
        S -= digit;
        password = password * 10 + digit;
    }

    return password;
}

int main() {
    int N = 5;
    int S = 12;

    int result = findLargestPassword(N, S);

    if (result == -1) {
        cout << "Not Possible to form password" << endl;
    } else {
        cout << "The largest password is: " << result << endl;
    }

    return 0;
}
