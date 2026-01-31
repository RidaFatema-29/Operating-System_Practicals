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

    int frame[10], faults = 0;
    for (int i = 0; i < f; i++) frame[i] = -1;

    cout << "\nOptimal Page Replacement:\n";
    for (int i = 0; i < n; i++) {
        bool hit = false;

        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i]) hit = true;

        if (!hit) {
            int replacePos = -1, farthest = -1;

            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) {
                    replacePos = j;
                    break;
                }

                int k = i + 1;
                while (k < n && frame[j] != pages[k]) k++;

                if (k > farthest) {
                    farthest = k;
                    replacePos = j;
                }
            }

            frame[replacePos] = pages[i];
            faults++;
        }

        for (int j = 0; j < f; j++)
            if (frame[j] == -1) cout << "- ";
            else cout << frame[j] << " ";
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << faults;
}