#include <iostream>
#include <string>
using namespace std;

int userNumChooser()
{
	//This function is a simple cin statememt which returns the number the user enters
	cout << "Please enter a number" << endl;

	double userOption;
	cin >> userOption; //reads user input

	return userOption;

}

 double balanceMenu(double userBalance)
 {
	 //adds money to user balance
	 cout << "Please enter amount to top up" << endl;
	 cout << "Note: Minimum amount to order is 5 credits!" << endl;

	 double userOption;
	 cin >> userOption; //reads user input

	 while (cin.fail() || userOption < 1 || userOption > 100) //error checking
	 {
		 cin.clear();
		 cin.ignore(80, '\n'); // after the error
		 // Ask the user once more        
		 cout << "Please only enter a number from 1 to 100" << endl;
		 cin >> userOption;
	 }


	 double newBal = userOption + userBalance; //adds user input to current balance

	 return newBal; //sends back new balance
 }

 string orderSize(double userBalance)
 {
	 bool sizeSelected = false;
	 string sizeChosen;

	 string sizes[3] = { "1. Small","2. Medium", "3. Large" };
	 const double sizesCost[3] = { 3.0, 5.50, 7.25 };

	 cout << "========================" << endl;
	 cout << "Your balance is: " << userBalance << endl;
	 cout << "Please select a size" << endl;
	 cout << "The cost is displayed to the right to the name" << endl;
	 cout << "========================" << endl;

	 for (int i = 0; i < 3; i++)// prints out sizes and costs
	 {
		 cout << sizes[i] << " ";
		 cout << sizesCost[i] << " " << endl;
	 }

	 while (sizeSelected == false)
	 {
		 cout << "Please select your burger size" << endl;
		 int size = userNumChooser();

		 while (cin.fail() || size < 1 || size > 5) //error checking
		 {
			 cin.clear();
			 cin.ignore(80, '\n'); // after the error
			 // Ask the user once more        
			 cout << "Please only enter a number from 1 to 3" << endl;
			 cin >> size;
		 }


		 if (size == 1)
		 {
			 cout << "You have selected small" << endl;
			 sizeChosen = "Small";//stores value
			 sizeSelected = true;
		 }
		 else if (size == 2)
		 {
			 cout << "You have selected medium" << endl;
			 sizeChosen =  "Medium";//stores value
			 sizeSelected = true;
		 }
		 else if (size == 3)
		 {
			 cout << "You have selected small" << endl;
			 sizeChosen = "Large";//stores value
			 sizeSelected = true;
		 }

		 else //error checking
		 {
			 cout << "Invaild option, please try again" << endl;
			 sizeSelected == false;
		 }
	 }

	 if (sizeSelected == true)
	 {
		 return sizeChosen;
	 }

 }

 string orderTopping(double userBalance)
 {
	 bool toppingSelected = false;
	 string toppingChosen;

	 //burger toppings + costs
	 string toppings[6] = { " 1. Cheese", "2. Salad", "3. Bacon", "4. Ketchup", "5. Mayo", "6. Extra Burger" };
	 double toppingCost[6] = { 0.80, 0.50, 1.0, 0.30, 0.30, 1.50 };

	 cout << "========================" << endl;
	 cout << "Your balance is: " << userBalance << endl;
	 cout << "Please select a topping" << endl;
	 cout << "The cost is displayed right to the name" << endl;
	 cout << "========================" << endl;

	 for (int i = 0; i < 6; i++) // prints out toppings and costs
	 {
		 cout << toppings[i] << " ";
		 cout << toppingCost[i] << " " << endl;
	 }

	 int topping = userNumChooser();

	 while (cin.fail() || topping < 1 || topping > 6) //error checking
	 {
		 cin.clear();
		 cin.ignore(80, '\n'); // after the error
		 // Ask the user once more        
		 cout << "Please only enter a number from 1 to 6" << endl;
		 cin >> topping;
	 }

	 if (topping == 1)//
	 {
		 cout << "You have selected Cheese" << endl;
		 toppingChosen = "Cheese";//stores value
		 toppingSelected = true;
	 }
	 else if (topping == 2)
	 {
		 cout << "You have selected Salad" << endl;
		 toppingChosen = "Salad";//stores value
		 toppingSelected = true;
	 }
	 else if (topping == 3)
	 {
		 cout << "You have selected Bacon" << endl;
		 toppingChosen = "Bacon";//stores value
		 toppingSelected = true;
	 }
	 else if (topping == 4)
	 {
		 cout << "You have selected Ketchup" << endl;
		 toppingChosen = "Ketchup";//stores value
		 toppingSelected = true;
	 }
	 else if (topping == 5)
	 {
		 cout << "You have selected Mayo" << endl;
		 toppingChosen = "Mayo";//stores value
		 toppingSelected = true;
	 }
	 else if (topping == 6)
	 {
		 cout << "You have selected Extra Burger" << endl;
		 toppingChosen = "Extra Burger";//stores value
		 toppingSelected = true;
	 }

	 else//error checking
	 {
		 cout << "Invaild option, please try again" << endl;
		 toppingSelected = false;
	 }

	 if (toppingSelected == true)
	 {
		 return toppingChosen;
	 }
	 else
	 {
		 toppingSelected = false;
	 }
 }

 double orderCostMenu(string burgerTopping, string burgerSize)
 {
	 //function sets the prices and calucates the total cost which then returns the result

	 double sizeCost = 0; //stores the selected size cost
	 double toppingCost = 0; //stores the selected topping cost
	 double totalCost; //stores the overall amount

	 cout << "You have selected: " << burgerSize << " with the topping " << burgerTopping << endl; //prints out what user has 

	 //Size Costs:
	 if (burgerSize == "Small")//option
	 {
		 sizeCost = 3.0;//cost
	 }
	 if (burgerSize == "Medium")//option
	 {
		 sizeCost = 5.50;//cost
	 }
	 if (burgerSize == "Large")//option
	 {
		 sizeCost = 7.25;//cost
	 }

	 //Topping Costs:
	 if (burgerTopping == "Cheese")//option
	 {
		 toppingCost = 0.80; //cost
	 }
	 if (burgerTopping == "Salad")//option
	 {
		 toppingCost = 0.50;//cost
	 }
	 if (burgerTopping == "Bacon")//option
	 {
		 toppingCost = 1.0;//cost
	 }
	 if (burgerTopping == "Ketchup")//option
	 {
		 toppingCost = 0.30;//cost
	 }
	 if (burgerTopping == "Mayo")//option
	 {
		 toppingCost = 0.30;//cost
	 }
	 if (burgerTopping == "Extra Burger") //option
	 {
		 toppingCost = 1.50;//cost
	 }

	 totalCost = sizeCost + toppingCost;

	 return totalCost;

 }

 bool checkOut(double userBalance, string burgerSize, string burgerTopping, double userOrderCost) //final check out for users
 { 
	 cout << "========" << endl;
	 cout << "Checkout" << endl;
	 cout << "User balance: " << userBalance << endl;
	 cout << "========" << endl;

	 cout << " Your order is: " << burgerSize << " with " << burgerTopping << endl; //displays order
	 cout << "The cost is: " << userOrderCost << endl; //displays cost of order

	 if (userBalance < userOrderCost) //if the user doesnt have enough money to cover costs, order is cancelled
	 {
		 cout << "insufficient funds, please top up atleast " << userOrderCost << endl;
		 return false;
	 }
	 else if (userBalance >= userOrderCost) //if user has enough money, contuine order:
	 {

		 cout << "Would you like to order?" << endl; // asks if users want to order
		 cout << "1. Yes" << endl;
		 cout << "2. No" << endl;

		 int userOption = userNumChooser();

		 while (cin.fail() || userOption < 1 || userOption > 2) // if user enters incorrect number
		 {
			 cin.clear();
			 cin.ignore(80, '\n'); // after the error
			 // Ask the user once more        
			 cout << "Please only enter a number from 1 to 2" << endl;
			 cin >> userOption;
		 }

		 if (userOption == 1) //contuines order
		 {
			 return true;
		 }

		 else // stops order
		 {
			 return false;
		 }
	 }
 }


int main()
{
	bool orderCompleted = false; //stores if the order is completed
	double userBalance = 0; //stores the user balance

	string burgerSize; // stores the current selected size the user chose
	string burgerTopping; //stores the selected topping the user chose

	double userOrderCost;

	//burger toppings + costs
	string toppings[6] = { "Cheese", "Salad", "Bacon", "Ketchup", "Mayo", "Extra Burger" };
	const double toppingCost[6] = { 0.80, 0.50, 1.0, 0.30, 0.30, 1.50 };

	string sizes[3] = { "small","medium", "large" };
	const double sizesCost[3] = { 3.0, 5.50, 7.25 };

	cout << "Welcome to the burger app!" << endl; //welcome message

	while (orderCompleted == false) //keeps menu going until the order is completed
	{
		//menu settings
		cout << "Main Menu: Please select an option" << endl;
		cout << "Your balance is: " << userBalance << " Credits" << endl;
		cout << "========================" << endl;
		cout << "1. Top-up Balance" << endl;
		cout << "2. Order Burger  " << endl;
		cout << "========================" << endl;

		int userOption = userNumChooser();

		while (cin.fail() || userOption < 1 || userOption > 3) // if user enters incorrect number
		{
			cin.clear();
			cin.ignore(80, '\n'); // after the error
			// Ask the user once more        
			cout << "Please only enter a number from 1 to 3" << endl;
			cin >> userOption;
		}

		if (userOption == 1) // top up balance option
		{
			userBalance = balanceMenu(userBalance); //calls balance function
			cout << "Your new balance is " << userBalance << endl;
		}

		else if (userOption == 2 && userBalance >= 5) //if user has enough credits, call burger order functions
		{

			burgerSize = orderSize(userBalance); // user selects size
			
			burgerTopping = orderTopping(userBalance); // user selects toppings

			userOrderCost = orderCostMenu(burgerTopping, burgerSize); // provides the cost of the order

			cout << "Your cost is " << userOrderCost << endl;
			
			orderCompleted = checkOut(userBalance, burgerSize, burgerTopping, userOrderCost);

			if (orderCompleted == true)
			{
				userBalance = userBalance - userOrderCost;

				cout << "Your new balance is: " << userBalance << endl;
				cout << "Thanks for ordering!" << endl;
	
			}
			else
			{
				cout << "Order cancelled" << endl;
			}

		}
#
		else if (userOption == 2 && userBalance < 5) // if the user has less than 5 credits, tell them to top up account
		{
			cout << "Your balance is below 5 credits, please top up before continuing!" << endl;
		}

		else
		{
			cout << "Please try again" << endl;
		}
	}

}