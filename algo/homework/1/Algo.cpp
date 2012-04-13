// Algo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using std::ifstream;
using std::istringstream;
using std::vector;
using std::stack;
using std::for_each;
using std::istream_iterator;
using std::back_insert_iterator;

typedef unsigned int uint;
typedef unsigned __int64 uint64;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

static uint64 g_count = 0;

template<typename IT, typename VT> void
insert( IT begin, IT end, /*const*/ VT &v )
{
    using ::std::swap;
    while( begin+1 != end && *( begin + 1 ) < v )
    {
        swap( *begin, *( begin + 1 ) );
        ++g_count;
        ++begin;
    }
    swap( *begin, v );
    ++g_count;
}

template<typename IT>
void merge( IT begin, IT begin_right, IT end )
{
    for( ; begin < begin_right; ++begin )
    {
        if( *begin_right < *begin )
        {
            typename std::iterator_traits<IT>::value_type v;
            using ::std::swap;
            swap( v, *begin );
            swap( *begin, *begin_right );
            insert( begin_right, end, v );
        }
    }
}

template<typename IT>
void mergesort( IT begin, IT end )
{
    size_t size( end - begin );
    if( size < 2 ) return;

    IT begin_right = begin + size / 2;

    mergesort( begin, begin_right );
    mergesort( begin_right, end );
    merge( begin, begin_right, end );
}

template<typename T>
void print( const T &data )
{
    //std::cout << " " << data;
    std::cout << data << std::endl;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
template <class T>
void ReadDataFile( _TCHAR* pFilename, vector<T>* data )
{
    data->clear();
    ifstream inFile( pFilename, std::ios::in );
    if ( inFile.good() )
    {
        std::copy( istream_iterator<T>( inFile ), istream_iterator<T>(), back_insert_iterator<vector<T> >( *data ) );
        inFile.close();
    }
}

template <class T>
void counting( const T& data )
{
    uint64 count = 0;
    size_t dsize = data.size();

    for( uint i=0; i<dsize; ++i )
    {
        for( uint j=i+1; j<dsize; ++j )
        {
            if( data[j] < data[i] )
                ++count;
        }
    }

    std::cout << "Inversions = " << count << std::endl;
}

void pq1( int argc, _TCHAR* argv[] )
{
    vector<uint> data;
    ReadDataFile( argv[1], &data );

    //counting( data );

    mergesort( data.begin(), data.end() );
    //std::for_each( data.begin(), data.end(), print<uint> );
    std::cout << "Inversions = " << g_count << std::endl;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

struct Arc
{
    uint tail;
    uint head;
};

namespace std
{ 
    std::istream& operator>>( std::istream& is, Arc &arc )
    { 
       return is >> arc.tail >> arc.head;
    }
    std::ostream& operator<<( std::ostream& os, Arc const &arc )
    { 
        return os << arc.tail << " " << arc.head << " " << endl;
    }
}

struct Node
{
    vector<uint>    to;
    vector<uint>    from;
};

vector<bool>* explored = NULL;
vector<uint>* leaders = NULL;
stack<uint> order;
uint leader = 0;

void FirstPassDfs( vector<Node>& graph, uint i )
{
    (*explored)[i] = true;
    for each( uint arc in graph[i].from )
    {
        if( !(*explored)[arc] )
            FirstPassDfs( graph, arc );
    }
    order.push( i );
}

void SecondPassDfs( vector<Node>& graph, uint i )
{
    (*explored)[i] = true;
    (*leaders)[i] = leader;
    for each( uint arc in graph[i].to )
    {
        if( !(*explored)[arc] )
            SecondPassDfs( graph, arc );
    }
}

void pq4( int argc, _TCHAR* argv[] )
{
    vector<Arc> data;
    data.reserve( 5200000UL );
    ReadDataFile( argv[1], &data );

    uint graph_size = data[data.size() - 1 ].tail + 1;
    vector<Node> graph( graph_size );
    //vector<uint> f( data[data.size() - 1 ].tail + 1 );
    explored = new vector<bool>( graph_size );
    leaders = new vector<uint>( graph_size );

    for each( Arc arc in data )
    {
        graph[arc.tail].to.push_back( arc.head );
        graph[arc.head].from.push_back( arc.tail );
    }

    /*
    Run first loop on reversed graph
    */
    uint t = 0;
    Node* s = NULL;

    uint i;
    for( i = 1; i < graph_size; ++i )
    {
        if( !(*explored)[i] )
        {
            FirstPassDfs( graph, i );
        }
    }

    delete explored;
    explored = new vector<bool>( graph_size );

    while( !order.empty() )
    {
        uint node = order.top();
        order.pop();
        if( !(*explored)[node] )
        {
            leader = node;
            SecondPassDfs( graph, node );
        }
    }

    data.clear();
    graph.clear();

    vector<uint> scc( graph_size );
    for each( uint arc in *leaders )
    {
        scc[arc]++;
    }
    std::sort( scc.begin(), scc.end(), std::greater<uint>( ) );
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int _tmain( int argc, _TCHAR* argv[] )
{
    //pq1( argc, argv );
    pq4( argc, argv );
    return 0;
}
