#include <iostream>
#include <iomanip>
#include <vector>

double Summa(std::vector<double> Array)
{
    double Sum = 0;
    for (int i = 0; i < Array.size(); i++)
    {
        Sum += Array[i];
    }
    return Sum;
}

double ChangeLast(std::vector<double> Array)
{
    double Last;
    double Sum = Summa(Array);
    double Size = Array.size();
    Last = (Sum / Size);
    return Last;
}

double Max(std::vector<double> Array)
{
    double maximum = 0;
    for (int i = 0; i < Array.size(); i++)
    {
        if (Array[i] > maximum)
            maximum = Array[i];
    }
    return maximum;
}

double Min(std::vector<double> Array)
{
    double minimum = 5000000;
    for (int i = 0; i < Array.size(); i++)
    {
        if (Array[i] < minimum)
            minimum = Array[i];
    }
    return minimum;
}

void Show(std::vector<double> Array)
{
    for (int i = 0; i < Array.size(); i++)
    {
        std::cout << std::fixed << std::setprecision(3) << Array[i] << " ";
    }
    std::cout << std::endl;
}

void Change(std::vector<double> Array)
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
        std::cin >> operation;
        if (operation == 0)
            break;
        if (operation == 1)
        {
            std::cin >> element;
            std::cout << "+: " << Array.size() + 1 << std::endl;
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
            std::cout << "-: " << Array.size() - 1 << std::endl;
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
    std::vector<double> Array;
    std::cin >> n;
    double* array = new double[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        Array.push_back(array[i]);
    }
    std::cout << n << std::endl;
    Show(Array);
    Change(Array);
    delete[] array;
    return 0;
}
