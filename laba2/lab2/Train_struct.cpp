#include "Train_struct.h"
using namespace std;

void Train::scheduleInput() {
    cout << "Enter train number: ";
    cin >> number;
    cout << "Enter direction: ";
    cin >> direction;
    cout << "Enter departure time (hh:mm): ";
    cin >> departureTime;
    cout << "Enter arrival time (hh:mm): ";
    cin >> arrivalTime;
}

void Train::printSchedule() {
    cout << setw(10) << left << number;
    cout << setw(30) << left << direction;
    cout << setw(20) << left << departureTime;
    cout << setw(20) << left << arrivalTime << endl;
}
