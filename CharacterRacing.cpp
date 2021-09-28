#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

const int RACE_LENGTH = 60;
char continue_racing = 'y';
int score = 0;

int high_score = 0;

void character_racing() {
    cout << "\n";
    cout << "Enter a character to begin: ";
    char c;
    cin >> c;
    cout << "\n";
    cout << "Starting the race!\n";

    time_t start, finish, total;
    time(&start);

    int pos = RACE_LENGTH / 2;

    while (true) {
        cout << "START";
        for (int i = 0; i < RACE_LENGTH; ++i) {
            if (i == pos) {
                cout << c;
            }
            else {
                cout << ' ';
            }
        }
        cout << "FINISH\n";

        int m = rand() % 5 - 2;
        pos += m;

        if (pos < 1) {
            time(&finish);
            total = finish - start;
            cout << "---\n";
            cout << "You did not finish the race!\n";
            cout << "You took " << total << " s\n";
            cout << "You lose " << 100 - min(100, (int) total) << " points!\n";
            score -= 100 - min(100, (int) total);
            break;
        }
        if (pos > RACE_LENGTH - 1) {
            time(&finish);
            total = finish - start;
            cout << "---\n";
            cout << "Yay! You finished the race!\n";
            cout << "You took " << total << " s\n";
            cout << "You get " << 100 - min(100, (int) total) << " points!\n";
            score += 100 - min(100, (int) total);
            break;
        }
    }

    cout << "Your score is: " << score << "\n";
    if (score > high_score) {
        high_score = score;
    }

    cout << "Continue racing? (y/n): ";
    cin >> continue_racing;
}

int main() {

    srand(time(0));

    cout << "************************************\n";
    cout << "********* Character Racing *********\n";
    cout << "************************************\n";
    cout << "\n";
    cout << "Welcome to Character Racing!\n";

    while (continue_racing != 'n') {
        character_racing();
    }

    cout << "\n";
    cout << "Your final score is: " << score << "\n";
    cout << "Your highest score was: " << high_score << "\n";
    cout << "\nThanks for racing!\n";
    return 0;
}
