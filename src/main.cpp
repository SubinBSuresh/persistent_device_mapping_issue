// src/main.cpp
#include <iostream>
#include <string>
#include <limits>
#include "device_utility.h"

int main()
{
    DeviceUtility device_manager;

    while (true)
    {
        int expected_devices;
        std::cout << "Enter the number of expected devices (1 or 2, or 0 to exit): ";
        std::cin >> expected_devices;

        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter 0, 1, or 2." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (expected_devices == 0)
        {
            std::cout << "Exiting program." << std::endl;
            break;
        }

        if (expected_devices != 1 && expected_devices != 2)
        {
            std::cout << "Invalid number of devices. Please enter 1 or 2." << std::endl;
            continue;
        }

        device_manager.setDeviceCount(expected_devices);

        for (int i = 0; i < expected_devices; ++i)
        {
            std::cout << "Enter device ID for device " << i + 1 << ": ";
            std::string device_id;
            std::cin >> device_id;

            if (std::cin.fail())
            {
                std::cout << "Invalid device ID input." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                --i;
                continue;
            }
            device_manager.addDeviceSubin(device_id);
        }

        device_manager.logPersistentDevices();
    }

    return 0;
}