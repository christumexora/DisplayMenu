#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Prototypes for displaying the menu and getting user selection
void display_menu();
char get_selection();

// Menu handling function prototypes
void handle_display(const vector<int> &v);
void handle_add(vector<int> &v);
void handle_mean(const vector<int> &v);
void handle_smallest(const vector<int> &v);
void handle_largest(const vector<int> &v);
void handle_find(const vector<int> &v);
void handle_quit();
void handle_unknown();

// Prototypes for functions that work with the list
// to display it, calculate mean, etc.
void display_list(const vector<int> &v);
double calculate_mean(const vector<int> &v);
int get_smallest(const vector<int> &v);
int get_largest(const vector<int> &v);
bool find(const vector<int> &v, int target);


int main(){
    //Stores all added numbers
vector<int>numbers{}; 
//stores selected option
char selectedOption{' '};

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
            //Print the numbers if P is selected
            print();
        }else if(selectedOption=='A'){
            //Adds a new number if 'A' is selected
            addNum();
        }else if(selectedOption=='M'){
            //Calculates the mean of the sslelcted numbers
            mean();
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
    
//This function displays the menu to the console.
void display_menu() {
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number"<< endl;
        cout << "F - Find a number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
}

//This function simply reads a character selection from 
//stdin and returns it as upper case.
char get_selection() {
    char selection {};
    cin >> selection;
    return toupper(selection);
}

//This function is called when the user selects the 
//display list option from the main menu.
void handle_display(const vector<int> &v) {
    if (v.size() == 0)
        cout << "[] - the list is empty" << endl;
    else    
        display_list(v);
}

//This function is called when the user selects add a 
//number to the list from the main menu
void handle_add(vector<int> &v) {
    int num_to_add {};
    cout << "Enter an integer to add to the list: ";
    cin >> num_to_add;
    v.push_back(num_to_add);
    cout << num_to_add << " added" << endl;
}

//This function is called when the user selects calculate
//the mean from the main menu
void handle_mean(const vector<int> &v) {
    if (v.size() == 0)
        cout << "Unable to calculate mean - list is empty" << endl;
    else    
        cout << "The mean is " << calculate_mean(v) << endl;
}

//This function is called when the user selects the 
//smallest option from the main menu
void handle_smallest(const vector<int> &v) {
     if (v.size() == 0)
        cout << "Unable to determine the smallest - list is empty" << endl;
    else    
        cout << "The smallest element in the list is " << get_smallest(v) << endl;
}

//This function is called when the user selects the 
//largest option from the main menu
void handle_largest(const vector<int> &v) {
     if (v.size() == 0)
        cout << "Unable to determine the largest - list is empty" << endl;
    else    
        cout << "The largest element in the list is " << get_largest(v) << endl;
}

//This function is called when the user selects the 
//find option from the main menu
void handle_find(const vector<int> &v) {
    int target{};
    cout << "Enter the number to find: ";
    cin >> target;
    if ( find(v, target)) 
        cout << target << " was found" << endl;
    else
        cout << target << " was not found" << endl;
}


//This function is called when the user selects the 
//quit option from the main menu
void handle_quit() {
    cout << "Goodbye" << endl;
}

//This function is called whenever the user enters an 
//unknown selection.
void handle_unknown() {
    cout << "Unknown selection - try again" << endl;
}

//This function expects a list of integers as a vector and
//displays all the integers in the list in square brackets
void display_list(const vector<int> &v) {
    cout << "[ ";
    for (auto num: v)
        cout << num << " ";
    cout << "]" << endl;
}

//This function expects a list of integers as a vector
//and returns the calculated mean
double calculate_mean(const vector<int> &v) {
    int total {};
    for (auto num: v)
        total += num;
    return static_cast<double>(total)/v.size();
}

//This function expects a list of integers as a vector
//and returns the largest integer in the list
int get_largest(const vector<int> &v) {
    int largest = v.at(0);
    for (auto num: v) 
        if (num > largest)
            largest = num;
    return largest;
}

//This function expects a list of integers as a vector
//and returns the smallest integer in the list
int get_smallest(const vector<int> &v) {
    int smallest = v.at(0);
    for (auto num: v) 
        if (num < smallest)
            smallest = num;
    return smallest;
}

///This function searches the list of integers as a vector
//for the given integer target
//If the target is found in the vector true is returned
//If the target is not found in the vector false is returned
bool find(const vector<int> &v, int target) {
    for (auto num: v)
        if (num == target)
            return true;
    return false;
}