#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class Receipt
{
public:
    string service_type;
    double amount;
    double fee;
    int receipt_number;
    string date_time;
    Receipt(string service_type, double amount, double fee)
    {
        this->service_type = service_type;
        this->amount = amount;
        this->fee = fee;

        srand(time(0));
        receipt_number = rand() % 1000000 + 100000;

        time_t now = time(0);
        now += 30 * 60;
        date_time = ctime(&now);
    }
    void header() const
    {
        cout << "=====================================" << endl;
        cout << "RECEIPT" << endl;
        cout << "=====================================" << endl;
        cout << "Please bring the slip to the cashier for payment" << endl;
    }
    void footer() const
    {
        cout << "Receipt Number: " << receipt_number << endl;
        cout << "Valid Until: " << date_time << endl;
    }
    virtual void display()
    {
        system("cls");
        header();
        cout << "Service: " << this->service_type << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount + this->fee) << endl;
        footer();

        system("pause");
        system("cls");
    }
};
class AccountReceipt : public Receipt
{
    string account_number, account_name;

public:
    AccountReceipt(string service_type, double amount, double fee, string account_number, string account_name)
        : Receipt(service_type, amount, fee)
    {
        this->account_number = account_number;
        this->account_name = account_name;
    }

    void display() override
    {
        system("cls");
        header();
        cout << "Service: " << this->service_type << endl;
        cout << "Account Number: " << this->account_number << endl;
        cout << "Account Name: " << this->account_name << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount + this->fee) << endl;
        footer();

        system("pause");
        system("cls");
    }
};
class MobileReceipt : public Receipt
{
public:
    string mobile_number;
    MobileReceipt(string mobile_number, string service_type, double amount, double fee)
        : Receipt(service_type, amount, fee)
    {
        this->mobile_number = mobile_number;
    }

    void display() override
    {
        system("cls");
        header();
        cout << "Service: " << this->service_type << endl;
        cout << "Mobile Number: " << this->mobile_number << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount + this->fee) << endl;
        footer();

        system("pause");
    }
};

class EmoneyReceipt : public MobileReceipt
{
public:
    EmoneyReceipt(string mobile_number, string service_type, double amount, double fee)
        : MobileReceipt(mobile_number, service_type, amount, fee) {}

    void display() override
    {
        system("cls");
        header();
        cout << "Service: " << this->service_type << endl;
        cout << "Mobile Number: " << this->mobile_number << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << (this->amount * this->fee) << endl;
        cout << "Total Amount: " << this->amount << endl;
        cout << "Total Loaded: " << this->amount - (this->amount * this->fee) << endl;
        footer();

        system("pause");
    }
};

void numberLimit(string &number, const string &label = "Number", int requiredLength = 11)
{
    bool valid = false;

    // Keep asking for input until it's valid
    while (!valid)
    {
        cout << label << " (" << requiredLength << " digits): ";
        cin >> number;

        // Check if the number has the correct length
        if (number.length() == requiredLength)
        {
            valid = true;
            // Check if every character is a digit
            for (int i = 0; i < number.length(); ++i)
            {
                if (!isdigit(number[i]))
                {
                    valid = false;
                    break;
                }
            }
        }

        // If invalid input, prompt again
        if (!valid)
        {
            cout << "Invalid input! Please enter exactly " << requiredLength << " digits." << endl;
            cin.clear(); // Clear the error flag
        }
    }
}

class Service /// base class for all services
{
public:
    virtual void run() = 0;
    virtual ~Service() = default;
};
class Rewards : public Service

{
public:
    string card_number, mobile_number, pin;

    Rewards(string card_number = "", string mobile_number = "", string pin = "")
    {
        this->card_number = card_number;
        this->mobile_number = mobile_number;
        this->pin = pin;
    }
    void run() override
    {
        int choices;
        system("cls");
        cout << "CLiQQ REWARDS MENU" << endl;
        cout << "1) Activate" << endl;
        cout << "2) Check Balance" << endl;
        cout << "3) Redeem" << endl;
        cout << "4) Print Barcode" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            activate();
            cout << "rawr";
            break;
        }
        case 2:
            checkBalance();
            break;
        case 3:
            redeem();
            break;
        case 4:
            printBarcode();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    void activate()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "CARD ACTIVATION" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your card number" << endl;

        numberLimit(this->card_number, "Card Number", 12);

        cout << endl
             << "CODE ACTIVATED" << endl;
        system("pause");

        cout << endl
             << "CODE ACTIVATED" << endl;
        system("pause");
    }
    void checkBalance()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "CHECK BALANCE" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter the card number you used for activation" << endl;
        numberLimit(this->card_number, "Card Number", 12);

        cout << endl
             << "You have 1000 points" << endl;
        system("pause");
    }
    void redeem()
    {
        system("cls");
        int choices;
        cout << "=====================================" << endl;
        cout << "REWARDS LIST" << endl;
        cout << "=====================================" << endl;
        cout << "1) Crunch Time 1pc Fried Chicken - 178 points" << endl;
        cout << "2) Crunch Time 2pc Fried Chicken - 350 points" << endl;
        cout << "3) Hershey's Dark Chocolate 40g, 50% off - 31 points" << endl;
        cout << "4) Kisses Classic Milk Choco 36g, 50% OFF - 35 points" << endl;
        cout << "5) Hershey's Kisses Cookies N Creme 36g, 50% OFF - 35 points" << endl;
        cout << "6) Siopao Spicy Asado - 90 points" << endl;
        cout << "0) Back" << endl;

        cout << "Please enter the number of the item you want to redeem: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
            redeem_reward("Crunch Time 1pc Fried Chicken");
            break;
        case 2:
            redeem_reward("Crunch Time 2pc Fried Chicken");
            break;
        case 3:
            redeem_reward("Hershey's Dark Chocolate");
            break;
        case 4:
            redeem_reward("Kisses Classic Milk Choco");
            break;
        case 5:
            redeem_reward("Hershey's Kisses Cookies N Creme");
            break;
        case 6:
            redeem_reward("Siopao Spicy Asado");
            break;
        case 0:
            system("cls");
            return;
        default:
            break;
        }

        Receipt receipt("Redeem Reward", 0.00, 0.00);
        receipt.display();
    }
    void redeem_reward(string reward_name)
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "REDEEM REWARD" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        numberLimit(this->mobile_number, "Mobile Number", 11);
        cout << "PIN: ";
        cin >> this->pin;

        Receipt receipt(reward_name, 0.00, 0.00);
        receipt.display();
    }
    void printBarcode()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "PRINT BARCODE" << endl;
        cout << "=====================================" << endl;
        cout << "Enter your mobile number: ";
        cin >> this->mobile_number;

        cout << "=====================================" << endl;
        cout << "BARCODE" << endl;
        cout << "=====================================" << endl;
        system("pause");
    }
};
class UtilityService
{
public:
    string service_type;
    string account_number;
    string account_name;
    double amount;
    double fee;

    UtilityService(string service_type = "", string account_number = "", string account_name = "", double amount = 0.0, double fee = 0.0)
        : service_type(service_type), account_number(account_number), account_name(account_name), amount(amount), fee(fee) {}

    virtual ~UtilityService() {}

    void billsDisplay(vector<string> serviceList, string header, double fee = 15.00)
    {
        system("cls");
        int choice;
        displayHeader(header);
        displayMenu(serviceList);
        cin >> choice;

        if (choice == 0)
        {
            system("cls");
            return;
        }
        else if (choice >= 1 && choice <= serviceList.size())
        {
            this->service_type = serviceList[choice - 1];
            this->fee = fee;
            pay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    void pay()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << this->service_type << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        numberLimit(this->account_number, "Account Number", 13);
        cin.ignore();
        cout << "Subscriber Name (ex. LUZCANTOS): ";
        getline(cin, this->account_name);
        cout << "Amount: ";
        cin >> this->amount;
    }

    void displayHeader(const string &header)
    {
        cout << "=====================================" << endl;
        cout << header << endl;
        cout << "=====================================" << endl;
    }

    void displayMenu(vector<string> &services)
    {
        for (int i = 0; i < services.size(); i++)
        {
            cout << i + 1 << ") " << services[i] << endl;
        }
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
    }
};

class UtilityWater : public UtilityService
{
public:
    UtilityWater() : UtilityService() {}
};

class UtilityPower : public UtilityService
{
public:
    UtilityPower() : UtilityService() {}
};

class Telephone : public UtilityService
{
public:
    Telephone() : UtilityService() {}
};

class CellularPhone : public UtilityService
{
public:
    CellularPhone() : UtilityService() {}
};

class CableTV : public UtilityService
{
public:
    CableTV() : UtilityService() {}
};

class Internet : public UtilityService
{
public:
    Internet() : UtilityService() {}
};
class BillsPayment : public Service
{
public:
    void run() override
    {
        system("cls");
        int choice;
        vector<string> service_types = {"Water Service", "Utility Power", "Telephone Service", "Cellular Phone", "Cable TV", "Internet"};

        cout << "=====================================" << endl;
        cout << "Bills Services" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < service_types.size(); i++)
        {
            cout << i + 1 << ") " << service_types[i] << endl;
        }
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0)
        {
            system("cls");
            return;
        }

        switch (choice)
        {
        case 1:
        {
            UtilityWater water;
            water.billsDisplay({"Maynilad", "Manila Water"}, "WATER SERVICES", 15.00);
            break;
        }
        case 2:
        {
            UtilityPower power;
            power.billsDisplay({"Meralco", "BENECO"}, "POWER SERVICES", 15.00);
            break;
        }
        case 3:
        {
            Telephone telephone;
            telephone.billsDisplay({"PLDT", "Globe Landline"}, "TELEPHONE SERVICES", 15.00);
            break;
        }
        case 4:
        {
            CellularPhone phone;
            phone.billsDisplay({"Smart", "Globe"}, "CELLULAR PHONE SERVICES", 15.00);
            break;
        }
        case 5:
        {
            CableTV cable;
            cable.billsDisplay({"Sky Cable", "Cignal"}, "CABLE TV SERVICES", 15.00);
            break;
        }
        case 6:
        {
            Internet internet;
            internet.billsDisplay({"Converge", "PLDT Home"}, "INTERNET SERVICES", 15.00);
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
};

class Load : public Service
{
public:
    string mobile_number;
    double amount;
    double fee;

    Load(string mobile_number = "", double amount = 0.0, double fee = 5.0)
        : mobile_number(mobile_number), amount(amount), fee(fee) {}

    void pay(double fee = 5.0)
    {
        this->fee = fee;

        system("cls");
        cout << "=====================================" << endl;
        cout << "LOAD" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;

        numberLimit(this->mobile_number, "Mobile Number", 11);

        cout << "Amount: ";
        cin >> amount;
    }

    void loadNetwork(string network)
    {
        pay();
        MobileReceipt receipt(mobile_number, network = " LOAD", amount, fee);
        receipt.display();
    }

    void run() override
    {
        system("cls");
        int choice;
        cout << "=====================================" << endl;
        cout << "LOAD SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Globe" << endl;
        cout << "2) Smart" << endl;
        cout << "3) TNT" << endl;
        cout << "4) Sun" << endl;
        cout << "5) DITO" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            loadNetwork("GLOBE");
            break;
        }

        case 2:
        {
            loadNetwork("SMART");
            break;
        }
        case 3:
        {
            loadNetwork("TNT");
            break;
        }
        case 4:
        {
            loadNetwork("SUN");
            break;
        }
        case 5:
        {
            loadNetwork("DITO");
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }
};

class EPins : public Service
{
public:
    string mobile_number;
    double amount;
    double fee;

    EPins(string mobile_number = "", double amount = 0.0, double fee = 10.0)
        : mobile_number(mobile_number), amount(amount), fee(fee) {}

    void options(string title, string names[], double prices[], int size)
    {
        int choice;
        system("cls");
        cout << "=====================================" << endl;
        cout << title << endl;
        cout << "=====================================" << endl;

        for (int x = 0; x < size; x++)
        {
            cout << x + 1 << ") " << names[x] << " - PHP " << prices[x] << endl;
        }

        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0)
        {
            system("cls");
            return;
        }

        if (choice >= 1 && choice <= size)
        {
            pay();
            MobileReceipt receipt(mobile_number, names[choice - 1], prices[choice - 1], fee);
            receipt.display();
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            options(title, names, prices, size);
        }
    }

    void globe()
    {
        string names[] = {"FAMSURF 50", "GOSURF 99", "GOSURF 299", "GOSURF 599", "GOSURF 999"};
        double prices[] = {50, 99, 299, 599, 999};
        options("GLOBE", names, prices, 5);
    }

    void smart()
    {
        string names[] = {"GIGA50", "ALLNET50", "GIGA99", "GIGA299", "GIGA499"};
        double prices[] = {50, 50, 99, 299, 499};
        options("SMART", names, prices, 5);
    }

    void garena()
    {
        string names[] = {"Garena 50", "Garena 100", "Garena 200", "Garena 300", "Garena 500"};
        double prices[] = {50, 100, 200, 300, 500};
        options("GARENA", names, prices, 5);
    }

    void gameclub()
    {
        string names[] = {"Gameclub 50", "Gameclub 100", "Gameclub 200", "Gameclub 300", "Gameclub 500"};
        double prices[] = {50, 100, 200, 300, 500};
        options("GAMECLUB", names, prices, 5);
    }

    void steam()
    {
        string names[] = {"STEAM 60", "STEAM 120", "STEAM 299", "STEAM 599", "STEAM 960"};
        double prices[] = {60, 120, 299, 599, 960};
        options("STEAM", names, prices, 5);
    }

    void pay()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "EPINS" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;

        numberLimit(this->mobile_number, "Mobile Number", 11);
    }

    void run() override
    {
        int choice;
        system("cls");
        cout << "=====================================" << endl;
        cout << "E-PINS SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Globe" << endl;
        cout << "2) Smart" << endl;
        cout << "3) Garena" << endl;
        cout << "4) Gameclub" << endl;
        cout << "5) Steam" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            globe();
            break;
        }
        case 2:
        {
            smart();
            break;
        }
        case 3:
        {
            garena();
            break;
        }
        case 4:
        {
            gameclub();
            break;
        }
        case 5:
        {
            steam();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            cout << "Invalid choice, please try again." << endl;
            system("pause");
            break;
        }
        }
    }
};

class EMoney : public Load
{
public:
    EMoney(string mobile_number = "", double amount = 0.0, double fee = 0.0)
        : Load(mobile_number, amount, fee) {}

    void pay(string service_name)
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << service_name << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;

        numberLimit(this->mobile_number, "Mobile Number", 11);

        cout << "Amount: ";
        cin >> amount;

        fee = 0.01;

        EmoneyReceipt receipt(mobile_number, " EMONEY", amount, fee);
        receipt.display();
    }

    void run() override
    {
        system("cls");
        int choices;
        vector<string> services;
        services.push_back("Grab");
        services.push_back("Lazada");
        services.push_back("GCash");
        services.push_back("Paymaya");
        services.push_back("Beep");

        cout << "=====================================" << endl;
        cout << "E-MONEY SERVICES" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < services.size(); ++i)
            cout << i + 1 << ") " << services[i] << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        if (choices == 0)
        {
            system("cls");
            return;
        }

        if (choices >= 1 && choices <= services.size())
        {
            pay(services[choices - 1]);
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }
};

int main()
{
    vector<Service *> services;
    services.push_back(new Rewards());
    services.push_back(new BillsPayment());
    services.push_back(new Load());
    services.push_back(new EPins());
    services.push_back(new EMoney());

    int choice;

    while (true)
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "    Welcome to 7-11 Kiosk System    " << endl;
        cout << "=====================================" << endl;
        cout << "Please select a service:" << endl;
        cout << "1. Rewards" << endl;
        cout << "2. Bills Payment" << endl;
        cout << "3. Load" << endl;
        cout << "4. E-Pins" << endl;
        cout << "5. E-Money" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= services.size())
        {
            services[choice - 1]->run();
        }
        else if (choice == 0)
        {
            system("cls");
            cout << "Thank you for using 7-11 Kiosk Services!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
        }
    }

    for (int i = 0; i < services.size(); ++i)
    {
        delete services[i];
    }

    return 0;
}
