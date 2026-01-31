#include <iostream>
using namespace std;

int main() {
    int n, f;
    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;

    int frame[10], lastUsed[10], faults = 0, time = 0;

    for (int i = 0; i < f; i++) frame[i] = lastUsed[i] = -1;

    cout << "\nLRU Page Replacement:\n";
    for (int i = 0; i < n; i++) {
        bool hit = false;
        time++;

        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i]) {
                hit = true;
                lastUsed[j] = time;
            }

        if (!hit) {
            int lru = 0;
            for (int j = 1; j < f; j++)
                if (lastUsed[j] < lastUsed[lru])
                    lru = j;

            frame[lru] = pages[i];
            lastUsed[lru] = time;
            faults++;
        }

        for (int j = 0; j < f; j++)
            if (frame[j] == -1) cout << "- ";
            else cout << frame[j] << " ";
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << faults;
}