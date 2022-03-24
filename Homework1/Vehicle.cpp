#include "Vehicle.h"
Vehicle::Vehicle(int maxPassengerNumber, double maxSpeed)
{
	this->maxSpeed = maxSpeed;
	this->maxPassengerNumber = maxPassengerNumber;
	this->engineStarted = false;
	this->currentSpeed = 0;
	this->currentPassengerNumber = 0;
}
Vehicle::~Vehicle()
{
}
bool Vehicle::Accelarate(double amount)
{
	if (engineStarted == true && currentSpeed + amount <= maxSpeed) {
		currentSpeed += amount;
		return true;
	}
	else if (currentSpeed + amount >= maxSpeed) {
		currentSpeed = maxSpeed;
		return true;
	}
		else return false;
}
bool Vehicle::Decelerate(double amount)
{
	if (engineStarted == true && currentSpeed != 0) {
		currentSpeed -= amount;
		return true;
	}
	else return false;
}
void Vehicle::StartEngine()
{
	engineStarted = true;
}
void Vehicle::StopEngine()
{
	engineStarted = false;
}
bool Vehicle::GetIn(int passengerNumber)
{
	if (currentSpeed == 0 && currentPassengerNumber + passengerNumber <= maxPassengerNumber) {
		currentPassengerNumber += passengerNumber;
		return true;
	}
	else 
		return false;
}
bool Vehicle::GetOut(int passengerNumber)
{
	if (currentSpeed == 0 && currentPassengerNumber - passengerNumber >= 0) {
		currentPassengerNumber -= passengerNumber;
		return true;
	}
	else 
		return false;
}
double Vehicle::getCurrentSpeed()
{
	return currentSpeed;
}
double Vehicle::getCurrentPassengerNumber()
{
	return currentPassengerNumber;
}
bool Vehicle::IsEngineStarted()
{
	return engineStarted;
}