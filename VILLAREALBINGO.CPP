#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <windows.h>


using namespace std;

#define SetConsoleTextAttributeBlack "\033[0m"
#define SetConsoleTextAttributeGreen "\033[38;2;0;255;0m"
#define SetConsoleTextAttributeCyan "\033[38;2;0;255;255m"
#define SetConsoleTextAttributeBlue "\033[38;2;0;0;255m"
#define SetConsoleTextAttributeWhite "\033[38;2;255;255;255m"
#define SetConsoleTextAttributeYellow "\033[38;2;255;255;0m"
#define SetConsoleTextAttributeRed "\033[38;2;255;0;0m"
int numericalSorcerer();
int bingoCardNumber(int minRange, int maxRange);
vector<int> createBingoCard();
void showPlayerCard(vector<int> card);
void showPlayerCardOption1(vector<int> card);
void showPlayerCardOption2(vector<int> card);
void showPlayerCardOption3(vector<int> card);
void showPlayerCardOption4(vector<int> card);
bool checkBingoWinHard( vector<int> card);
bool checkBingoWin( vector<int> card);
void displayWinningPattern( vector<int> card);
void displayBingoLogo();
void displayMainMenuUi();
void displayMenuErrorHandling();
void displayGameSettingMenu();
void displayCredit();
void displayAbout();
void displayLearnHowToPlay();
void displayPattern1();
void displayPattern2();
void displayPattern3();
void displayPattern4();
void displayDesignErrorHandling();
void displayCrownWinner();
void displayErrorHandlingBack();
void displayRating();
void displayGoodbyeExit();
void displayErrorHandlingMod();
void displayGuntingLineBreaker();
void displayKeyBoard1();
void displayMayBug();

int main() {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  int menuChoice;
  int generateOption = 0;
  int gameSettingModify;
  int cardDesignTemplate = 0;
  int selectedCardDesign = 0;
  int counterforPlayers = 0;
  int gameModehard = 0;
  int stars;
  int errorHandlerModifier;

  displayBingoLogo();

  while (true) {
    displayMainMenuUi();
    cout << "What do you want to do?\nUser:/> ";
    while (!(cin >> menuChoice) || menuChoice < 0 || menuChoice > 7 || (cin.get() != '\n'))
    {

      displayMenuErrorHandling();

      cin.clear();
      cin.ignore(123, '\n');
    }
    switch (menuChoice)
    {
    case 1: {
      cin.clear();
      srand(time(0));
      short infinityLoop = 1;
      vector <int> numbers;
      vector<string> player;
      vector<vector<int>> displayCards(4);

      for (int i = 0; i < 4; i++)
      {
        displayCards[i] = createBingoCard();
      }
      string entredName;
      cin.clear();
      displayGuntingLineBreaker();
      do
      {
        cout << "Enter Player 4 Names Only, Type 'X' or 'Done' if finish:.-> ";
        getline(cin, entredName);
        player.push_back(entredName);
        counterforPlayers++;
      } while (counterforPlayers != 4 && entredName != "Done" && entredName != "X" && entredName != "done" && entredName != "x");

      do
      {

        int sorecererNumber;
        do {
          if (generateOption == 1) {
            cout << "Please Press 1 to Summon and Generate a Card:.-> ";
            while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
            {
              displayKeyBoard1();
              cout << "You are Only Allowed to Press 1.-> ";

              cin.clear();
              cin.ignore(123, '\n');
            }

            sorecererNumber = numericalSorcerer();
          }
          if (generateOption == 0) {
            cout << "\n\n\nAutomatic Generation is -[ON]-\n-";

            sorecererNumber = numericalSorcerer();
          }
        } while (sorecererNumber == 2012);

        cout << "\nSorcerer Summon a number: " << sorecererNumber << '\n';

        for (int playersCard = 0; playersCard < 4; playersCard++)
        {
          for (int numberInsidePlayersCard = 0; numberInsidePlayersCard < 25; numberInsidePlayersCard++)
          {
            if (displayCards[playersCard][numberInsidePlayersCard] == sorecererNumber)
            {
              
              numbers.push_back(sorecererNumber);
              displayCards[playersCard][numberInsidePlayersCard] = 100;
            }
          }
        }
        for (int i = 0; i < 4; i++)
        {
          cout << "\nSorcerer Summon a number: "
               << "[" << sorecererNumber << "]" << '\n';
          cout << "\n"
               << "Player " << i + 1 << " Named " << player[i] << " Cards ";
          if (selectedCardDesign == 0) {
            showPlayerCard(displayCards[i]);
          }
          if (selectedCardDesign == 1) {
            showPlayerCardOption1(displayCards[i]);
          }
          if (selectedCardDesign == 2) {
            showPlayerCardOption2(displayCards[i]);
          }
          if (selectedCardDesign == 3) {
            showPlayerCardOption3(displayCards[i]);
          }
          if (selectedCardDesign == 4) {
            showPlayerCardOption4(displayCards[i]);
          }
        }
        if (gameModehard == 1) {
          if (checkBingoWinHard(displayCards[0])) {
            cout << "|=========================================|\n";
            cout << "|< Bingo "
                    "Player 1 "
                 << player[0] << " Wins the Game >\n";
            cout << "|=========================================|\n";
            displayWinningPattern(displayCards[0]);
            cout << endl;
            displayCrownWinner();
            showPlayerCard(displayCards[0]);
            cout << endl;
            cout << "Behold the wining Card-^\n";
            displayGuntingLineBreaker();
            cout << "\n";
            return 1;
            cout << "\nDo you want to back to the menu? ";
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
          }
        }
        else if (checkBingoWin(displayCards[0])) {
          cout << endl;
          cout << "Bingo! "
                  "Player 1 " << player[0] << " Wins the Game         \n";
          displayWinningPattern(displayCards[0]);
          displayCrownWinner();
          showPlayerCard(displayCards[0]);
          cout << endl;
          displayGuntingLineBreaker();
          cout << "\n";
          cout << "\nDo you want to back to the menu? ";
          break;
        }
        if (gameModehard == 1) {
          if (checkBingoWinHard(displayCards[1])) {
            cout << "|=========================================|\n";
            cout << "|Bingo! "
                    "Player 2 "
                 << player[1] << " Wins the Game         |\n";
            cout << "|=========================================|\n";
            displayCrownWinner();
            showPlayerCard(displayCards[1]);
            displayWinningPattern(displayCards[1]);
            cout << endl;
            cout << "Behold the wining Card-^\n";
            displayGuntingLineBreaker();
            return 1;
            cout << "\nDo you want to bakck to the menu? ";
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
          }
        }
        else if (checkBingoWin(displayCards[1])) {
          cout << endl;
          cout << "Bingo! "
                  "Player 2 "
               << player[1] << " Wins the Game\n";
          displayCrownWinner();
          showPlayerCard(displayCards[1]);
          displayWinningPattern(displayCards[1]);
            displayGuntingLineBreaker();
            cout << "\nDo you want to back to the menu? ";
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayKeyBoard1();
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
            break;
          }
        if (gameModehard == 1) {
          if (checkBingoWinHard(displayCards[2])) {
            cout << "|=========================================|\n";
            cout << "|Bingo "
                    "Player 3 "
                 << player[2] << " Wins the Game         |\n";
            cout << "|=========================================|\n";

            displayWinningPattern(displayCards[2]);
            cout << endl;
            displayCrownWinner();
            showPlayerCard(displayCards[2]);
            cout << endl;
            cout << "Behold the wining Card:-^\n";
            displayGuntingLineBreaker();
            cout << endl;
            return 1;
            cout << "\nDo you want to back to the menu? ";
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
          }
        }
        else if (checkBingoWin(displayCards[2])) {
          cout << endl;
          cout << "Bingo "
                  "Player 3 "
               << player[2] << " Wins the Game\n";
          displayWinningPattern(displayCards[2]);
          displayCrownWinner();
          showPlayerCard(displayCards[2]);
          cout << endl;
          displayGuntingLineBreaker();

          cout << endl;
          cout << "\nDo you want to back to the menu? ";
          while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
          {
            displayKeyBoard1();
            displayErrorHandlingBack();

            cin.clear();
            cin.ignore(123, '\n');
          }
          break;
        }
        if (gameModehard == 1) {
          if (checkBingoWinHard(displayCards[3])) {
            cout << "|=========================================|\n";
            cout << "|Bingo "
                    "Player 4 "
                 << player[3] << " Wins the Game         |\n";
            cout << "|=========================================|\n";

            displayWinningPattern(displayCards[3]);
            cout << endl;
            displayCrownWinner();
            showPlayerCard(displayCards[3]);
            cout << "Behold the wining Card:-^\n";
            displayGuntingLineBreaker();
            cout << endl;
            cout << "\nDo you want to back to the menu? ";
            return 1;
            while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
            {
              displayKeyBoard1();
              displayErrorHandlingBack();
              cin.clear();
              cin.ignore(123, '\n');
            }
          }
        }
        else if (checkBingoWin(displayCards[3])) {
          cout << endl;
          cout << "Bingo "
                  "Player 4 "
               << player[3] << " Wins the Game\n";
          displayWinningPattern(displayCards[3]);
          displayCrownWinner();
          showPlayerCard(displayCards[3]);
          cout << endl;
          displayGuntingLineBreaker();
          cout << endl;
          cout << "\nDo you want to back to the menu? ";
          while (!(cin >> menuChoice) || (menuChoice != 1 && menuChoice != 0) || cin.get() != '\n')
          {
            displayKeyBoard1();
            displayErrorHandlingBack();
            cin.clear();
            cin.ignore(123, '\n');
          }
          break;
        }
      } while (infinityLoop == 1);
      cout << "Type 1 to confirm? ";
      while (!(cin >> menuChoice) || (menuChoice != 1) || cin.get() != '\n')
      {
        displayMenuErrorHandling();
        cin.clear();
        cin.ignore(123, '\n');
      }
      break;
    }

    case 2: {
      displayLearnHowToPlay();

      cout << "Press 1 to go back to the Main menu-> ";
      while (!(cin >> menuChoice) || (menuChoice != 1) || cin.get() != '\n')
      {
        displayKeyBoard1();
        displayErrorHandlingBack();

        cin.clear();
        cin.ignore(123, '\n');
      }

      break;
    }
    case 3: {
      displayGameSettingMenu();
      cout << "What do you want to modify? ";
      cin >> gameSettingModify;

      switch (gameSettingModify)
      {
      case 1:
        cout << "Turn On Manual Generation By Pressing [1]:.-> ";
        while (!(cin >> generateOption))
        {
          cout << "Press [1]:.-> ";
          cin.clear();
          cin.ignore(123, '\n');
        }
        cout << "Press 1 to Enable Go Back to The Menu: ";
        while (!(cin >> menuChoice) || menuChoice < 0 || menuChoice > 5 || (cin.get() != '\n'))
        {
          displayMenuErrorHandling();
          cin.clear();
          cin.ignore(123, '\n');
        }
        break;
      case 2:
        cout << "Do you want to Modify the Bingo Card Design? [Press 1]: ";
        while (!(cin >> cardDesignTemplate) || cardDesignTemplate != 1 || cin.get() != '\n')
        {
          displayErrorHandlingBack();
          cin.clear();
          cin.ignore(123, '\n');
        }
        switch (cardDesignTemplate)
        {
        case 1:
        {
          cout << "Look at the design template by pressing [1]:-.> ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Allowed to Press 1.-> ";
            cin.clear();
            cin.ignore(123, '\n');
          }
          displayPattern1();
          cout << "Please Press 1 Please:;-> ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Allowed to Press 1.-> ";

            cin.clear();
            cin.ignore(123, '\n');
          }
          cout << endl;
          displayPattern2();
          cout << "Please Press 1 to See More Display Pattern: ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Only Allowed to Press 1.-> ";

            cin.clear();
            cin.ignore(123, '\n');
          }
          cout << endl;
          displayPattern3();
          cout << "Please Press 1 to See More Display Pattern:.-> ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Only Allowed to Press 1.-> ";

            cin.clear();
            cin.ignore(123, '\n');
          }
          cout << endl;
          displayPattern4();
          cout << "Please Press 1 to See More Display Pattern:.-> ";
          while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
          {
            cout << "You are Only Allowed to Press 1.-> ";

            cin.clear();
            cin.ignore(123, '\n');
          }
          cout << endl;
          cout << "What Design Do you Want to Select? ";
          while (!(cin >> selectedCardDesign) || selectedCardDesign > 5 || selectedCardDesign < 1 || cin.get() != '\n')
          {
            displayDesignErrorHandling();
          }
          cout << "Press 1 To go Back to the Main Menu.-> ";
          while (!(cin >> menuChoice) || menuChoice != 1 || (cin.get() != '\n'))
          {
            displayKeyBoard1();
            displayErrorHandlingBack();

            cin.clear();
            cin.ignore(123, '\n');
          }
         break;
        }

        default:
          break;
        }
        break;
      case 3:
        cout << "Press [1] to Change the Mode to Hard: ";
        while (!(cin >> gameModehard) || gameModehard != 1 || cin.get() != '\n')
        {
          cout << "Cannot Go Back Now Press [1]! ";
          displayKeyBoard1();
          cin.clear();
          cin.ignore(123, '\n');
        }
        cout << "Press 1 to Go Back to Main Menu.-> ";
        while (!(cin >> menuChoice) || menuChoice < 0 || menuChoice > 5 || (cin.get() != '\n'))
        {
          displayKeyBoard1();
          displayErrorHandlingBack();
          cin.clear();
          cin.ignore(123, '\n');
        }

      default:
        break;
      }

      break;
    }
    case 4: {
      displayCredit();
      cout << "Press 1 To go Back to the Main Menu.-> ";
      while (!(cin >> menuChoice) || menuChoice != 1 || (cin.get() != '\n'))
      {
        displayKeyBoard1();
        displayErrorHandlingBack();

        cin.clear();
        cin.ignore(123, '\n');
      }
      break;
    }
    case 5: {
      displayAbout();
      cout << "Press 1 To go Back to the Main Menu.-> ";
      while (!(cin >> menuChoice) || menuChoice != 1 || (cin.get() != '\n'))
      {
        displayKeyBoard1();
        displayErrorHandlingBack();

        cin.clear();
        cin.ignore(123, '\n');
      }
      break;
    }
    case 6: {
      displayRating();
      cout << "Press 1 To go Back to the Main Menu.-> ";
      while (!(cin >> menuChoice) || menuChoice != 1 || (cin.get() != '\n'))
      {
        displayKeyBoard1();
        displayErrorHandlingBack();

        cin.clear();
        cin.ignore(123, '\n');
      }
      break;
    }
    case 7: {
      displayGoodbyeExit();
      return 0;
    }
    default:
      break;
    }
  }
  return 0;
}
//------------------------------------------------------------------------------------------8<-------------------------------------------------------------------------------------------------------------------------------------------------------------
int numericalSorcerer() {
  return rand() % 75 + 1;
}

int bingoCardNumber(int minRange, int maxRange) {
  return minRange + rand() % (maxRange - minRange + 1);
}

vector<pair<int, int>> bingoRanges = {
    {1, 15},
    {16, 30},
    {31, 45},
    {46, 60},
    {61, 75},
};
vector<int> createBingoCard() {
  vector<int> card(25);

  for (int rows = 0; rows < 5; rows++)
  {
    for (int columns = 0; columns < 5; columns++)
    {
      int colMin = bingoRanges[columns].first;
      int colMax = bingoRanges[columns].second;

      do
      {
        int duplicatedNumber = 0;
        int cardnumber = bingoCardNumber(colMin, colMax);

        for (int numberInside : card)
        {
          if (numberInside == cardnumber)
          {
            duplicatedNumber = 1;
            card[rows * 5 + columns] = 0;
            break;
          }
        }
        if (duplicatedNumber == 0)
        {
          card[rows * 5 + columns] = cardnumber;
          break;
        }
      } while (card[rows * 5 + columns] == 0);
    }
  }
  card[12] = 100;
  return card;
  /*After rows = 0, columns = 1 (second iteration of the inner loop)
  -> -> -> -> -> ->

 | B   | I   | N   | G   | O   |
 |-----|-----|-----|-----|-----|
 |  2  | 18  |  .  |  .  |  .  |
 |  .  |  .  |  .  |  .  |  .  |
 |  .  |  .  |  .  |  .  |  .  |
 |  .  |  .  |  .  |  .  |  .  |
 |  .  |  .  |  .  |  .  |  .  |
 */
}
void showPlayerCard(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

  cout << "\n.___________________________________.\n";
  cout << "|B\t I\t N\t G\t O  |\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeBlue;
      cout << "<|X|> \t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << " " << card[i] << ""
           << " \t";
  }
  cout << "\n|__________________________________|" << SetConsoleTextAttributeBlack;
  cout
      << endl;
  cout << endl;
}
void showPlayerCardOption1(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n.___________________________________.\n";
  cout << "|B\t I\t N\t G\t O  |\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeGreen;
      cout << "-[X]-\t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << "-[" << card[i] << "]-"
           << " \t";
  }
  cout << "\n|__________________________________|";
  cout << endl;
  cout << endl;
}
void showPlayerCardOption2(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n.___________________________________.\n";
  cout << "|" << SetConsoleTextAttributeYellow "B\t I\t N\t G\t O" << SetConsoleTextAttributeBlack "|\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeYellow;
      cout << "<X> \t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << " " << card[i] << " "
           << "\t";
  }
  cout << "\n|__________________________________|";
  cout << endl;
  cout << endl;
}
void showPlayerCardOption3(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n.___________________________________.\n";
  cout << "|" << SetConsoleTextAttributeRed "B\t I\t N\t G\t O" << SetConsoleTextAttributeBlack "|\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeRed;
      cout << "\\X/ \t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << "\\" << card[i] << "/"
           << " \t";
  }
  cout << "\n|__________________________________|";
  cout << endl;
  cout << endl;
}
void showPlayerCardOption4(vector<int> card) {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n.___________________________________.\n";
  cout << "|B\t I\t N\t G\t O  |\n";
  cout << "|___________________________________|";
  for (int i = 0; i < 25; i++)
  {

    if (i % 5 == 0)
    {
      cout << endl;
    }

    int uniqueNumber = card[i];
    if (uniqueNumber == 100)
    {
      cout << SetConsoleTextAttributeCyan;
      cout << "(X) \t";
      cout << SetConsoleTextAttributeBlack;
    }
    else
      cout << "(" << card[i] << ")"
           << " \t";
  }
  cout << "\n|__________________________________|";
  cout << endl;
  cout << endl;
}
bool checkBingoWinHard(const vector<int> card) {
/*
  B   I    N    G    O
|0| |1 | |2 | |3 | |4 |
|5| |6 | |7 | |8 | |9 |
|10||11| |12| |13| |14|
|15||16| |17| |18| |19|
|20||21| |22| |23| |24|
12 is the center
*/

  if ((card[0] == 100 && card[1] == 100 && card[2] == 100 && card[3] == 100 && card[4] == 100) &&
      (card[5] == 100 && card[6] == 100 && card[7] == 100 && card[8] == 100 && card[9] == 100) &&
      (card[10] == 100 && card[11] == 100 && card[12] == 100 && card[13] == 100 && card[14] == 100) &&
      (card[15] == 100 && card[16] == 100 && card[17] == 100 && card[18] == 100 && card[19] == 100) &&
      (card[20] == 100 && card[21] == 100 && card[22] == 100 && card[23] == 100 && card[24] == 100) &&
      (card[0] == 100 && card[5] == 100 && card[10] == 100 && card[15] == 100 && card[20] == 100) &&
      (card[1] == 100 && card[6] == 100 && card[11] == 100 && card[16] == 100 && card[21] == 100) &&
      (card[2] == 100 && card[7] == 100 && card[12] == 100 && card[17] == 100 && card[22] == 100) &&
      (card[3] == 100 && card[8] == 100 && card[13] == 100 && card[18] == 100 && card[23] == 100) &&
      (card[4] == 100 && card[9] == 100 && card[14] == 100 && card[19] == 100 && card[24] == 100) &&
      (card[0] == 100 && card[6] == 100 && card[12] == 100 && card[18] == 100 && card[24] == 100) &&
      (card[4] == 100 && card[8] == 100 && card[12] == 100 && card[16] == 100 && card[20] == 100))
  {
    return true;
  }

  return false;
}
bool checkBingoWin(const vector<int> card) {
/*
  B   I    N    G    O
|0| |1 | |2 | |3 | |4 |
|5| |6 | |7 | |8 | |9 |
|10||11| |12| |13| |14|
|15||16| |17| |18| |19|
|20||21| |22| |23| |24|
12 is the center
*/

  if ((card[0] == 100 && card[1] == 100 && card[2] == 100 && card[3] == 100 && card[4] == 100) ||
      (card[5] == 100 && card[6] == 100 && card[7] == 100 && card[8] == 100 && card[9] == 100) ||
      (card[10] == 100 && card[11] == 100 && card[12] == 100 && card[13] == 100 && card[14] == 100) ||
      (card[15] == 100 && card[16] == 100 && card[17] == 100 && card[18] == 100 && card[19] == 100) ||
      (card[20] == 100 && card[21] == 100 && card[22] == 100 && card[23] == 100 && card[24] == 100))
  {
    return true;
  }

  if ((card[0] == 100 && card[5] == 100 && card[10] == 100 && card[15] == 100 && card[20] == 100) ||
      (card[1] == 100 && card[6] == 100 && card[11] == 100 && card[16] == 100 && card[21] == 100) ||
      (card[2] == 100 && card[7] == 100 && card[12] == 100 && card[17] == 100 && card[22] == 100) ||
      (card[3] == 100 && card[8] == 100 && card[13] == 100 && card[18] == 100 && card[23] == 100) ||
      (card[4] == 100 && card[9] == 100 && card[14] == 100 && card[19] == 100 && card[24] == 100))
  {
    return true;
  }

  if ((card[0] == 100 && card[6] == 100 && card[12] == 100 && card[18] == 100 && card[24] == 100) ||
      (card[4] == 100 && card[8] == 100 && card[12] == 100 && card[16] == 100 && card[20] == 100))
  {
    return true;
  }

  return false;
}
void displayWinningPattern(const vector<int> card) {
  if ((card[0] == 100 && card[1] == 100 && card[2] == 100 && card[3] == 100 && card[4] == 100) &&
      (card[5] == 100 && card[6] == 100 && card[7] == 100 && card[8] == 100 && card[9] == 100) &&
      (card[10] == 100 && card[11] == 100 && card[12] == 100 && card[13] == 100 && card[14] == 100) &&
      (card[15] == 100 && card[16] == 100 && card[17] == 100 && card[18] == 100 && card[19] == 100) &&
      (card[20] == 100 && card[21] == 100 && card[22] == 100 && card[23] == 100 && card[24] == 100) &&
      (card[0] == 100 && card[5] == 100 && card[10] == 100 && card[15] == 100 && card[20] == 100) &&
      (card[1] == 100 && card[6] == 100 && card[11] == 100 && card[16] == 100 && card[21] == 100) &&
      (card[2] == 100 && card[7] == 100 && card[12] == 100 && card[17] == 100 && card[22] == 100) &&
      (card[3] == 100 && card[8] == 100 && card[13] == 100 && card[18] == 100 && card[23] == 100) &&
      (card[4] == 100 && card[9] == 100 && card[14] == 100 && card[19] == 100 && card[24] == 100) &&
      (card[0] == 100 && card[6] == 100 && card[12] == 100 && card[18] == 100 && card[24] == 100) &&
      (card[4] == 100 && card[8] == 100 && card[12] == 100 && card[16] == 100 && card[20] == 100))
  {
    cout << "Full House Alert! This Player Needs to Stop Playing Bingo and Start Playing Lotto :)";
    cout << endl;
    return;
  }
  if ((card[0] == 100 && card[5] == 100 && card[10] == 100 && card[15] == 100 && card[20] == 100) ||
      (card[1] == 100 && card[6] == 100 && card[11] == 100 && card[16] == 100 && card[21] == 100) ||
      (card[2] == 100 && card[7] == 100 && card[12] == 100 && card[17] == 100 && card[22] == 100) ||
      (card[3] == 100 && card[8] == 100 && card[13] == 100 && card[18] == 100 && card[23] == 100) ||
      (card[4] == 100 && card[9] == 100 && card[14] == 100 && card[19] == 100 && card[24] == 100))
  {
    cout << "The Winner Achieved a Vertical Pattern What a Luck!";
    cout << endl;
  }
  if ((card[0] == 100 && card[1] == 100 && card[2] == 100 && card[3] == 100 && card[4] == 100) ||
      (card[5] == 100 && card[6] == 100 && card[7] == 100 && card[8] == 100 && card[9] == 100) ||
      (card[10] == 100 && card[11] == 100 && card[12] == 100 && card[13] == 100 && card[14] == 100) ||
      (card[15] == 100 && card[16] == 100 && card[17] == 100 && card[18] == 100 && card[19] == 100) ||
      (card[20] == 100 && card[21] == 100 && card[22] == 100 && card[23] == 100 && card[24] == 100))
  {
    cout << "The Winner Achieved a Horizontal Pattern, Lucky one !";
    cout << endl;
  }

  if ((card[0] == 100 && card[6] == 100 && card[12] == 100 && card[18] == 100 && card[24] == 100) ||
      (card[4] == 100 && card[8] == 100 && card[12] == 100 && card[16] == 100 && card[20] == 100))
  {
    cout << "The Winner Achieved a Diagonal Pattern, A Madiagonal Win!";
    cout << endl;
  }
}
void displayBingoLogo() {
  cout << SetConsoleTextAttributeYellow;
  cout << "\n\n   .+------+     +------+     +------+     +------+     +------+    +------+     +------+." << endl;
  cout << " .' |      |    /|      |     |      |     |      |     |      |    |      |\\    |      | `." << endl;
  cout << "+   |  W   |   + |   E  |     +   L  +     +   C  +     +  O   +    |  M   | +   |  E   |   +" << endl;
  cout << "|   |      |   | |      |     |      |     |      |     |      |    |      | |   |      |   |" << endl;
  cout << "|  .+------+   | +------+     +------+     +------+     +------+    +------+ |   +------+.  |" << endl;
  cout << "|.'      .'    |/   B  /      |   I  |     |  N   |     |  G   |     \\  O   \\|    `.       `|" << endl;
  cout << "+------+'      +------+       +------+     +------+     +------+      +------+      `+------+\n\n";
  cout << SetConsoleTextAttributeBlack;
}
void displayMainMenuUi() {
  cout << SetConsoleTextAttributeGreen;
  cout << "\t\t\t      ___________________________________\n";
  cout << "\t\t\t     /\\                                  \\\n";
  cout << "\t\t\t     \\_|                                 |\n";
  cout << "\t\t\t       |              Menu               |\n";
  cout << "\t\t\t       |                                 |\n";
  cout << "\t\t\t       |-[1]->Start the Game             |\n";
  cout << "\t\t\t       |-[2]->Learn How to Play          |\n";
  cout << "\t\t\t       |-[3]->Game Settings              |\n";
  cout << "\t\t\t       |-[4]->Credits                    |\n";
  cout << "\t\t\t       |-[5]->About the Game             |\n";
  cout << "\t\t\t       |-[6]->Rate the Game              |\n";
  cout << "\t\t\t       |-[7]->Exit the Game              |\n";
  cout << "\t\t\t       |                                 |\n";
  cout << "\t\t\t       |   ______________________________|_\n";
  cout << "\t\t\t       \\__/________________________________/\n\n";
  cout << SetConsoleTextAttributeBlack;
}
void displayMenuErrorHandling() {
  cout << SetConsoleTextAttributeYellow;
  cout << "\n\n  :-----[Error! Please Enter a Valid Number ]--:\n";
  cout << SetConsoleTextAttributeGreen "  |                                            |\n";
  cout << SetConsoleTextAttributeGreen "  |  [1]->Start the Game         " << SetConsoleTextAttributeYellow "_" << SetConsoleTextAttributeGreen "             |\n";
  cout << SetConsoleTextAttributeGreen "  |  [2]->Learn How to Play     " << SetConsoleTextAttributeYellow "| |" << SetConsoleTextAttributeGreen "            |\n";
  cout << SetConsoleTextAttributeGreen "  |  [3]->Game Settings" << SetConsoleTextAttributeYellow "         |||" << SetConsoleTextAttributeGreen "            |\n";
  cout << SetConsoleTextAttributeGreen"  |  [4]->Credits"<<SetConsoleTextAttributeYellow               "               |_|"<<SetConsoleTextAttributeGreen            "            |\n";
  cout << SetConsoleTextAttributeGreen "  |  [5]->About the Game" << SetConsoleTextAttributeYellow "        (_)" << SetConsoleTextAttributeGreen "            |\n";
  cout << SetConsoleTextAttributeGreen "  |  [6]->Exit the Game                        |\n";
  cout << SetConsoleTextAttributeGreen "  |____________________________________________|\n";
  cout << SetConsoleTextAttributeGreen "  |_/--> ";
  cout << SetConsoleTextAttributeBlack;
}
void displayCredit() {
  cout << "                      -,---.           ,---.\n";
  cout << "                     / /\"`\\.--\"\"\"--./,'\"\\ \\\n";
  cout << "                     \\ \\    _       _    / /\n";
  cout << "                      `./  / __   __ \\  \\,'\n";
  cout << "                       /    /_O)_(_O\\    \\\n";
  cout << "                       |  .-'  ___  `-.  |\n";
  cout << "                    .--|       \\_/       |--.\n";
  cout << "                  ,'    \\   \\   |   /   /    `.\n";
  cout << "                 /       `.  `--^--'  ,'       \\\n";
  cout << "              .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n";
  cout << " .-----------/         \\------------------/         \\---------------------------------------------.\n";
  cout << " | .---------\\         /----------------- \\         /--------------------------------------------. |\n";
  cout << " | |          `-`--`--'                    `--'--'-'                                             | |\n";
  cout << " | |                                         **Credits:**                                        | |\n";
  cout << " | | 1. **Brocode Idea in Creating Vector Pairs:**                                               | |\n";
  cout << " | |     - Source: Brocode                                                                       | |\n";
  cout << " | |     - Description: Inspiration and the idea  for creating vector pairs in the game.         | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 2. **Caleb Curry's Idea of Using Vector Over Arrays:**                                      | |\n";
  cout << " | |     - Source: Caleb Curry                                                                   | |\n";
  cout << " | |     - Description: Guidance on using vectors over arrays in game development.               | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 3. **Neso Academy's Insight on Why to Use Vector:**                                         | |\n";
  cout << " | |     - Source: Neso Academy                                                                  | |\n";
  cout << " | |     - Description: Explanation of the advantages of using vectors in programming.           | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 4. **Simplilearn's Explanation of Array Pairs and Vector Pairs:**                           | |\n";
  cout << " | |      - Source: Simplilearn                                                                  | |\n";
  cout << " | |      - Description: Conceptual understanding of array pairs and vector pair                 | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 5. **Shiam Junior Chuttoo's Code:**                                                         | |\n";
  cout << " | |     - Source: Shiam Junior Chuttoo                                                          | |\n";
  cout << " | |     - Description: Code contribution to the project                                         | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 6. **Akrit Subedi's Explanation of Bingo Game:**                                            | |\n";
  cout << " | |     - Source: Akrit Subedi                                                                  | |\n";
  cout << " | |     - Description: Insight and Code into the development of a Bingo game.                   | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 7. **Cosme Co.'s Explanation of Bingo Game:**                                               | |\n";
  cout << " | |     - Source: Cosme Co.                                                                     | |\n";
  cout << " | |     - Description: Contribution to the understanding of Bingo game development.             | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 8. **CasualGamer's Idea of Coloring Text and Simple UI Lesson:**                            | |\n";
  cout << " | |     - Source: CasualGamer                                                                   | |\n";
  cout << " | |     - Description: Creative input on text coloring and UI design.                           | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 9. **Andreas Wegmann's Idea and Explanation of Simple Menu in C++:**                        | |\n";
  cout << " | |     - Source: Andreas Wegmann                                                               | |\n";
  cout << " | |     - Description: Guidance on creating a simple menu in C++.                               | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 10. **Coding Cleverly's Idea of How 2d Vector Works:**                                      | |\n";
  cout << " | |      - Source: Coding Cleverly                                                              | |\n";
  cout << " | |      - Description: Understanding the mechanics of Bingo.                                   | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 11. **CodeBeauty's Idea of Error Handling:**                                                | |\n";
  cout << " | |      - Source: CodeBeauty                                                                   | |\n";
  cout << " | |      - Description: Conceptualization of error handling in the project.                     | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 12. **GeeksforGeeks' Idea of Drawing Numbers in Range:**                                    | |\n";
  cout << " | |      - Source: GeeksforGeeks                                                                | |\n";
  cout << " | |      - Description: Guidance on drawing numbers within a specified range.                   | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 13. **nikunj_sonigara from GeeksforGeeks for Bingo Game Source Code:**                      | |\n";
  cout << " | |      - Source: nikunj_sonigara                                                              | |\n";
  cout << " | |      - Description: Reference to a specific source code for a Bingo game.                   | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 14. **s-martel's Source for Bingo Game:**                                                   | |\n";
  cout << " | |     - Source: s-martel                                                                      | |\n";
  cout << " | |     - Description: Reference to a specific source for Bingo game development.               | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 15. **JavaScript Random by weschools:**                                                     | |\n";
  cout << " | |      - Source: weschools                                                                    | |\n";
  cout << " | |      - Description: Function reference for generating random numbers in a range.            | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 16.  **Stack Overflow - Using cin for Error Handling:**                                     | |\n";
  cout << " | |       - Source: Stack Overflow                                                              | |\n";
  cout << " | |       - Description: Code reference for error handling using cin.                           | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 17.  **ASCII Art for UI Design:**                                                           | |\n";
  cout << " | |       - Source: ASCII Art Archives                                                          | |\n";
  cout << " | |       - Description: Inspiration for creating ASCII art in console-based programs.          | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 18. **tsjensen ASCII Art for Scroll UI:**                                                   | |\n";
  cout << " | |      - Source: tsjensen                                                                     | |\n";
  cout << " | |      - Description: Contribution to the creation of a scroll UI using ASCII art.            | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | | 19. **ASCII Art Archives for Good ASCII Art Ideas:**                                        | |\n";
  cout << " | |      - Source: ASCII Art Archives bearholidng a board, crown, scroll, keyboard.             | |\n";
  cout << " | |      - Description: Reference for visually appealing ASCII art in the project.              | |\n";
  cout << "Press Enter:.-> ";
  cin.get();
  cout << " | |                                                                                             | |\n";
  cout << " | |                  __^__                                               __^__                  | |\n";
  cout << " | |                 ( ___ )---------------------------------------------( ___ )                 | |\n";
  cout << " | |                  | / | Special Thanks to Sir Josh!                   | \\ |                  | |\n";
  cout << " | |                  | / |                                               | \\ |                  | |\n";
  cout << " | |                  | / |     For Teaching us and help us to build      | \\ |                  | |\n";
  cout << " | |                  | / |    our knowledge  and  logic in programming   | \\ |                  | |\n";
  cout << " | |                  | / |   without  him we will not be able to create  | \\ |                  | |\n";
  cout << " | |                  | / |            this project in reality.           | \\ |                  | |\n";
  cout << " | |                  | / |                                               | \\ |                  | |\n";
  cout << " | |                  | / |                                               | \\ |                  | |\n";
  cout << " | |                  | / |                                               | \\ |                  | |\n";
  cout << " | |                  | / |                                               | \\ |                  | |\n";
  cout << " | |                 (_____)---------------------------------------------(_____)                 | |\n";
  cout << " | |                                                                                             | |\n";
  cout << " | |_____________________________________________________________________________________________| |\n";
  cout << " |_________________________________________________________________________________________________|\n";
  cout << "                    )__________|_                                       |__________(\n";
  cout << "                   |            |                                      |            |\n";
  cout << "                   |____________|                                      |____________|\n";
  cout << "                     ),-----.(                                            ),-----.(\n";
  cout << "                   ,'   ==.   \\                                          /  .==    `.\n";
  cout << "                  /            )                                        (            \\\n";
  cout << "                  `==========='                                         `===========\'\n";
  cout << "Scroll to See the Content|^|\n";
}
void displayAbout() {
  cout << endl;
  cout << endl;
  cout << endl;
  cout << " |**************************************************************************|\n";
  cout << "|*                    Welcome to our CSDC 101 project                       *|\n";
  cout << "|*  This game has been crafted exclusively for educational purposes within  *|\n";
  cout << "|*     the CSDC 101 subject, bingo game is free from any elements related   *|\n";
  cout << "|*                    to gambling or illegal activities                     *|\n";
  cout << "|*                                                                          *|\n";
  cout << "|*                                                                          *|\n";
  cout << "|*                                                                          *|\n";
  cout << "|*                                                                          *|\n";
  cout << "|*                                                                          *|\n";
  cout << ".****************************************************************************.\n";
  cin.get();
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << SetConsoleTextAttributeCyan;
  cout << "._____.                                                                ._____.\n";
  cout << "(__  _)._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-(__  _)\n";
  cout << "|  B  |                                                                |  B  |   \n";
  cout << "|  I  |                                                                |  I  |   \n";
  cout << "|  N  |" << SetConsoleTextAttributeRed "   /\\^/`\\                                                       |  N  |   \n";
  cout << "|  G  |" << SetConsoleTextAttributeRed "  | \\/   |                                                      |  G  |            \n";
  cout << "|  O  |" << SetConsoleTextAttributeRed "  | |    |" << SetConsoleTextAttributeBlue "                Bingo Project                         "
                                                                                              "|  O  |              \n";
  cout << "|     |" << SetConsoleTextAttributeRed "  \\ \\   /" << SetConsoleTextAttributeYellow "                                                _ _    |     |                  \n";
  cout << "|  P  |" << SetConsoleTextAttributeRed "  '\\\\//'" << SetConsoleTextAttributeYellow "                                               _{ ' }_  |  P  |              \n";
  cout << "|  R  |" << SetConsoleTextAttributeGreen "    ||                    Submitted by:" << SetConsoleTextAttributeYellow "               { `.!.` } |  R  |                  \n";
  cout << "|  O  |" << SetConsoleTextAttributeGreen "    ||               John Francis C. Villareal" << SetConsoleTextAttributeYellow "        ',_/Y\\_,  |  O  |                            \n";
  cout << "|  J  |" << SetConsoleTextAttributeGreen "    ||  ," << SetConsoleTextAttributeYellow "                                               {_,_}   |  J  |                      \n";
  cout << "|  E  |" << SetConsoleTextAttributeGreen "|\\  ||  |\\                                                |     |  E  |                \n";
  cout << "|  C  |" << SetConsoleTextAttributeGreen "| | ||  | |               Submitted to:                 (\\|  /) |  C  |            \n";
  cout << "|  T  |" << SetConsoleTextAttributeGreen "| | || / /            Sir Joshua C. Martinez             \\| //  |  T  |       \n";
  cout << "|     |" << SetConsoleTextAttributeGreen " \\ \\||/ /                                                 |//   |     |    \n";
  cout << "|     |" << SetConsoleTextAttributeGreen "  `\\\\//`   \\\\   \\./    \\\\ /     //   \\\\./ \\\\ // \\\\        |/ /" << SetConsoleTextAttributeBlack "  |     |    \n";
  cout << "|     |" << SetConsoleTextAttributeGreen "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|     |\n";
  cout << "|     |" << SetConsoleTextAttributeGreen "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|     |\n";
  cout << "(_ ___)-._.-= -._.-= -._.-= -._.-= -._.-= -._.-= -._.-= -._.-= -._.-._.(_ ___)\n ";
  cout << SetConsoleTextAttributeBlack;
}
void displayLearnHowToPlay() {
  cout << SetConsoleTextAttributeGreen "Game Overview:" SetConsoleTextAttributeBlack << endl;
  cout << "Bingo is a game of chance played with randomly drawn numbers." << endl;
  cout << "Each player is given a Bingo card with a 5x5 grid of numbers." << endl;
  cout << "The goal is to be the first player to complete a specific pattern on the card." << endl;
  cout << "User can modify the game by going to game options" << endl;
  cout << "User is capable of Modifying bingo card " << endl;
  cout << "User is capable of modifying bingo Pattern" << endl;

  cout << SetConsoleTextAttributeGreen "\nSetup:" SetConsoleTextAttributeBlack << endl;
  cout << "The game can be played with up to 4 players only." << endl;
  cout << "The Bingo card consists of five columns, labeled B, I, N, G, and O." << endl;
  cout << "The center square of the grid is marked with \'[X]\'." << endl;

  cout << SetConsoleTextAttributeGreen "\nCard Generation:" SetConsoleTextAttributeBlack << endl;
  cout << "The game generates Bingo cards automatically or manually, depending on the setting the default is automatic." << endl;
  cout << "The cards contain random numbers within specified ranges for each column (B, I, N, G, O)." << endl;

  cout << SetConsoleTextAttributeGreen "\nGame Start:" SetConsoleTextAttributeBlack << endl;
  cout << "The players need to enter their name after starting the game if the player start the game in 2nd time they need to press x or Done to stop " << endl;
  cout << "The game begins with the host called number sorcerer for drawing random numbers one by one." << endl;
  cout << "Each number is displayed, and players mark the called numbers on their Bingo cards by replacing the numbers with 'X'." << endl;

  cout << SetConsoleTextAttributeGreen "\nWinning Patterns:" SetConsoleTextAttributeBlack << endl;
  cout << "Players aim to complete specific patterns on their cards to win." << endl;
  cout << "Patterns can include horizontal lines, vertical lines, diagonal lines for the default mode and full house bingo in Hard Mode" << endl;

  cout << SetConsoleTextAttributeGreen "\nChecking for a Win:" SetConsoleTextAttributeBlack << endl;
  cout << "After each number is drawn, the program checks if any player has completed the winning pattern." << endl;
  cout << "If a player completes the pattern, they display 'Bingo with the winning card' and win the round." << endl;
  cout << "Press enter to see the winning pattern-> " << endl;
  cin.get();

  cout << "Default Mode: Horizontal Win" << endl;

  cout << ".___________________________________.\n";
  cout << "|B       I       N       G       O  |\n";
  cout << "|___________________________________|\n";

  cout << "|" << SetConsoleTextAttributeGreen "[X]     [X]     [X]     [X]    [x]" << SetConsoleTextAttributeBlack << " |\n";

  cout << "| 15     16       33      58     75 |\n";
  cout << "| 13     18      [X]      48     72 |\n";
  cout << "| 4      19       36      49     67 |\n";
  cout << "|" << SetConsoleTextAttributeGreen "[X]     [X]     [X]     [X]    [x]" << SetConsoleTextAttributeBlack << " |\n";
  cout << "|___________________________________|\n";

  cout << "Press enter to see the winning patter-> " << endl;

  cout << "Default Mode: Vertical Win" << endl;
  cout << ".___________________________________.\n";
  cout << "| B      I         N       G      O |\n";
  cout << "|___________________________________|\n";

  cout << "|" << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack "    20        31      50    " << SetConsoleTextAttributeGreen "[X] " << SetConsoleTextAttributeBlack "|\n";

  cout << "|" << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack "    16        33      58    " << SetConsoleTextAttributeGreen "[X] " << SetConsoleTextAttributeBlack "|\n";
  cout << "|" << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack "    18        [X]     48    " << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack " |\n";
  cout << "|" << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack "    19        36      49    " << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack " |\n";
  cout << "|" << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack "    26        40      54    " << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack " |\n";
  cout << "|___________________________________|\n\n";

  cout << "Press enter to see the winning pattern-> " << endl;
  cin.get();

  cout << "Default Mode: Diagonal Win" << endl;
  cout << ".___________________________________.\n";
  cout << "| B       I       N        G      O |\n";
  cout << "|___________________________________|\n";
  cout << "|" << SetConsoleTextAttributeGreen "[X]" << SetConsoleTextAttributeBlack << "      20      31      50    " << SetConsoleTextAttributeGreen "[X] " << SetConsoleTextAttributeBlack << "|\n";
  cout << "| 15      " << SetConsoleTextAttributeGreen "[X] " << SetConsoleTextAttributeBlack << "    33      " << SetConsoleTextAttributeGreen "[X] " << SetConsoleTextAttributeBlack << "   75"
       << " |\n";
  cout << "| 13      18" << SetConsoleTextAttributeGreen "      [X]" << SetConsoleTextAttributeBlack << "     48     72 |\n";
  cout << "| 4       " << SetConsoleTextAttributeGreen "[X] " << SetConsoleTextAttributeBlack << "    36" << SetConsoleTextAttributeGreen "      [X]" << SetConsoleTextAttributeBlack << "    67 |\n";
  cout << "|" SetConsoleTextAttributeGreen "[X] " << SetConsoleTextAttributeBlack << "     26      40      54" << SetConsoleTextAttributeGreen "    [X]" << SetConsoleTextAttributeBlack << " |\n";
  cout << "|___________________________________|\n";

  cout << "Press enter to see the winning pattern-> " << endl;
  cin.get();

  cout << "Hard Mode: Full House Win" << endl;

  cout << ".___________________________________.\n";
  cout << "|B       I       N       G       O  |\n";
  cout << "|___________________________________|\n";

  cout << "|" << SetConsoleTextAttributeGreen "[X]     [X]    [X]     [X]     [x]" << SetConsoleTextAttributeBlack << " |\n";

  cout << "|" << SetConsoleTextAttributeGreen "[X]     [X]    [X]     [X]     [X]" << SetConsoleTextAttributeBlack << " |\n";
  cout << "|" << SetConsoleTextAttributeGreen "[X]     [X]    [X]     [X]     [X]" << SetConsoleTextAttributeBlack << " |\n";
  cout << "|" << SetConsoleTextAttributeGreen "[X]     [X]    [X]     [X]     [X]" << SetConsoleTextAttributeBlack << " |\n";
  cout << "|" << SetConsoleTextAttributeGreen "[X]     [X]    [X]     [X]     [x]" << SetConsoleTextAttributeBlack << " |\n";
  cout << "|___________________________________|\n";

  cout << SetConsoleTextAttributeGreen "\nGame Rounds:" SetConsoleTextAttributeBlack << endl;
  cout << "The game can have multiple rounds with different winning patterns." << endl;
  cout << "Rounds continue until one of the players wins." << endl;

  cout << SetConsoleTextAttributeGreen "\nGame Modes:" SetConsoleTextAttributeBlack << endl;
  cout << "The game has different modes, including automatic number generation or manual number ny pressing enter." << endl;
  cout << "Players can choose from various Bingo card designs by going to game options." << endl;

  cout << SetConsoleTextAttributeGreen "\nGame End:" SetConsoleTextAttributeBlack << endl;
  cout << "The game stops when a player wins" << endl
       << endl;
}
void displayPattern1() {

  cout << "\nDesign 1: (Middle Stick) Press [1] to See More \n";
  cout << ".___________________________________.\n";
  cout << "|B       I       N       G       O  |\n";
  cout << "|___________________________________|\n";
  cout << SetConsoleTextAttributeGreen;
  cout << "-[X]-   -[24]-  -[X]-   -[53]-  -[X]-\n";
  cout << "-[X]-   -[29]-  -[33]-  -[57]-  -[68]-\n";
  cout << "-[10]-  -[X]-   -[X]-   -[X]-   -[63]-\n";
  cout << "-[12]-  -[22]-  -[32]-  -[46]-  -[66]-\n";
  cout << "-[14]-  -[X]-   -[X]-   -[56]-  -[X]-\n";
  cout << SetConsoleTextAttributeBlack;
  cout << "|___________________________________| \n\n";
}
void displayPattern2() {
  cout << "Design 2: (Chicken Wings) Press [1] to See More \n";
  cout << ".___________________________________.\n";
  cout << "|B       I       N       G       O  | \n";
  cout << "|___________________________________|\n";
  cout << SetConsoleTextAttributeYellow;
  cout << "<X>     20      39      50        70\n";
  cout << "<X>     <X>     <X>     <X>       65\n";
  cout << "<X>     <X>     <X>     <X>       65\n";
  cout << "9       27      <X>     54        75\n";
  cout << "<X>     <X>     43      56       [X]\n";
  cout << "<X>     <X>     <X>     <X>       68\n";
  cout << SetConsoleTextAttributeBlack;
  cout << "|__________________________________|\n";
}
void displayPattern3() {
  cout << "Design 3:(Red Spike) Press [1] to See More\n";
  cout << ".___________________________________.\n";
  cout << "|B       I       N       G       O  |\n";
  cout << "|___________________________________|\n";
  cout << SetConsoleTextAttributeRed;
  cout << "\\X/     \\16/    \\37/    \\55/    \\63/\n";
  cout << "\\X/     \\X/     \\40/    \\56/    \\X/\n";
  cout << "\\14/    \\24/    \\X/     \\53/    \\71/\n";
  cout << "\\1/     \\26/    \\35/    \\46/    \\X/\n";
  cout << "\\9/     \\21/    \\X/     \\X/     \\61/\n";
  cout << SetConsoleTextAttributeBlack;
  cout << "|__________________________________|\n";
}
void displayDesignErrorHandling() {
  cout << "\n\n  :-----[Error! Please Enter a Valid Number ]--:\n";
  cout << "  |                                            |\n";
  cout << "  |  [1]->Design 1 -[]-          _             |\n";
  cout << "  |  [2]->Design 2  [ ]         | |            |\n";
  cout << "  |  [3]->Design 3  \\//         |||           |\n";
  cout << "  |  [4]->Design 4  ( )         |_|            |\n";
  cout << "  |                             (_)            |\n";
  cout << "  |                                            |\n";
  cout << "  |____________________________________________|\n";
  cout << "  |_/--> ";
}
void displayPattern4() {
  cout << "Design 4: (ParenX) Press [1] to See More\n";
  cout << ".___________________________________.\n";
  cout << "|B       I       N       G       O  |\n";
  cout << "|___________________________________|\n";
  cout << SetConsoleTextAttributeCyan;
  cout << "(2)     (28)    (X)     (X)     (X)\n";
  cout << "(14)    (X)     (41)    (59)    (70)\n";
  cout << "(8)     (X)     (X)     (X)     (62)\n";
  cout << "(3)     (16)    (X)     (49)    (X)\n";
  cout << "(X)     (X)     (39)    (58)    (X)\n";
  cout << SetConsoleTextAttributeBlack;
  cout << "|__________________________________|\n";
}
void displayCrownWinner() {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(h, 14);
  cout << endl;
  cout << "             __  \\N/  __" << endl;
  cout << "          __ \\I) |*| (G/ __" << endl;
  cout << "       __ \\B) \\*\\|O|/*/ (O/ __" << endl;
  cout << "       \\*)_\\*\\_|*|*/_/\\*_/ (*/" << endl;
  cout << "        \\-o-=-o-=-O-=-o-=-o-/" << endl;
  cout << "         \\_________________/";
  SetConsoleTextAttribute(h, 7);
}
void displayErrorHandlingBack() {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(h, 10);
  cout << "\n\n  :-----[Error! Please Enter a Valid Number ]--:\n"
          "  |                                            |\n"
          "  |[1]->Press 1 to back to menu  _             |\n"
          "  |                             | |            |\n"
          "  |                             |||            |\n"
          "  |                             |_|            |\n"
          "  |                             (_)            |\n"
          "  |                                            |\n"
          "  |____________________________________________|\n"
          "  |_/--> ";
  SetConsoleTextAttribute(h, 7);
}
void displayRating() {
  int stars;

  cout << "Rate me 1 - 5: ";
  while (!(cin >> stars) || stars < 1 || stars > 5 || cin.get() != '\n')
  {
    cout << "Please enter a valid rating 1-5!-.> ";
    cin.clear();
    cin.ignore(123, '\n');
  }

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  switch (stars)
  {
  case 1:
    cout << "You successfully gave the game 1 star!\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "     /\\\n"
         << "____/  \\____\n"
         << "\\          /\n"
         << " >        <\n"
         << "/___    ___\\\n"
         << "    \\  /\n"
         << "     \\/\n";
    SetConsoleTextAttribute(hConsole, 7);
    break;
  case 2:
    cout << "You successfully gave the game 2 stars!\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "     /\\                /\\                                     \n"
         << "____/  \\____      ____/  \\____                            \n"
         << "\\          /      \\          /                                    \n"
         << " >        <        >         <                                         \n"
         << "/___    ___\\      /___    ___\\                                 \n"
         << "    \\  /              \\  /                              \n"
         << "     \\/                \\/                                 \n";
    SetConsoleTextAttribute(hConsole, 7);
    break;
  case 3:
    cout << "You successfully gave the game 3 stars!\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "     /\\                /\\                 /\\                           \n"
         << "____/  \\____      ____/  \\____       ____/  \\____                      \n"
         << "\\          /      \\          /       \\          /                              \n"
         << " >        <        >         <       >         <                               \n"
         << "/___    ___\\      /___    ___\\       /___    ___\\                          \n"
         << "    \\  /              \\  /               \\  /               \n"
         << "     \\/                \\/                 \\/                \n";
    SetConsoleTextAttribute(hConsole, 7);
    break;
  case 4:
    cout << "You successfully gave the game 4 stars!\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "     /\\                /\\                 /\\                 /\\                                   \n"
         << "____/  \\____      ____/  \\____       ____/  \\____       ____/  \\____                                  \n"
         << "\\          /      \\          /       \\          /       \\          /                                    \n"
         << " >        <        >         <       >         <         >         <                                       \n"
         << "/___    ___\\      /___    ___\\       /___    ___\\       /___    ___\\                                         \n"
         << "    \\  /              \\  /               \\  /               \\  /                                       \n"
         << "     \\/                \\/                 \\/                 \\/                                   \n";
    SetConsoleTextAttribute(hConsole, 7);
    break;
  case 5:
    cout << "You successfully gave the game 5 stars!\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "     /\\                /\\                 /\\                 /\\                /\\                       \n"
         << "____/  \\____      ____/  \\____       ____/  \\____       ____/  \\____      ____/  \\____                            \n"
         << "\\          /      \\          /       \\          /       \\          /      \\          /                              \n"
         << " >        <        >         <       >         <         >         <       >         <                                \n"
         << "/___    ___\\      /___    ___\\       /___    ___\\       /___    ___\\      /___    ___\\                                    \n"
         << "    \\  /              \\  /               \\  /               \\  /              \\  /                          \n"
         << "     \\/                \\/                 \\/                 \\/                \\/                   \n";
    SetConsoleTextAttribute(hConsole, 7);

    break;
  }
}
void displayGoodbyeExit() {
  cout << SetConsoleTextAttributeYellow;
  cout << "                      _ ._  _ , _ ._" << endl;
  cout << "                    (_ ' ( `  )_  .__)" << endl;
  cout << "                  ( (  (    )   `)  )_)" << endl;
  cout << "                 (__(_   (_ . _) _),__)" << endl;
  cout << "                     `~~`\\ ' . /`~~`" << endl;
  cout << "                     ,::: ;   ; :::," << endl;
  cout << "                    ':::::::::::::::'" << endl;
  cout << SetConsoleTextAttributeGreen "._________________________/_  _\\__________________________." << endl;
  cout << "|                                                         |" << endl;
  cout << "|                Hi and Thank You, Goodbye :<             |" << endl;
  cout << "|_________________________________________________________|" << endl;
  cout << SetConsoleTextAttributeBlack;
}
void displayGameSettingMenu() {
  cout << SetConsoleTextAttributeBlue;
  cout << "(************************************)\n";
  cout << "(*     |Welcome to Game Settings|   *)\n";
  cout << "(*                                  *)\n";
  cout << "(* [1] Modify Generation of Card    *)\n";
  cout << "(* [2] Modify Bingo Card Format     *)\n";
  cout << "(* [3] Modify Game Mode             *)\n";
  cout << "(************************************)\n";
  cout << SetConsoleTextAttributeBlack;
}
void displayErrorHandlingMod() {
  int errorHandlerModifier;

  cout << "Please Press 1 Please ";

  while (!(cin >> errorHandlerModifier) || errorHandlerModifier != 1 || cin.get() != '\n')
  {
    cout << "You are Allowed to Press 1.-> ";
    cin.clear();
    cin.ignore(123, '\n');
  }
}
void displayGuntingLineBreaker() {
  cout << SetConsoleTextAttributeRed;
  cout << "\n-------8<------------------------------------------------------------------------------------------------------------------------------\n\n";
  cout << SetConsoleTextAttributeBlack;
}
void displayKeyBoard1() {
  cout << SetConsoleTextAttributeWhite;
  cout << "\n\n. -------------------------------------------------------------------." << endl;
  cout << "| [Esc] [F1][F2][F3][F4][F5][F6][F7][F8][F9][F0][F10][F11][F12] o o o|" << endl;
  cout << "|      |                                                             |" << endl;
  cout << "| [`]" << SetConsoleTextAttributeGreen "[1]" << SetConsoleTextAttributeWhite "[2][3][4][5][6][7][8][9][0][-][=][_<_] [I][H][U] [N][/][*][-]|" << endl;
  cout << "| [|-][Q][W][E][R][T][Y][U][I][O][P][{][}] | | [D][E][D] [7][8][9]|+||" << endl;
  cout << "| [CAP][A][S][D][F][G][H][J][K][L][;]['][#]|_|           [4][5][6]|_||" << endl;
  cout << "| [^][\\][Z][X][C][V][B][N][M][,][.][/][__^__]     [^]    [1][2][3]||||" << endl;
  cout << "| [c]   [a][________________________][a]   [c] [<][V][>] [ 0  ][.]|_||" << endl;
  cout << "`--------------------------------------------------------------------' " << endl;
}
void displayMayBug() {
  cout << "Hindi Tumigil May Bug:<";
}
