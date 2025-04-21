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
    Receipt(const string service_type, double amount, double fee)
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
    virtual void display()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "RECEIPT" << endl;
        cout << "=====================================" << endl;
        cout << "Please bring the slip to the cashier for payment" << endl;
        cout << "Service: " << this->service_type << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount + this->fee) << endl;
        cout << "Receipt Number: " << this->receipt_number << endl;
        cout << "Valid Until: " << date_time << endl;

        system("pause");
        system("cls");
    }
};

class AccountReceipt : public Receipt
{
    int account_number;
    string account_name;

public:
    AccountReceipt(string service_type, double amount, double fee, int account_number, string account_name)
        : Receipt(service_type, amount, fee)
    {
        this->account_number = account_number;
        this->account_name = account_name;
    }

    void display() override
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "RECEIPT" << endl;
        cout << "=====================================" << endl;
        cout << "Please bring the slip to the cashier for payment" << endl;
        cout << "Service: " << this->service_type << endl;
        cout << "Account Number: " << this->account_number << endl;
        cout << "Account Name: " << this->account_name << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount + this->fee) << endl;
        cout << "Receipt Number: " << this->receipt_number << endl;
        cout << "Valid Until: " << date_time << endl;

        system("pause");
        system("cls");
    }
};

class MobileReceipt : public Receipt
{
public:
    int mobile_number;
    MobileReceipt(int mobile_number, string service_type, double amount, double fee)
        : Receipt(service_type, amount, fee)
    {
        this->mobile_number = mobile_number;
    }

    void display() override
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "RECEIPT" << endl;
        cout << "=====================================" << endl;
        cout << "Please bring the slip to the cashier for payment" << endl;
        cout << "Service: " << this->service_type << endl;
        cout << "Mobile Number: " << this->mobile_number << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << fee << endl;
        cout << "Total Amount: " << (this->amount + this->fee) << endl;
        cout << "Receipt Number: " << this->receipt_number << endl;
        cout << "Valid Until: " << date_time << endl;

        system("pause");
    }
};
class EmoneyReceipt : public MobileReceipt
{
public:
    EmoneyReceipt(int mobile_number, string service_type, double amount, double fee)
        : MobileReceipt(mobile_number, service_type, amount, fee) {}

    void display() override
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "RECEIPT" << endl;
        cout << "=====================================" << endl;
        cout << "Please bring the slip to the cashier for payment" << endl;
        cout << "Service: " << this->service_type << endl;
        cout << "Mobile Number: " << this->mobile_number << endl;
        cout << "Amount: " << this->amount << endl;
        cout << "Convenience Fee: " << (this->amount * this->fee) << endl;
        cout << "Total Amount: " << this->amount << endl;
        cout << "Total Loaded: " << this->amount - (this->amount * this->fee) << endl;
        cout << "Receipt Number: " << this->receipt_number << endl;
        cout << "Valid Until: " << date_time << endl;

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
        cout << "CLiQQ REWARDS MENU\n";
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
            cout << "Invalid choice.\n";
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
    int account_number;
    string account_name;
    double amount;
    double fee;

    UtilityWater(string service_type, int account_number, string account_name, double amount, double fee = 0)
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
        cout << "Subscriber Name(ex.LUZCANTOS): ";
        cin >> this->account_name;
        cout << "Amount: ";
        cin >> this->amount;
    }
};
class UtilityPower : public UtilityWater
{
public:
    UtilityPower(string service_type, int account_number, string account_name, double amount, double fee)
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
    Telephone(string service_type, int account_number, string account_name, double amount, double fee)
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
    CellularPhone(string service_type, int account_number, string account_name, double amount, double fee)
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
    CableTV(string service_type, int account_number, string account_name, double amount, double fee)
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
    Internet(string service_type, int account_number, string account_name, double amount, double fee)
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
        UtilityWater water("", 0, "", 0.00, 0.00);
        UtilityPower power("", 0, "", 0.00, 0.00);
        Telephone telephone("", 0, "", 0.00, 0.00);
        CellularPhone phone("", 0, "", 0.00, 0.00);
        CableTV cable("", 0, "", 0.00, 0.00);
        Internet internet("", 0, "", 0.00, 0.00);

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
    int mobile_number;
    double amount;
    double fee;

    Load(int mobile_number, double amount, double fee)
    {
        this->mobile_number = mobile_number;
        this->amount = amount;
        this->fee = 5.00;
    }
    void globe()
    {
        pay();

        MobileReceipt receipt(this->mobile_number, "GLOBE LOAD", this->amount, this->fee);
        receipt.display();
    }
    void sun()
    {
        pay();

        MobileReceipt receipt(this->mobile_number, "SUN LOAD", this->amount, this->fee);
        receipt.display();
    }
    void smart()
    {
        pay();

        MobileReceipt receipt(this->mobile_number, "SMART LOAD", this->amount, this->fee);
        receipt.display();
    }
    void tnt()
    {
        pay();

        MobileReceipt receipt(this->mobile_number, "TNT LOAD", this->amount, this->fee);
        receipt.display();
    }
    void dito()
    {
        pay();

        MobileReceipt receipt(this->mobile_number, "DITO LOAD", this->amount, this->fee);
        receipt.display();
    }
    void pay()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "LOAD" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
        cout << "Amount: ";
        cin >> this->amount;
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

        Load load(0, 0.00, 0.00);

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
        case 0:
            system("cls");
            return;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }
};
class EPins : public Service
{
public:
    int mobile_number;
    double amount;
    double fee;

    EPins(int mobile_number, double amount, double fee)
    {
        this->mobile_number = mobile_number;
        this->amount = amount;
        this->fee = 10.00;
    }

    void globe()
    {
        int choices;
        system("cls");
        cout << "=====================================" << endl;
        cout << "E-PINS" << endl;
        cout << "=====================================" << endl;
        cout << " GLOBE " << endl;
        cout << "1) FAMSURF 50 (Home prepaid WiFi. Up to 5GB valid for 3 days) - PHP 50" << endl;
        cout << "2) GOSURF 99 (1GB data valid for 7 days) - PHP 99" << endl;
        cout << "3) GOSURF 299 (3GB data valid for 30 days) - PHP 299" << endl;
        cout << "4) GOSURF 599 (5GB data valid for 30 days) - PHP 599" << endl;
        cout << "5) GOSURF 999 (10GB data valid for 30 days) - PHP 999" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            pay();

            MobileReceipt famsurf50(this->mobile_number, "FAMSURF 50", 50, this->fee);
            famsurf50.display();

            break;
        }
        case 2:
        {
            pay();

            MobileReceipt gosurf99(this->mobile_number, "GOSURF 99", 99, this->fee);
            gosurf99.display();
            break;
        }
        case 3:
        {
            pay();

            MobileReceipt gosurf299(this->mobile_number, "GOSURF 299", 299, this->fee);
            gosurf299.display();
            break;
        }
        case 4:
        {
            pay();

            MobileReceipt gosurf599(this->mobile_number, "GOSURF 599", 599, this->fee);
            gosurf599.display();
            break;
        }
        case 5:
        {
            pay();

            MobileReceipt gosurf999(this->mobile_number, "GOSURF 999", 999, this->fee);
            gosurf999.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            globe();
            return;
        };
        }
    }
    void smart()
    {
        int choices;
        system("cls");
        cout << "=====================================" << endl;
        cout << "E-PINS" << endl;
        cout << "=====================================" << endl;
        cout << " GLOBE " << endl;
        cout << "1) GIGA50	(2GB Data + 1GB YouTube 3 days) - PHP 50" << endl;
        cout << "2) ALLNET50 (Unlimited all-net texts + 50 mins calls + 500MB data 3 days) - PHP 50" << endl;
        cout << "3) GIGA99	(2GB/day on select apps 7 days)	- PHP 99" << endl;
        cout << "4) GIGA299	(2GB/day on select apps 30 days) - PHP 299" << endl;
        cout << "5) GIGA499	(4GB/day 30 days) - PHP 499" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            pay();

            MobileReceipt giga50(this->mobile_number, "GIGA 50", 50, this->fee);
            giga50.display();

            break;
        }
        case 2:
        {
            pay();

            MobileReceipt allnet50(this->mobile_number, "ALL NET 50", 99, this->fee);
            allnet50.display();
            break;
        }
        case 3:
        {
            pay();

            MobileReceipt giga99(this->mobile_number, "GIGA 99", 299, this->fee);
            giga99.display();
            break;
        }
        case 4:
        {
            pay();

            MobileReceipt giga299(this->mobile_number, "GIGA 299", 599, this->fee);
            giga299.display();
            break;
        }
        case 5:
        {
            pay();

            MobileReceipt giga499(this->mobile_number, "GIGA 499", 999, this->fee);
            giga499.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            globe();
            return;
        };
        }
    }

    void garena()
    {
        int choices;
        system("cls");
        cout << "=====================================" << endl;
        cout << "E-PINS" << endl;
        cout << "=====================================" << endl;
        cout << " GARENA " << endl;
        cout << "1) GARENA 50 (Pin will be sent via SMS) - PHP 50" << endl;
        cout << "2) GARENA 100 (Pin will be sent via SMS) - PHP 100" << endl;
        cout << "3) GARENA 200 (Pin will be sent via SMS) - PHP 200" << endl;
        cout << "4) GARENA 300 (Pin will be sent via SMS) - PHP 300" << endl;
        cout << "5) GARENA 500 (Pin will be sent via SMS) - PHP 500" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            pay();

            MobileReceipt garena50(this->mobile_number, "Garena 50", 50, this->fee);
            garena50.display();

            break;
        }
        case 2:
        {
            pay();

            MobileReceipt garena100(this->mobile_number, "Garena 100", 100, this->fee);
            garena100.display();
            break;
        }
        case 3:
        {
            pay();

            MobileReceipt garena200(this->mobile_number, "Garena 200", 299, this->fee);
            garena200.display();
            break;
        }
        case 4:
        {
            pay();

            MobileReceipt garena300(this->mobile_number, "Garena 300", 599, this->fee);
            garena300.display();
            break;
        }
        case 5:
        {
            pay();

            MobileReceipt garena500(this->mobile_number, "Garena 500", 999, this->fee);
            garena500.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            globe();
            return;
        };
        }
    }
    void gameclub()
    {
        int choices;
        system("cls");
        cout << "=====================================" << endl;
        cout << "E-PINS" << endl;
        cout << "=====================================" << endl;
        cout << " Gameclub " << endl;
        cout << "1) GAMECLUB 50 (Pin will be sent via SMS) - PHP 50" << endl;
        cout << "2) GAMECLUB 100 (Pin will be sent via SMS) - PHP 100" << endl;
        cout << "3) GAMECLUB 200 (Pin will be sent via SMS) - PHP 200" << endl;
        cout << "4) GAMECLUB 300 (Pin will be sent via SMS) - PHP 300" << endl;
        cout << "5) GAMECLUB 500 (Pin will be sent via SMS) - PHP 500" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            pay();

            MobileReceipt gc50(this->mobile_number, "Gameclub 50", 50, this->fee);
            gc50.display();

            break;
        }
        case 2:
        {
            pay();

            MobileReceipt gc100(this->mobile_number, "Gameclub 100", 100, this->fee);
            gc100.display();
            break;
        }
        case 3:
        {
            pay();

            MobileReceipt gc200(this->mobile_number, "Gameclub 200", 200, this->fee);
            gc200.display();
            break;
        }
        case 4:
        {
            pay();

            MobileReceipt gc300(this->mobile_number, "Gameclub 300", 300, this->fee);
            gc300.display();
            break;
        }
        case 5:
        {
            pay();

            MobileReceipt gc500(this->mobile_number, "Gameclub 500", 500, this->fee);
            gc500.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            globe();
            return;
        };
        }
    }
    void steam()
    {
        int choices;
        system("cls");
        cout << "=====================================" << endl;
        cout << "E-PINS" << endl;
        cout << "=====================================" << endl;
        cout << " STEAM " << endl;
        cout << "1) STEAM 60 (50 worth of Steam Credits) - PHP 60" << endl;
        cout << "2) STEAM 120 (100 worth of Steam Credits) - PHP 120" << endl;
        cout << "3) STEAM 299 (250 worth of Steam Credits) - PHP 299" << endl;
        cout << "4) STEAM 599 (500 worth of Steam Credits) - PHP 599" << endl;
        cout << "5) STEAM 960 (800 worth of Steam Credits) - PHP 960" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        switch (choices)
        {
        case 1:
        {
            pay();

            MobileReceipt steam60(this->mobile_number, "STEAM 60", 60, this->fee);
            steam60.display();

            break;
        }
        case 2:
        {
            pay();

            MobileReceipt steam120(this->mobile_number, "STEAM 120", 120, this->fee);
            steam120.display();
            break;
        }
        case 3:
        {
            pay();

            MobileReceipt steam299(this->mobile_number, "STEAM 299", 299, this->fee);
            steam299.display();
            break;
        }
        case 4:
        {
            pay();

            MobileReceipt steam599(this->mobile_number, "STEAM 599", 599, this->fee);
            steam599.display();
            break;
        }
        case 5:
        {
            pay();

            MobileReceipt steam960(this->mobile_number, "STEAM 960", 960, this->fee);
            steam960.display();
            break;
        }
        case 0:
        {
            system("cls");
            return;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            globe();
            return;
        };
        }
    }
    void pay()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "EPINS" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
    }

    void run() override
    {
        int choices;
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
        cin >> choices;

        EPins epins(0, 0.00, 0.00);

        switch (choices)
        {
        case 1:
            epins.globe();
            break;
        case 2:
            epins.smart();
            break;
        case 3:
            epins.garena();
            break;
        case 4:
            epins.gameclub();
            break;
        case 5:
            epins.steam();
            break;
        case 0:
            system("cls");
            return;
        default:
            cout << "Invalid choice, please try again." << endl;
            system("pause");
            break;
        }
    }
};

class EMoney : public Load
{
public:
    EMoney(int mobile_number, double amount, double fee) : Load(mobile_number, amount, fee)
    {
        this->mobile_number = mobile_number;
        this->amount = amount;
        this->fee = 0.01;
    }
    void grab()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "GRAB EMONEY" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
        cout << "Amount: ";
        cin >> this->amount;

        EmoneyReceipt receipt(this->mobile_number, "GRAB EMONEY", this->amount, this->fee);
        receipt.display();
    }
    void lazada()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "LAZADA EMONEY" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
        cout << "Amount: ";
        cin >> this->amount;

        EmoneyReceipt receipt(this->mobile_number, "LAZADA EMONEY", this->amount, this->fee);
        receipt.display();
    }
    void gcash()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "GCASH EMONEY" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
        cout << "Amount: ";
        cin >> this->amount;

        EmoneyReceipt receipt(this->mobile_number, "GCASH EMONEY", this->amount, this->fee);
        receipt.display();
    }
    void paymaya()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "PAYMAYA EMONEY" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
        cout << "Amount: ";
        cin >> this->amount;

        EmoneyReceipt receipt(this->mobile_number, "PAYMAYA EMONEY", this->amount, this->fee);
        receipt.display();
    }
    void beep()
    {
        system("cls");
        cout << "=====================================" << endl;
        cout << "BEEP EMONEY" << endl;
        cout << "=====================================" << endl;
        cout << "Please enter your information" << endl;
        cout << "Mobile Number: ";
        cin >> this->mobile_number;
        cout << "Amount: ";
        cin >> this->amount;

        EmoneyReceipt receipt(this->mobile_number, "BEEP EMONEY", this->amount, this->fee);
        receipt.display();
    }

    void run() override
    {
        system("cls");
        int choices;
        cout << "=====================================" << endl;
        cout << "E-MONEY SERVICES" << endl;
        cout << "=====================================" << endl;
        cout << "1) Grab" << endl;
        cout << "2) Lazada" << endl;
        cout << "3) GCash" << endl;
        cout << "4) Paymaya" << endl;
        cout << "5) Beep" << endl;
        cout << "0) Back" << endl;
        cout << "Enter choice: ";
        cin >> choices;

        EMoney emoney(0, 0.00, 0.00);

        switch (choices)
        {
        case 1:
            emoney.grab();
            break;
        case 2:
            emoney.lazada();
            break;
        case 3:
            emoney.gcash();
            break;
        case 4:
            emoney.paymaya();
            break;
        case 5:
            emoney.beep();
            break;
        case 0:
            system("cls");
            return;
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
        system("cls");
        int choice;
        cout << "\nPlease select a service:" << endl;
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
            Load load(0, 0.00, 0.00);
            load.run();
            displayMenu();
            break;
        }
        case 4:
        {
            EPins epins(0, 0, 0.00);
            epins.run();
            displayMenu();
            break;
        }
        case 5:
        {
            EMoney emoney(0, 0.00, 0.00);
            emoney.run();
            displayMenu();
            break;
        }
        case 0:
            system("cls");
            break;
        default:
            cout << "Invalid choice.\n";
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
