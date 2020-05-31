#include iostream
#include string
#include math.h

using namespace std;
convert from 10 to 2-binary(string) number system
string func10in2(long long int t)
{
	string resultBinary;
	if (t  0)
		cout  You entered a number with a negative value. It was automatically converted to absolute.  endl;
	t = abs(t);
	do
	{
		result = to_string(lrint(abs(remainder(lrint(t), 2)))) + result;
		resultBinary = to_string(t % 2) + resultBinary;
		t = 2;
	} while (t  0);
	return resultBinary;
}

setSomeZeros takes string and nSigns, and convert this string to requesting value nSigns
string setSomeZeros(string comb, int nSigns)
{
	if (comb.size()  nSigns)
	{
		comb.erase(0, comb.size() - nSigns);
	}
	if (comb.size()  nSigns)
	{
		while (comb.size() != nSigns)
			comb.insert(0, 0);
	}
	return comb;
}
set max arguments (0-maxArgs)
int setNarguments(int maxArgs)
{
	int setNarguments;
	cout  Enter count of arguments (0-  maxArgs  )  endl;
	cin  setNarguments;
	if (setNarguments  maxArgs)
	{
		setNarguments = maxArgs;
	}
	if (setNarguments  0)
	{
		setNarguments = 0;
	}
	return setNarguments;
}

DNF (DDNF(char='1'), DKNF(char='0')
string createDnf(int nArguments, int tableForNarg, string binaryValues, string tableForNvalues, char targetChar)
{
	char targetChar = '0';
	string resultDnf = , symbolArg = x, symbolNegation = !,
		symbolConjunct = , symbolDisjunct = +;
	for (int i = 0; i  tableForNarg; i++)
	{
		if (binaryValues[i] == targetChar)
		{
			if (targetChar == '0') DKNF
			{
				resultDnf += symbolConjunct + (;
				for (int g = 0; g  nArguments; g++)
				{
					if (tableForNvalues[i][g] == targetChar)
					{
						resultDnf += symbolArg + to_string(g + 1);
					}
					else
					{
						resultDnf += symbolNegation + symbolArg + to_string(g + 1);
					}
					if (g != (nArguments - 1))
					{
						resultDnf += symbolDisjunct;
					}
				}
				resultDnf += );
			}
			else if (targetChar == '1') DDNF
			{
				resultDnf += symbolDisjunct + (;
				for (int g = 0; g  nArguments; g++)
				{
					if (tableForNvalues[i][g] == targetChar)
					{
						resultDnf += symbolArg + to_string(g + 1);
					}
					else
					{
						resultDnf += symbolNegation + symbolArg + to_string(g + 1);
					}
				}
				resultDnf += );
			}
		}
	}
	if (targetChar == '0')
	{
		if ((resultDnf[0] == symbolConjunct[0]) && (resultDnf[symbolConjunct.size() - 1] == symbolConjunct[symbolConjunct.size() - 1]))
			resultDnf.erase(0, symbolConjunct.size());
	}
	else if (targetChar == '1')
	{
		if ((resultDnf[0] == symbolDisjunct[0]) && (resultDnf[symbolDisjunct.size() - 1] == symbolDisjunct[symbolDisjunct.size() - 1]))
			resultDnf.erase(0, symbolDisjunct.size());
	}

	return resultDnf;
}

int main()
{
	const int maxTable = 1024; 1024 - means that can use up to 10 arguments (2^10)

	int nArguments = 4, maxArguments = 10; default values
	string binaryValues;
	long long int numberEntered;

	cout  Create table, values and ddnfddnf to it from entered number  endl;
	nArguments = setNarguments(maxArguments); vvedennya kilkosti argumentiv
	int tableForNarg = pow(2, nArguments);
	cout  Enter the number in 10-number system  endl;
	cin  numberEntered;
	cout    endl;
	binaryValues = func10in2(numberEntered);
	cout  You entered number   numberEntered  , and this number in binary   binaryValues    endl;

	binaryValues = setSomeZeros(binaryValues, tableForNarg);
	cout  Final binary string   binaryValues    endl;

	string tableForNvalues[maxTable]; obyavlennya massivy, yakyi byde mistiti znachennya dlya nashoi tablici
	for (int i = 0; i  tableForNarg; i++)
	{
		tableForNvalues[i] = setSomeZeros(func10in2(i), nArguments);
	}

	cout  Table of values (for   nArguments   arguments)  endl;
	for (int i = 0; i  tableForNarg; i++) vivod tablici istinnosti
	{
		cout    tableForNvalues[i]    binaryValues[i]    endl;
	}

	DDNF and DKNF
	string ddnfString = createDnf(nArguments, tableForNarg, binaryValues, tableForNvalues, '1');
	string dknfString = createDnf(nArguments, tableForNarg, binaryValues, tableForNvalues, '0');

	cout  DDNF   ddnfString  endl;
	cout  DKNF   dknfString  endl  endl;

	return main();
}