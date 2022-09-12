#include <iostream>
using namespace std;

class MyString {
	private:
		char* str;
		char* strsearch;
		int length;
	public:
		MyString();
		MyString(const char* txt);

		~MyString();
		void Input();
		void Conclusion();
		MyString(const MyString& str);
		void MyStrStr(const char* str);
		void  MyChr();
};

void MyString::MyChr()
{
	cout << endl << "Input symbol for search:";
	char submol;
	cin>> submol;
	int count=1;
	int coub = 1;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == submol) {

			cout << endl << "Symbol " << submol << " : " << count;
			coub = true;

		}
		else {
			count++;
			coub = false;
		}
	}
	if (coub == false) {
		cout << endl << "Symbol not found";

	}
	
}

MyString::MyString(const MyString& temp)
{
	str = new char[strlen(temp.str) + 1];
	strcpy_s(str, strlen(temp.str) + 1, temp.str);
	cout << endl << "Copyy";
}

void MyString::MyStrStr(const char* txt)
{
	cout << endl << "Input text for search:";
	strsearch = new char[strlen(txt) + 1];
	strcpy_s(strsearch, strlen(txt) + 1, txt);

		

}



MyString::MyString()
{
	str = nullptr;
	length = 0;
}

MyString::MyString(const char* txt)//ввод строки любого ра3мера
{
	
	str = new char[strlen(txt) + 1];
	strcpy_s(str, strlen(txt) + 1, txt);


}

MyString::~MyString()
{
	delete[]str;
}

void MyString::Input()//до 80 символов
{
	char buff[80];
	cout << "Enter txt -  ";
	cin.getline(buff, 80);
	if (str != nullptr)
	{
		delete[]str;
	}
	str = new char[strlen(buff) + 1];
	strcpy_s(str, strlen(buff) + 1, buff);
	length = strlen(str);

}

void MyString::Conclusion()
{
	cout << endl << "txt - " << str;
}




int main() {

	 
	
	MyString obj1;
	MyString str("ASDFasdfasdfak;askdf;alskdf;laksdfaskd;flkas;dfk;asdkf;laks;dfk;aks;ldfka;lskdf;asdkf;aksd;lfkaksd;flkalsdfsalkdf;laskdf;laskdf;lkas;ldfk;laskdf;asldkfl;askdf;lsakdf;as;ldfk;klasdfk;fasdk;lafsd;klfsadk;lafsdk;lfasd;klafsd;kfasd;kfasd;kalfsd;lkafsd;klfdsakfasd;klfas;ldfsadf");
	//больше 80символов
	//str.Conclusion();
	obj1.Input();
	obj1.Conclusion();
	MyString obj2(obj1);//делаем копию , вы3ывая констрктор.
		obj2.Conclusion();
	obj1.MyChr();
	
	
}


