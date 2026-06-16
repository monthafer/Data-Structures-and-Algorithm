#include <iostream>
#include <chrono>
#include <thread>

int main() {
	std::cout << "Test" << std::endl	;
    std::cout << "This will be erased." << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    std::cout << "\b\b yes" << std::flush;
    return 0;
}

