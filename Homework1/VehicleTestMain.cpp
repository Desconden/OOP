#include <iostream>
#include <string>
using namespace std;
#include "Vehicle.h"
Vehicle vehicle1;
Vehicle vehicle2;
void TEST_Acceleration(Vehicle& vehicle, double amount)
{
	double previousSpeed = vehicle.getCurrentSpeed();
	if (vehicle.Accelarate(amount))
	{
		cout << "SUCCESS : Accelerated " << endl;
		cout << "Previous Speed : " << previousSpeed << " Current Speed : " <<
			vehicle.getCurrentSpeed() << endl;
	}
	else
	{
		cout << "FAILURE : Could not accelerated" << endl;
	}
}
void TEST_Deceleration(Vehicle& vehicle, double amount)
{
	double temp = vehicle.getCurrentSpeed();
	if (vehicle.Decelerate(amount))
		cout << "SUCCESS : Decelerated" << "\nPrevious Speed : " << temp << " Curent Speed : " << vehicle.getCurrentSpeed() << endl;
	else
		cout << "FAILURE : Could not decelerated" << endl;
}
void TEST_GetIn(Vehicle& vehicle, int passengerNumber)
{
	double previousPassengerNumber = vehicle.getCurrentPassengerNumber();
	if (vehicle.GetIn(passengerNumber)) {
		cout << "SUCCESS : Got-In" << endl
			<< "Previous PassengerNumber : " << previousPassengerNumber << " Current PassengerNumber : " << vehicle.getCurrentPassengerNumber() << endl;
	}
	else 
		cout << "ERROR : Cannot Get-In the vehicle while moving" << "\nFAILURE : Could not got-in" << endl;
}
void TEST_GetOut(Vehicle& vehicle, int passengerNumber)
{
	double previousPassengerNumber = vehicle.getCurrentPassengerNumber();
	if (vehicle.GetOut(passengerNumber))
	{
		cout << "SUCCESS : Got-out" << endl
			<< "Previous PassengerNumber : " << previousPassengerNumber << " Current PassengerNumber : " << vehicle.getCurrentPassengerNumber() << endl;
	}
	else 
		cout << "ERROR : Cannot Get-Out the vehicle while moving" << "\nFAILURE : Could not got-out" << endl;
}
void TEST_StartEngine(Vehicle& vehicle)
{
	cout << "Engine Started" << endl;
	vehicle.StartEngine();
}
void TEST_StopEngine(Vehicle& vehicle)
{
	cout << "Engine Stopped" << endl;
	vehicle.StopEngine();
}
int main()
{
	cout << "+-----------------------+" << endl
		<< "| TEST OF FIRST VEHICLE |" << endl
		<< "+-----------------------+" << endl;
	Vehicle vehicle1(4, 220);
	TEST_StartEngine(vehicle1);
	TEST_Acceleration(vehicle1, 30);
	TEST_Deceleration(vehicle1, 20);
	TEST_GetIn(vehicle1, 2);
	TEST_GetOut(vehicle1, 1);
	TEST_StopEngine(vehicle1);

	cout << "+------------------------+" << endl
		<< "| TEST OF SECOND VEHICLE |" << endl
		<< "+------------------------+" << endl;
	Vehicle vehicle2(5, 180);
	TEST_Acceleration(vehicle2, 30);
	TEST_Deceleration(vehicle2, 20);
	TEST_GetIn(vehicle2, 2);
	TEST_GetOut(vehicle2, 1);
	return 0;
}