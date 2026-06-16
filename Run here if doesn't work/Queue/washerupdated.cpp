#ifndef WASHINGUPDATED_H
#define WASHINGUPDATED_H

#include <cassert>
#include <cstdlib> // Provides std::size_t

class bool_source {
    public:
        // CONSTRUCTOR
        bool_source(double p = 0.5){
            assert(p >= 0);
            assert(p <= 1);
            probability = p;

        }

        // CONSTANT MEMBER FUNCTION
        bool query() const{
            return (rand() < probability * RAND_MAX);
        }

    private:
        double probability; // Probability of query( ) returning true
};

class averager {
    public:
        // CONSTRUCTOR
        averager( ){
            count = 0;
            sum = 0;
        }

        // MODIFICATION MEMBER FUNCTION
        void next_number(double value){
            ++count;
            sum += value;
        }

        // CONSTANT MEMBER FUNCTIONS
        std::size_t how_many_numbers( ) const { 
            return count;
        }

        double average( ) const{
            assert(how_many_numbers( ) > 0);
            return sum/count;
        }

    private:
        std::size_t count; // How many numbers have been given to the averager
        double sum; // Sum of all the numbers given to the averager
};

class washer {
    public:
        // CONSTRUCTOR
        washer(unsigned int s = 60){
            seconds_for_wash = s;
            wash_time_left = 0;
        }

        // MODIFICATION MEMBER FUNCTIONS
        void one_second( ){
            if (is_busy( ))--wash_time_left;
        }
        void start_washing( ){
            assert(!is_busy( ));
            wash_time_left = seconds_for_wash;
        }

        // CONSTANT MEMBER FUNCTION
        bool is_busy( ) const {
            return (wash_time_left > 0);
        }

    private:
        unsigned int seconds_for_wash; // Seconds for a single wash
        unsigned int wash_time_left; // Seconds until the washer is no longer busy
};

// #include "washer.cpp"
#endif