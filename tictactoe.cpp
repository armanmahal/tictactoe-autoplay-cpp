#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

// TIC TAC TOE {[VS COMPUTER]}  with a 💩logic. lol...

char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
bool checkWinner = false;
int x = -1;

int getRandomInteger()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    return dis(gen);
}

void drawBoard()
{
    cout << "|" << arr[0][0] << "|" << arr[0][1] << "|" << arr[0][2] << "|" << endl;
    cout << "|" << arr[1][0] << "|" << arr[1][1] << "|" << arr[1][2] << "|" << endl;
    cout << "|" << arr[2][0] << "|" << arr[2][1] << "|" << arr[2][2] << "|" << endl;
}

// YOU BETTER NOT SEE MY LOGIC FUNCTION.
void winLogic()
{
    if ((arr[0][0] == 'X') && (arr[0][1] == 'X') && (arr[0][2] == 'X'))
    {
        checkWinner = true;
    }
    else if ((arr[1][0] == 'X') && (arr[1][1] == 'X') && (arr[1][2] == 'X'))
    {
        checkWinner = true;
    }
    else if ((arr[2][0] == 'X') && (arr[2][1] == 'X') && (arr[2][2] == 'X'))
    {
        checkWinner = true;
    }

    else if ((arr[0][0] == 'X') && (arr[1][0] == 'X') && (arr[2][0] == 'X'))
    {
        checkWinner = true;
    }
    else if ((arr[0][1] == 'X') && (arr[1][1] == 'X') && (arr[2][1] == 'X'))
    {
        checkWinner = true;
    }
    else if ((arr[0][2] == 'X') && (arr[1][2] == 'X') && (arr[2][2] == 'X'))
    {
        checkWinner = true;
    }

    else if ((arr[0][0] == 'O') && (arr[0][1] == 'O') && (arr[0][2] == 'O'))
    {
        checkWinner = true;
    }
    else if ((arr[1][0] == 'O') && (arr[1][1] == 'O') && (arr[1][2] == 'O'))
    {
        checkWinner = true;
    }
    else if ((arr[2][0] == 'O') && (arr[2][1] == 'O') && (arr[2][2] == 'O'))
    {
        checkWinner = true;
    }

    else if ((arr[0][0] == 'O') && (arr[1][0] == 'O') && (arr[2][0] == 'O'))
    {
        checkWinner = true;
    }
    else if ((arr[0][1] == 'O') && (arr[1][1] == 'O') && (arr[2][1] == 'O'))
    {
        checkWinner = true;
    }
    else if ((arr[0][2] == 'O') && (arr[1][2] == 'O') && (arr[2][2] == 'O'))
    {
        checkWinner = true;
    }

    else if ((arr[0][0] == 'X') && (arr[1][1] == 'X') && (arr[2][2] == 'X'))
    {
        checkWinner = true;
    }
    else if ((arr[0][2] == 'X') && (arr[1][1] == 'X') && (arr[2][0] == 'X'))
    {
        checkWinner = true;
    }

    else if ((arr[0][0] == 'O') && (arr[1][1] == 'O') && (arr[2][2] == 'O'))
    {
        checkWinner = true;
    }
    else if ((arr[0][2] == 'O') && (arr[1][1] == 'O') && (arr[2][0] == 'O'))
    {
        checkWinner = true;
    }

    else
    {
        checkWinner = false;
    }
}

// this auto play function is designed to defend the game because first turn is of player...
void autoLogic()
{

    // first move priority should be occupying the centre box ,autoLogic's main function is to defend,, first turn is always of player. -->
    if ((arr[1][1] != 'X') && (arr[1][1] != 'O'))
    {
        arr[1][1] = 'O';
    }

    // following are all the winning chances of computer, and its move...
    // 1
    else if ((((arr[0][0] == 'O') && (arr[0][1] == 'O')) || ((arr[2][0] == 'O') && (arr[1][1] == 'O')) || ((arr[2][2] == 'O') && (arr[1][2] == 'O'))) && ((arr[0][2] != 'X') && (arr[0][2] != 'O')))
    {
        arr[0][2] = 'O';
    }
    // 2
    else if ((((arr[1][0] == 'O') && (arr[1][2] == 'O')) || ((arr[0][2] == 'O') && (arr[2][2] == 'O')) || ((arr[1][0]=='O') && (arr[1][1]=='O')) )&& ((arr[1][2] != 'O') && (arr[1][2] != 'X')))
    {
        arr[1][2] = 'O';
    }
    // 3
    else if ((((arr[2][0] == 'O') && (arr[2][1] == 'O')) || ((arr[0][0] == 'O') && (arr[1][1] == 'O')) || ((arr[0][2] == 'O') && (arr[1][2] == 'O'))) && ((arr[2][2] != 'X') && (arr[2][2] != 'O')))
    {
        arr[2][2] = 'O';
    }
    // 4
    else if ((((arr[0][1] == 'O') && (arr[0][2] == 'O')) || ((arr[1][0] == 'O') && (arr[2][0] == 'O')) || ((arr[2][2] == 'O') && (arr[1][1] == 'O'))) && ((arr[0][0] != 'X') && (arr[0][0] != 'O')))
    {
        arr[0][0] = 'O';
    }
    // 5
    else if ((((arr[2][1] == 'O') && (arr[2][2] == 'O')) || ((arr[0][0] == 'O') && (arr[1][0] == 'O')) || ((arr[0][2] == 'O') && (arr[1][1] == 'O'))) && ((arr[2][0] != 'X') && (arr[2][0] != 'O')))
    {
        arr[2][0] = 'O';
    }
    // 6
    else if ((((arr[1][1] == 'O') && (arr[1][2] == 'O')) || ((arr[0][0] == 'O') && (arr[2][0] == 'O'))) && ((arr[1][0] != 'O') && (arr[1][0] != 'X')))
    {
        arr[1][0] = 'O';
    }
    // 7
    else if ((((arr[0][1] == 'O') && (arr[1][1] == 'O')) || ((arr[2][2] == 'O') && (arr[2][0] == 'O'))) && ((arr[2][1] != 'O') && (arr[2][1] != 'X')))
    {
        arr[2][1] = 'O';
    }
    // 8
    else if ((((arr[2][1] == 'O') && (arr[1][1] == 'O')) || ((arr[0][2] == 'O') && (arr[0][0] == 'O'))) && ((arr[0][1] != 'O') && (arr[0][1] != 'X')))
    {
        arr[0][1] = 'O';
    }
    // 9
    else if ((((arr[1][0] == 'O') && (arr[1][2] == 'O')) || ((arr[0][1] == 'O') && (arr[2][1] == 'O')) || ((arr[2][2] == 'O') && (arr[0][0] == 'O')) || ((arr[2][0] == 'O') && (arr[0][2] == 'O'))) && ((arr[1][1] != 'O') && (arr[1][1] != 'X')))
    {
        arr[1][1] = 'O';
    }

    // following are all the winning chances of player, and its defence...
    // 1
    else if ((((arr[0][0] == 'X') && (arr[0][1] == 'X')) || ((arr[2][0] == 'X') && (arr[1][1] == 'X')) || ((arr[2][2] == 'X') && (arr[1][2] == 'X'))) && ((arr[0][2] != 'O') && (arr[0][2] != 'X')))
    {
        arr[0][2] = 'O';
    }
    // 2
    else if ((((arr[1][0] == 'X') && (arr[1][2] == 'X')) || ((arr[0][2] == 'X') && (arr[2][2] == 'X'))) && ((arr[1][2] != 'O') && (arr[1][2] != 'X')))
    {
        arr[1][2] = 'O';
    }
    // 3
    else if ((((arr[2][0] == 'X') && (arr[2][1] == 'X')) || ((arr[0][0] == 'X') && (arr[1][1] == 'X')) || ((arr[0][2] == 'X') && (arr[1][2] == 'X'))) && ((arr[2][2] != 'O') && (arr[2][2] != 'X')))
    {
        arr[2][2] = 'O';
    }
    // 4
    else if ((((arr[0][1] == 'X') && (arr[0][2] == 'X')) || ((arr[1][0] == 'X') && (arr[2][0] == 'X')) || ((arr[2][2] == 'X') && (arr[1][1] == 'X'))) && ((arr[0][0] != 'O') && (arr[0][0] != 'X')))
    {
        arr[0][0] = 'O';
    }
    // 5
    else if ((((arr[2][1] == 'X') && (arr[2][2] == 'X')) || ((arr[0][0] == 'X') && (arr[1][0] == 'X')) || ((arr[0][2] == 'X') && (arr[1][1] == 'X'))) && ((arr[2][0] != 'O') && (arr[2][0] != 'X')))
    {
        arr[2][0] = 'O';
    }
    // 6
    else if ((((arr[1][1] == 'X') && (arr[1][2] == 'X')) || ((arr[0][0] == 'X') && (arr[2][0] == 'X'))) && ((arr[1][0] != 'O') && (arr[1][0] != 'X')))
    {
        arr[1][0] = 'O';
    }
    // 7
    else if ((((arr[0][1] == 'X') && (arr[1][1] == 'X')) || ((arr[2][2] == 'X') && (arr[2][0] == 'X'))) && ((arr[2][1] != 'O') && (arr[2][1] != 'X')))
    {
        arr[2][1] = 'O';
    }
    // 8
    else if ((((arr[2][1] == 'X') && (arr[1][1] == 'X')) || ((arr[0][2] == 'X') && (arr[0][0] == 'X'))) && ((arr[0][1] != 'O') && (arr[0][1] != 'X')))
    {
        arr[0][1] = 'O';
    }
    // 9
    else if ((((arr[1][0] == 'X') && (arr[1][2] == 'X')) || ((arr[0][1] == 'X') && (arr[2][1] == 'X')) || ((arr[2][2] == 'X') && (arr[0][0] == 'X')) || ((arr[2][0] == 'X') && (arr[0][2] == 'X'))) && ((arr[1][1] != 'O') && (arr[1][1] != 'X')))
    {
        arr[1][1] = 'O';
    }

    // randomly puts anywhere if opponent does not have any winning chance. ( can improve this by making calculated moves to win )
    else
    {
        while (true)
        {
            int row = getRandomInteger();
            int col = getRandomInteger();
            if ((arr[row][col] == 'X') || (arr[row][col] == 'O'))
            {
                continue;
            }

            arr[row][col] = 'O';
            break;
        }
    }
}

int main()
{
    cout << endl
         << "***SEE THE GIVEN BOARD FOR REFERENCE OF INPUT POSITIONS (for 'X' and 'O') THAT YOU HAVE TO ENTER***" << endl
         << endl;
    drawBoard();
    cout << endl
         << "***NOTE: You are 'X' and COMPUTER is 'O'***" << endl
         << endl
         << "STARTING..." << endl
         << endl;

    for (int i = 0; i < 9; i++)
    {

        cout << endl;
        if ((i % 2) == 0)
        {

            while (true)
            {
                cout << "Your turn, enter your input location: ";

                cin >> x;

                if ((x > 9) || (x < 1))
                {
                    cout << "SIKE! THATS THE WROOOONG NUMBER :(   try again lol." << endl
                         << endl;
                    continue;
                }

                x = x - 1;

                if ((arr[x / 3][x % 3] == 'X') || (arr[x / 3][x % 3] == 'O'))
                {
                    cout << "Already filled an input here, TRY AGAIN! " << endl
                         << endl;
                    continue;
                }

                arr[x / 3][x % 3] = 'X';
                break;
            }
        }

        if ((i % 2) == 1)
        {
            cout << "COMPUTER's turn ..." << endl;

            if ((i == 1) && (x == 4))
            {
                arr[0][2] = 'O';
                drawBoard();
                continue;
            }
            if ((i == 3) && (((arr[0][2] == 'X') && (arr[2][0] == 'X')) || ((arr[0][0] == 'X') && (arr[2][2] == 'X'))))
            {
                arr[2][1] = 'O';
                drawBoard();
                continue;
            }

            autoLogic();
        }
        cout << endl;

        drawBoard();

        winLogic();

        if (checkWinner == true)
        {
            if ((i % 2) == 0)
            {
                cout << "YOU WIN!" << endl;
            }
            else
            {
                cout << "COMPUTER WINS!" << endl;
            }
            return 0;
        }
    }

    cout << "ITS A DRAW! ";
    return 1;
}