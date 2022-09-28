#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER nccl

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "/root/nccl/src/include/nccl_tp.h"

#if !defined(_NCCL_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _NCCL_TP_H

#include "lttng/tracepoint.h"

TRACEPOINT_EVENT(nccl, example, TP_ARGS(int64_t, tag),
                 TP_FIELDS(ctf_integer(int64_t, tag, tag)))

#endif /* _NCCL_TP_H */

#include "lttng/tracepoint-event.h"

