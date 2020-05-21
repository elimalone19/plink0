#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main () {
  int userInt = 0;
  double chipSlot = 40.0;
  const double RANDOM_SEED = 42.0;
  srand(RANDOM_SEED);
  const int PATH_NUM = 13;
  const double SMALL_WINNINGS = 100.00;
  const double NO_WINNINGS = 0.00;
  const double MEDIUM_WINNINGS = 500.00;
  const double LARGE_WINNINGS = 1000.00;
  const double HUGE_WINNINGS = 10000.00;
  int numChips = 0;
  double totalSum = 0.00;
  double avgWinnings = 0;
  int chipSlotHold = 0;


  cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl;
  cout << endl;

  cout << "Enter your selection now: ";
  cin >> userInt;
  cout << endl;

  if (userInt == 4){
    cout << "Goodbye!" << endl;
  }
  while (userInt != 4) {
    if (userInt <= 0 || userInt > 4) {
      cout << "Invalid selection. Enter 3 to see options." << endl;
      cout << "Enter your selection now: " << endl;
      cin >> userInt;
    }
    if (userInt == 3) {
      cout << "Menu: Please select one of the following options: " << endl;
      cout << endl;
      cout << "1 - Drop a single chip into one slot" << endl;
      cout << "2 - Drop multiple chips into one slot" << endl;
      cout << "3 - Show the options menu" << endl;
      cout << "4 - Quit the program" << endl;
      cout << endl;
      cout << "Enter your selection now: " << endl;
      cin >> userInt;
      cout << endl;

      if (userInt <= 0 || userInt > 4) {
        cout << "Invalid selection. Enter 3 to see options." << endl;
        cin >> userInt;
      }
    }
    if (userInt == 4) {
      cout << "Goodbye!" << endl;
      return 0;
    }

    if (userInt == 1) {
      cout << "*** Drop a single chip ***" << endl;
      cout << endl;
      cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
      cin >> chipSlot;
      cout << endl;
      if (chipSlot < 0.0 || chipSlot > 8.0) {
        cout << "Invalid slot." << endl;
        cout << endl;
      }
      if (chipSlot >= 0.0 && chipSlot <= 8.0) {
        cout << "*** Dropping chip into slot " << fixed << setprecision(0) << chipSlot << " ***" << endl;
        cout << endl;
        cout << "Path: [";

        for (int i = 0.0; i < PATH_NUM - 1; ++i) {
          cout << fixed << setprecision(1) << chipSlot;
          if (chipSlot == 0) {
            chipSlot = chipSlot + 0.5;
          }
          else if (chipSlot != 0 && chipSlot != 8) {
            if (rand() % 2 == 0.0) {
              chipSlot = chipSlot - 0.5;
            }
            else {
              chipSlot = chipSlot + 0.5;
            }
          }
          else if (chipSlot == 8) {
            chipSlot = chipSlot - 0.5;
          }
          if (i < PATH_NUM - 1) {
            cout << ", ";
          }
        }
        cout << chipSlot << "]" << endl;
        cout << "Winnings: $";
        if (chipSlot == 0 || chipSlot == 8) {
          cout << fixed << setprecision(2) << SMALL_WINNINGS << endl;
        }
        else if (chipSlot == 1 || chipSlot == 7) {
          cout << fixed << setprecision(2) << MEDIUM_WINNINGS << endl;
        }
        else if (chipSlot == 2 || chipSlot == 6) {
          cout << fixed << setprecision(2) << LARGE_WINNINGS << endl;
        }
        else if (chipSlot == 3 || chipSlot == 5) {
          cout << fixed << setprecision(2) << NO_WINNINGS << endl;
        }
        else if (chipSlot == 4) {
          cout << fixed << setprecision(2) << HUGE_WINNINGS << endl;
        }
      }
      cout << "Enter your selection now: " << endl;
      cin >> userInt;
      cout << endl;
    }
    if (userInt == 2) {
      cout << "*** Drop multiple chips ***" << endl;
      cout << "How many chips do you want to drop (>0)?";
      cin >> numChips;
      cout << endl;
      if (numChips <= 0) {
        cout << "Invalid number of chips." << endl << endl;
        cout << "Enter your selection now: " << endl;
        cin >> userInt;
        cout << endl;
        continue;
      }
      cout << "Which slot do you want to drop the chip in (0-8)?";
      cin >> chipSlot;
      chipSlotHold = chipSlot;
      cout << endl;
      if (numChips > 0 && chipSlot >= 0 && chipSlot <= 8) {
        cout << "Total winnings on " << numChips << " chips: $";
        for (int i = 0.0; i < numChips; ++i) {
          for (int j = 0.0; j < PATH_NUM - 1; ++j) {
            if (chipSlot == 0) {
              chipSlot = chipSlot + 0.5;
            }
            else if (chipSlot != 0 && chipSlot != 8) {
              if (rand() % 2 == 0.0) {
                chipSlot = chipSlot - 0.5;
              }
              else {
                chipSlot = chipSlot + 0.5;
              }
            }
            else if (chipSlot == 8) {
              chipSlot = chipSlot - 0.5;
            }
          }
          if (chipSlot == 0 || chipSlot == 8) {
            totalSum = totalSum + SMALL_WINNINGS;
          }
          else if (chipSlot == 1 || chipSlot == 7) {
            totalSum = totalSum + MEDIUM_WINNINGS;
          }
          else if (chipSlot == 2 || chipSlot == 6) {
            totalSum = totalSum + LARGE_WINNINGS;
          }
          else if (chipSlot == 3 || chipSlot == 5) {
            totalSum = totalSum + NO_WINNINGS;
          }
          else if (chipSlot == 4) {
            totalSum = totalSum + HUGE_WINNINGS;
          }    
          chipSlot = chipSlotHold;
        }  
        cout << fixed << setprecision(2) << totalSum << endl;
        avgWinnings = totalSum / numChips;
        totalSum = 0;
        cout << "Average winnings per chip: $" << avgWinnings << endl << endl;
        cout << "Enter your selection now: " << endl;
        cin >> userInt;
        cout << endl;
      }    
      else if (chipSlot < 0 || chipSlot > 8) {
        cout << "Invalid slot." << endl << endl;
        cout << "Enter your selection now: ";
        cin >> userInt;
        cout << endl;
      }
    }
  }
  if (userInt == 4){
    cout << "Goodbye!" << endl;
  }
  return 0;
}
