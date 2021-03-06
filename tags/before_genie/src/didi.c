#include "didi.h"

static int debug;
int hostlogin; //declared external in wikilogin.c
int dosendmail; //declared external in wikilogin.c

int
usage()
{ 
  fprintf(stderr, "Usage: wiki4freetz [options]\n");
  fprintf(stderr, "   -a, --autologin       : login localhost automatically\n");
  fprintf(stderr, "   -d, --debug           : debug mode, listens to requests from stdin\n");
  fprintf(stderr, "   -h, --home   <path>   : specify wiki4freetz's home directory\n");
  fprintf(stderr, "   -l, --listen <ipaddr> : specify IP address\n");
  fprintf(stderr, "   -p, --port   <port>   : specify port number \n");
  fprintf(stderr, "   -r, --restore         : restore the default WikiHelp\n");
  fprintf(stderr, "       --help            : display this help message\n");
  fprintf(stderr, "   -s, --sendmail        : run sendmail script automatically\n");
  fprintf(stderr, "   -v, --version         : display the version\n");
  exit(1);
}

int 
main(int argc, char **argv)
{
  HttpRequest    *req  = NULL;
  int             port = 8001;
  int             c;
  char           *didiwiki_home = NULL;
  int             restore_WikiHelp = 0;
  struct in_addr address;


  debug = 0;
  hostlogin = 0;
  dosendmail = 0;

  /* by default bind server to "0.0.0.0" */
  address.s_addr = inet_addr("0.0.0.0");

  while (1)
  {
    static struct option long_options[] = 
    {
      {"autologin",  no_argument,   0, 'a'},
      {"debug",  no_argument,       0, 'd'},
      {"version",  no_argument,     0, 'v'},
      {"listen", required_argument, 0, 'l'},
      {"port",   required_argument, 0, 'p'},
      {"home",   required_argument, 0, 'h'},
      {"restore",   no_argument,    0, 'r'},
      {"sendmail",  no_argument,    0, 's'},
      {"help",   no_argument,       0,  10 },
      {0, 0, 0, 0}
    };

    /* getopt_long stores the option index here */
    int option_index = 0;
    
    c = getopt_long (argc, argv, "adl:p:h:rsv", long_options, &option_index);

    /* detect the end of the options */
    if (c == -1)
    break;

    switch (c)
    {
      case 0:
        break;
      case 'a': //autologin for the localhost
        hostlogin = 1;
        fprintf(stderr,"Localhost is logged in.\n");
        break;
      case 'd':
        debug = 1;
        break;      
      case 'v':
        printf("CiWiki alias DidiWiki - version %s\n\n",VERSION);
        return 0;         
      case 'p': //default port is 8001
        port = atoi(optarg);
        break;      
      case 'h': //default home directory is ~/.didiwiki
        didiwiki_home = optarg;
        break;
      case 'l': //listen a inet address
        if(inet_aton(optarg,&address) == 0) 
        {
          fprintf(stderr, "didiwiki: invalid ip address \"%s\"\n", optarg);
          exit(1);
        } else
          address.s_addr = inet_addr(optarg);
        break;
      case 'r': //rewrite Wikihelp page
        restore_WikiHelp=1; 
        break;
      case 's':
        dosendmail= 1;
        break;
      case 10:
        usage();
        break;
      default:
        usage();
    }
  } //end while

  wiki_init(didiwiki_home,restore_WikiHelp);

  if (debug)
  {
    req = http_request_new();   /* reads request from stdin */
  }
  else 
  {
    fprintf(stderr, "Working directory is: %s\n", didiwiki_home); 
    req = http_server(address, port);    /* forks here */
  }

  wiki_handle_http_request(req);

  return 0;
}
