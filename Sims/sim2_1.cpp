#include<bits/stdc++.h>
using namespace std;

//vector <pair <int,int> > centers;
vector <pair <int,int> > points;
vector <pair <int,int> > current_centers;
vector <pair <int,int> > current_optimal_centers;
vector <double> radius_of_each_k;
vector <double> temp;

double dist(pair<int,int> a, pair<int,int> b)
{
//cout<<"in dist"<<endl;
    return sqrt(pow((double)a.first-(double)b.first,2)+pow((double)a.second-(double)b.second,2));
}

int main(void)
{
    ifstream points_read;
    int i=0;
    points_read.open("points3.txt",ifstream::in);
    int k,pointc;
    double r;
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
//        cout<<"1"<<endl;
    }
    double opt;
    points_read>>opt;
/*    pair<int, int> t;
    t=points.back();
    cout<<t.first<<" "<<t.second<<endl;
  */  cout<<"Optimal: "<<opt<<endl;
    int not_reduced_count=0;
    //bool flag=true;

    i=0;
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
  //      cout<<"2"<<endl;
    }
    for(vector< pair <int,int> >::iterator it=current_centers.begin(); it != current_centers.end();++it)
    {
        pair<int, int> p=*it;
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"Else part"<<endl;
            srand(time(0));
            int no_of_replacements=4;
            radius_of_each_k=temp;
            while(no_of_replacements>0)
            {
                srand(time(0)+rand());
                int old=rand()%k;
                srand(time(0)+rand());
                int newc=rand()%pointc;
                if (!(find(current_centers.begin(),current_centers.end(),points[newc])!=current_centers.end()))
                {
                    //counter++;
                    current_centers[old]=points[newc];
                    no_of_replacements--;
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
        //    cout<<"3"<<endl;
            while(j<k)
            {
                double ds=dist(d,current_centers[j]);
                if (ds<rad)
                {
                    rad=ds;
                    cluster=j;
                }
                j++;
          //      cout<<"4"<<endl;
            }
            if (radius_of_each_k[cluster]<rad)
                radius_of_each_k[cluster]=rad;
        }
        double ans=*max_element(radius_of_each_k.begin(),radius_of_each_k.end());
        if (ans<current_r_max)
        {
            current_r_max=r;
            current_optimal_centers=current_centers;
            not_reduced_count=0;
            //cout<<"Changed in iteration:" <<counter<<endl;
        }
        cout<<not_reduced_count<<endl;
    cout<<current_r_max<<endl;
    //cout<<counter<<endl;
}
