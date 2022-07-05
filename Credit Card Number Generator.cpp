//Using only Luhn Algorithm, finding a valid card number within a range. 16 card numbers only
#include <iostream>
#include <stdbool.h>

using namespace std;

bool checkCardNumber(long long int cardNumber);
void arrayChecker(int arr[]);
int addMultipleDigitNumber(int number);

int main()
{
    long long int cardNumber = 9999999999989999;
    long long int boundary = 9999999999999999;
    long long int ctr = 0;

    /*for(long long int i = cardNumber; i <= boundary; i++)
    {
        if(checkCardNumber(i))
        {
            cout<<i<<" is a valid card number!"<<endl;
            ctr++;
            //cout<<ctr<<endl;
        }
    }
    cout<<"There are "<<ctr<<" valid card number in the range!"<<endl;
    */
    long long int num = 4748445144526718;
    if(checkCardNumber(num))
    {
        cout<<num<<" is a valid card number!"<<endl;
    }
    else
    {
        cout<<num<<" is not a valid card number!"<<endl;
    }
}

bool checkCardNumber(long long int cardNumber)
{
    bool isValid = false;
    int length = 16;
    int s = length;
    int arr[length];
    long long int temp = cardNumber;

    while(cardNumber != 0)
    {
        arr[--length] = cardNumber % 10;
        cardNumber /= 10;
    }

    int x = 15;
    int secondArray[15];

    for (int i = 0; i < x; i++)
    {
        if(i % 2 == 0)
        {
            secondArray[i] = arr[i] * 2;
        }
        else if(i % 2 != 0)
        {
            secondArray[i] = arr[i] * 1;
        }
    }

    for(int i = 0; i < x; i++)
    {
        if(secondArray[i] > 9)
        {
            secondArray[i] = addMultipleDigitNumber(secondArray[i]);
        }
    }

    //adding up the content of the array
    int sum = 0;
    for(int i = 0; i < x; sum += secondArray[i++]){}

    //cout<<endl<<sum;

    int remainder = sum % 10;
    int difference = 10 - remainder;
    int lastDigit = arr[s-1];

    if(difference == lastDigit)
    {
        isValid = true;
    }

    return isValid;
}

int addMultipleDigitNumber(int number)
{
    int sum = 0;
    int digits;
    while(number != 0)
    {
        digits = number % 10;
        number /= 10;
        sum += digits;
    }

    return sum;
}
