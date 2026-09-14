#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum en_Level { Easy = 1, Middle = 2, Hard = 3, Mix = 4 };
enum en_Operation_Type { Add = 1, Subtract = 2, Multiplication = 3, Division = 4, Mix_ot = 5 };

struct st_Question
{
	short question_number, number1, number2, rigth_answer, user_answer;
	en_Operation_Type type;
};

struct st_Quizz
{
	st_Question questions_list[10];
	short number_of_questions, right_answers_times = 0, wrong_answers_times = 0;
	en_Level level;
	en_Operation_Type type;
	bool is_pass;
};

short Random_Number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}

short Number_Of_Questions()
{
	short n;

	do
	{
		cout << " Enter the number of questions(1-10): ";
		cin >> n;
	} while (n < 1 || n > 10);

	return n;
}

en_Level Quizz_Level()
{
	short l;

	do
	{
		cout << " Select the level of quizz(Easy[1], Middel[2], Hard[3], Mix[4]): ";
		cin >> l;
	} while (l < 1 || l > 4);

	return en_Level(l);
}

en_Operation_Type Questions_Type()
{
	short t;

	do
	{
		cout << " Select the type of question(Add[1], Subtract[2], Multiplication[3], Division[4], Mix[5]): ";
		cin >> t;
	} while (t < 1 || t > 5);

	return en_Operation_Type(t);
}

short Calculator(short num1, short num2, en_Operation_Type type)
{
	switch (type)
	{
	case en_Operation_Type::Add:
		return num1 + num2;
	case en_Operation_Type::Subtract:
		return num1 - num2;
	case en_Operation_Type::Multiplication:
		return num1 * num2;
	case en_Operation_Type::Division:
		return num1 / num2;
	}
}

st_Question Questions(en_Level level, en_Operation_Type type, short i)
{
	st_Question Question;

	if (level == en_Level::Mix)
		level = en_Level(Random_Number(1, 3));

	if (type == en_Operation_Type::Mix_ot)
		type = en_Operation_Type(Random_Number(1, 4));

	Question.type = type;

	switch (level)
	{
	case en_Level::Easy:
		Question.question_number = i;
		Question.number1 = Random_Number(1, 10);
		Question.number2 = Random_Number(1, 10);
		Question.rigth_answer = Calculator(Question.number1, Question.number2, type);
		break;

	case en_Level::Middle:
		Question.question_number = i;
		Question.number1 = Random_Number(11, 50);
		Question.number2 = Random_Number(11, 50);
		Question.rigth_answer = Calculator(Question.number1, Question.number2, type);
		break;

	case en_Level::Hard:
		Question.question_number = i;
		Question.number1 = Random_Number(51, 100);
		Question.number2 = Random_Number(51, 100);
		Question.rigth_answer = Calculator(Question.number1, Question.number2, type);
		break;
	}
	return Question;
}

void Generate_Questions(st_Quizz& Quizz)
{
	for (int i = 0; i < Quizz.number_of_questions; i++)
	{
		Quizz.questions_list[i] = Questions(Quizz.level, Quizz.type, i);
	}
}

char Print_Character(en_Operation_Type type)
{
	switch (type)
	{
	case en_Operation_Type::Add:
		return '+';
		break;
	case en_Operation_Type::Subtract:
		return '-';
		break;
	case en_Operation_Type::Multiplication:
		return '*';
		break;
	case en_Operation_Type::Division:
		return '/';
	}
}

void Print_Question(st_Quizz& Quizz, short i)
{
	cout << "\n" << " Question[" << i + 1 << '/' << Quizz.number_of_questions << ']' << endl;
	cout << "\n " << Quizz.questions_list[i].number1;
	cout << "\n " << Quizz.questions_list[i].number2;
	cout << " " << Print_Character(Quizz.questions_list[i].type);
	cout << "\n ----\n ";
}

short Read_Answer()
{
	short n;
	cin >> n;
	return n;
}

void Correct_Answer(st_Quizz& Quizz, short i)
{
	if (Quizz.questions_list[i].rigth_answer == Quizz.questions_list[i].user_answer)
	{
		system("color 2F");
		cout << "\n #Right answer (-:";
		cout << "\n---------------------------\n";
		Quizz.right_answers_times++;
	}
	else
	{
		system("color 4F");
        cout << '\a';
		cout << "\n #Wrong answer )-:" << "\n *The right answer = " << Quizz.questions_list[i].rigth_answer;
		cout << "\n---------------------------\n";
		Quizz.wrong_answers_times++;
	}
}

void Ask_And_Correct(st_Quizz& Quizz)
{
	for (int i = 0; i < Quizz.number_of_questions; i++)
	{
		Print_Question(Quizz, i);
		Quizz.questions_list[i].user_answer = Read_Answer();
		Correct_Answer(Quizz, i);
	}

    Quizz.is_pass = (Quizz.right_answers_times >= Quizz.wrong_answers_times);
}

string Get_Result_Name(bool is_pass)
{
    if (is_pass)
        return "'PASS'";
    else
        return "'FAIL'";
}

string Get_Level_Name(en_Level level)
{
	string level_name[4] = { "Easy", "Middle", "Hard", "Mix" };
	return level_name[level - 1];
}

string Get_Type_Name(en_Operation_Type type)
{
	string type_name[5] = { "Add", "Subtract", "Multiplication", "Division", "Mix" };
	return type_name[type - 1];
}

string Tabs(short n)
{
	return string(n, '\t');
}

void Print_Final_Result(st_Quizz Quizz)
{
	cout << "\n\n\n" << Tabs(3) << "---------------------------------------------------\n";
	cout << Tabs(5) << "Your Result is " << Get_Result_Name(Quizz.is_pass);
	cout << '\n' << Tabs(3) << "---------------------------------------------------";
	cout << '\n' << Tabs(3) << "Number Of Questions: " << Quizz.number_of_questions;
	cout << '\n' << Tabs(3) << "Quizz Level: " << Get_Level_Name(Quizz.level);
	cout << '\n' << Tabs(3) << "Questions Type: " << Get_Type_Name(Quizz.type);
	cout << '\n' << Tabs(3) << "Right answer times: " << Quizz.right_answers_times;
	cout << '\n' << Tabs(3) << "Wrong answer times: " << Quizz.wrong_answers_times;
	cout << '\n' << Tabs(3) << "---------------------------------------------------\n";

	if (Quizz.is_pass)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << '\a';
	}
}

st_Quizz Play_Quizz()
{
	st_Quizz Quizz;

	Quizz.number_of_questions = Number_Of_Questions();
	Quizz.level = Quizz_Level();
	Quizz.type = Questions_Type();

	Generate_Questions(Quizz);
	Ask_And_Correct(Quizz);
	Print_Final_Result(Quizz);

	return Quizz;
}

void Start_Quizz()
{
	char more;

	do
	{
		system("cls");
		system("color 0F");

		cout << Tabs(6) << " Start Quizz\n";
		cout << Tabs(6) << "-------------\n\n";

		Play_Quizz();

		cout << "\n Do you want to start quizz again(y/n): ";
		cin >> more;
	} while (more == 'Y' || more == 'y');

	cout << "\n\n" << Tabs(6) << " Finish\n";
	cout << Tabs(6) << "--------" << endl << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	Start_Quizz();

	return 0;
}