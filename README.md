
# Linestar Machine Controllers C++

Ethernet/IP Client Libraries For Automating Controls of Various Linestar Machines


### Example Usage

```
#include <iostream>
#include "Linestar.h"

int main() {
    Linestar linestar;
    try {
        // Connect to the PLC
        linestar.connect("192.168.1.100");

        // Wake up the system
        linestar.wake();
        std::cout << "System woke up successfully" << std::endl;

        // Move to the home position
        linestar.moveToHome();
        std::cout << "Moved to home position successfully" << std::endl;

        // Go to a specific position
        linestar.goToPosition(1.0f, 2.5f);
        std::cout << "Moved to position (1.0, 2.5) successfully" << std::endl;

        // Retrieve location information
        std::string location = linestar.reportLocation();
        std::cout << "Current location: " << location << std::endl;

        // Retrieve error margin information
        std::string error_margin = linestar.reportErrorMargin();
        std::cout << "Error margin: " << error_margin << std::endl;

        // Disconnect from the PLC
        linestar.disconnect();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```
