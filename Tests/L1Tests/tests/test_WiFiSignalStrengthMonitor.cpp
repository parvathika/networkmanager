#include <gtest/gtest.h>
#include "WiFiSignalStrengthMonitor.h"

using ::testing::_;
using ::testing::Invoke;
using ::testing::Return;

class MockNetworkManagerImplementation : public NetworkManagerImplementation {
public:
    MOCK_METHOD(void, ReportWiFiSignalStrengthChangedEvent, (const std::string&, const std::string&, Exchange::INetworkManager::WiFiSignalQuality), (override));
};

class WiFiSignalStrengthMonitorTest : public ::testing::Test {
protected:
    WiFiSignalStrengthMonitor wifiMonitor;
    MockNetworkManagerImplementation mockManager;

    void SetUp() override {
        _instance = &mockManager;  
    }

    void TearDown() override {
        _instance = nullptr;  
    }
};

TEST_F(WiFiSignalStrengthMonitorTest, RetrieveValuesReturnsCorrectValue) {
    
    std::string command = "echo 'ssid=my_wifi'";
    char outputBuffer[BUFFER_SIZE];

    EXPECT_CALL(mockManager, retrieveValues(command.c_str(), "ssid", _, _))
        .WillOnce(Invoke([&](const char*, const char*, char* buffer, size_t) {
            strncpy(buffer, "ssid=my_wifi", BUFFER_SIZE);
            return std::string("my_wifi");
        }));

    std::string result = wifiMonitor.retrieveValues(command.c_str(), "ssid", outputBuffer, sizeof(outputBuffer));
    EXPECT_EQ(result, "my_wifi");
}

TEST_F(WiFiSignalStrengthMonitorTest, GetSignalDataHandlesDisconnectedState) {
    std::string ssid;
    Exchange::INetworkManager::WiFiSignalQuality quality;
    std::string strengthOut;

    EXPECT_CALL(mockManager, retrieveValues(rssid_command, "RSSI", _, _))
        .WillOnce(Return("0")); 

    wifiMonitor.getSignalData(ssid, quality, strengthOut);
    EXPECT_EQ(quality, Exchange::INetworkManager::WIFI_SIGNAL_DISCONNECTED);
}

TEST_F(WiFiSignalStrengthMonitorTest, MonitorThreadFunctionSignalsChange) {
    std::string ssid;
    std::string strengthOut;

    EXPECT_CALL(mockManager, retrieveValues(ssid_command, "ssid", _, _))
        .WillOnce(Return("my_wifi"));
    EXPECT_CALL(mockManager, retrieveValues(rssid_command, "RSSI", _, _))
        .WillOnce(Return("-55"));  
    EXPECT_CALL(mockManager, ReportWiFiSignalStrengthChangedEvent("my_wifi", "-55", Exchange::INetworkManager::WIFI_SIGNAL_EXCELLENT));

    std::thread monitorThread([this]() { wifiMonitor.monitorThreadFunction(1); });
    monitorThread.detach();  
    std::this_thread::sleep_for(std::chrono::seconds(2));

    
    wifiMonitor.stopThread = true;
    monitorThread.join();
}

TEST_F(WiFiSignalStrengthMonitorTest, StartWiFiSignalStrengthMonitorAlreadyRunning) {
    wifiMonitor.startWiFiSignalStrengthMonitor(1); 
    EXPECT_FALSE(wifiMonitor.stopThread);

    
    wifiMonitor.startWiFiSignalStrengthMonitor(1);
    EXPECT_TRUE(wifiMonitor.isRunning); 

    
    wifiMonitor.stopThread = true;
}



