
//#define WIN32_MEAN_AND_LEAN
//#define CYBER_INC_STD

#include "../core/data.h"
using namespace std;

int main(void){

	//Visual, Manual Tests
	std::cout << "*********DATACONSTUCT**********" << std::endl;
	Cyber::Data data1;
	data1.Set("Hello World");
	
	assert(data1 == "Hello World");
	
	std::cout << "Assertion `data1 == \"Hello World\"` passed." << std::endl;

	Cyber::Data data2(data1);
	data1.Set("Welcome");
	
	assert(data1 == "Welcome");
	std::cout << "Assertion `data1 == \"Welcome\"` passed." << std::endl;
	assert(data2 == "Hello World");
	std::cout << "Assertion `data2 == \"Hello World\"` passed." << std::endl;

	Cyber::Data data3("HALLO WORLD",13);
	
	assert(data3 == "HALLO WORLD");
	std::cout << "Assertion `data3 == \"HALLO WORLD\"` passed." << std::endl;
	assert(data3.Length() == 11);
	std::cout << "Assertion `data3.Length() == 11` passed." << std::endl;

	std::cout << "*********DATA = **********" << std::endl;
	Cyber::Data data4 = data3;
	
	assert(data4 == "HALLO WORLD");
	std::cout << "Assertion `data4 == \"HALLO WORLD\"` passed." << std::endl;
	assert(data4.Length() == 11);
	std::cout << "Assertion `data4.Length() == 11)` passed." << std::endl;

	std::cout << "*********DATA Set**********" << std::endl;
	data3.Set("LESS THAN TEN", 10);//Test for less size
	
	assert(data3 == "LESS THAN ");
	std::cout << "Assertion `data3 == \"LESS THAN \"` passed." << std::endl;
	assert(data3.Length() == 10);
	std::cout << "Assertion `data3.Length() == 10)` passed." << std::endl;

	std::cout << "*********DATA ADD ( += )**********" << std::endl;
	Cyber::Data data5;
	std::cout << "Length = " << data5.Length() << std::endl;
	data5 += data3;
	std::cout << data3 << std::endl;
	std::cout << data5 << std::endl;
	std::cout << "Length = " << data5.Length() << std::endl;
	assert(data5 == "LESS THAN ");
	std::cout << "Assertion `data5  == \"LESS THAN \")` passed." << std::endl;
	assert(data5.Length() == 10);
	std::cout << "Assertion `data5.Length() == 10` passed." << std::endl;
	data5 += data1;
	data5 += data2;
	data5 += data4;

	std::cout << data1 << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data3 << std::endl;
	std::cout << data4 << std::endl;
	std::cout << data5 << std::endl;
	
	std::cout << "*********DATA Log**********" << std::endl;
	data5.Log((int8*)"Woohooooo\r\n");
	data5.Log((int8*)"BOOOOO\r\n");

	std::cout << "*********DATA GetLog**********" << std::endl;
	std::cout << data5.GetLog() << std::endl;

#if defined(WIN32_MEAN_AND_LEAN)
	system("pause");
#else
	std::cout << std::endl << "Press any key to continue . . .";
	int gc = getchar();
#endif
	return 0;

}
