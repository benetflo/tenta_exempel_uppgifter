// Fråga 1
// Skapa ett program som hanterar en enkel betygskalkylator för studenter:

// Skapa en klass som heter Student med attribut för namn och tre provresultat
// Inkludera metoder för att:
// Beräkna genomsnittspoäng
// Avgöra om studenten är godkänd (genomsnitt >= 60)
// Visa all studentinformation
// Skapa ett huvudprogram som skapar minst två Student-objekt och demonstrerar all funktionalitet

#include <string>
#include <iostream>
#include <vector>



class Student{

    private:
        std::string name;
        std::vector<float> grades;
    
    public:

        Student() {}
        Student(std::string name, std::vector<float> grades) : name(name), grades(grades) {}

        void setName(std::string inp_name){
            
            name = inp_name;
        }
        void addGrade(float grade){

            grades.push_back(grade);
            std::cout << grade << " was added to students list of grades\n";
        }

        void printInfo(){

            std::cout << "Students name: " << name << "\n";
            std::cout << "Student grades: ";
            for(float g : grades){
                
                std::cout << g << " ";
            }
            std::cout << std::endl;
        }

        void checkIfPassed(){

            float temp_c = 0.0f;

            for(float g : grades){
                
                temp_c += g;
            }
            float average = temp_c / grades.size();

            if(temp_c >= 60){
                std::cout << "Student has passed.\n";
                std::cout << "Average score: " << average << "\n";
            }
            else{
                std::cout << "Student has not passed.\n";
                std::cout << "Average score: " << average << "\n";
            }
        }
};

int main(int argc, char const *argv[])
{
    // Här under är två olika sätt på att lägga till info
    
    Student stud1;
    Student stud2("Erik", {37.5, 52.7, 77.9});

    stud1.setName("Tommy");
    stud1.addGrade(16.9);
    stud1.addGrade(10.6);
    stud1.addGrade(21.8);

    // Skriver ut info om elever och om de är godkända
    std::cout << "\n";
    stud1.printInfo();
    stud1.checkIfPassed();
    std::cout << "\n";
    stud2.printInfo();
    stud2.checkIfPassed();

    return 0;
}
