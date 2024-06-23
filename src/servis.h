// network toogle service
void wlan_init() {
    system("systemctl start iwd");
    notif();
    puts("wireless daemon enable");
}
void wlan_stop() {
    system("systemctl stop iwd");
    puts("wireless daemon disable");
}
void ethr_init() {
    system("systemctl start systemd-networkd");
    puts("ethernet daemon enable");
}

void ethr_stop() {
    system("systemctl stop systemd-networkd.socket");
    system("systemctl stop systemd-networkd");
    puts("ethernet daemon enable");
}
void wlan()
{
  if ( system("systemctl is-active --quiet iwd") != 0 ) 
  {
    ethr_stop(); frwl_stop();
    wlan_init(); frwl_init();
  }
  else
  {
    wlan_stop(); frwl_stop();
  }
}
void ethr()
{
  if ( system("systemctl is-active --quiet systemd-networkd") != 0 ) 
  {
    wlan_stop(); frwl_stop();
    ethr_init(); frwl_init();
  }
  else
  {
    ethr_stop(); frwl_stop();
  }
}


// bluetooth toggle service
void bluz_init() {
    system("systemctl start bluetooth.service");
    puts("bluetooth daemon enable");
}
void bluz_stop() {
    system("systemctl stop bluetooth.service");
    puts("bluetooth daemon disable");
}
void bluz()
{
  if ( system("systemctl is-active --quiet bluetooth.service") != 0 ) 
  {
    bluz_init();
  }
  else
  {
    bluz_stop();
  }
}


// virtualization toggle service
void vhos_init() {
    system("systemctl start libvirtd.socket");
    puts("virtualization daemon disable");
}
void vhos_stop() {
    system("systemctl stop libvirtd.socket");
    puts("virtualization daemon disable");
}
void vhos()
{
  if ( system("systemctl is-active --quiet libvirtd.socket") != 0 ) 
  {
    vhos_init();
  }
  else
  {
    vhos_stop();
  }
}


// cockpit toogle service
void cock_init() {
    system("systemctl start cockpit.socket");
    puts("cockpit daemon enable");
}
void cock_stop() {
    system("systemctl stop cockpit.socket");
    puts("cockpit daemon disable");
}
void cock()
{
  if ( system("systemctl is-active --quiet cockpit.socket") != 0 ) 
  {
    cock_init();
  }
  else
  {
    cock_stop();
  }
}


// docker toogle service
void dock_init() {
    system("systemctl start docker.socket");
    puts("docker daemon enable");
}
void dock_stop() {
    system("systemctl stop docker.socket");
    puts("docker daemon disable");
}
void dock()
{
  if ( system("systemctl is-active --quiet docker.socket") != 0 ) 
  {
    dock_init();
  }
  else
  {
    dock_stop();
  }
}


// sshd toogle service
void sshd_init() {
    system("systemctl start sshd");
    puts("sshd daemon enable");
}
void sshd_stop() {
    system("systemctl stop sshd");
    puts("sshd daemon disable");
}
void sshd()
{
  if ( system("systemctl is-active --quiet sshd") != 0 ) 
  {
    sshd_init();
  }
  else
  {
    sshd_stop();
  }
}
