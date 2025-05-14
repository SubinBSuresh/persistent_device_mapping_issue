// include/device_utility.h
#ifndef DEVICE_UTILITY_H
#define DEVICE_UTILITY_H

#include <map>
#include <string>

class DeviceUtility
{
public:
    DeviceUtility();
    void setDeviceCount(int count);
    void addDevice(const std::string &deviceId);
    void addDeviceSubin(const std::string &deviceId);
    void addDeviceSubin2(const std::string &deviceId);
    std::map<std::string, std::string> getDevices() const;
    void logPersistentDevices() const;

private:
    int expected_device_count_ = 0;
    std::string device1_id;
    std::string device2_id;
    static const size_t max_slots_ = 2;
};

#endif // DEVICE_UTILITY_H