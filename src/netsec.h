

void frwl_init() 
{
    system("systemctl start firewalld");
    puts("firewall service disable");
}

void frwl_stop()
{
    system("systemctl stop firewalld");
    puts("firewall service disable");
}
