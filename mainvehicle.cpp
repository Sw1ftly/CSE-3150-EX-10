#include "Vehicle.h"

int main() {
    Hybrid myHybrid(1500, 0.5, 30); 
    myHybrid.start();
    std::cout << "Cost of fuel: $" << myHybrid.costOfFuel() << " per unit." << std::endl;
    myHybrid.stop();
    return 0;
}