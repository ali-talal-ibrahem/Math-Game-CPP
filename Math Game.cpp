/*
-----------------------------------------------------------
-------------------      Math Game   	-------------------
-----------------------------------------------------------
-|	Welcome to my Second simple program :)
-|	This is my Second time developing software, and the application was based
-|	on the following idea from Dr. Mohammed Abu Hadhoud Roadmap course .

-|	PROBLEM : WRITE A SMALL GAME PROGRAM FOR MATH GAME

-|	Requirements:
-|		1) We ask the user to enter the number of questions they wish to answer in this Quizz.
-|		2) We ask the user to enter the difficulty level of the questions they want to answer in this Quizz.
-|			The Levels are [ Easy, Medium, Hard, Mix ]
-|		3) We ask the user to enter the type of calculations in the quizz.
-|			The Types of Operations it can choose from are [ Addition, Subtraction, Multiplication, Division, Mix ]
-|		4) After each question, we print whether the answer was correct or not, correcting any incorrect answers for the user,
-|			and finally, we print the complete quizz results.

-----------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	// Function to generate a random number 

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enum enQuestionLevel
{
	Easy = 1,
	Med = 2,
	Hard = 3,
	MixLevel = 4
};

enum enOperationType
{
	Add = 1,
	Sub = 2,
	Mul = 3,
	Div = 4,
	MixOperationType = 5
};

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType;
	enQuestionLevel QuestionLevel;
	int PlayerAnswer = 0;
	int CorrectAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestion;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool isPass = false;
};

short ReadHowManyQuestions() {
	short NumberOfQuestions = 0;
	do {
		cout << "How Many Questions do you want to answer ? ( 1 -> 10 ) : ";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions <= 0 || NumberOfQuestions > 10);
	return NumberOfQuestions;
}

short ReadQuestionAnswer() {
	short Answer = 0;
	cin >> Answer;
	return Answer;
}

enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel = 0;

	do
	{

		cout << "Please Enter Question Level | [1] Easy, [2] Med, [3] Hard, [4] Mix | : ";
		cin >> QuestionLevel;

	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return (enQuestionLevel)QuestionLevel;

}

enOperationType ReadOperationType()
{
	short ReadOperationType = 0;

	do
	{

		cout << "Please Enter Operation Type | [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix | : ";
		cin >> ReadOperationType;

	} while (ReadOperationType < 1 || ReadOperationType > 5);

	return (enOperationType)ReadOperationType;

}

string GetOperationType(enOperationType OperationType)
{
	string arrOperationTypeText[5] = { "+","-","*","/","Mix Opretion" };
	return arrOperationTypeText[OperationType - 1];
}

string getQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = { "Easy","Med","Hard","Mix Level" };
	return arrQuestionLevelText[QuestionLevel - 1];
}

enOperationType GetRandomOperationType()
{
	int OperationType = RandomNumber(1, 4);
	return (enOperationType)OperationType;
}

int SimpleCalculator(int Number1, int Number2, enOperationType OperationType)
{

	switch (OperationType) {

	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Mul:
		return Number1 * Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;

	}

}

stQuestion GenerateQuestions(enQuestionLevel QuestionLevel, enOperationType OperationType)
{

	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::MixLevel)
	{
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
	}

	if (OperationType == enOperationType::MixOperationType)
	{
		OperationType = GetRandomOperationType();
	}


	Question.OperationType = OperationType;

	switch (QuestionLevel)
	{

	case enQuestionLevel::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::Med:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	}

}

void GenerateQuizzQuestions(stQuizz& Quizz)
{

	for (short Question = 0; Question < Quizz.NumberOfQuestion; Question++)
	{
		Quizz.QuestionList[Question] = GenerateQuestions(Quizz.QuestionLevel, Quizz.OperationType);
	}

}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{

	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestion << "]" << "\n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1
		<< " " << GetOperationType(Quizz.QuestionList[QuestionNumber].OperationType)
		<< " " << Quizz.QuestionList[QuestionNumber].Number2
		<< " = ";

}

void setScreenColor(bool AnswerResult) {

	if (AnswerResult) {
		system("color 2F");
	}
	else {
		system("color 4F");
	}

}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber) {

	int CorrectAnswer = Quizz.QuestionList[QuestionNumber].CorrectAnswer;
	int PlayerAnswer = Quizz.QuestionList[QuestionNumber].PlayerAnswer;

	if (PlayerAnswer != CorrectAnswer) {
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :(" << endl;
		cout << "The Right Answer is : " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl;
	}
	else {
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;

		cout << "Right Answer :)" << endl;

	}
	cout << endl;
	setScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);

}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz) {

	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++) {
		PrintTheQuestion(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}

	Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);

}

string getQuizzResultText(bool Pass) {

	if (Pass) {
		return "PASS :)";
	}
	else {
		return "FALSE :(";
	}

}

void PrintQuizzResult(stQuizz Quizz) {

	cout << "--------------------------\n";
	cout << "\nGame Result :\n";
	cout << "Number Of Questions : " << Quizz.NumberOfQuestion << endl;
	cout << "Quizz Level : " << getQuestionLevelText(Quizz.QuestionLevel) << endl;
	cout << "Operation Type Of Quizz : " << GetOperationType(Quizz.OperationType) << endl;
	cout << "Right Answer : " << Quizz.NumberOfRightAnswers << endl;
	cout << "Wrong Answer : " << Quizz.NumberOfWrongAnswers << endl;
	cout << "Final Quizz : " << getQuizzResultText(Quizz.isPass) << endl;
	setScreenColor(Quizz.isPass);
	cout << "\n--------------------------\n\n";

}

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestion = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OperationType = ReadOperationType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResult(Quizz);

}

void ReseteScreen() {
	system("cls");
	system("color 0F");
};

void StartGame() {

	char PlayAgain = 'Y';

	do {
		ReseteScreen();
		PlayMathGame();
		cout << "You Need Play Again Y/N : ";
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');


};

int main() {

	srand((unsigned)time(NULL)); // IMPORTANT
	StartGame();

}


/*

Thank you all

This was my second project in two weeks of work

It will be further developed in the coming days to become more operationally extensive.


Ali Talal Ibrahem
Today's date: 9/12/2025

*/