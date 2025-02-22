#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

//Stores all added numbers
vector<int>numbers{}; 
//stores selected option
char selectedOption{' '};
//stores newly added number
int newNumber{}; 

int main(){
    do{
        cout << "Please select any options below to perform action: " << endl;
        cout << "===================================================" << endl;
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl << endl;
        cout << "Enter your choice: " << endl;
        // Store selected input options
        cin >> selectedOption;
        // convert input to uppercase
        selectedOption = toupper(selectedOption); 
        //Returns all the numbers added in the operation
        if(selectedOption=='P'){
            if(numbers.empty()){
                cout << "[ ] - the list is empty" << endl; 
            }else{
                cout << "[";
                for(auto num : numbers){
                    cout << num << " ";
                    }
                    cout << "]" << endl;
                }
        //Runs if 'A' is selected
        }else if(selectedOption=='A'){
            cout << "Enter a new number: " << endl;
            cin >> newNumber;
            cout << newNumber << " added" << endl;
            //stores the newly addeed number to the vector of numebers
            numbers.push_back(newNumber);
        //Calculates the mean of the sslelcted numbers
        }else if(selectedOption=='M'){
            if(numbers.empty()){
                cout << "Unable to calculate the mean - no data" << endl; 
            }else{
                double dispMeanNum = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
            cout << dispMeanNum << endl;
            }
        //Displays the smallest element of the vector
        }else if(selectedOption=='S'){
            if(numbers.empty()){
                cout << "Unable to determine the smallest number - list is empty" << endl; 
            }else{
                int smallestNum = *min_element(numbers.begin(), numbers.end());
            cout << "The smallest number is " << smallestNum << endl;
            }
        //Displays the largest element of the vector
        }else if(selectedOption=='L'){
            if(numbers.empty()){
                cout << "Unable to determine the largest number - list is empty" << endl; 
            }else{
                int largestNum = *max_element(numbers.begin(), numbers.end());
            cout << "The largest number is " << largestNum << endl;
            }
        //Terminates the operation
        }else if(selectedOption=='Q'){
            cout << "Goodbye" << endl;
        }else{
            cout << "Unknown selection, please try again" << endl;
        }
    
    }while(selectedOption!='Q');
    
    return 0;
    }
