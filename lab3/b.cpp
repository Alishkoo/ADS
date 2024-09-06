#include <iostream>
using namespace std;

int main()
{
    // Input: n (number of elements), k (maximum groups), and the sequence of numbers
    int n, k;
    cin >> n >> k;
    int sequence[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    // Binary search setup
    long long left = 0, right = 1e15, mid, countGroups, groupSum;

    // Binary search loop
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        countGroups = 1;
        groupSum = 0;

        // Try to group the sequence based on the current threshold (mid)
        for (int i = 0; i < n; i++)
        {
            if (mid < groupSum + sequence[i])
            {
                // Start a new group
                groupSum = 0;
                countGroups++;
            }
            if (mid < sequence[i])
            {
                // A single element exceeds the threshold; not possible
                countGroups = k + 1;
                break;
            }
            groupSum += sequence[i];
        }

        // Adjust the threshold based on the number of groups formed
        if (k < countGroups)
        {
            left = mid + 1; // Threshold is too small
        }
        else
        {
            right = mid - 1; // Threshold might be too large
        }
    }

    // Output the minimum threshold
    cout << left;

    return 0;
}
