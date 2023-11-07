#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double Summa(vector <double> Array)
{
    double Sum = 0;
    for (int i = 0; i < Array.size(); i++)
    {
        Sum += Array[i];
    }
    return Sum;
}

double ChangeLast(vector <double> Array)
{
    double Last;
    double Sum = Summa(Array);
    double Size = Array.size();
    Last = (Sum / Size);
    return Last;
}

double Max(vector <double> Array)
{
    double maximum = 0;
    for (int i = 0; i < Array.size(); i++)
    {
        if (Array[i] > maximum)
            maximum = Array[i];
    }
    return maximum;
}

double Min(vector <double> Array)
{
    double minimum = 5000000;
    for (int i = 0; i < Array.size(); i++)
    {
        if (Array[i] < minimum)
            minimum = Array[i];
    }
    return minimum;
}

void Show(vector <double> Array)
{
    for (int i = 0; i < Array.size(); i++)
    {
        cout << fixed << setprecision(3) << Array[i] << " ";
    }
    cout << endl;
}

void Change(vector <double> Array)
{
    double Sum = Summa(Array);
    double Last = ChangeLast(Array);
    Array.push_back(Sum);
    Array.push_back(Last);
    Show(Array);
    double max = Max(Array);
    double min = Min(Array);
    double Del;
    double Mnoj;
    Del = min;
    Mnoj = max;
    for (int i = 0; i < Array.size(); i++)
    {
        Array[i] /= Del;
        Array[i] += Mnoj;
    }
    Show(Array);
    int operation = 10;
    double element;
    while (operation)
    {
        cin >> operation;
        if (operation == 0)
            break;
        if (operation == 1)
        {
            cin >> element;
            cout << "+: " << Array.size() + 1 << endl;
            Array.push_back(element);
            Show(Array);
            double Sum = Summa(Array);
            double Last = ChangeLast(Array);
            Array.push_back(Sum);
            Array.push_back(Last);
            Show(Array);
            double max = Max(Array);
            double min = Min(Array);
            Del = min;
            Mnoj = max;
            for (int i = 0; i < Array.size(); i++)
            {
                Array[i] /= Del;
                Array[i] += Mnoj;
            }
            Show(Array);
        }

        if (operation == 2)
        {
            cout << "-: " << Array.size() - 1 << endl;
            Array.pop_back();
            Show(Array);
            double Sum = Summa(Array);
            double Last = ChangeLast(Array);
            Array.push_back(Sum);
            Array.push_back(Last);
            Show(Array);
            double max = Max(Array);
            double min = Min(Array);
            Del = min;
            Mnoj = max;
            for (int i = 0; i < Array.size(); i++)
            {
                Array[i] /= Del;
                Array[i] += Mnoj;
            }
            Show(Array);
        }
    }
}

int main()
{
    int n;
    vector<double> Array;
    cin >> n;
    double* array = new double[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        Array.push_back(array[i]);
    }
    cout << n << endl;
    Show(Array);
    Change(Array);
    delete[] array;
    return 0;
}