#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <libnotify/notify.h>
#include "helper.h"
#include "secmod.h"
#include "servis.h"


void errs( char *value );
void srvc( char *value );
void nsec( char *value );


int main( int argc, char **argv )
{
  // if ( getuid() != 0 ) { errs("application need root privileges" ); }
  if ( argc != 3 ) { errs( "parameter error, this command need 3 parameter"); }
  if ( strlen( argv[1] ) > 8 || strlen( argv[1] ) < 1 ) { errs( "scope parameter is to long." ); }
  if ( strlen( argv[2] ) > 20 || strlen( argv[2] ) < 1 ) { errs( "value parameter is to long." ); }


  if ( strcmp( argv[1], "service" ) == 0 ) 
  {
    char* value = argv[2]; srvc( value );
  }
  else if ( strcmp (argv[1], "netsec" ) == 0 ) 
  {
    char* value = argv[2]; nsec( value );
  }
  else
  {
    errs("command scope its not define");
  }

  return 0;
}


void errs( char *value )
{
    fprintf( stderr, "%s", value );
    exit(1);
}


void nsec( char *value )
{
  printf("karim\n");
}


void srvc( char *value ) 
{
  if ( strcmp( value, "wireless" ) == 0 )
  {
    wlan();
  }
  else if ( strcmp( value, "ethernet" ) == 0 )
  {
    ethr();
  }
  else if ( strcmp( value, "firewall" ) == 0 )
  {
    frwl();
  }
  else if ( strcmp( value, "bluetooth" ) == 0 ) 
  {
    bluz();
  }
  else if ( strcmp( value, "virtualization" ) == 0 ) 
  {
    vhos();
  }
  else if ( strcmp( value, "cockpit" ) == 0 )
  {
    cock();
  }
  else if ( strcmp( value, "docker" ) == 0 )
  {
    dock();
  }
  else if ( strcmp( value, "sshd" ) == 0 )
  {
    sshd();
  }
  else
  {
    printf("\"%s\" module not available \n", value );
  }
}
