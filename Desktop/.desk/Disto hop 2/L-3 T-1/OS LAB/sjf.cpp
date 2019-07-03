#include<iostream>
using namespace std;

int
main ()
{
    int n;
    cout << "Enter number of processes" << endl;
    cin >> n;
    int process[n], brustTime[n], temp;


    for (int i = 0; i < n; i++)
    {
        cin >> brustTime[i];
        process[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (brustTime[j] > brustTime[j + 1])
            {
                temp = brustTime[j];
                brustTime[j] = brustTime[j + 1];
                brustTime[j + 1] = temp;


                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"P"<<process[i];
        if(i!=n-1)
            cout<<"-->";
    }

    cout<<endl;


    int sum,res=0;

    for(int i=0; i<n-1; i++)
    {
        sum=0;
        for(int j=0; j<=i; j++)
        {
            sum+=brustTime[j];
        }
        res+=sum;
    }


    cout<<"Average waiting time = "<<float(res)/n<<endl;


}

