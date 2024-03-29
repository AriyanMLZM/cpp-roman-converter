// Arian Molazem
//-----------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

//----------------------------------------------------------------------- 
// Determining the Roman bases; their symbols and values

string symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

int values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

//-----------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------
void menu();                                       // Just for appearance
void line();
//-----------------------------------------------------------------------
void positional_system_base_10__to__roman_system();         // Converting
void roman_system__to__positional_system_base_10(); 
//-----------------------------------------------------------------------

int main()
{
//-----------------------------------------------------------------------	
	bool exit_prog = false;                                       // menu
	bool flag;
	int num_menu;
	
	while(not(exit_prog))
	{
		system("cls");
		menu();
		line();
		flag = true;
		cout << "\n Convert base 10 number to Roman number (1) \n\n"
				" Convert Roman number to base 10 number (2) \n\n"
				" Exit program                           (0) \n";
		
		line();
		while(flag)
		{
			flag = false;
			
			while(true)
			{
				cout << "\n num: "; cin >> num_menu;
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << " [Enter a number] \n";
				} else
					break;
			}
			
			cin.get();
			switch(num_menu)
			{
				case 1: system("cls"); 
				positional_system_base_10__to__roman_system(); break; // Calling func
				
				case 2: system("cls"); 
				roman_system__to__positional_system_base_10(); break; // Calling func
				
				case 0: exit_prog = true; break;
				
				default: flag = true;
				cout << " [Just enter one of the menu numbers] \n";
			}
		}
	}
	system("cls");
	cout << "\n Have a nice day! ";
	getch();
//-----------------------------------------------------------------------
	return 0;
}

void positional_system_base_10__to__roman_system()
{
	int number;
	int index_symbol = 12;
	
	while(true)
	{
//-----------------------------------------------------------------------		
		cout << "\n Enter number (1-3999) : ";      // Getting the input.
		cin >> number;
//-----------------------------------------------------------------------
		if(cin.fail())                   // Avoiding wrong type of input.
		{
			cin.clear();
			cin.ignore();
			cout << " [Enter an int number] \n";
			continue;
		}
//-----------------------------------------------------------------------
		if(number >= 0 && number < 4000)  // Avoiding out of range input.
			break;
		cout << " [Number is out of range] \n";
//-----------------------------------------------------------------------
	}
	
	cout << "\n Roman number: ";
	while(number > 0)
	{
		int num_symbol = number / values[index_symbol]; // Counting the number of symbol that we should use.
		number %= values[index_symbol]; // Keeping the remain for next round. 
		
		while(num_symbol--)
		{
			cout << symbols[index_symbol]; // Printing the symbols.
		}
		
		index_symbol--;
	}
	
	line();
	cout << " Press any key to go back to menu. ";
	getch();
}

void roman_system__to__positional_system_base_10()
{
//-----------------------------------------------------------------------	
	char num[999];                       // Getting the symbols as chars.
	cout << "\n (I, IV, V, IX, X, XL, L, XC, C, CD, D, CM, M)\n [Lower case is also accepted] \n\n Enter the symbols : ";
	cin.get(num, 999);
//-----------------------------------------------------------------------	
	string number = num;            // Changing lower case to upper case.
	for(int i = 0; i < number.length(); i++)
	{
		num[i] = toupper(num[i]);
	}
	number = num;
//-----------------------------------------------------------------------	
	int sum = 0;                              // Recognizing each symbol.
	bool invalid_input = false;
	
	for(int index = 0; index < number.length(); index++)
	{	
		switch(number[index])
		{
//-----------------------------------------------------------------------			
			case 'I':                        // Recognizing I, IV and IX.
			{
				if(index < number.length())
				{
					if(number[index + 1] == 'V')
					{
						sum += 4;
						index++; 
					}
					else if(number[index + 1] == 'X')
					{
						sum += 9;
						index++;
					}
					else
					{
						sum += 1;
					}
				}
				else
				{
					sum += 1;
				}
			}; break;
//-----------------------------------------------------------------------			
			case 'X':                        // Recognizing X, XL and XC.
			{
				if(index < number.length())
				{
					if(number[index + 1] == 'L')
					{
						sum += 40;
						index++; 
					}
					else if(number[index + 1] == 'C')
					{
						sum += 90;
						index++;
					}
					else
					{
						sum += 10;
					}
				}
				else
				{
					sum += 10;
				}
			}; break;
//-----------------------------------------------------------------------			
			case 'C':                        // Recognizing C, CD and CM.
			{
				if(index < number.length())
				{
					if(number[index + 1] == 'D')
					{
						sum += 400;
						index++; 
					}
					else if(number[index + 1] == 'M')
					{
						sum += 900;
						index++;
					}
					else
					{
						sum += 100;
					}
				}
				else
				{
					sum += 10;
				}
			}; break;
//-----------------------------------------------------------------------
			case 'V':                       // Recognizing V, L, D and M.
			{
				sum += 5;
			}; break;
			
			case 'L':
			{
				sum += 50;
			}; break;
			
			case 'D':
			{
				sum += 500;
			}; break;
			
			case 'M':
			{
				sum += 1000;
			}; break;
//-----------------------------------------------------------------------
			default:                   // Checking the validity of input.
			{
				invalid_input = true;  
			}
		}
		
		if(invalid_input)
		{
			
			break;
		}
	}
	
	if(invalid_input) 
	{
		cout << "\n [invalid input] \n";
		line();
		cout << " Press any key to go back to menu. ";
		getch();
		return;
	}
	
	if(sum > 3999)  // Checking the range.
	{
		cout << "\n [The number is out of range or invalid]";
		line();
		cout << " Press any key to go back to menu. ";
		getch();
	}
	else
	{
		cout << "\n Number: " << sum;  // Printing the number.
		line();
		cout << " Press any key to go back to menu. ";
		getch();
	}
}

void line(){
	cout << "\n ------------------------------------------\n";
}
void menu(){
	cout << "         _ __ ___   ___ _ __  _   _  \n"
			"        | '_ ` _ \\ / _ \\ '_ \\| | | | \n"
			"        | | | | | |  __/ | | | |_| | \n"
			"        |_| |_| |_|\\___|_| |_|\\__,_| ";
}


