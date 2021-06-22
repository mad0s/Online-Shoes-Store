#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<fstream>
#include<unistd.h>
using namespace std;


void RegAdmin(void);//admin
void ModifyKasut(void);//admin
void asmincheckout(void);//admin
void ADMIN(void);//admin


void LogIn(void);
void SignUp(void);
void CustBrand(void);//5 jenama
int CustBrandJenis(int);//function Jenis Tiap Jenama
void CART(void);
void CheckOutt(void);
void Details(void);
void payment(void);
void Resit(void);

int main()
{
	std::ofstream out;
  	out.open ("CART.txt",  std::ofstream::out | std::ofstream::trunc);
	int choose,choose1;
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << dt << endl;
	
	cout<<" ";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	
	cout<<"\tPlease choose : ";
	cout<<"\n\n\t1.Admin ";
	cout<<"\n\t2.Customer "	;
	cout<<"\n\n\t99.Exit ";
	
	cout<<"\n\t>> ";
	cin>>choose;
	
	switch(choose)
	{
		case 1 :
			system("CLS");
			ADMIN();
			
		case 2 :
			system("CLS");
			
				
				
				cout<<" ";
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n\n\n";
				
				
				cout<<"\tPlease choose : ";
				cout<<"\n\n\t1.Log in ";
				cout<<"\n\t2.Sign Up "	;
				cout<<"\n\n\t99.Back";
				cout<<"\n\t>> ";
				cin>>choose1;
				
				if(choose1==1)
				{
					system("CLS");
					LogIn();/*panggil function log in*/
				}
				
				else if(choose1==2)
				{
					system("CLS");
					SignUp();	
				}
				else if(choose1==99)
				{
				system("CLS");
				main();
				}
				else
				cout<<"Invalid input,please enter again.Back to homepage\n";
				system("pause");
				system("CLS");
				main();	
		case 99 :
				{
				system("CLS");
				cout<<"\n\tSee you next time. ^,^";
				cout<<"\n\tLogging out";
				for(int i=0; i<73; i++)
				{
		
				usleep(100000);
				cout<<".";
				if(i==72)
				break;
				
				}
				exit(0);
				}
					
		default :
			cout<<"Invalid input,please enter again.Back to homepage\n";
			system("pause");
			system("CLS");
			main();		
		
	}
	return 0;
	
}

struct reg
	 {
		string username;
		string password;

	  };


void LogIn(void)
{
	
	string uscheck,pwcheck,username,password;
	bool found=false;
	
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << dt << endl;
	
	std::ifstream in;
	in.open("Reg.txt", std::ifstream::in);
	std::ofstream out;
  	out.open ("Reg.txt",  std::ofstream::out | std::ofstream::app);
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	cout<<"\n\tPlease enter your\n";
	cout<<"\n\tUsername : ";
	cin>>username;
	cout<<"\tPassword : ";
	cin>>password;
	
	while(!in.eof())
	{
		in>>uscheck>>pwcheck;
		
		if(username==uscheck&&password==pwcheck)
		{
			found=true;
			break;
		}

	}
	
	if(found)
	{
	system("CLS");
	cout<<"\n\tSuccesfully log in\n\t";
	system("pause");
	cout<<endl;
	CustBrand();
	}
	
	else
	{
	cout<<"\n\nUser not found\n\tPlease sign up first\n\t";
	system("pause");
	system("CLS");
	SignUp();
	}
	
	in.close();
	out.close();
	
}

void SignUp()
{
	
	std::ifstream in;
	in.open("Reg.txt", std::ifstream::in);
	std::ofstream out;
  	out.open ("Reg.txt",  std::ofstream::out | std::ofstream::app);
	
	reg cust;
	string us,pw;
	string uscheck,pwcheck;
	int count;
	bool found=false;
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	cout<<"\n\tSign Up your account\n";
	cout<<"\n\n\tEnter your username : ";
	cin>>cust.username;
	cout<<"\tEnter your password : ";
	cin>>cust.password;
	
	out<<cust.username<<"\t\t"<<cust.password<<endl;
	system("CLS");
	cout<<"\n\tSuccess register,please log in"<<endl;
	
	cout<<uscheck;
	cout<<"\n\tUsername : ";
	cin>>us;
	cout<<"\tPassword : ";
	cin>>pw;
	

	
	while(!in.eof())
	{
		in>>uscheck>>pwcheck;
		
		if(us==uscheck&&pw==pwcheck)
		{
			found=true;
			break;
		}

	}
	
	if(found)
	{
	cout<<"\n\tSuccesfully log in\n";
	system("CLS");
	cout<<"\n\t";
	system("pause"); //program akan stop kejap,tekan enter baru keluar prog
	system("CLS");
	CustBrand();//panggil function brand
	}
	
	else
	{
		system("CLS");
		cout<<"\n\tUser not found. Please check your username and password\n";
		LogIn();
	}
	
	
	
	in.close();
	out.close();
	

}

void CustBrand()
{
	int option;
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << dt << endl;
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	cout<<"\n\t1.NIKE ";
	cout<<"\n\t2.ADIDAS ";
	cout<<"\n\t3.VANS ";
	cout<<"\n\t4.FILA ";
	cout<<"\n\t5.TIMBERLAND ";
	cout<<"\n\n\t88.Cart ";
	cout<<"\n\t99.EXIT ";
	cout<<"\n\t\t>> ";
	cin>>option;
	
	if(option==1|option==2|option==3|option==4|option==5)
	{
	system("CLS");
	CustBrandJenis(option);
	}
	else if(option==88)
	{
		system("CLS");
		CART();	//panggil function Cart
	}
	else if(option==99)
	{
		system("CLS");
		exit(0);
		//panggil function Back
	}
	else
	system("CLS");
	cout<<"\n\tInvalid input\n";
	CustBrand();
	//panggil function JenisBrand(int option)
		
}

struct kasut
{
	string name;
	float price;
	int quantity;
	int size;
};

int CustBrandJenis(int opt)//function brand
{
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << dt << endl;
	
	
	kasut jenis[10];
	int button,opts;
	string hold1;
	int countNIKE,countADIDAS,countTIMBER,countVANS,countFILA;
	
	ifstream in ("NIKE.txt");
	ifstream inn ("ADIDAS.txt");
	ifstream innn ("VANS.txt");
	ifstream innnn ("FILA.txt");
	ifstream innnnn ("TIMBERLAND.txt");
	
	std::ofstream out;
  	out.open ("CART.txt",  std::ofstream::out | std::ofstream::app);
	
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	cout<<"\n\t||	Pick number to choose	||||	SORT Price Ascending(33) / Descending(44)	||\n";
	
	switch(opt)
	{
		case 1:
			
			for(int i=0;i<10;i++)
				{
					
					getline(in,jenis[i].name,';');
					in>>jenis[i].price;
					in.ignore();
				}
				break;
		case 2:
			for(int i=0;i<10;i++)
				{
					getline(inn,jenis[i].name,';');
					inn>>jenis[i].price;
					inn.ignore();
				}
				break;
		case 3:
			for(int i=0;i<10;i++)
				{
					getline(innn,jenis[i].name,';');
					innn>>jenis[i].price;
					innn.ignore();
				}
				break;
		case 4:
			for(int i=0;i<10;i++)
				{
					getline(innnn,jenis[i].name,';');
					innnn>>jenis[i].price;
					innnn.ignore();
				}
				break;
		case 5:
			for(int i=0;i<10;i++)
				{
					getline(innnnn,jenis[i].name,';');
					innnnn>>jenis[i].price;
					innnnn.ignore();
				}
				break;
	}
	in.close();
	inn.close();
	innn.close();
	innnn.close();
	innnnn.close();
	
	out.close();
	
	
	
	in.open ("NIKE.txt");
	inn.open ("ADIDAS.txt");
	innn.open ("VANS.txt");
	innnn.open ("FILA.txt");
	innnnn.open ("TIMBERLAND.txt");

  	out.open ("CART.txt",  std::ofstream::out | std::ofstream::app);
  	
	
	cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t\n";
	for(int i=0;i<10;i++)
	{
		cout<<"\n\t"<<i+1<<"."<<jenis[i].name<<"\t|\t"<<"\tRM "<<jenis[i].price;
	}
	
	
	cout<<"\n\n\t88.Cart";
	cout<<"\n\n\t99.Back";
	cout<<"\n\t\t>>>";
	cin>>button;
	
	
	switch(button)
	{
		case 1 :
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
	
		case 2:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		case 3:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		case 4:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		case 5:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		case 6:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		case 7:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		case 8:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		case 9:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		case 10:
		cout<<"\n\n\t\tYou had chose "<<jenis[button-1].name<<" "<<"RM "<<jenis[button-1].price;
		cout<<"\n\t\t\tSize(38-48) : ";
		cin>>jenis[button-1].size;
		cout<<"\t\t\tQuantity : ";
		cin>>jenis[button-1].quantity;
		out<<jenis[button-1].name<<";"<<jenis[button-1].price<<" "<<jenis[button-1].size<<" "<<jenis[button-1].quantity<<"\n";
		break;
		
		
		out.close();
		case 33:
		//panggil fuction brand
		{
					
					system("CLS");
					for (int pass=1;pass<10;pass++)		//NUMBER OF PASS (START DENGAN 1)
				
						for(int i=0;i<9;i++)		//NUMBER OF ITERATION (START DENGAN 0 DAN KURANG 1 DARI SIZE)
				
							if(jenis[i].price>jenis[i+1].price)  // >(ASCENDING) <(DESCENDING)
							{
								int hold=jenis[i].price;
								hold1=jenis[i].name;
								jenis[i].price=jenis[i+1].price;
								jenis[i].name=jenis[i+1].name;
								jenis[i+1].price=hold;
								jenis[i+1].name=hold1;
							}
					cout<<endl<<endl;
					cout<<"\t********************************************************************************\n";
					cout<<"\t********************************************************************************\n";
					cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
					cout<<"\t********************************************************************************\n";
					cout<<"\t********************************************************************************\n\n\n";
					cout<<"\n\t\tData items in ascending order "<<endl;
					cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t\n";
					for(int i=0;i<10;i++)
					{
						cout<<"\n\t"<<i+1<<"."<<jenis[i].name<<"\t|\t"<<"\tRM "<<jenis[i].price;
						
					}
					cout<<"\n\n\t";
					system("pause");
					system("CLS");
					CustBrand();
								
		}
		case 44:
		//panggil fuction brand
		{
					
					system("CLS");
					for (int pass=1;pass<10;pass++)		//NUMBER OF PASS (START DENGAN 1)
				
						for(int i=0;i<9;i++)		//NUMBER OF ITERATION (START DENGAN 0 DAN KURANG 1 DARI SIZE)
				
							if(jenis[i].price<jenis[i+1].price)  // >(ASCENDING) <(DESCENDING)
							{
								int hold=jenis[i].price;
								hold1=jenis[i].name;
								jenis[i].price=jenis[i+1].price;
								jenis[i].name=jenis[i+1].name;
								jenis[i+1].price=hold;
								jenis[i+1].name=hold1;
							}
					cout<<endl<<endl;
					cout<<"\t********************************************************************************\n";
					cout<<"\t********************************************************************************\n";
					cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
					cout<<"\t********************************************************************************\n";
					cout<<"\t********************************************************************************\n\n\n";
					cout<<"\n\t\tData items in descending order "<<endl;
					cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t\n";
					for(int i=0;i<10;i++)
					{
						cout<<"\n\t"<<i+1<<"."<<jenis[i].name<<"\t|\t"<<"\tRM "<<jenis[i].price;
						
					}
					cout<<"\n\n\t";
					system("pause");
					system("CLS");
					CustBrand();
						
		}
		case 88:
			system("CLS");
			CART();
			//panggil function cart
		case 99:
			system("CLS");
			CustBrand();//panggil function back;
		break;
		
	}
	
	
	in.close();
	inn.close();
	innn.close();
	innnn.close();
	innnnn.close();
	
	out.close();
	
	cout<<endl;

	cout<<"\n\n\t\tContinue shopping (11) or Check out (22)";
	cout<<"\n\t\t>>>";
	cin>>button;
	
	if(button==11)
	{
		system("CLS");
		CustBrand();//panggil function BRAND
	}
	else if(button==22)
	{
		system("CLS");
		CART();
		//panggil function checkout
	}
	
	return 0;
}


struct CartShoe
{
	string name;
	float price;
	int size;
	int quantity;
};

void CART()//function cart
{

	time_t now = time(0);
	char* dt = ctime(&now);
	cout <<"\t"<< dt << endl;
	
	/*ifstream in ("1.troli.txt");
	ofstream out ("1.troli.txt");*/
	std::ifstream in;
	in.open("CART.txt", std::ifstream::in);
	std::ofstream out;
  	out.open ("CART.txt",  std::ofstream::out | std::ofstream::app);
	
	int sum=0,count=0,button,bil=0;
	string line;
	float total=0;
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";  	
	cout<<"\n\t MY CART 							\n";
	cout<<"\n\t\tTYPE\t\t\t|\t\tSIZE\t\t|\t\tQUANTITY\t\t|\tPRICE";
	
	while (getline(in,line))
	bil++;
	
	in.close();
	
	CartShoe cart[bil];
	
	in.open("CART.txt", std::ifstream::in);
	for(int i=0;i<bil;i++)
	{
		getline(in,cart[i].name,';');
		cout<<"\n\t"<<i+1<<"."<<cart[i].name;
		in>>cart[i].price>>cart[i].size>>cart[i].quantity;
		cout<<"\t\t\t"<<cart[i].size<<"\t\t\t\t"<<cart[i].quantity<<"\t\t\t\t"<<cart[i].price<<endl;
		sum+=cart[i].quantity;
		total+=cart[i].price;
		in>>ws;
	}
	
	cout<<"\n\n\tItem : "<<sum<<"\t\t\t\t\t\t\t\t\t\t\tTotal : RM"<<total;
	
	cout<<"\n\n\tDelete item(66)		Checkout(77)		Continue shopping(88)";
	cout<<"\n\t>> ";
	cin>>button;
	
	if(button==66)
	{
		cout<<"\n\tRemove item no >> ";
		cin>>button;
		button=button-1;

		std::ifstream in;
		in.open("CART.txt", std::ifstream::in);
		std::ofstream out;
  		out.open ("CART.txt",  std::ofstream::out);
		
		for(int i=0;i<bil;i++)
		{
			in.ignore();
			getline(in,cart[i].name,';');
			in>>cart[i].price>>cart[i].size>>cart[i].quantity;
			
		}
		
		for(int i=0;i<bil;i++)
		{
			if(i!=button)
			{
				
			out<<cart[i].name<<" ;"<<cart[i].price<<" "<<cart[i].size<<" "<<cart[i].quantity<<endl;
			}
		}	
	
		in.close();
		out.close();
		//outt.close();
		system("CLS");
		CART();	
				
	}	
	else if(button==77)
	{
		system("CLS");
		Details();//panggil function checkout
	}
	else if(button==88)
	{
		system("CLS");
		CustBrand();
		//back to brand
	}
	else
	{
		system("CLS");
		cout<<"\n\n\tInvalid value.";
		CART();
	}


}

struct checkout
	{
		string name, phoneNum, address, email;
	};

struct shoes
{
	string shoesName;
	float price;
	int quantity, size;
};

struct ShoesCount
{
	string shoesName1;
	float price1;
	int quantity1, size1;
};

void CheckOutt()
{
	int bil=0;
	string line;
	
	ifstream inD("CART.txt");
	
	while (getline(inD,line))
	bil++;
	
	inD.close();
	

	checkout info;
	ifstream inData("CustInfo.txt");
	ofstream outData("AfterCustInfo.txt");
	
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t***********************       		CHECKOUT           *********************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	
	if(inData.fail())
	{
		cout<<"Input file does not exist.\n";
		cout<<"Press any key to edit. \n";
	
	}	
	else
	{
		getline(inData,info.name,';');
		getline(inData,info.phoneNum,';');
		getline(inData,info.address,';');
		getline(inData,info.email,';');
		
		cout<<"\tName\t\t:       "<<info.name<<endl;
		cout<<"\tPhone Number\t: "<<info.phoneNum<<endl;
		cout<<"\tAddress\t\t: "<<info.address<<endl;
		cout<<"\tEmail\t\t: "<<info.email<<endl;
		cout<<"\n\n\n";
	}

	
	inD.open("CART.txt");
	ofstream outD("CONFIRM.txt",  std::ofstream::out | std::ofstream::app);
	
	shoes shoesInfo[bil];

	int count=0;
	for(int i=0;i<bil;i++)
	{
		if(i==bil)
		break;
		else
		{
		getline(inD,shoesInfo[i].shoesName,';');
		inD>>shoesInfo[i].price>>shoesInfo[i].size>>shoesInfo[i].quantity;
		outD<<shoesInfo[i].shoesName<<";"<<shoesInfo[i].price<<" "<<shoesInfo[i].size<<" "<<shoesInfo[i].quantity<<endl;
		count++;
		cout<<"\tShoes Name: "<<shoesInfo[i].shoesName<<endl;
		cout<<"\tShoes Size: "<<shoesInfo[i].size<<endl;
		cout<<"\tShoes Price: RM"<<shoesInfo[i].price<<endl;
		cout<<"\tShoes Quantity: "<<shoesInfo[i].quantity<<endl;
		cout<<"\n";
		inD>>ws;
		}
	}
	
	int button;
	cout<<"\n\tEnter 88 to go back to Cart.";
	cout<<"\n\tEnter 99 to go back to Payment.";
	cout<<"\n\t>>>";
	
	cin>>button;
	
	if(button==88)
	{
		system("CLS");
		CART();
	}
	else if(button==99)
	{
		system("CLS");
		payment();	
	}
	//panggil function payment
	else
	{
		CheckOutt();	
	}

}

struct details
{
	string name, phoneNum, address, email, deliveryOpt;
	
};

void Details()
{
	details custInfo;
	ifstream inData("CustInfo.txt",  std::ofstream::in);
	
	if(inData.fail())
	{
		getline(cin,custInfo.name,';');
		getline(cin,custInfo.phoneNum,';');;
		getline(cin,custInfo.address,';');
		getline(cin,custInfo.email,';');
		
		CheckOutt();	
	}
	
	inData.close();
	
	ofstream outData("CustInfo.txt",  std::ofstream::out | std::ofstream::trunc);
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t***************		WELCOME TO AH.SNEAKERS.OUTLET       ********************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	
	cout<<"\t************************  Please enter details below  **************************\n"<<endl<<endl;
	
	cin.ignore();
	cout<<"\tEnter full name: ";
	getline(cin,custInfo.name);
	cout<<"\tEnter phone number: ";
	getline(cin,custInfo.phoneNum);
	cout<<"\tEnter shipping address: ";
	getline(cin,custInfo.address);
	cout<<"\tEnter email address: ";
	getline(cin,custInfo.email);

	cout<<"\n\n\t****Proceed to checkout****\n\n\n\n";
	
	
	
	outData<<custInfo.name<<"; "<<"\t";
	outData<<custInfo.phoneNum<<"; "<<"\t";
	outData<<custInfo.address<<"; "<<"\t";
	outData<<custInfo.email<<"; "<<"\t";
	outData<<custInfo.deliveryOpt<<"; "<<endl;
	
	cout<<"\t";
	system("pause");
	//panggil function checkout
	system("CLS");
	CheckOutt();
	
	
	
	outData.close();
	
}


void payment()
{
	int payMet, cvv;
	string BankType1, BankType2, amount1, amount2, ownerName1, ownerName2, cardNum, passcode1, passcode2;
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t***********************       		PAYMENT           **********************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	
	cout<<"\t1. CREDIT/DEBIT CARD "<<endl;
	cout<<"\t2. ONLINE BANKING "<<endl;
	cout<<"\n\tChoose your payment method: ";
	cin>>payMet;
	
	if(payMet==1)
	{
		cin.ignore();
		cout<<"\n\tEnter Type of Bank: ";
		getline(cin,BankType1);
		
		cout<<"\tEnter Card Number: ";
		getline(cin,cardNum);
		
		cout<<"\tEnter Amount: RM"; 
		cin>>amount1;
				
		cout<<"\tEnter CVV: ";
		cin>>cvv;
		
		cout<<"\tEnter Owner Name: ";
		getline(cin,ownerName1);
		
		cin.ignore();
		
		cout<<"\tEnter Passcode: ";
		getline(cin,passcode2);
		
		cin.ignore();
		
		cout<<"\n\tLoading ";
		for(int i=0; i<73; i++)
		{
		
			usleep(100000);
			cout<<"|";
			if(i==72)
			break;
			
		}
		
	 	system("CLS");
		cout<<"\n\n\n\tPAYMENT SUCCESSFULL!\n\n";
		Resit();
		
	}
	else if(payMet==2)
	{
		cin.ignore();
		cout<<"\tEnter Type of Bank: ";
		getline(cin,BankType2);
		cout<<"\tEnter Owner Name: ";
		getline(cin,ownerName2);
		cin.ignore();
		cout<<"\tEnter Amount: "; 
		cin>>amount2;
		cout<<"\tEnter Passcode: ";
		getline(cin,passcode2);
		
		cout<<"\n\tLoading ";
		for(int i=0; i<73; i++)
		{
			
			cout<<"|";
			usleep(100000);
			
		}
		
		system("CLS");
		cout<<"\n\n\t\t\tPAYMENT SUCCESSFULL!\n\n";
		Resit();
	}
		
}

void Resit()
{
	string custName, custPhoneNum, custAddress, custEmail,line;
	float totalPrice=0, amount, subtotal=0;
	int bil=0;
	ifstream inData("CART.txt");
	ifstream inD("CustInfo.txt");

	
	cout<<endl;
	cout << "\t***************************************************************************************************************" << endl;
    cout << "\t****************************************  S A L E S  R E C E I P T  *******************************************" << endl;
    cout << "\t***************************************************************************************************************" << endl;
    cout << "\t*********************************     A H S N E A K E R S O U T L E T    **************************************" << endl;
    cout << "\t***************************************************************************************************************\n" << endl;
    cout <<"\tAHSNEAKERSOUTLET SDN BHD," <<endl;
    cout<<"\tNO 58, JALAN RAJAWALIMATULURUS,"<<endl;
    cout<<"\t054321, SELAYANG,"<<endl;
    cout<<"\tSELANGOR DARUL IHSAN"<<endl;
    
    
    if(inD.fail())
	{
		cout<<"Input file does not exist.\n";
		cout<<"Press any key to edit. \n";
	}	
	else
	{
		getline(inD,custName,';');
		getline(inD,custPhoneNum,';');
		getline(inD,custAddress,';');
		getline(inD,custEmail,';');
		
	}
	
	cout<<"\n\tShip To : "<<endl<<endl;
	cout<<"\t"<<custName<<endl;
	cout<<custPhoneNum<<endl;
	cout<<custAddress<<endl;
	cout<<custEmail<<endl;
	
	cout<<"\n\t________________________________________________________________________________________________________________"<<endl;
	cout<<"\tQUANTITY\t\tSHOES NAME\t\t\t\t\t\tUNIT PRICE\t\t\tAMOUNT"<<endl;
	cout<<"\t________________________________________________________________________________________________________________"<<endl;
	
	while (getline(inData,line))
	bil++;
	
	inData.close();
	string shoesName[bil];
	float shoesPrice[bil];
	int shoesSize[bil], shoesQuantity[bil];
	
	inData.open("CART.txt");	
	for(int i=0;i<bil;i++)
	{
		if(i==bil)
		break;
		else
		{
			amount=0;
			getline(inData,shoesName[i],';');
			inData>>shoesPrice[i]>>shoesSize[i]>>shoesQuantity[i];
			inData.ignore();
			amount=shoesQuantity[i]*shoesPrice[i];
			cout<<endl;
			cout<<"\t"<<shoesQuantity[i]<<"\t\t";
			cout<<"\t"<<shoesName[i]<<"\t\t\t\t";
			cout<<"\t"<<shoesPrice[i]<<"\t\t\t";
			cout<<amount;
			subtotal+=amount;
			cout<<"\n";
		}
	}
	inData.close();
	
	cout<<"\n\t________________________________________________________________________________________________________________"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tSUBTOTAL: RM"<<subtotal<<endl;
	cout<<"\t__________________________________________________________________________________________________________________"<<endl;
	
	cout<<"\n\tPlease keep this receipt for prove of your payment and shipment and warranty";
	
	cout<<"\n\n\t";
	system("pause");
	exit(0);

	inD.close();
	inData.close();
	
}

void ADMIN()
{

	string uscheck,pwcheck,userID,passID;
	bool found=false;
	
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << dt << endl;
	
	std::ifstream in;
	in.open("RegAdmin.txt", std::ifstream::in);
	std::ofstream out;
  	out.open ("RegAdmin.txt",  std::ofstream::out | std::ofstream::app);
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			WELCOME TO AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	cout<<"\tPlease enter your\n";
	cout<<"\tUserID : ";
	cin>>userID;
	cout<<"\tPassword : ";
	cin>>passID;
	
	
	while(!in.eof())
	{
		getline(in,uscheck,';');
		getline(in,pwcheck);
		//in>>uscheck>>pwcheck;
		
		if((userID==uscheck)&&(passID==pwcheck))
		{
			found=true;
			break;
		}

	}
	in.close();
	out.close();
	
	if(found)
		{
			//ifstream in("RegAdmin.txt");
			//ofstream out("RegAdmin.txt");
			system("CLS");
			cout<<"\tSuccesfully log in\n";
			system("pause");
			//in.close();
			//out.close();
			cout<<endl;
			asmincheckout();
			//panggil function MenuAdmin
		}
	else
		{
			//ifstream in("RegAdmin.txt");
			//ofstream out("RegAdmin.txt");
			cout<<"\n\n\tUser not found\n\tPlease refer to administrator\n";
			system("pause");
			system("CLS");
			in.close();
			out.close();
			main();
			//panggil function main
		}
	
	in.close();
	out.close();
	
	
}

struct order
{
	string name;
	float price;
	int size,quantity;
}kasut;

void asmincheckout()
{	
	system("CLS");
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << dt << endl;
	
	int button,option,bil=0,i=0;
	string line;
	float profit;
	float total=0;
	std::ifstream in;
	in.open("RegAdmin.txt", std::ifstream::in);
	std::ifstream inn;
	inn.open("CONFIRM.txt", std::ifstream::in);
	//std::ofstream out;
  	//out.open ("RegAdmin.txt",  std::ofstream::out | std::ofstream::app);
  	//std::ofstream outt;
  	//outt.open ("CARTU.txt",  std::ofstream::out | std::ofstream::app);
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t				AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";
	
	cout<<"\t1.Order received \n";
	cout<<"\n\t2.Add new admin\n";
	cout<<"\n\t3.Add new shoe";
	cout<<"\n\n\t99.Log out";
	
	cout<<"\n\n\t>>> ";
	cin>>button;
	
	switch(button)
	{
		case 1 :
			{
			std::ifstream inn;
			inn.open("CONFIRM.txt", std::ifstream::in);
			system("CLS");
			cout<<"\t********************************************************************************\n";
			cout<<"\t********************************************************************************\n";
			cout<<"\t				AH.SNEAKERS.OUTLET\n";
			cout<<"\t********************************************************************************\n";
			cout<<"\t********************************************************************************\n\n\n";
			
			while (getline(in,line))
			bil++;
			inn.close();
			
			inn.open("CONFIRM.txt", std::ifstream::in);
			if(inn.fail())
			{
				cout<<"\n\tThere is no order for the shoe.";
			}
			inn.close();
			cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t|\t\tSIZE\t\t|\t\tQUANTITY\t\t\n";	
			inn.open("CONFIRM.txt", std::ifstream::in);
			while(!inn.eof())
			{	
				getline(inn,kasut.name,';');
				inn>>kasut.price>>kasut.size>>kasut.quantity;
				in>>ws;
				cout<<"\n\t"<<i+1<<"."<<kasut.name<<"\t|\t"<<"\tRM "<<kasut.price<<"\t\t|\t\t"<<kasut.size<<"\t\t|\t\t"<<kasut.quantity<<endl;
				i++;
				total=+(kasut.price*kasut.quantity);
				profit+=total;
				inn.ignore();
			}
			inn.close();
			/*for(int i=0;i<bil;i++)
			{
				cout<<"\n\t"<<i+1<<"."<<kasut.name<<"\t|\t"<<"\tRM "<<kasut.price<<"\t|\t"<<kasut.size<<"\t|\t"<<kasut.quantity<<endl;
			}*/
			cout<<"\n\n\tThe profit that we get for this month is RM "<<profit;
			
			cout<<"\n\t";
			system("pause");
			system("CLS");
			asmincheckout();
		}
		case 2:
			system("CLS");
			RegAdmin();
		case 3:
			system("CLS");
			ModifyKasut();
		case 99:
			system("CLS");
			cout<<"\n\tSee you next time. ^,^";
			cout<<"\n\tLogging out";
			for(int i=0; i<73; i++)
		{
		
			usleep(100000);
			cout<<".";
			if(i==72)
			break;
			
		}
			exit(0);
			//exit programme;
		default:
			system("CLS");
			cout<<"\n\tInvalid input";
			asmincheckout();
	}
	
}

void RegAdmin()
{
	system("CLS");
	time_t now = time(0);
	char* dt = ctime(&now);
	cout <<"\t"<< dt << endl;
	
	/*ifstream in ("1.troli.txt");
	ofstream out ("1.troli.txt");*/
	std::ifstream in;
	in.open("RegAdmin.txt", std::ifstream::in);
	std::ofstream out;
  	out.open ("RegAdmin.txt",  std::ofstream::out | std::ofstream::app);
	
	int sum=0,count=0,button,bil=0;
	string line,ID,PW;
	float total=0;
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";  	
	cout<<"  ";
	cout<<"\t\t\tAdmin ";
	
	while (getline(in,line))
	bil++;
	
	in.close();
	out.close();
	
	cout<<"\n\n\tBack(66)		Add new admin(77)		Display available admin(88)";
	cout<<"\t\n>> ";
	cin>>button;
	
	if(button==66)
	{
		cout<<endl;//panggil functiuon asmincheckout
		asmincheckout();
	}
	else if(button==77)
	{
		system("CLS");
		std::ifstream in;
		in.open("RegAdmin.txt", std::ifstream::in);
		std::ofstream out;
  		out.open ("RegAdmin.txt",  std::ofstream::out| std::ofstream::app);
		
			cout<<"\t********************************************************************************\n";
			cout<<"\t********************************************************************************\n";
			cout<<"\t			AH.SNEAKERS.OUTLET\n";
			cout<<"\t********************************************************************************\n";
			cout<<"\t********************************************************************************\n\n\n";  	
			cout<<"  ";
			cout<<"  ";
		cout<<"\n\tEnter new Admin details ";
		cin.ignore();
		cout<<"\n\t ID : ";
		getline(cin,ID);
		cout<<"\t Passsword : ";
		getline(cin,PW);
		out<<ID<<";"<<PW;
		out<<endl;
			
	
		in.close();
		out.close();
		//outt.close();
		system("CLS");
		RegAdmin();					
	}
	else if(button==88)
	{
		system("CLS");
		std::ifstream in;
		in.open("RegAdmin.txt", std::ifstream::in);
		std::ofstream out;
  		out.open ("RegAdmin.txt",  std::ofstream::out| std::ofstream::app);
  		
  			cout<<"\t********************************************************************************\n";
			cout<<"\t********************************************************************************\n";
			cout<<"\t			AH.SNEAKERS.OUTLET\n";
			cout<<"\t********************************************************************************\n";
			cout<<"\t********************************************************************************\n\n\n";  
			cout<<"\t\t\tAvailable admin ";
			cout<<"\n\t ID\t\t\t\t\t\t Password";
			
			string ID[bil];
			string PW[bil];
			for(int i=0;i<bil;i++)
			{
				getline(in,ID[i],';');
				cout<<"\n\t"<<i+1<<"."<<ID[i];
				getline(in,PW[i]);
				cout<<"\t\t\t\t\t\t\t"<<PW[i];
				in>>ws;
			}
			
			in.close();
			out.close();
			cout<<endl;
			system("pause");
			system("cls");
			RegAdmin();
		//back to brand
	}
	else
	system("CLS");
	cout<<"\n\n\tInvalid value."<<endl;
	RegAdmin();


}

struct shoe
{
	string name;
	float price;
	int size,quantity;
};

void ModifyKasut(void)
{
	system("cls");
	shoe jenis[10];
	time_t now = time(0);
	char* dt = ctime(&now);
	cout <<"\t"<< dt << endl;
	
	int sum=0,count=0,button,bil=0,option;
	string line,newshoe;
	float total=0,newprice;
	
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t			AH.SNEAKERS.OUTLET\n";
	cout<<"\t********************************************************************************\n";
	cout<<"\t********************************************************************************\n\n\n";  
	cout<<"\n\tWhich brand do you want to update?";
	cout<<"\n\n\t1.NIKE ";
	cout<<"\n\t2.ADIDAS ";
	cout<<"\n\t3.VANS ";
	cout<<"\n\t4.FILA ";
	cout<<"\n\t5.TIMBERLAND ";
	cout<<"\n\t99.Back ";
	cout<<"\n\t\t>> ";
	cin>>option;
	
	system("CLS");
	
	cout <<"\t"<< dt << endl;
	//if(option==1||option==2||option==3||option==4||option==5||option==99)
	//{
		switch(option)
		{
		case 1:
			{
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t			AH.SNEAKERS.OUTLET\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n\n\n"; 
			
				cout<<"\n\tIf there are no changes just rewrite the original one.\n";
			ifstream in ("NIKE.txt");
			
			for(int i=0;i<10;i++)
				{
					
					getline(in,jenis[i].name,';');
					in>>jenis[i].price;
					in.ignore();
				}
			in.close();
				
					cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t\n";
			2	for(int i=0;i<10;i++)
				{
					cout<<"\n\t"<<i+1<<"."<<jenis[i].name<<"\t|\t"<<"\tRM "<<jenis[i].price;
				}
						
		
				cout<<"\n\t99.Back";		
				cout<<"\n\tEnter item no want to modify >>> ";
				cin>>button;
				if(button==99)
				break;
				button=button-1;
				
				cin.ignore();
				cout<<"\n\t Enter shoe name : ";
				getline(cin,newshoe);
				cout<<"\n\t Enter shoe price : ";
				cin>>newprice;
						
				jenis[button].name=newshoe;
				jenis[button].price=newprice;
				
				ofstream out("NIKE.txt");
				for(int i=0;i<10;i++)
				{	
					out<<jenis[i].name<<" ;"<<jenis[i].price<<endl;
				}
				out.close();
				
			
				system("pause");
				system("CLS");
				ModifyKasut();		
			}	
		case 2:
			{
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t			AH.SNEAKERS.OUTLET\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n\n\n"; 
			
				cout<<"\n\tIf there are no changes just rewrite the original one.\n";
			ifstream inn ("ADIDAS.txt");
			
			for(int i=0;i<10;i++)
				{
					
					getline(inn,jenis[i].name,';');
					inn>>jenis[i].price;
					inn.ignore();
				}
			inn.close();
				
					cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t\n";
				for(int i=0;i<10;i++)
				{
					cout<<"\n\t"<<i+1<<"."<<jenis[i].name<<"\t|\t"<<"\tRM "<<jenis[i].price;
				}
						
				cout<<"\n\t99.Back";		
				cout<<"\n\tEnter item no want to modify >>> ";
				cin>>button;
				if(button==99)
				break;			

				button=button-1;
				
				cin.ignore();
				cout<<"\n\t Enter shoe name : ";
				getline(cin,newshoe);
				cout<<"\n\t Enter shoe price : ";
				cin>>newprice;
						
				jenis[button].name=newshoe;
				jenis[button].price=newprice;
				
				ofstream outt("ADIDAS.txt");
				for(int i=0;i<10;i++)
				{	
					outt<<jenis[i].name<<" ;"<<jenis[i].price<<endl;
				}
				outt.close();
			
				system("pause");
				system("CLS");
				ModifyKasut();		
			}	
		case 3:
			{
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t			AH.SNEAKERS.OUTLET\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n\n\n"; 
			
				cout<<"\n\tIf there are no changes just rewrite the original one.\n";				
			ifstream innn ("VANS.txt");
			
			for(int i=0;i<10;i++)
				{
					
					getline(innn,jenis[i].name,';');
					innn>>jenis[i].price;
					innn.ignore();
				}
			innn.close();
				
					cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t\n";
				for(int i=0;i<10;i++)
				{
					cout<<"\n\t"<<i+1<<"."<<jenis[i].name<<"\t|\t"<<"\tRM "<<jenis[i].price;
				}
						
				cout<<"\n\t99.Back";		
				cout<<"\n\tEnter item no want to modify >>> ";
				cin>>button;
				if(button==99)
				break;			
				button=button-1;
				
				cin.ignore();
				cout<<"\n\t Enter shoe name : ";
				getline(cin,newshoe);
				cout<<"\n\t Enter shoe price : ";
				cin>>newprice;
						
				jenis[button].name=newshoe;
				jenis[button].price=newprice;
				
				ofstream outtt("VANS.txt");
				for(int i=0;i<10;i++)
				{	
					outtt<<jenis[i].name<<" ;"<<jenis[i].price<<endl;
				}
				outtt.close();
				
			
				system("pause");
				system("CLS");
				ModifyKasut();		
			}
			
		case 4:
			{
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t			AH.SNEAKERS.OUTLET\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n\n\n"; 
			
				cout<<"\n\tIf there are no changes just rewrite the original one.\n";				
			ifstream innnn ("FILA.txt");
			
			for(int i=0;i<10;i++)
				{
					
					getline(innnn,jenis[i].name,';');
					innnn>>jenis[i].price;
					innnn.ignore();
				}
			innnn.close();
				
					cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t\n";
				for(int i=0;i<10;i++)
				{
					cout<<"\n\t"<<i+1<<"."<<jenis[i].name<<"\t|\t"<<"\tRM "<<jenis[i].price;
				}
						
				cout<<"\n\t99.Back";		
				cout<<"\n\tEnter item no want to modify >>> ";
				cin>>button;
				if(button==99)
				break;							

				button=button-1;
				
				cin.ignore();
				cout<<"\n\t Enter shoe name : ";
				getline(cin,newshoe);
				cout<<"\n\t Enter shoe price : ";
				cin>>newprice;
						
				jenis[button].name=newshoe;
				jenis[button].price=newprice;
				
				ofstream outttt("FILA.txt");
				for(int i=0;i<10;i++)
				{	
					outttt<<jenis[i].name<<" ;"<<jenis[i].price<<endl;
				}
				outttt.close();
				
			
				system("pause");
				system("CLS");
				ModifyKasut();		
			}
		case 5:
			{
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t			AH.SNEAKERS.OUTLET\n";
				cout<<"\t********************************************************************************\n";
				cout<<"\t********************************************************************************\n\n\n"; 
			
				cout<<"\n\tIf there are no changes just rewrite the original one.\n";				
			ifstream innnnn ("TIMBERLAND.txt");
			
			for(int i=0;i<10;i++)
				{
					
					getline(innnnn,jenis[i].name,';');
					innnnn>>jenis[i].price;
					innnnn.ignore();
				}
			innnnn.close();
				
					cout<<"\n\t\tTYPE\t\t\t|\t\tPRICE\t\t\n";
				for(int i=0;i<10;i++)
				{
					cout<<"\n\t"<<i+1<<"."<<jenis[i].name<<"\t|\t"<<"\tRM "<<jenis[i].price;
				}
						
				cout<<"\n\t99.Back";		
				cout<<"\n\tEnter item no want to modify >>> ";
				cin>>button;
				if(button==99)
				break;							

				button=button-1;
				
				cin.ignore();
				cout<<"\n\t Enter shoe name : ";
				getline(cin,newshoe);
				cout<<"\n\t Enter shoe price : ";
				cin>>newprice;
						
				jenis[button].name=newshoe;
				jenis[button].price=newprice;
				
				ofstream outtttt("TIMBERLAND.txt");
				for(int i=0;i<10;i++)
				{	
					outtttt<<jenis[i].name<<" ;"<<jenis[i].price<<endl;
				}
				outtttt.close();
				
			
				system("pause");
				system("CLS");
				ModifyKasut();		
			}
		
		case 99:
			asmincheckout();
				//panggil function asmincheckout
		default:
			{
				cout<<"\n\tInvalid input";
				asmincheckout();	
			}
		}
	ModifyKasut();	
//	}
	/*else
	{
		system("CLS");
		cout<<"Invalid input";
		asmincheckout();
	}*/
	
	
}





