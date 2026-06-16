#include <iostream>
#include <vector>
#include <limits>
#include "arraystack.cpp"
#include "ring.cpp"

void printTower(const ArrayStack<Ring>& tower, int towerNum) {
    std::cout << "Tower " << towerNum << ": ";
    if (tower.empty()) {
        std::cout << "[Empty]" << std::endl;
        return;
    }

    std::vector<Ring> tempTower;
    ArrayStack<Ring> towerCopy = tower;

    while (!towerCopy.empty()) {
        Ring currentRing = towerCopy.pop();
        tempTower.push_back(currentRing);
    }

    for (int i = tempTower.size() - 1; i >= 0; --i) {
        std::cout << tempTower[i].size << " ";
    }

    std::cout << std::endl;
}

std::string genline(int number_of_lines, int max){
    std::string lline;
    for(int i = 0; i < max - number_of_lines; i++){
        lline = lline + " ";
        std::cout << i;
    }
    for(int i = 0; i < number_of_lines; i++){
        lline = lline + "-";
        std::cout << i;
    }
    return lline;
}

std::string pline(int max){
    std::string sspa;
    for(int i = 0; i < max; i++){
        sspa = sspa + "_";
    }
    return sspa;
}

std::string spaces(int max){
    std::string sspa;
    for(int i = 0; i < max; i++){
        sspa = sspa + " ";
    }
    return sspa;
}

std::string parseline(int maxring, int k){
    std::string spa = "|";
    if(k != 0){
        spa = "_";
    }
    return spaces(maxring - k) + pline(k) + spa + pline(k) + spaces(maxring - k);
}

void printillus(const ArrayStack<Ring>& tower1, const ArrayStack<Ring>& tower2, const ArrayStack<Ring>& tower3, int maxring){
    ArrayStack<Ring> tower1Copy2 = tower1;
    ArrayStack<Ring> tower2Copy2 = tower2;
    ArrayStack<Ring> tower3Copy2 = tower3;

    ArrayStack<Ring> tower1Copy;
    while (!tower1Copy2.empty()) {
        Ring currentRing = tower1Copy2.pop();
        tower1Copy.push(currentRing);
    }
    ArrayStack<Ring> tower2Copy;
    while (!tower2Copy2.empty()) {
        Ring currentRing = tower2Copy2.pop();
        tower2Copy.push(currentRing);
    }
    ArrayStack<Ring> tower3Copy;
    while (!tower3Copy2.empty()) {
        Ring currentRing = tower3Copy2.pop();
        tower3Copy.push(currentRing);
    }

    int tower1arr[maxring];
    int tower2arr[maxring];
    int tower3arr[maxring];

    int index = 0;

    while (!tower1Copy.empty()) {
        Ring currentRing = tower1Copy.pop();
        tower1arr[index] = currentRing.size;
        index++;
    }
    for(int i = 0; i < maxring - index; i++){
        tower1arr[index + i] = 0;
    }
    index = 0;
    while (!tower2Copy.empty()) {
        Ring currentRing = tower2Copy.pop();
        tower2arr[index] = currentRing.size;
        index++;
    }
    for(int i = 0; i < maxring - index; i++){
        tower2arr[index + i] = 0;
    }
    index = 0;
    while (!tower3Copy.empty()) {
        Ring currentRing = tower3Copy.pop();
        tower3arr[index] = currentRing.size;
        index++;
    }
    for(int i = 0; i < maxring - index; i++){
        tower3arr[index + i] = 0;
    }
    index = 0;

    for(int i = maxring + 1; i >= 0; i--){
        int j = maxring - i + 1;
        int k = maxring - j - 1;
        if(i == 1){
            std::cout << spaces(maxring - 3) << "Tower 1" << spaces(maxring - 2) << "    ~    ";
            std::cout << spaces(maxring - 3) << "Tower 2" << spaces(maxring - 2) << "    ~    ";
            std::cout << spaces(maxring - 3) << "Tower 3" << spaces(maxring - 2) << std::endl;
            break;
        }

        // std::cout << "Debug: " << maxring << " " << j << " " << k << std::endl;

        std::cout << parseline(maxring, tower1arr[k]) << "    ~    ";
        std::cout << parseline(maxring, tower2arr[k]) << "    ~    ";
        std::cout << parseline(maxring, tower3arr[k]) << std::endl;

        // std::cout << spaces(maxring - tower1arr[k]) << pline(tower1arr[k]) << "||" << pline(tower1arr[k]) << spaces(maxring - tower1arr[k]) << "    ~    ";
        // std::cout << spaces(maxring - tower2arr[k]) << pline(tower2arr[k]) << "||" << pline(tower2arr[k]) << spaces(maxring - tower2arr[k]) << "    ~    ";
        // std::cout << spaces(maxring - tower3arr[k]) << pline(tower3arr[k]) << "||" << pline(tower3arr[k]) << spaces(maxring - tower3arr[k]) << std::endl;
        // break;
        // if(i == maxring){
        //     std::cout << spaces(maxring) << "Tower 1" << spaces(maxring) << "|" << spaces(maxring) << "Tower 2" << spaces(maxring) << "|" << spaces(maxring) << "Tower 3" << spaces(maxring) << std::endl;
        // }
        // std::cout << genline(tower1arr[i], maxring) << "|" << genline(tower2arr[i], maxring) << "|" << genline(tower3arr[i], maxring) << std::endl;
        // break;
    }

}

void printGameState(const ArrayStack<Ring>& tower1, const ArrayStack<Ring>& tower2, const ArrayStack<Ring>& tower3, int max, int moves) {
    system("cls");
    printillus(tower1, tower2, tower3, max);
    // printTower(tower1, 1);
    // printTower(tower2, 2);
    // printTower(tower3, 3);
    std::cout << "----------------\n";
    std::cout << "Number of moves: " << moves << std::endl;
    // std::cout << "debug 1:\n";
}

void moveRing(ArrayStack<Ring>& source, ArrayStack<Ring>& destination) {
    if (source.empty()) {
        std::cout << "Invalid Move: Source tower is empty." << std::endl;
        return;
    }
    if (!destination.empty() && source.top().size > destination.top().size) {
        std::cout << "Invalid Move: You cannot put a bigger ring on a smaller ring." << std::endl;
        return;
    }

    Ring ring = source.pop();
    destination.push(ring);
}

void playHanoi(ArrayStack<Ring>& tower1, ArrayStack<Ring>& tower2, ArrayStack<Ring>& tower3, int numRings) {
    int moves = 0;
    while (tower3.size() != numRings) {
        printGameState(tower1, tower2, tower3, numRings, moves);

        int fromTower, toTower;
        std::cout << "Enter the tower to move FROM (1, 2, 3): ";
        std::cin >> fromTower;
        std::cout << "Enter the tower to move TO (1, 2, 3): ";
        std::cin >> toTower;

        ArrayStack<Ring>* source = nullptr;
        ArrayStack<Ring>* destination = nullptr;

        if (fromTower == 1) source = &tower1;
        else if (fromTower == 2) source = &tower2;
        else if (fromTower == 3) source = &tower3;

        if (toTower == 1) destination = &tower1;
        else if (toTower == 2) destination = &tower2;
        else if (toTower == 3) destination = &tower3;

        if (source && destination) {
            moveRing(*source, *destination);
            moves++;
        } else {
            std::cout << "Invalid tower selection. Please try again." << std::endl;
        }
    }

    std::cout << "Congratulations! You completed the game in " << moves << " moves!" << std::endl;
    std::cout << "Press enter to exit!" << std::endl;
    char next;
    do
        std::cin.get(next);
    while (next != '\n');
}

int main() {
    int numRings = 0;

    std::cout << "Enter the number of rings: ";
    std::cin >> numRings;
    if (numRings < 1) {
        std::cout << "Invalid number of rings. The minimum rings is 1." << std::endl;
        return 1;
    }

    ArrayStack<Ring> tower1;
    ArrayStack<Ring> tower2;
    ArrayStack<Ring> tower3;

    for (int i = numRings; i >= 1; --i) {
        tower1.push(Ring(i));
    }

    playHanoi(tower1, tower2, tower3, numRings);

    return 0;
}
