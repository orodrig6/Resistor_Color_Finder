#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string printcolor(int x) {
	switch (x) { //fed a value between 0 and 9, prints the corresponding color band
	case 0: return "Black";
	case 1: return "Brown";
	case 2: return "Red";
	case 3: return "Orange";
	case 4: return "Yellow";
	case 5: return "Green";
	case 6: return "Blue";
	case 7: return "Violet";
	case 8: return "Gray";
	case 9: return "White";
	}
}

long long int color_band(long long int x) {
	string str_num,str_rounded;
	long long int kirby = x,third_digit,rounded;
	int first_digit, second_digit, power_digit;
	str_num = to_string(x);
	//cout << "String version is: " << x << endl;
	//cout << "Number of digits in number is: " << str_num.length()<< endl;
	if (str_num.length() <= 2) { //if you only give me a 2 or 1 digit number handle it like this
		if(str_num.length()==2)
		first_digit = str_num[0] - 48; 
		else first_digit = 0; // if we have a 1 digit number, first color is always black

		if(str_num.length()==2)
		second_digit = str_num[1] - 48;
		else second_digit = str_num[0]-48; //if we have 1 digit number, second color is whatever digit we have
		power_digit = 0; 
		cout << "Color bands for this resistance are: ";
		cout << printcolor(first_digit) << "\t";
		cout << printcolor(second_digit) << "\t";
		cout << printcolor(power_digit) << "\t";
		cout << endl;
		return kirby;

	}

	third_digit = (long long)str_num[2]-48;
	//cout << "Third digit is: " << third_digit << endl;
	if (third_digit >= 5) {
		kirby += (long long)pow(10, (str_num.length() - 2)); //adds 1 to the second sig fig. will round off next time
}
	str_rounded = to_string(kirby);
	//cout << "Str_rounded Pre is :" << str_rounded;
	for (int i = 2; i < str_rounded.length(); i++) {
		str_rounded[i] = '0'; //set everything after 2nd sig fig to zero
	}
	//cout << "kirby is: " << kirby << endl;
//	cout << "Rounded number is: " << str_rounded << endl;
	rounded = stoll(str_rounded);
	cout << "Rounded resistance is: " << rounded << endl;
	first_digit = str_rounded[0] - 48; //now that we rounded the resistance. we get the first 2 digits
	second_digit = str_rounded[1] - 48;
	power_digit = str_rounded.length() - 2; //the third band is always 2 minus how many total digits there are.
	cout << "Color bands for this resistance are: ";
	cout << printcolor(first_digit) << "\t";
	cout << printcolor(second_digit) << "\t";
	cout << printcolor(power_digit) << "\t";
	cout << endl;


	return kirby;
}


int main(int argc, char* argv[]) {
	long long int num,rounded_num;
	
	cout << "Give me an integer resistance between 0 and 99E9" << endl;
	cin >> num;
	while (num > 99000000000 || num < 0) {
		cout << "Resistance is out of desired range" << endl;
		cout << "Please enter a resistance between 1 and 99E9" << endl;
		cin >> num;
	}
	cout << "Finished successfully, your resistance is:" << num << endl;
	rounded_num = color_band(num);

}