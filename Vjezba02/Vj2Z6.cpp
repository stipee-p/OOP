#include <iostream>
#include <string>

struct Student
{
    std::string ime;
    std::string jmbag;
    int godina;
    int ects;       
    double prosjek;
};

void print_student(Student& s)
{
    std::cout << s.ime << " (JMBAG: " << s.jmbag << "), godina: " << s.godina
              << ", ECTS: " << s.ects << ", prosjek: " << s.prosjek << "\n";
}

void slj_god(Student& s)
{
    ++s.godina;
}

void filter_students(Student s[], int n,
                     void (*action)(Student&),
                     bool (*cond)(const Student&))
{
    for (int i = 0; i < n; ++i)
        if (cond(s[i]))
            action(s[i]);
}

int main()
{
    Student students[] = {
        {"Ana Anic", "0123456789", 1, 60, 4.2},
        {"Ivo Ivic", "0123456790", 1, 0, 2.8},
        {"Marta Matic", "0123456791", 2, 45, 3.6},
        {"Luka Lukic", "0123456792", 1, 20, 3.1},
        {"Petra Peric", "0123456793", 3, 30, 3.9}
    };
    int n = sizeof(students) / sizeof(students[0]);

    auto pr_pol = [](const Student& s) {
        return s.godina == 1 && s.ects > 0;
    };
    auto prosjek = [](const Student& s) {
        return s.prosjek > 3.5;
    };
    auto ects_bod = [](const Student& s) {
        return s.ects >= 45;
    };

    std::cout << "Studenti prve godine s barem jednim polozenim ispitom:\n";
    filter_students(students, n, print_student, pr_pol);

    std::cout << "\nStudenti s prosjekom vecim od 3.5:\n";
    filter_students(students, n, print_student, prosjek);

    filter_students(students, n, slj_god, ects_bod);

    std::cout << "\nNakon povecanja godine (>= 45 ECTS):\n";
    filter_students(students, n, print_student,
                    [](const Student&) { return true; });

    return 0;
}
