#include <iostream>;
#include<string>;
#include"stdafx.h";
#include "BigNumFunc.h";
#include <vector>;



namespace BigNumFunc {

	/////////////////////////
	//Addition function/////
	///////////////////////
	std::string BigNumFuncClass::AddFunc(std::string a, std::string b)
	{
		std::string result = "";
		int carry = 0;

		if (a.length() > b.length()) {//swaps the two strings if a is greater in length than b
			swap(a, b);
		}

		int length1 = a.length();//finds length of first string
		int length2 = b.length();//findslength of second string

		reverse(a.begin(), a.end());//reverses the strings in order to add the numbers in the proper order
		reverse(b.begin(), b.end());

		
		for (int i = 0; i < length2; i++) {
			int num1 = (a[i] - '0');//converts charector number into a usable integer number
			int num2 = (b[i] - '0');

			int sum =  num1 + num2 + carry;//math is done here
			if (sum > 9) {//if the sum of two numbers is 10 or greater it will be subtracted by 10 and carried over to the next number
				carry = 1;//sets the carry value to 1 for the next addition operation
				result.push_back(sum-10 + '0' );//pushes the sum to the result string minus 10
			}
			if (sum < 10) {// if the sum is less than 10 nothing changes
				carry = 0;
				result.push_back(sum + '0');//push sum int the result string
			}
			
		}

		for (int i =length1; i < length2; i++) {// if string b still has numbers but string a doesn't they will be added to the result string here
		 
			int num2 = (b[i] - '0');//converts and stores charecter in string b to integer
			
			int sum = num2 + carry;// math is done
			if (sum > 9) {
				carry = 1;
				result.push_back(sum - 10 + '0');
			}
			if (sum < 9) {
				carry = 0;
				result.push_back(sum + '0');
			}

		}

		if (carry > 0) {// if there is still an unused carry it will be pushed into the string last
			result.push_back(carry + '0');
		}

		reverse(result.begin(), result.end());//since the string was feed numbers in reverse order the string must be reversed

		return result;// return result string

	}

	//////////////////////////////
	//function for subtraction////
	//////////////////////////////
	std::string BigNumFuncClass::SubFunc(std::string a, std::string b) {

		std::string result = "";//intiates result string
		int carry = 0;

		if (a.length() < b.length()) {
			swap(a, b);//swaps string b and a if b is greater than a
			result.push_back('-');// if string b is bigger than string a negative symbol will be added to string result
		}

		int length1 = a.length();//take the length of string a and b
		int length2 = b.length();

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());//reverse both a and b so that they can be operated on in the proper order

		for (int i = 0; i < length1; i++) {
			int num1 = a[i] - '0';//convert charecter to integer
			int num2 = b[i] - '0';

			if (num1 < num2) {// if second number is greater than the first number 
				int sub = num1 + 10 - num2 - carry;// ten will be added and 1  will be subtracted from the next operation
				carry = 1;
				result.push_back(sub + '0');//push the result into result string
			}
			if (num1 > num2) {
				int sub = num1 - num2 - carry;//if first number is greater tahn the second subtract like normal
				carry = 0;
				result.push_back(sub + '0');
			}
			
		}

		for (int i = length2; i < length1; i++) {// any remaining numbers in string a will be added to the result string
			int num1 = a[i] - '0';
			int sub = num1 - carry;
			carry = 0;
			result.push_back(sub + '0');//push result into result string
		}

		reverse(result.begin(), result.end());// since the string was feed numbers in reverse order the string must be reversed

		return result;//return result string

	}

	////////////////////////////////////////
	//////////Multiplication function///////
	////////////////////////////////////////

	std::string BigNumFuncClass::MultiFunc(std::string a, std::string b) {
		std::string result = "";
		int carry = 0;
		int length1 = a.length();
		int length2 = b.length();
		
	}


	////////////////////////////////////////
	//////////Divide function///////////////
	////////////////////////////////////////
	std::string BigNumFuncClass::DivFunc(std::string a, std::string b) {

		std::string result = "";
		std::string newb = b; // use string b in newb for later
		int check = 0;

		int carry = 0;

		int length1 = a.length();//length of string a
		int length2 = b.length();//length of string b
		

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		//since division is subtracting several times we add a while loop to the subtraction
		while (a.length() > newb.length())
		{
			result = "";//sets result to empty string
			for (int i = 0; i < length1; i++) {
				int num1 = a[i] - '0';
				int num2 = b[i] - '0';

				if (num1 < num2) {//if the first number is smaller then the second 
					int sub = num1 + 10 - num2 - carry;//add 10 
					carry = 1;//set carry to one to subract from next operation
					result.push_back(sub + '0');
				}
				if (num1 > num2) {//if first number is greater tahn second number
					int sub = num1 - num2 - carry;//subtract like normal 
					carry = 0;
					result.push_back(sub + '0');//push result into result string
				}

			}

			for (int i = length2; i < length1; i++) {// if any numbers are left over they are pushed into the string
				int num1 = a[i] - '0';
				int sub = num1 - carry;
				carry = 0;
				result.push_back(sub + '0');
			}
			check++;//keeps track of how many subractiions have been made
			reverse(result.begin(), result.end());
			newb = result;//saces string into newb
		}
		std::string result1 = std::to_string(check);// converts check number to a string
		return result1;//return result1
	}


	////////////////////////////////////////
	//////////mod function///////////////
	////////////////////////////////////////
	std::string BigNumFuncClass::ModFunc(std::string a, std::string b) {
		std::string result = "";
		std::string newb = b;
		int carry = 0;


		int length1 = a.length();//length of string a
		int length2 = b.length();//length of string b


		reverse(a.begin(), a.end());// reverse the string in order to do subtraction properlly
		reverse(b.begin(), b.end());

		while (a.length() > newb.length())
		{
			result = "";// empty the string
			for (int i = 0; i < length1; i++) {
				int num1 = a[i] - '0';
				int num2 = b[i] - '0';

				if (num1 < num2) {//if first number is smaller than the second number
					int sub = num1 + 10 - num2 - carry;// add 10 
					carry = 1;//set carry to 1
					result.push_back(sub + '0');
				}
				if (num1 > num2) {//if first number is laerger than the second					
					int sub = num1 - num2 - carry;
					carry = 0;
					result.push_back(sub + '0');
				}

			}

			for (int i = length2; i < length1; i++) {
				int num1 = a[i] - '0';
				int sub = num1 - carry;
				carry = 0;
				result.push_back(sub + '0');
			}
			reverse(result.begin(), result.end());// revers the string
			newb = result;//newb equals the number left after it has been subtracted
		}
		return newb;//return newb

	}

}

