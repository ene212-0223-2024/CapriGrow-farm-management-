#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Kennedy Kimani - ENE212-0223/2024
    EEC 2212 Object Oriented Programming
    CapriGrow Farm Management System
*/

class FarmModule {
protected:
    string name;
public:
    FarmModule(const string& n) {
        name = n;
    }
    virtual void execute() = 0;
    string getName() const {
        return name;
    }
    virtual ~FarmModule() {}
};

// Irrigation - tracks my daily watering for each greenhouse
class IrrigationModule : public FarmModule {
public:
    IrrigationModule() : FarmModule("Watering Log") {}
    void execute() override {
        cout << "\n DAILY WATERING LOG " << endl;
        cout << "Passarella (GH 0)  - watered at 06:00 AM" << endl;
        cout << "Illanga    (GH 1)  - watered at 06:15 AM" << endl;
        cout << "Mydas RZ   (GH 2)  - watered at 06:30 AM" << endl;
        cout << "Next cycle: 5:00 PM" << endl;
    }
};

// Spray - my weekly chemical programme
class SprayModule : public FarmModule {
public:
    SprayModule() : FarmModule("Spray Schedule") {}
    void execute() override {
        cout << "\n SPRAY SCHEDULE " << endl;
        cout << "Monday    : Occasion Star 250ml (Fungicide)  " << endl;
        cout << "Wednesday : Crop Max Foliar 1ltr             " << endl;
        cout << "Thursday  : Alonze 100ml (Pesticide)         " << endl;
        cout << "Saturday  : Tabibu 1ltr (Bactericide)        " << endl;
    }
};

// Harvest - records sales to my buyers
class HarvestModule : public FarmModule {
public:
    HarvestModule() : FarmModule("Harvest Tracker") {}
    void log(string crop) {
        cout << "Logged: " << crop << " (quantity not confirmed yet)" << endl;
    }
    void log(string crop, double kg, int price) {
        cout << "Logged: " << crop << " | " << kg << "kg @ Ksh" << price << " = Ksh" << kg * price << endl;
    }
    void log(string crop, double kg, int price, string buyer) {
        cout << "Logged: " << crop << " | " << kg << "kg @ Ksh" << price << " = Ksh" << kg * price << " | Buyer: " << buyer << endl;
    }
    void execute() override {
        cout << "\n HARVEST & SALES RECORDS " << endl;
        log("Mydas RZ");
        log("Passarella", 149, 50);
        log("Illanga Capsicum", 95, 150, "martin");
        log("Mydas RZ", 232, 50, "Annita");
    }
};

class CapriGrowSystem {
private:
    bool loggedIn;
public:
    CapriGrowSystem() {
        loggedIn = false;
    }
    bool authenticate() {
        string user, pass;
        cout << "Username: "; cin >> user;
        cout << "Password: "; cin >> pass;
        if (user == "Ken" && pass == "CG_2026") {
            loggedIn = true;
            return true;
        }
        return false;
    }
    void runMenu() {
        vector<FarmModule*> modules;
        modules.push_back(new IrrigationModule());
        modules.push_back(new SprayModule());
        modules.push_back(new HarvestModule());
        int logoutOption = modules.size() + 1;
        int choice = 0;
        do {
            cout << "\n CapriGrow Main Menu " << endl;
            for (size_t i = 0; i < modules.size(); i++) {
                cout << i + 1 << ". " << modules[i]->getName() << endl;
            }
            cout << logoutOption << ". Logout" << endl;
            cout << "Choice: ";
            cin >> choice;
            if (!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, enter a number." << endl;
                continue;
            }
            if (choice >= 1 && choice <= (int)modules.size()) {
                modules[choice - 1]->execute();
            }
        } while (choice != logoutOption);
        // free memory
        for (size_t i = 0; i < modules.size(); i++) {
            delete modules[i];
        }
    }
};

int main() {
    CapriGrowSystem farm;
    cout << "CapriGrow Farm Management System " << endl;
    cout << "        Kennedy Kimani | Ene212-0223/2024" << endl << endl;
    if (farm.authenticate()) {
        cout << "\nLogin successful. Welcome back.\n";
        farm.runMenu();
    } else {
        cout << "\nWrong credentials. Try again.\n";
    }
    return 0;
}
