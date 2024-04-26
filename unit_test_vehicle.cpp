#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vehicle.h"
#include <sstream>



TEST_CASE("Testing Electric Vehicle") {
    ElectricVehicle ev(1000, 0.6);  

    SUBCASE("Test Electric Vehicle cost of fuel") {
        CHECK(ev.costOfFuel() == doctest::Approx(0.6 * 0.13));
    }

    
}

TEST_CASE("Testing Gasoline Vehicle") {
    GasolineVehicle gv(1200, 20);  

    SUBCASE("Test Gasoline Vehicle cost of fuel") {
        CHECK(gv.costOfFuel() == doctest::Approx(20 * 3.50));
    }


}

TEST_CASE("Testing Hybrid Vehicle") {
    Hybrid hybrid(1500, 0.5, 30);  

    SUBCASE("Test Hybrid cost of fuel") {
        CHECK(hybrid.costOfFuel() == doctest::Approx((0.5 * 0.13 + 30 * 3.50) / 2));
    }

   
}
