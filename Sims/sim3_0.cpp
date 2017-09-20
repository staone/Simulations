#include<bits/stdc++.h>
using namespace std;

vector <pair <int,int> > points;
vector <pair <int,int> > current_centers;
vector <pair <int,int> > current_optimal_centers;
vector <int> points_covered_by_each_k;


//Distance Function
double dist(pair<int,int> a, pair<int,int> b)
{
    return sqrt(pow((double)a.first-(double)b.first,2)+pow((double)a.second-(double)b.second,2));
}

int main()
{
	//ifstream points_read;
    int i=0;
    string fname;
    //cin>>fname;
    //points_read.open(fname.c_str(),ifstream::in);
    int k,pointc;
    double r;
    cin>>k;
    cin>>pointc;
    cin>>r;
    double current_r_max=INT_MAX;
    int no_of_replacements=4;
    while(i<pointc)
    {
        int x,y;
        cin>>x>>y;
        pair<int,int> inp;
        inp.first=x;
        inp.second=y;
        points.push_back(inp);
        i++;
    }
    double opt;
    cin>>opt;
    i=0;

//Select k random centers initially.
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
            points_covered_by_each_k.push_back(0);
            i++;
        }
    }
    int points_covered=0,index=-1,old_points_covered_max=0;
    double threshold=1.822*r;
    int breakcount=1;
    old_points_covered_max=0;
    int ni=0;
    while (breakcount<=pointc)
    {
        ni++;
        points_covered=0;
        for(int j=0;j<k;j++)
        {
            points_covered_by_each_k[j]=0;
        }

        for(i=0;i<pointc;i++)
        {
            pair<int,int> cur_point=points[i];
            int min_dist=INT_MAX;
            for(int j=0;j<k;j++)
            {
                pair<int, int> p=current_centers[j];
                double d=dist(cur_point,p);
                if(d<threshold)
                {
                    if(d<min_dist)
                    {
                        index=j;
                        min_dist=d;

                    }

                }
            }
            if (index!=-1)
            {
                points_covered++;
                points_covered_by_each_k[index]++;
            }
            index=-1;
        }

        //Replacement of points which cover less points

        for(i=0;i<no_of_replacements;i++)
        {
          int minc=points_covered_by_each_k[0];
          int least=0;
          for(int j=1;j<k;j++)
          {
              if(points_covered_by_each_k[j]<minc)
              {
                  minc=points_covered_by_each_k[j];
                  least=j;
              }
          }
          points_covered_by_each_k[least]=INT_MAX;
          int r=rand()%pointc;
          while(true)
          {
            pair <int,int> x=points[r];

            if (!(find(current_centers.begin(),current_centers.end(),x)!=current_centers.end()))
            {
                current_centers[least]=points[r];
                break;

            }
            r=rand()%pointc;
          }
        }
        if (points_covered > old_points_covered_max)
        {
            breakcount=1;
            old_points_covered_max=points_covered;
            cout<<"Points Covered: "<<points_covered<<"\n";

        }
        else
        {
            breakcount++;
        }
    }
    cout<<"Max points covered: "<<old_points_covered_max<<"\n";
    cout<<"Iterations: "<<ni-pointc<<"\n";

}
