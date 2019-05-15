#pragma once
#include<string>;
#include<iostream>;

namespace BigNumFunc {

	class BigNumFuncClass

	{

	public:

		// Returns a + b 

		static std::string AddFunc(std::string a, std::string b);



		// Returns a - b 

		static std::string SubFunc(std::string a, std::string b);



		// Returns a * b 

		static std::string MultiFunc(std::string a, std::string b);



		// Returns a / b 

		static std::string DivFunc(std::string a, std::string b);


		static std::string ModFunc(std::string a, std::string b);

	};

}