// Mason Ayala
// Practice 10 - Gradebook Tools

#include <iostream>
using namespace std;

void curve(int scores[], int n, int points)
{
    for (int i = 0; i < n; i++)
    {
        scores[i] += points;
    }
}

void minMax(const int scores[], int n, int& lo, int& hi)
{
    lo = scores[0];
    hi = scores[0];

    for (int i = 1; i < n; i++)
    {
        if (scores[i] < lo)
            lo = scores[i];

        if (scores[i] > hi)
            hi = scores[i];
    }
}

bool findScore(const int scores[], int n, int target, int* where)
{
    for (int i = 0; i < n; i++)
    {
        if (scores[i] == target)
        {
            if (where != nullptr)
                *where = i;

            return true;
        }
    }

    return false;
}

int main()
{
    int scores[5] = {72, 88, 95, 60, 81};
    int lo, hi;
    int index;

    cout << "Before: ";
    for (int i = 0; i < 5; i++)
        cout << scores[i] << " ";
    cout << "\n";

    minMax(scores, 5, lo, hi);
    cout << "Low: " << lo << " High: " << hi << "\n";

    curve(scores, 5, 5);

    cout << "After curve +5: ";
    for (int i = 0; i < 5; i++)
        cout << scores[i] << " ";
    cout << "\n";

    if (findScore(scores, 5, 100, &index))
        cout << "100 found at index " << index << "\n";

    if (!findScore(scores, 5, 50, nullptr))
        cout << "50 not found\n";

    return 0;
}
