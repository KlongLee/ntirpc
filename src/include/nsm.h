/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NSM_H_RPCGEN
#define _NSM_H_RPCGEN

#include "config.h"
#include "rpc.h"
#include "sal_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define SM_MAXSTRLEN 1024
#define SM_PROG 100024
#define SM_VERS 1
#define SM_MON 2
#define SM_UNMON 3
#define SM_UNMON_ALL 4

  enum res
  {
    STAT_SUCC = 0,
    STAT_FAIL = 1,
  };
  typedef enum res res;

  struct sm_stat_res
  {
    res res_stat;
    int state;
  };
  typedef struct sm_stat_res sm_stat_res;

  struct sm_stat
  {
    int state;
  };
  typedef struct sm_stat sm_stat;

  struct my_id
  {
    char *my_name;
    int my_prog;
    int my_vers;
    int my_proc;
  };
  typedef struct my_id my_id;

  struct mon_id
  {
    char *mon_name;
    struct my_id my_id;
  };
  typedef struct mon_id mon_id;

  struct mon
  {
    struct mon_id mon_id;
    char priv[16];
  };
  typedef struct mon mon;
  extern bool_t nsm_monitor(state_nlm_client_t *host);
  extern bool_t nsm_unmonitor(state_nlm_client_t *host);
  extern void nsm_unmonitor_all(void);

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
  extern bool_t xdr_res(XDR *, res *);
  extern bool_t xdr_sm_stat_res(XDR *, sm_stat_res *);
  extern bool_t xdr_sm_stat(XDR *, sm_stat *);
  extern bool_t xdr_my_id(XDR *, my_id *);
  extern bool_t xdr_mon_id(XDR *, mon_id *);
  extern bool_t xdr_mon(XDR *, mon *);

#else                           /* K&R C */
  extern bool_t xdr_res();
  extern bool_t xdr_sm_stat_res();
  extern bool_t xdr_sm_stat();
  extern bool_t xdr_my_id();
  extern bool_t xdr_mon_id();
  extern bool_t xdr_mon();

#endif                          /* K&R C */

#ifdef __cplusplus
}
#endif

#endif                          /* !_NSM_H_RPCGEN */