//ioi 2009 review
//solution by Kim Vyacheslav
#include <cstdio>
#include <deque>

using namespace std;

#define MAXN 900
#define range(x) (x < n && x >= 0)
#define INF 10000000


int cx[] = {-1, 0, 1, 0},
    cy[] = {0, -1, 0, 1};

char map[MAXN][MAXN];
int beeDistance[MAXN][MAXN];
bool mechoCanReach[MAXN][MAXN];

int n, s, mx, my;

deque< pair<int, int> >bq;
deque< pair<int,  pair<int, int> > >q; 

bool check(int delay)
{
    if (delay * s >= beeDistance[my][mx])
        return false;
    q.clear();
    memset(mechoCanReach, 0, sizeof(mechCanReach));
    
    q.push_back(make_pair(delay * s, make_pair(my, mx)));
    mechoCanReach[my][mx] = true;
    
    while(!q.empty())
    {
        int y = q.front().second.first;
        int x = q.front().second.second;
        int distance = q.front().first;
        
        if (x == fx && y == fy) return true;
        
        for(int i = 0; i < 4; i++)
        {
            int ny = y + cy[i];
            int nx = x + cx[i];
            
            if(range(nx) && range(ny) && map[ny][nx] != 'T' && (!mechoCanReach[ny][nx]) && (distance + 1) < beeDistance[ny][nx])
            {
                mechoCanReach[ny][nx] = true;
                q.push_back(make_pair(distance+1, make_pair(ny, nx)));
            }
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &s);
    
    memset(beeDistance, -1, sizeof(beeDistance));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            scanf("%c", &map[i][j]);
            if (map[i][j] == 'M')
            {
                map[i][j] = 'G';
                mx = j;
                my = i;
            }
            else if (map[i][j] == 'H')
            {
                beeDistance[i][j] = 0;
                bq.push_back(make_pair(i, j));
            }
            else if (map[i][j] == 'D')
            {
                fx = j;
                fy = i;
                map[i][j] == 'G';
            }
        }
    
    while(!bq.empty())
    {
        int y = bq.front().first;
        int x = bq.front().second;
        
        bq.pop_front();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + cx[i];
            int ny = y + cy[i];
            
            if (range(nx) && range(ny) && map[ny][nx] == 'G' && beeDistance[ny][nx] == -1)
            {
                bq.push_back(make_pair(ny, nx));
                beeDistance[ny][nx] = beeDistance[y][x] + s;
            }
        }
    }
    
    beeDistance[fy][fx] = INF;
    
    int low = -1, top = n*n*2, mid;
    while (top-low > 1)
    {
        mid = (low + top) / 2;
        if(check(mid))
            low = mid;
        else top = mid;
    }
    
    printf("%d\n", low);
    
    return 0;
}

