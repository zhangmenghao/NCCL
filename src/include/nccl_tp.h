#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER nccl

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "/root/nccl/src/include/nccl_tp.h"

#if !defined(_NCCL_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _NCCL_TP_H

#include "lttng/tracepoint.h"

TRACEPOINT_EVENT(nccl, ncclIbv_post_send, TP_ARGS(uint32_t, qpnum, int, chunksize, char*, remoaddr),
                 TP_FIELDS(ctf_integer(uint32_t, qpnum, qpnum)          //qp number
                            ctf_integer(int, chunksize, chunksize)      //chunksize = 128kB / num of qp
                            ctf_integer(char*, remoaddr, remoaddr)))    //remote addr data sent to


TRACEPOINT_EVENT(nccl, ncclIbv_post_recv, TP_ARGS(uint32_t, qpnum, char*, remoaddr),
                 TP_FIELDS(ctf_integer(uint32_t, qpnum, qpnum)         //qp number
                            ctf_integer(char*, remoaddr, remoaddr)))   //remote addr data sent from


TRACEPOINT_EVENT(nccl, ncclIbv_poll_cq, TP_ARGS(uint32_t, qpnum, char*, remoaddr),
                 TP_FIELDS(ctf_integer(uint32_t, qpnum, qpnum) 
                            ctf_integer(char*, remoaddr, remoaddr)))   


TRACEPOINT_EVENT(nccl, ncclIbv_destroy_send_qp, TP_ARGS(uint32_t, qpnum),  
                 TP_FIELDS(ctf_integer(uint32_t, qpnum, qpnum)))   


TRACEPOINT_EVENT(nccl, ncclIbv_destroy_recv_qp, TP_ARGS(uint32_t, qpnum),
                 TP_FIELDS(ctf_integer(uint32_t, qpnum, qpnum)))


#endif /* _NCCL_TP_H */

#include "lttng/tracepoint-event.h"

