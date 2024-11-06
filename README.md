# C++ Data Transmission Simulation 📡

This C++ program simulates the process of creating data packets (frames) for transmission. It uses bit stuffing (padding the string with `$` characters) to ensure the string length is divisible by the frame size, and it calculates the checksum for each frame.

## Key Components 🔑

### 1. **Frame Structure** 🏗️
The `frame` structure defines the components of each packet:
- **no**: Frame number
- **len**: Frame size (fixed at 8 bytes)
- **des**: Destination address
- **source**: Source address
- **data**: The actual data being sent (maximum 8 characters)
- **checksum**: A simple checksum calculated by summing the ASCII values of the data characters.

```cpp
typedef struct frame {
    int no;          // Frame number
    int len;         // Frame size (8 bytes)
    char des;        // Destination address
    char source;     // Source address
    char data[9];    // Data to be sent (up to 8 characters + null terminator)
    int checksum;    // Checksum of the data
} F;
