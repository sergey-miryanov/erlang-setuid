#include <sys/types.h>
#include <unistd.h>
#include <erl_driver.h>
#include <ei.h>
#include <erl_interface.h>

#define CMD_SET_UID   1
#define CMD_SET_GID   2
#define CMD_SET_EUID  3
#define CMD_SET_EGID  4

typedef struct setuid_drv_t {
  ErlDrvPort      port;
  FILE            *log;
  ErlDrvTermData  ok_atom;
  ErlDrvTermData  error_atom;
} setuid_drv_t;

static ErlDrvData
start (ErlDrvPort port, char *cmd);

static void
stop (ErlDrvData drv);

static int
control (ErlDrvData drv,
  unsigned int command,
  char *buf,
  int len,
  char **rbuf,
  int rlen);

static void
set_uid (setuid_drv_t *drv,
  char *uid);

static void
set_gid (setuid_drv_t *drv,
  char *gid);

static void
set_euid (setuid_drv_t *drv,
  char *euid);
