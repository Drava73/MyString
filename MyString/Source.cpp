#include <iostream>
using namespace std;

class MyString {
	private:
		char* str;
		int length;
	public:
		MyString();
		MyString(const char* txt);

		~MyString();
		void Input();
		void Conclusion();
		MyString(const MyString& str);
};


MyString::MyString(const MyString& temp)
{
	str = new char[strlen(temp.str) + 1];
	strcpy_s(str, strlen(temp.str) + 1, temp.str);
	cout << endl << "Copy";
}

MyString::MyString()
{
	str = nullptr;
	length = 0;
}

MyString::MyString(const char* txt)//���� ������ ������ ��3����
{
	
	str = new char[strlen(txt) + 1];
	strcpy_s(str, strlen(txt) + 1, txt);


}

MyString::~MyString()
{
	delete[]str;
}

void MyString::Input()//�� 80 ��������
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
	MyString str("ASDFasdfasdfak;askdf;alskdf;laksdfaskd;flkas;dfk;asdkf;laks;dfk;aks;ldfka;lskdf;asdkf;aksd;lfkaksd;flkalsdfsalkdf;laskdf;laskdf;lkas;ldfk;laskdf;asldkfl;askdf;lsakdf;as;ldfk;klasdfk;fasdk;lafsd;klfsadk;lafsdk;lfasd;klafsd;kfasd;kfasd;kalfsd;lkafsd;klfdsakfasd;klfas;ldfsadf");//������ 80��������
	obj1.Input();
	obj1.Conclusion();
	MyString obj2(obj1);//������ ����� , ��3���� ����������.
		obj2.Conclusion();
	
}


