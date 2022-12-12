#include <memory>
#include <string>
#include <cstdlib>
#include <restbed>

using namespace std;
using namespace restbed;

void hello( const shared_ptr< Session > session )
{
    const auto request = session->get_request( );

    session->close( OK, "Hello World!\n" , { { "Content-Length", "13" } } );
}

void helloname( const shared_ptr< Session > session )
{
    const auto request = session->get_request( );

    string responseText = "Hello, " + request->get_path_parameter("name") + "!\n";
    session->close( OK, responseText , { { "Content-Length", ::to_string( responseText.size() ) } } );
}

int main( const int, const char** )
{
    auto hello_resource = make_shared< Resource >( );
    hello_resource->set_path( "/hello" );
    hello_resource->set_method_handler( "GET", hello );
    auto helloname_resource = make_shared< Resource >( );
    helloname_resource->set_path( "/hello/{name: .*}" );
    helloname_resource->set_method_handler( "GET", helloname );

    auto settings = make_shared< Settings >( );
    settings->set_port( 9080 );
    settings->set_default_header( "Connection", "close" );

    Service service;
    service.publish( hello_resource );
    service.publish( helloname_resource );
    service.start( settings );

    return EXIT_SUCCESS;
}
