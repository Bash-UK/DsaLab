#include "dfs_bfs.h"

using namespace std;

int main(){
    Area A1;
    areaList* temp;
    char a[30];
    int n;
    cout<<"Enter the number of area you want to insert: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        A1.readAreas();
    }
        for(int i=0; i<n; i++)
    {
         A1.readConnection();
    }

    A1.displayAreas();
    A1.DFS();


    return 0;
}