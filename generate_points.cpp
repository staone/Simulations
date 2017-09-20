#include<bits/stdc++.h>

using namespace std;
vector <pair <int,int> > centers;
vector <pair <int,int> > points;



double dist(pair<int,int> a, pair<int,int> b)
{
//cout<<"in dist"<<endl;
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

bool distance_between_n_points(pair<int,int> test,double r)
{
    //cout<<"in dbkp"<<endl;
    vector< pair <int,int> >::iterator it;
    for(vector< pair <int,int> >::iterator it=centers.begin(); it != centers.end();++it)
    {
        double d=dist(test,*it);
        if(d<=r)
            return true;
    }
    return false;
}

bool distance_between_k_points(pair<int,int> test,double r)
{
    //cout<<"in dbkp"<<endl;
    vector< pair <int,int> >::iterator it;
    for(vector< pair <int,int> >::iterator it=centers.begin(); it != centers.end();++it)
    {
        double d=dist(test,*it);
        if(d<=2*r)
            return false;
    }
    return true;
}

int main(void)
{
    vector < pair < int,int > >::iterator i;
    int k,n,counter=0;
    double r;
    ofstream pointsf;
    pointsf.open("points.txt");

    cout<<"Enter no. of center and points and optimal distance: \n";
    cin>>k>>n>>r;
    pointsf << k << "\n" << n << "\n" << r << "\n";
    while(counter<k)
    {
        //cout<<counter<<endl;
        pair<int,int> p;
        p.first=rand()%300;
        p.second=rand()%300;
        if(centers.size()==0)
        {
            centers.push_back(p);
        }
        else if(!(find(centers.begin(),centers.end(),p)!=centers.end()))//doesnt exist
        {
            if(distance_between_k_points(p,r))//>r
               {
                   centers.push_back(p);
                   points.push_back(p);
                   counter++;
                   pointsf << p.first<<" "<<p.second<<endl;
               }
        }

    }

    while(counter<n)
    {
        pair<int,int> p;
        p.first=rand()%300;
        p.second=rand()%300;
        if(!(find(points.begin(),points.end(),p)!=points.end()))//doesnt exist
        {
            if(distance_between_n_points(p,r))//>r
               {
                   points.push_back(p);
                   counter++;
                   pointsf << p.first<<" "<<p.second<<endl;
               }
        }
    }


    pointsf.close();
    //cout<< dist(make_pair(0,0),make_pair(3,3));
    return 0;
}
