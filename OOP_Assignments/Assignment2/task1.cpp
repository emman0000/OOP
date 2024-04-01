//Security Protocol Task 1 
//Programmer Emman Abrar Ali 23k0051

#include <iostream>
#include <string>
using namespace std;

class SecurityTool {
protected:
   string securityLevel; double cost; int numOfDevices;

public:
    SecurityTool(string secLevel, double toolCost, int devices) {
        securityLevel = (secLevel == "High" || secLevel == "Medium" || secLevel == "Low") ? secLevel : "Low";
        cost = (toolCost > 0) ? toolCost : 0;
        numOfDevices = devices;
    }//end constructor 

    void performScan() {
        cout << "Performing generic security scan..." << endl;
    }//end function
};//end class Security Tool

class FirewallTool : public SecurityTool {
    int ports[23]; // Assuming student ID provides 23 ports
    string protocols[6] = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};

public:
    FirewallTool(string secLevel, double toolCost, int devices) : SecurityTool(secLevel, toolCost, devices) {
        generatePortList();
    }//end constructor 

    void generatePortList() {
        int startPort = 2; // Starting port (excluding 0)
        for (int i = 0; i < 23; ++i) {
            ports[i] = startPort + i;
        }
    }

    void performScan() {
        cout << "Performing firewall security scan..." << endl;

        if (securityLevel == "High") {
            cout << "Allowed Ports: ";
            for (int i = 0; i < 10; ++i) {
                cout << ports[i] << " ";
            }
            cout << endl;
            cout << "Allowed Protocols: ";
            for (int i = 0; i < 6; ++i) {
                cout << protocols[i] << " ";
            }
            cout << endl;
            cout <<"Only traffic from selected ports is viable\n" << endl;
        } else if (securityLevel == "Medium") {
            cout << "Allowed Ports: ";
            for (int i = 0; i < 12; ++i) {
                cout << ports[i] << " ";
            }
            cout << endl;
            cout << "Allowed Protocols: ";
            for (int i = 0; i < 6; ++i) {
                cout << protocols[i] << " ";
            }
            cout << endl;
            cout << "All traffic from all ports and protocols inclusive of next 2 ports in sequence.\n" << endl;
        } else if (securityLevel == "Low") {
            cout << "Allowed Ports: ";
            for (int i = 0; i < 17; ++i) {
                cout << ports[i] << " ";
            }
            cout << endl;
            cout << "Allowed Protocols: ";
            for (int i = 0; i < 6; ++i) {
                cout << protocols[i] << " ";
            }
            cout << endl;
            cout << "All traffic from allowed ports and protocols is allowed inclusive of next 5 ports in sequence and from TCP and DNS protocols.\n" << endl;
        }
    }
};//end class

int main() {
  cout << "Programmer Emman Abrar Ali 23k0051" << endl;
    FirewallTool firewall("High", 1000, 10);
    firewall.performScan();
  FirewallTool firewall2("Medium", 1000, 10);
    firewall2.performScan();
      FirewallTool firewall3("Low", 1000, 10);
    firewall3.performScan();

    return 0;

}//end main
