#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER nccl

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "/root/NCCL/nccl/src/include/nccl_tp.h"

#if !defined(_NCCL_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _NCCL_TP_H

#include "lttng/tracepoint.h"

TRACEPOINT_EVENT(nccl, ncclIbv_post_send, TP_ARGS(uint32_t, qpNum, int, chunkSize, uint32_t, remoAddr),
                 TP_FIELDS(ctf_integer(uint32_t, srcQpNum, qpNum)          
                            ctf_integer(int, chunkSize, chunkSize)        //chunksize = 128kB / num of qp
                            ctf_integer(uint32_t, dstAddr, remoAddr)))    //remote addr data sent to                          

TRACEPOINT_EVENT(nccl, ncclIbv_post_recv, TP_ARGS(uint32_t, qpNum, uint32_t, remoAddr),
                 TP_FIELDS(ctf_integer(uint32_t, dstQpNum, qpNum)         
                            ctf_integer(uint32_t, srcAddr, remoAddr)))    //remote addr data sent from

TRACEPOINT_EVENT(nccl, ncclIbv_poll_cq, TP_ARGS(uint32_t, qpNum, uint32_t, remoAddr),
                 TP_FIELDS(ctf_integer(uint32_t, qpNum, qpNum)            //poll_cq diff send or recv by qpNum and remoAddr          
                            ctf_integer(uint32_t, remoAddr, remoAddr)))   

TRACEPOINT_EVENT(nccl, ncclGpuSendBegin, TP_ARGS(int, myRank, int, dstRank),
                 TP_FIELDS(ctf_integer(int, myRank, myRank)
                            ctf_integer(int, dstRank, dstRank)))

TRACEPOINT_EVENT(nccl, ncclGpuRecvBegin, TP_ARGS(int, myRank, int, srcRank),
                 TP_FIELDS(ctf_integer(int, myRank, myRank)
                            ctf_integer(int, srcRank, srcRank)))

TRACEPOINT_EVENT(nccl, ncclGpuCommEnd, TP_ARGS(int, myRank),
                 TP_FIELDS(ctf_integer(int, myRank, myRank)))            //GpuCommEnd ends one poll for all AsynGpuRecv & AsynGpuSend 

#endif /* _NCCL_TP_H */

#include "lttng/tracepoint-event.h"

