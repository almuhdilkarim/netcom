int notif( char *category, char *title, char *message , char *icon )
{
    // cli notification
    puts(message);

    // gui notification
    NotifyNotification *notif;
		notify_init(category);
		notif = notify_notification_new ( title, message, icon);
		notify_notification_set_timeout(notif, 3000); //3 seconds
    notify_notification_show(notif, NULL);

		if ( ! notify_notification_show (notif, NULL) ) 
    {
			g_error("Failed to send notification.\n");
			return 1;
		}
}


char* form_passwd() 
{
  FILE *dialog = popen("zenity --password", "r");
  char input[getpagesize()];
  char *result;
  result = malloc (sizeof (char) * 15);
  
  if (dialog != NULL)
  {
     fgets(input,sizeof(input),dialog);
     strcpy( result, input);
     return result;
  }
  else 
  {
     perror("password empty, exited with non-zero exit code");
     exit(1);
  }
}


int srv_check( char *service ) 
{
  char *passwd = form_passwd();
  char command[150];
  sprintf(command, "echo '%s' | sudo -S systemctl is-active --quiet %s", passwd, service );
  if ( system(command) != 0 )
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}


void srv_setup( char *action, char *service )
{
  char command[150];
  char content[150];
  if ( strcmp ( action, "init" ) == 0 )
  {
    sprintf( command, "sudo systemctl start %s", service );
    sprintf( content, "%s service is enabled\n", service );
  }
  else 
  {
    sprintf( command, "sudo systemctl stop %s", service );
    sprintf( content, "%s service is disabled\n", service );
  }
  system(command);
  notif( "service", service, content, NULL );
}
