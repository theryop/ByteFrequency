#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    int pprocess = 0; // 0 for normal, 1 for omit value and space, 2 for replace space with comma.
    bool percents = false;
    bool outsort = false;
	int counter = 0;
	int innercounter = 0;
	int perline = 0;
	double total;
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
		vector<double> sortedfcount;
		int ui = getchar();
		counter = 0;
		while (ui != EOF) // reads inputstream and fills input string with chosen input
		{
			useri.push_back(ui);
			ui = getchar();
		}

		cout << endl;
		counter = 0;
		while ((unsigned)counter < useri.size())
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
				total++;
			}
			else
			{
				bool insorted = false;
				while ((unsigned)innercounter < sorted.size())
				{
					if (sorted.at(innercounter) == checkout)
					{
						sortedcount.at(innercounter)++;
						total++;
						insorted = true;
						break;
					}
					innercounter++;
				}
				if (!insorted)
				{
					sorted.push_back(checkout);
					total++;
					sortedcount.push_back(1);
				}
			}
			counter++;
		}
		
		counter = 0;
		while ((unsigned)counter < sorted.size())
		{
			double pf = sortedcount.at(counter) / total ;
			sortedfcount.push_back(pf);
			counter++;
		}
		if (outsort)
		{
			bool swapped = true;
			int j = 0;
			int tmp;
			string stmp;
			double dtmp;
			while (swapped) 
			{
            swapped = false;
            j++;
            for (int i = 0; (unsigned)i < sorted.size() - j; i++) 
            {
                  if (sortedcount.at(i) < sortedcount.at(i+1)) 
                  {
                        tmp = sortedcount.at(i);
						stmp = sorted.at(i);
						dtmp = sortedfcount.at(i);
						sortedcount.at(i) = sortedcount.at(i+1);
						sorted.at(i) = sorted.at(i+1);
						sortedfcount.at(i) = sortedfcount.at(i+1);
                        sortedcount.at(i+1) = tmp;
						sorted.at(i+1) = stmp;
						sortedfcount.at(i+1) = dtmp;
                        swapped = true;

                  }

            }

		}
	}
		
		counter = 0;
		while ((unsigned)counter < sorted.size())
		{
			if (!percents)
			{
				if (pprocess != 1 && pprocess == 2)
				{
					cout << sorted.at(counter) << ",";
				}
				else if (pprocess != 1)
				{
					cout << sorted.at(counter) << " ";
				}
				cout  << sortedcount.at(counter)<< "; "; 
				if (perline > 0 && (counter + 1) % perline == 0)
				{
					cout << endl;
				}
			}
			else
			{
				if (pprocess != 1 && pprocess == 2)
				{
					cout << sorted.at(counter) << ",";
				}
				else if (pprocess != 1)
				{
					cout << sorted.at(counter) << " ";
				}
				cout << setprecision(2) << sortedfcount.at(counter) * 100 << "; ";
				if (perline > 0 && (counter + 1) % perline == 0)
				{
					cout << endl;
				}
			}
			counter++;
		}
		cout << endl;
}
