#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void vuid();
void vpar( char *action, char *servis );
void proc( char *action, char *servis );
void wlan( char *action );
void ethr( char *action );
void vhos( char *action );
void sec1( char *action );
void sec2( char *action );
void sec3( char *action );


int main( int argc, char **argv )
{
  if ( argc != 3 ) 
  {
    fprintf(stderr, "rarameter limit execed");
    exit(1);
  }
  vuid();
  vpar( argv[1], argv[2]);
  char* param_0 = argv[1];
  char* param_1 = argv[2];
  proc( param_0, param_1 );
  return 0;
}


void vuid() 
{
  if ( getuid() != 0 ) 
  {
    fprintf( stderr, "application need root privileges" );
    exit(1);
  }
}


void vpar( char *action, char *servis ) {

  if ( strlen( action ) > 2 || strlen( action ) < 1 )
  {
    fprintf( stderr, "action parameter is to long." );
    exit(1);
  }

  if ( strlen( servis ) > 7 || strlen( servis ) < 1 )
  {
    fprintf( stderr, "service parameter to long." );
    exit(1);
  }
}


void proc( char *action, char *servis ) 
{
  if ( strcmp( servis, "wlan" ) == 0 )
  {
    wlan( action );
  }
  else if ( strcmp( servis, "ethr" ) == 0 )
  {
    ethr( action );
  }
  else
  {
    printf("\"%s\" module not available \n", servis );
  }
}


void wlan( char *action )
{
  if ( strcmp( action, "-i" ) == 0 ) 
  {
    system("systemctl start iwd");
    system("systemctl start firewalld");
    puts("wlan daemon enable");
  }
  else if ( strcmp ( action, "-s") == 0 )
  {
    system("systemctl stop iwd");
    system("systemctl stop firewalld");
    puts("wlan daemon disable");
  }
  else
  {
    printf("Unknown \"%s\" operation parameter\n", action);
  }
}


void ethr( char *action )
{
  if ( strcmp( action, "-i" ) == 0 )
  {
    system("systemctl start systemd-networkd");
    system("systemctl start firewalld");
    puts("ethernet daemon enable");
  }
  else
  {
    system("systemctl stop systemd-networkd");
    system("systemctl stop firewalld");
    puts("ethernet daemon disable");
  }
}
