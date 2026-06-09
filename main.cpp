#include <iostream>
#include <string>
using namespace std;
 
string customerName;
string contactNumber;
string orderType;
int persons;
 
string foodItems[8] = {
   "Chicken Burger",
   "Zinger Burger",
   "Pizza Small",
   "Pizza Large",
   "Chicken Biryani",
   "BBQ Platter",
   "Fries",
   "Cold Drink"
};
 
double prices[8] = {
   450, 550, 900, 1800,
   350, 1200, 250, 120
};
 
double totalFoodBill = 0;
 
void registerCustomer()
{
   cout << "Enter Customer Name: ";
   cin.ignore();
   getline(cin, customerName);
 
   cout << "Enter Contact Number: ";
   cin >> contactNumber;
 
   int choice;
 
   cout << "1. Dine-In\n";
   cout << "2. Takeaway\n";
   cout << "Select Order Type: ";
   cin >> choice;
 
   if(choice == 1)
       orderType = "Dine-In";
   else
       orderType = "Takeaway";
 
   cout << "Enter Number of Persons: ";
   cin >> persons;
}
 
void displayFoodMenu()
{
   cout << "\n========== FOOD MENU ==========\n";
 
   for(int i=0; i<8; i++)
   {
       cout << i+1 << ". "
            << foodItems[i]
            << " - Rs. "
            << prices[i]
            << endl;
   }
}
 
void placeOrder()
{
   int itemNo, quantity;
 
   char choice;
 
   do
   {
       displayFoodMenu();
 
       cout << "\nEnter Item Number: ";
       cin >> itemNo;
 
       cout << "Enter Quantity: ";
       cin >> quantity;
 
       totalFoodBill =
       totalFoodBill +
       (prices[itemNo-1] * quantity);
 
       cout << "Add More Items? (Y/N): ";
       cin >> choice;
 
   }while(choice=='Y' || choice=='y');
}
 
double calculateFoodBill()
{
   return totalFoodBill;
}
 
double calculateServiceCharges(double bill)
{
   if(orderType == "Dine-In")
       return bill * 0.10;
   else
       return bill * 0.05;
}
 
double calculateGST(double bill)
{
   return bill * 0.16;
}
 
double calculateDiscount(double bill)
{
   if(bill >= 3000 && bill <= 5000)
       return bill * 0.05;
 
   else if(bill > 5000 && bill <= 10000)
       return bill * 0.10;
 
   else if(bill > 10000)
       return bill * 0.15;
 
   else
       return 0;
}
 
void addFreeDelivery(double total)
{
   if(total > 5000)
   {
       cout << "Free Delivery Added\n";
   }
}
 
void displayFinalBill()
{
   double foodBill = calculateFoodBill();
 
   double serviceCharges =
   calculateServiceCharges(foodBill);
 
   double gst =
   calculateGST(foodBill);
 
   double discount =
   calculateDiscount(foodBill);
 
   double total =
   foodBill +
   serviceCharges +
   gst -
   discount;
 
   cout << "\n========== RESTAURANT BILL ==========\n";
 
   cout << "Customer Name: "
        << customerName << endl;
 
   cout << "Contact Number: "
        << contactNumber << endl;
 
   cout << "Order Type: "
        << orderType << endl;
 
   cout << "Persons: "
        << persons << endl;
 
   cout << "\nFood Bill: Rs. "
        << foodBill << endl;
 
   cout << "Service Charges: Rs. "
        << serviceCharges << endl;
 
   cout << "GST: Rs. "
        << gst << endl;
 
   cout << "Discount: Rs. "
        << discount << endl;
 
   cout << "\nTotal Payable Amount: Rs. "
        << total << endl;
 
   addFreeDelivery(total);
 
   cout << "=====================================\n";
}
 
void displayCustomerDetails()
{
   cout << "\nCustomer Name: "
        << customerName << endl;
 
   cout << "Contact Number: "
        << contactNumber << endl;
 
   cout << "Order Type: "
        << orderType << endl;
 
   cout << "Number of Persons: "
        << persons << endl;
}
 
int main()
{
   registerCustomer();
 
   int choice;
 
   do
   {
       cout << "\n========== MAIN MENU ==========\n";
       cout << "1. View Food Menu\n";
       cout << "2. Place Order\n";
       cout << "3. Calculate Bill\n";
       cout << "4. View Customer Details\n";
       cout << "5. Exit\n";
 
       cout << "Enter Choice: ";
       cin >> choice;
 
       switch(choice)
       {
           case 1:
               displayFoodMenu();
               break;
 
           case 2:
               placeOrder();
               break;
 
           case 3:
               displayFinalBill();
               break;
 
           case 4:
               displayCustomerDetails();
               break;
 
           case 5:
               cout << "Program Closed Successfully.\n";
               break;
 
           default:
               cout << "Invalid Choice!\n";
       }
 
   }while(choice != 5);
 
   return 0;
}
