#ifndef WASHING_H
#define WASHING_H

#include <cstdlib> // Provides std::size_t

class bool_source {
    public:
        // CONSTRUCTOR
        bool_source(double p = 0.5);

        // CONSTANT MEMBER FUNCTION
        bool query() const;

    private:
        double probability; // Probability of query( ) returning true
};

class averager {
    public:
        // CONSTRUCTOR
        averager( );

        // MODIFICATION MEMBER FUNCTION
        void next_number(double value);

        // CONSTANT MEMBER FUNCTIONS
        std::size_t how_many_numbers( ) const { 
            return count;
        }

        double average( ) const;

    private:
        std::size_t count; // How many numbers have been given to the averager
        double sum;
};
// Sum of all the numbers given to the averager

class washer {
    public:
        // CONSTRUCTOR
        washer(unsigned int s = 60);

        // MODIFICATION MEMBER FUNCTIONS
        void one_second( );
        void start_washing( );

        // CONSTANT MEMBER FUNCTION
        bool is_busy( ) const {
            return (wash_time_left > 0);
        }

    private:
        unsigned int seconds_for_wash; // Seconds for a single wash
        unsigned int wash_time_left; // Seconds until the washer is no longer busy
};

#include "washer.cpp"
#endif