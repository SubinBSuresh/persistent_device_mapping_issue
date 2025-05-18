// src/device_utility.cpp
#include "device_utility.h"
#include <iostream>
#include <string>
#include <map>

DeviceUtility::DeviceUtility() : device1_id(""), device2_id("") {}

void DeviceUtility::setDeviceCount(int count)
{
    expected_device_count_ = count;
    // if (count == 1 || count == 2)
    // {
    //     expected_device_count_ = count;
    //     if (count == 0)
    //     {
    //         device1_id = "";
    //         device2_id = "";
    //     }
    // }
    // else
    // {
    //     std::cout << "Invalid device count." << std::endl;
    // }
}

void DeviceUtility::addDevice(const std::string &deviceId)
{

    if (expected_device_count_ == 1)
    {
        device1_id = deviceId;
        std::cout << "Device added to DEVICE_1: ID = " << deviceId << std::endl;
    }
    else if (expected_device_count_ == 2)
    {
        if (device1_id.empty())
        {
            device1_id = deviceId;
            std::cout << "Device added to DEVICE_1: ID = " << deviceId << std::endl;
        }
        else if (device2_id.empty())
        {
            device2_id = deviceId;
            std::cout << "Device added to DEVICE_2: ID = " << deviceId << std::endl;
        }
        else if (device1_id == deviceId)
        {
            std::cout << "Device added to DEVICE_1: ID = " << deviceId << std::endl;
        }
        else if (device2_id == deviceId)
        {
            std::cout << "Device added to DEVICE_2: ID = " << deviceId << std::endl;
        }
        else
        {
            std::cout << "Both slots are occupied." << std::endl;
        }
    }
}

void DeviceUtility::addDeviceSubin(const std::string &deviceId)
{
    if (expected_device_count_ <= 2 && expected_device_count_ != 0)
    {
        std::cout << "expected_device_count_ <= 2 && expected_device_count_ != 0" << std::endl;

        if (expected_device_count_ == 1)
        {
            std::cout << "expected_device_count_ == 1" << std::endl;

            if (device1_id.empty() && device2_id.empty())
            {
                device1_id = deviceId;
                std::cout << "Device added to DEVICE_1: ID = " << deviceId << std::endl;
            }

            if (device1_id == deviceId || device2_id == deviceId)
            {
                std::cout << "device1_id == deviceId || device2_id == deviceIds " << std::endl;

                if (device1_id == deviceId)
                {
                    device2_id = "";
                    std::cout << "device1_id == deviceId, so making device2_id empty" << device2_id << std::endl;
                }
                else if (device2_id == deviceId)
                {

                    device1_id = "";
                    std::cout << "device2_id == deviceId, so making device1_id empty" << device1_id << std::endl;
                }
            }
        }
        else
        {
            if (device1_id.empty() && !(device2_id == deviceId))
            {
                device1_id = deviceId;
                std::cout << " second Device added to DEVICE_1: ID = " << deviceId << std::endl;
            }
            else if (device2_id.empty() && !(device1_id == deviceId))
            {
                device2_id = deviceId;
                std::cout << "Device added to DEVICE_2: ID = " << deviceId << std::endl;
            }
        }
    }
    else
        std::cout << "not 1 and 2" << deviceId << std::endl;
    {
        return;
    }
    expected_device_count_--;
}

void DeviceUtility::addDeviceSubin(const std::string &deviceId)
{
            if (device1_id.empty() && device2_id.empty())
            {
                device1_id = deviceId;
                std::cout << "Device added to DEVICE_1: ID = " << deviceId << std::endl;
            }
            if (device1_id.empty() && !(device2_id == deviceId))
            {
                device1_id = deviceId;
                std::cout << " second Device added to DEVICE_1: ID = " << deviceId << std::endl;
            }
            else if (device2_id.empty() && !(device1_id == deviceId))
            {
                device2_id = deviceId;
                std::cout << "Device added to DEVICE_2: ID = " << deviceId << std::endl;
            }

            if (device1_id == deviceId || device2_id == deviceId)
            {
                std::cout << "device1_id == deviceId || device2_id == deviceIds " << std::endl;

                if (device1_id == deviceId)
                {
                    device2_id = "";
                    std::cout << "device1_id == deviceId, so making device2_id empty" << device2_id << std::endl;
                }
                else if (device2_id == deviceId)
                {

                    device1_id = "";
                    std::cout << "device2_id == deviceId, so making device1_id empty" << device1_id << std::endl;
                }
            }
        }


        }
}
}

void DeviceUtility::addDeviceSubin2(const std::string &deviceId)
{
    if (expected_device_count_ == 0 || expected_device_count_ > 2)
    {
        std::cout << "Invalid expected_device_count_: " << expected_device_count_ << ", device ID: " << deviceId << std::endl;
        return;
    }

    // Handle case when only 1 device is expected
    if (expected_device_count_ == 1)
    {
        std::cout << "Handling single device mode" << std::endl;

        // If both IDs are empty, assign device1
        if (device1_id.empty() && device2_id.empty())
        {
            device1_id = deviceId;
            std::cout << "Device added to DEVICE_1: ID = " << deviceId << std::endl;
        }

        // Toggle behavior: if ID already exists, clear the opposite
        if (device1_id == deviceId)
        {
            device2_id.clear();
            std::cout << "device1_id matched, cleared device2_id" << std::endl;
        }
        else if (device2_id == deviceId)
        {
            device1_id.clear();
            std::cout << "device2_id matched, cleared device1_id" << std::endl;
        }
    }
    else // expected_device_count_ == 2
    {
        std::cout << "Handling dual device mode" << std::endl;

        // Avoid adding duplicate device IDs
        if (device1_id.empty() && device2_id != deviceId)
        {
            device1_id = deviceId;
            std::cout << "Device added to DEVICE_1: ID = " << deviceId << std::endl;
        }
        else if (device2_id.empty() && device1_id != deviceId)
        {
            device2_id = deviceId;
            std::cout << "Device added to DEVICE_2: ID = " << deviceId << std::endl;
        }
        else
        {
            std::cout << "Device ID already exists or no slots available: ID = " << deviceId << std::endl;
        }
    }

    // Decrement count once a valid path was taken
    expected_device_count_--;
}

std::map<std::string, std::string> DeviceUtility::getDevices() const
{
    std::map<std::string, std::string> devices;
    if (!device1_id.empty())
    {
        devices[device1_id] = "DEVICE_1";
    }
    if (!device2_id.empty())
    {
        devices[device2_id] = "DEVICE_2";
    }
    return devices;
}

void DeviceUtility::logPersistentDevices() const
{
    std::cout << "\n--- Persistent Devices ---" << std::endl;

    std::cout << "DEVICE_1: ID = " << device1_id << std::endl;

    std::cout << "DEVICE_2: ID = " << device2_id << std::endl;
}