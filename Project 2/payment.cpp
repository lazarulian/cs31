// CS31: Project 2 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    
    // Constant Error Messages
    const string state_error_message = "Invalid state!";
    const string cost_error_message = "Invalid amount!";
    const string month_error_message = "Invalid month!";
    const string day_error_message = "Invalid day!";
    const string year_error_message = "Invalid year!";
    
    // Error Logic
    bool state_error;
    bool cost_error;
    bool month_error;
    bool day_error;
    bool year_error;
    int test_cases_passed = 0;
    
    // Input Values
    string state;
    double cost;
    string month;
    int day;
    int year;
    
    // Calculated Variables
    double total_cost;
    int free_tax;
    string precision;
    
    // Costs of Tax / State
    
    const double nebraska_tax = (5.50 + 1.35)/100;
    const double nevada_tax = (6.85 + 1.29)/100;
    const double newjersey_tax = (6.63 + -0.03)/100;
    const double newmexico_tax = (5.13 + -2.69)/100;
    const double newyork_tax = (4.00 + 4.49)/100;
    const double northcarolina_tax = (4.75+2.22)/100;
    const double northdakota_tax = (5.00+1.85)/100;
    const double ohio_tax = (5.75+1.42)/100;
    const double oklahoma_tax = (4.50+4.42)/100;
    const double pennsylvania_tax = (6.00+0.34)/100;
    const double rhodeisland_tax = (7.00)/100;
    const double southcarolina_tax = (6.00+1.43)/100;
    const double southdakota_tax = (4.50+1.90)/100;
    const double tennessee_tax = (7.00+2.47)/100;
    const double texas_tax = (6.25+1.94)/100;
    const double utah_tax = (5.95+0.99)/100;
    const double vermont_tax = (6.00+0.18)/100;
    const double virginia_tax = (5.30+0.35)/100;
    const double washington_tax = (6.50+2.67)/100;
    const double westvirginia_tax = (6.00+0.39)/100;
    const double wisconsin_tax = (5.00+0.44)/100;
    const double wyoming_tax = (4.00+1.36)/100;


    
    // Taking in User Input
    cout << "State Name: ";
    getline(cin, state);
    state.erase(remove(state.begin(), state.end(), ' '), state.end());
    
    cout << "Purchase amount: ";
    cin >> cost;
    cin.clear();
    cin.ignore(10000, '\n'); // Clears the Buffer
    
    cout << "Provide the month: ";
    getline(cin, month);
    
    cout << "Provide the day: ";
    cin >> day;
    cin.clear();
    cin.ignore(10000, '\n');
    
    cout << "Provide the year: ";
    cin >> year;
    cin.clear();
    cin.ignore(10000, '\n');
    
    
    // State Name Error Cases
    // Non-Capitalized State
    char fist_letter = state[0];
    if (fist_letter >= 'A' && fist_letter <= 'Z') {
        test_cases_passed = test_cases_passed + 1;
    }
    else {
        state_error = 1;
    }
    
    // Non-Existant State
    
    if (state == "Alabama" || state == "Alaska" || state == "Arizona" || state == "Arkansas" || state == "California" || state == "Colorado" || state == "Connecticut" || state == "Delaware" || state == "Florida" || state == "Georgia" || state == "Hawaii" || state == "Idaho" || state == "Illinois" || state == "Indiana" || state == "Iowa" || state == "Kansas" || state == "Kentucky" || state == "Lousiana" || state == "Maine" || state == "Maryland" || state == "Massachusetts" || state == "Michigan" || state == "Minnesota" || state == "Mississippi" || state == "Missouri" || state == "Montana" || state == "Nebraska" || state == "Nevada" || state == "NewHampshire" || state == "NewJersey" || state == "NewMexico" || state == "NewYork" || state == "NorthCarolina" || state == "NorthDakota" || state == "Ohio" || state == "Oklahoma" || state == "Oregon" || state == "Pennsylvania" || state == "RhodeIsland" || state == "SouthCarolina" || state == "SouthDakota" || state == "Tennessee" || state == "Texas" || state == "Utah" || state == "Vermont" || state == "Virginia" || state == "Washington" || state == "WestVirginia" || state == "Wisconsin" || state == "Wyoming") {
        test_cases_passed = test_cases_passed + 1;
        }
    
    else {
        state_error = 1;
    }
    
    // Purchase Amount Error Cases
        // Negative Values n Such
            if(cost <= 0) {
                cost_error = 1;
            }
            else {
                test_cases_passed = test_cases_passed + 1;
            }
    // String Inputted for Cost
    
    
    // Error for The Month Inputted
    if (month == "January" || month == "February" || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October" || month == "November" || month == "December") {
        test_cases_passed = test_cases_passed + 1;
    }
    
    else {
        month_error = 1;
    }
    
    // Error for the Day Inputted
        if (day >= 1 && day <= 31) {
            test_cases_passed = test_cases_passed + 1;
        }
        
        else {
            day_error = 1;
        }
    
    // Error for Year Inputted
        if (year >= 1 && year <= 2025) {
            test_cases_passed = test_cases_passed + 1;
        }
        
        else {
            year_error = 1;
        }
    
    // Running the Error Cases
    if (state_error == 1) {
        cout << state_error_message << endl;
    }
    
    else if (cost_error == 1) {
        cout << cost_error_message << endl;
    }
    
    else if (month_error == 1) {
        cout << month_error_message << endl;
    }
    
    else if (day_error == 1) {
        cout << day_error_message << endl;
    }
    
    else if (year_error == 1) {
        cout << year_error_message << endl;
    }
    
    
    
    
    
    
    
    // Calculating the Actual Cost of Goods
    
    if (state_error == 1 || cost_error == 1 || month_error == 1 || day_error == 1 || year_error == 1) {
        return 0;
    }
    
    else {
        
        // Alabama Cost
        if (state == "Alabama") {
            if (month == "July" && day <= 17 && day >= 15) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = .04*cost + .0514*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Alabama
        
        
        // Alaska
        else if (state == "Alaska") {
            total_cost = .0143*cost + cost;
        } // End Alaska
        
        
        // Arizona
        else if (state == "Arizona") {
            total_cost = .0277*cost + .0560*cost + cost;
        } // End Arizona
        
        // Arkansas
        else if (state == "Arkansas") {
            if (month == "August" && day <= 7 && day >= 6) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = .0650*cost + .0293*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Arkansas
        
        // California
        else if (state == "California") {
            total_cost = .0725*cost + .0131*cost + cost + 1;
        } // End California
        
        // Colorado
        else if (state == "Colorado") {
            total_cost = .0290*cost + .0473*cost + cost;
        } // End Colorado
        
        // Connecticut
        else if (state == "Connecticut") {
            if (month == "August" && day <= 27 && day >= 21) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = .0635*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Connecticut
        
        // Delaware
        else if (state == "Delaware") {
            total_cost = cost;
        } // End Delaware
        
        // Florida
        else if (state == "Florida") {
            total_cost = .06*cost + .0105*cost + cost;
        } // End Florida
        
        // Georgia
        else if (state == "Georgia") {
            total_cost = .04*cost + .0329*cost + cost;
        } // End Georgia
        
        // Hawaii
        else if (state == "Hawaii") {
            total_cost = .04*cost + .0041*cost + cost;
        } // End Hawaii
        
        // Idaho
        else if (state == "Idaho") {
            total_cost = .06*cost + .0003*cost + cost;
        } // End Idaho
        
        // Illinois
        else if (state == "Illinois") {
            total_cost = .0625*cost + .0249*cost + cost;
        } // End Illinois
        
        // Indiana
        else if (state == "Indiana") {
            total_cost = .07*cost + cost;
        } // End Indiana
        
        // Iowa
        else if (state == "Iowa") {
            total_cost = .06*cost + .0082*cost + cost;
        } // End Iowa
        
        // Kansas
        else if (state == "Kansas") {
            total_cost = .065*cost + .0217*cost + cost;
        } // End Kansas
        
        // Kentucky
        else if (state == "Kentucky") {
            total_cost = .06*cost + cost;
        } // End Kentucky
        
        // Louisiana
        else if (state == "Louisiana") {
            total_cost = .0445*cost + .05*cost + cost;
        } // End Louisiana
        
        // Maine
        else if (state == "Maine") {
            total_cost = .0550*cost +  cost;
        } // End Maine
        
        // Maryland
        else if (state == "Maryland") {
            if (month == "August" && day <= 20 && day >= 14) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = .06*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Maryland
        
        // Massachusetts
        else if (state == "Massachusetts") {
            if (month == "August" && day <= 15 && day >= 14) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = .0625*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Massachusetts
        
        // Michigan
        else if (state == "Michigan") {
            total_cost = .06*cost + cost;
        } // End Indiana
        
        // Minnesota
        else if (state == "Minnesota") {
            total_cost = .0688*cost + cost*0.055 + cost;
        } // End Minnesota

        // Mississippi
        else if (state == "Mississippi") {
            if (month == "July" && day <= 30 && day >= 29) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = .07*cost + cost*.0007 + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Mississippi
        
        // Missouri
        else if (state == "Missouri") {
            if (month == "April" && day <= 25 && day >= 19) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = .0423*cost + cost*.0390 + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Missouri
        
        // Montana
        else if (state == "Montana") {
            total_cost = cost;
        } // End Montana
        
        //Nebraska
        else if (state == "Nebraska") {
            total_cost = cost*nebraska_tax + cost;
        } // End Nebraska
        
        // Nevada
        else if (state == "Missouri") {
            if (month == "August" && day <= 7 && day >= 5) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = nevada_tax*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Nevada
        
        // New Hampshire
        else if (state == "NewHampshire") {
            total_cost = cost;
        }
        
        // New Jersey
        else if (state == "NewJersey") {
            total_cost = newjersey_tax*cost + cost;
        }
        
        // New Mexico
        else if (state == "NewMexico") {
            total_cost = newmexico_tax*cost + cost;
        }
        
        // New York
        else if (state == "NewYork") {
            total_cost = newyork_tax*cost + cost;
        }
        
        // NorthCarolina
        else if (state == "NorthCarolina") {
            total_cost = northcarolina_tax*cost + cost;
        }
        
        // North Dakota
        else if (state == "NorthDakota") {
            total_cost = northdakota_tax*cost + cost;
        }
        
        // Ohio
        else if (state == "Ohio") {
            if (month == "August" && day <= 7 && day >= 5) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = ohio_tax*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Ohio
        
        // Oklahoma
        else if (state == "Oklahoma") {
            if (month == "August" && day <= 6 && day >= 5) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = oklahoma_tax*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End Ohio
        
        // Oregon
        else if (state == "Orgeon") {
            total_cost = cost;
        }
        
        // Penn
        else if (state == "Pennsylvania") {
            total_cost = cost*pennsylvania_tax + cost;
        }
        
        // Rhode Island
        else if (state == "RhodeIsland") {
            total_cost = cost*rhodeisland_tax + cost;
        }
        
        // South Carolina
        else if (state == "SouthCarolina") {
            if (month == "August" && day <= 7 && day >= 5) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = southcarolina_tax*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End SC
        
        // South Dakota
        else if (state == "SouthDakota") {
            total_cost = cost*southdakota_tax + cost;
        }
        
        // Tennessee
        else if (state == "Tennessee") {
            if (month == "July" && day <= 31 && day >= 29) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = tennessee_tax*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End TNSEE
        
        // Texas
        else if (state == "Texas") {
            if (month == "August" && day <= 7 && day >= 5) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = texas_tax*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End TX
        
        // Utah
        else if (state == "Utah") {
            total_cost = cost*utah_tax + cost +1.25;
        }
        
        // Vermont
        else if (state == "Vermont") {
            total_cost = cost*vermont_tax + cost;
        }
        
        // Virginia
        else if (state == "Virginia") {
            total_cost = cost*virginia_tax + cost +1.00;
        }
        
        // Washington
        else if (state == "Washington") {
            total_cost = cost*washington_tax + cost;
        }
        
        // West Virginia
        else if (state == "WestVirginia") {
            if (month == "August" && day <= 7 && day >= 5) {
                free_tax = 1;
            }
            else {
                free_tax = 0;
            }
            
            switch(free_tax) {
                case 0:
                    total_cost = westvirginia_tax*cost + cost;
                    
                    break;
                    
                case 1:
                    total_cost = cost;
                    break;
            }
        } // End WV
        
        // Wisconsin
        else if (state == "Wisconsin") {
            total_cost = cost*wisconsin_tax + cost;
        }
        
        // Wyoming
        else if (state == "Wyoming") {
            total_cost = cost*wyoming_tax + cost;
        }
        
        else {
            total_cost = cost;
        }
        
    } // End Else Statement for Error
    
    
    //total_cost = ceil(total_cost * 100.0) / 100.0;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Please pay a total of $" << total_cost << endl;
    
    return 0;
}
