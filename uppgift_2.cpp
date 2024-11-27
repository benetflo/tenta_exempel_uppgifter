#include <vector>
#include <iostream>
#include <algorithm>


// Fråga 2
// Skriv ett program som läser in tal från användaren tills de matar in -1. Programmet ska:

// Lagra talen i en vektor
// Beräkna och visa:
// Summan av alla tal
// Medelvärdet av talen
// Det största och minsta inmatade talet

float sum(std::vector<float> &numbers)
{
    float temp = 0.0f;

    for(float n : numbers){
        
        temp += n;
    }
    return temp;
}

float average(float sum, std::vector<float> &numbers)
{
    return sum / numbers.size();
}

int main(int argc, char const *argv[])
{
    
    std::vector<float> numbers;

    float num;

    while(1)
    {
        std::cout << "Add number: ";
        std::cin >> num;
        
        if(num != -1){
            numbers.push_back(num);        
        }
        else
            break;
    }
    
    float sum_of_nums = sum(numbers);
    float average_of_nums = average(sum_of_nums, numbers);
    auto highest_lowest = std::minmax_element(numbers.begin(), numbers.end()); 
    

    std::cout << "\n";
    std::cout << "Sum of numbers: " << sum_of_nums << "\n";
    std::cout << "Average is: " << average_of_nums << "\n";
    std::cout << "Largest number is: " << *highest_lowest.second << "\n";
    std::cout << "Lowest number is: " << *highest_lowest.first << "\n";


    return 0;
}
