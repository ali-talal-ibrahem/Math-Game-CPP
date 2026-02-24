/*
-----------------------------------------------------------
-------------------      Math Game      -------------------
-----------------------------------------------------------
-|	Welcome to my Second simple program :)
-|	PROBLEM : WRITE A SMALL GAME PROGRAM FOR MATH GAME
-----------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//-----------------------------------------------------------
// Enums & Structs
//-----------------------------------------------------------

enum enQuestionLevel
{
    Easy = 1, Med = 2, Hard = 3, MixLevel = 4
};

enum enOperationType
{
    Add = 1, Sub = 2, Mul = 3, Div = 4, MixOperationType = 5
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

//-----------------------------------------------------------
// Helper Functions
//-----------------------------------------------------------

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

string GetOperationType(enOperationType OperationType)
{
    string arrOperationTypeText[5] = { "+", "-", "*", "/", "Mix Operation" };
    return arrOperationTypeText[OperationType - 1];
}

string getQuestionLevelText(enQuestionLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = { "Easy", "Med", "Hard", "Mix Level" };
    return arrQuestionLevelText[QuestionLevel - 1];
}

enOperationType GetRandomOperationType()
{
    return (enOperationType)RandomNumber(1, 4);
}

void setScreenColor(bool AnswerResult) 
{
    if (AnswerResult) 
        system("color 2F"); // Green
    else 
        system("color 4F"); // Red
}

void ReseteScreen() 
{
    system("cls");
    system("color 0F");
}

//-----------------------------------------------------------
// Input Functions
//-----------------------------------------------------------

short ReadHowManyQuestions() 
{
    short NumberOfQuestions = 0;
    do {
        cout << "How Many Questions do you want to answer? (1 -> 10): ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions <= 0 || NumberOfQuestions > 10);
    return NumberOfQuestions;
}

enQuestionLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;
    do {
        cout << "Please Enter Question Level | [1] Easy, [2] Med, [3] Hard, [4] Mix |: ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
    short OperationType = 0;
    do {
        cout << "Please Enter Operation Type | [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix |: ";
        cin >> OperationType;
    } while (OperationType < 1 || OperationType > 5);
    return (enOperationType)OperationType;
}

short ReadQuestionAnswer() 
{
    short Answer = 0;
    cin >> Answer;
    return Answer;
}

//-----------------------------------------------------------
// Game Logic Functions
//-----------------------------------------------------------

int SimpleCalculator(int Number1, int Number2, enOperationType OperationType)
{
    switch (OperationType) {
    case enOperationType::Add: return Number1 + Number2;
    case enOperationType::Sub: return Number1 - Number2;
    case enOperationType::Mul: return Number1 * Number2;
    case enOperationType::Div: return Number1 / Number2;
    default: return Number1 + Number2;
    }
}

stQuestion GenerateQuestions(enQuestionLevel QuestionLevel, enOperationType OperationType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionLevel::MixLevel)
        QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);

    if (OperationType == enOperationType::MixOperationType)
        OperationType = GetRandomOperationType();

    Question.OperationType = OperationType;
    Question.QuestionLevel = QuestionLevel;

    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuestionLevel::Med:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuestionLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestion; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestions(Quizz.QuestionLevel, Quizz.OperationType);
    }
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber) 
{
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer) {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;
        cout << "Wrong Answer :(" << endl;
        cout << "The Right Answer is: " << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl;
    }
    else {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;
        cout << "Right Answer :)" << endl;
    }
    setScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestion << "]\n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << " " 
         << GetOperationType(Quizz.QuestionList[QuestionNumber].OperationType) << " " 
         << Quizz.QuestionList[QuestionNumber].Number2 << " = ";
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz) 
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++) {
        PrintTheQuestion(Quizz, QuestionNumber);
        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

//-----------------------------------------------------------
// Results & Game Flow
//-----------------------------------------------------------

string getQuizzResultText(bool Pass) 
{
    return (Pass) ? "PASS :)" : "FAIL :(";
}

void PrintQuizzResult(stQuizz Quizz) 
{
    cout << "\n--------------------------\n";
    cout << "Game Result :\n";
    cout << "Number Of Questions     : " << Quizz.NumberOfQuestion << endl;
    cout << "Quizz Level             : " << getQuestionLevelText(Quizz.QuestionLevel) << endl;
    cout << "Operation Type          : " << GetOperationType(Quizz.OperationType) << endl;
    cout << "Right Answers           : " << Quizz.NumberOfRightAnswers << endl;
    cout << "Wrong Answers           : " << Quizz.NumberOfWrongAnswers << endl;
    cout << "Final Result            : " << getQuizzResultText(Quizz.isPass) << endl;
    cout << "--------------------------\n\n";
    setScreenColor(Quizz.isPass);
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

void StartGame() 
{
    char PlayAgain = 'Y';
    do {
        ReseteScreen();
        PlayMathGame();
        cout << "Do you want to play again? Y/N: ";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}

int main() 
{
    srand((unsigned)time(NULL)); 
    StartGame();
    return 0;
}
