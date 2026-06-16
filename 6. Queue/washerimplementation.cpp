#include <iostream>
#include "queue.cpp"
#include "washerupdated.cpp"
#include <cassert>
#include <cstdlib>

using namespace std;

// Function to simulate the car wash
void car_wash_simulate(unsigned int wash_time, double arrival_prob, unsigned int total_time) {
    Queue<unsigned int> arrival_times; // Time stamps of the waiting customers
    unsigned int next;
    bool_source arrival(arrival_prob);
    washer machine(wash_time);
    averager wait_times;
    unsigned int current_second;

    // Write the parameters to cout
    cout << "Seconds to wash one car: " << wash_time << endl;
    cout << "Probability of customer arrival during a second: " << arrival_prob << endl;
    cout << "Total simulation seconds: " << total_time << endl;

    for (current_second = 1; current_second <= total_time; ++current_second) {
        // Simulate the passage of one second of time
        // Check whether a new customer has arrived
        if (arrival.query())
            arrival_times.push(current_second);

        // Check whether we can start washing another car
        if ((!machine.is_busy()) && (!arrival_times.empty())) {
            next = arrival_times.front();
            arrival_times.pop();
            wait_times.next_number(current_second - next);
            machine.start_washing();
        }

        // Tell the washer to simulate the passage of one second
        machine.one_second();
    }

    // Write the summary information about the simulation
    cout << "Customers served: " << wait_times.how_many_numbers() << endl;
    if (wait_times.how_many_numbers() > 0)
        cout << "Average wait: " << wait_times.average() << " sec" << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    unsigned int wash_time = 240;
    double arrival_prob = 0.0025;
    unsigned int total_time = 6000;

    car_wash_simulate(wash_time, arrival_prob, total_time);
    return 0;
}
