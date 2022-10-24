#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER nccl

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "/root/NCCL/nccl/src/include/nccl_tp.h"

#if !defined(_NCCL_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _NCCL_TP_H

#include "lttng/tracepoint.h"

TRACEPOINT_EVENT(nccl, ncclIbv_post_send, TP_ARGS(uint32_t, qpnum, int, chunksize, uint32_t, remoaddr),
                 TP_FIELDS(ctf_integer(uint32_t, qpnum, qpnum)          //qp number
                            ctf_integer(int, chunksize, chunksize)      //chunksize = 128kB / num of qp
                            ctf_integer(uint32_t, remoaddr, remoaddr)))    //remote addr data sent to                          

TRACEPOINT_EVENT(nccl, ncclIbv_post_recv, TP_ARGS(uint32_t, qpnum, uint32_t, remoaddr),
                 TP_FIELDS(ctf_integer(uint32_t, qpnum, qpnum)         //qp number
                            ctf_integer(uint32_t, remoaddr, remoaddr)))   //remote addr data sent from

TRACEPOINT_EVENT(nccl, ncclIbv_poll_cq, TP_ARGS(uint32_t, qpnum, uint32_t, remoaddr),
                 TP_FIELDS(ctf_integer(uint32_t, qpnum, qpnum) 
                            ctf_integer(uint32_t, remoaddr, remoaddr)))   

TRACEPOINT_EVENT(nccl, ncclGpuIntraSendBegin, TP_ARGS(int, myRank, int, desRank),
                 TP_FIELDS(ctf_integer(int, myRank, myRank)
                            ctf_integer(int, desRank, desRank)))

TRACEPOINT_EVENT(nccl, ncclGpuIntraRecvBegin, TP_ARGS(int, myRank, int, srcRank),
                 TP_FIELDS(ctf_integer(int, myRank, myRank)
                            ctf_integer(int, srcRank, srcRank)))

TRACEPOINT_EVENT(nccl, ncclGpuIntraCommEnd, TP_ARGS(int, myRank),
                 TP_FIELDS(ctf_integer(int, myRank, myRank)))

#endif /* _NCCL_TP_H */

#include "lttng/tracepoint-event.h"

