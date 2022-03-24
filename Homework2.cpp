#include <iostream>
using namespace std;
int oneD = 0, twoD = 0;
class complexNumbers {
private:
	int a;
	int b;
public:
	complexNumbers() { //Default Constructer
		a = 2;
		b = 4;
	}
	complexNumbers(int A, int B) { //Constructor with parameters
		a = A;
		b = B;
	}//To access private**********************************
	void set_a(int A) {
		a = A;
	}
	void set_b(int B) {
		b = B;
	}
	int get_a() {
		return a;
	}
	int get_b() {
		return b;
	}//****************************************************

	int get_AV(complexNumbers& obj) { // To get the modulus.
		int modulus;
		modulus = obj.a*obj.a + obj.b*obj.b;
		return modulus;

	}//All of the changed operators**************************
	complexNumbers operator+(complexNumbers& obj) {
		complexNumbers result;
		result.a = obj.a + a;
		result.b = obj.b + b;
		return result;
	}
	complexNumbers operator-(complexNumbers& obj) {
		complexNumbers result;
		result.a = obj.a - a;
		result.b = obj.b - b;
		return result;
	}
	complexNumbers operator*(complexNumbers& obj) {
		complexNumbers result;
		result.a = obj.a * a;
		result.b = obj.b * b;
		return result;
	}
	friend istream& operator>>(istream& input, complexNumbers& obj) {
		input >> obj.a >> obj.b;
		return input;
	}
	friend ostream& operator<<(ostream& output, complexNumbers& obj) {
		if (obj.a != 0 && obj.b != 0) {
			cout << obj.a << " + " << obj.b << "i";
		}
		else if (obj.a == 0 && obj.b != 0) {
			cout << obj.b << "i";
		}
		return output;
	}
	/*
	int operatornew(complexNumbers& obj) {
		int modulus;
		modulus = obj.a*obj.a + obj.b*obj.b;
		return modulus;
	}
	*///******************************************************
};
//Base Class of myArray for one and two dimesional arrays
class myArray : public complexNumbers {
public:
	int onedimension[100];
	int twodimension[100][3];
};
class OneDimension : public myArray {
public:
	void O_AddMember(int num) {
		onedimension[oneD] = num; //Add the modulus
		oneD++; //increses count
	}
	void sort() { //Insertion sort algorithm
		for (int i = 1; i < oneD; i++) {
			int key = onedimension[i];
			int j = i - 1;
			while (i >= 0 && onedimension[j] > key) {
				onedimension[j + 1] = onedimension[j];
				j = j - 1;
				onedimension[j + 1] = key;
			}
		}
	}
};
class TwoDimension : public myArray {
public:
	void T_AddMember(int num) {
		twodimension[twoD][0] = num;        //Store the modulus
		twodimension[twoD][1] = get_a();   //Store the number
		twodimension[twoD][2] = get_b();  //Store the complex number
		twoD++;
	}
	void sort() { //Insertion sort algorithm
		for (int i = 1; i < oneD; i++) {
			int key = twodimension[i][0];
			int j = i - 1;
			while (i >= 0 && twodimension[j][0] > key) {
				twodimension[j + 1][0] = twodimension[j][0];
				j = j - 1;
				twodimension[j + 1][0] = key;
			}
		}
	}
};
complexNumbers cn1;
complexNumbers cn2;
complexNumbers cn3;
OneDimension ODimension;
TwoDimension TDimension;
//Test Driver **********************************************************************************************************************************************************************************************
int main() {
	int selection, temp;
	cout << "\n Enter the complex number(a + b (b is complex)) :";
	cin >> cn1;
	while (1) {
		cout << "\n\n**Your Number: " << cn1 << " **\n";
		cout << "\n 1. Store the complex number's absolute value(1D array). \n 2. Store the complex number's absolute value and a + bi format." <<
			"\n 3. Summation with another complex number. \n 4. Subtract a complex number. \n 5. Multiply with another complex number. \n 6. Print Array Lists \n 7. New Number \n 8. Exit.\n Selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
			temp = cn1.get_AV(cn1); //Gets the modulus from the base class because value a and b is private of base class
			ODimension.O_AddMember(temp); //Sends the temp to the function
			ODimension.sort(); //sorts the array after every entry.
			break;
		case 2:
			temp = cn1.get_AV(cn1); //Gets the modulus from the base class because value a and b is private of base class
			TDimension.T_AddMember(temp); //Sends the temp to the function
			TDimension.sort(); //sorts the array after every entry.
			break;
		case 3:
			cout << "Enter the number: "; //Does the mathematical operation based on the operator I changed
			cin >> cn2;
			cn3 = cn1 + cn2;
			cn1 = cn3;
			break;
		case 4:
			cout << "Enter the number: "; //Does the mathematical operation based on the operator I changed
			cin >> cn2;
			cn3 = cn2 - cn1;
			cn1 = cn3;
			break;
		case 5:
			cout << "Enter the number: "; //Does the mathematical operation based on the operator I changed
			cin >> cn2;
			cn3 = cn1 * cn2;
			cn1 = cn3;
			break;
		case 6:
			cout << "\n List of Onedimensional Array : ";
			if (oneD == 0) //Checks if array is empty
				cout << "\n One DimensionalArray is empty.";
			else
			for (int i = 0; i < oneD; i++) {
				cout << "\n " << i + 1 << ". Absolute Value: sqrt("<< ODimension.onedimension[i] << ")";
			}
			if (twoD == 0) //Checks if array is empty
				cout << "\n\n Two Dimensional Array is empty.";
			else
			for (int i = 0; i < oneD; i++) {
				cout << "\n " << i + 1 << ". Absolute Value: sqrt(" << TDimension.twodimension[i][0] << ")"; //prints modulus
				cout << "    " << i + 1 << TDimension.twodimension[i][1]; //prints elements of complex number that was stored
				cout << " + i" << i + 1 << TDimension.twodimension[i][2];
			}
			break;
		case 7: // To get new complex number
			cout << "\n Enter the new complex number(a + b (b is complex)) :";
			cin >> cn1;
			break;
		case 8:
			return 0;
		default: //Default for the incorrect entries
			cout << "\n Please make a proper selection.";
			break;
		}
	}
}//*******************************************************************************************************************************************************************************************************************