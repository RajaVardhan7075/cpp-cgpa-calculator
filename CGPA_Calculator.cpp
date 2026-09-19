#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

double gradePoint(string grade) {
    for (char &c : grade)
        c = toupper(c);

    if (grade == "O")  return 10;
    if (grade == "A+") return 9;
    if (grade == "A")  return 8;
    if (grade == "B+") return 7;
    if (grade == "B")  return 6;
    if (grade == "C")  return 5;
    if (grade == "D")  return 4;

    return -1;
}

int main() {

    int semester, n;
    double totalPoints = 0, totalCredits = 0;

    string grade[50];
    double credits[50], points[50];

    cout << "\n============================================\n";
    cout << "             CGPA CALCULATOR\n";
    cout << "============================================\n";

    cout << "Enter Semester: ";
    cin >> semester;

    cout << "Enter Number of Subjects: ";
    cin >> n;

    cout << "\nGrade Scale: O=10  A+=9  A=8  B+=7\n";
    cout << "             B=6   C=5   D=4\n";

    for (int i = 0; i < n; i++) {

        cout << "\nSubject " << i + 1 << endl;

        cout << "Grade   : ";
        cin >> grade[i];

        points[i] = gradePoint(grade[i]);

        while (points[i] == -1) {
            cout << "Invalid grade! Enter again: ";
            cin >> grade[i];
            points[i] = gradePoint(grade[i]);
        }

        cout << "Credits : ";
        cin >> credits[i];

        while (credits[i] <= 0) {
            cout << "Invalid credits! Enter again: ";
            cin >> credits[i];
        }

        totalPoints += points[i] * credits[i];
        totalCredits += credits[i];
    }

    double cgpa = totalPoints / totalCredits;

    cout << "\n============================================\n";
    cout << "           SEMESTER " << semester << " RESULT\n";
    cout << "============================================\n";

    cout << left << setw(15) << "Subject"
         << setw(10) << "Grade"
         << setw(10) << "Credits" << endl;

    cout << "--------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << ("Subject " + to_string(i + 1))
             << setw(10) << grade[i]
             << setw(10) << credits[i] << endl;
    }

    cout << "--------------------------------------------\n";

    cout << "Total Credits : " << totalCredits << endl;

    cout << fixed << setprecision(2);
    cout << "CGPA          : " << cgpa << endl;

    cout << "\n";

    if (cgpa >= 9)
        cout << "Excellent! Keep up the great work!\n";
    else if (cgpa >= 8)
        cout << "Great job! Keep pushing forward!\n";
    else if (cgpa >= 7)
        cout << "Good work! Stay consistent!\n";
    else if (cgpa >= 6)
        cout << "Good progress! Aim a little higher!\n";
    else
        cout << "Keep going! You can improve with consistency!\n";

    cout << "\n============================================\n";
    cout << "       Keep Learning. Keep Improving.\n";
    cout << "============================================\n";

    return 0;
}
