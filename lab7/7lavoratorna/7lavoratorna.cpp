#include<string>
#include<iostream>
using namespace std;

class Publication {
protected:
	int pages;
public:
	virtual void cinPages()
	{
		cout << "enter pages:";
		cin >> pages;
	};
	int getPages() {
		return pages;

	}
	virtual void coutPages() {
		cout << "number of pages:  " << getPages() << endl;
		cout << endl;
	}
};

class Book : public Publication {
public:
	void cinPages()
	{
		cout << "enter pages:";
		cin >> pages;
	}
	void coutPages() {
		cout << "book number of pages:" << getPages() << endl;
		cout << endl;
	}

};
class eBook : public Publication {
public:
	void cinPages()
	{
		cout << "enter pages:";
		cin >> pages;
	}
	void coutPages()
	{
		cout << "eBook number of pages:" << getPages() << endl;
		cout << endl;
	}
};
class audioBook : public Publication {
public:
	void cinPages()
	{
		cout << "enter pages:";
		cin >> pages;
	}

	void coutPages() {
		cout << "audiobook number of pages:" << getPages() << endl;
		cout << endl;
	}
};

class magazine : public Publication {
public:
	void cinPages()
	{
		cout << "enter pages:";
		cin >> pages;
	}
	void coutPages() {
		cout << "magazine number of pages:" << getPages() << endl;
		cout << endl;
	};


};

class monograph : public Publication
{
public:
	void cinPages()
	{
		cout << "enter pages:";
		cin >> pages;
	}
	void coutPages()
	{
		cout << "monograph number of pages:" << getPages() << endl;
		cout << endl;
	}
};

int main()
{
	Book Firts;
	Firts.cinPages();
	Firts.coutPages();

	eBook Second;
	Second.cinPages();
	Second.coutPages();

	audioBook Third;
	Third.cinPages();
	Third.coutPages();

	magazine Fourth;
	Fourth.cinPages();
	Fourth.coutPages();

	monograph Fifth;
	Fifth.cinPages();
	Fifth.coutPages();







	return 0;

}