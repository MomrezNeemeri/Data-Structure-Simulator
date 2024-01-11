#include "DataStructure.h"

void DataStructureSimulator::handleEvents() {

}

void DataStructureSimulator::render() {

}
void DataStructureSimulator::update() {

}
void DataStructureSimulator::run() {

}

vector<int> DataStructureSimulator::getInputArray() {
    std::vector<int> inputArray;
    int totalnumber;
    std::cout << "Enter the total number of elements: ";
    std::cin >> totalnumber;

    while (totalnumber--) {
        int i;
        std::cout << "Enter element: ";
        std::cin >> i;
        inputArray.push_back(i);
    }

    return inputArray;
}