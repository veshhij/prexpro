// Algo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using std::ifstream;
using std::istringstream;
using std::vector;
using std::stack;
using std::priority_queue;
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
        //std::stringstream buffer;
        //buffer << inFile.rdbuf();
        std::copy(
            istream_iterator<T>( inFile/*buffer*/ ),
            istream_iterator<T>(),
            //back_insert_iterator<vector<T> >( *data )
            back_inserter( *data )
            );
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

struct CSCC
{
    CSCC( uint size ) : graph( size ), explored( size ), leaders( size ), leader( 0 )
    {
    }
    ~CSCC()
    {
    }
    CSCC& BuildGraph( const vector<Arc>& data );
    CSCC& FirstPass();
    CSCC& SecondPass();
    CSCC& GetResult( uint count );
private:
    void DfsTo( uint node );
    void DfsToNR( uint node );
    void DfsFrom( uint node );
    void DfsFromNR( uint node );
private:
    vector<Node> graph;
    vector<bool> explored;
    vector<uint> leaders;
    stack<uint> order;
    uint leader;
};

CSCC& CSCC::BuildGraph( const vector<Arc>& data )
{
    for each( Arc arc in data )
    {
        graph[arc.tail].to.push_back( arc.head );
        graph[arc.head].from.push_back( arc.tail );
    }
    return *this;
}

CSCC& CSCC::FirstPass()
{
    uint i;
    for( i = 1; i < graph.size(); ++i )
    {
        if( !explored[i] )
        {
            DfsFrom( i );
            //DfsFromNR( i );
        }
    }
    return *this;
}

CSCC& CSCC::SecondPass()
{
    vector<bool> new_explored( graph.size() );
    new_explored.swap( explored );

    while( !order.empty() )
    {
        uint node = order.top();
        order.pop();
        if( !explored[node] )
        {
            leader = node;
            DfsTo( node );
            //DfsToNR( node );
        }
    }
    return *this;
}

CSCC& CSCC::GetResult( uint count )
{
    vector<uint> scc( graph.size() );
    for each( uint arc in leaders )
    {
        scc[arc]++;
    }

    priority_queue<uint> pq( scc.begin(), scc.end() );
    while ( !pq.empty( ) )
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
        if( --count == 0 )
            break;
    }
    return *this;
}

void CSCC::DfsToNR( uint node )
{
    stack<uint> nodes;
    nodes.push( node );
    while( !nodes.empty() )
    {
        node = nodes.top();

        leaders[node] = leader;

        if( !explored[node] )
        {
            explored[node] = true;
            for each( uint arc in graph[node].to )
            {
                if( !explored[arc] )
                    nodes.push( arc );
            }
        }
        else
        {
            nodes.pop();
        }
    }
}

void CSCC::DfsTo( uint node )
{
    leaders[node] = leader;

    explored[node] = true;
    for each( uint arc in graph[node].to )
    {
        if( !explored[arc] )
            DfsTo( arc );
    }
}

void CSCC::DfsFromNR( uint node )
{
    stack<uint> nodes;
    nodes.push( node );
    while( !nodes.empty() )
    {
        node = nodes.top();
        if( !explored[node] )
        {
            explored[node] = true;
            for each( uint arc in graph[node].from )
            {
                if( !explored[arc] )
                    nodes.push( arc );
            }
        }
        else
        {
            nodes.pop();
            order.push( node );
        }
    }
}

void CSCC::DfsFrom( uint node )
{
    explored[node] = true;
    for each( uint arc in graph[node].from )
    {
        if( !explored[arc] )
            DfsFrom( arc );
    }

    order.push( node );
}

void pq4( int argc, _TCHAR* argv[] )
{
    int now;
    int past = clock();

    vector<Arc> data;
    data.reserve( 5200000UL );

    ReadDataFile( argv[1], &data );

    now = clock();
    std::cout << "ReadDataFile: " << float( now - past ) / CLOCKS_PER_SEC << " seconds" << std::endl;
    past = now;

    if( !data.size() )
    {
        std::cout << "No data for processing" << std::endl;
        return;
    }

    uint graph_size = data[data.size() - 1 ].tail + 1;

    CSCC cscc( graph_size );

    now = clock();
    std::cout << "CSCC cscc: " << float( now - past ) / CLOCKS_PER_SEC << " seconds" << std::endl;
    past = now;

    cscc.BuildGraph( data );

    now = clock();
    std::cout << "BuildGraph: " << float( now - past ) / CLOCKS_PER_SEC << " seconds" << std::endl;
    past = now;

    cscc.FirstPass();

    now = clock();
    std::cout << "FirstPass: " << float( now - past ) / CLOCKS_PER_SEC << " seconds" << std::endl;
    past = now;

    cscc.SecondPass();

    now = clock();
    std::cout << "SecondPass: " << float( now - past ) / CLOCKS_PER_SEC << " seconds" << std::endl;
    past = now;

    cscc.GetResult( 5 );

    now = clock();
    std::cout << "GetResult: " << float( now - past ) / CLOCKS_PER_SEC << " seconds" << std::endl;
    past = now;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int _tmain( int argc, _TCHAR* argv[] )
{
    int past = clock();

    //pq1( argc, argv );
    pq4( argc, argv );

    std::cout << std::endl << "Run time: " << double( clock() - past ) / CLOCKS_PER_SEC << " seconds" << std::endl;
    return 0;
}
