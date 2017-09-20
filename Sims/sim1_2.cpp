#include<bits/stdc++.h>

using namespace std;
vector <pair <int,int> > centers;
vector <pair <int,int> > points;
double rad=0.0;


double dist(pair<int,int> a, pair<int,int> b)
{
//cout<<"in dist"<<endl;
    return sqrt(pow((double)a.first-(double)b.first,2)+pow((double)a.second-(double)b.second,2));
}

bool distance_between_n_points(pair<int,int> test,double r)
{
    //cout<<"in dbkp"<<endl;
    vector< pair <int,int> >::iterator it;
    for(vector< pair <int,int> >::iterator it=centers.begin(); it != centers.end();++it)
    {
        double d=dist(test,*it);
        if(d<=r)
        {
            if (d>rad)
                rad=d;
            return true;
        }
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
    int k,n,counter=0,gsize=450;
    double r;
    ofstream pointsf;
    cout<<"Enter no. of center and points and optimal distance: \n";
    cin>>k>>n>>r;
    pointsf << k << "\n" << n << "\n" << r << "\n";
    string fname;
    ostringstream kk, nn, rr;
    kk << k;
    nn << n;
    rr << r;
    fname = "points"+kk.str()+"_"+nn.str()+"_"+rr.str()+".txt";
    cout<<fname<<endl;
//    cout<<typeid().name();
    pointsf.open(fname.c_str());
    pointsf << k << "\n" << n << "\n" << r << "\n";
    while(counter<k)
    {
        //cout<<counter<<endl;
        pair<int,int> p;
        srand(time(0)+rand());
        p.first=rand()%gsize;
        srand(time(0)+rand());
        p.second=rand()%gsize;
        if(centers.size()==0)
        {
            centers.push_back(p);
            pointsf << p.first<<" "<<p.second<<endl;
            points.push_back(p);
            counter++;


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
     for(vector< pair <int,int> >::iterator it=centers.begin(); it != centers.end();++it)
    {
        pair<int, int> p=*it;
        cout<<p.first<<" "<<p.second<<endl;
    }

    while(counter<n)
    {
        pair<int,int> p;
        srand(time(0)+rand());
        p.first=rand()%gsize;
        srand(time(0)+rand());
        p.second=rand()%gsize;
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

    pointsf<<rad;
    pointsf.close();
    cout<<rad<<endl;
    //cout<< dist(make_pair(0,0),make_pair(3,3));
    return 0;
}
