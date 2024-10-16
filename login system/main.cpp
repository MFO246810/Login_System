#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;


void add_Login(map<string, string>& userMap, ofstream& f) {
	string name; 
	string p; 
	cout << "Enter your username: " << endl; 
	cin >> name;
	cout << "Enter your password: " << endl;
	cin >> p; 
	userMap[name] = p; 
	for (const auto& pair : userMap) {
		f << pair.first << " " << pair.second << endl;
	}
}

int main() {
    ifstream type("type.txt");
    int t = 0;
    type >> t;
    type.close();

    if (t == 1) {
        t = 2;
        ofstream outtype("type.txt");
        outtype << t;
        outtype.close();

        ifstream infile("input.txt");
        ofstream outfile("output.txt");

        map<string, string> userMap;
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
            int loc = line.find(" ");
            userMap[line.substr(0, loc)] = line.substr(loc + 1);
        }

        add_Login(userMap, outfile);
        infile.close();
        outfile.close();

        for (const auto& pair : userMap) {
            cout << "Username: " << pair.first << " Password: " << pair.second << endl;
        }
    }
    else {
        t = 1;
        ofstream outtype("type.txt");
        outtype << t;
        outtype.close();

        ifstream infile("output.txt");
        ofstream outfile("input.txt");

        map<string, string> userMap;
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
            int loc = line.find(" ");
            userMap[line.substr(0, loc)] = line.substr(loc + 1);
        }

        add_Login(userMap, outfile);
        infile.close();
        outfile.close();

        for (const auto& pair : userMap) {
            cout << "Username: " << pair.first << " Password: " << pair.second << endl;
        }
    }

    return 0;
}