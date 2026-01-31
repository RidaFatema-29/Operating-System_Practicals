#include <iostream>
using namespace std;

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
int countItems = 0;   // number of items in buffer

void produce() {
    if (countItems == SIZE) {
        cout << "Buffer is FULL! Producer cannot produce.\n";
        // return;
    }
    else{  
    int item;
    cout << "Enter item to produce: ";
    cin >> item;

    buffer[in] = item;
    cout << "Produced " << item << " at buffer[" << in << "]\n";

    in = (in + 1) % SIZE;    // circular increment
    countItems++;
    }
}

void consume() {
    if (countItems == 0) {
        cout << "Buffer is EMPTY! Consumer cannot consume.\n";
        // return;
    }
    else{
    int item = buffer[out];
    cout << "Consumed " << item << " from buffer[" << out << "]\n";

    out = (out + 1) % SIZE;  // circular increment
    countItems--;
    }
}

void display() {
    cout << "\nBuffer: ";
    for (int i = 0; i < SIZE; i++) {
        cout << buffer[i] << " ";
    }
    cout << "\nIn = " << in << " | Out = " << out << " | Items = " << countItems << "\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== PRODUCER - CONSUMER MENU ===\n";
        cout << "1. Produce\n2. Consume\n3. Display Buffer\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: produce(); break;
            case 2: consume(); break;
            case 3: display(); break;
            case 4: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}