#include<iostream>
#include<vector>
using namespace std;

struct process{
   int p_no;

   int bt;
};


int main()
{
	vector<int> time;
   
   int p,timequantum,flag,totaltime=0;
   flag=0;
   cout<<"how many processes ? ";
   cin>>p;

   process allpro[p+1];

   for(int i=1;i<=p;i++)
   {
      cin>>allpro[i].p_no;
      cin>>allpro[i].bt;
      totaltime+=allpro[i].bt;
   }

cout<<"What is the time quantum"<<endl;
cin>>timequantum;
  
  time.push_back(0);

 int t=0;

  while( t!= totaltime)
  {

  	 for(int i=1;i<=p;i++)
        {

        	if(allpro[i].bt <= timequantum && allpro[i].bt>0){

        	
        		cout<<"P"<<allpro[i].p_no<<"  ";
        	
        		allpro[i].bt=0;
        		time.push_back(t);
        		
              t+=allpro[i].bt;
          	}

        	else if(allpro[i].bt > timequantum &&  allpro[i].bt > 0 )
        	{

            

        		  
        		cout<<"P"<<allpro[i].p_no<<"  ";
        		
                  
                  time.push_back(t);
        		allpro[i].bt-=timequantum;
        		t=t+timequantum;
        	}
        }
  }
  
     
   vector<int> :: iterator it;

   for(it=time.begin();it!=time.end();it++)
   {
   	  cout<<*it<<" ";
   }

      
	return 0;
}
