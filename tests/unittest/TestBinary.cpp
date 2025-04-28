#ifndef MODULE_NAME
#define MODULE_NAME TestBinary
#endif /* MODULE_NAME */

#include <core/core.h>
#include <websocket/websocket.h>

MODULE_NAME_DECLARATION("MyTestBinary")

using namespace WPEFramework;
using namespace std;


int main ()
{
     {
   Core::SystemInfo::SetEnvironment(_T("THUNDER_ACCESS"), (_T("127.0.0.1:9998")));


    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin;
    jsonPlugin = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.NetworkManager.1", "");
    JsonObject parameters, response;

    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetIPSettings"), parameters, response);
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
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetLogLevel"), parameters, response);

    //Test 8:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetAvailableInterfaces"), parameters, response);
    
    //Test 9:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPrimaryInterface"), parameters, response);
    
    //Test 10:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPrimaryInterface"), parameters, response);
    
    //Test 11:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response);
    
    //Test 12:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetPrimaryInterface"), parameters, response);
    
    //Test 13:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
    
    //Test 14:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetInterfaceState"), parameters, response);
    
    //Test 15:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    
    //Test 16:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetInterfaceState"), parameters, response);
    
    //Test 17:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetIPSettings"), parameters, response);
    
    //Test 16:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetIPSettings"), parameters, response);
    
    //Test 18:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
    
    //Test 19:
    parameters["endpoint"] = "45.57.221.20";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetStunEndpoint"), parameters, response);
    
    //Test 20:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetConnectivityTestEndpoints"), parameters, response);
    
    //Test 21:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetConnectivityTestEndpoints"), parameters, response);
    
    //Test 22:
    parameters["endpoint"] =  "http://clients3.google.com/generate_204";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("SetConnectivityTestEndpoints"), parameters, response);
    
    //Test 23:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
    
    //Test 24:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("IsConnectedToInternet"), parameters, response);
    
    //Test 25:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetCaptivePortalURI"), parameters, response);
    
    //Test 26:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    
    //Test 27:
    parameters["interface"] = "wlan0";
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetPublicIP"), parameters, response);
    
    //Test 28:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetConnectedSSID"), parameters, response);
    
    //Test 29:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetWiFiSignalQuality"), parameters, response);
    
    //Test 30
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("GetWifiState"), parameters, response);
    
    
    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin2;
    jsonPlugin2 = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.Network.1", "");
  
    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getDefaultInterface"), parameters, response);
    
    //Test 2:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getInterfaces"), parameters, response);
    
    //Test 3:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getIPSettings"), parameters, response);
    
    //Test 4:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getNamedEndpoints"), parameters, response);
    
    //Test 5:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getStbIp"), parameters, response);
    
    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin3;
    jsonPlugin3 = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("org.rdk.WiFi.1", "");
    //Test 1:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("cancelWPSPairing"), parameters, response);
    
    //Test 2:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("clearSSID"), parameters, response);
    
    //Test 3:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("connect"), parameters, response);
    
    //Test 4:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("disconnect"), parameters, response);
    
    //Test 5:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getConnectedSSID"), parameters, response);
    
     //Test 6:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getCurrentState"), parameters, response);
    
    //Test 7:
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("getPairedSSID"), parameters, response);
    
    //Test 8:
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
    
    

}
