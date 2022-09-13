#include <iostream>
using namespace std;

class MyString {
	private:
		char* str;
		char* strsearch;
		char* nwstr;
		int length;
		static int count;
	public:
		MyString();
		MyString(const char* txt);

		~MyString();
		void Input();
		void Conclusion();
		MyString(const MyString& str);
		bool MyStrStr(const char* str);
		void  MyChr();
		int MyStrLen();
		void MyStrCat(MyString& obj);
		void MyDelChr();
		int MyStrCmp(MyString& b);
		static int GetCount()  
		{
			cout << endl << "Obj in MyString:";
			return count;
		}


};
int MyString::count = 0;


int MyString::MyStrLen()
{
	int length = strlen(str);
	cout << endl <<"Characters in text: " << length;
	
	return 0;
}

void MyString::MyStrCat(MyString& obj)//����������� �����
{
	
	MyString newStr;

	int length = strlen(str);
	int secondlength = strlen(obj.str);

	newStr.str = new char[length + secondlength + 1];

	int i = 0;

	for (; i < length; i++)
	{
		newStr.str[i] = str[i];
	}


	for (size_t j = 0; j < secondlength; j++, i++)
	{
		newStr.str[i] = obj.str[j];
	}

	cout << newStr.str[length + secondlength] ;

	
	
}

void MyString::MyDelChr()
{
	char c;
	
	int length = strlen(str);
	cout << endl << "Input symbol for Del:";
	cin >> c;
	for (int i = 0; i < length; i++)
	{
		if (str[i] != c) {
			for (int j = i; j < length; j++) {
				str[j] = str[i + 1];
				
			}
		}
		else {
			cout << "no symbol" << endl;
		}
	}
	cout << nwstr;
}

int MyString::MyStrCmp(MyString& b)
{
	if (this->length > b.length) {
		return 1;
	}
	else if (this->length < b.length) {
		return -1;
	}
	else {
		return 0;
	}

	
}


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
			break;

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

bool MyString::MyStrStr(const char* str)
{
	int Size = strlen(str);
	for (int i = 0; i < Size; ++i) {
		for (int j = i; j < strlen(str) + 1; ++j) {
			if (this->str[j] != str[j - i]) {
				continue;
			}

			else if (str[j] == '\0') {
				return true;
			}
		}
	}

	return false;

		

}



MyString::MyString()
{
	count++;
	str = nullptr;
	length = 0;
}

MyString::MyString(const char* txt)//���� ������ ������ ��3����
{
	count++;
	str = new char[strlen(txt) + 1];
	strcpy_s(str, strlen(txt) + 1, txt);


}

MyString::~MyString()
{
	delete[]str;
	count--;
}

void MyString::Input()//�� 80 ��������
{
	count++;
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
	MyString obj5;
	MyString str("ASDFasdfasdfak;askdf;alskdf;laksdfaskd;flkas;dfk;asdkf;laks;dfk;aks;ldfka;lskdf;asdkf;aksd;lfkaksd;flkalsdfsalkdf;laskdf;laskdf;lkas;ldfk;laskdf;asldkfl;askdf;lsakdf;as;ldfk;klasdfk;fasdk;lafsd;klfsadk;lafsdk;lfasd;klafsd;kfasd;kfasd;kalfsd;lkafsd;klfdsakfasd;klfas;ldfsadf");
	//������ 80��������
	//str.Conclusion();
	obj1.Input();
	obj1.Conclusion();
	MyString obj2(obj1);//������ ����� , ��3���� ����������.
		obj2.Conclusion();
	obj1.MyChr();
	obj1.MyStrLen();
	
	//obj1.MyDelChr();
	obj1.Conclusion();
	//MyString MyStrCmp(char *obj1,char *obj2);//������ �������� 0 ��� ��� ������ ������ ��� ����� �������.
	cout << MyString::GetCount();//-������ �������� ���.�� ��������.
	

}


