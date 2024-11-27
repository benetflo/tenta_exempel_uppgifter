// Fråga 1
// Skapa en mallbaserad datastruktur som implementerar en enkel Kö med följande krav:

// Använd en mallklass för att få den att fungera med alla datatyper
// Implementera följande metoder:
// enqueue (lägg till i slutet)
// dequeue (ta bort från början)
// peek (visa första elementet)
// isEmpty
// size
// Inkludera lämplig felhantering för tomma kö-operationer
// Skapa ett omfattande testprogram som:
// Testar kön med minst två olika datatyper
// Demonstrerar all funktionalitet
// Inkluderar kantfall
// Hanterar och visar fel på rätt sätt
// Skriv kommentarer som förklarar dina implementeringsval

#include <iostream>
#include <string>


template <typename T> class Benjiqueue{

    private:
        
        T *ptr;                           
        unsigned int size = 0;            // size var
    
    public:

        Benjiqueue() : ptr(nullptr), size(0) {}   //constructor

        ~Benjiqueue(){                         //deconstructor
            delete [] ptr;
        }
    

        void enqueue(T item){     // places new element last 

            T *temp = new T[size + 1];

            for(int i = 0; i < size; i++){          

                temp[i] = ptr[i];        //copy to new arr
            }
            temp[size] = item;  // add item to last pos
            
            delete [] ptr;    // delete to prevent memory leaks

            size++;
            ptr = temp;    // old ptr == new array
            temp = nullptr;
            
        }

        void dequeue(){     // removes first element

            if(size > 0){          // only if array is NOT empty
                
                T *temp = new T[size - 1];  

                for(int i = 1; i < size; i++){

                    temp[i - 1] = ptr[i];        // copy last arr to new arr escept first element
                }
                
                delete [] ptr;    // delete to prevent memory leaks

                size--;
                ptr = temp;           // old ptr == new array
                temp = nullptr;
            }

        }

        T peek(){      // returns first element. does nothing if empty


            if(size > 0){
                
                T first = ptr[0];        // first element in arr
                return first;            // return first
            }
        }

        bool isEmpty()
        {
            return (size == 0) ? true : false; // return true if size == 0 else false
        }

        int benji_size(){

            return size; //return current size
            
        }

        void print(){   //function to print 

            std::cout << "Elements in queue: ";
            for(int i = 0; i < size; i++){
                std::cout << ptr[i] << " ";
            }
            std::cout << std::endl;
        }

        


};










int main(int argc, char const *argv[])
{
    std::cout << "--------------------\n";
    Benjiqueue<int> my_queue;
    if(my_queue.isEmpty())  // check if empty
        std::cout << "Your queue is empty.\n"; 
    else    
        std::cout << "Your queue is not empty.\n";
    my_queue.enqueue(5);  // push back 5
    my_queue.enqueue(6); // push back 6
    std::cout << "First element is: " << my_queue.peek() << "\n";  //print first element
    my_queue.dequeue(); // remove 5
    my_queue.print();  // print 6
    if(my_queue.isEmpty())  // check if empty
        std::cout << "Your queue is empty.\n"; 
    else    
        std::cout << "Your queue is not empty.\n";
    std::cout << "Size is: " << my_queue.benji_size() << "\n";  // print size
    std::cout << "--------------------\n";




    std::cout << std::endl;




    std::cout << "--------------------\n";
    Benjiqueue<std::string> my_string_queue;
    if(my_string_queue.isEmpty())  // check if empty
        std::cout << "Your queue is empty.\n"; 
    else    
        std::cout << "Your queue is not empty.\n";
    my_string_queue.enqueue("Hej");  // push back "Hej"
    my_string_queue.enqueue("på"); // push back "på"
    std::cout << "First element is: " << my_string_queue.peek() << "\n";  //print first element
    my_string_queue.dequeue(); // remove "Hej"
    my_string_queue.print();  // print 
    if(my_string_queue.isEmpty())  // check if empty
        std::cout << "Your queue is empty.\n"; 
    else    
        std::cout << "Your queue is not empty.\n";
    std::cout << "Size is: " << my_string_queue.benji_size() << "\n";  // print size
    std::cout << "--------------------\n";


    return 0;
}
