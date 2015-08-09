#include "Includes.h"
#include "Console.h"
using namespace std;

Console C;
Menu M;

void Password_Genorator(){
	int Lines, Coloumns, Length = 10, Number = 10;
	C.GCS(Lines, Coloumns);
	string Action = "";
	while (Action != "Back"){
		Action = M.STR_Menu_From_File("Password Genorator.txt");
		if (Action == "Set Password Length"){
			C.C("Enter Password Length");
			C.C("(Recomended 7-15)");
			C.C("=============================");
			for (int a = 4; a < Lines; a++){
				cout << endl;
			}
			cin >> Length;
		}
		if (Action == "Set Number Of Passwords To Genorate"){
			C.C("Enter Number Of Password To Genorate");
			C.C("=============================");
			for (int a = 4; a < Lines; a++){
				cout << endl;
			}
			cin >> Number;
		}
		if (Action == "Genorate Passwords"){
			string tital = "Press Enter To Contiune";
			vector<string> Passwords;
			for (int a = 0; a < Number; a++){
				string Password;
				char Charictar_Char;
				int Charictar_Int;
				for (int b = 0; b < Length; b++){
					Charictar_Int = (rand() % 93) + 33;
					Charictar_Char = Charictar_Int;
					Password += Charictar_Char;
				}
				Passwords.push_back(Password);
			}
			M.STR_Menu(tital, Passwords);
		}
	}

}

int main()
{
	string Action = "";
	while (Action != "Quit"){
		Action = M.STR_Menu_From_File("Main Menu.txt");
		if (Action == "Password Genorator"){
			Password_Genorator();
		}
	}
}