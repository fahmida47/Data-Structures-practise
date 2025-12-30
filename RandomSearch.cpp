/// Random Search 

// With Replacement

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[] = {5, 12, 7, 19, 25, 30};  // Input array
    int n = 6;                         // Size of array
    int x = 19;                        // Target value

    srand(time(0));  // Random seed

    int i;  // index

    // 1. Do
    do {
        // 2. i = Random_Select()
        i = rand() % n;

        // 3. IF A[i] == x
        if (A[i] == x) {
            // 4. return i
            cout << "Found at index: " << i << endl;
            return 0;
        }

        // 5. End IF
        // 6. While A[i] != x
    } while (A[i] != x);

    return 0;
}
