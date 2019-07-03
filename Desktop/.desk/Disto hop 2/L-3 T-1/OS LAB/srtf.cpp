#include<cstring>
#include<iostream>
#include<set>

using namespace std;

struct process
{

  int pid;
  string pname;
  int at;
  int bt;
};


int
main ()
{
  int n, ttime = 0,flag=0;
  cout << "how many process ?" << endl;
  cin >> n;

  process pr[n];

  for (int i = 0; i < n; i++)
    {
      cin >> pr[i].pname >> pr[i].at >> pr[i].bt;
      pr[i].pid=i+1;
      ttime += pr[i].bt;
    }




  set < int > pids;

   int t=0;

  while ( t <= ttime)
    {

      for (int i = 0; i < n; i++)
	 {
	   if (pr[i].at <= t)
	     pids.insert(pr[i].pid);
	 }

      set<int> :: iterator it;

    


      int min=9999;
      int cpid;

      for(it=pids.begin();it!=pids.end();it++)
      {
          if(pr[*it-1].bt<min && pr[*it-1].bt>0)
          {
             min=pr[*it-1].bt;
             cpid=*it;
          }
      }

       if( flag!= cpid)
      cout<<pr[cpid-1].pname<<" ";

      pr[cpid-1].bt--;
flag=cpid;

      t++;

    }


}

