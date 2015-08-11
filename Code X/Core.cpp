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
void Encrypt(){
	int Lines, Coloumns;
	C.GCS(Lines, Coloumns);
	string Action = "";
	bool File = false;
	string To_Encrypt_String, Encrypted_String, File_Location, Password = "password";
	int Encryption_Level = 4, Current_Value = 0;
	vector<int> Processess;
	vector<int>Values;
	while (Action != "Back"){
		Action = M.STR_Menu_From_File("Encrypter.txt");
		if (Action == "Enter String"){
			C.C("Enter String");
			C.C("=============================");
			for (int a = 3; a < Lines; a++){
				cout << endl;
			}
			To_Encrypt_String = C.GS();
		}
		if (Action == "Enter File"){
			C.C("Enter File");
			C.C("=============================");
			for (int a = 3; a < Lines; a++){
				cout << endl;
			}
			cin >> File_Location;
			File = true;
		}
		if (Action == "Enter Password"){
			C.C("Enter Password");
			C.C("=============================");
			for (int a = 3; a < Lines; a++){
				cout << endl;
			}
			cin >> Password;
		}
		if (Action == "Enter Encryption Level"){
			C.C("Enter Encryption Level");
			C.C("=============================");
			for (int a = 3; a < Lines; a++){
				cout << endl;
			}
			cin >> Encryption_Level;
		}
		if (Action == "Encrypt"){
			int password = 0;
			for (int a = 0; a < Password.size(); a++){
				password = password + int(Password[a]);
			}
			srand(password);
			Encrypted_String = To_Encrypt_String;
			C.C(Encrypted_String);
			for (int a = 0; a < Encryption_Level; a++){
				int Temp = rand() % 3;
				Processess.push_back(Temp);

			}
			for (int a = 0; a < Encryption_Level; a++){
				if (Processess[a] != 0){
					for (int b = 0; b < To_Encrypt_String.size(); b++){
						int Temp = rand() % 100;
						Values.push_back(Temp);
					}
				}
			}
			for (int a = 0; a < Encryption_Level; a++){
				int Format;
				Format = Processess[a];
				if (Format == 0){
					//Flip Alphabet;
					for (int b = 0; b < Encrypted_String.size(); b++){
						int Temp_Char = int(Encrypted_String[b]);
						Temp_Char = Temp_Char - 79;
						Temp_Char = Temp_Char * -1;
						Temp_Char = Temp_Char + 79;
						Encrypted_String[b] = char(Temp_Char);
					}
				}
				if (Format == 1){
					//Add to Chaictar Values
					for (int b = Encrypted_String.size() - 1; b > -1; b--){
						int Add, Temp_Char;
						Add = (rand() % 100);
						Temp_Char = int(Encrypted_String[b]);
						Temp_Char = Temp_Char + Values[Current_Value];
						Current_Value++;
						while (Temp_Char > 126){
							Temp_Char = Temp_Char - 94;
						}
						Encrypted_String[b] = char(Temp_Char);
					}
				}
				if (Format == 2){
					//Sub from Charictar Values
					for (int b = Encrypted_String.size() - 1; b > -1; b--){
						int Sub, Temp_Char;
						Sub = (rand() % 100);
						Temp_Char = int(Encrypted_String[b]);
						Temp_Char = Temp_Char - Values[Current_Value];
						Current_Value++;
						while (Temp_Char < 32){
							Temp_Char = Temp_Char + 94;
						}
						Encrypted_String[b] = char(Temp_Char);
					}
				}
				C.C(Encrypted_String);
			}
		}
	}
}
void Decrypt(){
	int Lines, Coloumns;
	C.GCS(Lines, Coloumns);
	string Action = "";
	bool File = false;
	string To_Decrypt_String, Decrypted_String, File_Location, Password = "password";
	int Encryption_Level = 4, Current_Value = 0;
	vector<int> Processess;
	vector<int>Values;
	while (Action != "Back"){
		Action = M.STR_Menu_From_File("Decrypter.txt");
		if (Action == "Enter String"){
			C.C("Enter String");
			C.C("=============================");
			for (int a = 3; a < Lines; a++){
				cout << endl;
			}
			To_Decrypt_String = C.GS();
		}
		if (Action == "Enter File"){
			C.C("Enter File");
			C.C("=============================");
			for (int a = 3; a < Lines; a++){
				cout << endl;
			}
			cin >> File_Location;
			File = true;
		}
		if (Action == "Enter Password"){
			C.C("Enter Password");
			C.C("=============================");
			for (int a = 3; a < Lines; a++){
				cout << endl;
			}
			cin >> Password;
		}
		if (Action == "Enter Decryption Level"){
			C.C("Enter Encryption Level");
			C.C("=============================");
			for (int a = 3; a < Lines; a++){
				cout << endl;
			}
			cin >> Encryption_Level;
		}
		if (Action == "Decrypt"){
			int password = 0;
			for (int a = 0; a < Password.size(); a++){
				password = password + int(Password[a]);
			}
			srand(password);
			Decrypted_String = To_Decrypt_String;
			C.C(Decrypted_String);
			for (int a = 0; a < Encryption_Level; a++){
				int Temp = rand() % 3;
				Processess.push_back(Temp);

			}
			for (int a = 0; a < Encryption_Level; a++){
				if (Processess[a] != 0){
					for (int b = 0; b < Decrypted_String.size(); b++){
						int Temp = rand() % 100;
						Values.push_back(Temp);
					}
				}
			}
			Current_Value = Values.size() - 1;
			for (int a = Encryption_Level - 1; a > -1; a--){
				int Format;
				Format = Processess[a];
				if (Format == 0){
					//Flip Alphabet;
					for (int b = 0; b < Decrypted_String.size(); b++){
						int Temp_Char = int(Decrypted_String[b]);
						Temp_Char = Temp_Char - 79;
						Temp_Char = Temp_Char * -1;
						Temp_Char = Temp_Char + 79;
						Decrypted_String[b] = char(Temp_Char);
					}
				}
				if (Format == 1){
					//Add to Chaictar Values
					for (int b = 0; b < Decrypted_String.size(); b++){
						int Add, Temp_Char;
						Add = (rand() % 100);
						Temp_Char = int(Decrypted_String[b]);
						Temp_Char = Temp_Char - Values[Current_Value];
						Current_Value--;
						while (Temp_Char < 32){
							Temp_Char = Temp_Char + 94;
						}
						Decrypted_String[b] = char(Temp_Char);
					}
					for (int b = 0; b < Decrypted_String.size(); b++){
						if (Decrypted_String[b] == '~'){
							Decrypted_String[b] = ' ';
						}
						else if (Decrypted_String[b] == ' '){
							Decrypted_String[b] = '~';
						}
					}
				}
				if (Format == 2){
					//Sub from Charictar Values
					for (int b = 0; b < Decrypted_String.size(); b++){
						int Sub, Temp_Char;
						Sub = (rand() % 100);
						Temp_Char = int(Decrypted_String[b]);
						Temp_Char = Temp_Char + Values[Current_Value];
						Current_Value--;
						while (Temp_Char > 126){
							Temp_Char = Temp_Char - 94;
						}
						Decrypted_String[b] = char(Temp_Char);
					}
					for (int b = 0; b < Decrypted_String.size(); b++){
						if (Decrypted_String[b] == '~'){
							Decrypted_String[b] = ' ';
						}
						else if (Decrypted_String[b] == ' '){
							Decrypted_String[b] = '~';
						}
					}
				}
				
				C.C(Decrypted_String);
			}
		}
	}
}

int main()
{
	string Action = "";
	M.Set_Colors("w", "bl", "w", "dg");
	while (Action != "Quit"){
		Action = M.STR_Menu_From_File("Main Menu.txt");
		if (Action == "Password Genorator"){
			Password_Genorator();
		}
		if (Action == "Encrypter"){
			Encrypt();
		}
		if (Action == "Decrypter"){
			Decrypt();
		}
	}
}