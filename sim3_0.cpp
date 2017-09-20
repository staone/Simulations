#include<bits/stdc++.h>
using namespace std;

vector <pair <int,int> > points;
vector <pair <int,int> > current_centers;
vector <pair <int,int> > current_optimal_centers;
vector <double> radius_of_each_k;

double dist(pair<int,int> a, pair<int,int> b)
{
    return sqrt(pow((double)a.first-(double)b.first,2)+pow((double)a.second-(double)b.second,2));
}

int main()
{
	ifstream points_read;
    int i=0;
    points_read.open("points.txt",ifstream::in);
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
}
