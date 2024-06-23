// wireless toogle service
void wlan()
{
  if ( srv_check("iwd") != 0 ) 
  {
    srv_setup("stop", "systemd-networkd");
    srv_setup("init", "iwd");
  }
  else
  {
    srv_setup("stop", "iwd");
  }
}


// ethernet toogle service
void ethr()
{
  if ( srv_check("systemd-networkd") != 0 ) 
  {
    srv_setup("stop", "iwd");
    srv_setup("init", "systemd-networkd");
  }
  else
  {
    srv_setup("stop", "systemd-networkd");
  }
}


// bluetooth toggle service
void bluz()
{
  if ( srv_check( "bluetooth.service") != 0 ) 
  {
    srv_setup("init", "bluetooth.service");
  }
  else
  {
    srv_setup("stop", "bluetooth.service");
  }
}


// virtualization toggle service
void vhos()
{
  if ( srv_check( "libvirtd.socket" ) != 0 ) 
  {
    srv_setup("init", "libvirtd.socket");
  }
  else
  {
    srv_setup("stop", "libvirtd.socket");
  }
}


// cockpit toogle service
void cock()
{
  if ( srv_check("cockpit.socket") != 0 ) 
  {
    srv_setup("init", "cockpit.socket");
  }
  else
  {
    srv_setup("stop", "cockpit.socket");
  }
}


// docker toogle service
void dock()
{
  if ( srv_check("docker.socket") != 0 ) 
  {
    srv_setup("init", "docker.socket");
  }
  else
  {
    srv_setup("stop", "docker.socket");
  }
}


// sshd toogle service
void sshd()
{
  if ( srv_check("sshd") != 0 ) 
  {
    srv_setup("init", "sshd");
  }
  else
  {
    srv_setup("stop", "sshd");
  }
}


// firewalld toggle service
void frwl() {
  if ( srv_check("firewalld") != 0 )
  {
    srv_setup("init", "firewalld");
  }
  else
  {
    srv_setup("stop", "firewalld");
  }
}
