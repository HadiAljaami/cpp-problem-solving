#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
 enum enStonePaperScissor{ Stone=1, Paper=2, Scissor =3};
 int ComputerPoins =0, UserPoins =0, DrawPoins=0;

 void FirstGame()
 {
     ComputerPoins = 0, UserPoins = 0, DrawPoins = 0;
 }
 int ReadNumber()
 {
     int n;
     do
     {
         
         cin >> n;
     } while (n > 3 || n <= 0);
     return n;
 }
 int NumberRandom(int From ,int To)
 {
     return rand() % (To - From + 1) + From;
 }
 void DrawScreen(int Round)
{
    cout << "\nRound [" << Round << "] " << "being : \n";
    cout << "Your Choice : [1]:Stome, [2]:Paper, [3]: Scissors ?\n ";
}

int CheckTheWinner(int UserSelection, int CoputerSelection)
{  
     short Winner=0;
    switch (UserSelection)
    {
    case enStonePaperScissor::Paper:
        if (CoputerSelection == enStonePaperScissor::Scissor)
        {
            ComputerPoins++;
            Winner = 1;
        }
        else if (CoputerSelection == enStonePaperScissor::Stone)
        {
            UserPoins++;
            Winner = 2;
        }
        else
        {
            DrawPoins++;
            Winner = 0;
        }
        break;

    case enStonePaperScissor::Stone :
        if (CoputerSelection == enStonePaperScissor::Scissor)
        {
            UserPoins++;
            Winner = 2;
        }
        else if (CoputerSelection == enStonePaperScissor::Paper)
        {
            ComputerPoins++;
            Winner = 1;
        }
        else
        {
            DrawPoins++;
            Winner = 0;
        }
        break;

    case enStonePaperScissor::Scissor :

        if (CoputerSelection == enStonePaperScissor::Paper)
        {
            UserPoins++;
            Winner = 2;
        }
        else if (CoputerSelection == enStonePaperScissor::Stone)
        {
            ComputerPoins++;
            Winner = 1;
        }
        else
        {
            DrawPoins++;
            Winner = 0;
        }
        break;

    }

    return Winner;
}

string Choice(int choice)
{
    switch (choice)
    {
    case  enStonePaperScissor::Paper : 
        return  "Paper";

    case enStonePaperScissor::Scissor :
        return  "Scissor";

    case enStonePaperScissor::Stone:
        return  "Stone";

    }
}

void GameOver(int Round)
{
    cout << "\n\t\t_________________________________\n\n";
    cout << "\t\t      +++ Game Over +++\n";
    cout << "\t\t_________________________________\n";

    cout << "\n\t\t________[Game Result]____________\n" << endl;

    cout << "\t\tGame Rounds        : " << Round << endl;
    cout << "\t\tPlayer1 Won Times  : " << UserPoins << endl;
    cout << "\t\tComputer Won Times : " << ComputerPoins << endl;
    cout << "\t\tDraw Times         : " << DrawPoins << endl;
    cout << "\t\tFinal Winner       : ";


    if (ComputerPoins > UserPoins)
    {
        cout << "[Computer]\n";
    }
    else if (ComputerPoins < UserPoins)
    {
        cout << "[User]\n";
    }
    else
    {
        cout << "[Draw]\n";
    }
    cout << "\t\t_________________________________\n";




}
void PlayingScreen()
{
    bool Go = true;
    int Round;
    int Winner;
    int computer;
    int user;
    do
    {
        cout << "How Many Round 1 To 10 ?\n ";
        cin >>  Round ;
        cout << "\n";

        for (int i = 0; i < Round; i++)
        {
            DrawScreen(i+1);
            computer = NumberRandom(1, 3);
            user = ReadNumber();
            Winner= CheckTheWinner(user,computer );

            cout << "\n\n_________Round [" <<i+1 << "]_________\n";
            cout << "\nPlayer choice : "<< Choice(user);
            cout << "\nCoputer choice : " << Choice(computer);
            cout << "\nRound Winner : [";
           
            if (Winner == 1)
            {
                cout << "Computer";
            }
               
            else if (Winner == 2)
            {
                cout << "User";
            }
               
            else
            {
                  cout << "Draw"; 
            }
            cout <<"]" <<endl;
            cout << "____________________________\n";

        }

        GameOver(Round);


        cout << "\n\nDo You Play Agian ? [yes]:1 , [no]:0 ? ";
        cin >> Go;
        cout << endl;
        FirstGame();

    } while (Go);
    

}

int main()
{
   // system("color cyan");

    srand((unsigned)time(NULL));
    PlayingScreen();

    
}
