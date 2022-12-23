#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int number) {
    // convert the number to a roman numeral
    char R[7] = { 'I','V','X','L','C','D','M' };
    int n, count = 0;
    string str = "";
    vector <char> A;
    n = number;
    while (number > 0)
    {
        if (number % 10 == 0)
            goto H;
        if (number % 10 >= 5)
        {
            if (number % 10 == 9)
            {
                A.push_back(R[count + 2]);
                A.push_back(R[count]);
                goto H;
            }
            for (int i = 0; i < number % 10 - 5; i++)
            {
                A.push_back(R[count]);
            }
            A.push_back(R[count + 1]);
        }
        else
        {
            if (number % 10 == 4)
            {
                A.push_back(R[count + 1]);
                A.push_back(R[count]);
                goto H;
            }
            for (int i = 0; i < number % 10; i++)
            {
                A.push_back(R[count]);
            }
        }
    H:
        count += 2;
        number /= 10;
    }
    for (int i = A.size() - 1; i >= 0; i--)
    {
        str += A[i];
    }
    return str;
}

int main()
{
    cout << "Hello World\n";
    int num;
    for (int i = 0; i < 10; i++) {
        cout << "\nInput ";
        cin >> num;
        cout << "\n" << solution(num);
    }

    return 0;
}