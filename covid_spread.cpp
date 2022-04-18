/*
Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

 
*/



class Solution {

public:

    const int a[4]= { 1, -1, 0, 0};

    const int b[4]= { 0, 0, 1, -1};

    int helpaterp(vector<vector<int>> hospital)

    {

        //when total ==inf , return day
      // total = cell tat is 1 or 2 . Inf = cell tat is 2
      // bfs , day = level at inf == total 
      

        queue<pair<int,int>> infected;

        int inf=0, total=0, n=hospital.size(), m= hospital[0].size(), day=0;

        

        for(int i=0; i<n; i++)

            for(int j=0; j<m; j++)

            {

                if(hospital[i][j])

                    total++;

                if(hospital[i][j]==2)

                    infected.push({i,j});

            }

        

        while(!infected.empty())

        {

            int t=infected.size();

            inf+=t;

            if(inf==total) return day;

            while(t--)

            {

                int x=infected.front().first, y= infected.front().second;

                infected.pop();

                for(int i=0; i<4; i++)

                {

                    int nx= x+a[i], ny= y+b[i];

                    if(nx<0 || nx>=n || ny<0 || ny>=m || hospital[nx][ny]!=1)

                        continue;

                    

                    hospital[nx][ny]=2;

                    infected.push({nx, ny});

                }

            }

            day++;

        }

        if(inf==total) 

            return  day;

        

        return -1;

    }

};




