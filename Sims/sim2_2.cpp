#include<bits/stdc++.h>
using namespace std;


vector <pair <int,int> > points;					//vector of all the points given
vector <pair <int,int> > current_centers;			
vector <pair <int,int> > current_optimal_centers;
vector <double> radius_of_each_k;
vector <double> temp;


//Distance Function
double dist(pair<int,int> a, pair<int,int> b)
{
    return sqrt(pow((double)a.first-(double)b.first,2)+pow((double)a.second-(double)b.second,2));
}


int main(void)
{
    ifstream points_read;
    int i=0;
    int k,pointc;
    double r;
    string fname;
    cin>>fname;
    points_read.open(fname.c_str(),ifstream::in);
    
// Reading the input from the file.
    points_read>>k;
    points_read>>pointc;
    points_read>>r;
    double current_r_max=INT_MAX;
    while(i<pointc)
    {
        int x,y;
        points_read>>x>>y;
        pair<int,int> inp;
        inp.first=x;
        inp.second=y;
        points.push_back(inp);
        i++;
    }
    double opt;
    points_read>>opt;
	cout<<"Optimal: "<<opt<<endl;
    

    int not_reduced_count=0;
    bool flag=true;
    int counter=0;
    while(not_reduced_count<10000)
    {
        counter++;

        //Randomly selecting k centers out of n points.
        if (flag)
        {
            i=0;
            flag=false;
            while(i<k)
            {

                srand(time(0)+rand());
                int r=rand()%pointc;
                pair <int, int> x;
                x=points[r];
                cout<<"r:"<<r<<endl;
                if (!(find(current_centers.begin(),current_centers.end(),x)!=current_centers.end()))
                {
                    current_centers.push_back(x);
                    i++;
                    radius_of_each_k.push_back(0.0);
                    temp.push_back(0.0);
                }
          
            }
            for(vector< pair <int,int> >::iterator it=current_centers.begin(); it != current_centers.end();++it)
            {
                pair<int, int> p=*it;
                cout<<p.first<<" "<<p.second<<endl;
            }

        }
        else //Replacements for bad centers.
        {
            
            srand(time(0));
            int no_of_replacements=4;
            radius_of_each_k=temp;
            while(no_of_replacements>0)
            {
                srand(time(0)+rand());
                int old=no_of_replacements-1;//rand()%k;
                srand(time(0)+rand());
                int newc=rand()%pointc;
                //Check whether this points exist as a center or not.
                if (!(find(current_centers.begin(),current_centers.end(),points[newc])!=current_centers.end()))
                {
                    current_centers[old]=points[newc];
                    no_of_replacements--;
                }

            }

        }

        i=0;
        while(i<pointc)
        {
            double rad=INT_MAX;
            int cluster=-1;
            pair<int, int> d=points[i];
            int j=0;
            i++;
        
            while(j<k)
            {
                double ds=dist(d,current_centers[j]);
                if (ds<rad)
                {
                    rad=ds;
                    cluster=j;
                }
                j++;
          
            }
            if (radius_of_each_k[cluster]<rad)
                radius_of_each_k[cluster]=rad;
        }
        double ans=*max_element(radius_of_each_k.begin(),radius_of_each_k.end());
        if (ans<current_r_max)
        {
            current_r_max=ans;
            current_optimal_centers=current_centers;
            not_reduced_count=0;
            cout<<"Changed in iteration:" <<counter<<endl;
        }
        else
            not_reduced_count++;
        
        int s = radius_of_each_k.size();
        double temp;
        pair<int,int> temp_pair;
        for(int i=0;i<s-1;i++)
            for(int j=0;j<s-i-1;j++)
            {
                if(radius_of_each_k[j]<radius_of_each_k[j+1])
                {
                    temp_pair = current_centers[j];
                    current_centers[j] = current_centers[j+1];
                    current_centers[j+1] = temp_pair;
                    temp = radius_of_each_k[j];
                    radius_of_each_k[j]=radius_of_each_k[j+1];
                    radius_of_each_k[j+1]=temp;
                }
            }


    }
	cout<<not_reduced_count<<endl;
    cout<<current_r_max<<endl;
  return 0;
}
