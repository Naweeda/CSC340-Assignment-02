#include <iostream> 
#include <vector> 
#include <fstream>
#include <string>
#include <sstream> 
#include <array>
#include <algorithm>
using namespace std;

// Here the structure is defined to hold the line and 
//create the dictionary

//vector is used as data type
struct DicData
{
	string DicKeyword;
	vector<string> DicDefinition;
	vector<string> DicSpeech;

};


// Below method is created to convert the given 
// string in upper case in order to make things in same case
string convertToUpperCase(string userInput) {

	for (int i = 0; i <= userInput.size(); i++)
	{
		if (userInput[i] >= 97 && userInput[i] <= 122)
		{
			userInput[i] = userInput[i] - 32;
		}
	}

	return userInput;
}


// Below method is created to trim the space
string trim(const string& userInput)
{
	size_t first = userInput.find_first_not_of(' ');
	if (string::npos == first)
	{
		return userInput;
	}
	size_t last = userInput.find_last_not_of(' ');
	return userInput.substr(first, (last - first + 1));
}

// The purpose of this method is to convert in camel case 
// for displaying DicKeyword

string convertToCamelCase(string inpt_str) {
	if (inpt_str[0] >= 97 && inpt_str[0] <= 122)
	{
		inpt_str[0] = inpt_str[0] - 32;
	}

	return inpt_str;
}


//the purpose of this method is to remove delimiters
string replace(string userInput, string targtDelim, string replaceDelim) {
	int len, iterate = 0;
	string str_n = "", let;
	len = userInput.length();
	len--;
	while (iterate <= len) {
		let = userInput.substr(iterate, 1);
		if (let == targtDelim) {
			str_n = str_n + replaceDelim;
		}
		else {
			str_n = str_n + let;
		}
		iterate++;
	}
	return str_n;

}

//The purpose of this method is to split the string 
vector<string> split(string str, char DataDelim) {
	vector<string> split_out;
	stringstream ss(str); // Turn the string into a stream.
	string getString;

	while (getline(ss, getString, DataDelim)) {
		split_out.push_back(getString);
	}

	return split_out;
};


//From here main method starts
int main()
{

	// Variable initialization of structure
	struct DicData d1;

	//storing all structure variables in Vector
	vector<DicData> vect_dict;


	//reading file in line variable
	std::string line;

	//

	ifstream DicFile("Data.CS.SFSU.txt");


	// reading file and using loop to add data in attributes of class  
	cout << "\n! Opening data file... ./Data.CS.SFSU.txt\n";
	if (DicFile.is_open())
	{
		cout << "\n! Loading data...\n";
		while (getline(DicFile, line))
		{
			d1.DicKeyword = split(line, '|')[0];


			line = replace(line, "-", "");
			line = replace(line, ">", "");

			for (int i = 1; i < split(line, '|').size(); i++)
			{
				d1.DicSpeech.push_back(split(split(line, '|')[i], '=')[0]);
				d1.DicDefinition.push_back(split(split(line, '|')[i], '=')[1]);
			}
			vect_dict.push_back(d1);
			d1 = {};
		}


		cout << "\n! Loading completed...\n";
	}


	cout << "\n! Closing data file... ./Data.CS.SFSU.txt\n" << endl;
	cout << "----- DICTIONARY 340 C++ ----- \n";


	int value;
	int check;
	int ValidationCheck, counter;
	string DicKeyword;

	string val_distinct[15];
	string val_distinct_temp[15];

	vector<DicData>::iterator distinct_vp;

	string search, word_key, distinct, DicSpeech;

	//loop starts here
	while (search != "!Q") {

		cout << "\n\nSearch: ";
		getline(cin, search);
		value = 0;

		if (search == "!Q")
		{
			cout << "\n-----THANK YOU-----\n ";
			exit(0);
		}



		for (int i = 0; i < vect_dict.size(); i++)
		{
			if (split(search, ' ').size() == 1) {

				check = 0;
				if (convertToUpperCase(vect_dict[i].DicKeyword) == convertToUpperCase(search)) {
					// cout<<"        |\n\n";
					for (int j = 0; j < vect_dict[i].DicSpeech.size(); j++) {
						// cout<<"         ";
						if (convertToUpperCase(search) == "ARROW") {

							val_distinct[check] = trim(vect_dict[i].DicSpeech[j]) + "] : " + vect_dict[i].DicDefinition[j] + "  -=>>.";
							DicKeyword = convertToCamelCase(vect_dict[i].DicKeyword);
							check++;
						}
						else {
							val_distinct[check] = trim(vect_dict[i].DicSpeech[j]) + "] : " + vect_dict[i].DicDefinition[j];
							DicKeyword = convertToCamelCase(vect_dict[i].DicKeyword);
							check++;
						}
						// cout<<"\n        |\n\n";
						value = 1;
					}

				}
			}
			if (split(search, ' ').size() == 2 && ((convertToUpperCase(split(search, ' ')[1])).compare("DISTINCT")) == 0) {

				word_key = split(search, ' ')[0];


				if (convertToUpperCase(vect_dict[i].DicKeyword) == convertToUpperCase(word_key)) {

					check = 0;
					for (int j = 0; j < vect_dict[i].DicSpeech.size(); j++)
					{
						ValidationCheck = 0;

						for (int k = 0; k < sizeof(val_distinct) / sizeof(val_distinct[0]); k++)
						{
							if (val_distinct[k] == trim(vect_dict[i].DicSpeech[j]) + "] : " + vect_dict[i].DicDefinition[j])
							{
								ValidationCheck = 1;
							}

						}

						if (ValidationCheck == 0) {
							val_distinct[check] = trim(vect_dict[i].DicSpeech[j]) + "] : " + vect_dict[i].DicDefinition[j];
							DicKeyword = convertToCamelCase(vect_dict[i].DicKeyword);
							check++;
							value = 1;
						}


					}



					// for (int j = 0; j< check; j++){ 

					// if (j==0) cout<<"        |\n\n";
					// cout<<"         ";
					// cout << convertToCamelCase(vect_dict[i].DicKeyword) << " ["<< trim(split(val_distinct[j],'_')[0])<<"] : " << split(val_distinct[j],'_')[1]<<"\n";
					// if (j==check-1) cout<<"\n        |\n\n";
					// }

					// value=1;
				}

			}

			if (split(search, ' ').size() == 2 && ((convertToUpperCase(split(search, ' ')[1])).compare("DISTINCT")) != 0) {

				word_key = split(search, ' ')[0];
				DicSpeech = split(search, ' ')[1];
				check = 0;
				if (convertToUpperCase(vect_dict[i].DicKeyword) == convertToUpperCase(word_key)) {
					for (int j = 0; j < vect_dict[i].DicSpeech.size(); j++) {

						if (convertToUpperCase(trim(vect_dict[i].DicSpeech[j])) == convertToUpperCase(DicSpeech)) {
							val_distinct[check] = trim(vect_dict[i].DicSpeech[j]) + "] : " + vect_dict[i].DicDefinition[j];
							DicKeyword = convertToCamelCase(vect_dict[i].DicKeyword);
							value = 1;
							check++;
							
						}

					}

					// if (value==1) cout<<"\n        |\n\n";
				}


			}

			if (split(search, ' ').size() == 3) {

				word_key = split(search, ' ')[0];
				DicSpeech = split(search, ' ')[1];

				if (convertToUpperCase(vect_dict[i].DicKeyword) == convertToUpperCase(word_key)) {
					check = 0;
					for (int j = 0; j < vect_dict[i].DicSpeech.size(); j++)
					{
						ValidationCheck = 0;

						for (int k = 0; k < sizeof(val_distinct_temp) / sizeof(val_distinct_temp[0]); k++)
						{
							if (val_distinct_temp[k] == trim(vect_dict[i].DicSpeech[j]) + "] : " + trim(vect_dict[i].DicDefinition[j]))
							{
								ValidationCheck = 1;
							}

						}

						if (value == 0) {
							val_distinct_temp[check] = trim(vect_dict[i].DicSpeech[j]) + "] : " + trim(vect_dict[i].DicDefinition[j]);
							check++;
							// value=1;
							DicKeyword = convertToCamelCase(vect_dict[i].DicKeyword);
						}


					}

					for (int j = 0; j < check; j++) {

						counter = 0;
						if (convertToUpperCase(trim(split(val_distinct_temp[j], ']')[0])) == convertToUpperCase(DicSpeech)) {
							// if (counter==0) cout<<"        |\n\n";
							// cout<<"         ";

							// cout << convertToCamelCase(vect_dict[i].DicKeyword) << " ["<<trim(split(val_distinct[j],'_')[0])<<"] : " << split(val_distinct[j],'_')[1]<<"\n";
							val_distinct[counter] = val_distinct_temp[j];


							value = 1;
							counter++;
						}

					}
					// if(value==1) cout<<"\n        |\n\n";


				}


			}


		}

		DicSpeech = convertToUpperCase(DicSpeech);
		if (value == 0 && DicSpeech != "ADJECTIVE" && DicSpeech != "VERB" && DicSpeech != "ADVERB" && DicSpeech != "NOUN" && split(search, ' ').size() == 3) {
			cout << "        |\n";
			cout << "         ";
			cout << "<2nd argument must be a part of DicSpeech or \"distinct\">";
			cout << "\n        |\n\n";

		}
		if (value == 0 && (DicSpeech == "ADJECTIVE" || DicSpeech == "VERB" || DicSpeech == "ADVERB" || DicSpeech == "NOUN" || split(search, ' ').size() < 3)) {
			cout << "        |\n";
			cout << "         ";
			cout << "<Not found>";
			cout << "\n        |\n\n";

		}
		if (value == 1)
		{
			cout << "        |\n\n";

			sort(begin(val_distinct), end(val_distinct));
			for (int k = 0; k < 15; k++) {
				if (val_distinct[k] != "")
				{
					cout << "         ";
					cout << DicKeyword << " [" << val_distinct[k] << " " << endl;

				}
			}
			cout << "\n        |\n\n";
		}

		for (int k = 0; k < 15; k++) {
			val_distinct[k] = "";
		}
	}

	return 0;


}