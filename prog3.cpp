#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <limits>

using namespace std;

int main(int argc, char *argv[])
{
    int pprocess = 0; // 0 for normal, 1 for omit value and space, 2 for replace space with comma.
    bool percents = false;
    bool outsort = false;
	int counter = 0;
	int innercounter = 0;
	int perline = 0;
	if (argc > 1)
	{
		counter = 0;
		string comptemp = string(argv[counter]);
		size_t found = comptemp.find("-L");
		while (counter < argc)
		{
			comptemp = string(argv[counter]);
			found = comptemp.find("-L");
			if ((comptemp)== "-n")
			{
				pprocess = 1;
			}
			if ((comptemp) == "-c")
			{
				pprocess = 2;
			}
			if ((comptemp) == "-p")
			{
				percents = true;
				cout << "ayyy" << endl;
			}
			if ((comptemp) == "-s")
			{
				outsort = true;
			}
			if (found != string::npos)
			{
				string bstemp = comptemp.substr(2, comptemp.size() - 1);
				cout << "line size is now " << bstemp << endl;
				perline = atoi(bstemp.c_str());
			}	
			counter++;
		}
	}
		
		vector<char> useri;
		vector<string> sorted;
		vector<int> sortedcount;
		//int ui = getchar();
		counter = 0;
		//while (ui != EOF) // reads inputstream and fills input string with chosen input
		//{
		//	useri.push_back(ui);
		//	ui = getchar();
		//}
		useri.push_back('T');
		useri.push_back('h');
		useri.push_back('e');
		useri.push_back('e');
		useri.push_back('d');
		useri.push_back('g');
		useri.push_back('g');
		useri.push_back('g');
		
		counter = 0;
		cout << "size is " << useri.size() << endl;
		while (counter < useri.size())
		{
			char check = useri.at(counter);
			char checkout1;
			char checkout2;
			int numval = +check;  
			int remain = numval % 16; 
			numval = numval - remain;  
			numval = numval / 16;
			
			if (numval > 9)
			{
				switch (numval) 
				{
					case 10: checkout1 = 'a'; break;
					case 11: checkout1 = 'b'; break;
					case 12: checkout1 = 'c'; break;
					case 13: checkout1 = 'd'; break;
					case 14: checkout1 = 'e'; break;
					case 15: checkout1 = 'f'; break;
				}
			}
			else
			{
				char conv = numval + '0';
				checkout1 = conv;
			}
			if (remain > 9)
			{
				switch (remain) 
				{
					case 10: checkout2 = 'a'; break;
					case 11: checkout2 = 'b'; break;
					case 12: checkout2 = 'c'; break;
					case 13: checkout2 = 'd'; break;
					case 14: checkout2 = 'e'; break;
					case 15: checkout2 = 'f'; break;
				}
			}
			else
			{
				char conv = remain + '0';
				checkout2 = conv;
			}
			string checkout;
			checkout.push_back(checkout1);
			checkout.push_back(checkout2);
			innercounter = 0;
			if (counter == 0)
			{
				sorted.push_back(checkout);
				sortedcount.push_back(1);
			}
			else
			{
				bool insorted = false;
				while (innercounter < sorted.size())
				{
					if (sorted.at(innercounter) == checkout)
					{
						sortedcount.at(innercounter)++;
						insorted = true;
						break;
					}
					innercounter++;
				}
				if (!insorted)
				{
					sorted.push_back(checkout);
					sortedcount.push_back(1);
				}
			}
			
			counter++;
		}
		
		counter = 0;
		while (counter < sorted.size())
		{
			cout << sorted.at(counter) << ": " << sortedcount.at(counter) << " times." << endl;
			counter++;
		}

	
}
