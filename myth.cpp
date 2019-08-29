#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

void ascii () {

	std::random_device rd; 
    std::mt19937 eng(rd()); 
    std::uniform_int_distribution<> distr(1, 3); 
    int choice;
    choice = distr(eng);
    
    if (choice == 1) {

    	std::cout << "              ,~,\n";
		std::cout << "             (((""}\n";
		std::cout << "             -''-.  \"hello poor human,\n";
		std::cout << "            (\\  /\\)   let me help you with that\n"; 
		std::cout << "      ~______\\) | `\\   shellcode...\"\n";
		std::cout << "   ~~~(         |  ')\n"; 
		std::cout << "      | )____(  |\n";
		std::cout << "     /|/     ` /|\n";
		std::cout << "     \\ \\      / |\n";
		std::cout << "     |\\|\\   /| |\\\n";
		std::cout << "\n";
    }

    else if (choice == 2) {

    	std::cout << "		              ______________                \n";
      	std::cout << "		        ,===:'.,            `-._            \n";
        std::cout << " \"you woke me               `:.`---.__         `-._        \n";
        std::cout << "  from my slumber for         `:.     `--.         `.      \n";
        std::cout << "  this? verywell...\"            \\.        `.         `.   \n";
       	std::cout << "		         (,,(,    \\.         `.   ____,-`.,\n";
    	std::cout << "		      (,'     `/   \\.   ,--.___`.'         \n";
		std::cout << "		  ,  ,'  ,--.  `,   \\.:'         `         \n";
   		std::cout << "		   `""{D, ""{    \\  :    \\:               \n";
   		std::cout << "		     V,,'    /  /    //                     \n";
   		std::cout << "		     j::    /  ,' ,-//.    ,---.      ,     \n";
        std::cout << "		     \\:'   /  ,' /  _  \\  /  _  \\   ,'/  \n";
    	std::cout << "		           \\   `'  / \\  `'  / \\  `.' /   \n";
    	std::cout << "		            `.___,'   `.__,'   `.__,'       \n";
    	std::cout << "\n";
    }

    else {

    	std::cout << "          ,;~;,\n";
    	std::cout << "             /\\_        \"come with me,\n";
    	std::cout << "            (  /         i'll protect you from\n";
    	std::cout << "            (()     //)   the restricted chars...\"\n";
    	std::cout << "            | \\  ,,;;'\\\n";
    	std::cout << "        __ _(  )m=((((((((((((===============--------\n";
    	std::cout << "      /'  ' '()/~' '.(, |\n";
    	std::cout << "   ,;(      )||     |  ~\n";
    	std::cout << "  ,;' \\    /-(.;,   )\n";
    	std::cout << "       ) /       ) /\n";
    	std::cout << "      //         ||\n";
    	std::cout << "     )_\\         )_\\\n";
    	std::cout << "\n";


    }

}

int main () {

	ascii ();

	std::string str;
	std::cout << "Enter your shellcode: ";
	std::cin >> str;
	std::string varName;
	std::cout << "Enter variable name: ";
	std::cin >> varName;
	int length;
	length = (str.length()/2);

	if (length % 4 == 0) {

		//std::cout << "Shellcode is divisble by 4.\n";
		

	}

	else {

		//std::cout << "Shellcode is not divisible by 4, adding NOPs.\n";
		while (length % 4 != 0) {

			str = str.append("90");
			length = (str.length()/2);

		}

	}
	
	//std::cout << "Final shellcode is: " << str << "\n";
	std::cout << "\n";
	
	int trueLen, chunkNum, iterator, multiplier;
	trueLen = str.length();
	chunkNum = (trueLen/2)/4;
	iterator = 0;
	multiplier = 0;
	trueLen = trueLen - 1;

	int shellcodeLength = 0;

	//This code will dynamically figure out how many 4 byte sections of code we need to encode, and iterate through the user input string and create a new string that is the reverse order.
	while (iterator < chunkNum) {

		std::string payload;
		std::string append1;
		append1 = (str[trueLen - (multiplier + 1)]);
		payload.append(append1);
		std::string append2;
		append2 = (str[trueLen - (multiplier + 0)]);
		payload.append(append2);
		std::string append3;
		append3 = (str[trueLen - (multiplier + 3)]);
		payload.append(append3);
		std::string append4;
		append4 = (str[trueLen - (multiplier + 2)]);
		payload.append(append4);
		std::string append5;
		append5 = (str[trueLen - (multiplier + 5)]);
		payload.append(append5);
		std::string append6;
		append6 = (str[trueLen - (multiplier + 4)]);
		payload.append(append6);
		std::string append7;
		append7 = (str[trueLen - (multiplier + 7)]);
		payload.append(append7);
		std::string append8;
		append8 = (str[trueLen - (multiplier + 6)]);
		payload.append(append8);

		++iterator;

		multiplier = multiplier + 8;
		
		//std::cout << "Encoding: [" << payload << "]...\n";
	
		//assembling the bytes of the reversed shellcode to check for '\xff' and do arithmetic later...
		std::string firstByte;
		std::string firstByte1;
		std::string firstByte2;
		firstByte1 = payload[0];
		firstByte2 = payload[1];
		firstByte.append(firstByte1);
		firstByte.append(firstByte2);

		//std::cout << "The first byte of the shellcode is: " << firstByte << "\n";

		std::string secondByte;
		std::string secondByte1;
		std::string secondByte2;
		secondByte1 = payload[2];
		secondByte2 = payload[3];
		secondByte.append(secondByte1);
		secondByte.append(secondByte2);

		//std::cout << "The second byte of the shellcode is: " << secondByte << "\n";

		std::string thirdByte;
		std::string thirdByte1;
		std::string thirdByte2;
		thirdByte1 = payload[4];
		thirdByte2 = payload[5];
		thirdByte.append(thirdByte1);
		thirdByte.append(thirdByte2);

		//std::cout << "The third byte of the shellcode is: " << thirdByte << "\n";

		std::string fourthByte;
		std::string fourthByte1;
		std::string fourthByte2;
		fourthByte1 = payload[6];
		fourthByte2 = payload[7];
		fourthByte.append(fourthByte1);
		fourthByte.append(fourthByte2);

		//std::cout << "The fourth byte of the shellcode is: " << fourthByte << "\n";

		if (firstByte == "ff" or secondByte == "ff" or thirdByte == "ff" or fourthByte == "ff" or firstByte == "FF" or secondByte == "FF" or thirdByte == "FF" or fourthByte == "FF") {

			if (firstByte == "01" or secondByte == "01" or thirdByte == "01" or fourthByte == "01" or firstByte == "02" or secondByte == "02" or thirdByte == "02" or fourthByte == "02") {

				
				//starting arithmetic on the first byte
				int firstHex = std::stoi (firstByte,nullptr,16);
				int firstOperator1, firstOperator2, firstOperator3;
				firstHex = firstHex + 9;
				firstOperator1 = firstHex/3;
				firstOperator2 = firstHex/3;
				firstOperator3 = (firstHex - firstOperator1 - firstOperator2);

				//converting the decimal ints back into hex strings
				std::stringstream convertOne1;
				convertOne1 << std::hex << firstOperator1;
				std::string convertedOne1 = convertOne1.str();
				if (convertedOne1.length() == 1) {

					convertedOne1.insert(0, "0");

				}
				std::stringstream convertOne2;
				convertOne2 << std::hex << firstOperator2;
				std::string convertedOne2 = convertOne2.str();
				if (convertedOne2.length() == 1) {

					convertedOne2.insert(0, "0");

				}
				std::stringstream convertOne3;
				convertOne3 << std::hex << firstOperator3;
				std::string convertedOne3 = convertOne3.str();
				if (convertedOne3.length() == 1) {

					convertedOne3.insert(0, "0");

				}
				
				//starting arithmetic on the second byte
				int secondHex = std::stoi (secondByte,nullptr,16);
				int secondOperator1, secondOperator2, secondOperator3;
				secondHex = secondHex + 9;
				secondOperator1 = secondHex/3;
				secondOperator2 = secondHex/3;
				secondOperator3 = (secondHex - secondOperator1 - secondOperator2);

				//converting the decimal ints back into hex strings
				std::stringstream convertTwo1;
				convertTwo1 << std::hex << secondOperator1;
				std::string convertedTwo1 = convertTwo1.str();
				if (convertedTwo1.length() == 1) {

					convertedTwo1.insert(0, "0");

				}
				std::stringstream convertTwo2;
				convertTwo2 << std::hex << secondOperator2;
				std::string convertedTwo2 = convertTwo2.str();
				if (convertedTwo2.length() == 1) {

					convertedTwo2.insert(0, "0");

				}
				std::stringstream convertTwo3;
				convertTwo3 << std::hex << secondOperator3;
				std::string convertedTwo3 = convertTwo3.str();
				if (convertedTwo3.length() == 1) {

					convertedTwo3.insert(0, "0");

				}

				//starting arithmetic on the third byte
				int thirdHex = std::stoi (thirdByte,nullptr,16);
				int thirdOperator1, thirdOperator2, thirdOperator3;
				thirdHex = thirdHex + 9;
				thirdOperator1 = thirdHex/3;
				thirdOperator2 = thirdHex/3;
				thirdOperator3 = (thirdHex - thirdOperator1 - thirdOperator2);

				//converting the decimal ints back into hex strings
				std::stringstream convertThree1;
				convertThree1 << std::hex << thirdOperator1;
				std::string convertedThree1 = convertThree1.str();
				if (convertedThree1.length() == 1) {

					convertedThree1.insert(0, "0");

				}
				std::stringstream convertThree2;
				convertThree2 << std::hex << thirdOperator2;
				std::string convertedThree2 = convertThree2.str();
				if (convertedThree2.length() == 1) {

					convertedThree2.insert(0, "0");

				}
				std::stringstream convertThree3;
				convertThree3 << std::hex << thirdOperator3;
				std::string convertedThree3 = convertThree3.str();
				if (convertedThree3.length() == 1) {

					convertedThree3.insert(0, "0");

				}

				//starting arithmetic on the fourth byte
				int fourthHex = std::stoi (fourthByte,nullptr,16);
				int fourthOperator1, fourthOperator2, fourthOperator3;
				fourthHex = fourthHex + 9;
				fourthOperator1 = fourthHex/3;
				fourthOperator2 = fourthHex/3;
				fourthOperator3 = (fourthHex - fourthOperator1 - fourthOperator2);

				//converting the decimal ints back into hex strings
				std::stringstream convertFour1;
				convertFour1 << std::hex << fourthOperator1;
				std::string convertedFour1 = convertFour1.str();
				if (convertedFour1.length() == 1) {

					convertedFour1.insert(0, "0");

				}
				std::stringstream convertFour2;
				convertFour2 << std::hex << fourthOperator2;
				std::string convertedFour2 = convertFour2.str();
				if (convertedFour2.length() == 1) {

					convertedFour2.insert(0, "0");

				}
				std::stringstream convertFour3;
				convertFour3 << std::hex << fourthOperator3;
				std::string convertedFour3 = convertFour3.str();
				if (convertedFour3.length() == 1) {

					convertedFour3.insert(0, "0");

				}



				//std::cout << "FF found with an 01 or 02\n";
				std::cout << varName << " += \"\\x25\\x4a\\x4d\\x4e\\x55\"\n";
				std::cout << varName << " += \"\\x25\\x35\\x32\\x31\\x2a\"\n";
				std::cout << varName << " += \"\\x05\\x" << convertedFour1 << "\\x" << convertedThree1 << "\\x" << convertedTwo1 << "\\x" << convertedOne1 << "\"\n";
				std::cout << varName << " += \"\\x05\\x" << convertedFour2 << "\\x" << convertedThree2 << "\\x" << convertedTwo2 << "\\x" << convertedOne2 << "\"\n";
				std::cout << varName << " += \"\\x05\\x" << convertedFour3 << "\\x" << convertedThree3 << "\\x" << convertedTwo3 << "\\x" << convertedOne3 << "\"\n";
				std::cout << varName << " += \"\\x2d\\x09\\x09\\x09\\x09\"\n";
				std::cout << varName << " += \"\\x50\"\n";
				shellcodeLength = shellcodeLength + 31;

			}

			else {

				
				//starting arithmetic on the first byte
				int firstHex = std::stoi (firstByte,nullptr,16);
				int firstOperator1, firstOperator2, firstOperator3;
				firstOperator1 = firstHex/3;
				firstOperator2 = firstHex/3;
				firstOperator3 = (firstHex - firstOperator1 - firstOperator2);

				//converting the decimal ints back into hex strings
				std::stringstream convertOne1;
				convertOne1 << std::hex << firstOperator1;
				std::string convertedOne1 = convertOne1.str();
				if (convertedOne1.length() == 1) {

					convertedOne1.insert(0, "0");

				}
				std::stringstream convertOne2;
				convertOne2 << std::hex << firstOperator2;
				std::string convertedOne2 = convertOne2.str();
				if (convertedOne2.length() == 1) {

					convertedOne2.insert(0, "0");

				}
				std::stringstream convertOne3;
				convertOne3 << std::hex << firstOperator3;
				std::string convertedOne3 = convertOne3.str();
				if (convertedOne3.length() == 1) {

					convertedOne3.insert(0, "0");

				}

				//starting arithmetic on the second byte
				int secondHex = std::stoi (secondByte,nullptr,16);
				int secondOperator1, secondOperator2, secondOperator3;
				secondOperator1 = secondHex/3;
				secondOperator2 = secondHex/3;
				secondOperator3 = (secondHex - secondOperator1 - secondOperator2);

				//converting the decimal ints back into hex strings
				std::stringstream convertTwo1;
				convertTwo1 << std::hex << secondOperator1;
				std::string convertedTwo1 = convertTwo1.str();
				if (convertedTwo1.length() == 1) {

					convertedTwo1.insert(0, "0");

				}
				std::stringstream convertTwo2;
				convertTwo2 << std::hex << secondOperator2;
				std::string convertedTwo2 = convertTwo2.str();
				if (convertedTwo2.length() == 1) {

					convertedTwo2.insert(0, "0");

				}
				std::stringstream convertTwo3;
				convertTwo3 << std::hex << secondOperator3;
				std::string convertedTwo3 = convertTwo3.str();
				if (convertedTwo3.length() == 1) {

					convertedTwo3.insert(0, "0");

				}

				//starting arithmetic on the second byte
				int thirdHex = std::stoi (thirdByte,nullptr,16);
				int thirdOperator1, thirdOperator2, thirdOperator3;
				thirdOperator1 = thirdHex/3;
				thirdOperator2 = thirdHex/3;
				thirdOperator3 = (thirdHex - thirdOperator1 - thirdOperator2);

				//converting the decimal ints back into hex strings
				std::stringstream convertThree1;
				convertThree1 << std::hex << thirdOperator1;
				std::string convertedThree1 = convertThree1.str();
				if (convertedThree1.length() == 1) {

					convertedThree1.insert(0, "0");

				}
				std::stringstream convertThree2;
				convertThree2 << std::hex << thirdOperator2;
				std::string convertedThree2 = convertThree2.str();
				if (convertedThree2.length() == 1) {

					convertedThree2.insert(0, "0");

				}
				std::stringstream convertThree3;
				convertThree3 << std::hex << thirdOperator3;
				std::string convertedThree3 = convertThree3.str();
				if (convertedThree3.length() == 1) {

					convertedThree3.insert(0, "0");

				}

				//starting arithmetic on the second byte
				int fourthHex = std::stoi (fourthByte,nullptr,16);
				int fourthOperator1, fourthOperator2, fourthOperator3;
				fourthOperator1 = thirdHex/3;
				fourthOperator2 = thirdHex/3;
				fourthOperator3 = (fourthHex - fourthOperator1 - fourthOperator2);

				//converting the decimal ints back into hex strings
				std::stringstream convertFour1;
				convertFour1 << std::hex << fourthOperator1;
				std::string convertedFour1 = convertFour1.str();
				if (convertedFour1.length() == 1) {

					convertedFour1.insert(0, "0");

				}
				std::stringstream convertFour2;
				convertFour2 << std::hex << fourthOperator2;
				std::string convertedFour2 = convertFour2.str();
				if (convertedFour2.length() == 1) {

					convertedFour2.insert(0, "0");

				}
				std::stringstream convertFour3;
				convertFour3 << std::hex << fourthOperator3;
				std::string convertedFour3 = convertFour3.str();
				if (convertedFour3.length() == 1) {

					convertedFour3.insert(0, "0");

				}
				
				//std::cout << "FF found by itself.\n";
				std::cout << varName << " += \"\\x25\\x4a\\x4d\\x4e\\x55\"\n";
				std::cout << varName << " += \"\\x25\\x35\\x32\\x31\\x2a\"\n";
				std::cout << varName << " += \"\\x05\\x" << convertedFour1 << "\\x" << convertedThree1 << "\\x" << convertedTwo1 << "\\x" << convertedOne1 << "\"\n";
				std::cout << varName << " += \"\\x05\\x" << convertedFour2 << "\\x" << convertedThree2 << "\\x" << convertedTwo2 << "\\x" << convertedOne2 << "\"\n";
				std::cout << varName << " += \"\\x05\\x" << convertedFour3 << "\\x" << convertedThree3 << "\\x" << convertedTwo3 << "\\x" << convertedOne3 << "\"\n";
				std::cout << varName << " += \"\\x50\"\n";
				shellcodeLength = shellcodeLength + 26;

			}



		}

		else if (firstByte == "01" or secondByte == "01" or thirdByte == "01" or fourthByte == "01") {

			//starting arithmetic on the first byte
			int firstHex = std::stoi (firstByte,nullptr,16);
			int firstOperator1, firstOperator2, firstOperator3;
			firstHex = firstHex + 9;
			firstOperator1 = firstHex/3;
			firstOperator2 = firstHex/3;
			firstOperator3 = (firstHex - firstOperator1 - firstOperator2);

			//converting the decimal ints back into hex strings
			std::stringstream convertOne1;
			convertOne1 << std::hex << firstOperator1;
			std::string convertedOne1 = convertOne1.str();
			if (convertedOne1.length() == 1) {

				convertedOne1.insert(0, "0");

			}
			std::stringstream convertOne2;
			convertOne2 << std::hex << firstOperator2;
			std::string convertedOne2 = convertOne2.str();
			if (convertedOne2.length() == 1) {

				convertedOne2.insert(0, "0");

			}
			std::stringstream convertOne3;
			convertOne3 << std::hex << firstOperator3;
			std::string convertedOne3 = convertOne3.str();
			if (convertedOne3.length() == 1) {

				convertedOne3.insert(0, "0");

			}
			
			//starting arithmetic on the second byte
			int secondHex = std::stoi (secondByte,nullptr,16);
			int secondOperator1, secondOperator2, secondOperator3;
			secondHex = secondHex + 9;
			secondOperator1 = secondHex/3;
			secondOperator2 = secondHex/3;
			secondOperator3 = (secondHex - secondOperator1 - secondOperator2);

			//converting the decimal ints back into hex strings
			std::stringstream convertTwo1;
			convertTwo1 << std::hex << secondOperator1;
			std::string convertedTwo1 = convertTwo1.str();
			if (convertedTwo1.length() == 1) {

				convertedTwo1.insert(0, "0");

			}
			std::stringstream convertTwo2;
			convertTwo2 << std::hex << secondOperator2;
			std::string convertedTwo2 = convertTwo2.str();
			if (convertedTwo2.length() == 1) {

				convertedTwo2.insert(0, "0");

			}
			std::stringstream convertTwo3;
			convertTwo3 << std::hex << secondOperator3;
			std::string convertedTwo3 = convertTwo3.str();
			if (convertedTwo3.length() == 1) {

				convertedTwo3.insert(0, "0");

			}

			//starting arithmetic on the third byte
			int thirdHex = std::stoi (thirdByte,nullptr,16);
			int thirdOperator1, thirdOperator2, thirdOperator3;
			thirdHex = thirdHex + 9;
			thirdOperator1 = thirdHex/3;
			thirdOperator2 = thirdHex/3;
			thirdOperator3 = (thirdHex - thirdOperator1 - thirdOperator2);

			//converting the decimal ints back into hex strings
			std::stringstream convertThree1;
			convertThree1 << std::hex << thirdOperator1;
			std::string convertedThree1 = convertThree1.str();
			if (convertedThree1.length() == 1) {

				convertedThree1.insert(0, "0");

			}
			std::stringstream convertThree2;
			convertThree2 << std::hex << thirdOperator2;
			std::string convertedThree2 = convertThree2.str();
			if (convertedThree2.length() == 1) {

				convertedThree2.insert(0, "0");

			}
			std::stringstream convertThree3;
			convertThree3 << std::hex << thirdOperator3;
			std::string convertedThree3 = convertThree3.str();
			if (convertedThree3.length() == 1) {

				convertedThree3.insert(0, "0");

			}

			//starting arithmetic on the fourth byte
			int fourthHex = std::stoi (fourthByte,nullptr,16);
			int fourthOperator1, fourthOperator2, fourthOperator3;
			fourthHex = fourthHex + 9;
			fourthOperator1 = fourthHex/3;
			fourthOperator2 = fourthHex/3;
			fourthOperator3 = (fourthHex - fourthOperator1 - fourthOperator2);

			//converting the decimal ints back into hex strings
			std::stringstream convertFour1;
			convertFour1 << std::hex << fourthOperator1;
			std::string convertedFour1 = convertFour1.str();
			if (convertedFour1.length() == 1) {

				convertedFour1.insert(0, "0");

			}
			std::stringstream convertFour2;
			convertFour2 << std::hex << fourthOperator2;
			std::string convertedFour2 = convertFour2.str();
			if (convertedFour2.length() == 1) {

				convertedFour2.insert(0, "0");

			}
			std::stringstream convertFour3;
			convertFour3 << std::hex << fourthOperator3;
			std::string convertedFour3 = convertFour3.str();
			if (convertedFour3.length() == 1) {

				convertedFour3.insert(0, "0");

			}

			//std::cout << "01 was found.\n";
			std::cout << varName << " += \"\\x25\\x4a\\x4d\\x4e\\x55\"\n";
			std::cout << varName << " += \"\\x25\\x35\\x32\\x31\\x2a\"\n";
			std::cout << varName << " += \"\\x05\\x" << convertedFour1 << "\\x" << convertedThree1 << "\\x" << convertedTwo1 << "\\x" << convertedOne1 << "\"\n";
			std::cout << varName << " += \"\\x05\\x" << convertedFour2 << "\\x" << convertedThree2 << "\\x" << convertedTwo2 << "\\x" << convertedOne2 << "\"\n";
			std::cout << varName << " += \"\\x05\\x" << convertedFour3 << "\\x" << convertedThree3 << "\\x" << convertedTwo3 << "\\x" << convertedOne3 << "\"\n";
			std::cout << varName << " += \"\\x2d\\x09\\x09\\x09\\x09\"\n";
			std::cout << varName << " += \"\\x50\"\n";
			shellcodeLength = shellcodeLength + 31;
		}
		

		else {

			//std::cout << "ff was not found.\n";

			//starting arithmetic on the first byte
			int firstHex = std::stoi (firstByte,nullptr,16);
			int firstOperator1, firstOperator2;
			firstOperator1 = firstHex/2;
			firstOperator2 = (firstHex - firstOperator1);
			//converting the decimal ints back into hex strings
			std::stringstream convertOne1;
			convertOne1 << std::hex << firstOperator1;
			std::string convertedOne1 = convertOne1.str();
			if (convertedOne1.length() == 1) {

				convertedOne1.insert(0, "0");

			}
			std::stringstream convertOne2;
			convertOne2 << std::hex << firstOperator2;
			std::string convertedOne2 = convertOne2.str();
			if (convertedOne2.length() == 1) {

				convertedOne2.insert(0, "0");

			}


			//starting arithmetic on the second byte
			int secondHex = std::stoi (secondByte,nullptr,16);
			int secondOperator1, secondOperator2;
			secondOperator1 = secondHex/2;
			secondOperator2 = (secondHex - secondOperator1);
			//converting the decimal ints back into hex strings
			std::stringstream convertTwo1;
			convertTwo1 << std::hex << secondOperator1;
			std::string convertedTwo1 = convertTwo1.str();
			if (convertedTwo1.length() == 1) {

				convertedTwo1.insert(0, "0");

			}
			std::stringstream convertTwo2;
			convertTwo2 << std::hex << secondOperator2;
			std::string convertedTwo2 = convertTwo2.str();
			if (convertedTwo2.length() == 1) {

				convertedTwo2.insert(0, "0");

			}


			//starting arithmetic on the third byte
			int thirdHex = std::stoi (thirdByte,nullptr,16);
			int thirdOperator1, thirdOperator2;
			thirdOperator1 = thirdHex/2;
			thirdOperator2 = (thirdHex - thirdOperator1);
			//converting the decimal ints back into hex strings
			std::stringstream convertThree1;
			convertThree1 << std::hex << thirdOperator1;
			std::string convertedThree1 = convertThree1.str();
			if (convertedThree1.length() == 1) {

				convertedThree1.insert(0, "0");

			}
			std::stringstream convertThree2;
			convertThree2 << std::hex << thirdOperator2;
			std::string convertedThree2 = convertThree2.str();
			if (convertedThree2.length() == 1) {

				convertedThree2.insert(0, "0");

			}

			//starting arithmetic on the fourth byte
			int fourthHex = std::stoi (fourthByte,nullptr,16);
			int fourthOperator1, fourthOperator2;
			fourthOperator1 = fourthHex/2;
			fourthOperator2 = (fourthHex - fourthOperator1);
			//converting the decimal ints back into hex strings
			std::stringstream convertFour1;
			convertFour1 << std::hex << fourthOperator1;
			std::string convertedFour1 = convertFour1.str();
			if (convertedFour1.length() == 1) {

				convertedFour1.insert(0, "0");

			}
			std::stringstream convertFour2;
			convertFour2 << std::hex << fourthOperator2;
			std::string convertedFour2 = convertFour2.str();
			if (convertedFour2.length() == 1) {

				convertedFour2.insert(0, "0");

			}

			std::cout << varName << " += \"\\x25\\x4a\\x4d\\x4e\\x55\"\n";
			std::cout << varName << " += \"\\x25\\x35\\x32\\x31\\x2a\"\n";
			std::cout << varName << " += \"\\x05\\x" << convertedFour1 << "\\x" << convertedThree1 << "\\x" << convertedTwo1 << "\\x" << convertedOne1 << "\"\n"; 
			std::cout << varName << " += \"\\x05\\x" << convertedFour2 << "\\x" << convertedThree2 << "\\x" << convertedTwo2 << "\\x" << convertedOne2 << "\"\n";
			std::cout << varName << " += \"\\x50\"\n";
			shellcodeLength = shellcodeLength + 21;
			

	
		}



	}

	
	std::cout << "\n";
	std::cout << "Shellcode length: " << shellcodeLength << " bytes" << std::endl;

}


