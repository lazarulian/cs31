#include <iostream>
#include <string>


using namespace std;




bool Order(int m_arr[3])
{ // 3 integers, returns true if they are in ascending order

    if (m_arr[1] < m_arr[0])
        return false;
    if (m_arr[2] < m_arr[1])
        return false;

    return true;
}

// 5. Write a function to calculate the average and the range of 3 integers sent to it. Also write the call.

void average_range(int x, int y, int z, int& average, int& range)
{
    // Average
    average = (x+y+z)/3;
    // Range
    range = std::max(max(x, y), z)-std::min(min(x, y), z);
}


// 6. Write a function to return the whole number and the decimal fraction of a float value sent to it.  Also write the call.




int main()
{
    int range;
    int average;

    average_range(4, 12, 32, average, range);

    cout << average << ", " << range<< endl;

    return 0;
}