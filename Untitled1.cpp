#include<iostream>
#include<vector>
#include<string>
#include <fstream>
//#include <algorithm>
//#include <time.h>
using namespace std;

int exit_prog();
//variable to store the index of the player to access his data from any array
int index_of_player;
//var to know what is ID of the next QS during loading
int ID;
//variable to know if there is QS loaded or not
bool loaded = false;
//array used during generating random choices
int visited_choices[4];
//this is a struct to store all information of the user
struct full_user_information
{
	string un, password, fname, Lname, role;
};
//this struct is a struct to store the username and password of the user to compare it with the stored one
struct check_struct
{
	string username, pass;
};
class USER
{
protected:
	full_user_information ui;
public:
	USER() {
		ui.fname = "user";
		ui.Lname = "user";
	}
	virtual void main_menu() {}

	void struct_assigning(full_user_information x)
	{
		ui.fname = x.fname;
		ui.Lname = x.Lname;
		ui.un = x.un;
		ui.password = x.password;
		ui.role = x.role;
	}

	bool checking_exist(check_struct i)
	{
		return(i.username == ui.un && i.pass == ui.password);
	}
	bool checking_exist(string str)
	{
		return(str == ui.un);
	}
	string role_check()
	{
		return ui.role;
	}
	void Update_firstname_lastname()
	{
		cout << "Enter your First name ";
		cin >> ui.fname;
		cout << "Enter your Last name  ";
		cin >> ui.Lname;
	}
	void print_info() {
		cout << ui.fname << "  " << ui.Lname << "  " << ui.un << "  " << ui.role << endl;
	}
};
void admin_main_menu(int no_of_user, vector<USER*>& user_information);
//void player_main_menu(int no_of_user, vector<USER*>& user_information);
class ADMIN : public USER
{
public:
	void main_menu()
	{
		cout << "Welcome" << " " << ui.fname << " " << ui.Lname << " " << "(" << ui.role << ")" << ", please choose from the following options: " << endl;
		cout << "[1] Switch accounts." << endl;
		cout << "[2] Update your name." << endl;
		cout << "[3] View all users." << endl;
		cout << "[4] Add new user." << endl;
		cout << "[5] View all questions." << endl;
		cout << "[6] Add new question." << endl;
		cout << "[7] Load questions from file." << endl;
		cout << "[8] Exit the program." << endl;
		cout << "My choice :";
	}
};

//this struct takes the username & password to assign it to the calss struct and compare with it
check_struct assigning_username_password()
{
	check_struct x;
	cout << "Please enter your username: ";
	cin >> x.username;
	cout << "Please enter your password: ";
	cin >> x.pass;
	return x;
}
/*
this function checks that the account is exist in our vector or not.
takes the struct and vector as parameters.
uses the boolean checking exist function that return the value of checking if the username and password is exist or not.
returns the value of existing.
*/
int check_account(check_struct user_and_pass, vector<USER*>user_information)
{
	bool find = false;
	int count = 0;
	for (auto i = user_information.begin(); i != user_information.end(); i++)
	{

		if ((*i)->checking_exist(user_and_pass))
		{
			find = true;
			break;
		}
		count++;
	}
	if (find == true)
		return count;
	else
		return -1;
}
/*
this function takes the vector of objects and the struct that was used to compare with as paramiters
this function takes the first name,
last name,
username,
and the password of the user to store it and make a account for him
*/
void Default_admin_player(vector<USER*>& user_information)
{
	USER* admin = new ADMIN;
	//USER* player = new PLAYER;
	full_user_information u_information;
	u_information.fname = "user";
	u_information.Lname = "user";
	u_information.un = "admin";
	u_information.role = "admin";
	u_information.password = "admin";
	admin->struct_assigning(u_information);
	user_information.push_back(admin);
	u_information.fname = "user";
	u_information.Lname = "user";
	u_information.un = "player";
	u_information.role = "player";
	u_information.password = "player";
	//player->struct_assigning(u_information);
	//user_information.push_back(player);
}
int ADD_USER(vector<USER*>& user_information, check_struct user_and_pass = { "notempty","notempty" })
{
	full_user_information user_inform;
	cout << "Please enter your signing information: " << endl;
	cout << "Enter your First name: ";
	cin >> user_inform.fname;
	cout << "Enter your Last name: ";
	cin >> user_inform.Lname;
	cout << "Enter your Username: ";
	cin >> user_inform.un;
	while (true)
	{
		for (auto i = user_information.begin(); i != user_information.end(); i++)
		{
			if ((*i)->checking_exist(user_inform.un))
			{
				cout << "This username already taken, please enter another username : " << endl;
				cin >> user_inform.un;
				break;
			}
		}
		break;
	}
	cout << "Enter your Password: ";
	cin >> user_inform.password;

	USER* base;
	/*if (user_and_pass.username == "admin" && user_and_pass.pass == "admin")
	{
		user_inform.role = "admin";
		base = new ADMIN;
		base->struct_assigning(user_inform);
		user_information.push_back(base);
	}*/


		cout << "Enter the role (admin or player) : ";
		cin >> user_inform.role;
		while (true)
		{
			if (user_inform.role == "admin")
			{
				base = new ADMIN;
				break;
			}
			cout << "Invalid input, please enter a valid role (admin or player) : ";
			cin >> user_inform.role;
		}
		base->struct_assigning(user_inform);
		user_information.push_back(base);

	return user_information.size() - 1;
}
int logining(check_struct user_and_pass, vector<USER*>& user_information)
{


	int counter;
	while (true)
	{
		counter = check_account(user_and_pass, user_information);
		if (counter == -1)
		{
			cout << "Username or Password isn't correct, please enter your username and password again." << endl;
			cout << "Enter your username :" << endl;
			cin >> user_and_pass.username;
			cout << "Enter your password :" << endl;
			cin >> user_and_pass.pass;
		}
		else
			break;
	}
	return counter;

}

void run_program(vector<USER*>& user_information); //declaration

//fun to convert int to string
int str_To_Int(string s)
{
	int num = 0, digit = s.length(), multiplier = 1, temp;
	for (int i = 1; i < digit; i++) { multiplier *= 10; }
	for (int i = 0; i < s.length(); i++)
	{
		switch (int(s[i]))
		{
		case((int)'0'):
		{
			temp = 0;
			break;
		}
		case((int)'1'):
		{
			temp = 1;
			break;
		}
		case((int)'2'):
		{
			temp = 2;
			break;
		}
		case((int)'3'):
		{
			temp = 3;
			break;
		}
		case((int)'4'):
		{
			temp = 4;
			break;
		}
		case((int)'5'):
		{
			temp = 5;
			break;
		}
		case((int)'6'):
		{
			temp = 6;
			break;
		}
		case((int)'7'):
		{
			temp = 7;
			break;
		}
		case((int)'8'):
		{
			temp = 8;
			break;
		}
		case((int)'9'):
		{
			temp = 9;
			break;
		}
		}
		temp *= multiplier;
		num += temp;
		multiplier /= 10;
	}
	return num;
}
class question
{
public:
	virtual void readQuestionFromFile(string arr[6]) {}
	virtual void print_with_ans() {}
	virtual void store_details_of_qs(string arr[8]) {}
	virtual void printing_for_last_two() {}
};
class mcq : public question
{
	string qs;
	string right_ans;
	string answers[4];
	string player_ans;
public:
	mcq() {}
	mcq(string arr[6])
	{
		qs = arr[0];
		right_ans = arr[1];
		answers[0] = arr[1];
		answers[1] = arr[3];
		answers[2] = arr[4];
		answers[3] = arr[5];
	}
	void readQuestionFromFile(string arr[6])
	{
		qs = arr[0];
		right_ans = arr[1];
		answers[0] = arr[1];
		answers[1] = arr[2];
		answers[2] = arr[3];
		answers[3] = arr[4];
	}
	bool operator==(mcq added)
	{
		return qs == added.qs && right_ans == added.right_ans;
	}
	void set_visited_choices_def()
	{
		visited_choices[0] = 132456;
		visited_choices[1] = 132456;
		visited_choices[2] = 123456;
		visited_choices[3] = 123456;
	}
	bool if_visited_choices(int target)
	{
		for (int i = 0; i < 4; i++)
		{
			if (visited_choices[i] == target)
				return true;
		}
		return false;
	}
	int random(int limit, int ind)
	{
		//rand()%((max+1)-min+1)+min			rand_equ
		int target;
		target = rand() % limit;
		while (if_visited_choices(target))
		{
			target = rand() % limit;
		}
		visited_choices[ind] = target;
		return target;
	}
	void print_with_ans()
	{
		cout << qs << endl;
		set_visited_choices_def();
		for (int r = 0; r < 4; r++)
		{
			int rand = random(4, r);
			char c = 97 + r;
			if (answers[rand] == right_ans)
				cout << "     " << "*[" << c << "] " << answers[rand];
			else
				cout << "     " << "[" << c << "] " << answers[rand];
		}
		cout << endl << endl;

	}


};
//array to store mcq QS
mcq mcq_qs[1000];
//var to know how many mcq we have
int num_mcq_qs = 0;
//array to store the id of every QS
int mcq_ids[1000];
//fun to know if the structure of mcq qs valid or not
bool valid_mcq(string arr[6], int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			if ((arr[i] != "MCQ" )) {}
			else
				return false;
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			if ((arr[i] != "MCQ" && arr[i] != "COMPELETE" && arr[i] != "TF" && arr[i] != "") && (arr[5] == "COMPLETE" || arr[5] == "MCQ" || arr[5] == "TF")) {}
			else
				return false;
		}
	}
	return true;
}

//fun to know how many line in file
int num_lines_of_file()
{
	fstream file;
	file.open("exam2_questions.txt", ios::in);
	string s;
	int cnt = 0;
	while (!file.eof())
	{
		getline(file, s);
		cnt++;
	}
	file.close();
	return cnt;
}
bool if_file_found(string name)
{
	fstream file;
	file.open(name, ios::in);
	int i = 0;
	bool cond = false;
	while (!file.eof() && i <= 30)
	{
		string s;
		getline(file, s);
		i++;
		if (!cond && s != "\0")
			cond = true;
	}
	return cond;
}
void loading()
{
	string str;
	cin.ignore();
	cout << "Please add \".txt\" at the end of the file name" << endl << "The file name: ";
	getline(cin, str);
	while (!if_file_found(str))
	{
		cout << "This file is not found, Please enter a valid name of file" << endl << "The file name: ";
		getline(cin, str);
	}
	loaded = true;
	fstream file;
	file.open(str, ios::in);
	int cnt = 0;
	bool m = false;
	string arr[6];
	int lines = 0;
	while (!file.eof())
	{
		string s;
		getline(file, s);
		lines++;
		if (m)
		{
			arr[cnt] = s;
			cnt++;
			if (cnt == 6 || (cnt == 5 && lines == num_lines_of_file()))
			{
				m = false;
				if (!valid_mcq(arr, cnt))
				{
					cout << "The structure of a question is wrong, the process of loading has stopped." << endl;
					break;
				}
				else
				{
					mcq added(arr);
					bool flag = false;
					for (int r = 0; r < num_mcq_qs; r++)
					{
						if (added == mcq_qs[r])
						{
							flag = true;
							break;
						}
					}
					if (!flag)
					{
						question* ptr;
						ptr = &mcq_qs[num_mcq_qs];
						ptr->readQuestionFromFile(arr);
						mcq_ids[num_mcq_qs] = ++ID;
						num_mcq_qs++;
					}
				}
				cnt = 0;
			}
		}
		if (s == "MCQ")
			m = true;
	}
}
bool check_int(string ele) {
	for (int i = 0; i < ele.length(); i++) {
		if ((int)ele[i]<(int)'1' || (int)ele[i] > (int)'9')
			return false;
	}
	return true;
}
void view_all_qs(int no_of_user, vector<USER*>& user_information)
{
	cout << "Number of questions available: " << num_mcq_qs<< endl << endl;
	cout << "---------------------------------------------------" << endl << endl;
	cout << "MC Questions list (Total: " << num_mcq_qs << " Questions)" << endl << endl;
	cout << "---------------------------------------------------" << endl << endl;
	for (int i = 0; i < num_mcq_qs; i++)
	{
		cout << '[' << i + 1 << "] (ID: " << mcq_ids[i] << ") ";
		mcq_qs[i].print_with_ans();
	}
	cout << endl << "----------------------------------------------------" << endl << endl;
	cout << "Press [d] and the question ID if you want to delete a question (Example: d 2)" << endl;
	cout << "Press [b] if you want to go back to the main menu " << endl << endl;
	char charac;
	string num;
	cout << "Your choice: ";
	cin >> charac;
	while ((charac != 'b' && charac != 'd'))
	{
		cin >> charac;
	}
	if (charac == 'b')
		admin_main_menu(no_of_user, user_information);
	else
	{
		cin >> num;
		while (!check_int(num))
		{
			cout << "Please enter a valid ID of question: ";
			cin >> num;
		}
		bool flag = false;
		while (!flag)
		{
			int n = str_To_Int(num);
			for (int i = 0; i < num_mcq_qs; i++)
			{
				if (n == mcq_ids[i])
				{
					swap(mcq_ids[i], mcq_ids[num_mcq_qs - 1]);
					swap(mcq_qs[i], mcq_qs[num_mcq_qs - 1]);
					num_mcq_qs--;
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				cout << "There is no question found with that ID, please enter a valid ID." << endl;
				cout << "ID: ";
				cin >> num;
			}
		}
		view_all_qs(no_of_user, user_information);
	}
}
void add_new_qs(int no_of_user, vector<USER*>& user_information)
{
	string cont = "yes";
	while (cont == "yes" || cont == "YES" || cont == "YES")
	{
		char choice;
			cin.ignore();
			string arr[6];
			cout << "Please enter the question: ";
			getline(cin, arr[0]);
			while (arr[0] == "")
			{
				cout << "Please enter a valid question: ";
				getline(cin, arr[0]);
			}
			cout << "Please enter 4 choices which include the right choice as a first choice" << endl;
			cout << "first choice: ";
			getline(cin, arr[1]);
			while (arr[1] == "")
			{
				cout << "Please enter a valid choice: ";
				getline(cin, arr[1]);
			}
			cout << "second choice: ";
			getline(cin, arr[2]);
			while (arr[2] == "")
			{
				cout << "Please enter a valid choice: ";
				getline(cin, arr[2]);
			}
			cout << "third choice: ";
			getline(cin, arr[3]);
			while (arr[3] == "")
			{
				cout << "Please enter a valid choice: ";
				getline(cin, arr[3]);
			}
			cout << "fourth choice: ";
			getline(cin, arr[4]);
			while (arr[4] == "")
			{
				cout << "Please enter a valid choice: ";
				getline(cin, arr[4]);
			}
			mcq added(arr);
			bool flag = false;
			for (int r = 0; r < num_mcq_qs; r++)
			{
				if (added == mcq_qs[r])
				{
					flag = true;
					cout << "Sorry, This question has already been added";
					break;
				}
			}
			if (!flag)
			{
				question* ptr;
				ptr = &mcq_qs[num_mcq_qs];
				ptr->readQuestionFromFile(arr);
				mcq_ids[num_mcq_qs] = ++ID;
				num_mcq_qs++;
				cout << "The question has been added" << endl;
			}

		cout << "Do you want to add another question? " << endl;
		cout << "My answer: ";
		cin >> cont;
		while (cont != "YES" && cont != "Yes" && cont != "yes" && cont != "NO" && cont != "no")
		{
			cout << "Please enter a valid choice: ";
			cin >> cont;
		}
	}
	cout << "Press [b] if you want to go back to the main menu or [e] to exit" << endl;
	char choice;
	cout << "My choice: ";
	cin >> choice;
	while (choice != 'e' && choice != 'b')
	{
		cout << "Please enter a valid choice: ";
		cin >> choice;
	}
	if (choice == 'b')
		admin_main_menu(no_of_user, user_information);
	else
		exit_prog();
}

int exit_prog()
{
	return 0;
}
//array to store details of every quiz for every player
//details for_all_players[1000];
//dun to display stats of every player in previous quizzes

void admin_main_menu(int no_of_user, vector<USER*>& user_information)
{

	char choice;
	user_information[no_of_user]->main_menu();
	cin >> choice;
	while ((int)choice<(int)'1' || (int)choice>(int)'8')
	{
		cout << "Please enter a valid choice:";
		cin >> choice;
	}
	if (choice == '1') {
		run_program(user_information);
	}
	else if (choice == '2') {
		user_information[no_of_user]->Update_firstname_lastname();
		admin_main_menu(no_of_user, user_information);
	}
	else if (choice == '3') {
		for (auto i = user_information.begin(); i != user_information.end(); i++)
		{
			(*i)->print_info();
		}
		admin_main_menu(no_of_user, user_information);
	}
	else if (choice == '4') {
		ADD_USER(user_information);
		admin_main_menu(no_of_user, user_information);
	}
	else if (choice == '5')
		view_all_qs(no_of_user, user_information);
	else if (choice == '6')
		add_new_qs(no_of_user, user_information);
	else if (choice == '7') {
		loading();
		admin_main_menu(no_of_user, user_information);
	}
	else if (choice == '8') {
		exit_prog();
	}

}

void run_program(vector<USER*>& user_information)
{
	int user_index;
	check_struct ass_struct;
	ass_struct = assigning_username_password();
	user_index = logining(ass_struct, user_information);
	if (user_information[user_index]->role_check() == "admin")
	{
		admin_main_menu(user_index, user_information);
	}
}
int main()
{
	//srand(time(0));
	vector<USER*>user_information;
	cout << "*************************" << endl;
	cout << "\t\tWelcome to the Quiz game program V2.0! " << endl;
	cout << "*************************" << endl;
	Default_admin_player(user_information);
	run_program(user_information);
	return 0;
}
