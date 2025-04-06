#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Kiosk
{
public:
    string kiosk_services;

    Kiosk(string services)
    {
        this->kiosk_services = kiosk_services;
    }
    void kioskChoices()
    {
        int choices;
        cout << "Please select a service: " << endl;
        cout << "1. Rewards" << endl;
        cout << "2. Bills Payment" << endl;
        cout << "3. Load" << endl;
        cout << "4. E-Pins" << endl;
        cout << "5. E-Money" << endl;
        cout << "6. Parcel Drop-Off" << endl;
        cout << "Enter choice: ";
        cin >> choices;
        switch (choices)
        {
        case 1:
        {
            Rewards reward(0, 0, 0);
            reward.rewards_service();
            break;
        }
        case 2:
        {
            BillsPayment bills("Bills Services");
            bills.billsServices();
            break;
        }
        case 3:
        {
            Load load(0, 0.00);
            load.loadDisplay();
            break;
        }
        case 4:
        {
            cout << "E-Pins" << endl;
            break;
        }
        case 5:
        {
            cout << "E-Money" << endl;
            break;
        }
        case 6:
        {
            cout << "Parcel Drop-Off" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
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
        void receipt_display()
        {
            cout << "=====================================" << endl;
            cout << "RECEIPT" << endl;
            cout << "=====================================" << endl;
            cout << "Please bring the slip to the cashier for payment" << endl;
            cout << this->service_type << endl;                             /*classification like rewards, print barcode, check balance*/
            cout << "Amount: " << this->amount << endl;                     /// amount
            cout << "Convinience Fee: " << this->fee << endl;               /// convinence fee
            cout << "Total Amount: " << (this->amount - this->fee) << endl; /// total amount
            cout << "Receipt Number: " << receipt_number << endl;           /// random barcode number
            cout << "Payment slip valid until " << date_time /* date and time*/ << endl;
        }
    };
    class Receipt2 : public Receipt
    {
    public:
        int account_number;
        string account_name;
        Receipt2(string service_type, double amount, double fee, int account_number, string account_name)
            : Receipt(service_type, amount, fee)
        {
            this->account_number = account_number;
            this->account_name = account_name;
        }
        void receipt2_display()
        {
            cout << "=====================================" << endl;
            cout << "RECEIPT" << endl;
            cout << "=====================================" << endl;
            cout << "Please bring the slip to the cashier for payment" << endl;
            cout << this->service_type << endl; /*classification like rewards, print barcode, check balance*/
            cout << "Account Number: " << this->account_number << endl;
            cout << "Account Name: " << this->account_name << endl;
            cout << "Amount: " << this->amount << endl;                     /// amount
            cout << "Convinience Fee: " << this->fee << endl;               /// convinence fee
            cout << "Total Amount: " << (this->amount - this->fee) << endl; /// total amount
            cout << "Receipt Number: " << receipt_number << endl;           /// random barcode number
            cout << "Payment slip valid until " << date_time /* date and time*/ << endl;
        }
    };

    class Receipt3 : public Receipt
    {
    public:
        int mobile_number;
        Receipt3(int mobile_number, string service_type, double amount, double fee)
            : Receipt(service_type, amount, fee)
        {
            this->mobile_number = mobile_number;
        }
        void receipt2_display()
        {
            cout << "=====================================" << endl;
            cout << "RECEIPT" << endl;
            cout << "=====================================" << endl;
            cout << "Please bring the slip to the cashier for payment" << endl;
            cout << this->service_type << endl; /*classification like rewards, print barcode, check balance*/
            cout << "Mobile Number: " << this->mobile_number << endl;
            cout << "Amount: " << this->amount << endl;                     /// amount
            cout << "Convinience Fee: " << this->fee << endl;               /// convinence fee
            cout << "Total Amount: " << (this->amount - this->fee) << endl; /// total amount
            cout << "Receipt Number: " << receipt_number << endl;           /// random barcode number
            cout << "Payment slip valid until " << date_time /* date and time*/ << endl;
        }
    };

    class Rewards
    {
    public:
        int card_number, mobile_number, pin;

        Rewards(int card_number, int mobile_number, int pin)
        {
            this->card_number = card_number;
            this->mobile_number = mobile_number;
            this->pin = pin;
        }
        void rewards_service()
        {
            int choices;

            cout << "=====================================" << endl;
            cout << "CLiQQ REWARDS" << endl;
            cout << "=====================================" << endl;
            cout << "1) Activate " << endl;
            cout << "2) Check Balance" << endl;
            cout << "3) Redeem" << endl;
            cout << "4) Print Barcode" << endl;
            cout << " Enter choice: ";
            cin >> choices;

            switch (choices)
            {
            case 1:
            {
                activate();
                break;
            }
            case 2:
            {
                checkBalance();
                break;
            }
            case 3:
            {
                redeem();
                break;
            }
            case 4:
            {
                printBarcode();
                break;
            }
            default:
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
            receipt.receipt_display();
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
            receipt.receipt_display();
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
            receipt.receipt_display();
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
            receipt.receipt_display();
        }
        void printBarcode()
        {
            cout << "=====================================" << endl;
            cout << "PRINT BARCODE" << endl;
            cout << "=====================================" << endl;
            cout << "Please Enter your mobile number" << endl;
            cin >> this->mobile_number;

            Receipt receipt("Print Barcode", 0.00, 0.00);
            receipt.receipt_display();
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
                Receipt2 receipt("Maynilad", amount, 0.00, account_number, account_name);
                receipt.receipt2_display();
                break;
            }
            case 2:
            {
                Receipt2 receipt("Manila Water", 0.00, 0.00, 0, "");
                receipt.receipt2_display();
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
                Receipt2 receipt("Meralco", this->amount, 0.00, this->account_number, this->account_name);
                receipt.receipt2_display();
                break;
            }
            case 2:
            {
                Receipt2 receipt("IDK", this->amount, 0.00, this->account_number, this->account_name);
                receipt.receipt2_display();
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

    class BillsPayment
    {
    public:
        string bills_services;

        BillsPayment(string bills_services)
        {
            this->bills_services = bills_services;
        }
        void billsServices()
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

    class Load
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

            Receipt3 receipt(this->mobile_number, "LOAD", this->amount, 0.00);
            receipt.receipt_display();
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
        void loadDisplay()
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

    class EPins
    {
    public:
        string product;

        EPins(string product, int mobile_number)
        {
            this->product = product;
        }
        void globe()
        {
            cout << "=====================================" << endl;
            cout << "E-PINS" << endl;
            cout << "=====================================" << endl;
            cout << " GLOBE " << endl;
            cout << " 1) FAMSURF 50 (Home prepaid WiFi. Up to 5GB valid for 3 days)" << endl;
            cout << " 2)";
        }
        void garena()
        {
        }
        void gameclub()
        {
        }
        void cherry_credits()
        {
        }
        void playpark()
        {
        }
    };

    class EMoney
    {
    public:
        string service;
        string mobileNumber;
        string amount;

        EMoney(string service, string mobileNumber, string amount)
        {
            this->service = service;
            this->mobileNumber = mobileNumber;
            this->amount = amount;
        }
        void grab()
        {
        }
        void lazada()
        {
        }
        void gcash()
        {
        }
        void paymaya()
        {
        }
        void beep()
        {
        }
    };

    class ParcelDropOff
    {
    public:
        string service;
        string receiver;
        string amount;

        ParcelDropOff(string service, string receiver, string amount)
        {
            this->service = service;
            this->receiver = receiver;
            this->amount = amount;
        }
        void canada()
        {
        }
        void uae()
        {
        }
        void usa()
        {
        }
        void uk()
        {
        }
        void japan()
        {
        }
    };
};

int main()
{
    int userChoice;
    Kiosk kiosk("CLIQQ Services");
    kiosk.kioskChoices();

    return 0;
}