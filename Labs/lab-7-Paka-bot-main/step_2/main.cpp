#include <iostream>
#include "vehicle.hpp"
#include "car.hpp"
#include "bus.hpp"
#include "bot.hpp"

using namespace std;

int main() {

    vehicle ferrari("Ferrari", 1999, 150);
    vehicle bmw("BMW", 2016, 300);

    car porsche("Porshce", 2023, 200, 2, false);
    car tesla("Tesla", 2024, 400, 4, true);

    bus hyundai("Hyundai", 2003, 300, 40);
    bus kia("Kia", 2000, 200, 30);

    delivery_bot lucia("Lucia", 2024, 1000, 7);
    delivery_bot paka("Paka", 2003, 1018, 7);



    ferrari.print_info();
    bmw.print_info();

    porsche.print_info();
    tesla.print_info();

    hyundai.print_info();
    kia.print_info();

    lucia.print_info();
    paka.print_info();

    return 0;
}