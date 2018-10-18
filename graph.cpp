
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <assert.h>
using namespace std;
#define DEBUG 1
struct Vertex;
typedef std::vector< Vertex > Vertices_t;
typedef std::set <int> Neighbours_t;

struct Vertex {
private:
    int data;
public:
    Neighbours_t neighbours;

    int getData(){return data;}
    Vertex( int d ): data(d) {}
    Vertex( ): data(-1) {}

    bool operator==( const Vertex& ref ) const {
        return ( ref.data == data );
    }
    bool operator<( const Vertex& ref ) const {
        return ( ref.data < data );
    }
};

class Graph
{
    private :
    Vertices_t vertices;

    private :
    void addEdgeIndices(int index1,int index2);

    Vertices_t::iterator findVertexIndex(int val, bool& res);

    public :
    void addEdge(int n1, int n2);
    int checkForLoop(int n);
    void printGraph();

};

void Graph::addEdgeIndices ( int index1, int index2 ) {
    vertices[ index1 ].neighbours.insert( index2 );
}

void Graph::printGraph(){
    for(int i=0;i<vertices.size();i++){
       cout << vertices[i]. << ": ";
        for(auto neighbour : vertices[i].neighbours){
            cout << vertices[neighbour].getData << " ";
        }
        cout << endl;
    }
}

int Graph::checkForLoop(int n){
    vector<bool> currVertices(n,false);
    vector<bool> allVertices(n,false);
    Vertices_t activeVertices(0);

    Vertex currVertex = Vertex();
    bool allNodesChecked = false;
    while(!allNodesChecked){
        int pos = std::find(allVertices.begin(), allVertices.end(), false) - allVertices.begin();
        activeVertices.push_back(vertices[pos]);
        while(!activeVertices.empty())
        {
            // get the next vertex
            currVertex = activeVertices.back();
            //cout << currVertex.getData() << ": ";
            //check if it is already added and if yes end search
            if(currVertices[currVertex.getData()] == true)
            {
                if(DEBUG){
                    cout << currVertex.getData() << endl;
                }
                return 1;
            }

            // set them to true
            currVertices[currVertex.getData()] = true;
            allVertices[currVertex.getData()] = true;
            activeVertices.pop_back();
            for(auto neighbour : currVertex.neighbours){
               // cout << neighbour << " " ;
                activeVertices.push_back(vertices[neighbour]);
            }
           // cout << endl;
        }
        allNodesChecked = std::find(allVertices.begin(), allVertices.end(), false) == allVertices.end();
    }
    return 0;
}


Vertices_t::iterator Graph::findVertexIndex( int val, bool& res )
{
    std::vector<Vertex>::iterator it;
    Vertex v(val);
    it = std::find( vertices.begin(), vertices.end(), v );
    if (it != vertices.end()){
        res = true;
        return it;
    } else {
        res = false;
        return vertices.end();
    }
}

void Graph::addEdge ( int n1, int n2 ) {

    bool foundNet1 = false, foundNet2 = false;
    Vertices_t::iterator vit1 = findVertexIndex( n1, foundNet1 );
    int node1Index = -1, node2Index = -1;
    if ( !foundNet1 ) {
        Vertex v1( n1 );
        vertices.push_back( v1 );
        node1Index = vertices.size() - 1;
    } else {
        node1Index = vit1 - vertices.begin();
    }
    Vertices_t::iterator vit2 = findVertexIndex( n2, foundNet2);
    if ( !foundNet2 ) {
        Vertex v2( n2 );
        vertices.push_back( v2 );
        node2Index = vertices.size() - 1;
    } else {
        node2Index = vit2 - vertices.begin();
    }

    //assert( ( node1Index > -1 ) && ( node1Index <  vertices.size()));
    //assert( ( node2Index > -1 ) && ( node2Index <  vertices.size()));

    addEdgeIndices( node1Index, node2Index );
}

int main() {
    int t;
    cin >> t;
    int n;
    int m;
    int n1;
    int n2;
    Graph graph = Graph();
    for(int i=0;i<t;i++){
        graph = Graph();
        cin >> n >> m;
        for(int j=0;j<m;j++){
            cin >> n1 >> n2;
            graph.addEdge(n1,n2);
        }
        cout << graph.checkForLoop(n) << endl;
        //graph.checkForLoop(n);
        //cout << endl << endl;
        //graph.printGraph();
    }

    return 0;
}
