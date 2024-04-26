#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>


class Vehicle {
public:
    double weight;

    Vehicle(double w) : weight(w) {}
    virtual ~Vehicle() {}

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual double costOfFuel() = 0;
};


class ElectricVehicle : virtual public Vehicle {
protected:
    double electricEfficiency; 

public:
    ElectricVehicle(double w, double efficiency) : Vehicle(w), electricEfficiency(efficiency) {}

    void start() override {
        std::cout << "Electric Vehicle starting." << std::endl;
    }

    void stop() override {
        std::cout << "Electric Vehicle stopping." << std::endl;
    }

    double costOfFuel() override {
        return electricEfficiency * 0.13; 
    }
};


class GasolineVehicle : virtual public Vehicle {
protected:
    double fuelEfficiency; 

public:
    GasolineVehicle(double w, double efficiency) : Vehicle(w), fuelEfficiency(efficiency) {}

    void start() override {
        std::cout << "Gasoline Vehicle starting." << std::endl;
    }

    void stop() override {
        std::cout << "Gasoline Vehicle stopping." << std::endl;
    }

    double costOfFuel() override {
        return fuelEfficiency * 3.50; 
    }
};


class Hybrid : public ElectricVehicle, public GasolineVehicle {
public:
    Hybrid(double w, double electricEff, double gasEff)
        : Vehicle(w), ElectricVehicle(w, electricEff), GasolineVehicle(w, gasEff) {}

    void start() override {
        ElectricVehicle::start(); 
        GasolineVehicle::start(); 
    }

    void stop() override {
        ElectricVehicle::stop();
        GasolineVehicle::stop();
    }

    double costOfFuel() override {
        return (ElectricVehicle::costOfFuel() + GasolineVehicle::costOfFuel()) / 2;
    }
};

#endif