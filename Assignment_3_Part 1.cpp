#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int getFirstOctet(const string& ip) {
    stringstream ss(ip);
    string firstOctetStr;

    if (getline(ss, firstOctetStr, '.')) {
        try {
            return stoi(firstOctetStr);
        } catch (...) {
            return -1; 
        }
    }
    return -1;
}

void evaluateIPClass(const string& ipStr) {
    int firstOctet = getFirstOctet(ipStr);

    int category = 0;
    if (firstOctet >= 0 && firstOctet <= 127) category = 1;
    else if (firstOctet >= 128 && firstOctet <= 191) category = 2;
    else if (firstOctet >= 192 && firstOctet <= 223) category = 3;
    else if (firstOctet >= 224 && firstOctet <= 239) category = 4;
    else if (firstOctet >= 240 && firstOctet <= 255) category = 5;
    else category = -1;

    switch (category) {
        case 1:
            cout << "\nIP: " << ipStr << " falls under **Class A**\n";
            cout << " -> First Octet:        " << firstOctet << " (Range: 0 - 127)\n";
            cout << " -> Binary Range:       0XXXXXXX\n";
            cout << " -> Default Subnet Mask: 255.0.0.0\n";
            cout << " -> Hosts per Network:   2^24 - 2\n";
            cout << " -> Number of Networks:  2^7\n";
            break;
            
        case 2:
            cout << "\nIP: " << ipStr << " falls under **Class B**\n";
            cout << " -> First Octet:        " << firstOctet << " (Range: 128 - 191)\n";
            cout << " -> Binary Range:       10XXXXXX\n";
            cout << " -> Default Subnet Mask: 255.255.0.0\n";
            cout << " -> Hosts per Network:   2^16 - 2\n";
            cout << " -> Number of Networks:  2^14\n";
            break;
            
        case 3:
            cout << "\nIP: " << ipStr << " falls under **Class C**\n";
            cout << " -> First Octet:        " << firstOctet << " (Range: 192 - 223)\n";
            cout << " -> Binary Range:       110XXXXX\n";
            cout << " -> Default Subnet Mask: 255.255.255.0\n";
            cout << " -> Hosts per Network:   2^8 - 2\n";
            cout << " -> Number of Networks:  2^21\n";
            break;
            
        case 4:
            cout << "\nIP: " << ipStr << " falls under **Class D (Multicast)**\n";
            cout << " -> First Octet:        " << firstOctet << " (Range: 224 - 239)\n";
            cout << " -> Binary Range:       1110XXXX\n";
            cout << " -> Subnet Mask/Hosts:   Not applicable (Multicast)\n";
            break;
            
        case 5:
            cout << "\nIP: " << ipStr << " falls under **Class E (Experimental)**\n";
            cout << " -> First Octet:        " << firstOctet << " (Range: 240 - 255)\n";
            cout << " -> Binary Range:       1111XXXX\n";
            cout << " -> Subnet Mask/Hosts:   Reserved / Experimental\n";
            break;
            
        default:
            cout << "\nError: Invalid IP address format or out of valid range.\n";
            break;
    }
}

int main(){
    cout << "Subnet Mask" << endl;
    cout << "A subnet mask is a 32-bit number that divides an IP address into its network and host portions, determining which part of the address identifies the specific network and which part identifies the specific device." << endl;
    cout << endl;
    cout << "What is subnetting" << endl;
    cout << "Subnetting is the practice of dividing a single physical network into smaller, logical sub-networks (called subnets)" << endl;
    cout << endl;
    string ipAddress;
    cout << "Enter a full IPv4 address (e.g., 192.168.1.1): ";
    cin >> ipAddress;
    
    cout << "\n----------------------------------------\n";
    evaluateIPClass(ipAddress);
    cout << "----------------------------------------\n";
}