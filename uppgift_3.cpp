#include <iostream>
using namespace std;

int main() {
    int numbers[] = {1, 2, 3, 4, 5};  // här var det en parentes istället för en '}' ÅTGÄRDAT
    int sum = 0;                      // gav ett värde till sum för att inte få undefined behavior. ÅTGÄRDAT
    
    for(int i = 0; i <= 4; i++) {   // Det stod i <= 5 här men det är utanför range så jag ändrade till 4. ÅTGÄRDAT
        sum += numbers[i];
    }
    
    cout << "The average is: " << sum/5.0;
}