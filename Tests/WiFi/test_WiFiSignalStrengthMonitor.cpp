#include "WiFiSignalStrengthMonitor.h"
#include "NetworkManagerImplementation.h"
#include "NetworkManagerLogger.h"
#include "INetworkManager.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <string>

extern NetworkManagerImplementation* _instance;

using namespace std;
using namespace WPEFramework;
using namespace WPEFramework::Plugin;

class MockNetworkManagerImplementation : public NetworkManagerImplementation {
public:
    MOCK_METHOD(void, ReportWiFiSignalStrengthChangedEvent,
                (const std::string& ssid, const std::string& signalLevel, 
                 Exchange::INetworkManager::WiFiSignalQuality signalQuality), 
                (override));
};

class WiFiSignalStrengthMonitorTest : public ::testing::Test {
protected:
    WPEFramework::Plugin::WiFiSignalStrengthMonitor monitor;
    MockNetworkManagerImplementation mockManager;

    void SetUp() override {
        // Set the _instance to the mockManager
        _instance = &mockManager;
    }

    void TearDown() override {
        _instance = nullptr; // Reset the instance
    }

    // Accessor methods for private members
    bool isMonitorRunning() {
        return monitor.isRunning.load(); // Assuming isRunning is atomic
    }

    void stopMonitorThread() {
        monitor.stopThread = true; // If stopThread is private, consider changing its access level
    }
};

#define BUFFER_SIZE 1024

TEST_F(WiFiSignalStrengthMonitorTest, RetrieveValues_Success) {
    char output_buffer[BUFFER_SIZE];

    std::string result = monitor.retrieveValues("echo ssid=TestSSID", "ssid", output_buffer, sizeof(output_buffer));

    EXPECT_EQ(result, "TestSSID");
}

TEST_F(WiFiSignalStrengthMonitorTest, GetSignalData_Connected) {
    std::string ssid = "TestSSID";
    Exchange::INetworkManager::WiFiSignalQuality quality;
    std::string strengthOut = "-55";

    monitor.getSignalData(ssid, quality, strengthOut);

    EXPECT_EQ(ssid, "TestSSID");
    EXPECT_EQ(quality, Exchange::INetworkManager::WIFI_SIGNAL_GOOD);
}

TEST_F(WiFiSignalStrengthMonitorTest, StartWiFiSignalStrengthMonitor) {
    monitor.startWiFiSignalStrengthMonitor(1);  
    EXPECT_TRUE(isMonitorRunning());
}

TEST_F(WiFiSignalStrengthMonitorTest, MonitorThreadFunction) {
    EXPECT_CALL(mockManager, ReportWiFiSignalStrengthChangedEvent("TestSSID", "-55", Exchange::INetworkManager::WIFI_SIGNAL_GOOD)).Times(1);

    monitor.startWiFiSignalStrengthMonitor(1);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    stopMonitorThread();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    EXPECT_FALSE(isMonitorRunning());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
