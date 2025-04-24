#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

string getDigitsOnly(string input)
{
    while (true)
    {
        bool valid = true;

        for (char ch : input)
        {
            if (ch < '0' || ch > '9')
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            return input;
        }

        cin.clear();
        cin >> input;
    }
}

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

class Service /// base class for all services
{
public:
    virtual void run() = 0;
    virtual ~Service() = default;
};
class Rewards : public Service
{
public:
    int card_number, mobile_number, pin;

    Rewards(int card_number, int mobile_number, int pin)
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
            activate();
            cout << "rawr";
            break;
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
        cout << "Card Number: ";
        cin >> this->card_number;

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
        cout << "Please enter the mobile number you used for activation" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;

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
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
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
        cout << "Please Enter your mobile number" << endl;
        cin >> this->mobile_number;

        cout << "=====================================" << endl;
        cout << "BARCODE" << endl;
        cout << "=====================================" << endl;
        system("pause");
    }
};
class UtilityWater
{
public:
    string service_type;
    string account_number;
    string account_name;
    double amount;
    double fee;

    UtilityWater(string service_type, string account_number, string account_name, double amount, double fee = 0)
    {
        this->service_type = service_type;
        this->account_number = account_number;
        this->account_name = account_name;
        this->amount = amount;
        this->fee = fee;
    }
    void billsDisplay()
    {
        system("cls");
        int choices;
        cout << "=====================================" << endl;
        cout << "WATER SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Maynilad" << endl;
        cout << "2) Manila Water" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        this->fee = 15.00;
        switch (choices)
        {
        case 1:
        {
            this->service_type = "Maynilad";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 2:
        {
            this->service_type = "Manila Water";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, 0.00, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 0:
            system("cls");
            return;
        default:
        {
            break;
        }
        }
    }
    void billsPay()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << this->service_type << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Account Number: ";
        cin >> this->account_number;
        this->account_number = getDigitsOnly(this->account_number);
        cout << "Subscriber Name(ex.LUZCANTOS): ";
        cin >> this->account_name;
        cout << "Amount: ";
        cin >> this->amount;
    }
};
class UtilityPower : public UtilityWater
{
public:
    UtilityPower(string service_type, string account_number, string account_name, double amount, double fee)
        : UtilityWater(service_type, account_number, account_name, amount, fee) {}
    void billsDisplay()
    {
        system("cls");
        int choices;
        cout << "=====================================" << endl;
        cout << "POWER SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Meralco" << endl;
        cout << "2) IDK" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        this->fee = 15.00;
        switch (choices)
        {
        case 1:
        {
            this->service_type = "Meralco";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 2:
        {
            this->service_type = "IDK";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            break;
        }
        }
    }
    void pay()
    {
        UtilityWater::billsPay();
    }
};
class Telephone : public UtilityWater
{
public:
    Telephone(string service_type, string account_number, string account_name, double amount, double fee)
        : UtilityWater(service_type, account_number, account_name, amount, fee) {}
    void billsDisplay()
    {
        system("cls");
        int choices;
        cout << "=====================================" << endl;
        cout << "TELEPHONE SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) PLDT" << endl;
        cout << "2) Globe" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        this->fee = 15.00;
        switch (choices)
        {
        case 1:
        {
            this->service_type = "PLDT";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 2:
        {
            this->service_type = "Globe";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            break;
        }
        }
    }
    void pay()
    {
        UtilityWater::billsPay();
    }
};
class CellularPhone : public UtilityWater
{
public:
    CellularPhone(string service_type, string account_number, string account_name, double amount, double fee)
        : UtilityWater(service_type, account_number, account_name, amount, fee) {}
    void billsDisplay()
    {
        system("cls");
        int choices;
        cout << "=====================================" << endl;
        cout << "POWER SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Globe" << endl;
        cout << "2) Smart" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        this->fee = 15.00;
        switch (choices)
        {
        case 1:
        {
            this->service_type = "Globe";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 2:
        {
            this->service_type = "Smart";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            break;
        }
        }
    }
    void pay()
    {
        UtilityWater::billsPay();
    }
};
class CableTV : public UtilityWater
{
public:
    CableTV(string service_type, string account_number, string account_name, double amount, double fee)
        : UtilityWater(service_type, account_number, account_name, amount, fee) {}
    void billsDisplay()
    {
        system("cls");
        int choices;
        cout << "=====================================" << endl;
        cout << "CABLE TV SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Sky Cable" << endl;
        cout << "2) Cignal" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        this->fee = 15.00;
        switch (choices)
        {
        case 1:
        {
            this->service_type = "Sky Cable";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 2:
        {
            this->service_type = "Cignal";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            break;
        }
        }
    }
    void pay()
    {
        UtilityWater::billsPay();
    }
};
class Internet : public UtilityWater
{
public:
    Internet(string service_type, string account_number, string account_name, double amount, double fee)
        : UtilityWater(service_type, account_number, account_name, amount, fee) {}
    void billsDisplay()
    {
        system("cls");
        int choices;
        cout << "=====================================" << endl;
        cout << "INTERNET SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) PLDT" << endl;
        cout << "2) Converge" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        this->fee = 15.00;
        switch (choices)
        {
        case 1:
        {
            this->service_type = "PLDT";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 2:
        {
            this->service_type = "Converge";
            billsPay();
            AccountReceipt receipt(this->service_type, this->amount, this->fee, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            break;
        }
        }
    }
    void pay()
    {
        UtilityWater::billsPay();
    }
};
class BillsPayment : public Service
{
public:
    void run() override
    {
        system("cls");
        int choices;
        UtilityWater water("", "", "", 0.00, 0.00);
        UtilityPower power("", "", "", 0.00, 0.00);
        Telephone telephone("", "", "", 0.00, 0.00);
        CellularPhone phone("", "", "", 0.00, 0.00);
        CableTV cable("", "", "", 0.00, 0.00);
        Internet internet("", "", "", 0.00, 0.00);

        cout << "=====================================" << endl;
        cout << "Bills Services" << endl;
        cout << "=====================================" << endl;
        cout << "1)Water Service" << endl;
        cout << "2)Utility Power" << endl;
        cout << "3)Telephone Services" << endl;
        cout << "4)Cellular Phone" << endl;
        cout << "5)Cable TV" << endl;
        cout << "6)Internet" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            water.billsDisplay();
            break;
        }
        case 2:
        {
            power.billsDisplay();
            break;
        }
        case 3:
        {
            telephone.billsDisplay();
            break;
        }
        case 4:
        {
            phone.billsDisplay();
            break;
        }
        case 5:
        {
            cable.billsDisplay();
            break;
        }
        case 6:
        {
            internet.billsDisplay();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:

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

    void pay()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "LOAD" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> mobile_number;
        mobile_number = getDigitsOnly(mobile_number);
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
        cout << "E-PINS" << endl;
        cout << "=====================================" << endl;
        cout << " " << title << " " << endl;

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
        cout << "Mobile Number: ";
        cin >> mobile_number;
        mobile_number = getDigitsOnly(mobile_number);
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

    void transaction(string service_name)
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << service_name << " EMONEY" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> mobile_number;
        mobile_number = getDigitsOnly(mobile_number);
        cout << "Amount: ";
        cin >> amount;

        fee = 0.01;

        EmoneyReceipt receipt(mobile_number, service_name = " EMONEY", amount, fee);
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
            transaction(services[choices - 1]);
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }
};

class Kiosk
{
public:
    string kiosk_services;

    Kiosk(const string kiosk_services)
    {
        this->kiosk_services = kiosk_services;
    }

    void displayMenu()
    {
        system("cls");
        int choice;
        cout << "Please select a service:" << endl;
        cout << "1. Rewards" << endl;
        cout << "2. Bills Payment" << endl;
        cout << "3. Load" << endl;
        cout << "4. E-Pins" << endl;
        cout << "5. E-Money" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Rewards reward(0, 0, 0);
            reward.run();
            displayMenu();
            break;
        }
        case 2:
        {
            BillsPayment bills;
            bills.run();
            displayMenu();
            break;
        }
        case 3:
        {
            Load load("", 0.00, 0.00);
            load.run();
            displayMenu();
            break;
        }
        case 4:
        {
            EPins epins("", 0, 0.00);
            epins.run();
            displayMenu();
            break;
        }
        case 5:
        {
            EMoney emoney("", 0.00, 0.00);
            emoney.run();
            displayMenu();
            break;
        }
        case 0:
            system("cls");
            break;
        default:
            cout << "Invalid choice." << endl;
            system("pause");
            displayMenu();
        }
    }
};

int main()
{
    int userChoice;
    Kiosk kiosk("CLIQQ Services");
    kiosk.displayMenu();

    return 0;
}
