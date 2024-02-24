#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

// Define states for objects
enum ObjectState { GREEN, YELLOW, RED };

// Function to generate random state for an object
enum ObjectState generateRandomState() {
    return rand() % 2; // Randomly choose between GREEN, YELLOW,
}

enum ObjectState generateDefaultState() {
    return 0; //GREEN
}

// Function to simulate sensor reading
int sensor1() {
    return rand() % 5; 
}

int sensor2() {
    return rand() % 5; 
}

int sensor3() {
    return rand() % 5; 
}

int sensor4() {
    return rand() % 5; 
}

void updateObjectState(enum ObjectState newState, enum ObjectState *state) {
    *state = newState;
}

// Function to update LED based on object state
void updateLED(enum ObjectState state) {
    switch (state) {
        case GREEN:
            printf("Green ");
            break;
        case YELLOW:
            printf("Yellow ");
            break;
        case RED:
            printf("Red ");
            break;
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    enum ObjectState object1State = GREEN; 
    enum ObjectState object2State = GREEN;
    enum ObjectState object3State = GREEN;
    enum ObjectState object4State = GREEN;

    printf("\nBeginning State\n");
    printf("Object 1: ");
    updateLED(object1State);
    printf("\nObject 2: ");
    updateLED(object2State);
    printf("\nObject 3: ");
    updateLED(object3State);
    printf("\nObject 4: ");
    updateLED(object4State);
    printf("\n");
    // Define time limit for repair
    const int repairTimeLimit = 5; // 10 seconds
    
    // Variables to track repair time
    int repairTimer = 0;
    bool isRepairing = false;
    
    // Main game loop
    while (true) {

        if(!isRepairing){
            if(object1State != RED){
                object1State = generateRandomState();
            }

            if(object2State != RED){
                object2State = generateRandomState();
            }

            if(object3State != RED){
                object3State = generateRandomState();
            }

            if(object4State != RED){
                object4State = generateRandomState();
            }

            printf("\n\nCurrent State\n");
            printf("Object 1: ");
            updateLED(object1State);
            printf("\nObject 2: ");
            updateLED(object2State);
            printf("\nObject 3: ");
            updateLED(object3State);
            printf("\nObject 4: ");
            updateLED(object4State);
            printf("\n\n");
        }
        
        // Check if any object is in yellow state and initiate repair
        if (!isRepairing && (object1State == YELLOW || object2State == YELLOW || object3State == YELLOW || object4State == YELLOW)) {
            isRepairing = true; // Start repair process
            repairTimer = 0; // Reset repair timer
            printf("\n\nRepairing...\n\n");
        }

        // Perform repair if repair timer reaches limit
        printf("\nRepair Timing Difference ");
        printf("%d",repairTimer);
        printf("\n\n");
        if (isRepairing && repairTimer > repairTimeLimit) {
            isRepairing = false; 
            repairTimer = 0;
            // Reset object states to RED after repair time limit
            if (object1State == YELLOW) object1State = RED;
            if (object2State == YELLOW) object2State = RED;
            if (object3State == YELLOW) object3State = RED;
            if (object4State == YELLOW) object4State = RED;

            printf("\n\nFinal State\n");
            printf("Object 1: ");
            updateLED(object1State);
            printf("\nObject 2: ");
            updateLED(object2State);
            printf("\nObject 3: ");
            updateLED(object3State);
            printf("\nObject 4: ");
            updateLED(object4State);
            printf("\n\n");
        }

        // Simulate sensor readings
        int sensorValue1 = sensor1();
        int sensorValue2 = sensor2();
        int sensorValue3 = sensor3();
        int sensorValue4 = sensor4();
    
        if(isRepairing && object1State == YELLOW && sensorValue1 == 1){
            updateObjectState(GREEN, &object1State);
        }
        if(isRepairing && object2State == YELLOW && sensorValue2 == 1){
            updateObjectState(GREEN, &object2State);
        }
        if(isRepairing && object3State == YELLOW && sensorValue3 == 1){
            updateObjectState(GREEN, &object3State);
        }
        if(isRepairing && object4State == YELLOW && sensorValue4 == 1){
            updateObjectState(GREEN, &object4State);
        }
        

        printf("\n\nObject Situation during process\n");
        printf("Object 1: ");
        updateLED(object1State);
        printf("\nObject 2: ");
        updateLED(object2State);
        printf("\nObject 3: ");
        updateLED(object3State);
        printf("\nObject 4: ");
        updateLED(object4State);
        printf("\n");

        if (isRepairing && object1State == GREEN && object2State == GREEN && object3State == GREEN && object4State == GREEN) {
            isRepairing = false;
            repairTimer = 0;
            printf("\nReparing finished");

        }
        
        // Increment repair timer if repairing
        if (isRepairing) {
            sleep(1); // Wait for 1 second (simulation)
            repairTimer++;
        } else {
           
            // Check if all objects are in red state
            if (object1State == RED && object2State == RED && object3State == RED && object4State == RED) {
                printf("\nTime Out! Game Over!\n");
                break; // Exit game loop
            }
        }
    }
    
    return 0;
}
