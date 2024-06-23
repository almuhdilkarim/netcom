

void sway() {
  printf("karim\n");
}

int notif()
{
    char *karim = "harlo";
    char *zaza  = "berlo";
    NotifyNotification *notif;
		notify_init("swaync");
		notif = notify_notification_new ( karim, zaza, NULL);
		notify_notification_set_timeout(notif, 3000); //3 seconds
    notify_notification_show(notif, NULL);
		if (!notify_notification_show (notif, NULL)) {
			g_error("Failed to send notification.\n");
			return 1;
		}
}

