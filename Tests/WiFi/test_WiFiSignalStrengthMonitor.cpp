#include "WiFiSignalStrengthMonitor.h"
#include "NetworkManagerImplementation.h"
#include "NetworkManagerLogger.h"
#include "INetworkManager.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <string>

using namespace std;
using namespace WPEFramework;
using namespace WPEFramework::Plugin;

class MockNetworkManagerImplementation : public NetworkManagerImplementation {
public:

    MOCK_METHOD(void, ReportWiFiSignalStrengthChangedEvent, 

                (const std::string&, const std::string&, 

                 INetworkManager::WiFiSignalQuality), 

                (override));

};

class WiFiSignalStrengthMonitorTest : public ::testing::Test {

protected:

    WPEFramework::Plugin::WiFiSignalStrengthMonitor monitor;

    MockNetworkManagerImplementation mockManager;



    void SetUp() override {

        _instance = &mockManager;

    }
    void TearDown() override {

     _instance = nullptr;

    }

};

#define BUFFER_SIZE 1024


TEST_F(WiFiSignalStrengthMonitorTest, RetrieveValues_Success) {

    char output_buffer[BUFFER_SIZE];

    std::string result = monitor.retrieveValues("echo ssid=TestSSID", "ssid", output_buffer, sizeof(output_buffer));

    EXPECT_EQ(result, "TestSSID");

}

TEST_F(WiFiSignalStrengthMonitorTest, GetSignalData_Connected) {

    std::string ssid;

    WiFiSignalQuality quality;

    std::string strengthOut;

    ssid = "TestSSID";

    strengthOut = "-55";

    quality = WiFiSignalQuality::WIFI_SIGNAL_GOOD;

    

    monitor.getSignalData(ssid, quality, strengthOut);



    

    EXPECT_EQ(ssid, "TestSSID"); 

    EXPECT_EQ(quality, WiFiSignalQuality::WIFI_SIGNAL_GOOD); 

}





TEST_F(WiFiSignalStrengthMonitorTest, StartWiFiSignalStrengthMonitor) {

    monitor.startWiFiSignalStrengthMonitor(1);  

    EXPECT_TRUE(monitor.isRunning); 

}



TEST_F(WiFiSignalStrengthMonitorTest, MonitorThreadFunction) {

    EXPECT_CALL(mockManager, ReportWiFiSignalStrengthChangedEvent("TestSSID", "-55", WiFiSignalQuality::WIFI_SIGNAL_GOOD)).Times(1);



    monitor.startWiFiSignalStrengthMonitor(1);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    monitor.stopThread = true;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    EXPECT_FALSE(monitor.isRunning);

}


int main(int argc, char **argv) {

    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();

}

