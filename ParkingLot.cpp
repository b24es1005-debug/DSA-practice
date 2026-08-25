#include <iostream>
#include <vector>
#include <string>
using namespace std;

// A vehicle or parking spot can only be COMPACT or LARGE
enum class VehicleSize {
    COMPACT,
    LARGE
};

// Base class containing properties common to all vehicles
class Vehicle {
protected:
    string licensePlate;
    VehicleSize size;

public:
    // Every vehicle has a license plate and size
    Vehicle(string plate, VehicleSize s) {
        licensePlate = plate;
        size = s;
    }

    // Virtual destructor ensures proper cleanup through a base class pointer
    virtual ~Vehicle() = default;

    // Returns the size of the vehicle
    VehicleSize getSize() {
        return size;
    }

    // Returns the license plate of the vehicle
    string getLicensePlate() {
        return licensePlate;
    }
};

// Car inherits common properties from Vehicle
class Car : public Vehicle {
public:
    // Every car is COMPACT
    Car(string plate) : Vehicle(plate, VehicleSize::COMPACT) {}
};

// Truck inherits common properties from Vehicle
class Truck : public Vehicle {
public:
    // Every truck is LARGE
    Truck(string plate) : Vehicle(plate, VehicleSize::LARGE) {}
};

// Represents one parking spot
class ParkingSpot {
private:
    int spotNumber;
    VehicleSize spotSize;

    // Stores the vehicle currently parked here
    // nullptr means the spot is empty
    Vehicle* vehicle = nullptr;

public:
    ParkingSpot(int number, VehicleSize size) {
        spotNumber = number;
        spotSize = size;
    }

    // A spot is available if no vehicle is parked in it
    bool isAvailable() {
        return vehicle == nullptr;
    }

    // Checks whether the given vehicle can fit in this spot
    bool canFit(Vehicle* v) {
        // Cannot park if the spot is already occupied
        if (!isAvailable())
            return false;

        // A LARGE vehicle cannot fit in a COMPACT spot
        if (v->getSize() == VehicleSize::LARGE &&
            spotSize == VehicleSize::COMPACT)
            return false;

        return true;
    }

    // Parks the vehicle if it can fit
    bool park(Vehicle* v) {
        if (!canFit(v))
            return false;

        vehicle = v;
        return true;
    }

    // Removes the currently parked vehicle
    void removeVehicle() {
        vehicle = nullptr;
    }

    // Returns the parking spot number
    int getSpotNumber() {
        return spotNumber;
    }
};

// Manages all the parking spots
class ParkingLot {
private:
    // Stores all parking spots in the parking lot
    vector<ParkingSpot> spots;

public:
    // Creates the required number of compact and large spots
    ParkingLot(int compactSpots, int largeSpots) {
        int id = 1;

        // Add compact parking spots
        for (int i = 0; i < compactSpots; i++) {
            spots.push_back(ParkingSpot(id++, VehicleSize::COMPACT));
        }

        // Add large parking spots
        for (int i = 0; i < largeSpots; i++) {
            spots.push_back(ParkingSpot(id++, VehicleSize::LARGE));
        }
    }

    // Finds the first available spot where the vehicle can fit
    void parkVehicle(Vehicle* vehicle) {
        for (auto& spot : spots) {

            // Try parking the vehicle in the current spot
            if (spot.park(vehicle)) {
                cout << vehicle->getLicensePlate()
                     << " parked at spot "
                     << spot.getSpotNumber() << endl;
                return;
            }
        }

        // No suitable parking spot was found
        cout << "No spot available for "
             << vehicle->getLicensePlate() << endl;
    }
};

int main() {
    // Create a parking lot with 2 compact and 1 large spot
    ParkingLot parkingLot(2, 1);

    // Create vehicles
    Car car1("RJ19AB1234");
    Car car2("RJ19CD5678");
    Truck truck("RJ19TR9999");

    // Pass the addresses of the vehicles to the parking lot
    parkingLot.parkVehicle(&car1);
    parkingLot.parkVehicle(&car2);
    parkingLot.parkVehicle(&truck);

    return 0;
}