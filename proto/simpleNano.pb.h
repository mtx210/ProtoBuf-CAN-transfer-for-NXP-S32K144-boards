/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Fri Sep 20 10:51:05 2019. */

#ifndef PB_NANOPB_SIMPLENANO_PB_H_INCLUDED
#define PB_NANOPB_SIMPLENANO_PB_H_INCLUDED
#include "pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _nanoPB_simpleNano {
    int32_t a;
    int32_t b;
/* @@protoc_insertion_point(struct:nanoPB_simpleNano) */
} nanoPB_simpleNano;

/* Default values for struct fields */

/* Initializer values for message structs */
#define nanoPB_simpleNano_init_default           {0, 0}
#define nanoPB_simpleNano_init_zero              {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define nanoPB_simpleNano_a_tag                  1
#define nanoPB_simpleNano_b_tag                  2

/* Struct field encoding specification for nanopb */
extern const pb_field_t nanoPB_simpleNano_fields[3];

/* Maximum encoded size of messages (where known) */
#define nanoPB_simpleNano_size                   22

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SIMPLENANO_MESSAGES


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
