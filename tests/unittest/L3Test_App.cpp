#ifndef MODULE_NAME
#define MODULE_NAME L3Test
#endif /* MODULE_NAME */

#include <core/core.h>
#include <websocket/websocket.h>

MODULE_NAME_DECLARATION("L3Test")

using namespace WPEFramework;
using namespace std;


int main ()
{
     
   Core::SystemInfo::SetEnvironment(_T("THUNDER_ACCESS"), (_T("127.0.0.1:9998")));


    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin;
    jsonPlugin = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.NetworkManager.1", "");
    JsonObject parameters, response;
   
    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
	printf("testing");
	
    //Test 2:
    parameters["interface"] = "test";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
    //Test 3:
    parameters["interface"] = "eth0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
    //Test 4:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
    
    //Test 5:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel"), parameters, response);

    //Test 6:
    parameters["level"] = "1";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel"), parameters, response);
    
    //Test 7:
    parameters["level"] = "4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel"), parameters, response);
    
    //Test 8:
    parameters["level"] = "20";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetLogLevel"), parameters, response);
      
    //Test 7:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetLogLevel"), parameters, response);
    
    //Test 10:
    parameters["level"] = "1";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetLogLevel"), parameters, response);
    
    //Test 11:
    parameters["level"] = "4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetLogLevel"), parameters, response);

    //Test 12:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetAvailableInterfaces"), parameters, response);
    
    //Test 13:
    parameters["interface"] = "eth0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetAvailableInterfaces"), parameters, response);
    
    //Test 14:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetAvailableInterfaces"), parameters, response);
    
    //Test 15:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPrimaryInterface"), parameters, response);
    
    //Test 16:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPrimaryInterface"), parameters, response);
    
    //Test 17:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response);
    
    //Test 18:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response);
    
    //Test 19:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response);
    
    //Test 20:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
    
    //Test 21:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
   
    //Test 22:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    
    //Test 23:
    parameters["interface"] = "eth0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    
    //Test 24:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    
    //Test 25:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetIPSettings"), parameters, response);
    
    //Test 16:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetIPSettings"), parameters, response);
    
    //Test 18:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
    
    //Test 26:
    parameters["endpoint"] = "45.57.221.20";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
    
    //Test 27:
     parameters["endpoint"] = "1567";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
    
    //Test 28:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetConnectivityTestEndpoints"), parameters, response);
    
    //Test 29:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetConnectivityTestEndpoints"), parameters, response);
    
    //Test 30:
    parameters["endpoint"] =  "http://clients3.google.com/generate_204";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetConnectivityTestEndpoints"), parameters, response);
    
    //Test 31:
    parameters["endpoint"] =  "clients.com";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetConnectivityTestEndpoints"), parameters, response);
    
    //Test 32:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
    
    //Test 33:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
    
    //Test 34:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetCaptivePortalURI"), parameters, response);
    
    //Test 35:
    parameters["uri"] = "http://10.0.0.1/captiveportal.jst";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetCaptivePortalURI"), parameters, response);
    
    //Test 36:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    
    //Test 37:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    
    //Test 38:
    parameters["interface"] = "hello";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    
    //Test :39
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetConnectedSSID"), parameters, response);
    
    //Test 40:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetWiFiSignalQuality"), parameters, response);
    
    //Test 41:
    parameters["ssid"] = "myHomeSSID";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    
    //Test 42:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetWifiState"), parameters, response);
    
    //Test 43:
    parameters["state"] = "4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    
    
    
    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin2;
    jsonPlugin2 = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.Network.1", "");
  
    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getDefaultInterface"), parameters, response);
    //Test 2:
    parameters["interface"] = "test";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getDefaultInterface"), parameters, response);
    //Test 3:
    parameters["interface"] = "WIFI";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getDefaultInterface"), parameters, response);
      
    
    //Test 4:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInterfaces"), parameters, response);
    //Test 5:
    parameters["interface"] = "WIFI";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInterfaces"), parameters, response);
    //Test 6:
    parameters["interface"] = "etho";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInterfaces"), parameters, response);
    
    //Test 7:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    //Test 8:
    parameters["interface"] = "WIFI";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    //Test 9:
    parameters["interface"] = "etho";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    
    //Test 10:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getStbIp"), parameters, response);
    //Test 11:
    parameters["ip"] = "192.168.1.101";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getStbIp"), parameters, response);
    //Test 12:
    parameters["ip"] = "192.168.";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getStbIp"), parameters, response);
    
    //Test 13:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSTBIPFamily"), parameters, response);
    //Test 14:
    parameters["family"] = "AF_INET";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSTBIPFamily"), parameters, response);
    //Test 15:
    parameters["ip"] = "abcd";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSTBIPFamily"), parameters, response);
    
    //Test 17:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setConnectivityTestEndpoints"), parameters, response);
    //Test 18:
    parameters["endpoints"] = "http://clients3.google.com/generate_204";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("setConnectivityTestEndpoints"), parameters, response);
    
    //Test 19:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isConnectedToInternet"), parameters, response);
    //Test 20:
    parameters["ipversion"] = "IPv4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isConnectedToInternet"), parameters, response);
    //Test 21:
    parameters["ipversion"] = "IP";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInternetConnectionState"), parameters, response);
    
    //Test 22:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInternetConnectionState"), parameters, response);
    //Test 23:
    parameters["ipversion"] = "IPv4";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInternetConnectionState"), parameters, response);
    //Test 24:
    parameters["ipversion"] = "IP";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInternetConnectionState"), parameters, response);
    
    //Test 25:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getCaptivePortalURI"), parameters, response);
    //Test 26:
    parameters["URI"] = "http://10.0.0.1/captiveportal.jst";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getCaptivePortalURI"), parameters, response);
    
    //Test 27:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isInterfaceEnabled"), parameters, response);
    //Test 28:
    parameters["interface"] = "WIFI";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isInterfaceEnabled"), parameters, response);
    
    
    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin3;
    jsonPlugin3 = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.WiFi.1", "");
    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("cancelWPSPairing"), parameters, response);
    
    //Test 2:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("clearSSID"), parameters, response);
    
    //Test 3:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    //Test 4:
    parameters["ssid"] = "123412341234";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    //Test 5:
    parameters["ssid"] = "myssid";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    
    //Test 6:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("disconnect"), parameters, response);
    //Test 7:
    parameters["result"] = "0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("disconnect"), parameters, response);
    //Test 8:
    parameters["result"] = "1";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("disconnect"), parameters, response);
    //Test 9:
    parameters["result"] = "2";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("disconnect"), parameters, response);
    
    //Test 10:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getConnectedSSID"), parameters, response);
    //Test 11:
    parameters["ssid"] = "123412341234";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getConnectedSSID"), parameters, response);
    //Test 12:
    parameters["ssid"] = "myssid";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getConnectedSSID"), parameters, response);
    
     //Test 13:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getCurrentState"), parameters, response);
    //Test 14:
    parameters["state"] = "1";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getCurrentState"), parameters, response);
    //Test 15:
    parameters["state"] = "2";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getCurrentState"), parameters, response);
    
    //Test 16:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSID"), parameters, response);
    //Test 17:
    parameters["ssid"] = "123412341234";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSID"), parameters, response);
    //Test 18:
    parameters["ssid"] = "myssid";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSID"), parameters, response);
    
    //Test 8:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSIDInfo"), parameters, response);
    //Test 17:
    parameters["ssid"] = "123412341234";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSIDInfo"), parameters, response);
    //Test 18:
    parameters["ssid"] = "myssid";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSIDInfo"), parameters, response);
    
      
    //Test 9:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getSupportedSecurityModes"), parameters, response);
    
     //Test 10:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("isPaired"), parameters, response);
    
    //Test 7:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("startScan"), parameters, response);
    
    //Test 8:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("stopScan"), parameters, response);
      

}
