#include<iostream>
#include<string>
#include<limits>
using namespace std;

// Global vote counters
int total_votes = 0;
int tlp_votes = 0, pti_votes = 0, pmln_votes = 0, ppp_votes = 0;

// Arrays to store voter data
string name[50], f_name[50], cnic[50], mobile_no[50];
int age[50];

// Function to check digits-only input (no C++11 syntax)
bool isDigitsOnly(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

struct voting {
    int i;

    voting() {
        i = 0;
    }

    void intro() {
        cout << "\n\t*********************************************";
        cout << "\n\t**         Voting System                   **";
        cout << "\n\t**         (1) Rimsha Shehzadi             **";
        cout << "\n\t**         (2) Sana Aslam                  **";
        cout << "\n\t*********************************************\n";
    }

    void info() {
    again:
        cout << "\n\t\t\tEnter your First Name: ";
        cin >> name[i];

        cout << "\n\t\t\tEnter your Father Name: ";
        cin >> f_name[i];

        cout << "\n\t\t\tEnter your CNIC (13 digits): ";
        cin >> cnic[i];
        if (cnic[i].length() != 13 || !isDigitsOnly(cnic[i])) {
            cout << "\nInvalid CNIC. Try again.";
            return;
        }

        for (int x = 0; x < i; x++) {
            if (cnic[i] == cnic[x]) {
                cout << "\nYou have already voted.";
                return;
            }
        }

        cout << "\n\t\t\tEnter your Mobile Number (11 digits): ";
        cin >> mobile_no[i];
        if (mobile_no[i].length() != 11 || !isDigitsOnly(mobile_no[i])) {
            cout << "\nInvalid Mobile Number. Try again.";
            return;
        }

        cout << "\n\t\t\tEnter your Age: ";
        cin >> age[i];
        if (cin.fail() || age[i] < 18) {
            cout << "\nYou are under age or entered invalid input.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cout << "\n\t\t\t1 - TLP";
        cout << "\n\t\t\t2 - PTI";
        cout << "\n\t\t\t3 - PMLN";
        cout << "\n\t\t\t4 - PPP";
        cout << "\n\t\t\tEnter your choice (1-4): ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: cout << "\nYou voted TLP."; tlp_votes++; break;
            case 2: cout << "\nYou voted PTI."; pti_votes++; break;
            case 3: cout << "\nYou voted PMLN."; pmln_votes++; break;
            case 4: cout << "\nYou voted PPP."; ppp_votes++; break;
            default: cout << "\nInvalid choice. Vote wasted."; break;
        }

        total_votes++;
        i++;
    }

    void show_votes() {
        cout << "\nTotal Votes Cast: " << total_votes;
    }

    void show_party_votes() {
        cout << "\nVotes per Party:";
        cout << "\n1. TLP  = " << tlp_votes;
        cout << "\n2. PTI  = " << pti_votes;
        cout << "\n3. PMLN = " << pmln_votes;
        cout << "\n4. PPP  = " << ppp_votes;
    }

    void winner() {
        cout << "\n\n>>>> Winner of the Election <<<<";
        if (tlp_votes > pti_votes && tlp_votes > pmln_votes && tlp_votes > ppp_votes)
            cout << "\n>>> TLP is the Winner <<<";
        else if (pti_votes > tlp_votes && pti_votes > pmln_votes && pti_votes > ppp_votes)
            cout << "\n>>> PTI is the Winner <<<";
        else if (pmln_votes > pti_votes && pmln_votes > tlp_votes && pmln_votes > ppp_votes)
            cout << "\n>>> PMLN is the Winner <<<";
        else if (ppp_votes > pti_votes && ppp_votes > pmln_votes && ppp_votes > tlp_votes)
            cout << "\n>>> PPP is the Winner <<<";
        else
            cout << "\n>>> It's a Tie <<<";
    }

    void show_info() {
        for (int j = 0; j < i; j++) {
            cout << "\n-----------------------------";
            cout << "\nVoter #" << j + 1;
            cout << "\nName: " << name[j];
            cout << "\nFather Name: " << f_name[j];
            cout << "\nCNIC: " << cnic[j];
            cout << "\nMobile No: " << mobile_no[j];
            cout << "\nAge: " << age[j];
        }
        if (i == 0) {
            cout << "\nNo voters yet.";
        }
    }
};

int main() {
    voting V;
    V.intro();
    system("pause");
    system("cls");

    int a; // ? This was missing before

welcome:
    cout << "Welcome to Voting System\n";
    do {
    start:
        cout << "\n1 - Cast Vote";
        cout << "\n2 - Show Total Votes";
        cout << "\n3 - Show Votes per Party";
        cout << "\n4 - Show Winner";
        cout << "\n5 - Show Voter Details";
        cout << "\n6 - Clear Screen";
        cout << "\n0 - Exit";
        cout << "\nEnter your choice (0-6): ";
        cin >> a;

        switch (a) {
            case 1: V.info(); break;
            case 2: V.show_votes(); break;
            case 3: V.show_party_votes(); break;
            case 4: V.winner(); break;
            case 5: V.show_info(); break;
            case 6: system("cls"); goto welcome;
            case 0: break;
            default: cout << "\nInvalid Choice!";
        }
    } while (a != 0);

    return 0;
}

