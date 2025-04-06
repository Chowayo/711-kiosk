#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Receipt
{
public:
    string service_type;
    double amount;
    double fee;
    int receipt_number;
    string date_time;
    Receipt(const string service_type, double amt, double fee)
    {
        this->service_type = service_type;
        this->amount = amt;
        this->fee = fee;

        srand(time(0));
        receipt_number = rand() % 1000000 + 100000;

        time_t now = time(0);
        now += 30 * 60;
        date_time = ctime(&now);
    }
    virtual void display()
    {
        cout << "=====================================" << endl;
        cout << "RECEIPT" << endl;
        cout << "=====================================" << endl;
        cout << "Please bring the slip to the cashier for payment" << endl;
        cout << "Service: " << this->service_type << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount - this->fee) << endl;
        cout << "Receipt Number: " << this->receipt_number << endl;
        cout << "Valid Until: " << date_time << endl;
    }
};

class AccountReceipt : public Receipt
{
    int account_number;
    string account_name;

public:
    AccountReceipt(string type, double amount, double fee, int account_number, string account_name)
        : Receipt(type, amount, fee)
    {
        this->account_number = account_number;
        this->account_name = account_name;
    }

    void display() override
    {
        cout << "=====================================" << endl;
        cout << "RECEIPT" << endl;
        cout << "=====================================" << endl;
        cout << "Please bring the slip to the cashier for payment" << endl;
        cout << "Service: " << this->service_type << endl;
        cout << "Account Number: " << this->account_number << endl;
        cout << "Account Name: " << this->account_name << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount - this->fee) << endl;
        cout << "Receipt Number: " << this->receipt_number << endl;
        cout << "Valid Until: " << date_time << endl;
    }
};

class MobileReceipt : public Receipt
{
    int mobile_number;

public:
    MobileReceipt(int mobile_number, string type, double amount, double fee)
        : Receipt(type, amount, fee)
    {
        this->mobile_number = mobile_number;
    }

    void display() override
    {
        cout << "=====================================" << endl;
        cout << "RECEIPT" << endl;
        cout << "=====================================" << endl;
        cout << "Please bring the slip to the cashier for payment" << endl;
        cout << "Service: " << this->service_type << endl;
        cout << "Mobile Number: " << this->mobile_number << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount - this->fee) << endl;
        cout << "Receipt Number: " << this->receipt_number << endl;
        cout << "Valid Until: " << date_time << endl;
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
        int choice;
        cout << "CLiQQ REWARDS MENU\n";
        cout << "1) Activate" << endl;
        cout << "2) Check Balance" << endl;
        cout << "3) Redeem" << endl;
        cout << "4) Print Barcode" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            activate();
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
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
    void activate()
    {
        cout << "=====================================" << endl;
        cout << "CARD ACTIVATION" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your card number" << endl;
        cout << "Card Number: ";
        cin >> this->card_number;

        Receipt receipt("Rewards Activation", 0.00, 0.00);
        receipt.display();
    }
    void checkBalance()
    {
        cout << "=====================================" << endl;
        cout << "CHECK BALANCE" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter the mobile number you used for activation" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;

        Receipt receipt("Check Balance", 0.00, 0.00);
        receipt.display();
    }
    void redeem()
    {
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

        cout << "Please enter the number of the item you want to redeem: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
            redeem_reward();
            break;
        case 2:
            redeem_reward();
            break;
        case 3:
            redeem_reward();
            break;
        case 4:
            redeem_reward();
            break;
        case 5:
            redeem_reward();
            break;
        case 6:
            redeem_reward();
            break;
        default:
            redeem_reward();
            break;
        }

        Receipt receipt("Redeem Reward", 0.00, 0.00);
        receipt.display();
    }
    void redeem_reward()
    {
        cout << "=====================================" << endl;
        cout << "REDEEM REWARD" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
        cout << "PIN: ";
        cin >> this->pin;

        Receipt receipt("Redeem Reward", 0.00, 0.00);
        receipt.display();
    }
    void printBarcode()
    {
        cout << "=====================================" << endl;
        cout << "PRINT BARCODE" << endl;
        cout << "=====================================" << endl;
        cout << "Please Enter your mobile number" << endl;
        cin >> this->mobile_number;

        Receipt receipt("Print Barcode", 0.00, 0.00);
        receipt.display();
    }
};

class UtilityWater
{
public:
    int account_number;
    string account_name;
    double amount;

    UtilityWater(int account_number, string account_name, double amount)
    {

        this->account_number = account_number;
        this->account_name = account_name;
        this->amount = amount;
    }
    void billsDisplay()
    {
        int choices;

        cout << "=====================================" << endl;
        cout << "WATER SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Maynilad" << endl;
        cout << "2) Manila Water" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        billsPay();

        switch (choices)
        {
        case 1:
        {
            AccountReceipt receipt("Maynilad", amount, 0.00, account_number, account_name);
            receipt.display();
            break;
        }
        case 2:
        {
            AccountReceipt receipt("Manila Water", amount, 0.00, account_number, account_name);
            receipt.display();
            break;
        }
        default:
        {
            break;
        }
        }
    }
    void billsPay()
    {
        cout << "Account Number: ";
        cin >> this->account_number;
        cout << "Subscriber Name(ex.LUZCANTOS): ";
        cin >> this->account_name;
        cout << "Amount: ";
        cin >> this->amount;
    }
};
class UtilityPower : public UtilityWater
{
public:
    UtilityPower(int account_number, string account_name, double amount)
        : UtilityWater(account_number, account_name, amount) {}
    void billsDisplay()
    {
        int choices;

        cout << "=====================================" << endl;
        cout << "POWER SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Meralco" << endl;
        cout << "2) IDK" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        billsPay();

        switch (choices)
        {
        case 1:
        {
            AccountReceipt receipt("Meralco", this->amount, 0.00, this->account_number, this->account_name);
            receipt.display();
            break;
        }
        case 2:
        {
            AccountReceipt receipt("IDK", this->amount, 0.00, this->account_number, this->account_name);
            receipt.display();
            break;
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
class Telephone
{
public:
    string telephone_servies;

    Telephone(string telephone_services)
    {
        this->telephone_servies = telephone_servies;
    }
    void pay()
    {
    }
};
class CellularPhone
{
public:
    string cellular_servies;

    CellularPhone(string cellular_servies)
    {
        this->cellular_servies = cellular_servies;
    }
    void globe()
    {
    }
    void sun()
    {
    }
    void pldt()
    {
    }
    void smart()
    {
    }
    void pay()
    {
    }
};
class CableTV
{
public:
    string cable_servies;

    CableTV(string cable_services)
    {
        this->cable_servies = cable_servies;
    }
    void pay()
    {
    }
};
class Airlines
{
public:
    string airlines_servies;

    Airlines(string airline_services)
    {
        this->airlines_servies = airlines_servies;
    }
    void pay()
    {
    }
};
class Loans
{
public:
    string loans_servies;

    Loans(string loans_services)
    {
        this->loans_servies = loans_servies;
    }
};
class Internet
{
public:
    string internet_servies;

    Internet(string internet_services)
    {
        this->internet_servies = internet_servies;
    }
    void pay()
    {
    }
};
class BillsPayment : public Service
{
public:
    void run() override
    {
        int choice;
        UtilityWater water(0, "", 0.00);
        UtilityPower power(0, "", 0.00);
        Telephone telephone("");
        CellularPhone phone("");
        CableTV cable("");
        Airlines airlines("");
        Internet internet("");

        cout << "=====================================" << endl;
        cout << "Bills Services" << endl;
        cout << "=====================================" << endl;
        cout << "1)Water Service" << endl;
        cout << "2)Utility Power" << endl;
        cout << "3)Telephone Services" << endl;
        cout << "4)Cellular Phone" << endl;
        cout << "5)Cable TV" << endl;
        cout << "6)Airlines" << endl;
        cout << "7)Internet" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            water.billsDisplay();
            break;
        case 2:
            power.billsDisplay();
            break;
        case 3:
            telephone.pay();
            break;
        case 4:
            phone.pay();
            break;
        case 5:
            cable.pay();
            break;
        case 6:
            airlines.pay();
            break;
        case 7:
            internet.pay();
            break;
        default:

            break;
        }
    }
};

class Load : public Service
{
public:
    int mobile_number;
    double amount;

    Load(int mobile_number, double amount)
    {
        this->mobile_number = mobile_number;
        this->amount = amount;
    }
    void globe()
    {
        cout << "=====================================" << endl;
        cout << "LOAD" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
        cout << "Amount: ";
        cin >> this->amount;

        MobileReceipt receipt(this->mobile_number, "LOAD", this->amount, 0.00);
        receipt.display();
    }
    void sun()
    {
        globe();
    }
    void smart()
    {
        globe();
    }
    void tnt()
    {
        globe();
    }
    void dito()
    {
        globe();
    }
    void run() override
    {
        int choice;
        cout << "=====================================" << endl;
        cout << "LOAD SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Globe" << endl;
        cout << "2) Smart" << endl;
        cout << "3) TNT" << endl;
        cout << "4) Sun" << endl;
        cout << "5) DITO" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        Load load(0, 0.00);

        switch (choice)
        {
        case 1:
            load.globe();
            break;
        case 2:
            load.smart();
            break;
        case 3:
            load.tnt();
            break;
        case 4:
            load.sun();
            break;
        case 5:
            load.dito();
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
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
        int choice;
        cout << "\nPlease select a service:" << endl;
        cout << "1. Rewards" << endl;
        cout << "2. Bills Payment" << endl;
        cout << "3. Load" << endl;
        cout << "4. E-Pins" << endl;
        cout << "5. E-Money" << endl;
        cout << "6. Parcel Drop-Off" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Rewards reward(0, 0, 0);
            reward.run();
            break;
        }
        case 2:
        {
            BillsPayment bills;
            bills.run();

            break;
        }
        case 3:
        {
            Load load(0, 0.00);
            load.run();
            break;
        }
        case 4:
            cout << "E-Pins selected.\n";
            break;
        case 5:
            cout << "E-Money selected.\n";
            break;
        case 6:
            cout << "Parcel Drop-Off selected.\n";
            break;
        default:
            cout << "Invalid choice.\n";
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
