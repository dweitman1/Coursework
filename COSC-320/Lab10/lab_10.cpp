#include <iostream>
#include <list>
#include "d_graph.h"
#include"d_util.h"

using namespace std;

int main(){

    
    graph<char> B;
    ifstream dataFile;
    
    dataFile.open("graphB.dat");
    
    dataFile >> B;
    
    char c;
    cout << "Input vertex character: ";
    cin >> c;
    
    set<char> bread;
    set<char>::iterator a, b;
    bread = bfs(B, c);
    a = bread.begin();
    b = bread.end();
    writeContainer(a, b);
    cout << endl;
    
    list<char> depth;
    dfs(B, depth);
    writeList(depth);

    

    return 0;

}
