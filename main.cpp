#include <iostream>
#include <cmath>

using namespace std;

int mod(int a, int b)
{
    return a-b*floor(double(a)/b);
}

// pos = 2^i + 2^(i+1) * a
int find_i(int n, int pos)
{
	int ret = 0;
    for (int i=0;i<=n-1;i++)
    {
        if ((pos-(1<<i))%(1<<(i+1))==0) ret=i;
    }
	return ret;
}

int main()
{
    int n;
	cout << "How many disks? ";
    cin >> n;
    int disks_moved[(1<<n)-1]={0};
    disks_moved[0]=1;
    if (n>1) {disks_moved[1]=2;disks_moved[2]=1;}
    int append=0;
    int pos=1;
    for (int i=3;i<(1<<n)-1;i++)
    {
        append=3+find_i(n, pos++);
        disks_moved[i]=append;
        disks_moved[i+1]=disks_moved[i+3]=1;
        disks_moved[i+2]=2;
        i+=3;
    }
    int moves[n+1][2]={0};
    moves[1][0]=1;
    moves[1][1]=2;
    if (n%2) moves[1][1]=3;
    for (int i=2;i<=n;i++)
    {
        if (moves[i-1][1]==2) moves[i][1]=3;
        else moves[i][1]=2;
    }
    for (int i=1;i<=n;i++) moves[i][0]=1;
    cout << "The number of disk moves in total: " << (1<<n)-1 << "\n";
    for (int i=0;i<(1<<n)-1;i++)
    {
        for (int j=0;j<2;j++) cout << moves[disks_moved[i]][j] << " ";
        cout << "\n";
        if (disks_moved[i]%2)
        {
            moves[disks_moved[i]][0]+=(n%2 ? -2 : 0);
            moves[disks_moved[i]][1]+=(n%2 ? -2 : 0);
        }
        else
        {
            moves[disks_moved[i]][0]+=(n%2 ? 0 : -2);
            moves[disks_moved[i]][1]+=(n%2 ? 0 : -2);
        }
        moves[disks_moved[i]][0]=mod(moves[disks_moved[i]][0],3)+1;
        moves[disks_moved[i]][1]=mod(moves[disks_moved[i]][1],3)+1;
    }
    return 0;
}
