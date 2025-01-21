#include<string>
#include"Credentials.h"


class Admin:public Credentials
{
private:
public:
	Admin();
	void Options();
	void Add();
	void Stock();
	void Refill();
	void Remove();
	void Status();
	void Modify();
	void Reciepts();
	void Search();
	void ShowAllDetails();
};

