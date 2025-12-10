#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void startEngine(const char *carName) { printf("%s: Engine started!\n", carName); }
void carAccelerate(const char *carName) { printf("%s: Car: Pressing gas pedal...\n", carName); }
void carBrake(const char *carName) { printf("%s: Car: Applying brakes...\n", carName); }

typedef struct {
    char name[50];

    void (*startEngine)(const char *);
    void (*accelerate)(const char *);
    void (*brake)(const char *);
} Car;

// initalize car
Car *createCar(const char *name) {
    Car *c = malloc(sizeof(Car));

    strncpy(c->name, name, sizeof(c->name));
    c->name[sizeof(c->name)-1] = '\0';

    c->startEngine = startEngine;
    c->accelerate = carAccelerate;
    c->brake = carBrake;

    return c;
}

int main() {

    // exmaple case
    Car *janesCar = createCar("Jane's car");
    janesCar->startEngine(janesCar->name);
    janesCar->accelerate(janesCar->name);
    janesCar->brake(janesCar->name);

    printf("\n");

    // example case
    Car *jacksCar = createCar("Jack's car");
    jacksCar->startEngine(jacksCar->name);
    jacksCar->accelerate(jacksCar->name);
    jacksCar->brake(jacksCar->name);

    free(janesCar);
    free(jacksCar);

    return 0;
}
