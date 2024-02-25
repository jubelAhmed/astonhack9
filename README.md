# README

## Description

This code simulates faults in different parts of a system and attempts to recover them. The system has four components: Engine, Shields, Life Support, and Reactor. Each component has an associated fault flag (`flag1`, `flag2`, `flag3`, `flag4`) that is initially set to 1, indicating no fault.

The program randomly selects one of the components, triggers a fault, and attempts to recover the component. If the recovery is successful, the corresponding fault flag is set to 0.

## Setup

The code is designed to run on a microcontroller or Arduino board. Before uploading the code to the board, ensure that the necessary pins are configured correctly.

```cpp
void setup() {
  Serial.begin(9600);
  // Set pins as OUTPUT
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  // ... Repeat for pins 2 to 13
}

// ... Rest of the code ...
```

## Functions

### `fail_part`

This function is responsible for simulating a fault in a specific part of the system and attempting recovery.

```cpp
void fail_part(char* partName, int basePin, int inputPin, int* flag);
```

- `partName`: A string representing the name of the component with the fault.
- `basePin`: The base pin associated with the component (e.g., Engine: 0, Shields: 3, Life Support: 6, Reactor: 9).
- `inputPin`: The analog pin used to check the condition of the component.
- `flag`: A pointer to the fault flag associated with the component.

### `loop`

The main loop continuously triggers faults in random components and checks for recovery.

```cpp
void loop();
```

## Usage

1. Connect the system components to the specified pins on the microcontroller.
2. Upload the code to the microcontroller.
3. Open the serial monitor to observe fault messages and flag statuses.

## Note

- The program uses random faults for simulation purposes.
- The recovery process involves checking the analog input to determine if the component has revived.
- If recovery fails within a specified timeout, the fault flag is set to 0.

Feel free to modify the code according to your specific requirements or add additional features.
