#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <limits>

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

    while (!valid)
    {
        cout << label << " (" << requiredLength << " digits): ";
        cin >> number;

        if (number.length() == requiredLength)
        {
            valid = true;

            for (int i = 0; i < number.length(); ++i)
            {
                if (!isdigit(number[i]))
                {
                    valid = false;
                    break;
                }
            }
        }

        if (!valid)
        {
            cout << "Invalid input! Please enter exactly " << requiredLength << " digits." << endl;
            cin.clear();
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
        while (true)
        {
            int choices;
            system("cls");
            cout << "=====================================" << endl;
            cout << "Rewards Menu" << endl;
            cout << "=====================================" << endl;
            cout << "1) Card Activation" << endl;
            cout << "2) Check Balance" << endl;
            cout << "3) Redeem Rewards" << endl;
            cout << "4) Print Barcode" << endl;
            cout << "0) Back" << endl;
            cout << "Enter choice: ";
            cin >> choices;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choices)
            {
            case 1:
                activate();
                break;
            case 2:
                checkBalance();
                break;
            case 3:
                if (redeem())
                    return;
                break;
            case 4:
                printBarcode();
                break;
            case 0:
                system("cls");
                return;
            default:
                continue;
            }
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
    bool redeem()
    {
        while (true)
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

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choices)
            {
            case 1:
            {
                redeem_reward("Crunch Time 1pc Fried Chicken");
                return true;
            }
            case 2:
            {
                redeem_reward("Crunch Time 2pc Fried Chicken");
                return true;
            }
            case 3:
            {
                redeem_reward("Hershey's Dark Chocolate");
                return true;
            }
            case 4:
            {
                redeem_reward("Kisses Classic Milk Choco");
                return true;
            }
            case 5:
            {
                redeem_reward("Hershey's Kisses Cookies N Creme");
                return true;
            }
            case 6:
            {
                redeem_reward("Siopao Spicy Asado");
                return true;
            }
            case 0:
            {
                system("cls");
                return false;
            }
            default:
            {
                continue;
            }
            }
        }
    }
    void redeem_reward(string reward_name)
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "REDEEM REWARD" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        numberLimit(this->mobile_number, "Mobile Number", 11);
        numberLimit(this->pin, "Pin", 6);

        Receipt receipt(reward_name, 0.00, 0.00);
        receipt.display();
    }
    void printBarcode()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "PRINT BARCODE" << endl;
        cout << "=====================================" << endl;
        numberLimit(this->mobile_number, "Mobile Number", 11);

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

    bool billsDisplay(vector<string> serviceList, string header, double fee = 15.00)
    {
        while (true)
        {
            system("cls");
            int choice;
            displayHeader(header);
            displayMenu(serviceList);
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (choice == 0)
            {
                system("cls");
                return false;
            }
            else if (choice >= 1 && choice <= serviceList.size())
            {
                this->service_type = serviceList[choice - 1];
                this->fee = fee;
                pay();
                AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
                receipt.display();
                return true;
            }
            else
            {
                continue;
            }
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
        do
        {
            cout << "Amount: ";
            cin >> this->amount;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid numeric amount." << endl;
            }
            else if (this->amount <= 0)
            {
                cout << "Please enter a positive amount greater than zero." << endl;
            }
        } while (this->amount <= 0 || cin.fail());
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
    UtilityWater(string account_number = "", string account_name = "", double amount = 0.0, double fee = 15.0)
        : UtilityService("Water", account_number, account_name, amount, fee) {}
};

class UtilityPower : public UtilityService
{
public:
    UtilityPower(string account_number = "", string account_name = "", double amount = 0.0, double fee = 15.0)
        : UtilityService("Water", account_number, account_name, amount, fee) {}
};

class Telephone : public UtilityService
{
public:
    Telephone(string account_number = "", string account_name = "", double amount = 0.0, double fee = 15.0)
        : UtilityService("Water", account_number, account_name, amount, fee) {}
};

class CellularPhone : public UtilityService
{
public:
    CellularPhone(string account_number = "", string account_name = "", double amount = 0.0, double fee = 15.0)
        : UtilityService("Water", account_number, account_name, amount, fee) {}
};

class CableTV : public UtilityService
{
public:
    CableTV(string account_number = "", string account_name = "", double amount = 0.0, double fee = 15.0)
        : UtilityService("Water", account_number, account_name, amount, fee) {}
};

class Internet : public UtilityService
{
public:
    Internet(string account_number = "", string account_name = "", double amount = 0.0, double fee = 15.0)
        : UtilityService("Water", account_number, account_name, amount, fee) {}
};
class BillsPayment : public Service
{
public:
    void run() override
    {
        while (true)
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

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice)
            {
            case 1:
            {
                UtilityWater water;
                bool success = water.billsDisplay({"Maynilad", "Manila Water"}, "WATER SERVICES", 15.00);
                if (success)
                    return;
                break;
            }
            case 2:
            {
                UtilityPower power;
                bool success = power.billsDisplay({"Meralco", "BENECO"}, "POWER SERVICES", 15.00);
                if (success)
                    return;
                break;
            }
            case 3:
            {
                Telephone telephone;
                bool success = telephone.billsDisplay({"PLDT", "Globe Landline"}, "TELEPHONE SERVICES", 15.00);
                if (success)
                    return;
                break;
            }
            case 4:
            {
                CellularPhone phone;
                bool success = phone.billsDisplay({"Smart", "Globe"}, "CELLULAR PHONE SERVICES", 15.00);
                if (success)
                    return;
                break;
            }
            case 5:
            {
                CableTV cable;
                bool success = cable.billsDisplay({"Sky Cable", "Cignal"}, "CABLE TV SERVICES", 15.00);
                if (success)
                    return;
                break;
            }
            case 6:
            {
                Internet internet;
                bool success = internet.billsDisplay({"Converge", "PLDT Home"}, "INTERNET SERVICES", 15.00);
                if (success)
                    return;
                break;
            }
            case 0:
            {
                system("cls");
                return;
            }
            default:
            {
                continue;
            }
            }
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

    void pay(string &network)
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "LOAD - " << network << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;

        numberLimit(this->mobile_number, "Mobile Number", 11);

        do
        {
            cout << "Amount: ";
            cin >> this->amount;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid numeric amount." << endl;
            }
            else if (this->amount <= 0)
            {
                cout << "Please enter a positive amount greater than zero." << endl;
            }
        } while (this->amount <= 0 || cin.fail());

        fee = 5.0;

        MobileReceipt receipt(mobile_number, network, amount, fee);
        receipt.display();
    }

    void run() override
    {
        while (true)
        {
            system("cls");
            int choice;
            vector<string> networks = {"Globe", "Smart", "TNT", "Sun", "DITO"};

            cout << "=====================================" << endl;
            cout << "LOAD SERVICES" << endl;
            cout << "=====================================" << endl;

            for (int i = 0; i < networks.size(); ++i)
            {
                cout << i + 1 << ") " << networks[i] << endl;
            }
            cout << "0) Back" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (choice == 0)
            {
                system("cls");
                return;
            }

            if (choice >= 1 && choice <= networks.size())
            {
                pay(networks[choice - 1]);
                return;
            }
            else
            {
                continue;
            }
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

    void pay(const string &service_name, const string &item_name, double item_price)
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << service_name << " - " << item_name << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;

        numberLimit(this->mobile_number, "Mobile Number", 11);
        amount = item_price;

        MobileReceipt receipt(mobile_number, service_name + " - " + item_name, amount, fee);
        receipt.display();
    }

    bool displayOptions(const string &service_name, const vector<string> &names, const vector<double> &prices)
    {
        while (true)
        {
            int choice;
            system("cls");
            cout << "=====================================" << endl;
            cout << "E-PINS - " << service_name << endl;
            cout << "=====================================" << endl;

            for (size_t i = 0; i < names.size(); ++i)
            {
                cout << i + 1 << ") " << names[i] << " - PHP " << prices[i] << endl;
            }

            cout << "0) Back" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (choice == 0)
            {
                return false;
            }

            if (choice >= 1 && choice <= names.size())
            {
                pay(service_name, names[choice - 1], prices[choice - 1]);
                return true;
            }
            else
            {
                continue;
            }
        }
    }

    void run() override
    {
        while (true)
        {
            system("cls");
            int choice;
            vector<string> services = {"Globe", "Smart", "Garena", "Gameclub", "Steam"};

            cout << "=====================================" << endl;
            cout << "E-PINS SERVICES" << endl;
            cout << "=====================================" << endl;

            for (size_t i = 0; i < services.size(); ++i)
            {
                cout << i + 1 << ") " << services[i] << endl;
            }

            cout << "0) Back" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (choice == 0)
            {
                system("cls");
                return;
            }

            if (choice >= 1 && choice <= services.size())
            {
                string selected = services[choice - 1];
                vector<string> names;
                vector<double> prices;

                if (selected == "Globe")
                {
                    names = {"FAMSURF 50", "GOSURF 99", "GOSURF 299", "GOSURF 599", "GOSURF 999"};
                    prices = {50, 99, 299, 599, 999};
                }
                else if (selected == "Smart")
                {
                    names = {"GIGA50", "ALLNET50", "GIGA99", "GIGA299", "GIGA499"};
                    prices = {50, 50, 99, 299, 499};
                }
                else if (selected == "Garena")
                {
                    names = {"Garena 50", "Garena 100", "Garena 200", "Garena 300", "Garena 500"};
                    prices = {50, 100, 200, 300, 500};
                }
                else if (selected == "Gameclub")
                {
                    names = {"Gameclub 50", "Gameclub 100", "Gameclub 200", "Gameclub 300", "Gameclub 500"};
                    prices = {50, 100, 200, 300, 500};
                }
                else if (selected == "Steam")
                {
                    names = {"STEAM 60", "STEAM 120", "STEAM 299", "STEAM 599", "STEAM 960"};
                    prices = {60, 120, 299, 599, 960};
                }

                bool success = displayOptions(selected, names, prices);
                if (success)
                {
                    return;
                }
                else
                {
                    continue;
                }
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

        do
        {
            cout << "Amount: ";
            cin >> this->amount;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid numeric amount." << endl;
            }
            else if (this->amount <= 0)
            {
                cout << "Please enter a positive amount greater than zero." << endl;
            }
        } while (this->amount <= 0 || cin.fail());

        fee = 0.01;

        EmoneyReceipt receipt(mobile_number, " EMONEY", amount, fee);
        receipt.display();
    }

    void run() override
    {
        while (true)
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

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (choices == 0)
            {
                system("cls");
                return;
            }

            if (choices >= 1 && choices <= services.size())
            {
                pay(services[choices - 1]);
                return;
            }
            else
            {
                continue;
            }
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
        cout << "    Welcome to KioskXpress    " << endl;
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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice >= 1 && choice <= services.size())
        {
            services[choice - 1]->run();
        }
        else if (choice == 0)
        {
            system("cls");
            cout << "Thank you for using KioskXpress!" << endl;
            break;
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < services.size(); ++i)
    {
        delete services[i];
    }

    return 0;
}