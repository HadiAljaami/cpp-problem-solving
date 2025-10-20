#include <iostream>
#include <time.h>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, LeMix = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };
enum  enFinalResult { Winner = 1, Fial = 2, Draw = 3 };
struct stFinalResult
{
    enQuestionsLevel   QuestionsLevel;
    enOpType OpType;
    int NumberOfQuestions = 0;
    int NumberOfRightAnswer = 0;
    int NumberOfWrongAnswer = 0;

};
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
int GenerateNumbersDependingOnTHeLevel(enQuestionsLevel QuestionsLevel)
{
    switch (QuestionsLevel)
    {
    case  enQuestionsLevel::Easy:
        return  RandomNumber(0, 10);

    case enQuestionsLevel::Med:
        return  RandomNumber(11, 20);

    case enQuestionsLevel::Hard:
        return  RandomNumber(21, 50);

    case enQuestionsLevel::LeMix:
        return  RandomNumber(0, 50);
    }
}

int CalculationOperations(enOpType OpType, int  Number1, int Number2)
{
    switch (OpType)
    {
    case  enOpType::Add:
        return Number1 + Number2;

    case  enOpType::Sub:
        return Number1 - Number2;

    case  enOpType::Mul:
        return Number1 * Number2;

    case  enOpType::Div:
        return Number1 / Number2;
    }
}

enOpType RandomOperations()
{
    return (enOpType)RandomNumber(1, 4);
}
char ChoiceOperation(enOpType OpType)
{
    char Operation[4] = { '+','-','*', '/' };
    return Operation[OpType-1];
}
void PrintOperation(enOpType OpType, int  Number1, int Number2, int NumberOfQuestions, int Questions)
{
    cout << "\nQuestions[" << Questions << "/" << NumberOfQuestions << "]\n";
    cout << Number1 << "\n" << Number2 << "   " << ChoiceOperation(OpType) << "\n";
    cout << "_________" << endl;
}

int ReadAnswerFromPlayer()
{
    int n = 0;
    cin >> n;
    return n;
}
bool IsRight(int AnswerOfPlayer, int Result)
{
    return AnswerOfPlayer == Result;
}



enFinalResult WinFailDraw(stFinalResult FinalResult)
{
    if (FinalResult.NumberOfRightAnswer > FinalResult.NumberOfWrongAnswer)
    {
        return enFinalResult::Winner;
        system("color 2F"); //turn screen to Green
    }

    else if (FinalResult.NumberOfRightAnswer < FinalResult.NumberOfWrongAnswer)
    {
        return enFinalResult::Fial;
        system("color 4F"); //turn screen to Red 
    }
    else
    {
        return enFinalResult::Draw;
    }
}
string ChoiceFinalResult(enFinalResult FinalResult)
{
    string   Result[3] = { "Win", "Fial", "Draw" };
    return   Result[FinalResult-1];
}

void PrintShap(stFinalResult FinalResult)
{
    if (WinFailDraw(FinalResult) == enFinalResult::Winner)
    {
        cout << "[+_+]" << endl;
    }
    else if (WinFailDraw(FinalResult) == enFinalResult::Fial)
    {
        cout << "[-_-]" << endl;
    }

    else
    {
        cout << "[-_-]  v  [+_+] " << endl;
    }
}
string ChoiceQuestionsLevel(enQuestionsLevel Level)
{
    string  QuestionsLevel[4] = { "Easy", "Med" , "Hard", "Mix" };
    return  QuestionsLevel[Level-1];
}
void PrintFinalResult(stFinalResult FinalResult)
{
    cout << "\n\n_____________________________________\n";
    cout << "Final Result is           : " << ChoiceFinalResult(WinFailDraw(FinalResult)) << " : ";
    PrintShap(FinalResult);

    cout << "Number of question        : " << FinalResult.NumberOfQuestions << "\n";
    cout << "Question Level            : " << ChoiceQuestionsLevel(FinalResult.QuestionsLevel) << "\n";
    if (FinalResult.OpType == enOpType::Mix)
    {
        cout << "OpTye                     : Mix\n";
    }
    else
    {
         cout << "OpTye                     : " << ChoiceOperation(FinalResult.OpType) << "\n";
    }

    cout << "Number of Right Questions : " << FinalResult.NumberOfRightAnswer << "\n";
    cout << "Number of Wrong Questions : " << FinalResult.NumberOfWrongAnswer << "\n";
    cout << "\n_____________________________________\n";
    cout << endl;


}
void PlayGame(int NumberOfQuestions)
{
    stFinalResult FinalResult;
    short QuestionLevel = 1;
    short OperationType = 1;
    int Number1 = 0;
    int Number2 = 0;
    int Result = 0;

    cout << "\nEnter Question Level : [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
    cin >> QuestionLevel;

    cout << "\nEnter Operation Type : [1]Add, [2]Sub, [3]Mul=3,  [4]Div, [5]Mix ? ";
    cin >> OperationType;

    FinalResult.NumberOfQuestions = NumberOfQuestions;
    FinalResult.OpType = (enOpType)OperationType;
    FinalResult.QuestionsLevel = (enQuestionsLevel)QuestionLevel;

  
    for (int Question = 1;Question <= NumberOfQuestions;Question++)
    {
        Number1 = GenerateNumbersDependingOnTHeLevel((enQuestionsLevel)QuestionLevel);
        Number2 = GenerateNumbersDependingOnTHeLevel((enQuestionsLevel)QuestionLevel);

        if (FinalResult.OpType == enOpType::Mix)
        {
            OperationType = RandomOperations();
        }

        Result = CalculationOperations((enOpType)OperationType, Number1, Number2);
        PrintOperation((enOpType)OperationType, Number1, Number2, NumberOfQuestions, Question);
        int Answer = ReadAnswerFromPlayer();

        if (IsRight(Answer, Result))
        {
            cout << "\nRight Answer : [+_+] " << endl;
            FinalResult.NumberOfRightAnswer++;
            system("color 2F"); //turn screen to Green
        }

        else
        {
            cout << "\nWorng Answer : [-_-]" << endl;
            cout << "The Right Answer is : " << Result << endl;
            FinalResult.NumberOfWrongAnswer++;
            system("color 4F"); //turn screen to Red 
        }

        


    }

    PrintFinalResult(FinalResult);

}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void Game()
{
    int NumberOfQuestions = 0;
    char Again = 'y';

    do
    {
        ResetScreen();
        cout << "How many Questions do you want to answer ? ";
        cin >> NumberOfQuestions;

        PlayGame(NumberOfQuestions);

        cout << "Do you want to play again ? y/n ? ";
        cin >> Again;
    } while ((Again == 'Y') || (Again == 'y'));

}
int main()
{
    srand((unsigned)time(NULL));
  Game();

   
    
}