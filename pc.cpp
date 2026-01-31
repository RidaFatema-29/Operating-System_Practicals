#include <iostream>
using namespace std;

int mutex = 1;
int full = 0;
int empty;
int in = 0, out = 0;
int buffer[50];

int waitS(int s) { return --s; }
int signalS(int s) { return ++s; }

void produce() {
    mutex = waitS(mutex);

    int item;
    cout << "Enter item to produce: ";
    cin >> item;

    buffer[in] = item;
    in = (in + 1) % empty;

    full = signalS(full);
    empty = waitS(empty);

    cout << "Produced: " << item << endl;

    mutex = signalS(mutex);
}

void consume() {
    mutex = waitS(mutex);

    int item = buffer[out];
    out = (out + 1) % empty;

    full = waitS(full);
    empty = signalS(empty);

    cout << "Consumed: " << item << endl;

    mutex = signalS(mutex);
}

int main() {
    int choice;

    cout << "Enter buffer size: ";
    cin >> empty;

    while (true) {
        cout << "\n1. Produce\n2. Consume\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (mutex == 1 && empty > 0)
                    produce();
                else
                    cout << "BUFFER FULL! Cannot produce.\n";
                break;

            case 2:
                if (mutex == 1 && full > 0)
                    consume();
                else
                    cout << "BUFFER EMPTY! Cannot consume.\n";
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}