#include "BigInteger.h"
// #include "SignedBigInteger.hpp"

using namespace std;

void testBigInteger()
{    
	cout << "-----------------------Test procedure for BigInteger-----------------------" << endl;        
	BigInteger num1, num2;    
	char instruction;
    	while (1)    
    	{        
    		cout << "Enter q to exit and other to start" << endl;        
    		cin >> instruction;        
    		if (instruction == 'q')            
    			break;
        	cout << "please input num1:" << endl;        
        	cin >> num1;        
        	cout << "please input num2:" << endl;        
        	cin >> num2;        
        	cout << "the result of (num1 + num2) is:" << endl;        
        	cout << num1 + num2 << endl;        
        	cout << "the result of (num1 - num2):" << endl;        
        	cout << num1 - num2 << endl;        
        	cout << "the result of (num1 * num2):" << endl;        
        	cout << num1 * num2 << endl;        
        	cout << "the result of (num1 / num2):" << endl;        
        	cout << num1 / num2 << endl;        
        	// cout << "the result of (num1 % num2):" << endl;        
        	// cout << num1 % num2 << endl;        
        	// cout << endl;
	}
}

// void testSignedBigInteger()
// {    
// 	cout << "-----------------------Test procedure for SignedBigInteger-----------------------" << endl;        
// 	SignedBigInteger num1, num2;    
// 	char instruction;
//     	while (1)    
//     	{        
//     		cout << "Enter q to exit and other to start" << endl;        
//     		cin >> instruction;        
//     		if (instruction == 'q')            
//     			break;
//         	cout << "please input num1:" << endl;        
//         	cin >> num1;        
//         	cout << "please input num2:" << endl;        
//         	cin >> num2;        
//         	cout << "the result of (num1 + num2) is:" << endl;        
//         	cout << num1 + num2 << endl;        
//         	cout << "the result of (num1 - num2):" << endl;        
//         	cout << num1 - num2 << endl;        
//         	cout << "the result of (num1 * num2):" << endl;        
//         	cout << num1 * num2 << endl;        
//         	cout << "the result of (num1 / num2):" << endl;        
//         	cout << num1 / num2 << endl;        
//         	cout << "the result of (num1 % num2):" << endl;        
//         	cout << num1 % num2 << endl;        
//         	cout << endl;
//     	}
// }

int main()
{    
	testBigInteger();    
	// testSignedBigInteger();    
	return 0;
}
