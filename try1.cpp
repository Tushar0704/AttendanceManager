#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
class Voter
{
protected:
	char voter_id[10];
public:
	void getdata()
	{
	label:
		cout << endl << "PLEASE ENTER THE VOTER ID:";
		cin >> voter_id;
		if (strcmpi(voter_id, "18ce001") != 0 && strcmpi(voter_id, "18ce012") != 0 && strcmpi(voter_id, "18ce011") != 0 && strcmpi(voter_id, "18ce020") != 0 && strcmpi(voter_id, "18ce021") != 0 && strcmpi(voter_id, "18ce015") != 0)
		{
			cout << "ENTER VALID VOTER ID";
			goto label;
		}
	}
};
class Party
{
	char party_name[3][4] = { "BJP","INC","AAP" };
public:
	void show_party_name()
	{
		int i;
		cout << endl << "PARTIES:";
		for (i = 0; i < 3; i++)
		{
			cout << endl << i + 1 << " FOR " << party_name[i];
		}
	}
};
class NRI : virtual public Voter
{
protected:
	char nri[4][10] = { "18ce011","18ce012","18ce015" };

};
class IR : virtual public Voter
{
protected:
	char ir[4][10] = { "18ce001","18ce020","18ce021" };
};
class Vote : public NRI, public IR
{
	static int a, b, c, d, e, f;
protected:
	int age, no;
	string voter_name, city, voting_center;
public:
	void get_voter_details()
	{
		Voter::getdata();
		for (int i = 1; i < 4; i++)
		{
			if (strcmpi(voter_id, nri[i]) == 0)
			{
				cout << "Sorry, But you have to do E-Voting" << endl;
				cout << "For more information contact at the Information Desk";
				exit(0);
			}
		}
		if (strcmpi(voter_id, "18ce001") == 0)
		{
			a++;
			if (a > 1)
			{
				cout << "MULTIPLE TIMES VOTING NOT ALLOWED";
			}
			voter_name = "TUSHAR AGARWAL";
			city = "VADODRA";
			age = 18;
			voting_center = "ADAJAN";
		}
		else if (strcmpi(voter_id, "18ce020") == 0)
		{
			voter_name = "DEVANSHU DESAI";
			city = "SURAT";
			age = 18;
			voting_center = "ADAJAN";
			d++;
			if (d > 1)
			{
				cout << "MULTIPLE TIMES VOTING NOT ALLOWED";
			}
		}
		else if (strcmpi(voter_id, "18ce021") == 0)
		{
			voter_name = "YASH DESAI";
			city = "NAVSARI";
			age = 18;
			voting_center = "CHAPPRA ROAD";
			e++;
			if (e > 1)
			{
				cout << "MULTIPLE TIMES VOTING NOT ALLOWED";
			}
		}
		else
		{
			cout << "Enter Valid Voter ID";
		}
	}
	void show_voter_details()
	{
		cout << endl << "VOTER NAME:" << voter_name;
		cout << endl << "AGE:" << age;
		cout << endl << "CITY:" << city;
		cout << endl << "VOTING CENTER:" << voting_center << endl;
	}
};
class Voting : public Vote, public Party
{
	int v;
public:
	int bjp = 0, inc = 0, aap = 0;
	void give_vote()
	{
		cout << endl << "ENTER YOUR CHOICE FOR VOTE:";
		cin >> v;
		if (v == 1)
		{
			bjp++;
			cout << "VOTE REGISTERED";
			Sleep(3000);
		}
		else if (v == 2)
		{
			inc++;
			cout << "VOTE REGISTERED";
			Sleep(3000);
		}
		else if (v == 3)
		{
			aap++;
			cout << "VOTE REGISTERED";
			Sleep(3000);
		}
		else
		{
			cout << endl << "PLEASE ENTER VALID COICE" << endl;
		}
	}
	void cnt_vote()
	{
		cout << endl << "BJP=" << bjp;
		cout << endl << "INC=" << inc;
		cout << endl << "AAP=" << aap;
	}
};
int Vote::a;
int Vote::b;
int Vote::c;
int Vote::d;
int Vote::e;
int Vote::f;

int main()
{
	int a, b = 0;
	Vote v;
	Voting s;
	do
	{
		cout << "WELCOME" << endl;
		cout << "Press 1 to Vote" << endl;
		cout << "Press 2 if Voting is Completed" << endl;
		cin >> a;
		Sleep(1000);
		switch (a)
		{
		case 1: v.get_voter_details();
			v.show_voter_details();
			s.show_party_name();
			s.give_vote();
			break;
		case 2: s.cnt_vote();
			exit(0);
		default: cout << "Press valid number" << endl;
		}
		system("CLS");
		cout << endl << "Press 1 for going back to menu" << endl;
		cout << "Press 2 to exit" << endl;
		cin >> b;
		system("CLS");
	} while (b != 2);
	if (b == 2)
		s.cnt_vote();
}